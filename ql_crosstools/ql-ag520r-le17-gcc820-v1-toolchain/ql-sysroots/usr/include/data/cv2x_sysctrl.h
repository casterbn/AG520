/**
  @file
  cv2x_sysctrl.h

  @brief
  This file provide APIs for cv2x syetem spefic qmi mesage processing.

*/

/*===========================================================================

Copyright (c) 2019 -2020 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CV2X_SYSCTRL_H
#define CV2X_SYSCTRL_H

#include "wireless_data_service_v01.h"
#include "cv2x_dbg.h"


/*---------------------------------------------------------------------------
                           DECLARATIONS and MACROS
---------------------------------------------------------------------------*/

typedef uint16_t cv2x_init_mode_t;

#define CV2X_MDM_OUT_OF_SERVICE   (0x0000)
#define CV2X_MDM_IN_SERVICE       (0x0001)


/** Return value from most of the CV2X functions. */
#define CV2X_SUCCESS   (0)   /**< Indicates that the operation was successful. */
#define CV2X_ERROR    (-1)   /**< Indicates that the operation was not successful. */


/* Entry and Exit macros */
#define CV2X_LOG_ENTRY  CV2X_LOG_DEBUG( "%s: ENTRY", __func__ );
#define CV2X_LOG_EXIT                                     \
  if( CV2X_SUCCESS == ret ) {                             \
    CV2X_LOG_DEBUG( "%s: EXIT with suc", __func__ );      \
  } else {                                               \
    CV2X_LOG_DEBUG( "%s: EXIT with err", __func__ );      \
  }


typedef void * cv2x_hndl_t;


typedef enum
{
  CV2X_INVALID_IND = -1,
  CV2X_CAPABILITY_INFO_IND = 0,
  CV2X_SEND_CONFIG_FILE_RESULT_IND,
  CV2X_SPS_SCHEDULING_INFO_IND,
  CV2X_SRC_L2_INFO_IND,
  CV2X_MAX_IND = 0xFF
} cv2x_msg_type_t;

typedef enum
{
  CV2X_REQUEST_INVALID = -1,
  C2X_GET_CAPABILITY_INFO_REQ = 0,
  CV2X_SEND_CONFIG_FILE_REQ,
  CV2X_TUNNEL_MODE_INFO_REQ,
  CV2X_UPDATE_SRC_L2_INFO_REQ,
  CV2X_REQUEST_MAX
} cv2x_req_t;


#define CV2X_OPT_PARAM_MASK_SPS_FLOW_CNT                          ((uint64_t) 0x01ull)
#define CV2X_OPT_PARAM_MASK_EVENT_DRIVEN_FLOW_CNT                 ((uint64_t) 0x02ull)
#define CV2X_OPT_PARAM_MASK_CONCURRENCY_SUPPORT                   ((uint64_t) 0x04ull)
#define CV2X_OPT_PARAM_MASK_PPP_INFO                              ((uint64_t) 0x08ull)
#define CV2X_OPT_PARAM_MASK_MIN_TX_PWR                            ((uint64_t) 0x10ull)
#define CV2X_OPT_PARAM_MASK_MAX_TX_PWR                            ((uint64_t) 0x20ull)
#define CV2X_OPT_PARAM_MASK_PERIODICITY                           ((uint64_t) 0x40ull)
#define CV2X_OPT_PARAM_MASK_TX_POOL_ID                            ((uint64_t) 0x80ull)
#define CV2X_OPT_PARAM_MASK_SRC_L2_ID                             ((uint64_t) 0x100ull)
#define CV2X_OPT_PARAM_MASK_TRUSTED_L2_INFO                       ((uint64_t) 0x200ull)
#define CV2X_OPT_PARAM_MASK_MALACIOUS_SRC_L2_ID                   ((uint64_t) 0x400ull)


#define CV2X_PPPP_LIST_MAX          QMI_WDS_V2X_PPPP_LIST_MAX_V01
#define CV2X_PERIODICITY_LIST_MAX   QMI_WDS_V2X_PERIODICITY_LIST_MAX_V01
#define CV2X_POOL_ID_LIST_MAX_V01   QMI_WDS_V2X_POOL_ID_LIST_MAX_V01

