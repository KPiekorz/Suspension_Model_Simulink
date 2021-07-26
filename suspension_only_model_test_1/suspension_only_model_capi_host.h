#ifndef RTW_HEADER_suspension_only_model_cap_host_h_
#define RTW_HEADER_suspension_only_model_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} suspension_only_model_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void suspension_only_model_host_InitializeDataMapInfo
    (suspension_only_model_host_DataMapInfo_T *dataMap, const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                        /* RTW_HEADER_suspension_only_model_cap_host_h_ */

/* EOF: suspension_only_model_capi_host.h */
