#ifndef QUEC_COMMON_QMI_SERVICE_01_H
#define QUEC_COMMON_QMI_SERVICE_01_H
/**
  @file quec_common_qmi_v01.h

  @brief This is the public header file which defines the quec_common_qmi service Data structures.

  This header file defines the types and structures that were defined in
  quec_common_qmi. It contains the constant values defined, enums, structures,
  messages, and service message IDs (in that order) Structures that were
  defined in the IDL as messages contain mandatory elements, optional
  elements, a combination of mandatory and optional elements (mandatory
  always come before optionals in the structure), or nothing (null message)

  An optional element in a message is preceded by a uint8_t value that must be
  set to true if the element is going to be included. When decoding a received
  message, the uint8_t values will be set to true or false by the decode
  routine, and should be checked before accessing the values that they
  correspond to.

  Variable sized arrays are defined as static sized arrays with an unsigned
  integer (32 bit) preceding it that must be set to the number of elements
  in the array that are valid. For Example:

  uint32_t test_opaque_len;
  uint8_t test_opaque[16];

  If only 4 elements are added to test_opaque[] then test_opaque_len must be
  set to 4 before sending the message.  When decoding, the _len value is set
  by the decode routine and should be checked so that the correct number of
  elements in the array will be accessed.

*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  

  
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.7 
   It was generated on: Wed Jun 17 2020 (Spin 0)
   From IDL File: quec_common_qmi_v01.idl */

/** @defgroup quec_common_qmi_qmi_consts Constant values defined in the IDL */
/** @defgroup quec_common_qmi_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup quec_common_qmi_qmi_enums Enumerated types used in QMI messages */
/** @defgroup quec_common_qmi_qmi_messages Structures sent as QMI messages */
/** @defgroup quec_common_qmi_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup quec_common_qmi_qmi_accessor Accessor for QMI service object */
/** @defgroup quec_common_qmi_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup quec_common_qmi_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define QUEC_COMMON_QMI_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define QUEC_COMMON_QMI_V01_IDL_MINOR_VERS 0x01
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define QUEC_COMMON_QMI_V01_IDL_TOOL_VERS 0x06
/** Maximum Defined Message ID */
#define QUEC_COMMON_QMI_V01_MAX_MESSAGE_ID 0x0039
/**
    @}
  */


/** @addtogroup quec_common_qmi_qmi_consts
    @{
  */

/**     */
#define QUEC_COMMON_QMI_SERVICE_V01 227

/**  Maximum size of the ecall urc event */
#define QUEC_COMMON_MAX_ECALL_URC_EVENT_LENGTH_V01 128

/**  Maximum nv item name length. */
#define QUEC_COMMON_MAX_NV_ITME_NAME_LENGTH_V01 127

