#ifndef MCM_NW_SERVICE_01_H
#define MCM_NW_SERVICE_01_H
/**
  @file mcm_nw_v01.h

  @brief This is the public header file which defines the mcm_nw service Data structures.

  This header file defines the types and structures that were defined in
  mcm_nw. It contains the constant values defined, enums, structures,
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
   It was generated on: Sat May 16 2020 (Spin 0)
   From IDL File: mcm_nw_v01.idl */

/** @defgroup mcm_nw_qmi_consts Constant values defined in the IDL */
/** @defgroup mcm_nw_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup mcm_nw_qmi_enums Enumerated types used in QMI messages */
/** @defgroup mcm_nw_qmi_messages Structures sent as QMI messages */
/** @defgroup mcm_nw_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup mcm_nw_qmi_accessor Accessor for QMI service object */
/** @defgroup mcm_nw_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "mcm_common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup mcm_nw_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define MCM_NW_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define MCM_NW_V01_IDL_MINOR_VERS 0x01
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define MCM_NW_V01_IDL_TOOL_VERS 0x06

/**
    @}
  */


/** @addtogroup mcm_nw_qmi_consts
    @{
  */
#define MCM_NW_SCAN_LIST_MAX_V01 40
#define MCM_NW_NITZ_STR_BUF_MAX_V01 30

/**  Maximum cells in cell info response.  */
#define MCM_CELL_INFO_GSM_MAX_V01 20
#define MCM_CELL_INFO_UMTS_MAX_V01 20
#define MCM_CELL_INFO_LTE_MAX_V01 20
#define MCM_MAX_WEA_ALERT_LENGTH_V01 512
#define MCM_MAX_ETWS_ALERT_LENGTH_V01 256
/**
    @}
  */

typedef uint64_t mcm_nw_mode_type_v01;
#define MCM_MODE_NONE_V01 ((mcm_nw_mode_type_v01)0x00ull) /**<  No network. */
#define MCM_MODE_GSM_V01 ((mcm_nw_mode_type_v01)0x01ull) /**<  Include GSM networks. */
#define MCM_MODE_WCDMA_V01 ((mcm_nw_mode_type_v01)0x02ull) /**<  Include WCDMA networks. */
#define MCM_MODE_CDMA_V01 ((mcm_nw_mode_type_v01)0x04ull) /**<  Include CDMA networks. */
#define MCM_MODE_EVDO_V01 ((mcm_nw_mode_type_v01)0x08ull) /**<  Include EVDO networks. */
#define MCM_MODE_LTE_V01 ((mcm_nw_mode_type_v01)0x10ull) /**<  Include LTE networks. */
#define MCM_MODE_TDSCDMA_V01 ((mcm_nw_mode_type_v01)0x20ull) /**<  Include TDSCDMA networks. */
#define MCM_MODE_PRL_V01 ((mcm_nw_mode_type_v01)0x10000ull) /**<  Give preference according to the preferred
 roaming list. */
/** @addtogroup mcm_nw_qmi_enums
    @{
  */
