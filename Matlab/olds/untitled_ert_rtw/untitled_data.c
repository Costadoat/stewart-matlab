/*
 * File: untitled_data.c
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

/* Block parameters (auto storage) */
P_untitled_T untitled_P = {
  0.0,                                 /* Mask Parameter: PID1_D
                                        * Referenced by: '<S3>/Derivative Gain'
                                        */
  0.0,                                 /* Mask Parameter: PID1_I
                                        * Referenced by: '<S3>/Integral Gain'
                                        */
  100.0,                               /* Mask Parameter: PID1_N
                                        * Referenced by: '<S3>/Filter Coefficient'
                                        */
  10.0,                                /* Mask Parameter: PID1_P
                                        * Referenced by: '<S3>/Proportional Gain'
                                        */
  200.0,                               /* Mask Parameter: mapminmax_xmax
                                        * Referenced by: '<S5>/range y // range x'
                                        */
  0.0,                                 /* Mask Parameter: mapminmax_xmin
                                        * Referenced by:
                                        *   '<S5>/Subtract min x'
                                        *   '<S5>/range y // range x'
                                        */
  255.0,                               /* Mask Parameter: mapminmax_ymax
                                        * Referenced by: '<S5>/range y // range x'
                                        */
  0.0,                                 /* Mask Parameter: mapminmax_ymin
                                        * Referenced by:
                                        *   '<S5>/Add min y'
                                        *   '<S5>/range y // range x'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S2>/Digital Output'
                                        */
  10U,                                 /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S4>/PWM'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/theta_x'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S3>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S3>/Filter'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -200.0                               /* Expression: -200
                                        * Referenced by: '<S1>/Saturation'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
