#ifndef MCM_DM_SERVICE_01_H
#define MCM_DM_SERVICE_01_H
/**
  @file mcm_dm_v01.h

  @brief This is the public header file which defines the mcm_dm service Data structures.

  This header file defines the types and structures that were defined in
  mcm_dm. It contains the constant values defined, enums, structures,
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
   From IDL File: mcm_dm_v01.idl */

/** @defgroup mcm_dm_qmi_consts Constant values defined in the IDL */
/** @defgroup mcm_dm_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup mcm_dm_qmi_enums Enumerated types used in QMI messages */
/** @defgroup mcm_dm_qmi_messages Structures sent as QMI messages */
/** @defgroup mcm_dm_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup mcm_dm_qmi_accessor Accessor for QMI service object */
/** @defgroup mcm_dm_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "mcm_common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup mcm_dm_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define MCM_DM_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define MCM_DM_V01_IDL_MINOR_VERS 0x01
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define MCM_DM_V01_IDL_TOOL_VERS 0x06

/**
    @}
  */


/** @addtogroup mcm_dm_qmi_consts
    @{
  */

/**  Max array limit */
#define MCM_MAX_ARRAY_LIMIT_V01 252

/**  Max array limit */
#define MCM_MAX_DMS_IMEI_V01 32

/**  Max array limit  */
#define MCM_MAX_DMS_MEID_V01 32

/**  Max device rev id limit  */
#define MCM_MAX_DEVICE_REV_ID_V01 256

/**  Maximum nv item name length. */
#define MCM_MAX_DMS_NV_ITME_NAME_V01 127

