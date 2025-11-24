import struct
import math

class UnknownFilter:
    def __init__(self):
        # 1. Load Parameters from the Memory Dump
        # The dump contains 5 doubles.
        # Hex values parsed:
        # P0: 5B 2C 5F 4E 93 C7 CB 3F -> 0.21702805830713853
        # P1: B9 F6 EC 6B 36 60 E9 3F -> 0.7929947002337122
        # P2: FF FF FF FF FF FF EF 3F -> 0.9999999999999999 (approx 1.0)
        # P3: 00 00 00 00 00 00 00 00 -> 0.0
        # P4: 00 00 00 00 00 00 00 00 -> 0.0
        
        self.P = [
            0.21702805830713853, # P0
            0.7929947002337122,  # P1
            0.9999999999999999,  # P2
            0.0,                 # P3
            0.0                  # P4
        ]

        # 2. Calculate Runtime Coefficients (Filter Design Step)
        self.C = self._calculate_coefficients(self.P)
        
        # 3. Initialize State (History)
        # [S0 (Left1), S1 (Right1), S2 (Left2), S3 (Right2)]
        self.state = [0.0, 0.0, 0.0, 0.0] 

    def _calculate_coefficients(self, P):
        """
        Translates the 5 input parameters into the 5 runtime coefficients (C0-C4)
        using the complex root solving logic from the decompilation.
        """
        P0, P1, P2, P3, P4 = P
        
        # --- Root Calculation ---
        # Calculate term A
        val_A = (-1.0 - P3) - P4
        if val_A <= 0.0:
            root1_im = math.sqrt(-val_A)
            root1_re = 0.0
        else:
            root1_re = math.sqrt(val_A)
            root1_im = 0.0
            
        # Calculate term B
        val_B = (P3 - 1.0) - P4
        if val_B <= 0.0:
            root2_im = math.sqrt(-val_B)
            root2_re = 0.0
        else:
            root2_re = math.sqrt(val_B)
            root2_im = 0.0

        # --- Solve System (dVar9 Calculation) ---
        # Logic handles cases to avoid division by zero, simplifed for these inputs:
        # With P3=0, P4=0: root1_im=1, root2_im=1, reals=0.
        if abs(root2_re) <= abs(root2_im):
            # This path is taken for the provided values
            dVar24 = root2_im * (root2_im / root2_im) + root2_re # 1.0 * 1.0 + 0 = 1.0
            dVar9 = (root1_im * (root2_im / root2_im) + root1_re) / dVar24 # (1*1 + 0)/1 = 1.0
        else:
            dVar24 = root2_re * (root2_re / root2_im) + root2_im
            dVar9 = (root1_im + root1_re * (root2_re / root2_im)) / dVar24

        # --- Final Coefficient Mapping ---
        # Denominator for normalization
        # inv_den = 1.0 / (Real(Root1 * Root2))
        inv_den = 1.0 / (root1_re * root2_re - root2_im * root1_im) 
        
        C0 = dVar9
        C1 = (P4 - 1.0) * inv_den
        C2 = ((P0 - P1) + P2) / ((1.0 - P3) + P4)
        C3 = (P0 - P2) * -2.0 * inv_den
        C4 = (P0 + P1 + P2) / (P3 + 1.0 + P4)
        
        return [C0, C1, C2, C3, C4]

    def process(self, left_samples, right_samples):
        """
        Processes a block of stereo audio.
        Returns tuple (left_output, right_output)
        """
        output_l = []
        output_r = []
        
        # Unpack Coefficients and State for speed
        C0, C1, C2, C3, C4 = self.C
        S0, S1, S2, S3 = self.state
        
        # Pre-calculated loop constants
        dVar5 = C0 * 2.0
        dVar3 = C1 * 2.0
        dVar26 = dVar3 + C0
        dVar28 = 1.0 / (dVar26 * C0 + 1.0) # The TPT Inverse Term

        for i in range(len(left_samples)):
            L_in = left_samples[i]
            R_in = right_samples[i]

            # --- Left Channel Processing ---
            # 1. Estimate new state based on input
            u_L = L_in * C0 + S0
            
            # 2. Solve Zero-Delay Feedback equation (Linear Solver)
            # This resolves the implicit loop: val_L is roughly Highpass/Intermediate
            val_L = L_in - (dVar26 * u_L + S2) * dVar28
            
            # 3. Update temporary state (needed for output mix)
            S2_temp_L = (u_L - S2 * C0) * dVar28 * C0 + S2
            
            # 4. Calculate v1 (Bandpass/Intermediate)
            v1_L = val_L * C0 + S0
            
            # 5. Calculate Left Output (State Variable Mix)
            out_L = C3 * v1_L + C4 * S2_temp_L + C2 * val_L
            
            # --- Right Channel Processing (Symmetric) ---
            u_R = R_in * C0 + S1
            val_R = R_in - (dVar26 * u_R + S3) * dVar28
            S3_temp_R = (u_R - S3 * C0) * dVar28 * C0 + S3
            v1_R = val_R * C0 + S1
            out_R = C3 * v1_R + C4 * S3_temp_R + C2 * val_R
            
            # --- State Update (Tick Tock) ---
            # Updates internal capacitors (Integrators) for next sample
            S0 = ((L_in - dVar3 * v1_L) - S2_temp_L) * dVar5 + S0
            S1 = ((R_in - dVar3 * v1_R) - S3_temp_R) * dVar5 + S1
            S2 = v1_L * dVar5 + S2
            S3 = v1_R * dVar5 + S3
            
            output_l.append(out_L)
            output_r.append(out_R)

        # Save state back
        self.state = [S0, S1, S2, S3]
        
        return output_l, output_r

# Example Usage:
if __name__ == "__main__":
    # Create the filter
    dsp = UnknownFilter()
    
    # Create a dummy impulse signal (1.0 followed by zeros)
    data_len = 20
    inp_l = [1.0] + [0.0] * (data_len - 1)
    inp_r = [1.0] + [0.0] * (data_len - 1)
    
    # Process
    out_l, out_r = dsp.process(inp_l, inp_r)
    
    print("Filter Coefficients (C0-C4):", dsp.C)
    print("\nImpulse Response (First 10 samples):")
    for i in range(10):
        print(f"[{i}] L: {out_l[i]:.6f}, R: {out_r[i]:.6f}")