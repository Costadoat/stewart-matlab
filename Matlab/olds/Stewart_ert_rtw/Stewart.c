/*
 * File: Stewart.c
 *
 * Code generated for Simulink model 'Stewart'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Thu Jan 26 18:55:36 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Stewart.h"
#include "Stewart_private.h"
#include "Stewart_dt.h"

/* Block signals (auto storage) */
B_Stewart_T Stewart_B;

/* Real-time model */
RT_MODEL_Stewart_T Stewart_M_;
RT_MODEL_Stewart_T *const Stewart_M = &Stewart_M_;
real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void Stewart_step(void)
{
  uint16_T rtb_Potentiomtre1_0;
  real_T rtb_Divide_ncka1fctzt;
  boolean_T tmp;
  int16_T i;
  int32_T tmp_0;
  real_T rtb_Divide_l0wo3ief2w;
  uint8_T tmp_1;

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S17>/theta_x'
   *  Constant: '<S17>/theta_y'
   *  Constant: '<S17>/theta_z'
   *  Constant: '<S17>/x'
   *  Constant: '<S17>/y'
   *  Constant: '<S17>/z'
   *  Constant: '<S6>/theta_x'
   *  Constant: '<S6>/theta_y'
   *  Constant: '<S6>/theta_z'
   *  Constant: '<S6>/x'
   *  Constant: '<S6>/y'
   *  Sin: '<S6>/z'
   */
  tmp = (0.0 >= Stewart_P.Switch_Threshold);
  Stewart_B.dv0[0] = Stewart_P.theta_x_Value;
  Stewart_B.dv0[1] = Stewart_P.theta_y_Value;
  Stewart_B.dv0[2] = Stewart_P.theta_z_Value;
  Stewart_B.dv0[3] = Stewart_P.x_Value;
  Stewart_B.dv0[4] = Stewart_P.y_Value;
  Stewart_B.dv0[5] = Stewart_P.z_Value;
  Stewart_B.dv1[0] = Stewart_P.theta_x_Value_ekze1zr2o2;
  Stewart_B.dv1[1] = Stewart_P.theta_y_Value_hpy1hkark1;
  Stewart_B.dv1[2] = Stewart_P.theta_z_Value_gi4rxypddg;
  Stewart_B.dv1[3] = Stewart_P.x_Value_erhep10kxc;
  Stewart_B.dv1[4] = Stewart_P.y_Value_au20vl24uo;
  Stewart_B.dv1[5] = sin(Stewart_P.z_Freq * Stewart_M->Timing.t[0] +
    Stewart_P.z_Phase) * Stewart_P.z_Amp + Stewart_P.z_Bias;
  for (i = 0; i < 6; i++) {
    if (tmp) {
      Stewart_B.Switch[i] = Stewart_B.dv0[i];
    } else {
      Stewart_B.Switch[i] = Stewart_B.dv1[i];
    }
  }

  /* End of Switch: '<S5>/Switch' */

  /* Fcn: '<Root>/L1' incorporates:
   *  Constant: '<S16>/alpha'
   *  Constant: '<S16>/beta'
   *  Constant: '<S16>/h'
   *  Constant: '<S16>/rf'
   *  Constant: '<S16>/rm'
   */
  rtb_Divide_ncka1fctzt = (rt_powd_snf((((cos(1.0471975511965976 +
    Stewart_B.Switch[2]) * cos(Stewart_B.Switch[1]) - sin(1.0471975511965976 +
    Stewart_B.Switch[2]) * sin(Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1])) *
    Stewart_P.rm_Value * cos(Stewart_P.beta_Value) + sin(1.0471975511965976 +
    Stewart_B.Switch[2]) * cos(Stewart_B.Switch[0]) * Stewart_P.rm_Value * sin
    (Stewart_P.beta_Value)) - Stewart_P.rf_Value * cos(Stewart_P.alpha_Value)) +
    Stewart_B.Switch[3], 2.0) + rt_powd_snf((((cos(1.0471975511965976 +
    Stewart_B.Switch[2]) * sin(Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1]) +
    sin(1.0471975511965976 + Stewart_B.Switch[2]) * cos(Stewart_B.Switch[1])) *
    Stewart_P.rm_Value * cos(Stewart_P.beta_Value) - cos(1.0471975511965976 +
    Stewart_B.Switch[2]) * cos(Stewart_B.Switch[0]) * Stewart_P.rm_Value * sin
    (Stewart_P.beta_Value)) - Stewart_P.rf_Value * sin(Stewart_P.alpha_Value)) +
    Stewart_B.Switch[4], 2.0)) + rt_powd_snf(((-cos(Stewart_B.Switch[0]) * sin
    (Stewart_B.Switch[1]) * Stewart_P.rm_Value * cos(Stewart_P.beta_Value) - sin
    (Stewart_B.Switch[0]) * Stewart_P.rm_Value * sin(Stewart_P.beta_Value)) +
    Stewart_P.h_Value) + Stewart_B.Switch[5], 2.0);
  if (rtb_Divide_ncka1fctzt < 0.0) {
    Stewart_B.L1 = -sqrt(-rtb_Divide_ncka1fctzt);
  } else {
    Stewart_B.L1 = sqrt(rtb_Divide_ncka1fctzt);
  }

  /* End of Fcn: '<Root>/L1' */

  /* S-Function (arduinoanaloginput_sfcn): '<Root>/Potentiomètre 1' */
  rtb_Potentiomtre1_0 = MW_analogRead(Stewart_P.Potentiomtre1_p1);

  /* Sum: '<S3>/Add1' incorporates:
   *  Constant: '<S3>/Lmax'
   *  Constant: '<S3>/Lmin'
   *  Gain: '<S3>/Gain1'
   *  Product: '<S3>/Divide'
   *  S-Function (arduinoanaloginput_sfcn): '<Root>/Potentiomètre 1'
   *  Sum: '<S3>/Add'
   */
  Stewart_B.Add1 = (real_T)((uint32_T)Stewart_P.Gain1_Gain_jfd0ao4z3a *
    rtb_Potentiomtre1_0) * 2.9802322387695313E-8 * (Stewart_P.Lmax_Value -
    Stewart_P.Lmin_Value) + Stewart_P.Lmin_Value;

  /* Gain: '<Root>/Gain6' incorporates:
   *  Sum: '<Root>/Add1'
   */
  Stewart_B.Gain6 = (Stewart_B.L1 - Stewart_B.Add1) * Stewart_P.Gain6_Gain;

  /* Saturate: '<S1>/Saturation' */
  if (Stewart_B.Gain6 > Stewart_P.Saturation_UpperSat) {
    rtb_Divide_ncka1fctzt = Stewart_P.Saturation_UpperSat;
  } else if (Stewart_B.Gain6 < Stewart_P.Saturation_LowerSat) {
    rtb_Divide_ncka1fctzt = Stewart_P.Saturation_LowerSat;
  } else {
    rtb_Divide_ncka1fctzt = Stewart_B.Gain6;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Signum: '<S1>/Sign' */
  if (rtb_Divide_ncka1fctzt < 0.0) {
    rtb_Divide_l0wo3ief2w = -1.0;
  } else if (rtb_Divide_ncka1fctzt > 0.0) {
    rtb_Divide_l0wo3ief2w = 1.0;
  } else if (rtb_Divide_ncka1fctzt == 0.0) {
    rtb_Divide_l0wo3ief2w = 0.0;
  } else {
    rtb_Divide_l0wo3ief2w = rtb_Divide_ncka1fctzt;
  }

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Signum: '<S1>/Sign'
   *  Sum: '<S1>/Add'
   */
  Stewart_B.Divide = (Stewart_P.Constant_Value + rtb_Divide_l0wo3ief2w) /
    Stewart_P.Constant1_Value;

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (Stewart_B.Divide < 256.0) {
    if (Stewart_B.Divide >= 0.0) {
      tmp_1 = (uint8_T)Stewart_B.Divide;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_digitalWrite(Stewart_P.DigitalOutput_pinNumber, tmp_1);

  /* Abs: '<S1>/Abs' */
  rtb_Divide_ncka1fctzt = fabs(rtb_Divide_ncka1fctzt);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Bias: '<S15>/Add min y'
   *  Bias: '<S15>/Subtract min x'
   *  Gain: '<S15>/range y // range x'
   */
  rtb_Divide_l0wo3ief2w = floor((Stewart_P.mapminmax_ymax -
    Stewart_P.mapminmax_ymin) / (Stewart_P.mapminmax_xmax -
    Stewart_P.mapminmax_xmin) * (rtb_Divide_ncka1fctzt +
    -Stewart_P.mapminmax_xmin) + Stewart_P.mapminmax_ymin);
  if (rtIsNaN(rtb_Divide_l0wo3ief2w) || rtIsInf(rtb_Divide_l0wo3ief2w)) {
    rtb_Divide_l0wo3ief2w = 0.0;
  } else {
    rtb_Divide_l0wo3ief2w = fmod(rtb_Divide_l0wo3ief2w, 4.294967296E+9);
  }

  Stewart_B.DataTypeConversion = rtb_Divide_l0wo3ief2w < 0.0 ? -(int32_T)
    (uint32_T)-rtb_Divide_l0wo3ief2w : (int32_T)(uint32_T)rtb_Divide_l0wo3ief2w;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  tmp_0 = Stewart_B.DataTypeConversion;
  if (Stewart_B.DataTypeConversion < 0L) {
    tmp_0 = 0L;
  } else {
    if ((uint32_T)Stewart_B.DataTypeConversion > 255UL) {
      tmp_0 = 255L;
    }
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S8>/PWM' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   */
  MW_analogWrite(Stewart_P.PWM_pinNumber, (uint8_T)tmp_0);

  /* Fcn: '<Root>/L2' incorporates:
   *  Constant: '<S16>/alpha'
   *  Constant: '<S16>/beta'
   *  Constant: '<S16>/h'
   *  Constant: '<S16>/rf'
   *  Constant: '<S16>/rm'
   */
  rtb_Divide_ncka1fctzt = (rt_powd_snf((((cos(1.0471975511965976 +
    Stewart_B.Switch[2]) * cos(Stewart_B.Switch[1]) - sin(1.0471975511965976 +
    Stewart_B.Switch[2]) * sin(Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1])) *
    Stewart_P.rm_Value * cos(Stewart_P.beta_Value) - sin(1.0471975511965976 +
    Stewart_B.Switch[2]) * cos(Stewart_B.Switch[0]) * Stewart_P.rm_Value * sin
    (Stewart_P.beta_Value)) + cos(1.0471975511965976 + Stewart_P.alpha_Value) *
    Stewart_P.rf_Value) + Stewart_B.Switch[3], 2.0) + rt_powd_snf((((cos
    (1.0471975511965976 + Stewart_B.Switch[2]) * sin(Stewart_B.Switch[0]) * sin
    (Stewart_B.Switch[1]) + sin(1.0471975511965976 + Stewart_B.Switch[2]) * cos
    (Stewart_B.Switch[1])) * Stewart_P.rm_Value * cos(Stewart_P.beta_Value) +
    cos(1.0471975511965976 + Stewart_B.Switch[2]) * cos(Stewart_B.Switch[0]) *
    Stewart_P.rm_Value * sin(Stewart_P.beta_Value)) - sin(1.0471975511965976 +
    Stewart_P.alpha_Value) * Stewart_P.rf_Value) + Stewart_B.Switch[4], 2.0)) +
    rt_powd_snf(((-cos(Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1]) *
                  Stewart_P.rm_Value * cos(Stewart_P.beta_Value) + sin
                  (Stewart_B.Switch[0]) * Stewart_P.rm_Value * sin
                  (Stewart_P.beta_Value)) + Stewart_P.h_Value) +
                Stewart_B.Switch[5], 2.0);

  /* S-Function (arduinoanaloginput_sfcn): '<S9>/Potentiomètre 2' */
  rtb_Potentiomtre1_0 = MW_analogRead(Stewart_P.Potentiomtre2_p1);

  /* Fcn: '<Root>/L2' */
  if (rtb_Divide_ncka1fctzt < 0.0) {
    rtb_Divide_ncka1fctzt = -sqrt(-rtb_Divide_ncka1fctzt);
  } else {
    rtb_Divide_ncka1fctzt = sqrt(rtb_Divide_ncka1fctzt);
  }

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S20>/Lmax'
   *  Constant: '<S20>/Lmin'
   *  Gain: '<S20>/Gain1'
   *  Product: '<S20>/Divide'
   *  S-Function (arduinoanaloginput_sfcn): '<S9>/Potentiomètre 2'
   *  Sum: '<S20>/Add'
   *  Sum: '<S20>/Add1'
   *  Sum: '<S9>/Add2'
   */
  rtb_Divide_ncka1fctzt = (rtb_Divide_ncka1fctzt - ((real_T)((uint32_T)
    Stewart_P.Gain1_Gain_m20otgelwl * rtb_Potentiomtre1_0) *
    2.9802322387695313E-8 * (Stewart_P.Lmax_Value_fp0qrty4ea -
    Stewart_P.Lmin_Value_fxiqxw14ju) + Stewart_P.Lmin_Value_fxiqxw14ju)) *
    Stewart_P.Gain1_Gain;

  /* Saturate: '<S18>/Saturation' */
  if (rtb_Divide_ncka1fctzt > Stewart_P.Saturation_UpperSat_b3rn2kfzri) {
    rtb_Divide_ncka1fctzt = Stewart_P.Saturation_UpperSat_b3rn2kfzri;
  } else {
    if (rtb_Divide_ncka1fctzt < Stewart_P.Saturation_LowerSat_bvomtudfti) {
      rtb_Divide_ncka1fctzt = Stewart_P.Saturation_LowerSat_bvomtudfti;
    }
  }

  /* End of Saturate: '<S18>/Saturation' */

  /* Signum: '<S18>/Sign' */
  if (rtb_Divide_ncka1fctzt < 0.0) {
    rtb_Divide_l0wo3ief2w = -1.0;
  } else if (rtb_Divide_ncka1fctzt > 0.0) {
    rtb_Divide_l0wo3ief2w = 1.0;
  } else if (rtb_Divide_ncka1fctzt == 0.0) {
    rtb_Divide_l0wo3ief2w = 0.0;
  } else {
    rtb_Divide_l0wo3ief2w = rtb_Divide_ncka1fctzt;
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant1'
   *  Product: '<S18>/Divide'
   *  Signum: '<S18>/Sign'
   *  Sum: '<S18>/Add'
   */
  rtb_Divide_l0wo3ief2w = (Stewart_P.Constant_Value_cxtxrspyx2 +
    rtb_Divide_l0wo3ief2w) / Stewart_P.Constant1_Value_cnehq0fw23;
  if (rtb_Divide_l0wo3ief2w < 256.0) {
    if (rtb_Divide_l0wo3ief2w >= 0.0) {
      tmp_1 = (uint8_T)rtb_Divide_l0wo3ief2w;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S19>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S19>/Digital Output' */
  MW_digitalWrite(Stewart_P.DigitalOutput_pinNum_ek4xiwztl1, tmp_1);

  /* Abs: '<S18>/Abs' */
  rtb_Divide_ncka1fctzt = fabs(rtb_Divide_ncka1fctzt);

  /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
   *  Bias: '<S22>/Add min y'
   *  Bias: '<S22>/Subtract min x'
   *  Gain: '<S22>/range y // range x'
   */
  rtb_Divide_l0wo3ief2w = floor((Stewart_P.mapminmax_ymax_iej5kpatil -
    Stewart_P.mapminmax_ymin_k5go5squy4) / (Stewart_P.mapminmax_xmax_d3hx0fzg3v
    - Stewart_P.mapminmax_xmin_iehjoea5ea) * (rtb_Divide_ncka1fctzt +
    -Stewart_P.mapminmax_xmin_iehjoea5ea) + Stewart_P.mapminmax_ymin_k5go5squy4);
  if (rtIsNaN(rtb_Divide_l0wo3ief2w) || rtIsInf(rtb_Divide_l0wo3ief2w)) {
    rtb_Divide_l0wo3ief2w = 0.0;
  } else {
    rtb_Divide_l0wo3ief2w = fmod(rtb_Divide_l0wo3ief2w, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S21>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   */
  tmp_0 = rtb_Divide_l0wo3ief2w < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Divide_l0wo3ief2w : (int32_T)(uint32_T)rtb_Divide_l0wo3ief2w;
  if (tmp_0 < 0L) {
    tmp_0 = 0L;
  } else {
    if ((uint32_T)tmp_0 > 255UL) {
      tmp_0 = 255L;
    }
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S21>/PWM' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion'
   */
  MW_analogWrite(Stewart_P.PWM_pinNumber_nkrnw2yx44, (uint8_T)tmp_0);

  /* Fcn: '<Root>/L3' incorporates:
   *  Constant: '<S16>/alpha'
   *  Constant: '<S16>/beta'
   *  Constant: '<S16>/h'
   *  Constant: '<S16>/rf'
   *  Constant: '<S16>/rm'
   */
  rtb_Divide_ncka1fctzt = (rt_powd_snf(((-(cos(1.0471975511965976 +
    Stewart_B.Switch[2]) * cos(Stewart_B.Switch[1]) - sin(1.0471975511965976 +
    Stewart_B.Switch[2]) * sin(Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1])) *
    Stewart_P.rm_Value * cos(1.0471975511965976 + Stewart_P.beta_Value) - sin
    (1.0471975511965976 + Stewart_B.Switch[2]) * cos(Stewart_B.Switch[0]) *
    Stewart_P.rm_Value * sin(1.0471975511965976 + Stewart_P.beta_Value)) + sin
    (0.52359877559829882 + Stewart_P.alpha_Value) * Stewart_P.rf_Value) +
    Stewart_B.Switch[3], 2.0) + rt_powd_snf(((-(cos(1.0471975511965976 +
    Stewart_B.Switch[2]) * sin(Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1]) +
    sin(1.0471975511965976 + Stewart_B.Switch[2]) * cos(Stewart_B.Switch[1])) *
    Stewart_P.rm_Value * cos(1.0471975511965976 + Stewart_P.beta_Value) + cos
    (1.0471975511965976 + Stewart_B.Switch[2]) * cos(Stewart_B.Switch[0]) *
    Stewart_P.rm_Value * sin(1.0471975511965976 + Stewart_P.beta_Value)) - cos
    (0.52359877559829882 + Stewart_P.alpha_Value) * Stewart_P.rf_Value) +
    Stewart_B.Switch[4], 2.0)) + rt_powd_snf(((cos(Stewart_B.Switch[0]) * sin
    (Stewart_B.Switch[1]) * Stewart_P.rm_Value * cos(1.0471975511965976 +
    Stewart_P.beta_Value) + sin(Stewart_B.Switch[0]) * Stewart_P.rm_Value * sin
    (1.0471975511965976 + Stewart_P.beta_Value)) + Stewart_P.h_Value) +
    Stewart_B.Switch[5], 2.0);

  /* S-Function (arduinoanaloginput_sfcn): '<S10>/Potentiomètre 3' */
  rtb_Potentiomtre1_0 = MW_analogRead(Stewart_P.Potentiomtre3_p1);

  /* Fcn: '<Root>/L3' */
  if (rtb_Divide_ncka1fctzt < 0.0) {
    rtb_Divide_ncka1fctzt = -sqrt(-rtb_Divide_ncka1fctzt);
  } else {
    rtb_Divide_ncka1fctzt = sqrt(rtb_Divide_ncka1fctzt);
  }

  /* Gain: '<S10>/Gain2' incorporates:
   *  Constant: '<S25>/Lmax'
   *  Constant: '<S25>/Lmin'
   *  Gain: '<S25>/Gain1'
   *  Product: '<S25>/Divide'
   *  S-Function (arduinoanaloginput_sfcn): '<S10>/Potentiomètre 3'
   *  Sum: '<S10>/Add3'
   *  Sum: '<S25>/Add'
   *  Sum: '<S25>/Add1'
   */
  rtb_Divide_ncka1fctzt = (rtb_Divide_ncka1fctzt - ((real_T)((uint32_T)
    Stewart_P.Gain1_Gain_btfs54h4bx * rtb_Potentiomtre1_0) *
    2.9802322387695313E-8 * (Stewart_P.Lmax_Value_nmppsrzwc4 -
    Stewart_P.Lmin_Value_d1kp3d2x14) + Stewart_P.Lmin_Value_d1kp3d2x14)) *
    Stewart_P.Gain2_Gain;

  /* Saturate: '<S23>/Saturation' */
  if (rtb_Divide_ncka1fctzt > Stewart_P.Saturation_UpperSat_dnbjpnjl05) {
    rtb_Divide_ncka1fctzt = Stewart_P.Saturation_UpperSat_dnbjpnjl05;
  } else {
    if (rtb_Divide_ncka1fctzt < Stewart_P.Saturation_LowerSat_am0q0a0ygv) {
      rtb_Divide_ncka1fctzt = Stewart_P.Saturation_LowerSat_am0q0a0ygv;
    }
  }

  /* End of Saturate: '<S23>/Saturation' */

  /* Signum: '<S23>/Sign' */
  if (rtb_Divide_ncka1fctzt < 0.0) {
    rtb_Divide_l0wo3ief2w = -1.0;
  } else if (rtb_Divide_ncka1fctzt > 0.0) {
    rtb_Divide_l0wo3ief2w = 1.0;
  } else if (rtb_Divide_ncka1fctzt == 0.0) {
    rtb_Divide_l0wo3ief2w = 0.0;
  } else {
    rtb_Divide_l0wo3ief2w = rtb_Divide_ncka1fctzt;
  }

  /* DataTypeConversion: '<S24>/Data Type Conversion' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S23>/Constant1'
   *  Product: '<S23>/Divide'
   *  Signum: '<S23>/Sign'
   *  Sum: '<S23>/Add'
   */
  rtb_Divide_l0wo3ief2w = (Stewart_P.Constant_Value_dqqxjknpbv +
    rtb_Divide_l0wo3ief2w) / Stewart_P.Constant1_Value_bzdab4one2;
  if (rtb_Divide_l0wo3ief2w < 256.0) {
    if (rtb_Divide_l0wo3ief2w >= 0.0) {
      tmp_1 = (uint8_T)rtb_Divide_l0wo3ief2w;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S24>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S24>/Digital Output' */
  MW_digitalWrite(Stewart_P.DigitalOutput_pinNum_hetit3zm4v, tmp_1);

  /* Abs: '<S23>/Abs' */
  rtb_Divide_ncka1fctzt = fabs(rtb_Divide_ncka1fctzt);

  /* DataTypeConversion: '<S23>/Data Type Conversion' incorporates:
   *  Bias: '<S27>/Add min y'
   *  Bias: '<S27>/Subtract min x'
   *  Gain: '<S27>/range y // range x'
   */
  rtb_Divide_l0wo3ief2w = floor((Stewart_P.mapminmax_ymax_jfea2ow0og -
    Stewart_P.mapminmax_ymin_ogggrkrg4e) / (Stewart_P.mapminmax_xmax_i1mgu1wczb
    - Stewart_P.mapminmax_xmin_cuaeahpuiv) * (rtb_Divide_ncka1fctzt +
    -Stewart_P.mapminmax_xmin_cuaeahpuiv) + Stewart_P.mapminmax_ymin_ogggrkrg4e);
  if (rtIsNaN(rtb_Divide_l0wo3ief2w) || rtIsInf(rtb_Divide_l0wo3ief2w)) {
    rtb_Divide_l0wo3ief2w = 0.0;
  } else {
    rtb_Divide_l0wo3ief2w = fmod(rtb_Divide_l0wo3ief2w, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S26>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   */
  tmp_0 = rtb_Divide_l0wo3ief2w < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Divide_l0wo3ief2w : (int32_T)(uint32_T)rtb_Divide_l0wo3ief2w;
  if (tmp_0 < 0L) {
    tmp_0 = 0L;
  } else {
    if ((uint32_T)tmp_0 > 255UL) {
      tmp_0 = 255L;
    }
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S26>/PWM' incorporates:
   *  DataTypeConversion: '<S26>/Data Type Conversion'
   */
  MW_analogWrite(Stewart_P.PWM_pinNumber_hoyrwcvift, (uint8_T)tmp_0);

  /* Fcn: '<Root>/L4' incorporates:
   *  Constant: '<S16>/alpha'
   *  Constant: '<S16>/beta'
   *  Constant: '<S16>/h'
   *  Constant: '<S16>/rf'
   *  Constant: '<S16>/rm'
   */
  rtb_Divide_ncka1fctzt = (rt_powd_snf(((-(cos(1.0471975511965976 +
    Stewart_B.Switch[2]) * cos(Stewart_B.Switch[1]) - sin(1.0471975511965976 +
    Stewart_B.Switch[2]) * sin(Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1])) *
    Stewart_P.rm_Value * sin(0.52359877559829882 + Stewart_P.beta_Value) - sin
    (1.0471975511965976 + Stewart_B.Switch[2]) * cos(Stewart_B.Switch[0]) *
    Stewart_P.rm_Value * cos(0.52359877559829882 + Stewart_P.beta_Value)) + sin
    (0.52359877559829882 + Stewart_P.alpha_Value) * Stewart_P.rf_Value) +
    Stewart_B.Switch[3], 2.0) + rt_powd_snf(((-(cos(1.0471975511965976 +
    Stewart_B.Switch[2]) * sin(Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1]) +
    sin(1.0471975511965976 + Stewart_B.Switch[2]) * cos(Stewart_B.Switch[1])) *
    Stewart_P.rm_Value * sin(0.52359877559829882 + Stewart_P.beta_Value) + cos
    (1.0471975511965976 + Stewart_B.Switch[2]) * cos(Stewart_B.Switch[0]) *
    Stewart_P.rm_Value * cos(0.52359877559829882 + Stewart_P.beta_Value)) + cos
    (0.52359877559829882 + Stewart_P.alpha_Value) * Stewart_P.rf_Value) +
    Stewart_B.Switch[4], 2.0)) + rt_powd_snf(((cos(Stewart_B.Switch[0]) * sin
    (Stewart_B.Switch[1]) * Stewart_P.rm_Value * sin(0.52359877559829882 +
    Stewart_P.beta_Value) + sin(Stewart_B.Switch[0]) * Stewart_P.rm_Value * cos
    (0.52359877559829882 + Stewart_P.beta_Value)) + Stewart_P.h_Value) +
    Stewart_B.Switch[5], 2.0);

  /* S-Function (arduinoanaloginput_sfcn): '<S11>/Potentiomètre 4' */
  rtb_Potentiomtre1_0 = MW_analogRead(Stewart_P.Potentiomtre4_p1);

  /* Fcn: '<Root>/L4' */
  if (rtb_Divide_ncka1fctzt < 0.0) {
    rtb_Divide_ncka1fctzt = -sqrt(-rtb_Divide_ncka1fctzt);
  } else {
    rtb_Divide_ncka1fctzt = sqrt(rtb_Divide_ncka1fctzt);
  }

  /* Gain: '<S11>/Gain3' incorporates:
   *  Constant: '<S30>/Lmax'
   *  Constant: '<S30>/Lmin'
   *  Gain: '<S30>/Gain1'
   *  Product: '<S30>/Divide'
   *  S-Function (arduinoanaloginput_sfcn): '<S11>/Potentiomètre 4'
   *  Sum: '<S11>/Add4'
   *  Sum: '<S30>/Add'
   *  Sum: '<S30>/Add1'
   */
  rtb_Divide_ncka1fctzt = (rtb_Divide_ncka1fctzt - ((real_T)((uint32_T)
    Stewart_P.Gain1_Gain_ptftxodxyn * rtb_Potentiomtre1_0) *
    2.9802322387695313E-8 * (Stewart_P.Lmax_Value_lhquxpnirq -
    Stewart_P.Lmin_Value_jjhk2iniiu) + Stewart_P.Lmin_Value_jjhk2iniiu)) *
    Stewart_P.Gain3_Gain;

  /* Saturate: '<S28>/Saturation' */
  if (rtb_Divide_ncka1fctzt > Stewart_P.Saturation_UpperSat_llrmljpyl3) {
    rtb_Divide_ncka1fctzt = Stewart_P.Saturation_UpperSat_llrmljpyl3;
  } else {
    if (rtb_Divide_ncka1fctzt < Stewart_P.Saturation_LowerSat_ld4hzxvf1k) {
      rtb_Divide_ncka1fctzt = Stewart_P.Saturation_LowerSat_ld4hzxvf1k;
    }
  }

  /* End of Saturate: '<S28>/Saturation' */

  /* Signum: '<S28>/Sign' */
  if (rtb_Divide_ncka1fctzt < 0.0) {
    rtb_Divide_l0wo3ief2w = -1.0;
  } else if (rtb_Divide_ncka1fctzt > 0.0) {
    rtb_Divide_l0wo3ief2w = 1.0;
  } else if (rtb_Divide_ncka1fctzt == 0.0) {
    rtb_Divide_l0wo3ief2w = 0.0;
  } else {
    rtb_Divide_l0wo3ief2w = rtb_Divide_ncka1fctzt;
  }

  /* DataTypeConversion: '<S29>/Data Type Conversion' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant1'
   *  Product: '<S28>/Divide'
   *  Signum: '<S28>/Sign'
   *  Sum: '<S28>/Add'
   */
  rtb_Divide_l0wo3ief2w = (Stewart_P.Constant_Value_ohnaqb1c5m +
    rtb_Divide_l0wo3ief2w) / Stewart_P.Constant1_Value_fhaxeoxakj;
  if (rtb_Divide_l0wo3ief2w < 256.0) {
    if (rtb_Divide_l0wo3ief2w >= 0.0) {
      tmp_1 = (uint8_T)rtb_Divide_l0wo3ief2w;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S29>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S29>/Digital Output' */
  MW_digitalWrite(Stewart_P.DigitalOutput_pinNum_bkde3yd3cq, tmp_1);

  /* Abs: '<S28>/Abs' */
  rtb_Divide_ncka1fctzt = fabs(rtb_Divide_ncka1fctzt);

  /* DataTypeConversion: '<S28>/Data Type Conversion' incorporates:
   *  Bias: '<S32>/Add min y'
   *  Bias: '<S32>/Subtract min x'
   *  Gain: '<S32>/range y // range x'
   */
  rtb_Divide_l0wo3ief2w = floor((Stewart_P.mapminmax_ymax_ihor11sths -
    Stewart_P.mapminmax_ymin_jjvvjjkkrv) / (Stewart_P.mapminmax_xmax_aub2z1f52q
    - Stewart_P.mapminmax_xmin_k4al5ovj24) * (rtb_Divide_ncka1fctzt +
    -Stewart_P.mapminmax_xmin_k4al5ovj24) + Stewart_P.mapminmax_ymin_jjvvjjkkrv);
  if (rtIsNaN(rtb_Divide_l0wo3ief2w) || rtIsInf(rtb_Divide_l0wo3ief2w)) {
    rtb_Divide_l0wo3ief2w = 0.0;
  } else {
    rtb_Divide_l0wo3ief2w = fmod(rtb_Divide_l0wo3ief2w, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S31>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S28>/Data Type Conversion'
   */
  tmp_0 = rtb_Divide_l0wo3ief2w < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Divide_l0wo3ief2w : (int32_T)(uint32_T)rtb_Divide_l0wo3ief2w;
  if (tmp_0 < 0L) {
    tmp_0 = 0L;
  } else {
    if ((uint32_T)tmp_0 > 255UL) {
      tmp_0 = 255L;
    }
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S31>/PWM' incorporates:
   *  DataTypeConversion: '<S31>/Data Type Conversion'
   */
  MW_analogWrite(Stewart_P.PWM_pinNumber_mx02rvdlnc, (uint8_T)tmp_0);

  /* Fcn: '<Root>/L5' incorporates:
   *  Constant: '<S16>/alpha'
   *  Constant: '<S16>/beta'
   *  Constant: '<S16>/h'
   *  Constant: '<S16>/rf'
   *  Constant: '<S16>/rm'
   */
  rtb_Divide_ncka1fctzt = (rt_powd_snf(((-(cos(1.0471975511965976 +
    Stewart_B.Switch[2]) * cos(Stewart_B.Switch[1]) - sin(1.0471975511965976 +
    Stewart_B.Switch[2]) * sin(Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1])) *
    Stewart_P.rm_Value * sin(0.52359877559829882 + Stewart_P.beta_Value) + sin
    (1.0471975511965976 + Stewart_B.Switch[2]) * cos(Stewart_B.Switch[0]) *
    Stewart_P.rm_Value * cos(0.52359877559829882 + Stewart_P.beta_Value)) + cos
    (1.0471975511965976 + Stewart_P.alpha_Value) * Stewart_P.rf_Value) +
    Stewart_B.Switch[3], 2.0) + rt_powd_snf(((-(cos(1.0471975511965976 +
    Stewart_B.Switch[2]) * sin(Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1]) +
    sin(1.0471975511965976 + Stewart_B.Switch[2]) * cos(Stewart_B.Switch[1])) *
    Stewart_P.rm_Value * sin(0.52359877559829882 + Stewart_P.beta_Value) - cos
    (1.0471975511965976 + Stewart_B.Switch[2]) * cos(Stewart_B.Switch[0]) *
    Stewart_P.rm_Value * cos(0.52359877559829882 + Stewart_P.beta_Value)) + sin
    (1.0471975511965976 + Stewart_P.alpha_Value) * Stewart_P.rf_Value) +
    Stewart_B.Switch[4], 2.0)) + rt_powd_snf(((cos(Stewart_B.Switch[0]) * sin
    (Stewart_B.Switch[1]) * Stewart_P.rm_Value * sin(0.52359877559829882 +
    Stewart_P.beta_Value) - sin(Stewart_B.Switch[0]) * Stewart_P.rm_Value * cos
    (0.52359877559829882 + Stewart_P.beta_Value)) + Stewart_P.h_Value) +
    Stewart_B.Switch[5], 2.0);

  /* S-Function (arduinoanaloginput_sfcn): '<S12>/Potentiomètre 5' */
  rtb_Potentiomtre1_0 = MW_analogRead(Stewart_P.Potentiomtre5_p1);

  /* Fcn: '<Root>/L5' */
  if (rtb_Divide_ncka1fctzt < 0.0) {
    rtb_Divide_ncka1fctzt = -sqrt(-rtb_Divide_ncka1fctzt);
  } else {
    rtb_Divide_ncka1fctzt = sqrt(rtb_Divide_ncka1fctzt);
  }

  /* Gain: '<S12>/Gain4' incorporates:
   *  Constant: '<S35>/Lmax'
   *  Constant: '<S35>/Lmin'
   *  Gain: '<S35>/Gain1'
   *  Product: '<S35>/Divide'
   *  S-Function (arduinoanaloginput_sfcn): '<S12>/Potentiomètre 5'
   *  Sum: '<S12>/Add5'
   *  Sum: '<S35>/Add'
   *  Sum: '<S35>/Add1'
   */
  rtb_Divide_ncka1fctzt = (rtb_Divide_ncka1fctzt - ((real_T)((uint32_T)
    Stewart_P.Gain1_Gain_fpelshvuq5 * rtb_Potentiomtre1_0) *
    2.9802322387695313E-8 * (Stewart_P.Lmax_Value_nh4qnxlmtb -
    Stewart_P.Lmin_Value_asz1pke2r5) + Stewart_P.Lmin_Value_asz1pke2r5)) *
    Stewart_P.Gain4_Gain;

  /* Saturate: '<S33>/Saturation1' */
  if (rtb_Divide_ncka1fctzt > Stewart_P.Saturation1_UpperSat) {
    rtb_Divide_ncka1fctzt = Stewart_P.Saturation1_UpperSat;
  } else {
    if (rtb_Divide_ncka1fctzt < Stewart_P.Saturation1_LowerSat) {
      rtb_Divide_ncka1fctzt = Stewart_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<S33>/Saturation1' */

  /* Signum: '<S33>/Sign1' */
  if (rtb_Divide_ncka1fctzt < 0.0) {
    rtb_Divide_l0wo3ief2w = -1.0;
  } else if (rtb_Divide_ncka1fctzt > 0.0) {
    rtb_Divide_l0wo3ief2w = 1.0;
  } else if (rtb_Divide_ncka1fctzt == 0.0) {
    rtb_Divide_l0wo3ief2w = 0.0;
  } else {
    rtb_Divide_l0wo3ief2w = rtb_Divide_ncka1fctzt;
  }

  /* DataTypeConversion: '<S34>/Data Type Conversion' incorporates:
   *  Constant: '<S33>/Constant3'
   *  Constant: '<S33>/Constant4'
   *  Product: '<S33>/Divide3'
   *  Signum: '<S33>/Sign1'
   *  Sum: '<S33>/Add2'
   */
  rtb_Divide_l0wo3ief2w = (Stewart_P.Constant3_Value + rtb_Divide_l0wo3ief2w) /
    Stewart_P.Constant4_Value;
  if (rtb_Divide_l0wo3ief2w < 256.0) {
    if (rtb_Divide_l0wo3ief2w >= 0.0) {
      tmp_1 = (uint8_T)rtb_Divide_l0wo3ief2w;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S34>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S34>/Digital Output' */
  MW_digitalWrite(Stewart_P.DigitalOutput_pinNum_j5nhbsiy1k, tmp_1);

  /* Abs: '<S33>/Abs1' */
  rtb_Divide_ncka1fctzt = fabs(rtb_Divide_ncka1fctzt);

  /* DataTypeConversion: '<S33>/Data Type Conversion1' incorporates:
   *  Bias: '<S37>/Add min y'
   *  Bias: '<S37>/Subtract min x'
   *  Gain: '<S37>/range y // range x'
   */
  rtb_Divide_l0wo3ief2w = floor((Stewart_P.mapminmax1_ymax -
    Stewart_P.mapminmax1_ymin) / (Stewart_P.mapminmax1_xmax -
    Stewart_P.mapminmax1_xmin) * (rtb_Divide_ncka1fctzt +
    -Stewart_P.mapminmax1_xmin) + Stewart_P.mapminmax1_ymin);
  if (rtIsNaN(rtb_Divide_l0wo3ief2w) || rtIsInf(rtb_Divide_l0wo3ief2w)) {
    rtb_Divide_l0wo3ief2w = 0.0;
  } else {
    rtb_Divide_l0wo3ief2w = fmod(rtb_Divide_l0wo3ief2w, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S36>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S33>/Data Type Conversion1'
   */
  tmp_0 = rtb_Divide_l0wo3ief2w < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Divide_l0wo3ief2w : (int32_T)(uint32_T)rtb_Divide_l0wo3ief2w;
  if (tmp_0 < 0L) {
    tmp_0 = 0L;
  } else {
    if ((uint32_T)tmp_0 > 255UL) {
      tmp_0 = 255L;
    }
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S36>/PWM' incorporates:
   *  DataTypeConversion: '<S36>/Data Type Conversion'
   */
  MW_analogWrite(Stewart_P.PWM_pinNumber_cubsriyfnt, (uint8_T)tmp_0);

  /* Fcn: '<Root>/L6' incorporates:
   *  Constant: '<S16>/alpha'
   *  Constant: '<S16>/beta'
   *  Constant: '<S16>/h'
   *  Constant: '<S16>/rf'
   *  Constant: '<S16>/rm'
   */
  rtb_Divide_ncka1fctzt = (rt_powd_snf(((-(cos(1.0471975511965976 +
    Stewart_B.Switch[2]) * cos(Stewart_B.Switch[1]) - sin(1.0471975511965976 +
    Stewart_B.Switch[2]) * sin(Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1])) *
    Stewart_P.rm_Value * cos(1.0471975511965976 + Stewart_P.beta_Value) + sin
    (1.0471975511965976 + Stewart_B.Switch[2]) * cos(Stewart_B.Switch[0]) *
    Stewart_P.rm_Value * sin(1.0471975511965976 + Stewart_P.beta_Value)) -
    Stewart_P.rf_Value * cos(Stewart_P.alpha_Value)) + Stewart_B.Switch[3], 2.0)
    + rt_powd_snf(((-(cos(1.0471975511965976 + Stewart_B.Switch[2]) * sin
                      (Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1]) + sin
                      (1.0471975511965976 + Stewart_B.Switch[2]) * cos
                      (Stewart_B.Switch[1])) * Stewart_P.rm_Value * cos
                    (1.0471975511965976 + Stewart_P.beta_Value) - cos
                    (1.0471975511965976 + Stewart_B.Switch[2]) * cos
                    (Stewart_B.Switch[0]) * Stewart_P.rm_Value * sin
                    (1.0471975511965976 + Stewart_P.beta_Value)) +
                   Stewart_P.rf_Value * sin(Stewart_P.alpha_Value)) +
                  Stewart_B.Switch[4], 2.0)) + rt_powd_snf(((cos
    (Stewart_B.Switch[0]) * sin(Stewart_B.Switch[1]) * Stewart_P.rm_Value * cos
    (1.0471975511965976 + Stewart_P.beta_Value) - sin(Stewart_B.Switch[0]) *
    Stewart_P.rm_Value * sin(1.0471975511965976 + Stewart_P.beta_Value)) +
    Stewart_P.h_Value) + Stewart_B.Switch[5], 2.0);

  /* S-Function (arduinoanaloginput_sfcn): '<S13>/Potentiomètre 6' */
  rtb_Potentiomtre1_0 = MW_analogRead(Stewart_P.Potentiomtre6_p1);

  /* Fcn: '<Root>/L6' */
  if (rtb_Divide_ncka1fctzt < 0.0) {
    rtb_Divide_ncka1fctzt = -sqrt(-rtb_Divide_ncka1fctzt);
  } else {
    rtb_Divide_ncka1fctzt = sqrt(rtb_Divide_ncka1fctzt);
  }

  /* Gain: '<S13>/Gain5' incorporates:
   *  Constant: '<S40>/Lmax'
   *  Constant: '<S40>/Lmin'
   *  Gain: '<S40>/Gain1'
   *  Product: '<S40>/Divide'
   *  S-Function (arduinoanaloginput_sfcn): '<S13>/Potentiomètre 6'
   *  Sum: '<S13>/Add6'
   *  Sum: '<S40>/Add'
   *  Sum: '<S40>/Add1'
   */
  rtb_Divide_ncka1fctzt = (rtb_Divide_ncka1fctzt - ((real_T)((uint32_T)
    Stewart_P.Gain1_Gain_j13fe42xcx * rtb_Potentiomtre1_0) *
    2.9802322387695313E-8 * (Stewart_P.Lmax_Value_pp0fbeghm2 -
    Stewart_P.Lmin_Value_iw11bz0kqi) + Stewart_P.Lmin_Value_iw11bz0kqi)) *
    Stewart_P.Gain5_Gain;

  /* Saturate: '<S38>/Saturation' */
  if (rtb_Divide_ncka1fctzt > Stewart_P.Saturation_UpperSat_dpja4mkxr2) {
    rtb_Divide_ncka1fctzt = Stewart_P.Saturation_UpperSat_dpja4mkxr2;
  } else {
    if (rtb_Divide_ncka1fctzt < Stewart_P.Saturation_LowerSat_iddp3i1r04) {
      rtb_Divide_ncka1fctzt = Stewart_P.Saturation_LowerSat_iddp3i1r04;
    }
  }

  /* End of Saturate: '<S38>/Saturation' */

  /* Signum: '<S38>/Sign' */
  if (rtb_Divide_ncka1fctzt < 0.0) {
    rtb_Divide_l0wo3ief2w = -1.0;
  } else if (rtb_Divide_ncka1fctzt > 0.0) {
    rtb_Divide_l0wo3ief2w = 1.0;
  } else if (rtb_Divide_ncka1fctzt == 0.0) {
    rtb_Divide_l0wo3ief2w = 0.0;
  } else {
    rtb_Divide_l0wo3ief2w = rtb_Divide_ncka1fctzt;
  }

  /* DataTypeConversion: '<S39>/Data Type Conversion' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S38>/Constant1'
   *  Product: '<S38>/Divide'
   *  Signum: '<S38>/Sign'
   *  Sum: '<S38>/Add'
   */
  rtb_Divide_l0wo3ief2w = (Stewart_P.Constant_Value_gamabtpgbn +
    rtb_Divide_l0wo3ief2w) / Stewart_P.Constant1_Value_kij2jw3212;
  if (rtb_Divide_l0wo3ief2w < 256.0) {
    if (rtb_Divide_l0wo3ief2w >= 0.0) {
      tmp_1 = (uint8_T)rtb_Divide_l0wo3ief2w;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S39>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S39>/Digital Output' */
  MW_digitalWrite(Stewart_P.DigitalOutput_pinNum_p3klgfr0gp, tmp_1);

  /* Abs: '<S38>/Abs' */
  rtb_Divide_ncka1fctzt = fabs(rtb_Divide_ncka1fctzt);

  /* DataTypeConversion: '<S38>/Data Type Conversion' incorporates:
   *  Bias: '<S42>/Add min y'
   *  Bias: '<S42>/Subtract min x'
   *  Gain: '<S42>/range y // range x'
   */
  rtb_Divide_l0wo3ief2w = floor((Stewart_P.mapminmax_ymax_lwlufp43xq -
    Stewart_P.mapminmax_ymin_pwvv1lkczl) / (Stewart_P.mapminmax_xmax_ct4bepuicm
    - Stewart_P.mapminmax_xmin_d0gqzccq3k) * (rtb_Divide_ncka1fctzt +
    -Stewart_P.mapminmax_xmin_d0gqzccq3k) + Stewart_P.mapminmax_ymin_pwvv1lkczl);
  if (rtIsNaN(rtb_Divide_l0wo3ief2w) || rtIsInf(rtb_Divide_l0wo3ief2w)) {
    rtb_Divide_l0wo3ief2w = 0.0;
  } else {
    rtb_Divide_l0wo3ief2w = fmod(rtb_Divide_l0wo3ief2w, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S41>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S38>/Data Type Conversion'
   */
  tmp_0 = rtb_Divide_l0wo3ief2w < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Divide_l0wo3ief2w : (int32_T)(uint32_T)rtb_Divide_l0wo3ief2w;
  if (tmp_0 < 0L) {
    tmp_0 = 0L;
  } else {
    if ((uint32_T)tmp_0 > 255UL) {
      tmp_0 = 255L;
    }
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S41>/PWM' incorporates:
   *  DataTypeConversion: '<S41>/Data Type Conversion'
   */
  MW_analogWrite(Stewart_P.PWM_pinNumber_n4eukf2fei, (uint8_T)tmp_0);

  /* Clock: '<Root>/Clock' */
  Stewart_B.Clock = Stewart_M->Timing.t[0];

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, Stewart_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(1, ((Stewart_M->Timing.clockTick1) * 0.001));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Stewart_M)!=-1) &&
        !((rtmGetTFinal(Stewart_M)-Stewart_M->Timing.t[0]) > Stewart_M->
          Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(Stewart_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Stewart_M)) {
      rtmSetErrorStatus(Stewart_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Stewart_M->Timing.t[0] =
    (++Stewart_M->Timing.clockTick0) * Stewart_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Stewart_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Stewart_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Stewart_M, 0,
                sizeof(RT_MODEL_Stewart_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Stewart_M->solverInfo, &Stewart_M->Timing.simTimeStep);
    rtsiSetTPtr(&Stewart_M->solverInfo, &rtmGetTPtr(Stewart_M));
    rtsiSetStepSizePtr(&Stewart_M->solverInfo, &Stewart_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Stewart_M->solverInfo, (&rtmGetErrorStatus(Stewart_M)));
    rtsiSetRTModelPtr(&Stewart_M->solverInfo, Stewart_M);
  }

  rtsiSetSimTimeStep(&Stewart_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Stewart_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Stewart_M, &Stewart_M->Timing.tArray[0]);
  rtmSetTFinal(Stewart_M, -1);
  Stewart_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Stewart_M->Sizes.checksums[0] = (2703431461U);
  Stewart_M->Sizes.checksums[1] = (3894138881U);
  Stewart_M->Sizes.checksums[2] = (1254058033U);
  Stewart_M->Sizes.checksums[3] = (3995045899U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Stewart_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Stewart_M->extModeInfo,
      &Stewart_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Stewart_M->extModeInfo, Stewart_M->Sizes.checksums);
    rteiSetTPtr(Stewart_M->extModeInfo, rtmGetTPtr(Stewart_M));
  }

  /* block I/O */
  (void) memset(((void *) &Stewart_B), 0,
                sizeof(B_Stewart_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Stewart_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (arduinoanaloginput_sfcn): '<Root>/Potentiomètre 1' */
  MW_pinModeAnalogInput(Stewart_P.Potentiomtre1_p1);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_pinModeOutput(Stewart_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S8>/PWM' */
  MW_pinModeOutput(Stewart_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S9>/Potentiomètre 2' */
  MW_pinModeAnalogInput(Stewart_P.Potentiomtre2_p1);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S19>/Digital Output' */
  MW_pinModeOutput(Stewart_P.DigitalOutput_pinNum_ek4xiwztl1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S21>/PWM' */
  MW_pinModeOutput(Stewart_P.PWM_pinNumber_nkrnw2yx44);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S10>/Potentiomètre 3' */
  MW_pinModeAnalogInput(Stewart_P.Potentiomtre3_p1);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S24>/Digital Output' */
  MW_pinModeOutput(Stewart_P.DigitalOutput_pinNum_hetit3zm4v);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S26>/PWM' */
  MW_pinModeOutput(Stewart_P.PWM_pinNumber_hoyrwcvift);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S11>/Potentiomètre 4' */
  MW_pinModeAnalogInput(Stewart_P.Potentiomtre4_p1);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S29>/Digital Output' */
  MW_pinModeOutput(Stewart_P.DigitalOutput_pinNum_bkde3yd3cq);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S31>/PWM' */
  MW_pinModeOutput(Stewart_P.PWM_pinNumber_mx02rvdlnc);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S12>/Potentiomètre 5' */
  MW_pinModeAnalogInput(Stewart_P.Potentiomtre5_p1);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S34>/Digital Output' */
  MW_pinModeOutput(Stewart_P.DigitalOutput_pinNum_j5nhbsiy1k);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S36>/PWM' */
  MW_pinModeOutput(Stewart_P.PWM_pinNumber_cubsriyfnt);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S13>/Potentiomètre 6' */
  MW_pinModeAnalogInput(Stewart_P.Potentiomtre6_p1);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S39>/Digital Output' */
  MW_pinModeOutput(Stewart_P.DigitalOutput_pinNum_p3klgfr0gp);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S41>/PWM' */
  MW_pinModeOutput(Stewart_P.PWM_pinNumber_n4eukf2fei);
}

/* Model terminate function */
void Stewart_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
