/*
 * File: Stewart2.c
 *
 * Code generated for Simulink model 'Stewart2'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Thu Jan 26 16:11:59 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Stewart2.h"
#include "Stewart2_private.h"
#include "Stewart2_dt.h"

/* Block signals (auto storage) */
B_Stewart2_T Stewart2_B;

/* Real-time model */
RT_MODEL_Stewart2_T Stewart2_M_;
RT_MODEL_Stewart2_T *const Stewart2_M = &Stewart2_M_;

/* Model step function */
void Stewart2_step(void)
{
  uint16_T rtb_Potentiomtre1_0;
  real_T rtb_Saturation;
  int32_T tmp;
  real_T rtb_Saturation_0;
  uint8_T tmp_0;

  /* Constant: '<Root>/theta_x' */
  Stewart2_B.theta_x = Stewart2_P.theta_x_Value;

  /* S-Function (arduinoanaloginput_sfcn): '<Root>/Potentiomètre 1' */
  rtb_Potentiomtre1_0 = MW_analogRead(Stewart2_P.Potentiomtre1_p1);

  /* Sum: '<S3>/Add1' incorporates:
   *  Constant: '<S3>/Lmax'
   *  Constant: '<S3>/Lmin'
   *  Gain: '<S3>/Gain1'
   *  Product: '<S3>/Divide'
   *  S-Function (arduinoanaloginput_sfcn): '<Root>/Potentiomètre 1'
   *  Sum: '<S3>/Add'
   */
  Stewart2_B.Add1 = (real_T)((uint32_T)Stewart2_P.Gain1_Gain *
    rtb_Potentiomtre1_0) * 2.9802322387695313E-8 * (Stewart2_P.Lmax_Value -
    Stewart2_P.Lmin_Value) + Stewart2_P.Lmin_Value;

  /* Gain: '<Root>/Gain6' incorporates:
   *  Sum: '<Root>/Add1'
   */
  Stewart2_B.Gain6 = (Stewart2_B.theta_x - Stewart2_B.Add1) *
    Stewart2_P.Gain6_Gain;

  /* Saturate: '<S1>/Saturation' */
  if (Stewart2_B.Gain6 > Stewart2_P.Saturation_UpperSat) {
    rtb_Saturation = Stewart2_P.Saturation_UpperSat;
  } else if (Stewart2_B.Gain6 < Stewart2_P.Saturation_LowerSat) {
    rtb_Saturation = Stewart2_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = Stewart2_B.Gain6;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Signum: '<S1>/Sign' */
  if (rtb_Saturation < 0.0) {
    rtb_Saturation_0 = -1.0;
  } else if (rtb_Saturation > 0.0) {
    rtb_Saturation_0 = 1.0;
  } else if (rtb_Saturation == 0.0) {
    rtb_Saturation_0 = 0.0;
  } else {
    rtb_Saturation_0 = rtb_Saturation;
  }

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Signum: '<S1>/Sign'
   *  Sum: '<S1>/Add'
   */
  Stewart2_B.Divide = (Stewart2_P.Constant_Value + rtb_Saturation_0) /
    Stewart2_P.Constant1_Value;

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (Stewart2_B.Divide < 256.0) {
    if (Stewart2_B.Divide >= 0.0) {
      tmp_0 = (uint8_T)Stewart2_B.Divide;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_digitalWrite(Stewart2_P.DigitalOutput_pinNumber, tmp_0);

  /* Abs: '<S1>/Abs' */
  Stewart2_B.Abs = fabs(rtb_Saturation);

  /* Bias: '<S5>/Add min y' incorporates:
   *  Bias: '<S5>/Subtract min x'
   *  Gain: '<S5>/range y // range x'
   */
  Stewart2_B.Addminy = (Stewart2_P.mapminmax_ymax - Stewart2_P.mapminmax_ymin) /
    (Stewart2_P.mapminmax_xmax - Stewart2_P.mapminmax_xmin) * (Stewart2_B.Abs +
    -Stewart2_P.mapminmax_xmin) + Stewart2_P.mapminmax_ymin;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_Saturation = floor(Stewart2_B.Addminy);
  if (rtIsNaN(rtb_Saturation) || rtIsInf(rtb_Saturation)) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = fmod(rtb_Saturation, 4.294967296E+9);
  }

  Stewart2_B.DataTypeConversion = rtb_Saturation < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Saturation : (int32_T)(uint32_T)rtb_Saturation;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  tmp = Stewart2_B.DataTypeConversion;
  if (Stewart2_B.DataTypeConversion < 0L) {
    tmp = 0L;
  } else {
    if ((uint32_T)Stewart2_B.DataTypeConversion > 255UL) {
      tmp = 255L;
    }
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   */
  MW_analogWrite(Stewart2_P.PWM_pinNumber, (uint8_T)tmp);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, Stewart2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(Stewart2_M)!=-1) &&
        !((rtmGetTFinal(Stewart2_M)-Stewart2_M->Timing.taskTime0) >
          Stewart2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Stewart2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Stewart2_M)) {
      rtmSetErrorStatus(Stewart2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Stewart2_M->Timing.taskTime0 =
    (++Stewart2_M->Timing.clockTick0) * Stewart2_M->Timing.stepSize0;
}

/* Model initialize function */
void Stewart2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Stewart2_M, 0,
                sizeof(RT_MODEL_Stewart2_T));
  rtmSetTFinal(Stewart2_M, -1);
  Stewart2_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Stewart2_M->Sizes.checksums[0] = (659750090U);
  Stewart2_M->Sizes.checksums[1] = (1291956012U);
  Stewart2_M->Sizes.checksums[2] = (2596492072U);
  Stewart2_M->Sizes.checksums[3] = (37649866U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Stewart2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Stewart2_M->extModeInfo,
      &Stewart2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Stewart2_M->extModeInfo, Stewart2_M->Sizes.checksums);
    rteiSetTPtr(Stewart2_M->extModeInfo, rtmGetTPtr(Stewart2_M));
  }

  /* block I/O */
  (void) memset(((void *) &Stewart2_B), 0,
                sizeof(B_Stewart2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Stewart2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (arduinoanaloginput_sfcn): '<Root>/Potentiomètre 1' */
  MW_pinModeAnalogInput(Stewart2_P.Potentiomtre1_p1);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_pinModeOutput(Stewart2_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_pinModeOutput(Stewart2_P.PWM_pinNumber);
}

/* Model terminate function */
void Stewart2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