typedef enum {
  MCM_NW_SERVICE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  MCM_NW_SERVICE_NONE_V01 = 0x0000, /**<  Not registered or no data. */
  MCM_NW_SERVICE_LIMITED_V01 = 0x0001, /**<  Registered; emergency service only. */
  MCM_NW_SERVICE_FULL_V01 = 0x0002, /**<  Registered, full service. */
  MCM_NW_SERVICE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}mcm_nw_service_t_v01;
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_enums
    @{
  */
typedef enum {
  MCM_NW_SELECTION_TYPE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  MCM_NW_SELECTION_AUTOMATIC_V01 = 0x0000, /**<  Automatic network selection. */
  MCM_NW_SELECTION_MANUAL_V01 = 0x0001, /**<  Manual network selection. */
  MCM_NW_SELECTION_TYPE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}mcm_nw_selection_type_t_v01;
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_enums
    @{
  */
typedef enum {
  MCM_NW_NETWORK_STATUS_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  MCM_NW_NETWORK_STATUS_NONE_V01 = 0x0000, /**<  Network status not available. */
  MCM_NW_NETWORK_STATUS_CURRENT_SERVING_V01 = 0x0001, /**<  Current serving network. */
  MCM_NW_NETWORK_STATUS_PREFERRED_V01 = 0x0002, /**<  Preferred network */
  MCM_NW_NETWORK_STATUS_NOT_PREFERRED_V01 = 0x0003, /**<  Not the preferred network */
  MCM_NW_NETWORK_STATUS_AVAILABLE_V01 = 0x0004, /**<  Service available. */
  MCM_NW_NETWORK_STATUS_FORBIDDEN_V01 = 0x0005, /**<  Forbidden service. */
  MCM_NW_NETWORK_STATUS_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}mcm_nw_network_status_t_v01;
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_enums
    @{
  */
typedef enum {
  MCM_NW_RADIO_TECH_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  MCM_NW_RADIO_TECH_TD_SCDMA_V01 = 1, /**<  TDSCDMA. */
  MCM_NW_RADIO_TECH_GSM_V01 = 2, /**<  GSM; only supports voice. */
  MCM_NW_RADIO_TECH_HSPAP_V01 = 3, /**<  HSPA+. */
  MCM_NW_RADIO_TECH_LTE_V01 = 4, /**<  LTE. */
  MCM_NW_RADIO_TECH_EHRPD_V01 = 5, /**<  EHRPD. */
  MCM_NW_RADIO_TECH_EVDO_B_V01 = 6, /**<  EVDO B. */
  MCM_NW_RADIO_TECH_HSPA_V01 = 7, /**<  HSPA. */
  MCM_NW_RADIO_TECH_HSUPA_V01 = 8, /**<  HSUPA. */
  MCM_NW_RADIO_TECH_HSDPA_V01 = 9, /**<  HSDPA. */
  MCM_NW_RADIO_TECH_EVDO_A_V01 = 10, /**<  EVDO A. */
  MCM_NW_RADIO_TECH_EVDO_0_V01 = 11, /**<  EVDO 0. */
  MCM_NW_RADIO_TECH_1xRTT_V01 = 12, /**<  1xRTT. */
  MCM_NW_RADIO_TECH_IS95B_V01 = 13, /**<  IS95B. */
  MCM_NW_RADIO_TECH_IS95A_V01 = 14, /**<  IS95A. */
  MCM_NW_RADIO_TECH_UMTS_V01 = 15, /**<  UMTS. */
  MCM_NW_RADIO_TECH_EDGE_V01 = 16, /**<  EDGE. */
  MCM_NW_RADIO_TECH_GPRS_V01 = 17, /**<  GPRS. */
  MCM_NW_RADIO_TECH_NONE_V01 = 18, /**<  No technology. */
  MCM_NW_RADIO_TECH_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}mcm_nw_radio_tech_t_v01;
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_enums
    @{
  */
typedef enum {
  MCM_NW_CELL_ACCESS_STATE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  MCM_NW_CELL_ACCESS_NONE_V01 = 0x00, /**<  Unknown cell access state. */
  MCM_NW_CELL_ACCESS_NORMAL_ONLY_V01 = 0x01, /**<  Cell access is allowed for normal calls only. */
  MCM_NW_CELL_ACCESS_EMERGENCY_ONLY_V01 = 0x02, /**<  Cell access is allowed for emergency calls only. */
  MCM_NW_CELL_ACCESS_NO_CALLS_V01 = 0x03, /**<  Cell access is not allowed for any call type. */
  MCM_NW_CELL_ACCESS_ALL_CALLS_V01 = 0x04, /**<  Cell access is allowed for all call types. */
  MCM_NW_CELL_ACCESS_STATE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}mcm_nw_cell_access_state_t_v01;
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_enums
    @{
  */
typedef enum {
  MCM_NW_ROAM_STATE_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  MCM_NW_ROAM_STATE_OFF_V01 = 0, /**<  None, or roaming indicator off. */
  MCM_NW_ROAM_STATE_ON_V01 = 1, /**<  Roaming indicator on. */
  MCM_NW_ROAM_STATE_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}mcm_nw_roam_state_t_v01;
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_enums
    @{
  */
typedef enum {
  MCM_NW_TECH_DOMAIN_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  MCM_NW_TECH_DOMAIN_NONE_V01 = 0, /**<  None. */
  MCM_NW_TECH_DOMAIN_3GPP_V01 = 1, /**<  3GPP. */
  MCM_NW_TECH_DOMAIN_3GPP2_V01 = 2, /**<  3GPP2. */
  MCM_NW_TECH_DOMAIN_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}mcm_nw_tech_domain_t_v01;
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_enums
    @{
  */
typedef enum {
  MCM_NW_DENY_REASON_T_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  MCM_NW_IMSI_UNKNOWN_HLR_DENY_REASON_V01 = 1, /**<  IMSI unknown in HLR */
  MCM_NW_ILLEGAL_MS_DENY_REASON_V01 = 2, /**<  Illegal MS */
  MCM_NW_IMSI_UNKNOWN_VLR_DENY_REASON_V01 = 3, /**<  IMSI unknown in VLR */
  MCM_NW_IMEI_NOT_ACCEPTED_DENY_REASON_V01 = 4, /**<  IMSI not accepted */
  MCM_NW_ILLEGAL_ME_DENY_REASON_V01 = 5, /**<  Illegal ME */
  MCM_NW_PLMN_NOT_ALLOWED_DENY_REASON_V01 = 6, /**<  PLMN not allowed */
  MCM_NW_LA_NOT_ALLOWED_DENY_REASON_V01 = 7, /**<  Location area not allowed */
  MCM_NW_ROAMING_NOT_ALLOWED_LA_DENY_REASON_V01 = 8, /**<  Roaming not allowed in this location area */
  MCM_NW_NO_SUITABLE_CELLS_LA_DENY_REASON_V01 = 9, /**<  No suitable cells in location area */
  MCM_NW_NETWORK_FAILURE_DENY_REASON_V01 = 10, /**<  Network failure */
  MCM_NW_MAC_FAILURE_DENY_REASON_V01 = 11, /**<  MAC failure */
  MCM_NW_SYNCH_FAILURE_DENY_REASON_V01 = 12, /**<  Sync failure */
  MCM_NW_CONGESTION_DENY_REASON_V01 = 13, /**<  Congestion */
  MCM_NW_GSM_AUTHENTICATION_UNACCEPTABLE_DENY_REASON_V01 = 14, /**<  GSM authentication unacceptable */
  MCM_NW_NOT_AUTHORIZED_CSG_DENY_REASON_V01 = 15, /**<  Not autherized in this CSG */
  MCM_NW_SERVICE_OPTION_NOT_SUPPORTED_DENY_REASON_V01 = 16, /**<  Service option not supported */
  MCM_NW_REQ_SERVICE_OPTION_NOT_SUBSCRIBED_DENY_REASON_V01 = 17, /**<  Requested service option not subscribed */
  MCM_NW_CALL_CANNOT_BE_IDENTIFIED_DENY_REASON_V01 = 18, /**<  Call cannot be identified */
  MCM_NW_SEMANTICALLY_INCORRECT_MSG_DENY_REASON_V01 = 19, /**<  Semantically incorrect message */
  MCM_NW_INVALID_MANDATORY_INFO_DENY_REASON_V01 = 20, /**<  Invalid mandatory information */
  MCM_NW_MSG_TYPE_NON_EXISTENT_DENY_REASON_V01 = 21, /**<  Message type non-existent or not implemented */
  MCM_NW_INFO_ELEMENT_NON_EXISTENT_DENY_REASON_V01 = 22, /**<  Message type not compatible with the protocol state */
  MCM_NW_CONDITIONAL_IE_ERR_DENY_REASON_V01 = 23, /**<  Conditional IE error */
  MCM_NW_MSG_INCOMPATIBLE_PROTOCOL_STATE_DENY_REASON_V01 = 24, /**<  Message not compatible with the protocol state */
  MCM_NW_PROTOCOL_ERROR_DENY_REASON_V01 = 25, /**<  Protocol error, unspecified */
  MCM_NW_DENY_REASON_T_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}mcm_nw_deny_reason_t_v01;
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  char long_eons[512 + 1];
  /**<   Long EONS.*/

  char short_eons[512 + 1];
  /**<   Short EONS.*/

  char mcc[3 + 1];
  /**<   Mobile country code.*/

  char mnc[3 + 1];
  /**<   Mobile network code.*/
}mcm_nw_operator_name_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  mcm_nw_operator_name_t_v01 operator_name;
  /**<   Operator name.*/

  mcm_nw_network_status_t_v01 network_status;
  /**<   Network status.*/

  mcm_nw_radio_tech_t_v01 rat;
  /**<   Radio technology.*/
}mcm_nw_scan_entry_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  mcm_nw_tech_domain_t_v01 tech_domain;
  /**<   Technology, used to determine the structure type
 mcm_tech: 0 -- None, 1 -- 3GPP, 2 -- 3GPP2.*/

  mcm_nw_radio_tech_t_v01 radio_tech;
  /**<   Radio technology @ref mcm_nw_radiotech.*/

  mcm_nw_roam_state_t_v01 roaming;
  /**<   0 -- Off, 1 -- Roaming (3GPP2 has extended values).*/

  mcm_nw_deny_reason_t_v01 deny_reason;
  /**<   Set when registration state is
 @ref mcm_nw_deny_reason_t.*/

  mcm_nw_service_t_v01 registration_state;
  /**<   Registration state.*/
}mcm_nw_common_registration_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  mcm_nw_tech_domain_t_v01 tech_domain;
  /**<   Technology, used to determine the structure type
 mcm_tech: 0 -- None, 1 -- 3GPP, 2 -- 3GPP2.*/

  mcm_nw_radio_tech_t_v01 radio_tech;
  /**<   Radio technology @ref mcm_nw_radiotech.*/

  char mcc[3 + 1];
  /**<   Mobile country code.*/

  char mnc[3 + 1];
  /**<   Mobile network code.*/

  mcm_nw_roam_state_t_v01 roaming;
  /**<   0 -- Off, 1 -- Roaming (3GPP2 has extended values).*/

  uint8_t forbidden;
  /**<   Forbidden: 0 -- No, 1 -- Yes.*/

  uint32_t cid;
  /**<   Cell id for the registered 3GPP system.*/

  uint16_t lac;
  /**<   Locatin area code for the registered 3GPP system.*/

  uint16_t psc;
  /**<   Primary scrambling code (WCDMA only); 0 -- None.*/

  uint16_t tac;
  /**<   Tracking area code information for LTE.*/
}mcm_nw_3gpp_registration_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  mcm_nw_tech_domain_t_v01 tech_domain;
  /**<   Technology, used to determine structure type
 mcm_tech: 0 -- None, 1 -- 3GPP, 2 -- 3GPP2.*/

  mcm_nw_radio_tech_t_v01 radio_tech;
  /**<   Radio technology @ref mcm_nw_radiotech.*/

  char mcc[3 + 1];
  /**<   Mobile country code.*/

  char mnc[3 + 1];
  /**<   Mobile network code.*/

  mcm_nw_roam_state_t_v01 roaming;
  /**<   Roaming status @ref mcm_nw_roam_state.*/

  uint8_t forbidden;
  /**<   Forbidden: 0 -- No, 1 -- Yes.*/

  uint8_t inPRL;
  /**<   0 -- Not in PRL, 1 -- In PRL.*/

  uint8_t css;
  /**<   Concurrent services supported: 0 -- No, 1 -- Yes.*/

  uint16_t sid;
  /**<   CDMA system ID.*/

  uint16_t nid;
  /**<   CDMA network ID.*/

  uint16_t bsid;
  /**<   Base station ID.*/
}mcm_nw_3gpp2_registration_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  mcm_nw_selection_type_t_v01 nw_selection_type;
  /**<   Network selection type.*/

  char mcc[3 + 1];
  /**<   Mobile country code for a manual network selection.*/

  char mnc[3 + 1];
  /**<   Mobile network code for a manual network selection.*/

  mcm_nw_radio_tech_t_v01 rat;
  /**<   Radio technology.*/
}mcm_nw_selection_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t cid;
  /**<   Cell ID (0 indicates information is not present).*/

  char plmn[3];
  /**<   MCC/MNC information coded as octet 3, 4, and 5 in
 3GPP TS 24.008 Section 10.5.1.3.
 (This field should be ignored when cid is not present).*/

  uint16_t lac;
  /**<   Location area code. (This field should be ignored when cid is not present). */

  uint16_t arfcn;
  /**<   Absolute RF channel number. */

  uint8_t bsic;
  /**<   Base station identity code. (0 indicates information is not present). */

  int16_t rssi;
  /**<   Received signal strength indicator in dBm.*/
}mcm_nw_gsm_info_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t cid;
  /**<   Cell ID (0 indicates information is not present).*/

  uint32_t lcid;
  /**<   UTRAN Cell ID (0 indicates information is not present).*/

  char plmn[3];
  /**<   MCC/MNC information coded as octet 3, 4, and 5 in
 3GPP TS 24.008 Section 10.5.1.3.
 (This field should be ignored when cid is not present).*/

  uint16_t lac;
  /**<   Location area code. (This field should be ignored when cid is not present).*/

  uint16_t uarfcn;
  /**<   UTRA absolute RF channel number.*/

  uint16_t psc;
  /**<   Primary scrambling code.*/

  int16_t rssi;
  /**<   Received signal strength indicator in dBm.*/
}mcm_nw_umts_info_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t cid;
  /**<   Global cell ID in the system information block (0 indicates information is not present). */

  char plmn[3];
  /**<   MCC/MNC information coded as octet 3, 4, and 5 in
 3GPP TS 24.008 Section 10.5.1.3.
 (This field should be ignored when cid is not present.)*/

  uint16_t tac;
  /**<   Tracking area code (This field should be ignored when cid is not present). */

  uint16_t pci;
  /**<   Physical cell ID. Range: 0 to 503.*/

  uint16_t earfcn;
  /**<   E-UTRA absolute radio frequency channel number of the cell. Range: 0 to 65535.*/

  int16_t rssi;
  /**<   Received signal strength indicator in dBm.*/
}mcm_nw_lte_info_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t sid;
  /**<   System ID.*/

  uint16_t nid;
  /**<   Network ID.*/

  uint16_t bid;
  /**<   Base station ID. */

  uint16_t refpn;
  /**<   Reference PN. */

  uint32_t base_lat;
  /**<   Latitude of the current base station in units of 0.25 sec. */

  uint32_t base_long;
  /**<   Longitude of the current base station in units of 0.25 sec.*/

  int16_t rssi;
  /**<   Received signal strength indicator in dBm.*/
}mcm_nw_cdma_info_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  int8_t rssi;
  /**<   RSSI in dBm. Indicates received signal strength.
 A signed value; -125 or lower indicates no signal.*/
}mcm_nw_gsm_sig_info_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  int8_t rssi;
  /**<   RSSI in dBm. Indicates forward link pilot Ec.
 A signed value; -125 or lower indicates no signal.*/

  int16_t ecio;
  /**<   Ec/Io value representing negative 0.5 dB increments, e.g., 2 means -1 dbm.*/
}mcm_nw_wcdma_sig_info_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  int8_t rssi;
  /**<   RSSI in dBm. Indicates forward link pilot Ec.
 a signed value; -125 or lower indicates no signal.*/

  int8_t rscp;
  /**<   RSCP in dBm.*/

  int16_t ecio;
  /**<   Ec/Io value representing negative 0.5 dB increments, e.g., 2 means -1 dbm.*/

  int8_t sinr;
  /**<   Measured SINR in dB.*/
}mcm_nw_tdscdma_sig_info_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  int8_t rssi;
  /**<   RSSI in dBm. Indicates forward link pilot Ec.
 A signed value; -125 or lower indicates no signal.*/

  int8_t rsrq;
  /**<   RSRQ value in dB (signed integer value), as measured by L1.
 Range: -3 to -20 (-3 means -3 dB, -20 means -20 dB).*/

  int16_t rsrp;
  /**<   Current RSRP in dBm, as measured by L1.
 Range: -44 to -140 (-44 means -44 dBm, -140 means -140 dBm).*/

  int16_t snr;
  /**<   SNR level as a scaled integer in units of 0.1 dB;
 e.g., -16 dB has a value of -160 and 24.6 dB has a value of 246.*/
}mcm_nw_lte_sig_info_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  int8_t rssi;
  /**<   RSSI in dBm. Indicates forward link pilot Power (AGC) + Ec/Io.
 A signed value; -125 or lower indicates no signal.*/

  int16_t ecio;
  /**<   Ec/Io value representing negative 0.5 dB increments, e.g., 2 means -1 dbm.*/
}mcm_nw_cdma_sig_info_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  int8_t rssi;
  /**<   RSSI in dBm. Indicates forward link pilot Power (AGC) + Ec/Io.
 A signed value; -125 or lower indicates no signal.*/

  int16_t ecio;
  /**<   Ec/Io value representing negative 0.5 dB increments, e.g., 2 means -1 dbm.*/

  int8_t sinr;
  /**<   SINR level.*/

  int32_t io;
  /**<   Received IO in dBm.*/
}mcm_nw_hdr_sig_info_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
    @{
  */
typedef struct {

  char nitz_time[MCM_NW_NITZ_STR_BUF_MAX_V01 + 1];
  /**<   NITZ Time.*/
}mcm_nw_nitz_time_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_aggregates
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
}mcm_nw_wea_config_t_v01;  /* Type */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Configures the settings that define the MCM network interface. */
typedef struct {

  /* Optional */
  /*  Configuration parameters for MCM network registration
 Network registration details
 Technology dependent network registration details */
  uint8_t preferred_nw_mode_valid;  /**< Must be set to true if preferred_nw_mode is being passed */
  uint64_t preferred_nw_mode;
  /**<   Preferred network mode for connections;
 a bitmask of mcm_nw_mode.*/

  /* Optional */
  uint8_t roaming_pref_valid;  /**< Must be set to true if roaming_pref is being passed */
  mcm_nw_roam_state_t_v01 roaming_pref;
  /**<   Roaming preference.*/
}mcm_nw_set_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Configures the settings that define the MCM network interface. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/
}mcm_nw_set_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Gets the configuration status for this network interface. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_nw_get_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Gets the configuration status for this network interface. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Optional */
  /*  Configuration parameters for MCM network registration
 Network registration details
 Technology dependent network registration details */
  uint8_t preferred_nw_mode_valid;  /**< Must be set to true if preferred_nw_mode is being passed */
  uint64_t preferred_nw_mode;
  /**<   Preferred network mode for connections;
 a bitmask of mcm_nw_mode.*/

  /* Optional */
  uint8_t roaming_pref_valid;  /**< Must be set to true if roaming_pref is being passed */
  mcm_nw_roam_state_t_v01 roaming_pref;
  /**<   Roaming preference*/
}mcm_nw_get_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Gets the status associated with the connection of \<id\>. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_nw_get_registration_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Gets the status associated with the connection of \<id\>. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Optional */
  uint8_t voice_registration_valid;  /**< Must be set to true if voice_registration is being passed */
  mcm_nw_common_registration_t_v01 voice_registration;
  /**<   Voice registration. */

  /* Optional */
  uint8_t data_registration_valid;  /**< Must be set to true if data_registration is being passed */
  mcm_nw_common_registration_t_v01 data_registration;
  /**<   Data registration. */

  /* Optional */
  uint8_t voice_registration_details_3gpp_valid;  /**< Must be set to true if voice_registration_details_3gpp is being passed */
  mcm_nw_3gpp_registration_t_v01 voice_registration_details_3gpp;
  /**<   Voice registration details for 3GPP. */

  /* Optional */
  uint8_t data_registration_details_3gpp_valid;  /**< Must be set to true if data_registration_details_3gpp is being passed */
  mcm_nw_3gpp_registration_t_v01 data_registration_details_3gpp;
  /**<   Data registration details for 3GPP. */

  /* Optional */
  uint8_t voice_registration_details_3gpp2_valid;  /**< Must be set to true if voice_registration_details_3gpp2 is being passed */
  mcm_nw_3gpp2_registration_t_v01 voice_registration_details_3gpp2;
  /**<   Voice registration details for 3GPP2. */

  /* Optional */
  uint8_t data_registration_details_3gpp2_valid;  /**< Must be set to true if data_registration_details_3gpp2 is being passed */
  mcm_nw_3gpp2_registration_t_v01 data_registration_details_3gpp2;
  /**<   Data registration details for 3GPP2. */
}mcm_nw_get_registration_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Scanning current network. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_nw_scan_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Scanning current network. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Optional */
  uint8_t entry_valid;  /**< Must be set to true if entry is being passed */
  uint32_t entry_len;  /**< Must be set to # of elements in entry */
  mcm_nw_scan_entry_t_v01 entry[MCM_NW_SCAN_LIST_MAX_V01];
  /**<   Scan entry.*/
}mcm_nw_scan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Gets the operator name. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_nw_get_operator_name_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Gets the operator name. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Optional */
  uint8_t operator_name_valid;  /**< Must be set to true if operator_name is being passed */
  mcm_nw_operator_name_t_v01 operator_name;
  /**<   Operator name.*/
}mcm_nw_get_operator_name_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Turn the screen on/off to save the battery. */
typedef struct {

  /* Mandatory */
  uint8_t turn_off_screen;
  /**<   Turn the screen off.*/
}mcm_nw_screen_on_off_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Turn the screen on/off to save the battery. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/
}mcm_nw_screen_on_off_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Network selection (manual or automatic). */
typedef struct {

  /* Mandatory */
  mcm_nw_selection_t_v01 nw_selection_info;
  /**<   Network selection information.*/
}mcm_nw_selection_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Network selection (manual or automatic). */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/
}mcm_nw_selection_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Get signal strength information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_nw_get_signal_strength_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Get signal strength information. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Optional */
  uint8_t gsm_sig_info_valid;  /**< Must be set to true if gsm_sig_info is being passed */
  mcm_nw_gsm_sig_info_t_v01 gsm_sig_info;
  /**<   GSM signal information. */

  /* Optional */
  uint8_t wcdma_sig_info_valid;  /**< Must be set to true if wcdma_sig_info is being passed */
  mcm_nw_wcdma_sig_info_t_v01 wcdma_sig_info;
  /**<   WCDMA signal information. */

  /* Optional */
  uint8_t tdscdma_sig_info_valid;  /**< Must be set to true if tdscdma_sig_info is being passed */
  mcm_nw_tdscdma_sig_info_t_v01 tdscdma_sig_info;
  /**<   TDSCDMA signal information. */

  /* Optional */
  uint8_t lte_sig_info_valid;  /**< Must be set to true if lte_sig_info is being passed */
  mcm_nw_lte_sig_info_t_v01 lte_sig_info;
  /**<   LTE signal information. */

  /* Optional */
  uint8_t cdma_sig_info_valid;  /**< Must be set to true if cdma_sig_info is being passed */
  mcm_nw_cdma_sig_info_t_v01 cdma_sig_info;
  /**<   CDMA signal information. */

  /* Optional */
  uint8_t hdr_sig_info_valid;  /**< Must be set to true if hdr_sig_info is being passed */
  mcm_nw_hdr_sig_info_t_v01 hdr_sig_info;
  /**<   HDR signal information. */
}mcm_nw_get_signal_strength_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Get the cell access state. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_nw_get_cell_access_state_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Get the cell access state. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Optional */
  uint8_t nw_cell_access_state_valid;  /**< Must be set to true if nw_cell_access_state is being passed */
  mcm_nw_cell_access_state_t_v01 nw_cell_access_state;
  /**<   Network cell access state. */
}mcm_nw_get_cell_access_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Get NITZ Time information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_nw_get_nitz_time_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Get NITZ Time information. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Optional */
  uint8_t nw_nitz_time_valid;  /**< Must be set to true if nw_nitz_time is being passed */
  mcm_nw_nitz_time_t_v01 nw_nitz_time;

  /* Optional */
  uint8_t abs_time_valid;  /**< Must be set to true if abs_time is being passed */
  uint64_t abs_time;

  /* Optional */
  uint8_t leap_sec_valid;  /**< Must be set to true if leap_sec is being passed */
  int8_t leap_sec;
}mcm_nw_get_nitz_time_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Register for an indication of events. */
typedef struct {

  /* Optional */
  uint8_t register_voice_registration_event_valid;  /**< Must be set to true if register_voice_registration_event is being passed */
  uint8_t register_voice_registration_event;
  /**<   Register for a voice registration event. */

  /* Optional */
  uint8_t register_data_registration_event_valid;  /**< Must be set to true if register_data_registration_event is being passed */
  uint8_t register_data_registration_event;
  /**<   Register for a data registration event. */

  /* Optional */
  uint8_t register_signal_strength_event_valid;  /**< Must be set to true if register_signal_strength_event is being passed */
  uint8_t register_signal_strength_event;
  /**<   Register for a signal strength event. */

  /* Optional */
  uint8_t register_cell_access_state_change_event_valid;  /**< Must be set to true if register_cell_access_state_change_event is being passed */
  uint8_t register_cell_access_state_change_event;
  /**<   Register for a cell access state change event. */

  /* Optional */
  uint8_t register_nitz_time_update_event_valid;  /**< Must be set to true if register_nitz_time_update_event is being passed */
  uint8_t register_nitz_time_update_event;
  /**<   Register for a nitz time update event. */

  /* Optional */
  uint8_t register_wea_alert_event_valid;  /**< Must be set to true if register_wea_alert_event is being passed */
  uint8_t register_wea_alert_event;
  /**<   Register for a ewa alert event. */

  /* Optional */
  uint8_t register_etws_alert_event_valid;  /**< Must be set to true if register_etws_alert_event is being passed */
  uint8_t register_etws_alert_event;
  /**<   Register for a etws alert event. */
}mcm_nw_event_register_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Register for an indication of events. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/
}mcm_nw_event_register_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Get cell info. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_nw_get_cell_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Get cell info. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<   Result code.*/

  /* Mandatory */
  mcm_nw_radio_tech_t_v01 serving_rat;
  /**<   Serving radio access technology.
 The serving cell will be represented by the first element
 of one of the TLVs below that matches the serving rat.*/

  /* Optional */
  uint8_t gsm_info_valid;  /**< Must be set to true if gsm_info is being passed */
  uint32_t gsm_info_len;  /**< Must be set to # of elements in gsm_info */
  mcm_nw_gsm_info_t_v01 gsm_info[MCM_CELL_INFO_GSM_MAX_V01];
  /**<   GSM cell information (Serving and neighbor).*/

  /* Optional */
  uint8_t umts_info_valid;  /**< Must be set to true if umts_info is being passed */
  uint32_t umts_info_len;  /**< Must be set to # of elements in umts_info */
  mcm_nw_umts_info_t_v01 umts_info[MCM_CELL_INFO_UMTS_MAX_V01];
  /**<   UMTS cell information (Serving and neighbor).*/

  /* Optional */
  uint8_t lte_info_valid;  /**< Must be set to true if lte_info is being passed */
  uint32_t lte_info_len;  /**< Must be set to # of elements in lte_info */
  mcm_nw_lte_info_t_v01 lte_info[MCM_CELL_INFO_LTE_MAX_V01];
  /**<   LTE cell information (Serving and neighbor).*/

  /* Optional */
  uint8_t cdma_info_valid;  /**< Must be set to true if cdma_info is being passed */
  mcm_nw_cdma_info_t_v01 cdma_info;
  /**<   CDMA cell information (Serving and neighbor).*/
}mcm_nw_get_cell_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Indication Message; Indication for the corresponding registered event
	       MCM_NW_VOICE_REGISTRATION_EV. */
