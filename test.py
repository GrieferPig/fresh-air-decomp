import math
import struct

# ==============================================================================
# 1. PROVIDED MODULE IMPLEMENTATIONS (Strict Copy)
# ==============================================================================


class StereoGainMeter:
    def __init__(self, meter_coeff_l: float = 0.1, meter_coeff_r: float = 0.1):
        self._initialized = False
        self._stored_target_gain = 0.0
        self._start_gain = 0.0
        self._current_gain = 0.0
        self._ramp_step = 0.0
        self._meter_coeff_l = meter_coeff_l
        self._meter_coeff_r = meter_coeff_r
        self._meter_state_l = 0.0
        self._meter_state_r = 0.0

    def process_block(
        self,
        left_samples: list[float],
        right_samples: list[float],
        config_mode: int,
        config_val_normal: float,
        config_val_boost: float,
    ):
        if config_mode == 1:
            target_gain = config_val_boost * 2.0
        else:
            target_gain = config_val_normal

        block_size = len(left_samples)

        if not self._initialized:
            self._initialized = True
            self._start_gain = target_gain
            self._stored_target_gain = target_gain
            self._ramp_step = 0.0
            self._current_gain = target_gain
        else:
            diff = target_gain - self._stored_target_gain
            if abs(diff) >= 1e-15:
                self._ramp_step = 1.0 / float(block_size)
                self._start_gain = self._stored_target_gain
            else:
                self._ramp_step = 0.0
                self._start_gain = target_gain

        self._stored_target_gain = target_gain
        ramp_counter = 0.0

        for i in range(block_size):
            ramp_counter += 1.0
            t = ramp_counter * self._ramp_step

            if self._ramp_step > 0:
                calculated_gain = (1.0 - t) * self._start_gain + (t * target_gain)
            else:
                calculated_gain = target_gain

            self._current_gain = calculated_gain

            samp_l = left_samples[i]
            out_l = samp_l * calculated_gain
            left_samples[i] = out_l
            energy_l = out_l * out_l
            self._meter_state_l = (
                energy_l - self._meter_state_l
            ) * self._meter_coeff_l + self._meter_state_l

            samp_r = right_samples[i]
            out_r = samp_r * self._current_gain
            right_samples[i] = out_r
            energy_r = out_r * out_r
            self._meter_state_r = (
                energy_r - self._meter_state_r
            ) * self._meter_coeff_r + self._meter_state_r


class UnknownCompressor:
    def __init__(self, sample_rate=44100.0):
        self.sample_rate = float(sample_rate)
        self.mode = 2
        self.threshold = 1.0
        self.ratio = 4.0
        self.attack_time = 0.002
        self.release_time = 0.100
        self.rms_state = 0.0
        self.peak_state = 0.0
        self.gain_state = 1.0
        self.EPSILON = 9.536743e-07

    def _calc_coeff(self, time_seconds):
        if time_seconds <= 0.0:
            return 1.0
        return 1.0 - math.exp(-1.0 / (time_seconds * self.sample_rate))

    def process_block(self, left_channel, right_channel):
        attack_coeff = self._calc_coeff(self.attack_time)
        release_coeff = self._calc_coeff(self.release_time)
        rms_coeff = self._calc_coeff(0.050)
        gain_smooth_coeff = self._calc_coeff(0.005)
        slope = 1.0 - (1.0 / self.ratio) if self.ratio > 1.0 else 0.0

        output_l = [0.0] * len(left_channel)
        output_r = [0.0] * len(right_channel)

        for i in range(len(left_channel)):
            samp_l = left_channel[i]
            samp_r = right_channel[i]
            current_env = 0.0

            if self.mode == 0:
                power = (samp_l * samp_l + samp_r * samp_r) * 0.5
                if power <= self.EPSILON:
                    power = self.EPSILON
                self.rms_state += (power - self.rms_state) * rms_coeff
                current_env = math.sqrt(max(0, self.rms_state))

            else:
                abs_l = abs(samp_l)
                abs_r = abs(samp_r)
                input_level = abs_l if abs_l > abs_r else abs_r
                coeff = attack_coeff if input_level > self.peak_state else release_coeff
                self.peak_state += (input_level - self.peak_state) * coeff
                current_env = self.peak_state

            target_gain_linear = 1.0

            if self.threshold < current_env:
                safe_env = current_env if current_env > self.EPSILON else self.EPSILON
                ratio_calc = self.threshold / safe_env
                target_gain_linear = math.pow(ratio_calc, slope)

            self.gain_state += (
                target_gain_linear - self.gain_state
            ) * gain_smooth_coeff
            applied_gain = self.gain_state

            output_l[i] = samp_l * applied_gain
            output_r[i] = samp_r * applied_gain

        return output_l, output_r