typedef struct {
  uint8_t priority;
  uint16_t pdb;
}cv2x_pppp_info_type;  /* Type */

typedef struct {
  uint8_t pool_id;
  uint16_t min_freq;
  uint16_t max_freq;
}cv2x_tx_pool_id_info_type;  /* Type */

typedef struct {
  /* Mandatory */
  uint64_t opt_params_mask;
   /* Optional */
  uint8_t max_sps_flow_cnt;
  uint16_t max_event_driven_flow_cnt;
  uint8_t is_concurrency_supported;
  uint32_t pppp_info_len;
  cv2x_pppp_info_type pppp_info[CV2X_PPPP_LIST_MAX];
  int32_t min_tx_pwr;
  int32_t max_tx_pwr;
  uint32_t supported_periodicity_list_len;
  uint32_t supported_periodicity_list[CV2X_PERIODICITY_LIST_MAX];
  uint32_t tx_pool_id_list_len;
  cv2x_tx_pool_id_info_type tx_pool_id_list[CV2X_POOL_ID_LIST_MAX_V01];
}cv2x_get_capability_info_resp_msg_t;  /* Message */

typedef  cv2x_get_capability_info_resp_msg_t cv2x_capability_info_ind_msg_t;  /* Message */


#define CV2X_CONFIG_FILE_NAME_LEN_MAX  (512)

typedef struct {
  /* Mandatory */
  uint32_t cfg_file_path_len;
  uint8_t cfg_file_name[CV2X_CONFIG_FILE_NAME_LEN_MAX];
}cv2x_send_config_file_req_msg_t;

typedef enum {
  CV2X_CONFIG_FILE_SEND_RESULT_ENUM_MIN_ENUM_VAL = -1,
  CV2X_CONFIG_FILE_SUCCESS = 0,                 /**<  Success. */
  CV2X_CONFIG_FILE_FAILURE_INTERNAL = 1,        /**<  Internal failure. */
  CV2X_CONFIG_FILE_FAILURE_TIMEOUT = 2,         /**<  Timeout failure.*/
  CV2X_CONFIG_FILE_FAILURE_OUT_OF_ORDER = 3,    /**<  Out of order failure. */
  CV2X_CONFIG_FILE_FAILURE_DECODED_ERR = 4,     /**<  Decoded error failure. */
  CV2X_CONFIG_FILE_FAILURE_INVALID_STATE = 5,   /**<  Invalid state failure.  */
  CV2X_CONFIG_FILE_SEND_RESULT_ENUM_MAX_ENUM_VAL = 0xffff
}cv2x_config_file_send_result_enum;

typedef struct {
  /* Mandatory */
  /*  Result */
  cv2x_config_file_send_result_enum result;
}cv2x_send_config_file_result_ind_msg_t;  /* Message */

#define CV2X_INFO_LIST_MAX QMI_WDS_V2X_INFO_LIST_MAX_V01

typedef struct {
  uint32_t src_l2_id;
  float time_uncertainty;
  uint16_t position_confidence_level;
  uint16_t time_confidence_level;
  uint32_t propagation_delay;
}cv2x_trusted_ue_info_type;  /* Type */

typedef struct {
  /* Mandatory */
  uint64_t opt_params_mask;
  /* Optional */
  uint32_t malicious_src_l2_id_list_len;
  uint32_t malicious_src_l2_id_list[CV2X_INFO_LIST_MAX];
  uint32_t trusted_l2_info_ex_len;
  cv2x_trusted_ue_info_type trusted_l2_info_ex[CV2X_INFO_LIST_MAX];
}cv2x_tunnel_mode_info_req_msg_t;  /* Message */

typedef struct {
  uint8_t sps_id;
  uint64_t utc_time;
  uint32_t periodicity;
}cv2x_sps_scheduling_info_ind_msg_t;  /* Type */

typedef struct {
  /* Mandatory */
  /*  Source L2 ID */
  uint32_t src_l2_id;
}cv2x_src_l2_info_ind_msg_t;  /* Message */