typedef struct {

  /* Optional */
  uint8_t voice_registration_valid;  /**< Must be set to true if voice_registration is being passed */
  mcm_nw_common_registration_t_v01 voice_registration;
  /**<   Voice registration. */

  /* Optional */
  uint8_t voice_registration_details_3gpp_valid;  /**< Must be set to true if voice_registration_details_3gpp is being passed */
  mcm_nw_3gpp_registration_t_v01 voice_registration_details_3gpp;
  /**<   Voice registration details for 3GPP. */

  /* Optional */
  uint8_t voice_registration_details_3gpp2_valid;  /**< Must be set to true if voice_registration_details_3gpp2 is being passed */
  mcm_nw_3gpp2_registration_t_v01 voice_registration_details_3gpp2;
  /**<   Voice registration details for 3GPP2. */
}mcm_nw_voice_registration_event_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Indication Message; Indication for the corresponding registered event
	       MCM_NW_DATA_REGISTRATION_EV. */
typedef struct {

  /* Optional */
  uint8_t data_registration_valid;  /**< Must be set to true if data_registration is being passed */
  mcm_nw_common_registration_t_v01 data_registration;
  /**<   Data registration. */

  /* Optional */
  uint8_t data_registration_details_3gpp_valid;  /**< Must be set to true if data_registration_details_3gpp is being passed */
  mcm_nw_3gpp_registration_t_v01 data_registration_details_3gpp;
  /**<   Data registration details for 3GPP. */

  /* Optional */
  uint8_t data_registration_details_3gpp2_valid;  /**< Must be set to true if data_registration_details_3gpp2 is being passed */
  mcm_nw_3gpp2_registration_t_v01 data_registration_details_3gpp2;
  /**<   Data registration details for 3GPP2. */
}mcm_nw_data_registration_event_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Indication Message; Indication for the corresponding registered event
	       MCM_NW_SIGNAL_STRENGTH_EV. */