class UnknownFilter:
    def __init__(self, c_hex_strings=None):
        # 1. Initialize State (History)
        # Based on decomp: offsets -4, -3, -2, -1 relative to coeff pointer
        # [S0, S1, S2, S3]
        self.state = [0.0, 0.0, 0.0, 0.0]

        # 2. Load Coefficients Directly
        if c_hex_strings:
            self.set_coefficients(c_hex_strings)
        else:
            self.C = [1.0, 0.0, 0.0, 0.0, 0.0]  # Default Pass-through

    def set_coefficients(self, hex_strings):
        """
        Expects list of 5 hex strings representing the COMPUTED coefficients.
        (C0, C1, C2, C3, C4)
        """
        self.C = []
        for h in hex_strings:
            b = bytes.fromhex(h.replace(" ", ""))
            # Little Endian Double
            val = struct.unpack("<d", b)[0]
            self.C.append(val)

    def set_params(self, c0, c1, c2, c3, c4):
        """
        Accept numeric coefficient values (floats) and set the filter coefficients.

        This is used by the FreshAirClone initializer which passes already-decoded
        floating-point coefficient values (not hex strings).
        """
        # Ensure we store a list of five coefficient values matching the
        # previous 'set_coefficients' shape.
        self.C = [float(c0), float(c1), float(c2), float(c3), float(c4)]

    def process(self, left_samples, right_samples):
        block_len = len(left_samples)
        output_l = [0.0] * block_len
        output_r = [0.0] * block_len

        # Local copies allow us to add coefficient smoothing later without
        # reshaping the loop structure.
        c0, c1, c2, c3, c4 = self.C
        dc0 = dc1 = dc2 = dc3 = dc4 = 0.0

        s0, s1, s2, s3 = self.state

        for i in range(block_len):
            two_c0 = c0 * 2.0
            two_c1 = c1 * 2.0
            mix = two_c1 + c0
            denom = mix * c0 + 1.0
            inv = 1.0 / denom if abs(denom) > 1e-20 else 0.0

            inp_l = left_samples[i]
            inp_r = right_samples[i]

            acc_l = inp_l * c0 + s0
            acc_r = inp_r * c0 + s1

            hp_l = inp_l - (mix * acc_l + s2) * inv
            hp_r = inp_r - (mix * acc_r + s3) * inv

            s2_temp = (acc_l - s2 * c0) * inv * c0 + s2
            s3_temp = (acc_r - s3 * c0) * inv * c0 + s3

            bp_l = hp_l * c0 + s0
            bp_r = hp_r * c0 + s1

            output_l[i] = c3 * bp_l + c4 * s2_temp + c2 * hp_l
            output_r[i] = c3 * bp_r + c4 * s3_temp + c2 * hp_r

            s0 = ((inp_l - two_c1 * bp_l) - s2_temp) * two_c0 + s0
            s1 = ((inp_r - two_c1 * bp_r) - s3_temp) * two_c0 + s1
            s2 = bp_l * two_c0 + s2
            s3 = bp_r * two_c0 + s3

            c0 += dc0
            c1 += dc1
            c2 += dc2
            c3 += dc3
            c4 += dc4

        self.state = [s0, s1, s2, s3]
        self.C = [c0, c1, c2, c3, c4]
        return output_l, output_r


# ==============================================================================
# 2. DATA EXTRACTION & HELPERS
# ==============================================================================


def hex_to_double(hex_str):
    """Converts hex string (LE) to double"""
    # Remove spaces and convert
    clean_hex = hex_str.replace(" ", "")
    return struct.unpack("<d", bytes.fromhex(clean_hex))[0]


