/*
 * File: Stewart.h
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

#ifndef RTW_HEADER_Stewart_h_
#define RTW_HEADER_Stewart_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Stewart_COMMON_INCLUDES_
# define Stewart_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_analoginput_lct.h"
#include "arduino_digitaloutput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* Stewart_COMMON_INCLUDES_ */

#include "Stewart_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Switch[6];                    /* '<S5>/Switch' */
  real_T dv0[6];
  real_T dv1[6];
  real_T L1;                           /* '<Root>/L1' */
  real_T Add1;                         /* '<S3>/Add1' */
  real_T Gain6;                        /* '<Root>/Gain6' */
  real_T Divide;                       /* '<S1>/Divide' */
  real_T Clock;                        /* '<Root>/Clock' */
  real_T TmpSignalConversionAtsfunxyInpo[2];
  int32_T DataTypeConversion;          /* '<S1>/Data Type Conversion' */
} B_Stewart_T;

/* Parameters (auto storage) */
struct P_Stewart_T_ {
  real_T mapminmax_xmax;               /* Mask Parameter: mapminmax_xmax
                                        * Referenced by: '<S15>/range y // range x'
                                        */
  real_T mapminmax_xmax_d3hx0fzg3v;    /* Mask Parameter: mapminmax_xmax_d3hx0fzg3v
                                        * Referenced by: '<S22>/range y // range x'
                                        */
  real_T mapminmax_xmax_i1mgu1wczb;    /* Mask Parameter: mapminmax_xmax_i1mgu1wczb
                                        * Referenced by: '<S27>/range y // range x'
                                        */
  real_T mapminmax_xmax_aub2z1f52q;    /* Mask Parameter: mapminmax_xmax_aub2z1f52q
                                        * Referenced by: '<S32>/range y // range x'
                                        */
  real_T mapminmax1_xmax;              /* Mask Parameter: mapminmax1_xmax
                                        * Referenced by: '<S37>/range y // range x'
                                        */
  real_T mapminmax_xmax_ct4bepuicm;    /* Mask Parameter: mapminmax_xmax_ct4bepuicm
                                        * Referenced by: '<S42>/range y // range x'
                                        */
  real_T mapminmax_xmin;               /* Mask Parameter: mapminmax_xmin
                                        * Referenced by:
                                        *   '<S15>/Subtract min x'
                                        *   '<S15>/range y // range x'
                                        */
  real_T mapminmax_xmin_iehjoea5ea;    /* Mask Parameter: mapminmax_xmin_iehjoea5ea
                                        * Referenced by:
                                        *   '<S22>/Subtract min x'
                                        *   '<S22>/range y // range x'
                                        */
  real_T mapminmax_xmin_cuaeahpuiv;    /* Mask Parameter: mapminmax_xmin_cuaeahpuiv
                                        * Referenced by:
                                        *   '<S27>/Subtract min x'
                                        *   '<S27>/range y // range x'
                                        */
  real_T mapminmax_xmin_k4al5ovj24;    /* Mask Parameter: mapminmax_xmin_k4al5ovj24
                                        * Referenced by:
                                        *   '<S32>/Subtract min x'
                                        *   '<S32>/range y // range x'
                                        */
  real_T mapminmax1_xmin;              /* Mask Parameter: mapminmax1_xmin
                                        * Referenced by:
                                        *   '<S37>/Subtract min x'
                                        *   '<S37>/range y // range x'
                                        */
  real_T mapminmax_xmin_d0gqzccq3k;    /* Mask Parameter: mapminmax_xmin_d0gqzccq3k
                                        * Referenced by:
                                        *   '<S42>/Subtract min x'
                                        *   '<S42>/range y // range x'
                                        */
  real_T mapminmax_ymax;               /* Mask Parameter: mapminmax_ymax
                                        * Referenced by: '<S15>/range y // range x'
                                        */
  real_T mapminmax_ymax_iej5kpatil;    /* Mask Parameter: mapminmax_ymax_iej5kpatil
                                        * Referenced by: '<S22>/range y // range x'
                                        */
  real_T mapminmax_ymax_jfea2ow0og;    /* Mask Parameter: mapminmax_ymax_jfea2ow0og
                                        * Referenced by: '<S27>/range y // range x'
                                        */
  real_T mapminmax_ymax_ihor11sths;    /* Mask Parameter: mapminmax_ymax_ihor11sths
                                        * Referenced by: '<S32>/range y // range x'
                                        */
  real_T mapminmax1_ymax;              /* Mask Parameter: mapminmax1_ymax
                                        * Referenced by: '<S37>/range y // range x'
                                        */
  real_T mapminmax_ymax_lwlufp43xq;    /* Mask Parameter: mapminmax_ymax_lwlufp43xq
                                        * Referenced by: '<S42>/range y // range x'
                                        */
  real_T mapminmax_ymin;               /* Mask Parameter: mapminmax_ymin
                                        * Referenced by:
                                        *   '<S15>/Add min y'
                                        *   '<S15>/range y // range x'
                                        */
  real_T mapminmax_ymin_k5go5squy4;    /* Mask Parameter: mapminmax_ymin_k5go5squy4
                                        * Referenced by:
                                        *   '<S22>/Add min y'
                                        *   '<S22>/range y // range x'
                                        */
  real_T mapminmax_ymin_ogggrkrg4e;    /* Mask Parameter: mapminmax_ymin_ogggrkrg4e
                                        * Referenced by:
                                        *   '<S27>/Add min y'
                                        *   '<S27>/range y // range x'
                                        */
  real_T mapminmax_ymin_jjvvjjkkrv;    /* Mask Parameter: mapminmax_ymin_jjvvjjkkrv
                                        * Referenced by:
                                        *   '<S32>/Add min y'
                                        *   '<S32>/range y // range x'
                                        */
  real_T mapminmax1_ymin;              /* Mask Parameter: mapminmax1_ymin
                                        * Referenced by:
                                        *   '<S37>/Add min y'
                                        *   '<S37>/range y // range x'
                                        */
  real_T mapminmax_ymin_pwvv1lkczl;    /* Mask Parameter: mapminmax_ymin_pwvv1lkczl
                                        * Referenced by:
                                        *   '<S42>/Add min y'
                                        *   '<S42>/range y // range x'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S2>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S8>/PWM'
                                        */
  uint32_T DigitalOutput_pinNum_ek4xiwztl1;/* Mask Parameter: DigitalOutput_pinNum_ek4xiwztl1
                                            * Referenced by: '<S19>/Digital Output'
                                            */
  uint32_T PWM_pinNumber_nkrnw2yx44;   /* Mask Parameter: PWM_pinNumber_nkrnw2yx44
                                        * Referenced by: '<S21>/PWM'
                                        */
  uint32_T DigitalOutput_pinNum_hetit3zm4v;/* Mask Parameter: DigitalOutput_pinNum_hetit3zm4v
                                            * Referenced by: '<S24>/Digital Output'
                                            */
  uint32_T PWM_pinNumber_hoyrwcvift;   /* Mask Parameter: PWM_pinNumber_hoyrwcvift
                                        * Referenced by: '<S26>/PWM'
                                        */
  uint32_T DigitalOutput_pinNum_bkde3yd3cq;/* Mask Parameter: DigitalOutput_pinNum_bkde3yd3cq
                                            * Referenced by: '<S29>/Digital Output'
                                            */
  uint32_T PWM_pinNumber_mx02rvdlnc;   /* Mask Parameter: PWM_pinNumber_mx02rvdlnc
                                        * Referenced by: '<S31>/PWM'
                                        */
  uint32_T DigitalOutput_pinNum_j5nhbsiy1k;/* Mask Parameter: DigitalOutput_pinNum_j5nhbsiy1k
                                            * Referenced by: '<S34>/Digital Output'
                                            */
  uint32_T PWM_pinNumber_cubsriyfnt;   /* Mask Parameter: PWM_pinNumber_cubsriyfnt
                                        * Referenced by: '<S36>/PWM'
                                        */
  uint32_T DigitalOutput_pinNum_p3klgfr0gp;/* Mask Parameter: DigitalOutput_pinNum_p3klgfr0gp
                                            * Referenced by: '<S39>/Digital Output'
                                            */
  uint32_T PWM_pinNumber_n4eukf2fei;   /* Mask Parameter: PWM_pinNumber_n4eukf2fei
                                        * Referenced by: '<S41>/PWM'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T theta_x_Value;                /* Expression: 0
                                        * Referenced by: '<S17>/theta_x'
                                        */
  real_T theta_y_Value;                /* Expression: 0
                                        * Referenced by: '<S17>/theta_y'
                                        */
  real_T theta_z_Value;                /* Expression: 0
                                        * Referenced by: '<S17>/theta_z'
                                        */
  real_T x_Value;                      /* Expression: 0
                                        * Referenced by: '<S17>/x'
                                        */
  real_T y_Value;                      /* Expression: 0
                                        * Referenced by: '<S17>/y'
                                        */
  real_T z_Value;                      /* Expression: 0
                                        * Referenced by: '<S17>/z'
                                        */
  real_T theta_x_Value_ekze1zr2o2;     /* Expression: 0
                                        * Referenced by: '<S6>/theta_x'
                                        */
  real_T theta_y_Value_hpy1hkark1;     /* Expression: 0
                                        * Referenced by: '<S6>/theta_y'
                                        */
  real_T theta_z_Value_gi4rxypddg;     /* Expression: 0
                                        * Referenced by: '<S6>/theta_z'
                                        */
  real_T x_Value_erhep10kxc;           /* Expression: 0
                                        * Referenced by: '<S6>/x'
                                        */
  real_T y_Value_au20vl24uo;           /* Expression: 0
                                        * Referenced by: '<S6>/y'
                                        */
  real_T z_Amp;                        /* Expression: 50
                                        * Referenced by: '<S6>/z'
                                        */
  real_T z_Bias;                       /* Expression: 0
                                        * Referenced by: '<S6>/z'
                                        */
  real_T z_Freq;                       /* Expression: 60
                                        * Referenced by: '<S6>/z'
                                        */
  real_T z_Phase;                      /* Expression: 0
                                        * Referenced by: '<S6>/z'
                                        */
  real_T Switch_Threshold;             /* Expression: -1
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T rm_Value;                     /* Expression: 200
                                        * Referenced by: '<S16>/rm'
                                        */
  real_T rf_Value;                     /* Expression: 270
                                        * Referenced by: '<S16>/rf'
                                        */
  real_T alpha_Value;                  /* Expression: 0.007
                                        * Referenced by: '<S16>/alpha'
                                        */
  real_T beta_Value;                   /* Expression: 0.009
                                        * Referenced by: '<S16>/beta'
                                        */
  real_T h_Value;                      /* Expression: 380
                                        * Referenced by: '<S16>/h'
                                        */
  real_T Lmin_Value;                   /* Expression: 350
                                        * Referenced by: '<S3>/Lmin'
                                        */
  real_T Lmax_Value;                   /* Expression: 500
                                        * Referenced by: '<S3>/Lmax'
                                        */
  real_T Gain6_Gain;                   /* Expression: 5
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 200
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -200
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant_Value_cxtxrspyx2;    /* Expression: 1
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Lmin_Value_fxiqxw14ju;        /* Expression: 350
                                        * Referenced by: '<S20>/Lmin'
                                        */
  real_T Lmax_Value_fp0qrty4ea;        /* Expression: 500
                                        * Referenced by: '<S20>/Lmax'
                                        */
  real_T Gain1_Gain;                   /* Expression: 5
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Saturation_UpperSat_b3rn2kfzri;/* Expression: 200
                                         * Referenced by: '<S18>/Saturation'
                                         */
  real_T Saturation_LowerSat_bvomtudfti;/* Expression: -200
                                         * Referenced by: '<S18>/Saturation'
                                         */
  real_T Constant1_Value_cnehq0fw23;   /* Expression: 2
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Constant_Value_dqqxjknpbv;    /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Lmin_Value_d1kp3d2x14;        /* Expression: 350
                                        * Referenced by: '<S25>/Lmin'
                                        */
  real_T Lmax_Value_nmppsrzwc4;        /* Expression: 500
                                        * Referenced by: '<S25>/Lmax'
                                        */
  real_T Gain2_Gain;                   /* Expression: 5
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T Saturation_UpperSat_dnbjpnjl05;/* Expression: 200
                                         * Referenced by: '<S23>/Saturation'
                                         */
  real_T Saturation_LowerSat_am0q0a0ygv;/* Expression: -200
                                         * Referenced by: '<S23>/Saturation'
                                         */
  real_T Constant1_Value_bzdab4one2;   /* Expression: 2
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T Constant_Value_ohnaqb1c5m;    /* Expression: 1
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T Lmin_Value_jjhk2iniiu;        /* Expression: 350
                                        * Referenced by: '<S30>/Lmin'
                                        */
  real_T Lmax_Value_lhquxpnirq;        /* Expression: 500
                                        * Referenced by: '<S30>/Lmax'
                                        */
  real_T Gain3_Gain;                   /* Expression: 5
                                        * Referenced by: '<S11>/Gain3'
                                        */
  real_T Saturation_UpperSat_llrmljpyl3;/* Expression: 200
                                         * Referenced by: '<S28>/Saturation'
                                         */
  real_T Saturation_LowerSat_ld4hzxvf1k;/* Expression: -200
                                         * Referenced by: '<S28>/Saturation'
                                         */
  real_T Constant1_Value_fhaxeoxakj;   /* Expression: 2
                                        * Referenced by: '<S28>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S33>/Constant3'
                                        */
  real_T Lmin_Value_asz1pke2r5;        /* Expression: 350
                                        * Referenced by: '<S35>/Lmin'
                                        */
  real_T Lmax_Value_nh4qnxlmtb;        /* Expression: 500
                                        * Referenced by: '<S35>/Lmax'
                                        */
  real_T Gain4_Gain;                   /* Expression: 5
                                        * Referenced by: '<S12>/Gain4'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 200
                                        * Referenced by: '<S33>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -200
                                        * Referenced by: '<S33>/Saturation1'
                                        */
  real_T Constant4_Value;              /* Expression: 2
                                        * Referenced by: '<S33>/Constant4'
                                        */
  real_T Constant_Value_gamabtpgbn;    /* Expression: 1
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T Lmin_Value_iw11bz0kqi;        /* Expression: 350
                                        * Referenced by: '<S40>/Lmin'
                                        */
  real_T Lmax_Value_pp0fbeghm2;        /* Expression: 500
                                        * Referenced by: '<S40>/Lmax'
                                        */
  real_T Gain5_Gain;                   /* Expression: 5
                                        * Referenced by: '<S13>/Gain5'
                                        */
  real_T Saturation_UpperSat_dpja4mkxr2;/* Expression: 200
                                         * Referenced by: '<S38>/Saturation'
                                         */
  real_T Saturation_LowerSat_iddp3i1r04;/* Expression: -200
                                         * Referenced by: '<S38>/Saturation'
                                         */
  real_T Constant1_Value_kij2jw3212;   /* Expression: 2
                                        * Referenced by: '<S38>/Constant1'
                                        */
  uint32_T Potentiomtre1_p1;           /* Computed Parameter: Potentiomtre1_p1
                                        * Referenced by: '<Root>/Potentiomètre 1'
                                        */
  uint32_T Potentiomtre2_p1;           /* Computed Parameter: Potentiomtre2_p1
                                        * Referenced by: '<S9>/Potentiomètre 2'
                                        */
  uint32_T Potentiomtre3_p1;           /* Computed Parameter: Potentiomtre3_p1
                                        * Referenced by: '<S10>/Potentiomètre 3'
                                        */
  uint32_T Potentiomtre4_p1;           /* Computed Parameter: Potentiomtre4_p1
                                        * Referenced by: '<S11>/Potentiomètre 4'
                                        */
  uint32_T Potentiomtre5_p1;           /* Computed Parameter: Potentiomtre5_p1
                                        * Referenced by: '<S12>/Potentiomètre 5'
                                        */
  uint32_T Potentiomtre6_p1;           /* Computed Parameter: Potentiomtre6_p1
                                        * Referenced by: '<S13>/Potentiomètre 6'
                                        */
  uint16_T Gain1_Gain_jfd0ao4z3a;      /* Computed Parameter: Gain1_Gain_jfd0ao4z3a
                                        * Referenced by: '<S3>/Gain1'
                                        */
  uint16_T Gain1_Gain_m20otgelwl;      /* Computed Parameter: Gain1_Gain_m20otgelwl
                                        * Referenced by: '<S20>/Gain1'
                                        */
  uint16_T Gain1_Gain_btfs54h4bx;      /* Computed Parameter: Gain1_Gain_btfs54h4bx
                                        * Referenced by: '<S25>/Gain1'
                                        */
  uint16_T Gain1_Gain_ptftxodxyn;      /* Computed Parameter: Gain1_Gain_ptftxodxyn
                                        * Referenced by: '<S30>/Gain1'
                                        */
  uint16_T Gain1_Gain_fpelshvuq5;      /* Computed Parameter: Gain1_Gain_fpelshvuq5
                                        * Referenced by: '<S35>/Gain1'
                                        */
  uint16_T Gain1_Gain_j13fe42xcx;      /* Computed Parameter: Gain1_Gain_j13fe42xcx
                                        * Referenced by: '<S40>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Stewart_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Stewart_T Stewart_P;

/* Block signals (auto storage) */
extern B_Stewart_T Stewart_B;

/* Model entry point functions */
extern void Stewart_initialize(void);
extern void Stewart_step(void);
extern void Stewart_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Stewart_T *const Stewart_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/theta_x' : Unused code path elimination
 * Block '<S4>/theta_y' : Unused code path elimination
 * Block '<S4>/theta_z' : Unused code path elimination
 * Block '<S4>/x' : Unused code path elimination
 * Block '<S4>/y' : Unused code path elimination
 * Block '<S4>/z' : Unused code path elimination
 * Block '<S7>/theta_x' : Unused code path elimination
 * Block '<S7>/theta_y' : Unused code path elimination
 * Block '<S7>/theta_z' : Unused code path elimination
 * Block '<S7>/x' : Unused code path elimination
 * Block '<S7>/y' : Unused code path elimination
 * Block '<S7>/z' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Stewart'
 * '<S1>'   : 'Stewart/Adaptation1'
 * '<S2>'   : 'Stewart/Digital Output'
 * '<S3>'   : 'Stewart/Kc1'
 * '<S4>'   : 'Stewart/Rotation z'
 * '<S5>'   : 'Stewart/Selecteur'
 * '<S6>'   : 'Stewart/Transaltion z'
 * '<S7>'   : 'Stewart/Vague'
 * '<S8>'   : 'Stewart/Vérin 1'
 * '<S9>'   : 'Stewart/Vérin 2'
 * '<S10>'  : 'Stewart/Vérin 3'
 * '<S11>'  : 'Stewart/Vérin 4'
 * '<S12>'  : 'Stewart/Vérin 5'
 * '<S13>'  : 'Stewart/Vérin 6'
 * '<S14>'  : 'Stewart/XY Graph'
 * '<S15>'  : 'Stewart/Adaptation1/mapminmax'
 * '<S16>'  : 'Stewart/Selecteur/Paramètres mécanisme'
 * '<S17>'  : 'Stewart/Selecteur/Stop'
 * '<S18>'  : 'Stewart/Vérin 2/Adaptation2'
 * '<S19>'  : 'Stewart/Vérin 2/Digital Output1'
 * '<S20>'  : 'Stewart/Vérin 2/Kc2'
 * '<S21>'  : 'Stewart/Vérin 2/Vérin 2'
 * '<S22>'  : 'Stewart/Vérin 2/Adaptation2/mapminmax'
 * '<S23>'  : 'Stewart/Vérin 3/Adaptation3'
 * '<S24>'  : 'Stewart/Vérin 3/Digital Output2'
 * '<S25>'  : 'Stewart/Vérin 3/Kc3'
 * '<S26>'  : 'Stewart/Vérin 3/Vérin 3'
 * '<S27>'  : 'Stewart/Vérin 3/Adaptation3/mapminmax'
 * '<S28>'  : 'Stewart/Vérin 4/Adaptation4'
 * '<S29>'  : 'Stewart/Vérin 4/Digital Output3'
 * '<S30>'  : 'Stewart/Vérin 4/Kc4'
 * '<S31>'  : 'Stewart/Vérin 4/Vérin 4'
 * '<S32>'  : 'Stewart/Vérin 4/Adaptation4/mapminmax'
 * '<S33>'  : 'Stewart/Vérin 5/Adaptation5'
 * '<S34>'  : 'Stewart/Vérin 5/Digital Output4'
 * '<S35>'  : 'Stewart/Vérin 5/Kc5'
 * '<S36>'  : 'Stewart/Vérin 5/Vérin 5'
 * '<S37>'  : 'Stewart/Vérin 5/Adaptation5/mapminmax1'
 * '<S38>'  : 'Stewart/Vérin 6/Adaptation6'
 * '<S39>'  : 'Stewart/Vérin 6/Digital Output5'
 * '<S40>'  : 'Stewart/Vérin 6/Kc6'
 * '<S41>'  : 'Stewart/Vérin 6/Vérin 6'
 * '<S42>'  : 'Stewart/Vérin 6/Adaptation6/mapminmax'
 */
#endif                                 /* RTW_HEADER_Stewart_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
