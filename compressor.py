import math

class UnknownCompressor:
    def __init__(self, sample_rate=44100.0):
        # --- System Setup ---
        self.sample_rate = float(sample_rate)
        
        # --- Parameters (Knobs) ---
        # Corresponds to *(int *)(lVar4 + 0x9e54)
        # 0 = RMS, 2 = Peak
        self.mode = 2 
        
        # Corresponds to *(float *)(lVar4 + 0x9ee4)
        self.threshold = 1.0  # Linear scale (1.0 = 0dB)
        
        # Ratio is likely calculated externally and passed as a slope factor
        # We will simulate the ratio behavior here. 
        # 4.0 ratio means 1/4 output for input. Slope = 1.0 - (1.0/Ratio)
        self.ratio = 4.0 
        
        # Time constants (in seconds)
        # Corresponds to *(float *)(param_1 + 0xb0)
        self.attack_time = 0.002 
        self.release_time = 0.100
        
        # --- Internal State (History) ---
        # Corresponds to *(float *)(param_1 + 0xa8) -> RMS State
        self.rms_state = 0.0
        
        # Corresponds to *(float *)(param_1 + 0xc4) -> Peak State
        self.peak_state = 0.0
        
        # Corresponds to *(float *)(param_1 + 0xe4) -> Smoothed Gain State
        self.gain_state = 1.0
        
        # Constants for avoiding denormals/div-by-zero
        self.EPSILON = 9.536743e-07

    def _calc_coeff(self, time_seconds):
        """
        Approximates the coefficient calculation logic seen in:
        uVar14 = FUN_18103fd60(); 
        *(float *)(param_1 + 0xb8) = 1.0 - (float)uVar14;
        Standard 1-pole coeff: 1 - exp(-1 / (time * sample_rate))
        """
        if time_seconds <= 0.0:
            return 1.0
        # The decompiled function FUN_18103fd60 is a pow/exp approximation.
        # We use the standard math equivalent.
        return 1.0 - math.exp(-1.0 / (time_seconds * self.sample_rate))

    def process_block(self, left_channel, right_channel):
        """
        Functionally equivalent to: void unknown(longlong param_1, longlong *param_2)
        
        :param left_channel: List or numpy array of floats (Audio L)
        :param right_channel: List or numpy array of floats (Audio R)
        :return: (processed_left, processed_right)
        """
        
        # 1. Update Coefficients
        # In C, this checked if inputs changed. Here we calc every block for simplicity.
        attack_coeff = self._calc_coeff(self.attack_time)   # param_1 + 0xb8
        release_coeff = self._calc_coeff(self.release_time) # param_1 + 0xbc
        
        # RMS averaging coefficient (approximate constant for RMS mode)
        rms_coeff = self._calc_coeff(0.050) # param_1 + 0xa4 (Guessed value based on logic)
        
        # Gain smoothing coefficient (Ballistics)
        # The logic around uVar12/uVar13 suggests a smoothing filter for the gain reduction itself
        gain_smooth_coeff = self._calc_coeff(0.005) 

        # Calculate Slope for the gain computer: slope = 1 - (1/Ratio)
        # This matches the FUN_18103fd60 pow() logic in the gain reduction phase
        slope = 1.0 - (1.0 / self.ratio) if self.ratio > 1.0 else 0.0

        output_l = [0.0] * len(left_channel)
        output_r = [0.0] * len(right_channel)

        # 2. Processing Loop (do-while)
        for i in range(len(left_channel)):
            # Load Samples
            samp_l = left_channel[i] # fVar18
            samp_r = right_channel[i] # fVar19
            
            # --- DETECTOR STAGE ---
            current_env = 0.0 # fVar20
            
            if self.mode == 0: # RMS Mode (iVar2 == 0)
                # Calculate Power: (L^2 + R^2) * 0.5
                power = (samp_l * samp_l + samp_r * samp_r) * 0.5
                
                if power <= self.EPSILON:
                    power = self.EPSILON
                
                # Filter: state += (input - state) * coeff
                # Corresponds to: fVar20 = (fVar18 / fVar20 - fVar20) ... (The C math is optimized/weird here, standardizing)
                # Standard one-pole smoothing:
                self.rms_state += (power - self.rms_state) * rms_coeff
                current_env = math.sqrt(max(0, self.rms_state)) # RMS is Root Mean Square
                
            else: # Peak Mode (iVar2 == 2)
                abs_l = abs(samp_l)
                abs_r = abs(samp_r)
                
                # Take the max of absolute values
                input_level = abs_l if abs_l > abs_r else abs_r # *pfVar6
                
                # Attack / Release Branching
                # if input > current_state: coeff = attack, else: coeff = release
                coeff = attack_coeff if input_level > self.peak_state else release_coeff
                
                # Filter: fVar20 = (*pfVar6 - fVar20) * fVar18 + fVar20;
                self.peak_state += (input_level - self.peak_state) * coeff
                current_env = self.peak_state

            # --- GAIN COMPUTER STAGE ---
            # fVar1 is Threshold
            target_gain_linear = 1.0 # fVar18 (initialized to 1.0)
            
            if self.threshold < current_env:
                # Calculate Gain Reduction
                # C code uses: fVar18 = (float)uVar17 * (float)uVar15;
                # This represents the transfer function: Gain = (Threshold / Input) ^ Slope
                
                # Prevent div by zero
                safe_env = current_env if current_env > self.EPSILON else self.EPSILON
                ratio_calc = self.threshold / safe_env
                
                # The heavy FUN_18103fd60 call is pow(ratio_calc, slope)
                target_gain_linear = math.pow(ratio_calc, slope)

            # --- BALLISTICS (Smoothing the Gain) ---
            # fVar19 = *(float *)(param_1 + 0xe4);
            # fVar19 = (fVar18 - fVar19) * (1.0 - fVar11) + fVar19;
            self.gain_state += (target_gain_linear - self.gain_state) * gain_smooth_coeff
            
            applied_gain = self.gain_state # fVar19

            # --- APPLY GAIN ---
            # *(float *)(*param_2 + uVar16) = fVar19 * ...
            output_l[i] = samp_l * applied_gain
            output_r[i] = samp_r * applied_gain
            
            # --- METERING (Simplified) ---
            # The C code checks flags (0x9fb3, 0xa043) and updates pointers for UI meters.
            # We omit the raw pointer logic, but functionally, we would store max values here.
            # self.max_reduction = min(self.max_reduction, applied_gain)

        return output_l, output_r

# --- Example Usage ---
if __name__ == "__main__":
    # Initialize
    comp = UnknownCompressor(sample_rate=44100)
    
    # Configure (Matches C param_1 setup)
    comp.threshold = 0.5   # -6dB
    comp.ratio = 4.0       # 4:1
    comp.mode = 2          # Peak Mode
    comp.attack_time = 0.01
    comp.release_time = 0.1

    # Create dummy audio (Sine wave)
    data_len = 100
    input_l = [math.sin(x * 0.1) for x in range(data_len)]
    input_r = [math.cos(x * 0.1) for x in range(data_len)]

    # Process
    out_l, out_r = comp.process_block(input_l, input_r)

    print(f"Input [0]: {input_l[0]:.4f}, Output [0]: {out_l[0]:.4f}")
    print(f"Input [50]: {input_l[50]:.4f}, Output [50]: {out_l[50]:.4f}")