def hex_to_double_be(hex_str):
    """Converts Big Endian hex string (Register Value) to double"""
    clean = hex_str.replace(" ", "")
    return struct.unpack(">d", bytes.fromhex(clean))[0]


def hex_to_float(hex_str):
    """Converts hex string (LE) to float"""
    clean_hex = hex_str.replace(" ", "")
    return struct.unpack("<f", bytes.fromhex(clean_hex))[0]


def lerp(a, b, t):
    return a + t * (b - a)


def interpolate_curve(knob_val, points):
    """Linear interpolation for parameter lookup"""
    sorted_keys = sorted(points.keys())
    if knob_val <= sorted_keys[0]:
        return points[sorted_keys[0]]
    if knob_val >= sorted_keys[-1]:
        return points[sorted_keys[-1]]

    for i in range(len(sorted_keys) - 1):
        k1 = sorted_keys[i]
        k2 = sorted_keys[i + 1]
        if k1 <= knob_val <= k2:
            t = (knob_val - k1) / (k2 - k1)
            return lerp(points[k1], points[k2], t)
    return 0.0


# --- Extracted Static Coefficients ---
# Band 0 (Mid Air)
MID_FILTER_COEFFS = [
    hex_to_double("5B 2C 5F 4E 93 C7 CB 3F"),  # P0
    hex_to_double("B9 F6 EC 6B 36 60 E9 3F"),  # P1
    hex_to_double("FF FF FF FF FF FF EF 3F"),  # P2
    0.0,  # P3 (Zeroed in dump)
    0.0,  # P4 (Zeroed in dump)
]

# Band 1 (High Air)
HIGH_FILTER_COEFFS = [
    hex_to_double("B5 C9 7F 88 D8 E1 E7 3F"),  # P0
    hex_to_double("10 51 A6 55 7E A1 E6 3F"),  # P1
    hex_to_double("00 00 00 00 00 00 F0 3F"),  # P2 (1.0)
    0.0,
    0.0,
]

# --- Extracted Dynamic Curves ---
MID_GAIN_CURVE = {
    0.00: hex_to_double_be("3FE51AED3F1C0A9C"),  # 0.6595
    0.25: hex_to_double_be("3FF088C83F7BBFBB"),  # 1.0334
    0.50: hex_to_double_be("3FF50ACE3FA1F00A"),  # 1.3151
    0.75: hex_to_double_be("3FF9A1693FC6A4EA"),  # 1.6019
    1.00: hex_to_double_be("3FFE7ACA3FED6FEC"),  # 1.9050
}

print(MID_GAIN_CURVE)

HIGH_LIMITER_THRESH_CURVE = {
    0.00: hex_to_float("9D 41 00 3F"),  # 0.501
    0.25: hex_to_float("2F 7C 95 3E"),  # 0.292
    0.50: hex_to_float("F2 BA 5F 3E"),  # 0.218
    0.75: hex_to_float("EA 7C 30 3E"),  # 0.172
    1.00: hex_to_float("37 4B 0F 3E"),  # 0.140
}

HIGH_LIMITER_SHAPE_CURVE = {  # Maps to Ratio/Slope
    0.00: hex_to_float("11 33 3D 3F"),
    0.25: hex_to_float("EF 18 23 3F"),
    0.50: hex_to_float("76 15 15 3F"),
    0.75: hex_to_float("50 9E 09 3F"),
    1.00: hex_to_float("EE 17 FF 3E"),
}

# ==============================================================================
# 3. THE FRESH AIR PROCESSOR
# ==============================================================================


