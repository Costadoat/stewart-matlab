/*
 * File: Stewart2.h
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

#ifndef RTW_HEADER_Stewart2_h_
#define RTW_HEADER_Stewart2_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Stewart2_COMMON_INCLUDES_
# define Stewart2_COMMON_INCLUDES_
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
#endif                                 /* Stewart2_COMMON_INCLUDES_ */

#include "Stewart2_types.h"

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
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T theta_x;                      /* '<Root>/theta_x' */
  real_T Add1;                         /* '<S3>/Add1' */
  real_T Gain6;                        /* '<Root>/Gain6' */
  real_T Divide;                       /* '<S1>/Divide' */
  real_T Abs;                          /* '<S1>/Abs' */
  real_T Addminy;                      /* '<S5>/Add min y' */
  int32_T DataTypeConversion;          /* '<S1>/Data Type Conversion' */
} B_Stewart2_T;

/* Parameters (auto storage) */
struct P_Stewart2_T_ {
  real_T mapminmax_xmax;               /* Mask Parameter: mapminmax_xmax
                                        * Referenced by: '<S5>/range y // range x'
                                        */
  real_T mapminmax_xmin;               /* Mask Parameter: mapminmax_xmin
                                        * Referenced by:
                                        *   '<S5>/Subtract min x'
                                        *   '<S5>/range y // range x'
                                        */
  real_T mapminmax_ymax;               /* Mask Parameter: mapminmax_ymax
                                        * Referenced by: '<S5>/range y // range x'
                                        */
  real_T mapminmax_ymin;               /* Mask Parameter: mapminmax_ymin
                                        * Referenced by:
                                        *   '<S5>/Add min y'
                                        *   '<S5>/range y // range x'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S2>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S4>/PWM'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T theta_x_Value;                /* Expression: 350
                                        * Referenced by: '<Root>/theta_x'
                                        */
  real_T Lmin_Value;                   /* Expression: 350
                                        * Referenced by: '<S3>/Lmin'
                                        */
  real_T Lmax_Value;                   /* Expression: 500
                                        * Referenced by: '<S3>/Lmax'
                                        */
  real_T Gain6_Gain;                   /* Expression: 10
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
  uint32_T Potentiomtre1_p1;           /* Computed Parameter: Potentiomtre1_p1
                                        * Referenced by: '<Root>/Potentiomètre 1'
                                        */
  uint16_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S3>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Stewart2_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

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
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Stewart2_T Stewart2_P;

/* Block signals (auto storage) */
extern B_Stewart2_T Stewart2_B;

/* Model entry point functions */
extern void Stewart2_initialize(void);
extern void Stewart2_step(void);
extern void Stewart2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Stewart2_T *const Stewart2_M;

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
 * '<Root>' : 'Stewart2'
 * '<S1>'   : 'Stewart2/Adaptation1'
 * '<S2>'   : 'Stewart2/Digital Output'
 * '<S3>'   : 'Stewart2/Kc1'
 * '<S4>'   : 'Stewart2/Vérin 1'
 * '<S5>'   : 'Stewart2/Adaptation1/mapminmax'
 */
#endif                                 /* RTW_HEADER_Stewart2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