/**  Maximun mv item value length. */
#define MCM_MAX_DMS_NV_ITME_VALUE_V01 4096
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_enums
    @{
  */
typedef enum {
  MCM_DM_RADIO_MODE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  MCM_DM_RADIO_MODE_OFFLINE_V01 = 0x0001, /**<  Radio power off or unknown. */
  MCM_DM_RADIO_MODE_ONLINE_V01 = 0x0002, /**<  Radio online. */
  MCM_DM_RADIO_MODE_UNAVAILABLE_V01 = 0x0003, /**<  Radio unvailable. */
  MCM_DM_RADIO_MODE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}mcm_dm_radio_mode_t_v01;
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_enums
    @{
  */
typedef enum {
  MCM_DM_QOOS_ENABLE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  MCM_DM_QOOS_ENABLE_STATE_OFF_V01 = 0, /**<   close QOOS function.  */
  MCM_DM_QOOS_ENABLE_STATE_ON_NO_SERVICE_V01 = 1, /**<   open QOOS function in no service state.  */
  MCM_DM_QOOS_ENABLE_STATE_ON_V01 = 2, /**<   open QOOS function in no and limited service state.  */
  MCM_DM_QOOS_ENABLE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}mcm_dm_qoos_enable_t_v01;
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_enums
    @{
  */
typedef enum {
  MCM_DM_QOOS_DATA_TYPE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  MCM_DM_QOOS_DATA_TYPE_ENABLE_STATE_V01 = 0, /**<   QOOS enable state.  */
  MCM_DM_QOOS_DATA_TYPE_CONFIG_V01 = 1, /**<   QOOS configuration.  */
  MCM_DM_QOOS_DATA_TYPE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}mcm_dm_qoos_data_type_t_v01;
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_aggregates
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
}mcm_dm_qoos_config_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Gets the radio mode of the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_dm_get_radio_mode_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Gets the radio mode of the device. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;

  /* Optional */
  uint8_t radio_mode_valid;  /**< Must be set to true if radio_mode is being passed */
  mcm_dm_radio_mode_t_v01 radio_mode;
  /**<   Current radio power level; must
 be one of the modes in
 mcm_dm_radio_mode_t_v01.*/
}mcm_dm_get_radio_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Sets the device radio mode. */
typedef struct {

  /* Mandatory */
  mcm_dm_radio_mode_t_v01 radio_mode;
  /**<   Radio power level to set.*/
}mcm_dm_set_radio_mode_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Sets the device radio mode. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Optional */
  uint8_t no_change_valid;  /**< Must be set to true if no_change is being passed */
  uint8_t no_change;
  /**<   No change.*/
}mcm_dm_set_radio_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Gets the device serial numbers. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_dm_get_device_serial_numbers_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Gets the device serial numbers. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Optional */
  uint8_t imei_valid;  /**< Must be set to true if imei is being passed */
  char imei[MCM_MAX_DMS_IMEI_V01 + 1];
  /**<   imei.*/

  /* Optional */
  uint8_t meid_valid;  /**< Must be set to true if meid is being passed */
  char meid[MCM_MAX_DMS_MEID_V01 + 1];
  /**<   meid.*/
}mcm_dm_get_device_serial_numbers_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Gets the device firmware revision identification. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_dm_get_device_rev_id_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Gets the device firmware revision identification. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Mandatory */
  char device_rev_id[MCM_MAX_DEVICE_REV_ID_V01 + 1];
  /**<   device rev id.*/
}mcm_dm_get_device_rev_id_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Gets the value of nv item */
typedef struct {

  /* Mandatory */
  char nv_item_name[MCM_MAX_DMS_NV_ITME_NAME_V01 + 1];
  /**<   NV item name*/
}mcm_dm_get_nv_item_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Gets the value of nv item */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Optional */
  uint8_t nv_item_value_valid;  /**< Must be set to true if nv_item_value is being passed */
  uint32_t nv_item_value_len;  /**< Must be set to # of elements in nv_item_value */
  uint8_t nv_item_value[MCM_MAX_DMS_NV_ITME_VALUE_V01];
  /**<   NV item value.*/
}mcm_dm_get_nv_item_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Sets the value of nv item */
typedef struct {

  /* Mandatory */
  char nv_item_name[MCM_MAX_DMS_NV_ITME_NAME_V01 + 1];
  /**<   NV item name.*/

  /* Mandatory */
  uint32_t nv_item_value_len;  /**< Must be set to # of elements in nv_item_value */
  uint8_t nv_item_value[MCM_MAX_DMS_NV_ITME_VALUE_V01];
  /**<   NV item value.*/
}mcm_dm_set_nv_item_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Sets the value of nv item */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Mandatory */
  uint32_t nv_item_value_len;
}mcm_dm_set_nv_item_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Sets radio on */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_dm_set_radio_on_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Sets radio on */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/
}mcm_dm_set_radio_on_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Sets the radio off */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_dm_set_radio_off_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Sets the radio off */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/
}mcm_dm_set_radio_off_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Gets the configuration status for qoos. */
typedef struct {

  /* Mandatory */
  mcm_dm_qoos_data_type_t_v01 type;
}mcm_dm_get_qoos_param_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Gets the configuration status for qoos. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Optional */
  uint8_t enable_valid;  /**< Must be set to true if enable is being passed */
  mcm_dm_qoos_enable_t_v01 enable;

  /* Optional */
  uint8_t config_valid;  /**< Must be set to true if config is being passed */
  mcm_dm_qoos_config_t_v01 config;
}mcm_dm_get_qoos_param_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Set the Configures status of qoos. */
typedef struct {

  /* Optional */
  uint8_t enable_valid;  /**< Must be set to true if enable is being passed */
  mcm_dm_qoos_enable_t_v01 enable;

  /* Optional */
  uint8_t config_valid;  /**< Must be set to true if config is being passed */
  mcm_dm_qoos_config_t_v01 config;
}mcm_dm_set_qoos_param_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Set the Configures status of qoos. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/
}mcm_dm_set_qoos_param_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Registers for an indication of events. */
typedef struct {

  /* Optional */
  uint8_t register_radio_mode_changed_event_valid;  /**< Must be set to true if register_radio_mode_changed_event is being passed */
  uint8_t register_radio_mode_changed_event;
  /**<   Radio mode changed event.*/
}mcm_dm_event_register_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Registers for an indication of events. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/
}mcm_dm_event_register_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Indication Message; Indication when the radio mode is changed. */
typedef struct {

  /* Optional */
  uint8_t radio_mode_valid;  /**< Must be set to true if radio_mode is being passed */
  mcm_dm_radio_mode_t_v01 radio_mode;
}mcm_dm_radio_mode_changed_event_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Get modem info */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_dm_get_modem_cpu_utilization_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Get modem info */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Mandatory */
  float cpu_utilization;
}mcm_dm_get_modem_cpu_utilization_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Request Message; Get modem info */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_dm_get_modem_mem_utilization_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_dm_qmi_messages
    @{
  */
/** Response Message; Get modem info */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Mandatory */
  float mem_utilization;
}mcm_dm_get_modem_mem_utilization_resp_msg_v01;  /* Message */
/**
    @}
  */