class FreshAirClone:
    def __init__(self, sample_rate=44100.0):
        self.sample_rate = sample_rate

        # --- Lane 0: Mid Air ---
        self.mid_filter = UnknownFilter()
        self.mid_filter.set_params(*MID_FILTER_COEFFS)

        # Note: Mid compressor has fixed threshold ~0.0316 (from analysis)
        self.mid_compressor = UnknownCompressor(sample_rate)
        self.mid_compressor.threshold = 0.0316
        self.mid_compressor.mode = 0  # RMS Mode (implied by iVar2=0 in analysis)
        self.mid_compressor.ratio = 2.0  # Standard expansion ratio

        # --- Lane 1: High Air ---
        self.high_filter = UnknownFilter()
        self.high_filter.set_params(*HIGH_FILTER_COEFFS)

        self.high_gate = UnknownCompressor(sample_rate)  # Static Gate
        self.high_gate.threshold = 0.0  # Effectively pass-through if not specified

        self.high_gain = StereoGainMeter()

        self.high_limiter = UnknownCompressor(sample_rate)
        self.high_limiter.mode = 2  # Peak Mode

        # --- Lane 2: Output ---
        self.trim_gain = StereoGainMeter()
        self.static_pad = StereoGainMeter()

        # State
        self.knob_mid = 0.0
        self.knob_high = 0.0
        self.knob_trim = 0.0

    def set_parameters(self, mid_air: float, high_air: float, trim_db: float):
        """
        Update internal modules based on knob positions (0.0 to 1.0 for Air, dB for Trim)
        """
        self.knob_mid = mid_air
        self.knob_high = high_air
        self.knob_trim = trim_db

        # --- Update High Air Limiter ---
        # Map Slope back to Ratio: Slope = 1 - (1/Ratio) -> Ratio = 1 / (1 - Slope)
        slope = interpolate_curve(high_air, HIGH_LIMITER_SHAPE_CURVE)
        ratio = 1.0 / (1.0 - slope) if slope < 1.0 else 20.0

        self.high_limiter.threshold = interpolate_curve(
            high_air, HIGH_LIMITER_THRESH_CURVE
        )
        self.high_limiter.ratio = ratio

    def process(self, left_in, right_in):
        block_len = len(left_in)

        # --- Lane 0: Mid Air Processing ---
        # 1. Filter
        mid_l, mid_r = self.mid_filter.process(left_in, right_in)

        # 2. Apply Pre-Compressor Gain (The "Drive")
        # Logic: Gain = CurveVal - Offset(0.05) -> Derived from hex analysis
        mid_drive_raw = interpolate_curve(self.knob_mid, MID_GAIN_CURVE)
        # Note: Hex 0x3D4CCC... is approx 0.05.
        # However, raw hex 3FE5... is 0.6595. 0.6595 - 0.05 = 0.6095 (Min Gain)
        mid_drive = mid_drive_raw - 0.05

        mid_l = [s * mid_drive for s in mid_l]
        mid_r = [s * mid_drive for s in mid_r]

        # 3. Compressor (Expander Logic via low threshold)
        mid_l, mid_r = self.mid_compressor.process_block(mid_l, mid_r)

        # --- Lane 1: High Air Processing ---
        # 1. Filter
        high_l, high_r = self.high_filter.process(left_in, right_in)

        # 2. Gate (Pass-through in this implementation as it is static)
        high_l, high_r = self.high_gate.process_block(high_l, high_r)

        # 3. Gain (Dynamic Boost)
        # Curve: 1.0 + 0.9 * pow(knob, 0.8)
        high_boost = 1.0 + 0.8962 * math.pow(self.knob_high, 0.8)
        self.high_gain.process_block(high_l, high_r, 0, high_boost, 0.0)

        # 4. Limiter (Dynamic Thresholds)
        high_l, high_r = self.high_limiter.process_block(high_l, high_r)

        # --- Summing & Output ---
        out_l = []
        out_r = []

        for i in range(block_len):
            # Sum: Dry + Mid + High
            sum_l = left_in[i] + mid_l[i] + high_l[i]
            sum_r = right_in[i] + mid_r[i] + high_r[i]
            out_l.append(sum_l)
            out_r.append(sum_r)

        # --- Lane 2: Output Trim ---
        trim_lin = math.pow(10, self.knob_trim / 20.0)
        self.trim_gain.process_block(out_l, out_r, 0, trim_lin, 0.0)

        # Static Pad (0.822 / -1.7dB) found in analysis
        pad_val = 0.822
        self.static_pad.process_block(out_l, out_r, 0, pad_val, 0.0)

        return out_l, out_r


import numpy as np
import matplotlib.pyplot as plt


