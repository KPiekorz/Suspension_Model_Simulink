/*
 * suspension_only_model.c
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

#include "rt_logging_mmi.h"
#include "suspension_only_model_capi.h"
#include "suspension_only_model.h"
#include "suspension_only_model_private.h"

/* Block signals (default storage) */
B_suspension_only_model_T suspension_only_model_B;

/* Continuous states */
X_suspension_only_model_T suspension_only_model_X;

/* Block states (default storage) */
DW_suspension_only_model_T suspension_only_model_DW;

/* Real-time model */
static RT_MODEL_suspension_only_mode_T suspension_only_model_M_;
RT_MODEL_suspension_only_mode_T *const suspension_only_model_M =
  &suspension_only_model_M_;

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *Fty, real_T *fac,
                  real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = pow(EPS, 0.75);
  real_T BU = pow(EPS, 0.25);
  real_T FACMIN = pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 5;
  real_T *x = rtsiGetContStates(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = fabs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = fabs(del);
    else
      del = -fabs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    suspension_only_model_step();
    rtsiSetdX(si,p);
    suspension_only_model_derivatives();
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = fabs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = fabs(FdelRowmax);
      if (fscale < fabs(Fty[rowmax]))
        fscale = fabs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE1be fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE1BE_IntgData *id = (ODE1BE_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *z = id->z;
  int_T i,iter;
  int_T nx = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  suspension_only_model_derivatives();
  local_numjac(si,x0,f0,fac,dfdx );
  for (i = 0;i < nx; i++) {
    z[i] = 0;
  }

  t1 = t0 + h;
  rtsiSetT(si, t1);

  /* Newton iteration Loop */
  for (iter = 0; iter < numIter; iter++) {
    real_T *p;

    /* Compute f(t1,x1) */
    rtsiSetdX(si, f1);
    suspension_only_model_step();
    suspension_only_model_derivatives();

    /* Compute Newton RHS Delta = h*Delta - M*z =
       h*f1 - M*(xn - x0)*/
    for (i = 0; i < nx; i++) {
      Delta[i] = h*f1[i];
    }

    if (iter >= 1) {
      for (i = 0; i < nx; i++) {
        Delta[i] -= z[i];
      }
    }

    /* LU = (M - hJ) */
    (void) memcpy(W, dfdx,
                  (uint_T)nx*nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-h);
    }

    for (p = W, i = 0; i < nx; i++, p += (nx+1)) {
      *p += 1.0;
    }

    rt_lu_real(W, nx,
               pivots);

    /* Delta = inv(U)*inv(L)*z */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* Update x1 and z = x - x0 */
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      z[i] += Delta[i];                /*x1[i] - x0[i];*/
    }
  }

  /* Run whatever FixedStepSolver::PostStep is doing */

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void suspension_only_model_step(void)
{
  if (rtmIsMajorTimeStep(suspension_only_model_M)) {
    /* set solver stop time */
    if (!(suspension_only_model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&suspension_only_model_M->solverInfo,
                            ((suspension_only_model_M->Timing.clockTickH0 + 1) *
        suspension_only_model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&suspension_only_model_M->solverInfo,
                            ((suspension_only_model_M->Timing.clockTick0 + 1) *
        suspension_only_model_M->Timing.stepSize0 +
        suspension_only_model_M->Timing.clockTickH0 *
        suspension_only_model_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(suspension_only_model_M)) {
    suspension_only_model_M->Timing.t[0] = rtsiGetT
      (&suspension_only_model_M->solverInfo);
  }

  {
    real_T lastTime;
    real_T *lastU;

    /* Integrator: '<S1>/Integrator1' */
    suspension_only_model_B.x1 = suspension_only_model_X.Integrator1_CSTATE;

    /* Integrator: '<S1>/Integrator2' */
    suspension_only_model_B.x2 = suspension_only_model_X.Integrator2_CSTATE;

    /* Sum: '<S1>/Add2' */
    suspension_only_model_B.Add2 = suspension_only_model_B.x1 -
      suspension_only_model_B.x2;

    /* Gain: '<S1>/Gain2' */
    suspension_only_model_B.Gain2 = suspension_only_model_P.k1 *
      suspension_only_model_B.Add2;

    /* Integrator: '<S1>/Integrator' */
    suspension_only_model_B.v1 = suspension_only_model_X.Integrator_CSTATE;

    /* Integrator: '<S1>/Integrator3' */
    suspension_only_model_B.v2 = suspension_only_model_X.Integrator3_CSTATE;

    /* Sum: '<S1>/Add3' */
    suspension_only_model_B.Add3 = suspension_only_model_B.v1 -
      suspension_only_model_B.v2;

    /* Gain: '<S1>/damper1' */
    suspension_only_model_B.damper1 = suspension_only_model_P.b1 *
      suspension_only_model_B.Add3;

    /* Sum: '<S1>/Add' */
    suspension_only_model_B.Add = (0.0 - suspension_only_model_B.Gain2) -
      suspension_only_model_B.damper1;

    /* Sum: '<S1>/Add4' */
    suspension_only_model_B.Add4 = 0.0 - suspension_only_model_B.x2;

    /* Gain: '<S1>/Spring2' */
    suspension_only_model_B.Spring2 = suspension_only_model_P.k2 *
      suspension_only_model_B.Add4;

    /* Derivative: '<S1>/Derivative' */
    if ((suspension_only_model_DW.TimeStampA >=
         suspension_only_model_M->Timing.t[0]) &&
        (suspension_only_model_DW.TimeStampB >=
         suspension_only_model_M->Timing.t[0])) {
      /* Derivative: '<S1>/Derivative' */
      suspension_only_model_B.Derivative = 0.0;
    } else {
      lastTime = suspension_only_model_DW.TimeStampA;
      lastU = &suspension_only_model_DW.LastUAtTimeA;
      if (suspension_only_model_DW.TimeStampA <
          suspension_only_model_DW.TimeStampB) {
        if (suspension_only_model_DW.TimeStampB <
            suspension_only_model_M->Timing.t[0]) {
          lastTime = suspension_only_model_DW.TimeStampB;
          lastU = &suspension_only_model_DW.LastUAtTimeB;
        }
      } else {
        if (suspension_only_model_DW.TimeStampA >=
            suspension_only_model_M->Timing.t[0]) {
          lastTime = suspension_only_model_DW.TimeStampB;
          lastU = &suspension_only_model_DW.LastUAtTimeB;
        }
      }

      lastTime = suspension_only_model_M->Timing.t[0] - lastTime;

      /* Derivative: '<S1>/Derivative' */
      suspension_only_model_B.Derivative = (0.0 - *lastU) / lastTime;
    }

    /* End of Derivative: '<S1>/Derivative' */

    /* Sum: '<S1>/Add5' */
    suspension_only_model_B.Add5 = suspension_only_model_B.Derivative -
      suspension_only_model_B.v2;

    /* Gain: '<S1>/damper2' */
    suspension_only_model_B.damper2 = suspension_only_model_P.b2 *
      suspension_only_model_B.Add5;

    /* Sum: '<S1>/Add1' */
    suspension_only_model_B.Add1 = ((suspension_only_model_B.damper1 +
      suspension_only_model_B.Gain2) + suspension_only_model_B.Spring2) +
      suspension_only_model_B.damper2;

    /* Gain: '<S1>/Gain' */
    lastTime = 1.0 / suspension_only_model_P.M1;

    /* Gain: '<S1>/Gain' */
    suspension_only_model_B.a1 = lastTime * suspension_only_model_B.Add;

    /* Gain: '<S1>/Gain1' */
    lastTime = 1.0 / suspension_only_model_P.M2;

    /* Gain: '<S1>/Gain1' */
    suspension_only_model_B.Gain1 = lastTime * suspension_only_model_B.Add1;

    /* Integrator: '<S1>/Integrator4' */
    suspension_only_model_B.Integrator4 =
      suspension_only_model_X.Integrator4_CSTATE;
  }

  if (rtmIsMajorTimeStep(suspension_only_model_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(suspension_only_model_M->rtwLogInfo,
                        (suspension_only_model_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(suspension_only_model_M)) {
    real_T *lastU;

    /* Update for Derivative: '<S1>/Derivative' */
    if (suspension_only_model_DW.TimeStampA == (rtInf)) {
      suspension_only_model_DW.TimeStampA = suspension_only_model_M->Timing.t[0];
      lastU = &suspension_only_model_DW.LastUAtTimeA;
    } else if (suspension_only_model_DW.TimeStampB == (rtInf)) {
      suspension_only_model_DW.TimeStampB = suspension_only_model_M->Timing.t[0];
      lastU = &suspension_only_model_DW.LastUAtTimeB;
    } else if (suspension_only_model_DW.TimeStampA <
               suspension_only_model_DW.TimeStampB) {
      suspension_only_model_DW.TimeStampA = suspension_only_model_M->Timing.t[0];
      lastU = &suspension_only_model_DW.LastUAtTimeA;
    } else {
      suspension_only_model_DW.TimeStampB = suspension_only_model_M->Timing.t[0];
      lastU = &suspension_only_model_DW.LastUAtTimeB;
    }

    *lastU = 0.0;

    /* End of Update for Derivative: '<S1>/Derivative' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(suspension_only_model_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(suspension_only_model_M)!=-1) &&
          !((rtmGetTFinal(suspension_only_model_M)-
             (((suspension_only_model_M->Timing.clockTick1+
                suspension_only_model_M->Timing.clockTickH1* 4294967296.0)) *
              0.01)) > (((suspension_only_model_M->Timing.clockTick1+
                          suspension_only_model_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01) * (DBL_EPSILON))) {
        rtmSetErrorStatus(suspension_only_model_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&suspension_only_model_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++suspension_only_model_M->Timing.clockTick0)) {
      ++suspension_only_model_M->Timing.clockTickH0;
    }

    suspension_only_model_M->Timing.t[0] = rtsiGetSolverStopTime
      (&suspension_only_model_M->solverInfo);

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
      suspension_only_model_M->Timing.clockTick1++;
      if (!suspension_only_model_M->Timing.clockTick1) {
        suspension_only_model_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void suspension_only_model_derivatives(void)
{
  XDot_suspension_only_model_T *_rtXdot;
  _rtXdot = ((XDot_suspension_only_model_T *) suspension_only_model_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = suspension_only_model_B.v1;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = suspension_only_model_B.v2;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = suspension_only_model_B.a1;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = suspension_only_model_B.Gain1;

  /* Derivatives for Integrator: '<S1>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = suspension_only_model_B.Add2;
}

/* Model initialize function */
void suspension_only_model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)suspension_only_model_M, 0,
                sizeof(RT_MODEL_suspension_only_mode_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&suspension_only_model_M->solverInfo,
                          &suspension_only_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&suspension_only_model_M->solverInfo, &rtmGetTPtr
                (suspension_only_model_M));
    rtsiSetStepSizePtr(&suspension_only_model_M->solverInfo,
                       &suspension_only_model_M->Timing.stepSize0);
    rtsiSetdXPtr(&suspension_only_model_M->solverInfo,
                 &suspension_only_model_M->derivs);
    rtsiSetContStatesPtr(&suspension_only_model_M->solverInfo, (real_T **)
                         &suspension_only_model_M->contStates);
    rtsiSetNumContStatesPtr(&suspension_only_model_M->solverInfo,
      &suspension_only_model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&suspension_only_model_M->solverInfo,
      &suspension_only_model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&suspension_only_model_M->solverInfo,
      &suspension_only_model_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&suspension_only_model_M->solverInfo,
      &suspension_only_model_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&suspension_only_model_M->solverInfo,
                          (&rtmGetErrorStatus(suspension_only_model_M)));
    rtsiSetRTModelPtr(&suspension_only_model_M->solverInfo,
                      suspension_only_model_M);
  }

  rtsiSetSimTimeStep(&suspension_only_model_M->solverInfo, MAJOR_TIME_STEP);
  suspension_only_model_M->intgData.x0 = suspension_only_model_M->odeX0;
  suspension_only_model_M->intgData.f0 = suspension_only_model_M->odeF0;
  suspension_only_model_M->intgData.f1 = suspension_only_model_M->odeF1;
  suspension_only_model_M->intgData.Delta = suspension_only_model_M->odeDELTA;
  suspension_only_model_M->intgData.fac = suspension_only_model_M->odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = suspension_only_model_M->intgData.fac;
    for (i = 0; i < (int_T)(sizeof(suspension_only_model_M->odeFAC)/sizeof
                            (real_T)); i++) {
      f[i] = 1.5e-8;
    }
  }

  suspension_only_model_M->intgData.DFDX = suspension_only_model_M->odeDFDX;
  suspension_only_model_M->intgData.W = suspension_only_model_M->odeW;
  suspension_only_model_M->intgData.pivots = suspension_only_model_M->odePIVOTS;
  suspension_only_model_M->intgData.z = suspension_only_model_M->odeZ;
  suspension_only_model_M->intgData.isFirstStep = true;
  rtsiSetSolverNumberNewtonIterations(&suspension_only_model_M->solverInfo, 1);
  suspension_only_model_M->contStates = ((X_suspension_only_model_T *)
    &suspension_only_model_X);
  rtsiSetSolverData(&suspension_only_model_M->solverInfo, (void *)
                    &suspension_only_model_M->intgData);
  rtsiSetSolverName(&suspension_only_model_M->solverInfo,"ode1be");
  rtmSetTPtr(suspension_only_model_M, &suspension_only_model_M->Timing.tArray[0]);
  rtmSetTFinal(suspension_only_model_M, 20.0);
  suspension_only_model_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    suspension_only_model_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(suspension_only_model_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(suspension_only_model_M->rtwLogInfo, (NULL));
    rtliSetLogT(suspension_only_model_M->rtwLogInfo, "tout");
    rtliSetLogX(suspension_only_model_M->rtwLogInfo, "");
    rtliSetLogXFinal(suspension_only_model_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(suspension_only_model_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(suspension_only_model_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(suspension_only_model_M->rtwLogInfo, 0);
    rtliSetLogDecimation(suspension_only_model_M->rtwLogInfo, 1);
    rtliSetLogY(suspension_only_model_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(suspension_only_model_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(suspension_only_model_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &suspension_only_model_B), 0,
                sizeof(B_suspension_only_model_T));

  /* states (continuous) */
  {
    (void) memset((void *)&suspension_only_model_X, 0,
                  sizeof(X_suspension_only_model_T));
  }

  /* states (dwork) */
  (void) memset((void *)&suspension_only_model_DW, 0,
                sizeof(DW_suspension_only_model_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  suspension_only_model_InitializeDataMapInfo();

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(suspension_only_model_M->rtwLogInfo, 0.0,
    rtmGetTFinal(suspension_only_model_M),
    suspension_only_model_M->Timing.stepSize0, (&rtmGetErrorStatus
    (suspension_only_model_M)));

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  suspension_only_model_X.Integrator1_CSTATE =
    suspension_only_model_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  suspension_only_model_X.Integrator2_CSTATE =
    suspension_only_model_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  suspension_only_model_X.Integrator_CSTATE =
    suspension_only_model_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  suspension_only_model_X.Integrator3_CSTATE =
    suspension_only_model_P.Integrator3_IC;

  /* InitializeConditions for Derivative: '<S1>/Derivative' */
  suspension_only_model_DW.TimeStampA = (rtInf);
  suspension_only_model_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S1>/Integrator4' */
  suspension_only_model_X.Integrator4_CSTATE =
    suspension_only_model_P.Integrator4_IC;
}

/* Model terminate function */
void suspension_only_model_terminate(void)
{
  /* (no terminate code required) */
}
