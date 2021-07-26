/*
 * suspension_only_model_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "suspension_only_model".
 *
 * Model version              : 1.57
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Jul 26 16:11:26 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "suspension_only_model_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "suspension_only_model.h"
#include "suspension_only_model_capi.h"
#include "suspension_only_model_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, TARGET_STRING("suspension_only_model/suspension_model/Derivative"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("suspension_only_model/suspension_model/Gain"),
    TARGET_STRING("a1"), 0, 0, 0, 0, 0 },

  { 2, 0, TARGET_STRING("suspension_only_model/suspension_model/Gain1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("suspension_only_model/suspension_model/Gain2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 4, 0, TARGET_STRING("suspension_only_model/suspension_model/Spring2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 5, 0, TARGET_STRING("suspension_only_model/suspension_model/damper1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 6, 0, TARGET_STRING("suspension_only_model/suspension_model/damper2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 7, 0, TARGET_STRING("suspension_only_model/suspension_model/Integrator"),
    TARGET_STRING("v1"), 0, 0, 0, 0, 0 },

  { 8, 0, TARGET_STRING("suspension_only_model/suspension_model/Integrator1"),
    TARGET_STRING("x1"), 0, 0, 0, 0, 0 },

  { 9, 0, TARGET_STRING("suspension_only_model/suspension_model/Integrator2"),
    TARGET_STRING("x2"), 0, 0, 0, 0, 0 },

  { 10, 0, TARGET_STRING("suspension_only_model/suspension_model/Integrator3"),
    TARGET_STRING("v2"), 0, 0, 0, 0, 0 },

  { 11, 0, TARGET_STRING("suspension_only_model/suspension_model/Integrator4"),
    TARGET_STRING("int(y1)"), 0, 0, 0, 0, 0 },

  { 12, 0, TARGET_STRING("suspension_only_model/suspension_model/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 13, 0, TARGET_STRING("suspension_only_model/suspension_model/Add1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 14, 0, TARGET_STRING("suspension_only_model/suspension_model/Add2"),
    TARGET_STRING("y1"), 0, 0, 0, 0, 0 },

  { 15, 0, TARGET_STRING("suspension_only_model/suspension_model/Add3"),
    TARGET_STRING("d/dt(y1)"), 0, 0, 0, 0, 0 },

  { 16, 0, TARGET_STRING("suspension_only_model/suspension_model/Add4"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 0, TARGET_STRING("suspension_only_model/suspension_model/Add5"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 18, TARGET_STRING("suspension_only_model/suspension_model/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 19, TARGET_STRING("suspension_only_model/suspension_model/Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 20, TARGET_STRING("suspension_only_model/suspension_model/Integrator2"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 21, TARGET_STRING("suspension_only_model/suspension_model/Integrator3"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 22, TARGET_STRING("suspension_only_model/suspension_model/Integrator4"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Block states information */