def measure_frequency_response(plugin, duration_sec=2.0, sample_rate=44100):
    """
    Generates a log sweep, runs it through the plugin, and calculates magnitude response.
    """
    # 1. Generate Logarithmic Sine Sweep (20Hz to 20kHz)
    t = np.linspace(0, duration_sec, int(sample_rate * duration_sec))
    f_start = 20.0
    f_end = 30000.0

    # Standard Log Sweep Formula: sin(2*pi * f_start * T * ( (f_end/f_start)^(t/T) - 1) / ln(f_end/f_start))
    k = np.log(f_end / f_start) / duration_sec
    phase = 2 * np.pi * f_start * (np.exp(k * t) - 1) / k
    input_signal = np.sin(phase)

    # Normalize input to -18dBFS (standard headroom for dynamic plugins)
    # This is important because Fresh Air is dynamic; louder inputs change the curve!
    input_gain = 10 ** (-18 / 20)
    input_signal *= input_gain

    # 2. Process through Plugin
    # (Convert numpy to list for our class, then back)
    print(f"Processing {len(input_signal)} samples...")
    out_l, out_r = plugin.process(input_signal.tolist(), input_signal.tolist())
    output_signal = np.array(out_l)

    # 3. Calculate Envelope (Magnitude)
    # We use the Hilbert transform to get the analytic signal envelope
    # or a simple peak-hold sliding window for visualization.
    # For a clean plot, we can compare input vs output envelope.

    # Simple approach: Windowed RMS
    window_size = 1000
    # Create a frequency axis corresponding to time
    freqs_over_time = f_start * (f_end / f_start) ** (t / duration_sec)

    # Calculate Gain (Output / Input) in dB
    # We avoid division by zero/noise by adding epsilon
    gain_curve_db = []
    plot_freqs = []

    step = 100  # Downsample for plotting speed
    for i in range(0, len(t) - window_size, step):
        # Get chunk
        in_chunk = input_signal[i : i + window_size]
        out_chunk = output_signal[i : i + window_size]

        # Calc RMS
        rms_in = np.sqrt(np.mean(in_chunk**2))
        rms_out = np.sqrt(np.mean(out_chunk**2))

        if rms_in > 1e-6:
            # Calculate dB difference
            db = 20 * np.log10(rms_out / rms_in)
            gain_curve_db.append(db)
            plot_freqs.append(freqs_over_time[i + window_size // 2])

    return plot_freqs, gain_curve_db


if __name__ == "__main__":
    # 1. Initialize
    sr = 176400
    plugin = FreshAirClone(sample_rate=sr)

    # 2. Configure: BOTH KNOBS @ 100%
    # Note: Input level matters! At -18dBFS input, we expect a smooth boost.
    # At 0dBFS input, the limiter in High Air will flatten the top.
    mid_air = 0.0
    high_air = 0.05
    plugin.set_parameters(mid_air=mid_air, high_air=high_air, trim_db=0.0)

    print(f"Running Frequency Sweep (Mid={mid_air*100}%, High={high_air*100}%)...")
    freqs, db_response = measure_frequency_response(
        plugin, duration_sec=3.0, sample_rate=sr
    )

    print(db_response)

    # 3. Plot
    plt.figure(figsize=(10, 6))
    plt.semilogx(freqs, db_response, linewidth=2, color="#00ccff")

    # Formatting
    plt.title("Fresh Air Clone - Frequency Response (100% Amount)")
    plt.xlabel("Frequency (Hz)")
    plt.ylabel("Gain (dB)")
    plt.grid(True, which="both", ls="-", alpha=0.5)

    # Set Axis Limits for clarity
    plt.xlim(20, 30000)
    # Y-Axis centered around 0dB to show the boost
    plt.ylim(-2, 15)

    # Add markers for standard bands
    plt.axvline(
        x=2500, color="gray", linestyle="--", alpha=0.5, label="Mid Air Region (~2.5k)"
    )
    plt.axvline(
        x=10000, color="gray", linestyle="--", alpha=0.5, label="High Air Region (~10k)"
    )
    plt.legend()

    plt.tight_layout()
    plt.show()