typedef struct
{
  cv2x_msg_type_t  msg_type;
  union
  {
    cv2x_capability_info_ind_msg_t          cv2x_capability_ind_info;
    cv2x_send_config_file_result_ind_msg_t  cv2x_send_config_file_result_ind_info;
    cv2x_sps_scheduling_info_ind_msg_t      cv2x_sps_scheduling_ind_info;
    cv2x_src_l2_info_ind_msg_t              cv2x_src_l2_ind_info;
  } cv2x_msg_info;
} cv2x_msg_info_t;


typedef void (*cv2x_init_cb_func)(cv2x_init_mode_t mode, void *userdata);

/** Callback function prototype for cv2x_sysctrl events. */
typedef void (*cv2x_ind_cb)
(
  cv2x_hndl_t               hndl,                       /*< Handle to which this ind is associated */
  cv2x_msg_type_t           cv2x_msg_type_t,            /**< Event identifier. **/
  cv2x_msg_info_t           *payload_ptr,                 /**< Associated event information. */
  void                      *user_data                   /**< Application-provided user data. */
);

/*===========================================================================
                    EXTERNAL FUNCTION PROTOTYPES
===========================================================================*/


/*===========================================================================
  FUNCTION:  cv2x_init
===========================================================================*/
/** @ingroup cv2x_init

    Initializes the cv2x_sysctrl library for the specified operating mode and
    executes a callback function with the callback data,
    given as an argument after completing init.

    This function must be invoked once per process, typically on process
    startup.

    param [in] init mode
    param [in] cv2x_init_cb_func
    param [in] userdata

    @return
    CV2X_SUCCESS -- Initialization was successful.
    CV2X_ERROR -- Initialization failed.

    @dependencies
    None.
*/
/*=========================================================================*/
extern int cv2x_init
(
  cv2x_init_cb_func cb_func,
  void *userdata
);

/*===========================================================================
  FUNCTION:  cv2x_release
===========================================================================*/
/** @ingroup cv2x_release

    Clean-up the cv2x_sysctrl library.

    @return
    CV2X_SUCCESS -- Cleanup was successful. \n
    CV2X_ERROR -- Cleanup failed.

    @dependencies
    None.
*/
/*=========================================================================*/
extern int cv2x_release(void);


/*===========================================================================
  FUNCTION:  cv2x_get_data_srvc_hndl
===========================================================================*/
/** @ingroup cv2x_get_data_srvc_hndl

    Gets an opaque handle. All subsequent functions use this
    handle as an input parameter.

    @note1hang

    @param[in] user_cb_fn  Client callback function used to post event indications.
    @param[in] user_data   Pointer to the client context block (cookie). The value may be NULL.

    @return
    cv2x_hndl_t if successfull, NULL otherwise.

    @dependencies
    cv2x_init() must be called.
*/
/*=========================================================================*/

extern cv2x_hndl_t cv2x_get_data_srvc_hndl
(
  cv2x_ind_cb user_cb_fn,
  void *user_data
);

/*===========================================================================
  FUNCTION:  cv2x_rel_data_srvc_hndl
===========================================================================*/
/** @ingroup cv2x_rel_data_srvc_hndl

    Releases a handle. All resources associated with the
    library are released.

    @note1hang

    @param[in] hndl Handle received from cv2x_get_data_srvc_hndl().

    @return
    None.

    @dependencies
    cv2x_init() must be called.
    The handle must be a valid handle obtained by cv2x_get_data_srvc_hndl().
*/
/*=========================================================================*/
extern void cv2x_rel_data_srvc_hndl
(
  cv2x_hndl_t hndl
);

/*===========================================================================
  FUNCTION:  cv2x_send_request
===========================================================================*/
/** @ingroup cv2x_send_request
    Send cv2x system spefic message using handle.

    @note1hang

    @param[in] hndl Handle received from cv2x_get_data_srvc_hndl().
    @param[in] cv2x_req_t cv2x message id
    @param[in] req_info request mesage data,this can be NULL;
    @param[in] resp_info response message. this can be NULL;


    @return
    None.

    @dependencies
    cv2x_init() must be called.
    The handle must be a valid handle obtained by cv2x_get_data_srvc_hndl().

*/
/*=========================================================================*/
extern int cv2x_send_request
(
 cv2x_hndl_t hndl, 
 cv2x_req_t req_type, 
 void *req_info,
 void *resp_info
 );

#endif /* CV2X_SYSCTRL_H */

#ifdef __cplusplus
}
#endif

