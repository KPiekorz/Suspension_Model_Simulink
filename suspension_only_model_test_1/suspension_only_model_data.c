/*
 * suspension_only_model_data.c
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

#include "suspension_only_model.h"
#include "suspension_only_model_private.h"

/* Block parameters (default storage) */
P_suspension_only_model_T suspension_only_model_P = {
  /* Variable: M1
   * Referenced by: '<S1>/Gain'
   */
  2500.0,

  /* Variable: M2
   * Referenced by: '<S1>/Gain1'
   */
  320.0,

  /* Variable: b1
   * Referenced by: '<S1>/damper1'
   */
  350.0,

  /* Variable: b2
   * Referenced by: '<S1>/damper2'
   */
  15020.0,

  /* Variable: k1
   * Referenced by: '<S1>/Gain2'
   */
  80000.0,

  /* Variable: k2
   * Referenced by: '<S1>/Spring2'
   */
  500000.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator4'
   */
  0.0
};