typedef struct {

  /* Optional */
  uint8_t gsm_sig_info_valid;  /**< Must be set to true if gsm_sig_info is being passed */
  mcm_nw_gsm_sig_info_t_v01 gsm_sig_info;
  /**<   GSM singal information. */

  /* Optional */
  uint8_t wcdma_sig_info_valid;  /**< Must be set to true if wcdma_sig_info is being passed */
  mcm_nw_wcdma_sig_info_t_v01 wcdma_sig_info;
  /**<   WCDMA singal information. */

  /* Optional */
  uint8_t tdscdma_sig_info_valid;  /**< Must be set to true if tdscdma_sig_info is being passed */
  mcm_nw_tdscdma_sig_info_t_v01 tdscdma_sig_info;
  /**<   TDSCDMA singal information. */

  /* Optional */
  uint8_t lte_sig_info_valid;  /**< Must be set to true if lte_sig_info is being passed */
  mcm_nw_lte_sig_info_t_v01 lte_sig_info;
  /**<   LTE singal information. */

  /* Optional */
  uint8_t cdma_sig_info_valid;  /**< Must be set to true if cdma_sig_info is being passed */
  mcm_nw_cdma_sig_info_t_v01 cdma_sig_info;
  /**<   CDMA singal information. */

  /* Optional */
  uint8_t hdr_sig_info_valid;  /**< Must be set to true if hdr_sig_info is being passed */
  mcm_nw_hdr_sig_info_t_v01 hdr_sig_info;
  /**<   HDR singal information. */
}mcm_nw_signal_strength_event_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Indication Message; Indication for a change in the cell access state, e.g., emergency only, CS call only. */
typedef struct {

  /* Mandatory */
  mcm_nw_cell_access_state_t_v01 nw_cell_access_state;
  /**<   Network cell access state. */
}mcm_nw_cell_access_state_change_event_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Indication Message; Indication to update NITZ time. */
typedef struct {

  /* Optional */
  uint8_t nw_nitz_time_valid;  /**< Must be set to true if nw_nitz_time is being passed */
  mcm_nw_nitz_time_t_v01 nw_nitz_time;
  /**<   NITZ Time update. */

  /* Optional */
  uint8_t abs_time_valid;  /**< Must be set to true if abs_time is being passed */
  uint64_t abs_time;

  /* Optional */
  uint8_t leap_sec_valid;  /**< Must be set to true if leap_sec is being passed */
  int8_t leap_sec;
}mcm_nw_nitz_time_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Indication for MCM_NW_SET_WEA_CONFIG_REQ. */
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
}mcm_nw_set_wea_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Indication for MCM_NW_SET_WEA_CONFIG_REQ. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<  Result code.*/
}mcm_nw_set_wea_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Indication for MCM_NW_GET_WEA_CONFIG_REQ. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_nw_get_wea_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Indication for MCM_NW_GET_WEA_CONFIG_REQ. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;

  /* Mandatory */
  mcm_nw_wea_config_t_v01 wea_config_info;
}mcm_nw_get_wea_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Indication for MCM_NW_WEA_ALERT_IND. */
typedef struct {

  /* Mandatory */
  uint32_t wea_alert_len;  /**< Must be set to # of elements in wea_alert */
  char wea_alert[MCM_MAX_WEA_ALERT_LENGTH_V01];
}mcm_nw_wea_alert_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Indication for MCM_NW_SET_ETWS_CONFIG_REQ. */
typedef struct {

  /* Mandatory */
  uint8_t etws_alert;
  /**<    Enable or disable etws_alert: 0 -- Disable; 1 -- Enable */
}mcm_nw_set_etws_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Indication for MCM_NW_SET_ETWS_CONFIG_REQ. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;
  /**<  Result code.*/
}mcm_nw_set_etws_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Request Message; Indication for MCM_NW_GET_ETWS_CONFIG_REQ. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}mcm_nw_get_etws_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Indication for MCM_NW_GET_ETWS_CONFIG_REQ. */
typedef struct {

  /* Mandatory */
  mcm_response_t_v01 response;

  /* Mandatory */
  uint8_t etws_config_info;
}mcm_nw_get_etws_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_qmi_messages
    @{
  */
/** Response Message; Indication for MCM_NW_ETWS_ALERT_IND. */
typedef struct {

  /* Mandatory */
  uint32_t etws_primary_alert_len;  /**< Must be set to # of elements in etws_primary_alert */
  char etws_primary_alert[MCM_MAX_ETWS_ALERT_LENGTH_V01];

  /* Mandatory */
  uint32_t etws_secondary_alert_len;  /**< Must be set to # of elements in etws_secondary_alert */
  char etws_secondary_alert[MCM_MAX_ETWS_ALERT_LENGTH_V01];
}mcm_nw_etws_alert_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup mcm_nw_msg_ids
    @{
  */
#define MCM_NW_SET_CONFIG_REQ_V01 0x0500
#define MCM_NW_SET_CONFIG_RESP_V01 0x0500
#define MCM_NW_GET_CONFIG_REQ_V01 0x0501
#define MCM_NW_GET_CONFIG_RESP_V01 0x0501
#define MCM_NW_GET_REGISTRATION_STATUS_REQ_V01 0x0502
#define MCM_NW_GET_REGISTRATION_STATUS_RESP_V01 0x0502
#define MCM_NW_SCAN_REQ_V01 0x0503
#define MCM_NW_SCAN_RESP_V01 0x0503
#define MCM_NW_GET_OPERATOR_NAME_REQ_V01 0x0504
#define MCM_NW_GET_OPERATOR_NAME_RESP_V01 0x0504
#define MCM_NW_SCREEN_ON_OFF_REQ_V01 0x0505
#define MCM_NW_SCREEN_ON_OFF_RESP_V01 0x0505
#define MCM_NW_SELECTION_REQ_V01 0x0506
#define MCM_NW_SELECTION_RESP_V01 0x0506
#define MCM_NW_GET_SIGNAL_STRENGTH_REQ_V01 0x0507
#define MCM_NW_GET_SIGNAL_STRENGTH_RESP_V01 0x0507
#define MCM_NW_GET_CELL_ACCESS_STATE_REQ_V01 0x0508
#define MCM_NW_GET_CELL_ACCESS_STATE_RESP_V01 0x0508
#define MCM_NW_GET_NITZ_TIME_INFO_REQ_V01 0x0509
#define MCM_NW_GET_NITZ_TIME_INFO_RESP_V01 0x0509
#define MCM_NW_EVENT_REGISTER_REQ_V01 0x050A
#define MCM_NW_EVENT_REGISTER_RESP_V01 0x050A
#define MCM_NW_VOICE_REGISTRATION_EVENT_IND_V01 0x050B
#define MCM_NW_DATA_REGISTRATION_EVENT_IND_V01 0x050C
#define MCM_NW_SIGNAL_STRENGTH_EVENT_IND_V01 0x050D
#define MCM_NW_CELL_ACCESS_STATE_CHANGE_EVENT_IND_V01 0x050E
#define MCM_NW_NITZ_TIME_IND_V01 0x050F
#define MCM_NW_GET_CELL_INFO_REQ_V01 0x0510
#define MCM_NW_GET_CELL_INFO_RESP_V01 0x0510
#define MCM_NW_SET_WEA_CONFIG_REQ_V01 0x0511
#define MCM_NW_SET_WEA_CONFIG_RESP_V01 0x0511
#define MCM_NW_GET_WEA_CONFIG_REQ_V01 0x0512
#define MCM_NW_GET_WEA_CONFIG_RESP_V01 0x0512
#define MCM_NW_WEA_ALERT_IND_V01 0x0513
#define MCM_NW_SET_ETWS_CONFIG_REQ_V01 0x0514
#define MCM_NW_SET_ETWS_CONFIG_RESP_V01 0x0514
#define MCM_NW_GET_ETWS_CONFIG_REQ_V01 0x0515
#define MCM_NW_GET_ETWS_CONFIG_RESP_V01 0x0515
#define MCM_NW_ETWS_ALERT_IND_V01 0x0516

/**
    @}
  */

#ifdef __cplusplus
}
#endif
#endif