/** @addtogroup mcm_dm_service_msg_ids
    @{
  */
#define MCM_DM_GET_RADIO_MODE_REQ_V01 0x0201
#define MCM_DM_GET_RADIO_MODE_RESP_V01 0x0201
#define MCM_DM_SET_RADIO_MODE_REQ_V01 0x0202
#define MCM_DM_SET_RADIO_MODE_RESP_V01 0x0202
#define MCM_DM_EVENT_REGISTER_REQ_V01 0x0203
#define MCM_DM_EVENT_REGISTER_RESP_V01 0x0203
#define MCM_DM_RADIO_MODE_CHANGED_EVENT_IND_V01 0x0204
//Laurence.yin-2018/04/20-QCM9XOL00004C015-P01, <[DM] : define imei meid message id.>
#define MCM_DM_GET_DEVICE_SERIAL_NUMBERS_REQ_V01 0x02A0
#define MCM_DM_GET_DEVICE_SERIAL_NUMBERS_RESP_V01 0x02A0
#define MCM_DM_GET_DEVICE_REV_ID_REQ_V01 0x02A1
#define MCM_DM_GET_DEVICE_REV_ID_RESP_V01 0x02A1
#define MCM_DM_GET_NV_ITEM_REQ_V01 0x02A2
#define MCM_DM_GET_NV_ITEM_RESP_V01 0x02A2
#define MCM_DM_SET_NV_ITEM_REQ_V01 0x02A3
#define MCM_DM_SET_NV_ITEM_RESP_V01 0x02A3
#define MCM_DM_SET_RADIO_ON_REQ_V01 0x02A4
#define MCM_DM_SET_RADIO_ON_RESP_V01 0x02A4
#define MCM_DM_SET_RADIO_OFF_REQ_V01 0x02A5
#define MCM_DM_SET_RADIO_OFF_RESP_V01 0x02A5
//added by rambo at 2020/05/13 for get mdemo utilization info
#define MCM_DM_GET_MODEM_CPU_UTILIZATION_REQ_V01 0x02A6
#define MCM_DM_GET_MODEM_CPU_UTILIZATION_RESP_V01 0x02A6
#define MCM_DM_GET_MODEM_MEM_UTILIZATION_REQ_V01 0x02A7
#define MCM_DM_GET_MODEM_MEM_UTILIZATION_RESP_V01 0x02A7
#define MCM_DM_GET_QOOS_PARAM_REQ_V01 0x02A8
#define MCM_DM_GET_QOOS_PARAM_RESP_V01 0x02A8
#define MCM_DM_SET_QOOS_PARAM_REQ_V01 0x02A9
#define MCM_DM_SET_QOOS_PARAM_RESP_V01 0x02A9

/**
 @}
 */

#ifdef __cplusplus
}
#endif
#endif

