/*
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue Jan 24 13:57:19 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"

/* Block signals (auto storage) */
B_untitled_T untitled_B;

/* Continuous states */
X_untitled_T untitled_X;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  untitled_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  untitled_step();
  untitled_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  untitled_step();
  untitled_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void untitled_step(void)
{
  real_T rtb_Abs;
  real_T tmp;
  uint8_T tmp_0;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&untitled_M->solverInfo,
                          ((untitled_M->Timing.clockTick0+1)*
      untitled_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(untitled_M)) {
    untitled_M->Timing.t[0] = rtsiGetT(&untitled_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Gain: '<S3>/Proportional Gain' incorporates:
     *  Constant: '<Root>/theta_x'
     */
    untitled_B.ProportionalGain = untitled_P.PID1_P * untitled_P.theta_x_Value;

    /* Gain: '<S3>/Derivative Gain' incorporates:
     *  Constant: '<Root>/theta_x'
     */
    untitled_B.DerivativeGain = untitled_P.PID1_D * untitled_P.theta_x_Value;
  }

  /* Gain: '<S3>/Filter Coefficient' incorporates:
   *  Integrator: '<S3>/Filter'
   *  Sum: '<S3>/SumD'
   */
  untitled_B.FilterCoefficient = (untitled_B.DerivativeGain -
    untitled_X.Filter_CSTATE) * untitled_P.PID1_N;

  /* Sum: '<S3>/Sum' incorporates:
   *  Integrator: '<S3>/Integrator'
   */
  rtb_Abs = (untitled_B.ProportionalGain + untitled_X.Integrator_CSTATE) +
    untitled_B.FilterCoefficient;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Abs > untitled_P.Saturation_UpperSat) {
    rtb_Abs = untitled_P.Saturation_UpperSat;
  } else {
    if (rtb_Abs < untitled_P.Saturation_LowerSat) {
      rtb_Abs = untitled_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S1>/Saturation' */
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Signum: '<S1>/Sign' */
    if (rtb_Abs < 0.0) {
      /* DataTypeConversion: '<S2>/Data Type Conversion' */
      tmp = -1.0;
    } else if (rtb_Abs > 0.0) {
      /* DataTypeConversion: '<S2>/Data Type Conversion' */
      tmp = 1.0;
    } else if (rtb_Abs == 0.0) {
      /* DataTypeConversion: '<S2>/Data Type Conversion' */
      tmp = 0.0;
    } else {
      /* DataTypeConversion: '<S2>/Data Type Conversion' */
      tmp = rtb_Abs;
    }

    /* End of Signum: '<S1>/Sign' */

    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    /* S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
    MW_digitalWrite(untitled_P.DigitalOutput_pinNumber, tmp_0);
  }

  /* Abs: '<S1>/Abs' */
  rtb_Abs = fabs(rtb_Abs);
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Bias: '<S5>/Add min y'
     *  Bias: '<S5>/Subtract min x'
     *  Gain: '<S5>/range y // range x'
     */
    tmp = (untitled_P.mapminmax_ymax - untitled_P.mapminmax_ymin) /
      (untitled_P.mapminmax_xmax - untitled_P.mapminmax_xmin) * (rtb_Abs +
      -untitled_P.mapminmax_xmin) + untitled_P.mapminmax_ymin;
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

    /* S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
    MW_analogWrite(untitled_P.PWM_pinNumber, tmp_0);

    /* Gain: '<S3>/Integral Gain' incorporates:
     *  Constant: '<Root>/theta_x'
     */
    untitled_B.IntegralGain = untitled_P.PID1_I * untitled_P.theta_x_Value;
  }

  if (rtmIsMajorTimeStep(untitled_M)) {
    rt_ertODEUpdateContinuousStates(&untitled_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++untitled_M->Timing.clockTick0;
    untitled_M->Timing.t[0] = rtsiGetSolverStopTime(&untitled_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      untitled_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void untitled_derivatives(void)
{
  XDot_untitled_T *_rtXdot;
  _rtXdot = ((XDot_untitled_T *) untitled_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE = untitled_B.IntegralGain;

  /* Derivatives for Integrator: '<S3>/Filter' */
  _rtXdot->Filter_CSTATE = untitled_B.FilterCoefficient;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetdXPtr(&untitled_M->solverInfo, &untitled_M->ModelData.derivs);
    rtsiSetContStatesPtr(&untitled_M->solverInfo, (real_T **)
                         &untitled_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&untitled_M->solverInfo,
      &untitled_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&untitled_M->solverInfo,
      &untitled_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  untitled_M->ModelData.intgData.y = untitled_M->ModelData.odeY;
  untitled_M->ModelData.intgData.f[0] = untitled_M->ModelData.odeF[0];
  untitled_M->ModelData.intgData.f[1] = untitled_M->ModelData.odeF[1];
  untitled_M->ModelData.intgData.f[2] = untitled_M->ModelData.odeF[2];
  untitled_M->ModelData.contStates = ((X_untitled_T *) &untitled_X);
  rtsiSetSolverData(&untitled_M->solverInfo, (void *)
                    &untitled_M->ModelData.intgData);
  rtsiSetSolverName(&untitled_M->solverInfo,"ode3");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  untitled_M->Timing.stepSize0 = 0.2;

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* states (continuous) */
  {
    (void) memset((void *)&untitled_X, 0,
                  sizeof(X_untitled_T));
  }

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_pinModeOutput(untitled_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_pinModeOutput(untitled_P.PWM_pinNumber);

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  untitled_X.Integrator_CSTATE = untitled_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S3>/Filter' */
  untitled_X.Filter_CSTATE = untitled_P.Filter_IC;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
