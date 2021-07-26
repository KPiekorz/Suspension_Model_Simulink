/*
 * suspension_only_model.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "suspension_only_model".
 *
 * Model version              : 1.55
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Jul 26 15:48:17 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_suspension_only_model_h_
#define RTW_HEADER_suspension_only_model_h_
#include <float.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef suspension_only_model_COMMON_INCLUDES_
#define suspension_only_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                              /* suspension_only_model_COMMON_INCLUDES_ */

#include "suspension_only_model_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "rt_matrixlib.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeDELTA
#define rtmGetOdeDELTA(rtm)            ((rtm)->odeDELTA)
#endif

#ifndef rtmSetOdeDELTA
#define rtmSetOdeDELTA(rtm, val)       ((rtm)->odeDELTA = (val))
#endif

#ifndef rtmGetOdeDFDX
#define rtmGetOdeDFDX(rtm)             ((rtm)->odeDFDX)
#endif

#ifndef rtmSetOdeDFDX
#define rtmSetOdeDFDX(rtm, val)        ((rtm)->odeDFDX = (val))
#endif

#ifndef rtmGetOdeF0
#define rtmGetOdeF0(rtm)               ((rtm)->odeF0)
#endif

#ifndef rtmSetOdeF0
#define rtmSetOdeF0(rtm, val)          ((rtm)->odeF0 = (val))
#endif

#ifndef rtmGetOdeF1
#define rtmGetOdeF1(rtm)               ((rtm)->odeF1)
#endif

#ifndef rtmSetOdeF1
#define rtmSetOdeF1(rtm, val)          ((rtm)->odeF1 = (val))
#endif

#ifndef rtmGetOdeFAC
#define rtmGetOdeFAC(rtm)              ((rtm)->odeFAC)
#endif

#ifndef rtmSetOdeFAC
#define rtmSetOdeFAC(rtm, val)         ((rtm)->odeFAC = (val))
#endif

#ifndef rtmGetOdePIVOTS
#define rtmGetOdePIVOTS(rtm)           ((rtm)->odePIVOTS)
#endif

#ifndef rtmSetOdePIVOTS
#define rtmSetOdePIVOTS(rtm, val)      ((rtm)->odePIVOTS = (val))
#endif

#ifndef rtmGetOdeW
#define rtmGetOdeW(rtm)                ((rtm)->odeW)
#endif

#ifndef rtmSetOdeW
#define rtmSetOdeW(rtm, val)           ((rtm)->odeW = (val))
#endif

#ifndef rtmGetOdeX0
#define rtmGetOdeX0(rtm)               ((rtm)->odeX0)
#endif

#ifndef rtmSetOdeX0
#define rtmSetOdeX0(rtm, val)          ((rtm)->odeX0 = (val))
#endif

#ifndef rtmGetOdeZ
#define rtmGetOdeZ(rtm)                ((rtm)->odeZ)
#endif

#ifndef rtmSetOdeZ
#define rtmSetOdeZ(rtm, val)           ((rtm)->odeZ = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T x1;                           /* '<S1>/Integrator1' */
  real_T x2;                           /* '<S1>/Integrator2' */
  real_T Add2;                         /* '<S1>/Add2' */
  real_T Gain2;                        /* '<S1>/Gain2' */
  real_T v1;                           /* '<S1>/Integrator' */
  real_T v2;                           /* '<S1>/Integrator3' */
  real_T Add3;                         /* '<S1>/Add3' */
  real_T damper1;                      /* '<S1>/damper1' */
  real_T Add;                          /* '<S1>/Add' */
  real_T Add4;                         /* '<S1>/Add4' */
  real_T Spring2;                      /* '<S1>/Spring2' */
  real_T Derivative;                   /* '<S1>/Derivative' */
  real_T Add5;                         /* '<S1>/Add5' */
  real_T damper2;                      /* '<S1>/damper2' */
  real_T Add1;                         /* '<S1>/Add1' */
  real_T a1;                           /* '<S1>/Gain' */
  real_T Gain1;                        /* '<S1>/Gain1' */
  real_T Integrator4;                  /* '<S1>/Integrator4' */
} B_suspension_only_model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<S1>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S1>/Derivative' */
  real_T TimeStampB;                   /* '<S1>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S1>/Derivative' */
} DW_suspension_only_model_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S1>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator3_CSTATE;           /* '<S1>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S1>/Integrator4' */
} X_suspension_only_model_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S1>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator3_CSTATE;           /* '<S1>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S1>/Integrator4' */
} XDot_suspension_only_model_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S1>/Integrator2' */
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
  boolean_T Integrator3_CSTATE;        /* '<S1>/Integrator3' */
  boolean_T Integrator4_CSTATE;        /* '<S1>/Integrator4' */
} XDis_suspension_only_model_T;

#ifndef ODE1BE_INTG
#define ODE1BE_INTG

/* ODE1BE Integration Data */
typedef struct {
  real_T *x0;
  real_T *f0;
  real_T *f1;
  real_T *Delta;
  real_T *fac;
  real_T *DFDX;
  real_T *W;
  int_T *pivots;
  real_T *z;
  real_T *M;
  boolean_T isFirstStep;
} ODE1BE_IntgData;

#endif

/* Parameters (default storage) */
struct P_suspension_only_model_T_ {
  real_T M1;                           /* Variable: M1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T M2;                           /* Variable: M2
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T b1;                           /* Variable: b1
                                        * Referenced by: '<S1>/damper1'
                                        */
  real_T b2;                           /* Variable: b2
                                        * Referenced by: '<S1>/damper2'
                                        */
  real_T k1;                           /* Variable: k1
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T k2;                           /* Variable: k2
                                        * Referenced by: '<S1>/Spring2'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator2'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator3'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_suspension_only_model_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_suspension_only_model_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeX0[5];
  real_T odeF0[5];
  real_T odeF1[5];
  real_T odeDELTA[5];
  real_T odeFAC[5];
  real_T odeDFDX[5*5];
  real_T odeW[5*5];
  int_T odePIVOTS[5];
  real_T odeZ[5];
  ODE1BE_IntgData intgData;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_suspension_only_model_T suspension_only_model_P;

/* Block signals (default storage) */
extern B_suspension_only_model_T suspension_only_model_B;

/* Continuous states (default storage) */
extern X_suspension_only_model_T suspension_only_model_X;

/* Block states (default storage) */
extern DW_suspension_only_model_T suspension_only_model_DW;

/* Model entry point functions */
extern void suspension_only_model_initialize(void);
extern void suspension_only_model_step(void);
extern void suspension_only_model_terminate(void);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  suspension_only_model_GetCAPIStaticMap(void);

/* Real-time Model object */
extern RT_MODEL_suspension_only_mode_T *const suspension_only_model_M;

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
 * '<Root>' : 'suspension_only_model'
 * '<S1>'   : 'suspension_only_model/suspension_model'
 */
#endif                                 /* RTW_HEADER_suspension_only_model_h_ */
