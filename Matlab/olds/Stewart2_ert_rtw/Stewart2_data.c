/*
 * File: Stewart2_data.c
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

/* Block parameters (auto storage) */
P_Stewart2_T Stewart2_P = {
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
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  350.0,                               /* Expression: 350
                                        * Referenced by: '<Root>/theta_x'
                                        */
  350.0,                               /* Expression: 350
                                        * Referenced by: '<S3>/Lmin'
                                        */
  500.0,                               /* Expression: 500
                                        * Referenced by: '<S3>/Lmax'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Gain6'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -200.0,                              /* Expression: -200
                                        * Referenced by: '<S1>/Saturation'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S1>/Constant1'
                                        */
  2U,                                  /* Computed Parameter: Potentiomtre1_p1
                                        * Referenced by: '<Root>/Potentiomètre 1'
                                        */
  32768U                               /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S3>/Gain1'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
