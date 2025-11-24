class StereoGainMeter:
    def __init__(self, meter_coeff_l: float = 0.1, meter_coeff_r: float = 0.1):
        """
        Initializes the DSP block state.
        
        Args:
            meter_coeff_l: Smoothing factor for Left metering (offset 0xbc)
            meter_coeff_r: Smoothing factor for Right metering (offset 0xcc)
        """
        # --- State Variables (Mapping to param_1 offsets) ---
        
        # 0xb0: Initialization flag
        self._initialized = False
        
        # 0xa8: Target Gain (Acts as "Previous Target" at start of block)
        self._stored_target_gain = 0.0
        
        # 0xa4: Start Gain (Snapshot of gain at start of processing block)
        self._start_gain = 0.0
        
        # 0xac: Current Instantaneous Gain (Updated every sample)
        self._current_gain = 0.0
        
        # 0xa0: Ramp Step Size (1.0 / block_size)
        self._ramp_step = 0.0
        
        # 0xbc, 0xcc: Metering Coefficients (smoothing factors)
        self._meter_coeff_l = meter_coeff_l
        self._meter_coeff_r = meter_coeff_r
        
        # 0xc0, 0xd0: Metering State (Accumulated Energy)
        self._meter_state_l = 0.0
        self._meter_state_r = 0.0

    def process_block(self, left_samples: list[float], right_samples: list[float], 
                      config_mode: int, config_val_normal: float, config_val_boost: float):
        """
        Functionally equivalent to `void unknown`.
        Modifies audio buffers in-place and updates internal state.
        """
        
        # --- 1. Determine Target Gain (Logic from 0x90 Config Object) ---
        # Corresponds to: if (*(int *)(lVar1 + 0x9dc4) == 1) ...
        if config_mode == 1:
            # Corresponds to: fVar5 = val + val;
            target_gain = config_val_boost * 2.0
        else:
            target_gain = config_val_normal

        block_size = len(left_samples)
        
        # --- 2. Setup Ramping (De-zippering Logic) ---
        if not self._initialized:
            # Handle first run (0xb0 == 0)
            self._initialized = True
            self._start_gain = target_gain
            self._stored_target_gain = target_gain
            self._ramp_step = 0.0
            
            # If uninitialized, we snap immediately (fVar6 = 0.0 logic)
            self._current_gain = target_gain
        else:
            # Compare New Target vs Old Target (0xa8)
            # Corresponds to: if ((fVar5 - fVar7 <= -1e-15) || ...)
            diff = target_gain - self._stored_target_gain
            
            if abs(diff) >= 1e-15:
                # Calculate step size: 1.0 / block_size
                self._ramp_step = 1.0 / float(block_size)
                # Start ramping from where we left off
                self._start_gain = self._stored_target_gain 
            else:
                # No change, no ramping needed
                self._ramp_step = 0.0
                self._start_gain = target_gain

        # Update stored target for the *next* function call
        # Corresponds to: *(float *)(param_1 + 0xa8) = fVar5;
        self._stored_target_gain = target_gain

        # --- 3. Audio Processing Loop ---
        ramp_counter = 0.0 # Offset 0x9c is reset to 0
        
        # In C: do { ... } while (uVar2 < param_2[5])
        for i in range(block_size):
            
            # Update Interpolation Counter
            ramp_counter += 1.0
            
            # Calculate Gain Interpolation Factor (t)
            # fVar5 = fVar5 * *(float *)(param_1 + 0xa0);
            t = ramp_counter * self._ramp_step
            
            # Apply Linear Interpolation (Lerp)
            # Formula: (1.0 - t) * start + t * target
            # Corresponds to: fVar5 = (1.0 - fVar5) * *(float *)(0xa4) + fVar5 * *(float *)(0xa8)
            
            if self._ramp_step > 0:
                calculated_gain = (1.0 - t) * self._start_gain + (t * target_gain)
            else:
                calculated_gain = target_gain

            self._current_gain = calculated_gain # Store at 0xac

            # --- Process Channel 1 (Left) ---
            samp_l = left_samples[i]
            
            # Apply Gain
            out_l = samp_l * calculated_gain
            left_samples[i] = out_l # Write back to buffer
            
            # Update Metering (Low Pass Filter on Energy)
            # Formula: state = (input^2 - state) * coeff + state
            energy_l = out_l * out_l
            self._meter_state_l = (energy_l - self._meter_state_l) * self._meter_coeff_l + self._meter_state_l

            # --- Process Channel 2 (Right) ---
            samp_r = right_samples[i]
            
            # Apply Gain
            out_r = samp_r * self._current_gain # Uses value from 0xac
            right_samples[i] = out_r # Write back to buffer
            
            # Update Metering
            energy_r = out_r * out_r
            self._meter_state_r = (energy_r - self._meter_state_r) * self._meter_coeff_r + self._meter_state_r

    def get_meter_levels(self):
        """Returns the current energy state (offsets 0xc0 and 0xd0)."""
        return self._meter_state_l, self._meter_state_r