/**  Maximun mv item value length. */
#define QUEC_COMMON_MAX_NV_ITME_VALUE_LENGTH_V01 4096
#define QUEC_COMMON_MAX_WEA_ALERT_LENGTH_V01 512
#define QUEC_COMMON_MAX_ETWS_ALERT_LENGTH_V01 256
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_RESULT_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUEC_RESULT_SUCCESS_V01 = 0, /**<  Success. */
  QUEC_RESULT_FAILURE_V01 = 1, /**<  Failure. */
  QUEC_RESULT_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_result_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_ERROR_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUEC_SUCCESS_V01 = 0, /**<  Success. */
  QUEC_SUCCESS_CONDITIONAL_SUCCESS_V01 = 1, /**<  Conditional success. */
  QUEC_ERROR_QUEC_SERVICES_NOT_AVAILABLE_V01 = 2, /**<  QUEC services not available. */
  QUEC_ERROR_GENERIC_V01 = 3, /**<  Generic error. */
  QUEC_ERROR_BADPARM_V01 = 4, /**<  Bad parameter. */
  QUEC_ERROR_MEMORY_V01 = 5, /**<  Memory error. */
  QUEC_ERROR_INVALID_STATE_V01 = 6, /**<  Invalid state. */
  QUEC_ERROR_MALFORMED_MSG_V01 = 7, /**<  Malformed message. */
  QUEC_ERROR_NO_MEMORY_V01 = 8, /**<  No memory. */
  QUEC_ERROR_INTERNAL_V01 = 9, /**<  Internal error. */
  QUEC_ERROR_ABORTED_V01 = 10, /**<  Action was aborted. */
  QUEC_ERROR_CLIENT_IDS_EXHAUSTED_V01 = 11, /**<  Client IDs have been exhausted. */
  QUEC_ERROR_UNABORTABLE_TRANSACTION_V01 = 12, /**<  Unabortable transaction. */
  QUEC_ERROR_INVALID_CLIENT_ID_V01 = 13, /**<  Invalid client ID. */
  QUEC_ERROR_NO_THRESHOLDS_V01 = 14, /**<  No thresholds.  */
  QUEC_ERROR_NV_NO_FILE_V01 = 15, /**<  NV file not exist. */
  QUEC_ERROR_NV_FS_NOT_SUPPORTED_V01 = 16, /**<  NV file system not supported. */
  QUEC_ERROR_NV_BAD_SIZE_V01 = 17, /**<  NV bad buffer size. */
  QUEC_ERROR_NV_BAD_BUF_V01 = 18, /**<  NV buffer is NULL. */
  QUEC_ERROR_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_error_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_LED_FUNC_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUEC_LED_FUNC_0_V01 = 0, /**<  net status. */
  QUEC_LED_FUNC_1_V01 = 1, /**<  net mode. */
  QUEC_LED_FUNC_2_V01 = 2, /**<  airplane mode. */
  QUEC_LED_FUNC_3_V01 = 3, /**<  CV2X. */
  QUEC_LED_FUNC_4_V01 = 4, /**<  GNSS. */
  QUEC_LED_FUNC_5_V01 = 5, /**<  reserved. */
  QUEC_LED_FUNC_6_V01 = 6, /**<  reserved. */
  QUEC_LED_FUNC_7_V01 = 7, /**<  reserved. */
  QUEC_LED_FUNC_8_V01 = 8, /**<  reserved. */
  QUEC_LED_FUNC_9_V01 = 9, /**<  reserved. */
  QUEC_LED_FUNC_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_led_func_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_LED_STATUS_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUECTEL_GPIO_STATUS_LOW_V01 = 0, 
  QUECTEL_GPIO_STATUS_HIGH_V01 = 1, 
  QUECTEL_GPIO_STATUS_FLICKER_V01 = 2, 
  QUECTEL_GPIO_STATUS_MAX_V01 = 3, 
  QUEC_LED_STATUS_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_led_status_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_VOICE_ECALL_STATE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUEC_VOICE_ECALL_INACTIVE_V01 = 0, 
  QUEC_VOICE_ECALL_ORIGINATING_CALL_V01 = 1, 
  QUEC_VOICE_ECALL_IN_CALL_TRANSMITTING_V01 = 2, /**<  ECALL APP TRANSMITTING */
  QUEC_VOICE_ECALL_WATING_FOR_AL_ACK_V01 = 3, 
  QUEC_VOICE_ECALL_IN_CALL_V01 = 4, 
  QUEC_VOICE_ECALL_IDLE_ALLOW_MT_ECALL_V01 = 5, 
  QUEC_VOICE_ECALL_STATE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_voice_ecall_state_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_DM_QOOS_ENABLE_TYPE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUEC_DM_QOOS_ENABLE_STATE_OFF_V01 = 0, /**<   close QOOS function.  */
  QUEC_DM_QOOS_ENABLE_STATE_ON_NO_SERVICE_V01 = 1, /**<   open QOOS function in no service state.  */
  QUEC_DM_QOOS_ENABLE_STATE_ON_V01 = 2, /**<   open QOOS function in no and limited service state.  */
  QUEC_DM_QOOS_ENABLE_TYPE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_dm_qoos_enable_type_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_DM_QOOS_DATA_TYPE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUEC_DM_QOOS_DATA_TYPE_ENABLE_STATE_V01 = 0, /**<   QOOS enable state  */
  QUEC_DM_QOOS_DATA_TYPE_CONFIG_V01 = 1, /**<   QOOS configuration  */
  QUEC_DM_QOOS_DATA_TYPE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_dm_qoos_data_type_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  quec_result_t_v01 result;
  /**<   Result code:
                            - QUEC_RESULT_SUCCESS
                            - QUEC_RESULT_FAILURE
                          */

  quec_error_t_v01 error;
  /**<   Error code. Possible error code values are
                            described in the error codes section of each
                            message definition.
                          */
}quec_response_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t msk;

  uint8_t xtra_enable;

  uint8_t port;

  uint8_t nmea_src;

  uint8_t auto_gps;

  uint16_t gnss_config;

  uint8_t dpo_enable;
}gps_cfg_s_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t srv_system_type;

  uint32_t pdp_type;

  uint32_t reserved;

  uint8_t apn[100];
}agps_lbs_apn_s_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t appid_name_id[16];

  uint8_t appid_name_pwd[16];

  uint8_t appid_provider[25];
}agps_appidname_s_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t msk;

  uint8_t plane;

  uint32_t agps_pos_mode;

  agps_lbs_apn_s_type_v01 lbs_apn;

  agps_appidname_s_type_v01 appid_name;

  uint32_t agnss_protocol;
}agps_cfg_s_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t msk;
}quec_common_get_agps_cfg_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result;

  /* Mandatory */
  agps_cfg_s_type_v01 agps_cfg;
}quec_common_get_agps_cfg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  agps_cfg_s_type_v01 agps_cfg;
}quec_common_set_agps_cfg_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result;
}quec_common_set_agps_cfg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_comm_at_cmd_mode_change_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t cmd_mode;
}quec_comm_at_cmd_mode_change_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t cmd_mode;
}quec_comm_at_cmd_mode_change_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_comm_usb_escape_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_comm_usb_escape_resp_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_comm_net_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_comm_net_status_resp_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t on_time;

  /* Mandatory */
  int32_t off_time;
}quec_comm_net_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t country;

  /* Mandatory */
  uint32_t tone;
}quec_comm_tone_event_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  char file_name[256];

  /* Mandatory */
  int32_t open_flag;
}quec_comm_efs_file_open_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result;

  /* Mandatory */
  int32_t file_handle;
}quec_comm_efs_file_open_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  char file_name[256];
}quec_comm_efs_file_size_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result;

  /* Mandatory */
  uint32_t file_size;
}quec_comm_efs_file_size_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t file_handle;

  /* Mandatory */
  uint32_t read_len;
}quec_comm_efs_file_read_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result;

  /* Mandatory */
  uint8_t data[1024];

  /* Mandatory */
  uint32_t actual_read_len;
}quec_comm_efs_file_read_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t file_handle;

  /* Mandatory */
  uint8_t data[1024];

  /* Mandatory */
  uint32_t write_len;
}quec_comm_efs_file_write_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result;

  /* Mandatory */
  uint32_t actual_write_len;
}quec_comm_efs_file_write_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t file_handle;
}quec_comm_efs_file_close_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result;
}quec_comm_efs_file_close_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  char file_name[256];
}quec_comm_efs_file_delete_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result;
}quec_comm_efs_file_delete_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t file_handle;

  /* Mandatory */
  int32_t offset;

  /* Mandatory */
  int32_t whence;
}quec_comm_efs_file_seek_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result;
}quec_comm_efs_file_seek_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t msg_len;

  /* Mandatory */
  uint8_t msg_data[512];
}quec_comm_wap_sms_fwd_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t enable_fwd;
}quec_comm_wap_sms_fwd_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result;
}quec_comm_wap_sms_fwd_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_comm_uart1_dtr_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int8_t dtr_level;
}quec_comm_uart1_dtr_resq_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int8_t dtr_level;
}quec_comm_uart1_dtr_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_comm_get_gps_cfg_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result;

  /* Mandatory */
  gps_cfg_s_type_v01 gps_cfg;
}quec_comm_get_gps_cfg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  gps_cfg_s_type_v01 gps_cfg;
}quec_comm_set_gps_cfg_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result;
}quec_comm_set_gps_cfg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  char ap_version[128];
}quec_common_qmi_sync_ap_version_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t result_flag;
}quec_common_qmi_sync_ap_version_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t modem_rdy;
}quec_common_qmi_get_modem_rdy_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t modem_rdy;
}quec_common_qmi_get_modem_rdy_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t modem_rdy;
}quec_common_qmi_get_modem_rdy_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_usb_id_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t pid;

  /* Mandatory */
  uint32_t vid;
}quec_common_qmi_get_usb_id_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t pid;

  /* Mandatory */
  uint32_t vid;
}quec_common_qmi_get_usb_id_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_des_gain_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t value;
}quec_common_qmi_get_des_gain_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t value;
}quec_common_qmi_get_des_gain_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_5616_power_ctl_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t value;
}quec_common_qmi_get_5616_power_ctl_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t value;
}quec_common_qmi_get_5616_power_ctl_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_audio_mod_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t value;
}quec_common_qmi_get_audio_mod_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t value;
}quec_common_qmi_get_audio_mod_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t gpio;

  uint32_t status;

  uint32_t on_time;

  uint32_t off_time;
}gpio_on_off_status_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_VOICE_ECALL_MODE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUEC_VOICE_ECALL_MODE_NOMAL_V01 = 0, 
  QUEC_VOICE_ECALL_MODE_ONLY_V01 = 1, 
  QUEC_VOICE_ECALL_MODE_DEFAULT_V01 = 2, /**<  ECALL APP TRANSMITTING */
  QUEC_VOICE_ECALL_MODE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_voice_ecall_mode_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t enable;

  /*  Enable or disable ecall 
 0 -- Disable; 1 -- Enable */
  uint8_t voiceconfig;

  /*  Enable or disable to mute IVS speaker in MSD
 0 -- Disable to mute IVS speaker automatical in MSD transmission
 1 -- Enable to mute IVS speaker automatical in MSD transmission */
  quec_voice_ecall_mode_t_v01 ecallmode;

  /*  The Ecall mode. */
  uint8_t processinfo;

  /*  Enable or disable to report ecall event info.
 0 -- Disable; 1 -- Enable */
  uint16_t T5;

  /*  The timer of IVS waiting for "START". */
  uint16_t T6;

  /*  The timer of IVS waiting for "HACK". */
  uint16_t T7;

  /*  The timer of MSD transmission. */
  uint8_t mofailredial;

  /*  The dial fail times. */
  uint8_t dropredial;

  /*  The ecall abnormal disconnenct redial times. */
  uint16_t T2;

  /*  The timer of IVS waiting for "ClearDown". */
  uint16_t T3;

  /*  The timer of IVS waiting for "InitIATION". */
  uint16_t T9;

  /*  The timer of IVS waiting for "NAD Registration". */
  uint16_t T10;

  /*  The timer of IVS waiting for "NAD Deregistration". */
  uint8_t ecall_system;

  /*  The ecall system: eu or era_glonass. */
  uint16_t era_glonass_redial_time_s;

  /*  The timer of IVS waiting ecall redial for era_glonass. */
  uint16_t era_glonass_auto_answer_time_s;
}quec_voice_ecall_config_info_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_VOICE_ECALL_EVENT_FAIL_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUEC_VOICE_ECALL_EVENT_FAIL_START_TIMEOUT_V01 = 1, /**<  Wait for START timeout. */
  QUEC_VOICE_ECALL_EVENT_FAIL_HACK_TIMEOUT_V01 = 2, /**<  Wait for HACK timeout.	 */
  QUEC_VOICE_ECALL_EVENT_FAIL_MSD_TRANSMISSION_TIMEOUT_V01 = 3, /**<  MSD transmission timeout.	 */
  QUEC_VOICE_ECALL_EVENT_FAIL_IVS_RESET_TIMEOUT_V01 = 4, /**<  IVS reset. */
  QUEC_VOICE_ECALL_EVENT_CLEAR_DOWN_FALLBACK_TIMEOUT_V01 = 5, /**<  IVS clear down fallback timeout.  */
  QUEC_VOICE_ECALL_EVENT_IVS_INITIATION_TIMEOUT_V01 = 6, /**<  IVS initiation timeout.  */
  QUEC_VOICE_ECALL_EVENT_FAIL_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_voice_ecall_event_fail_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_VOICE_ECALL_EVENT_PROCESS_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUEC_VOICE_ECALL_EVENT_PROCESS_IVS_START_RECEIVED_MSD_V01 = 1, /**<  IVS Link Layer receives START message and starts to send MSD. */
  QUEC_VOICE_ECALL_EVENT_PROCESS_IVS_NACK_RECEIVED_V01 = 2, /**<  IVS Link Layer receives NACK message. */
  QUEC_VOICE_ECALL_EVENT_PROCESS_IVS_ACK_RECEIVED_V01 = 3, /**<  IVS Link Layer receives the first LACK message. */
  QUEC_VOICE_ECALL_EVENT_PROCESS_IVS_TX_COMPLETED_V01 = 4, /**<  IVS MSD transmission is complete. */
  QUEC_VOICE_ECALL_EVENT_PROCESS_IVS_HLACK_RECEIVED_V01 = 5, /**<  IVS Link Layer receives first HACK message. */
  QUEC_VOICE_ECALL_EVENT_PROCESS_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_voice_ecall_event_process_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_VOICE_ECALL_EVENT_MSDUPADTE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUEC_VOICE_ECALL_EVENT_MSDUPDATE_IVS_UPDATING_MSD_V01 = 0, /**<  Indicates MSD has been updated. */
  QUEC_VOICE_ECALL_EVENT_MSDUPDATE_PSAP_REQURE_UPDATE_MSD_V01 = 1, /**<  Indicate to update MSD in 5 seconds. */
  QUEC_VOICE_ECALL_EVENT_MSDUPDATE_IVS_UPDATE_MSD_TIMEOUT_V01 = 2, /**<  Indicate timeout of updating MSD and module starts to transfer the old MSD. */
  QUEC_VOICE_ECALL_EVENT_MSDUPADTE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_voice_ecall_event_msdupadte_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_VOICE_ECALL_EVENT_ESTABLISH_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUEC_VOICE_ECALL_EVENT_ECALL_ESTABLISHNG_SUCCESS_V01 = 0, /**<  Establish eCall successfully. */
  QUEC_VOICE_ECALL_EVENT_ECALL_ESTABLISHNG_FAIL_V01 = 1, /**<  Establish eCall fails. */
  QUEC_VOICE_ECALL_EVENT_ESTABLISH_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_voice_ecall_event_establish_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_enums
    @{
  */
typedef enum {
  QUEC_VOICE_ECALL_EVENT_EXTEND_STATE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QUEC_VOICE_ECALL_EVENT_START_RECEIVED_SYNCHRONIZATION_V01 = 0, /**<  Ecall start received synchronization. */
  QUEC_VOICE_ECALL_EVENT_T9_TIMEOUT_V01 = 1, /**<  eCall T9 timeout. */
  QUEC_VOICE_ECALL_EVENT_T10_TIMEOUT_V01 = 2, /**<  eCall T10 timeout. */
  QUEC_VOICE_ECALL_EVENT_IVS_ALACK_RECEIVED_V01 = 3, /**<  eCall IVS ALACK RECEIVED. */
  QUEC_VOICE_ECALL_EVENT_IVS_LLACK_RECEIVED_V01 = 4, /**<  eCall IVS LLACK RECEIVED. */
  QUEC_VOICE_ECALL_EVENT_ECALL_STOPPED_V01 = 5, /**<  eCall IVS STOPPED ECALL. */
  QUEC_VOICE_ECALL_EVENT_ANSWERING_INCOMING_PSAP_ECALL_V01 = 6, /**<  eCall IVS AUTO ANSWERING INCOMING PSAP ECALL */
  QUEC_VOICE_ECALL_EVENT_CLEAR_DOWN_RECEIVED_V01 = 7, /**<  eCall IVS CLEARDOWN RECEIVED. */
  QUEC_VOICE_ECALL_EVENT_EXTEND_STATE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}quec_voice_ecall_event_extend_state_t_v01;
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t hack_code;
  /**<  psap hack code*/
}quec_voice_ecall_event_hackcode_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t ori_remainder_times;
  /**<   originate fail remainder times*/

  uint16_t time;
  /**<   the minimum time duration between the previous call attempt*/
}quec_voice_ecall_event_originate_fail_and_redial_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t drop_remainder_times;
  /**<   dorp remainder times*/

  uint16_t time;
  /**<   the minimum time duration between the previous call attempt*/
}quec_voice_ecall_event_drop_and_redial_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t large_item_pool_size;
  /**<   size of large item pool.*/

  uint32_t large_item_pool_used;
  /**<   large item pool count.*/

  uint32_t large_item_pool_free;
  /**<   large item pool count.*/

  uint32_t small_item_pool_size;
  /**<   size of small item pool.*/

  uint32_t small_item_pool_used;
  /**<   small item pool count.*/

  uint32_t small_item_pool_free;
  /**<   small item pool count.*/

  uint32_t dup_item_pool_size;
  /**<   size of dup item pool.*/

  uint32_t dup_item_pool_used;
  /**<   dup item pool count.*/

  uint32_t dup_item_pool_free;
  /**<   dup item pool count.*/
}quec_modem_mem_pool_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t Presidential_alert;
  /**<    Enable or disable Presidential_alert: 0 -- Disable; 1 -- Enable */

  uint8_t Extreme_alert;
  /**<    Enable or disable Extreme_alert: 0 -- Disable; 1 -- Enable */

  uint8_t Servere_alert;
  /**<    Enable or disable Servere_alert: 0 -- Disable; 1 -- Enable */

  uint8_t Amber_alert;
  /**<    Enable or disable Amber_alert: 0 -- Disable; 1 -- Enable */

  uint8_t PublicSafety_alert;
  /**<    Enable or disable PublicSafety_alert: 0 -- Disable; 1 -- Enable */

  uint8_t StateLocalTest_alert;
  /**<    Enable or disable StateLocalTest_alert: 0 -- Disable; 1 -- Enable */

  uint8_t RMT_alert;
  /**<    Enable or disable RMT_alert: 0 -- Disable; 1 -- Enable */

  uint8_t Exercise_alert;
  /**<    Enable or disable Exercise_alert: 0 -- Disable; 1 -- Enable */

  uint8_t CMSPDefined_alert;
  /**<    Enable or disable CMSPDefined_alert: 0 -- Disable; 1 -- Enable */

  uint8_t Spanish_alert;
  /**<    Enable or disable Spanish_alert: 0 -- Disable; 1 -- Enable */
}quec_common_wea_config_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t pre_time;

  uint16_t sleep_time;

  uint16_t acq_time;

  uint8_t cir_cnt;

  uint8_t sleep_step;

  uint8_t acq_step;

  uint8_t adj_cnt;

  uint8_t idle_interval;
}quec_common_qmi_qoos_config_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_gpio_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  gpio_on_off_status_v01 gpio_status;
}quec_common_qmi_get_gpio_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t led_func;

  /* Mandatory */
  gpio_on_off_status_v01 gpio_status;
}quec_common_qmi_get_gpio_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_usb_early_enable_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t enable;
}quec_common_qmi_get_usb_early_enable_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t enable;
}quec_common_qmi_get_usb_early_enable_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_usb_function_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t function_mask;
}quec_common_qmi_get_usb_function_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t function_mask;
}quec_common_qmi_get_usb_function_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_sclk_value_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t sclk_value;
}quec_common_qmi_get_sclk_value_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t sclk_value;
}quec_common_qmi_get_sclk_value_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_usb_net_value_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t usbnet_value;
}quec_common_qmi_get_usb_net_value_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t usbnet_value;
}quec_common_qmi_get_usb_net_value_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t timer_id;
}quec_common_qmi_register_timer_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t result;
}quec_common_qmi_register_timer_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t timer_id;

  /* Mandatory */
  uint32_t interval;

  /* Mandatory */
  uint32_t auto_repeat;
}quec_common_qmi_start_timer_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t result;
}quec_common_qmi_start_timer_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t timer_id;
}quec_common_qmi_stop_timer_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t result;
}quec_common_qmi_stop_timer_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t timer_id;
}quec_common_qmi_timer_expire_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t forbid_ind;
}quec_common_qmi_forbid_ind_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t result;
}quec_common_qmi_forbid_ind_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t thermal_limit_rates_flag;
}quec_common_qmi_get_thermal_limit_rates_flag_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t thermal_limit_rates_flag;
}quec_common_qmi_get_thermal_limit_rates_flag_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t thermal_limit_rates_flag;
}quec_common_qmi_get_thermal_limit_rates_flag_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_wificfg_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t mac[6];
}quec_common_qmi_wificfg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t mac[6];
}quec_common_qmi_wificfg_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t call_id;
}quec_common_qmi_ecall_hangup_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
}quec_common_qmi_ecall_hangup_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Optional */
  uint8_t enable_valid;  /**< Must be set to true if enable is being passed */
  uint8_t enable;

  /* Optional */
  /*  Enable or disable ecall 
 0 -- Disable; 1 -- Enable */
  uint8_t voiceconfig_valid;  /**< Must be set to true if voiceconfig is being passed */
  uint8_t voiceconfig;

  /* Optional */
  /*  Enable or disable to mute IVS speaker in MSD
 0 -- Disable to mute IVS speaker automatical in MSD transmission
 1 -- Enable to mute IVS speaker automatical in MSD transmission */
  uint8_t ecallmode_valid;  /**< Must be set to true if ecallmode is being passed */
  quec_voice_ecall_mode_t_v01 ecallmode;

  /* Optional */
  /*  The Ecall mode. */
  uint8_t processinfo_valid;  /**< Must be set to true if processinfo is being passed */
  uint8_t processinfo;

  /* Optional */
  /*  Enable or disable to report ecall event info.
 0 -- Disable; 1 -- Enable */
  uint8_t T5_valid;  /**< Must be set to true if T5 is being passed */
  uint16_t T5;

  /* Optional */
  /*  The timer of IVS waiting for "START". */
  uint8_t T6_valid;  /**< Must be set to true if T6 is being passed */
  uint16_t T6;

  /* Optional */
  /*  The timer of IVS waiting for "HACK". */
  uint8_t T7_valid;  /**< Must be set to true if T7 is being passed */
  uint16_t T7;

  /* Optional */
  /*  The timer of MSD transmission. */
  uint8_t mofailredial_valid;  /**< Must be set to true if mofailredial is being passed */
  uint8_t mofailredial;

  /* Optional */
  /*  The dial fail times. */
  uint8_t dropredial_valid;  /**< Must be set to true if dropredial is being passed */
  uint8_t dropredial;

  /* Optional */
  /*  The ecall abnormal disconnenct redial times. */
  uint8_t T2_valid;  /**< Must be set to true if T2 is being passed */
  uint16_t T2;

  /* Optional */
  /*  The timer of IVS waiting for "ClearDown". */
  uint8_t T3_valid;  /**< Must be set to true if T3 is being passed */
  uint16_t T3;

  /* Optional */
  /*  The timer of IVS waiting for "InitIATION". */
  uint8_t T9_valid;  /**< Must be set to true if T9 is being passed */
  uint16_t T9;

  /* Optional */
  /*  The timer of IVS waiting for "NAD Registration". */
  uint8_t T10_valid;  /**< Must be set to true if T10 is being passed */
  uint16_t T10;

  /* Optional */
  /*  The timer of IVS waiting for "NAD Deregistration". */
  uint8_t ecall_system_valid;  /**< Must be set to true if ecall_system is being passed */
  uint8_t ecall_system;

  /* Optional */
  /*  The ecall system: eu or era_glonass.
 0 -- eu; 1 -- era_glonass */
  uint8_t era_glonass_redial_time_s_valid;  /**< Must be set to true if era_glonass_redial_time_s is being passed */
  uint16_t era_glonass_redial_time_s;

  /* Optional */
  /*  The timer of IVS waiting ecall redial for era_glonass. */
  uint8_t era_glonass_auto_answer_time_s_valid;  /**< Must be set to true if era_glonass_auto_answer_time_s is being passed */
  uint16_t era_glonass_auto_answer_time_s;
}quec_common_qmi_set_ecall_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
}quec_common_qmi_set_ecall_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_ecall_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;

  /* Mandatory */
  quec_voice_ecall_config_info_t_v01 ecall_config;
}quec_common_qmi_get_ecall_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_ecall_command_push_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;

  /* Optional */
  uint8_t ecall_state_valid;  /**< Must be set to true if ecall_state is being passed */
  quec_voice_ecall_state_t_v01 ecall_state;
}quec_common_qmi_ecall_command_push_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t call_id;
  /**<  call_id.*/

  /* Mandatory */
  uint32_t ecall_urc_event_len;  /**< Must be set to # of elements in ecall_urc_event */
  char ecall_urc_event[QUEC_COMMON_MAX_ECALL_URC_EVENT_LENGTH_V01];
}quec_common_qmi_ecall_urc_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Optional */
  uint8_t ecall_event_fails_valid;  /**< Must be set to true if ecall_event_fails is being passed */
  quec_voice_ecall_event_fail_t_v01 ecall_event_fails;

  /* Optional */
  /*  event of eCall Failed. */
  uint8_t ecall_event_process_valid;  /**< Must be set to true if ecall_event_process is being passed */
  quec_voice_ecall_event_process_t_v01 ecall_event_process;

  /* Optional */
  /*  event of eCall process */
  uint8_t ecall_event_msdupdate_valid;  /**< Must be set to true if ecall_event_msdupdate is being passed */
  quec_voice_ecall_event_msdupadte_t_v01 ecall_event_msdupdate;

  /* Optional */
  /*  event of ecall msd update. */
  uint8_t ecall_event_establish_valid;  /**< Must be set to true if ecall_event_establish is being passed */
  quec_voice_ecall_event_establish_t_v01 ecall_event_establish;

  /* Optional */
  /*  event of eCall establish */
  uint8_t ecall_event_hackcode_valid;  /**< Must be set to true if ecall_event_hackcode is being passed */
  quec_voice_ecall_event_hackcode_t_v01 ecall_event_hackcode;

  /* Optional */
  /*  event of eCall hack code */
  uint8_t ecall_event_ori_redial_valid;  /**< Must be set to true if ecall_event_ori_redial is being passed */
  quec_voice_ecall_event_originate_fail_and_redial_t_v01 ecall_event_ori_redial;
  /**<   event of originate fail and redial.*/

  /* Optional */
  uint8_t ecall_event_drop_redial_valid;  /**< Must be set to true if ecall_event_drop_redial is being passed */
  quec_voice_ecall_event_drop_and_redial_t_v01 ecall_event_drop_redial;
  /**<   event of drop and redial.*/

  /* Optional */
  uint8_t ecall_event_extend_state_valid;  /**< Must be set to true if ecall_event_extend_state is being passed */
  quec_voice_ecall_event_extend_state_t_v01 ecall_event_extend_state;
  /**<   event of eCall extend.*/
}quec_common_qmi_ecall_event_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Optional */
  uint8_t ecall_urc_valid;  /**< Must be set to true if ecall_urc is being passed */
  uint8_t ecall_urc;

  /* Optional */
  /*  Enable or disable ecall_urc  */
  uint8_t ecall_event_valid;  /**< Must be set to true if ecall_event is being passed */
  uint8_t ecall_event;

  /* Optional */
  /*  Enable or disable ecall_event  */
  uint8_t modem_info_valid;  /**< Must be set to true if modem_info is being passed */
  uint8_t modem_info;

  /* Optional */
  /*  Enable or disable modem_cpu_info  */
  uint8_t wea_info_valid;  /**< Must be set to true if wea_info is being passed */
  uint8_t wea_info;

  /* Optional */
  /*  Enable or disable wea_info  */
  uint8_t etws_info_valid;  /**< Must be set to true if etws_info is being passed */
  uint8_t etws_info;
}quec_common_qmi_event_register_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
}quec_common_qmi_event_register_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t modem_cpu_utilization;

  /* Mandatory */
  /*  event of eCall Failed. */
  quec_modem_mem_pool_t_v01 modem_mem_pool;
}quec_common_qmi_modem_info_event_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  char nv_item_name[QUEC_COMMON_MAX_NV_ITME_NAME_LENGTH_V01 + 1];
}quec_common_qmi_get_nv_item_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;

  /* Optional */
  /*  Result code. */
  uint8_t nv_item_value_valid;  /**< Must be set to true if nv_item_value is being passed */
  uint32_t nv_item_value_len;  /**< Must be set to # of elements in nv_item_value */
  uint8_t nv_item_value[QUEC_COMMON_MAX_NV_ITME_VALUE_LENGTH_V01];
}quec_common_qmi_get_nv_item_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  char nv_item_name[QUEC_COMMON_MAX_NV_ITME_NAME_LENGTH_V01 + 1];

  /* Mandatory */
  /*  NV item name. */
  uint32_t nv_item_value_len;  /**< Must be set to # of elements in nv_item_value */
  uint8_t nv_item_value[QUEC_COMMON_MAX_NV_ITME_VALUE_LENGTH_V01];
}quec_common_qmi_set_nv_item_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
  /**<   Result code*/

  /* Mandatory */
  uint32_t nv_item_value_len;
}quec_common_qmi_set_nv_item_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_set_radio_on_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
  /**<   Result code*/
}quec_common_qmi_set_radio_on_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_set_radio_off_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
  /**<   Result code*/
}quec_common_qmi_set_radio_off_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_modem_cpu_utilization_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
  /**<   Result code*/

  /* Mandatory */
  uint32_t modem_cpu_utilization;
}quec_common_qmi_get_modem_cpu_utilization_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_modem_mem_utilization_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
  /**<   Result code*/

  /* Mandatory */
  float modem_mem_utilization;
}quec_common_qmi_get_modem_mem_utilization_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Optional */
  uint8_t Presidential_alert_valid;  /**< Must be set to true if Presidential_alert is being passed */
  uint8_t Presidential_alert;
  /**<    Enable or disable Presidential_alert: 0 -- Disable; 1 -- Enable */

  /* Optional */
  uint8_t Extreme_alert_valid;  /**< Must be set to true if Extreme_alert is being passed */
  uint8_t Extreme_alert;
  /**<    Enable or disable Extreme_alert: 0 -- Disable; 1 -- Enable */

  /* Optional */
  uint8_t Servere_alert_valid;  /**< Must be set to true if Servere_alert is being passed */
  uint8_t Servere_alert;
  /**<    Enable or disable Servere_alert: 0 -- Disable; 1 -- Enable */

  /* Optional */
  uint8_t Amber_alert_valid;  /**< Must be set to true if Amber_alert is being passed */
  uint8_t Amber_alert;
  /**<    Enable or disable Amber_alert: 0 -- Disable; 1 -- Enable */

  /* Optional */
  uint8_t PublicSafety_alert_valid;  /**< Must be set to true if PublicSafety_alert is being passed */
  uint8_t PublicSafety_alert;
  /**<    Enable or disable PublicSafety_alert: 0 -- Disable; 1 -- Enable */

  /* Optional */
  uint8_t StateLocalTest_alert_valid;  /**< Must be set to true if StateLocalTest_alert is being passed */
  uint8_t StateLocalTest_alert;
  /**<    Enable or disable StateLocalTest_alert: 0 -- Disable; 1 -- Enable */

  /* Optional */
  uint8_t RMT_alert_valid;  /**< Must be set to true if RMT_alert is being passed */
  uint8_t RMT_alert;
  /**<    Enable or disable RMT_alert: 0 -- Disable; 1 -- Enable */

  /* Optional */
  uint8_t Exercise_alert_valid;  /**< Must be set to true if Exercise_alert is being passed */
  uint8_t Exercise_alert;
  /**<    Enable or disable Exercise_alert: 0 -- Disable; 1 -- Enable */

  /* Optional */
  uint8_t CMSPDefined_alert_valid;  /**< Must be set to true if CMSPDefined_alert is being passed */
  uint8_t CMSPDefined_alert;
  /**<    Enable or disable CMSPDefined_alert: 0 -- Disable; 1 -- Enable */

  /* Optional */
  uint8_t Spanish_alert_valid;  /**< Must be set to true if Spanish_alert is being passed */
  uint8_t Spanish_alert;
  /**<    Enable or disable Spanish_alert: 0 -- Disable; 1 -- Enable */
}quec_common_qmi_set_wea_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
  /**<   Result code*/
}quec_common_qmi_set_wea_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_wea_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
  /**<   Result code*/

  /* Mandatory */
  quec_common_wea_config_t_v01 wea_config;
}quec_common_qmi_get_wea_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t wea_alert_len;  /**< Must be set to # of elements in wea_alert */
  char wea_alert[QUEC_COMMON_MAX_WEA_ALERT_LENGTH_V01];
}quec_common_qmi_wea_alert_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t etws_alert;
  /**<    Enable or disable etws_alert: 0 -- Disable; 1 -- Enable */
}quec_common_qmi_set_etws_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
  /**<   Result code*/
}quec_common_qmi_set_etws_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}quec_common_qmi_get_etws_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
  /**<   Result code*/

  /* Mandatory */
  uint8_t etws_config;
}quec_common_qmi_get_etws_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t etws_primary_alert_len;  /**< Must be set to # of elements in etws_primary_alert */
  char etws_primary_alert[QUEC_COMMON_MAX_ETWS_ALERT_LENGTH_V01];

  /* Mandatory */
  uint32_t etws_secondary_alert_len;  /**< Must be set to # of elements in etws_secondary_alert */
  char etws_secondary_alert[QUEC_COMMON_MAX_ETWS_ALERT_LENGTH_V01];
}quec_common_qmi_etws_alert_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_dm_qoos_data_type_t_v01 type;
}quec_common_qmi_get_qoos_param_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;

  /* Optional */
  uint8_t enable_valid;  /**< Must be set to true if enable is being passed */
  quec_dm_qoos_enable_type_t_v01 enable;

  /* Optional */
  uint8_t config_valid;  /**< Must be set to true if config is being passed */
  quec_common_qmi_qoos_config_t_v01 config;
}quec_common_qmi_get_qoos_param_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Optional */
  uint8_t enable_valid;  /**< Must be set to true if enable is being passed */
  quec_dm_qoos_enable_type_t_v01 enable;

  /* Optional */
  uint8_t config_valid;  /**< Must be set to true if config is being passed */
  quec_common_qmi_qoos_config_t_v01 config;
}quec_common_qmi_set_qoos_param_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup quec_common_qmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  quec_response_t_v01 resp;
}quec_common_qmi_set_qoos_param_resp_msg_v01;  /* Message */
/**
    @}
  */

