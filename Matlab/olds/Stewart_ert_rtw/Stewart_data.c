/*
 * File: Stewart_data.c
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

/* Block parameters (auto storage) */
P_Stewart_T Stewart_P = {
  200.0,                               /* Mask Parameter: mapminmax_xmax
                                        * Referenced by: '<S15>/range y // range x'
                                        */
  200.0,                               /* Mask Parameter: mapminmax_xmax_d3hx0fzg3v
                                        * Referenced by: '<S22>/range y // range x'
                                        */
  200.0,                               /* Mask Parameter: mapminmax_xmax_i1mgu1wczb
                                        * Referenced by: '<S27>/range y // range x'
                                        */
  200.0,                               /* Mask Parameter: mapminmax_xmax_aub2z1f52q
                                        * Referenced by: '<S32>/range y // range x'
                                        */
  200.0,                               /* Mask Parameter: mapminmax1_xmax
                                        * Referenced by: '<S37>/range y // range x'
                                        */
  200.0,                               /* Mask Parameter: mapminmax_xmax_ct4bepuicm
                                        * Referenced by: '<S42>/range y // range x'
                                        */
  0.0,                                 /* Mask Parameter: mapminmax_xmin
                                        * Referenced by:
                                        *   '<S15>/Subtract min x'
                                        *   '<S15>/range y // range x'
                                        */
  0.0,                                 /* Mask Parameter: mapminmax_xmin_iehjoea5ea
                                        * Referenced by:
                                        *   '<S22>/Subtract min x'
                                        *   '<S22>/range y // range x'
                                        */
  0.0,                                 /* Mask Parameter: mapminmax_xmin_cuaeahpuiv
                                        * Referenced by:
                                        *   '<S27>/Subtract min x'
                                        *   '<S27>/range y // range x'
                                        */
  0.0,                                 /* Mask Parameter: mapminmax_xmin_k4al5ovj24
                                        * Referenced by:
                                        *   '<S32>/Subtract min x'
                                        *   '<S32>/range y // range x'
                                        */
  0.0,                                 /* Mask Parameter: mapminmax1_xmin
                                        * Referenced by:
                                        *   '<S37>/Subtract min x'
                                        *   '<S37>/range y // range x'
                                        */
  0.0,                                 /* Mask Parameter: mapminmax_xmin_d0gqzccq3k
                                        * Referenced by:
                                        *   '<S42>/Subtract min x'
                                        *   '<S42>/range y // range x'
                                        */
  255.0,                               /* Mask Parameter: mapminmax_ymax
                                        * Referenced by: '<S15>/range y // range x'
                                        */
  255.0,                               /* Mask Parameter: mapminmax_ymax_iej5kpatil
                                        * Referenced by: '<S22>/range y // range x'
                                        */
  255.0,                               /* Mask Parameter: mapminmax_ymax_jfea2ow0og
                                        * Referenced by: '<S27>/range y // range x'
                                        */
  255.0,                               /* Mask Parameter: mapminmax_ymax_ihor11sths
                                        * Referenced by: '<S32>/range y // range x'
                                        */
  255.0,                               /* Mask Parameter: mapminmax1_ymax
                                        * Referenced by: '<S37>/range y // range x'
                                        */
  255.0,                               /* Mask Parameter: mapminmax_ymax_lwlufp43xq
                                        * Referenced by: '<S42>/range y // range x'
                                        */
  1.0,                                 /* Mask Parameter: mapminmax_ymin
                                        * Referenced by:
                                        *   '<S15>/Add min y'
                                        *   '<S15>/range y // range x'
                                        */
  1.0,                                 /* Mask Parameter: mapminmax_ymin_k5go5squy4
                                        * Referenced by:
                                        *   '<S22>/Add min y'
                                        *   '<S22>/range y // range x'
                                        */
  1.0,                                 /* Mask Parameter: mapminmax_ymin_ogggrkrg4e
                                        * Referenced by:
                                        *   '<S27>/Add min y'
                                        *   '<S27>/range y // range x'
                                        */
  1.0,                                 /* Mask Parameter: mapminmax_ymin_jjvvjjkkrv
                                        * Referenced by:
                                        *   '<S32>/Add min y'
                                        *   '<S32>/range y // range x'
                                        */
  1.0,                                 /* Mask Parameter: mapminmax1_ymin
                                        * Referenced by:
                                        *   '<S37>/Add min y'
                                        *   '<S37>/range y // range x'
                                        */
  1.0,                                 /* Mask Parameter: mapminmax_ymin_pwvv1lkczl
                                        * Referenced by:
                                        *   '<S42>/Add min y'
                                        *   '<S42>/range y // range x'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S2>/Digital Output'
                                        */
  10U,                                 /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S8>/PWM'
                                        */
  5U,                                  /* Mask Parameter: DigitalOutput_pinNum_ek4xiwztl1
                                        * Referenced by: '<S19>/Digital Output'
                                        */
  4U,                                  /* Mask Parameter: PWM_pinNumber_nkrnw2yx44
                                        * Referenced by: '<S21>/PWM'
                                        */
  3U,                                  /* Mask Parameter: DigitalOutput_pinNum_hetit3zm4v
                                        * Referenced by: '<S24>/Digital Output'
                                        */
  2U,                                  /* Mask Parameter: PWM_pinNumber_hoyrwcvift
                                        * Referenced by: '<S26>/PWM'
                                        */
  9U,                                  /* Mask Parameter: DigitalOutput_pinNum_bkde3yd3cq
                                        * Referenced by: '<S29>/Digital Output'
                                        */
  8U,                                  /* Mask Parameter: PWM_pinNumber_mx02rvdlnc
                                        * Referenced by: '<S31>/PWM'
                                        */
  7U,                                  /* Mask Parameter: DigitalOutput_pinNum_j5nhbsiy1k
                                        * Referenced by: '<S34>/Digital Output'
                                        */
  6U,                                  /* Mask Parameter: PWM_pinNumber_cubsriyfnt
                                        * Referenced by: '<S36>/PWM'
                                        */
  13U,                                 /* Mask Parameter: DigitalOutput_pinNum_p3klgfr0gp
                                        * Referenced by: '<S39>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: PWM_pinNumber_n4eukf2fei
                                        * Referenced by: '<S41>/PWM'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/theta_x'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/theta_y'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/theta_z'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/x'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/y'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/z'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/theta_x'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/theta_y'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/theta_z'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/x'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/y'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S6>/z'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/z'
                                        */
  60.0,                                /* Expression: 60
                                        * Referenced by: '<S6>/z'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/z'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S5>/Switch'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<S16>/rm'
                                        */
  270.0,                               /* Expression: 270
                                        * Referenced by: '<S16>/rf'
                                        */
  0.007,                               /* Expression: 0.007
                                        * Referenced by: '<S16>/alpha'
                                        */
  0.009,                               /* Expression: 0.009
                                        * Referenced by: '<S16>/beta'
                                        */
  380.0,                               /* Expression: 380
                                        * Referenced by: '<S16>/h'
                                        */
  350.0,                               /* Expression: 350
                                        * Referenced by: '<S3>/Lmin'
                                        */
  500.0,                               /* Expression: 500
                                        * Referenced by: '<S3>/Lmax'
                                        */
  5.0,                                 /* Expression: 5
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
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S18>/Constant'
                                        */
  350.0,                               /* Expression: 350
                                        * Referenced by: '<S20>/Lmin'
                                        */
  500.0,                               /* Expression: 500
                                        * Referenced by: '<S20>/Lmax'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S9>/Gain1'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<S18>/Saturation'
                                        */
  -200.0,                              /* Expression: -200
                                        * Referenced by: '<S18>/Saturation'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S18>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  350.0,                               /* Expression: 350
                                        * Referenced by: '<S25>/Lmin'
                                        */
  500.0,                               /* Expression: 500
                                        * Referenced by: '<S25>/Lmax'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S10>/Gain2'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<S23>/Saturation'
                                        */
  -200.0,                              /* Expression: -200
                                        * Referenced by: '<S23>/Saturation'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S23>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/Constant'
                                        */
  350.0,                               /* Expression: 350
                                        * Referenced by: '<S30>/Lmin'
                                        */
  500.0,                               /* Expression: 500
                                        * Referenced by: '<S30>/Lmax'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S11>/Gain3'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<S28>/Saturation'
                                        */
  -200.0,                              /* Expression: -200
                                        * Referenced by: '<S28>/Saturation'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S28>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S33>/Constant3'
                                        */
  350.0,                               /* Expression: 350
                                        * Referenced by: '<S35>/Lmin'
                                        */
  500.0,                               /* Expression: 500
                                        * Referenced by: '<S35>/Lmax'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S12>/Gain4'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<S33>/Saturation1'
                                        */
  -200.0,                              /* Expression: -200
                                        * Referenced by: '<S33>/Saturation1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S33>/Constant4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S38>/Constant'
                                        */
  350.0,                               /* Expression: 350
                                        * Referenced by: '<S40>/Lmin'
                                        */
  500.0,                               /* Expression: 500
                                        * Referenced by: '<S40>/Lmax'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S13>/Gain5'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<S38>/Saturation'
                                        */
  -200.0,                              /* Expression: -200
                                        * Referenced by: '<S38>/Saturation'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S38>/Constant1'
                                        */
  2U,                                  /* Computed Parameter: Potentiomtre1_p1
                                        * Referenced by: '<Root>/Potentiomètre 1'
                                        */
  1U,                                  /* Computed Parameter: Potentiomtre2_p1
                                        * Referenced by: '<S9>/Potentiomètre 2'
                                        */
  0U,                                  /* Computed Parameter: Potentiomtre3_p1
                                        * Referenced by: '<S10>/Potentiomètre 3'
                                        */
  5U,                                  /* Computed Parameter: Potentiomtre4_p1
                                        * Referenced by: '<S11>/Potentiomètre 4'
                                        */
  4U,                                  /* Computed Parameter: Potentiomtre5_p1
                                        * Referenced by: '<S12>/Potentiomètre 5'
                                        */
  3U,                                  /* Computed Parameter: Potentiomtre6_p1
                                        * Referenced by: '<S13>/Potentiomètre 6'
                                        */
  32768U,                              /* Computed Parameter: Gain1_Gain_jfd0ao4z3a
                                        * Referenced by: '<S3>/Gain1'
                                        */
  32768U,                              /* Computed Parameter: Gain1_Gain_m20otgelwl
                                        * Referenced by: '<S20>/Gain1'
                                        */
  32768U,                              /* Computed Parameter: Gain1_Gain_btfs54h4bx
                                        * Referenced by: '<S25>/Gain1'
                                        */
  32768U,                              /* Computed Parameter: Gain1_Gain_ptftxodxyn
                                        * Referenced by: '<S30>/Gain1'
                                        */
  32768U,                              /* Computed Parameter: Gain1_Gain_fpelshvuq5
                                        * Referenced by: '<S35>/Gain1'
                                        */
  32768U                               /* Computed Parameter: Gain1_Gain_j13fe42xcx
                                        * Referenced by: '<S40>/Gain1'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