static const rtwCAPI_States rtBlockStates[] = {
  /* addrMapIndex, contStateStartIndex, blockPath,
   * stateName, pathAlias, dWorkIndex, dataTypeIndex, dimIndex,
   * fixPtIdx, sTimeIndex, isContinuous, hierInfoIdx, flatElemIdx
   */
  { 23, 2, TARGET_STRING("suspension_only_model/suspension_model/Integrator"),
    TARGET_STRING(""),
    TARGET_STRING(""),
    0, 0, 0, 0, 0, 1, -1, 0 },

  { 24, 0, TARGET_STRING("suspension_only_model/suspension_model/Integrator1"),
    TARGET_STRING(""),
    TARGET_STRING(""),
    0, 0, 0, 0, 0, 1, -1, 0 },

  { 25, 1, TARGET_STRING("suspension_only_model/suspension_model/Integrator2"),
    TARGET_STRING(""),
    TARGET_STRING(""),
    0, 0, 0, 0, 0, 1, -1, 0 },

  { 26, 3, TARGET_STRING("suspension_only_model/suspension_model/Integrator3"),
    TARGET_STRING(""),
    TARGET_STRING(""),
    0, 0, 0, 0, 0, 1, -1, 0 },

  { 27, 4, TARGET_STRING("suspension_only_model/suspension_model/Integrator4"),
    TARGET_STRING(""),
    TARGET_STRING(""),
    0, 0, 0, 0, 0, 1, -1, 0 },

  {
    0, -1, (NULL), (NULL), (NULL), 0, 0, 0, 0, 0, 0, -1, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 28, TARGET_STRING("M1"), 0, 0, 0 },

  { 29, TARGET_STRING("M2"), 0, 0, 0 },

  { 30, TARGET_STRING("b1"), 0, 0, 0 },

  { 31, TARGET_STRING("b2"), 0, 0, 0 },

  { 32, TARGET_STRING("k1"), 0, 0, 0 },

  { 33, TARGET_STRING("k2"), 0, 0, 0 },

  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &suspension_only_model_B.Derivative, /* 0: Signal */
  &suspension_only_model_B.a1,         /* 1: Signal */
  &suspension_only_model_B.Gain1,      /* 2: Signal */
  &suspension_only_model_B.Gain2,      /* 3: Signal */
  &suspension_only_model_B.Spring2,    /* 4: Signal */
  &suspension_only_model_B.damper1,    /* 5: Signal */
  &suspension_only_model_B.damper2,    /* 6: Signal */
  &suspension_only_model_B.v1,         /* 7: Signal */
  &suspension_only_model_B.x1,         /* 8: Signal */
  &suspension_only_model_B.x2,         /* 9: Signal */
  &suspension_only_model_B.v2,         /* 10: Signal */
  &suspension_only_model_B.inty1,      /* 11: Signal */
  &suspension_only_model_B.Add,        /* 12: Signal */
  &suspension_only_model_B.Add1,       /* 13: Signal */
  &suspension_only_model_B.y1,         /* 14: Signal */
  &suspension_only_model_B.ddty1,      /* 15: Signal */
  &suspension_only_model_B.Add4,       /* 16: Signal */
  &suspension_only_model_B.Add5,       /* 17: Signal */
  &suspension_only_model_P.Integrator_IC,/* 18: Block Parameter */
  &suspension_only_model_P.Integrator1_IC,/* 19: Block Parameter */
  &suspension_only_model_P.Integrator2_IC,/* 20: Block Parameter */
  &suspension_only_model_P.Integrator3_IC,/* 21: Block Parameter */
  &suspension_only_model_P.Integrator4_IC,/* 22: Block Parameter */
  &suspension_only_model_X.Integrator_CSTATE,/* 23: Continuous State */
  &suspension_only_model_X.Integrator1_CSTATE,/* 24: Continuous State */
  &suspension_only_model_X.Integrator2_CSTATE,/* 25: Continuous State */
  &suspension_only_model_X.Integrator3_CSTATE,/* 26: Continuous State */
  &suspension_only_model_X.Integrator4_CSTATE,/* 27: Continuous State */
  &suspension_only_model_P.M1,         /* 28: Model Parameter */
  &suspension_only_model_P.M2,         /* 29: Model Parameter */
  &suspension_only_model_P.b1,         /* 30: Model Parameter */
  &suspension_only_model_P.b2,         /* 31: Model Parameter */
  &suspension_only_model_P.k1,         /* 32: Model Parameter */
  &suspension_only_model_P.k2,         /* 33: Model Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1                                    /* 1 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[0],
    0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 18,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 5,
    rtModelParameters, 6 },

  { rtBlockStates, 5 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2048105773U,
    766069868U,
    2533507943U,
    3651091853U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  suspension_only_model_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void suspension_only_model_InitializeDataMapInfo(void)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(suspension_only_model_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(suspension_only_model_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(suspension_only_model_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(suspension_only_model_M->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(suspension_only_model_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(suspension_only_model_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(suspension_only_model_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(suspension_only_model_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void suspension_only_model_host_InitializeDataMapInfo
    (suspension_only_model_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: suspension_only_model_capi.c */