/* Conditional compilation tags for message removal */ 

/*Service Message Definition*/
/** @addtogroup quec_common_qmi_qmi_msg_ids
    @{
  */
#define QMI_COMM_QMI_GET_USB_ID_REQ_V01 0x0001
#define QMI_COMM_QMI_GET_USB_ID_RESP_V01 0x0001
#define QMI_COMM_QMI_GET_USB_ID_IND_V01 0x0001
#define QMI_COMM_QMI_GET_DES_GAIN_REQ_V01 0x0002
#define QMI_COMM_QMI_GET_DES_GAIN_RESP_V01 0x0002
#define QMI_COMM_QMI_GET_DES_GAIN_IND_V01 0x0002
#define QMI_COMM_QMI_GET_5616_POWER_CTL_REQ_V01 0x0003
#define QMI_COMM_QMI_GET_5616_POWER_CTL_RESP_V01 0x0003
#define QMI_COMM_QMI_GET_5616_POWER_CTL_IND_V01 0x0003
#define QMI_COMM_QMI_GET_AUDIO_MOD_REQ_V01 0x0004
#define QMI_COMM_QMI_GET_AUDIO_MOD_RESP_V01 0x0004
#define QMI_COMM_QMI_GET_AUDIO_MOD_IND_V01 0x0004
#define QMI_COMM_QMI_GET_GPIO_STATUS_REQ_V01 0x0005
#define QMI_COMM_QMI_GET_GPIO_STATUS_RESP_V01 0x0005
#define QMI_COMM_QMI_GET_GPIO_STATUS_IND_V01 0x0005
#define QMI_COMM_QMI_GET_USB_EARLY_ENABLE_REQ_V01 0x0006
#define QMI_COMM_QMI_GET_USB_EARLY_ENABLE_RESP_V01 0x0006
#define QMI_COMM_QMI_GET_USB_EARLY_ENABLE_IND_V01 0x0006
#define QMI_COMM_QMI_GET_USB_FUNCTION_REQ_V01 0x0007
#define QMI_COMM_QMI_GET_USB_FUNCTION_RESP_V01 0x0007
#define QMI_COMM_QMI_GET_USB_FUNCTION_IND_V01 0x0007
#define QMI_COMM_QMI_GET_SCLK_VALUE_REQ_V01 0x0008
#define QMI_COMM_QMI_GET_SCLK_VALUE_RESP_V01 0x0008
#define QMI_COMM_QMI_GET_SCLK_VALUE_IND_V01 0x0008
#define QMI_COMM_QMI_GET_USB_NET_VALUE_REQ_V01 0x0009
#define QMI_COMM_QMI_GET_USB_NET_VALUE_RESP_V01 0x0009
#define QMI_COMM_QMI_GET_USB_NET_VALUE_IND_V01 0x0009
#define QMI_COMM_QMI_REG_TIMER_REQ_V01 0x000A
#define QMI_COMM_QMI_REG_TIMER_RSP_V01 0x000A
#define QMI_COMM_QMI_START_TIMER_REQ_V01 0x000B
#define QMI_COMM_QMI_START_TIMER_RSP_V01 0x000B
#define QMI_COMM_QMI_STOP_TIMER_REQ_V01 0x000C
#define QMI_COMM_QMI_STOP_TIMER_RSP_V01 0x000C
#define QMI_COMM_QMI_TIMER_EXP_IND_V01 0x000D
#define QMI_COMM_QMI_FORBID_IND_REQ_V01 0x000E
#define QMI_COMM_QMI_FORBID_IND_RESP_V01 0x000E
#define QMI_COMM_QMI_GET_THERMAL_LIMIT_RATES_FLAG_REQ_V01 0x000F
#define QMI_COMM_QMI_GET_THERMAL_LIMIT_RATES_FLAG_RESP_V01 0x000F
#define QMI_COMM_QMI_GET_THERMAL_LIMIT_RATES_FLAG_IND_V01 0x000F
#define QMI_COMM_QMI_WIFICFG_REQ_V01 0x0010
#define QMI_COMM_QMI_WIFICFG_RESP_V01 0x0010
#define QMI_COMM_QMI_WIFICFG_IND_V01 0x0010
#define QUEC_COMMON_QMI_ECALL_HANGUP_REQ_V01 0x0011
#define QUEC_COMMON_QMI_ECALL_HANGUP_RESP_V01 0x0011
#define QUEC_COMMON_QMI_SET_ECALL_CONFIG_REQ_V01 0x0012
#define QUEC_COMMON_QMI_SET_ECALL_CONFIG_RESP_V01 0x0012
#define QUEC_COMMON_QMI_GET_ECALL_CONFIG_REQ_V01 0x0013
#define QUEC_COMMON_QMI_GET_ECALL_CONFIG_RESP_V01 0x0013
#define QUEC_COMMON_QMI_ECALL_COMMAND_PUSH_REQ_V01 0x0014
#define QUEC_COMMON_QMI_ECALL_COMMAND_PUSH_RESP_V01 0x0014
#define QUEC_COMMON_QMI_ECALL_URC_IND_V01 0x0015
#define QUEC_COMMON_QMI_ECALL_EVENT_IND_V01 0x0016
#define QUEC_COMMON_QMI_EVENT_REGISTER_REQ_V01 0x0017
#define QUEC_COMMON_QMI_EVENT_REGISTER_RESP_V01 0x0017
#define QUEC_COMMON_QMI_MODEM_INFO_EVENT_IND_V01 0x0018
#define QUEC_COMMON_QMI_GET_NV_ITEM_REQ_V01 0x0019
#define QUEC_COMMON_QMI_GET_NV_ITEM_RESP_V01 0x0019
#define QUEC_COMMON_QMI_SET_NV_ITEM_REQ_V01 0x001A
#define QUEC_COMMON_QMI_SET_NV_ITEM_RESP_V01 0x001A
#define QUEC_COMMON_QMI_SET_RADIO_ON_REQ_V01 0x001B
#define QUEC_COMMON_QMI_SET_RADIO_ON_RESP_V01 0x001B
#define QUEC_COMMON_QMI_SET_RADIO_OFF_REQ_V01 0x001C
#define QUEC_COMMON_QMI_SET_RADIO_OFF_RESP_V01 0x001C
#define QMI_QUEC_COMM_AT_CMD_MODE_CHANGE_REQ_V01 0x001D
#define QMI_QUEC_COMM_AT_CMD_MODE_CHANGE_RSP_V01 0x001D
#define QMI_QUEC_COMM_AT_CMD_MODE_CHANGE_IND_V01 0x001D
#define QMI_QUEC_COMM_USB_ESCAPE_REQ_V01 0x001E
#define QMI_QUEC_COMM_USB_ESCAPE_RSP_V01 0x001E
#define QMI_QUEC_COMM_NET_STATUS_REQ_V01 0x001F
#define QMI_QUEC_COMM_NET_STATUS_RSP_V01 0x001F
#define QMI_QUEC_COMM_NET_STATUS_IND_V01 0x001F
#define QMI_QUEC_COMM_TONE_EVENT_IND_V01 0x0020
#define QMI_QUEC_COMM_EFS_FILE_OPEN_REQ_V01 0x0021
#define QMI_QUEC_COMM_EFS_FILE_OPEN_RESP_V01 0x0021
#define QMI_QUEC_COMM_EFS_FILE_SIZE_REQ_V01 0x0022
#define QMI_QUEC_COMM_EFS_FILE_SIZE_RESP_V01 0x0022
#define QMI_QUEC_COMM_EFS_FILE_READ_REQ_V01 0x0023
#define QMI_QUEC_COMM_EFS_FILE_READ_RESP_V01 0x0023
#define QMI_QUEC_COMM_EFS_FILE_WRITE_REQ_V01 0x0024
#define QMI_QUEC_COMM_EFS_FILE_WRITE_RESP_V01 0x0024
#define QMI_QUEC_COMM_EFS_FILE_CLOSE_REQ_V01 0x0025
#define QMI_QUEC_COMM_EFS_FILE_CLOSE_RESP_V01 0x0025
#define QMI_QUEC_COMM_EFS_FILE_DELETE_REQ_V01 0x0026
#define QMI_QUEC_COMM_EFS_FILE_DELETE_RESP_V01 0x0026
#define QMI_QUEC_COMM_EFS_FILE_SEEK_REQ_V01 0x0027
#define QMI_QUEC_COMM_EFS_FILE_SEEK_RESP_V01 0x0027
#define QMI_QUEC_COMM_WAP_SMS_FWD_REQ_V01 0x0028
#define QMI_QUEC_COMM_WAP_SMS_FWD_RESP_V01 0x0028
#define QMI_QUEC_COMM_WAP_SMS_FWD_IND_V01 0x0028
#define QMI_QUEC_COMM_UART1_DTR_REQ_V01 0x0029
#define QMI_QUEC_COMM_UART1_DTR_RESP_V01 0x0029
#define QMI_QUEC_COMM_UART1_DTR_IND_V01 0x0029
#define QMI_QUEC_COMM_GET_GPS_CFG_REQ_V01 0x002A
#define QMI_QUEC_COMM_GET_GPS_CFG_RESP_V01 0x002A
#define QMI_QUEC_COMM_SET_GPS_CFG_REQ_V01 0x002B
#define QMI_QUEC_COMM_SET_GPS_CFG_RESP_V01 0x002B
#define QMI_QUEC_COMM_GET_AGPS_REQ_V01 0x002C
#define QMI_QUEC_COMM_GET_AGPS_RESP_V01 0x002C
#define QMI_QUEC_COMM_SET_AGPS_REQ_V01 0x002D
#define QMI_QUEC_COMM_SET_AGPS_RESP_V01 0x002D
#define QMI_COMM_QMI_SYNC_AP_VERSION_REQ_V01 0x002E
#define QMI_COMM_QMI_SYNC_AP_VERSION_RESP_V01 0x002E
#define QMI_COMM_QMI_GET_MODEM_RDY_REQ_V01 0x002F
#define QMI_COMM_QMI_GET_MODEM_RDY_RESP_V01 0x002F
#define QMI_COMM_QMI_GET_MODEM_RDY_IND_V01 0x002F
#define QMI_COMM_QMI_GET_MODEM_CPU_UTILIZATION_REQ_V01 0x0030
#define QMI_COMM_QMI_GET_MODEM_CPU_UTILIZATION_RESP_V01 0x0030
#define QMI_COMM_QMI_GET_MODEM_MEM_UTILIZATION_REQ_V01 0x0031
#define QMI_COMM_QMI_GET_MODEM_MEM_UTILIZATION_RESP_V01 0x0031
#define QUEC_COMM_QMI_SET_WEA_CONFIG_REQ_V01 0x0032
#define QUEC_COMM_QMI_SET_WEA_CONFIG_RESP_V01 0x0032
#define QUEC_COMM_QMI_GET_WEA_CONFIG_REQ_V01 0x0033
#define QUEC_COMM_QMI_GET_WEA_CONFIG_RESP_V01 0x0033
#define QUEC_COMM_QMI_WEA_ALERT_IND_V01 0x0034
#define QUEC_COMM_QMI_SET_ETWS_CONFIG_REQ_V01 0x0035
#define QUEC_COMM_QMI_SET_ETWS_CONFIG_RESP_V01 0x0035
#define QUEC_COMM_QMI_GET_ETWS_CONFIG_REQ_V01 0x0036
#define QUEC_COMM_QMI_GET_ETWS_CONFIG_RESP_V01 0x0036
#define QUEC_COMM_QMI_ETWS_ALERT_IND_V01 0x0037
#define QUEC_COMMON_QMI_GET_QOOS_PARAM_REQ_V01 0x0038
#define QUEC_COMMON_QMI_GET_QOOS_PARAM_RESP_V01 0x0038
#define QUEC_COMMON_QMI_SET_QOOS_PARAM_REQ_V01 0x0039
#define QUEC_COMMON_QMI_SET_QOOS_PARAM_RESP_V01 0x0039
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro quec_common_qmi_get_service_object_v01( ) that takes in no arguments. */
qmi_idl_service_object_type quec_common_qmi_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );

/** This macro should be used to get the service object */
#define quec_common_qmi_get_service_object_v01( ) \
          quec_common_qmi_get_service_object_internal_v01( \
            QUEC_COMMON_QMI_V01_IDL_MAJOR_VERS, QUEC_COMMON_QMI_V01_IDL_MINOR_VERS, \
            QUEC_COMMON_QMI_V01_IDL_TOOL_VERS )
/**
    @}
  */


#ifdef __cplusplus
}
#endif
#endif

