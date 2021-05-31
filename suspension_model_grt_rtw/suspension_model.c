/*
 * suspension_model.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "suspension_model".
 *
 * Model version              : 1.28
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Jun  1 00:00:19 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "suspension_model.h"
#include "suspension_model_private.h"

/* Block signals (default storage) */
B_suspension_model_T suspension_model_B;

/* Continuous states */
X_suspension_model_T suspension_model_X;

/* Block states (default storage) */
DW_suspension_model_T suspension_model_DW;

/* Real-time model */
static RT_MODEL_suspension_model_T suspension_model_M_;
RT_MODEL_suspension_model_T *const suspension_model_M = &suspension_model_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  suspension_model_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  suspension_model_step();
  suspension_model_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  suspension_model_step();
  suspension_model_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  suspension_model_step();
  suspension_model_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void suspension_model_step(void)
{
  if (rtmIsMajorTimeStep(suspension_model_M)) {
    /* set solver stop time */
    if (!(suspension_model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&suspension_model_M->solverInfo,
                            ((suspension_model_M->Timing.clockTickH0 + 1) *
        suspension_model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&suspension_model_M->solverInfo,
                            ((suspension_model_M->Timing.clockTick0 + 1) *
        suspension_model_M->Timing.stepSize0 +
        suspension_model_M->Timing.clockTickH0 *
        suspension_model_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(suspension_model_M)) {
    suspension_model_M->Timing.t[0] = rtsiGetT(&suspension_model_M->solverInfo);
  }

  {
    real_T lastTime;
    real_T rtb_Derivative;
    real_T rtb_Gain2;
    real_T rtb_U;
    real_T rtb_damper1;
    real_T *lastU;

    /* Sum: '<Root>/Add2' incorporates:
     *  Integrator: '<Root>/Integrator1'
     *  Integrator: '<Root>/Integrator2'
     */
    suspension_model_B.Add2 = suspension_model_X.Integrator1_CSTATE -
      suspension_model_X.Integrator2_CSTATE;
    if (rtmIsMajorTimeStep(suspension_model_M)) {
    }

    /* Gain: '<Root>/Gain2' */
    rtb_Gain2 = suspension_model_P.k1 * suspension_model_B.Add2;

    /* Integrator: '<Root>/Integrator' */
    suspension_model_B.v1 = suspension_model_X.Integrator_CSTATE;

    /* Integrator: '<Root>/Integrator3' */
    suspension_model_B.v2 = suspension_model_X.Integrator3_CSTATE;

    /* Gain: '<Root>/damper1' incorporates:
     *  Sum: '<Root>/Add3'
     */
    rtb_damper1 = (suspension_model_B.v1 - suspension_model_B.v2) *
      suspension_model_P.b1;

    /* Step: '<Root>/U' incorporates:
     *  Step: '<Root>/Road'
     */
    rtb_Derivative = suspension_model_M->Timing.t[0];
    if (rtb_Derivative < suspension_model_P.U_Time) {
      rtb_U = suspension_model_P.U_Y0;
    } else {
      rtb_U = suspension_model_P.U_YFinal;
    }

    /* End of Step: '<Root>/U' */

    /* Step: '<Root>/Road' */
    if (rtb_Derivative < suspension_model_P.Road_Time) {
      /* Step: '<Root>/Road' */
      suspension_model_B.Road = suspension_model_P.Road_Y0;
    } else {
      /* Step: '<Root>/Road' */
      suspension_model_B.Road = suspension_model_P.Road_YFinal;
    }

    /* Derivative: '<Root>/Derivative' */
    rtb_Derivative = suspension_model_M->Timing.t[0];
    if ((suspension_model_DW.TimeStampA >= rtb_Derivative) &&
        (suspension_model_DW.TimeStampB >= rtb_Derivative)) {
      rtb_Derivative = 0.0;
    } else {
      lastTime = suspension_model_DW.TimeStampA;
      lastU = &suspension_model_DW.LastUAtTimeA;
      if (suspension_model_DW.TimeStampA < suspension_model_DW.TimeStampB) {
        if (suspension_model_DW.TimeStampB < rtb_Derivative) {
          lastTime = suspension_model_DW.TimeStampB;
          lastU = &suspension_model_DW.LastUAtTimeB;
        }
      } else {
        if (suspension_model_DW.TimeStampA >= rtb_Derivative) {
          lastTime = suspension_model_DW.TimeStampB;
          lastU = &suspension_model_DW.LastUAtTimeB;
        }
      }

      rtb_Derivative = (suspension_model_B.Road - *lastU) / (rtb_Derivative -
        lastTime);
    }

    /* End of Derivative: '<Root>/Derivative' */

    /* Gain: '<Root>/Gain' incorporates:
     *  Sum: '<Root>/Add'
     */
    suspension_model_B.a1 = ((rtb_U - rtb_Gain2) - rtb_damper1) * (1.0 /
      suspension_model_P.M1);

    /* Gain: '<Root>/Gain1' incorporates:
     *  Gain: '<Root>/Spring2'
     *  Gain: '<Root>/damper2'
     *  Integrator: '<Root>/Integrator2'
     *  Sum: '<Root>/Add1'
     *  Sum: '<Root>/Add4'
     *  Sum: '<Root>/Add5'
     */
    suspension_model_B.Gain1 = ((((rtb_damper1 + rtb_Gain2) - rtb_U) +
      (suspension_model_B.Road - suspension_model_X.Integrator2_CSTATE) *
      suspension_model_P.k2) + (rtb_Derivative - suspension_model_B.v2) *
      suspension_model_P.b2) * (1.0 / suspension_model_P.M2);
  }

  if (rtmIsMajorTimeStep(suspension_model_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(suspension_model_M->rtwLogInfo,
                        (suspension_model_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(suspension_model_M)) {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative' */
    if (suspension_model_DW.TimeStampA == (rtInf)) {
      suspension_model_DW.TimeStampA = suspension_model_M->Timing.t[0];
      lastU = &suspension_model_DW.LastUAtTimeA;
    } else if (suspension_model_DW.TimeStampB == (rtInf)) {
      suspension_model_DW.TimeStampB = suspension_model_M->Timing.t[0];
      lastU = &suspension_model_DW.LastUAtTimeB;
    } else if (suspension_model_DW.TimeStampA < suspension_model_DW.TimeStampB)
    {
      suspension_model_DW.TimeStampA = suspension_model_M->Timing.t[0];
      lastU = &suspension_model_DW.LastUAtTimeA;
    } else {
      suspension_model_DW.TimeStampB = suspension_model_M->Timing.t[0];
      lastU = &suspension_model_DW.LastUAtTimeB;
    }

    *lastU = suspension_model_B.Road;

    /* End of Update for Derivative: '<Root>/Derivative' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(suspension_model_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(suspension_model_M)!=-1) &&
          !((rtmGetTFinal(suspension_model_M)-
             (((suspension_model_M->Timing.clockTick1+
                suspension_model_M->Timing.clockTickH1* 4294967296.0)) * 0.01)) >
            (((suspension_model_M->Timing.clockTick1+
               suspension_model_M->Timing.clockTickH1* 4294967296.0)) * 0.01) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(suspension_model_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&suspension_model_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++suspension_model_M->Timing.clockTick0)) {
      ++suspension_model_M->Timing.clockTickH0;
    }

    suspension_model_M->Timing.t[0] = rtsiGetSolverStopTime
      (&suspension_model_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      suspension_model_M->Timing.clockTick1++;
      if (!suspension_model_M->Timing.clockTick1) {
        suspension_model_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void suspension_model_derivatives(void)
{
  XDot_suspension_model_T *_rtXdot;
  _rtXdot = ((XDot_suspension_model_T *) suspension_model_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = suspension_model_B.v1;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = suspension_model_B.v2;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = suspension_model_B.a1;

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = suspension_model_B.Gain1;
}

/* Model initialize function */
void suspension_model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)suspension_model_M, 0,
                sizeof(RT_MODEL_suspension_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&suspension_model_M->solverInfo,
                          &suspension_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&suspension_model_M->solverInfo, &rtmGetTPtr(suspension_model_M));
    rtsiSetStepSizePtr(&suspension_model_M->solverInfo,
                       &suspension_model_M->Timing.stepSize0);
    rtsiSetdXPtr(&suspension_model_M->solverInfo, &suspension_model_M->derivs);
    rtsiSetContStatesPtr(&suspension_model_M->solverInfo, (real_T **)
                         &suspension_model_M->contStates);
    rtsiSetNumContStatesPtr(&suspension_model_M->solverInfo,
      &suspension_model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&suspension_model_M->solverInfo,
      &suspension_model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&suspension_model_M->solverInfo,
      &suspension_model_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&suspension_model_M->solverInfo,
      &suspension_model_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&suspension_model_M->solverInfo, (&rtmGetErrorStatus
      (suspension_model_M)));
    rtsiSetRTModelPtr(&suspension_model_M->solverInfo, suspension_model_M);
  }

  rtsiSetSimTimeStep(&suspension_model_M->solverInfo, MAJOR_TIME_STEP);
  suspension_model_M->intgData.y = suspension_model_M->odeY;
  suspension_model_M->intgData.f[0] = suspension_model_M->odeF[0];
  suspension_model_M->intgData.f[1] = suspension_model_M->odeF[1];
  suspension_model_M->intgData.f[2] = suspension_model_M->odeF[2];
  suspension_model_M->intgData.f[3] = suspension_model_M->odeF[3];
  suspension_model_M->contStates = ((X_suspension_model_T *) &suspension_model_X);
  rtsiSetSolverData(&suspension_model_M->solverInfo, (void *)
                    &suspension_model_M->intgData);
  rtsiSetSolverName(&suspension_model_M->solverInfo,"ode4");
  rtmSetTPtr(suspension_model_M, &suspension_model_M->Timing.tArray[0]);
  rtmSetTFinal(suspension_model_M, 50.0);
  suspension_model_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    suspension_model_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(suspension_model_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(suspension_model_M->rtwLogInfo, (NULL));
    rtliSetLogT(suspension_model_M->rtwLogInfo, "tout");
    rtliSetLogX(suspension_model_M->rtwLogInfo, "");
    rtliSetLogXFinal(suspension_model_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(suspension_model_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(suspension_model_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(suspension_model_M->rtwLogInfo, 0);
    rtliSetLogDecimation(suspension_model_M->rtwLogInfo, 1);
    rtliSetLogY(suspension_model_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(suspension_model_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(suspension_model_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &suspension_model_B), 0,
                sizeof(B_suspension_model_T));

  /* states (continuous) */
  {
    (void) memset((void *)&suspension_model_X, 0,
                  sizeof(X_suspension_model_T));
  }

  /* states (dwork) */
  (void) memset((void *)&suspension_model_DW, 0,
                sizeof(DW_suspension_model_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(suspension_model_M->rtwLogInfo, 0.0,
    rtmGetTFinal(suspension_model_M), suspension_model_M->Timing.stepSize0,
    (&rtmGetErrorStatus(suspension_model_M)));

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  suspension_model_X.Integrator1_CSTATE = suspension_model_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  suspension_model_X.Integrator2_CSTATE = suspension_model_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  suspension_model_X.Integrator_CSTATE = suspension_model_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator3' */
  suspension_model_X.Integrator3_CSTATE = suspension_model_P.Integrator3_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  suspension_model_DW.TimeStampA = (rtInf);
  suspension_model_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void suspension_model_terminate(void)
{
  /* (no terminate code required) */
}
