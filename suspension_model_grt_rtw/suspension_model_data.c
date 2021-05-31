/*
 * suspension_model_data.c
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

/* Block parameters (default storage) */
P_suspension_model_T suspension_model_P = {
  /* Variable: M1
   * Referenced by: '<Root>/Gain'
   */
  2500.0,

  /* Variable: M2
   * Referenced by: '<Root>/Gain1'
   */
  320.0,

  /* Variable: b1
   * Referenced by: '<Root>/damper1'
   */
  350.0,

  /* Variable: b2
   * Referenced by: '<Root>/damper2'
   */
  15020.0,

  /* Variable: k1
   * Referenced by: '<Root>/Gain2'
   */
  80000.0,

  /* Variable: k2
   * Referenced by: '<Root>/Spring2'
   */
  500000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/U'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/U'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/U'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<Root>/Road'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<Root>/Road'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Road'
   */
  1.0
};
