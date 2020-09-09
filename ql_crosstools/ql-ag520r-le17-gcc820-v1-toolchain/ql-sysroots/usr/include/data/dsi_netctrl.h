/**
  @file
  dsi_netctrl.h

  @brief
  This file provides an API to interact with underlying data control
  plane.

*/

/*===========================================================================
  Copyright (c) 2008-2015, 2018-2020 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

$Header:  $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
05/23/13   leo     (Tech Pubs) Edited/added Doxygen comments and markup.
04/19/10   js      modified original to suit multi modem requirements

===========================================================================*/
#ifdef __cplusplus
extern "C" {
#endif

#ifndef DSI_NETCTRL_H
#define DSI_NETCTRL_H

#include <sys/socket.h>
#include <netdb.h>
#include <stdbool.h>

/*---------------------------------------------------------------------------
                           DECLARATIONS
---------------------------------------------------------------------------*/

typedef void * dsi_hndl_t;

#if (!defined(FEATURE_EXTERNAL_AP) && !defined(FEATURE_IPQ_OPENWRT))
#include "dsi_netctrl_qos.h"
#endif /* (!defined(FEATURE_EXTERNAL_AP) && !defined(FEATURE_IPQ_OPENWRT)) */

#include "wireless_data_service_v01.h"

/* these are unique bitmasks. always make sure
 * the next technology bitmap is 1 left shift of
 * previous technolgoy bitmap */
#define DSI_RADIO_TECH_MIN 0x00000001
#define DSI_RADIO_TECH_UMTS DSI_RADIO_TECH_MIN
#define DSI_RADIO_TECH_CDMA 0x00000002
#define DSI_RADIO_TECH_1X 0x00000004
#define DSI_RADIO_TECH_DO 0x00000008
#define DSI_RADIO_TECH_LTE 0x00000010
#define DSI_RADIO_TECH_TDSCDMA 0x00000020
/* this is integer number telling how many techs we have */
#define DSI_RADIO_TECH_MAX 6
#define DSI_RADIO_TECH_UNKNOWN 0

/* PCSCF address limit */
#define DSI_PCSCF_ADDR_LIST_MAX 20
#define DSI_PCSCF_FQDN_LIST_MAX 15

#define DSI_MAX_FQDN_STR_SIZE   256

#define DSI_IPV6_ADDR_ARRAY_LEN 16

typedef struct sockaddr_storage sockaddr_storage_t;

typedef enum dsi_auth_pref_e
{
  DSI_AUTH_PREF_PAP_CHAP_NOT_ALLOWED = 0,
  DSI_AUTH_PREF_PAP_ONLY_ALLOWED,
  DSI_AUTH_PREF_CHAP_ONLY_ALLOWED,
  DSI_AUTH_PREF_PAP_CHAP_BOTH_ALLOWED
} dsi_auth_pref_t;

typedef enum dsi_ce_reason_type_e
{
  DSI_CE_TYPE_UNINIT  = -2,
  DSI_CE_TYPE_INVALID = 0XFF,
  DSI_CE_TYPE_MOBILE_IP = 0x01,
  DSI_CE_TYPE_INTERNAL = 0x02,
  DSI_CE_TYPE_CALL_MANAGER_DEFINED = 0x03,
  DSI_CE_TYPE_3GPP_SPEC_DEFINED = 0x06,
  DSI_CE_TYPE_PPP = 0x07,
  DSI_CE_TYPE_EHRPD = 0x08,
  DSI_CE_TYPE_IPV6 = 0x09
} dsi_ce_reason_type_t;

/** @cond
*/

typedef struct dsi_ce_reason_s
{
  dsi_ce_reason_type_t reason_type; /* discriminator for reason codes */
  int reason_code; /* overloaded cause codes discriminated by reason_type */
} dsi_ce_reason_t;

/** @endcond */

typedef enum dsi_embms_tmgi_deactivated_reason_type_e
{
  DSI_EMBMS_TMGI_DEACTIVATED_TYPE_INVALID                    = -1,
  DSI_EMBMS_TMGI_DEACTIVATED_TYPE_ACT_FAIL_RADIO_CONFIG      = 0x00010000,
  DSI_EMBMS_TMGI_DEACTIVATED_TYPE_ACT_FAIL_CHANNEL_UNAVAIL   = 0x00010001,
  DSI_EMBMS_TMGI_DEACTIVATED_TYPE_ACT_FAIL_EMBMS_NOT_ENABLED = 0x00010002,
  DSI_EMBMS_TMGI_DEACTIVATED_TYPE_ACT_FAIL_OUT_OF_COVERAGE   = 0x00010003,
} dsi_embms_tmgi_deactivate_reason_type_t;

typedef enum dsi_ext_tech_pref_e
{
  DSI_EXT_TECH_INVALID = 0,
  DSI_EXT_TECH_CDMA,
  DSI_EXT_TECH_UMTS,
  DSI_EXT_TECH_EMBMS,
  DSI_EXT_TECH_MODEM_LINK_LOCAL /* used only by IMS not by qcril */
} dsi_ext_tech_pref_t;

typedef dsi_ext_tech_pref_t dsi_call_tech_type;

/** @addtogroup datatypes
@{ */

/** Return value from most of the DSI functions. */
#define DSI_SUCCESS   0   /**< Indicates that the operation was successful. */
#define DSI_ERROR    -1   /**< Indicates that the operation was not successful. */

/** @} */ /* end_addtogroup datatypes */


/** @addtogroup errorcodes
@{ */

#define DSI_EFAULT        101
#define DSI_EBADF         102
#define DSI_EINTERNAL     103
#define DSI_EINITED       104   /**< Indicates the library is already inited. */

/** @} */ /* end_addtogroup datatypes */

/* currently using #define constants
 * instead of typedef primarily so that
 * user can pass in an integer without
 * typcasting */
#define DSI_CALL_TYPE_TETHERED 0
#define DSI_CALL_TYPE_EMBEDDED 1

#define DSI_IP_VERSION_4   4
#define DSI_IP_VERSION_6   6
#define DSI_IP_VERSION_4_6 10

/** @addtogroup datatypes
@{ */


/** IMS portforwarding status defines **/
typedef enum dsi_port_forwarding_status_enum_e
{
  DSI_PORT_FORWARDING_INVALID = -1,
  DSI_PORT_FORWARDING_ENABLED,
  DSI_PORT_FORWARDING_DISABLED,
}dsi_port_forwarding_status_t;


/** Specifies which configuration parameter to update using
dsi_set_data_call_param(). */
typedef enum dsi_call_info_enum_e
{
  DSI_CALL_INFO_MIN = 0,
  DSI_CALL_INFO_UMTS_PROFILE_IDX, /**< UMTS profile ID. */
  DSI_CALL_INFO_APN_NAME,         /**< APN name. */
  DSI_CALL_INFO_USERNAME,         /**< APN user name (if any). */
  DSI_CALL_INFO_PASSWORD,         /**< APN password (if any). */
  DSI_CALL_INFO_AUTH_PREF,        /**< Authentication preference. */
  DSI_CALL_INFO_CDMA_PROFILE_IDX, /**< CDMA profile ID. */
  DSI_CALL_INFO_IP_ADDR,
  DSI_CALL_INFO_DEVICE_NAME,
  DSI_CALL_INFO_TECH_PREF,        /**< Technology preference. */
  DSI_CALL_INFO_CALL_TYPE,
  DSI_CALL_INFO_IP_VERSION,       /**< Preferred IP family for the call. */
  DSI_CALL_INFO_EXT_TECH_PREF,
  DSI_CALL_INFO_PARTIAL_RETRY,
  DSI_CALL_INFO_APP_TYPE,
  DSI_CALL_INFO_SUBS_ID,
  DSI_CALL_INFO_MAX
} dsi_call_param_identifier_t;

typedef enum dsi_call_param_app_type
{
  DSI_CALL_PARAM_APP_TYPE_INVALID = -1,
  DSI_CALL_PARAM_APP_TYPE_DEFAULT = 0,
  DSI_CALL_PARAM_APP_TYPE_INTERNET = DSI_CALL_PARAM_APP_TYPE_DEFAULT,
  DSI_CALL_PARAM_APP_TYPE_IMS
} dsi_param_app_type_t;

/** Specifies string parameter values for dsi_set_data_call_param(). */
typedef struct
{
  char * buf_val;  /**< Pointer to the buffer containing the parameter value
                        that is to be set. */
  int num_val;     /**< Size of the parameter buffer. */
} dsi_call_param_value_t;

typedef struct
{
  dsi_call_param_identifier_t  identifier;
  dsi_call_param_value_t       value;
}dsi_call_param_info_t;

#define DSI_MAX_CALL_PARAMS 13   /* Matches the numer of enums in dsi_call_param_identifier_t */


/** @} */ /* end_addtogroup datatypes */

#define DSI_CALL_INFO_USERNAME_MAX_LEN (127 + 1)
#define DSI_CALL_INFO_PASSWORD_MAX_LEN (127 + 1)
/* rmnet_sdioxx, rmnet_xx */
#define DSI_CALL_INFO_DEVICE_NAME_MAX_LEN 16

/* max supported dsi handles */
#define DSI_MAX_DATA_CALLS     (40)

/** @addtogroup datatypes
@{ */

/**
   DSI event names.

   These event names are sent along with the callback that
   has been registered during dsi_get_data_service_hndl().
*/
typedef enum
{
  DSI_EVT_INVALID = 0x0,              /**< Invalid event. */
  DSI_EVT_NET_IS_CONN,                /**< Call is connected. */
  DSI_EVT_NET_NO_NET,                 /**< Call is disconnected. */
  DSI_EVT_PHYSLINK_DOWN_STATE,        /**< Physlink becomes dormant. */
  DSI_EVT_PHYSLINK_UP_STATE,          /**< Physlink becomes active. */
  DSI_EVT_NET_RECONFIGURED,           /**< Interface is reconfigured. */
  DSI_EVT_QOS_STATUS_IND,             /**< A status for the associated QoS has
                                           changed. */
  DSI_EVT_NET_NEWADDR,                /**< New address is generated. */
  DSI_EVT_NET_DELADDR,                /**< An address for the interface has been deleted. */
  DSI_EVT_NET_PARTIAL_CONN,           /**< Address is available for either IPv4
                                           or IPv6 only. @newpage */
  DSI_NET_TMGI_ACTIVATED,
  DSI_NET_TMGI_DEACTIVATED,
  DSI_NET_TMGI_ACTIVATED_DEACTIVATED,
  DSI_NET_TMGI_LIST_CHANGED,
  DSI_NET_SAI_LIST_CHANGED,
  DSI_NET_CONTENT_DESC_CONTROL,
  DSI_NET_TMGI_SERVICE_INTERESTED,

  DSI_EVT_NET_HANDOFF,
  DSI_EVT_WDS_CONNECTED,
  DSI_EVT_NET_NEWMTU,                 /**< MTU update. */

  DSI_EVT_V2X_SPS_FLOW_REG_IND,       /** V2X indications */
  DSI_EVT_V2X_SPS_FLOW_DEREG_IND,
  DSI_EVT_V2X_SPS_FLOW_UPDATE_IND,
  DSI_EVT_V2X_SERVICE_SUBSCRIBE_IND,
  DSI_EVT_PWR_SAVE_INFO,

  DSI_EVT_PID_RESERVED,   /* LPTD */
  DSI_EVT_PID_UNRESERVED, /* Application no longer has isolated core */

  /* Update dsi_evt_str array when adding new event to this enum */
  DSI_EVT_MAX
} dsi_net_evt_t;

/** @} */ /* end_addtogroup datatypes */

typedef enum dsi_embms_tmgi_session_id_valid_e
{
  DSI_EMBMS_TMGI_SESSION_ID_NOT_VALID = 0,
  DSI_EMBMS_TMGI_SESSION_ID_VALID     = 1
}dsi_embms_tmgi_session_id_state_t;

typedef enum dsi_embms_tmgi_activate_request_type_e
{
  DSI_EMBMS_TMGI_REQUEST_INVALID    = -1,
  DSI_EMBMS_TMGI_REQUEST_ACTIVATE   = 0,
  DSI_EMBMS_TMGI_REQUEST_DEACTIVATE = 1
}dsi_embms_tmgi_activate_request_type_t;

/** @cond
*/

typedef struct
{
  int                                       param_code;
  int                                       param_value;
}dsi_embms_content_desc_type;

typedef wds_connection_status_enum_v01              dsi_link_status_type;
typedef wds_embms_tmgi_list_type_enum_v01           dsi_embms_tmgi_list_type;
typedef wds_handoff_information_type_enum_v01       dsi_handoff_info_type;


typedef enum
{
  DSI_WDS_RAT_EX_NULL_BEARER  = WDS_BEARER_TECH_RAT_EX_NULL_BEARER_V01,

  /* 3GPP RAT Values */
  DSI_WDS_RAT_EX_3GPP_WCDMA   = WDS_BEARER_TECH_RAT_EX_3GPP_WCDMA_V01,
  DSI_WDS_RAT_EX_3GPP_GERAN   = WDS_BEARER_TECH_RAT_EX_3GPP_GERAN_V01,
  DSI_WDS_RAT_EX_3GPP_LTE     = WDS_BEARER_TECH_RAT_EX_3GPP_LTE_V01,
  DSI_WDS_RAT_EX_3GPP_TDSCDMA = WDS_BEARER_TECH_RAT_EX_3GPP_TDSCDMA_V01,
  DSI_WDS_RAT_EX_3GPP_WLAN    = WDS_BEARER_TECH_RAT_EX_3GPP_WLAN_V01,
  DSI_WDS_RAT_EX_3GPP_MAX     = WDS_BEARER_TECH_RAT_EX_3GPP_MAX_V01,

  /* 3GPP2 RAT Values */
  DSI_WDS_RAT_EX_3GPP2_1X     = WDS_BEARER_TECH_RAT_EX_3GPP2_1X_V01,
  DSI_WDS_RAT_EX_3GPP2_HRPD   = WDS_BEARER_TECH_RAT_EX_3GPP2_HRPD_V01,
  DSI_WDS_RAT_EX_3GPP2_EHRPD  = WDS_BEARER_TECH_RAT_EX_3GPP2_EHRPD_V01,
  DSI_WDS_RAT_EX_3GPP2_WLAN   = WDS_BEARER_TECH_RAT_EX_3GPP2_WLAN_V01,
  DSI_WDS_RAT_EX_3GPP2_MAX    = WDS_BEARER_TECH_RAT_EX_3GPP2_MAX_V01,

  /* Force to 32 bits */
  DSI_WDS_RAT_EX_MAX          = WDS_BEARER_TECH_RAT_EX_ENUM_MAX_ENUM_VAL_V01
}dsi_wds_rat_e;

typedef struct dsi_wds_handoff_info
{
  dsi_handoff_info_type    handoff_type;
  dsi_wds_rat_e            source_rat;
  dsi_wds_rat_e            target_rat;
  wds_ip_family_preference_enum_v01 ip_type;
} dsi_wds_handoff_info_type;

typedef enum
{
  QMI_WDS_HANDOFF_IND = 0
} dsi_ind_reg_type;

typedef enum
{
  DSI_IND_REGISTER = 0,
  DSI_IND_UNREGISTER
} dsi_ind_registration_t;

typedef enum
{
  CHECK_ACTIVATE_STATUS = 0,
  CHECK_DEACTIVATE_STATUS = 1,
  CHECK_ACTIVATE_DEACTIVATE_STATUS = 3
}dsi_embms_tmgi_status_field_type;

/** @addtogroup datatypes
@{ */

/* Enum of different IP families */
typedef enum
{
  DSI_IP_FAMILY_V4,
  DSI_IP_FAMILY_V6,
  DSI_NUM_IP_FAMILIES
} dsi_ip_family_t;

typedef enum
{
  DSI_FLTR_MASK_INVALID  = 0x00,
  DSI_FLTR_MASK_SRC_ADDR = 0x01,
  DSI_FLTR_MASK_DST_ADDR = 0x02,
  DSI_FLTR_MASK_SRC_PORT = 0x04,
  DSI_FLTR_MASK_DST_PORT = 0x08,
  DSI_FLTR_MASK_PROTOCOL = 0x10,
  DSI_FLTR_MASK_MAX_VAL  = 0xFF
}dsi_fltr_mask;

typedef struct
{
  uint8_t   ipv6_addr[DSI_IPV6_ADDR_ARRAY_LEN];
  uint8_t   prefix_len;
}dsi_ipv6_addr_type;

typedef struct
{
  uint32_t    ipv4_addr;
  uint32_t  ip_mask;
}dsi_ipv4_addr_type;

typedef struct
{
 dsi_ip_family_t  ip_family;
  union
   {
      dsi_ipv4_addr_type ipv4_addr;
      dsi_ipv6_addr_type  ipv6_addr;
  } ip_addr;
} dsi_ip_addr_info;

typedef enum
{
  DSI_PROTO_NONE =0x0,
  DSI_PROTO_TCP =0x06,
  DSI_PROTO_UDP= 0x11,
  DSI_PROTO_INVALID = 0XFFFF
}dsi_protocol_type;


typedef struct{
  uint16_t   port;
  uint16_t  range;
}dsi_port_info_type;


typedef struct {
  uint64_t            ip_opt_mask;
  dsi_ip_addr_info    src_addr;
  dsi_ip_addr_info    dst_addr;
  dsi_protocol_type   protocol;
  dsi_port_info_type  src_port_info;
  dsi_port_info_type  dst_port_info;
}dsi_ip_filter_info;


typedef union
{
  /* Populated for events: DSI_NET_TMGI_LIST_CHANGED */
  wds_embms_tmgi_list_ind_msg_v01 embms_list_info;

  /* Populated for events: DSI_NET_TMGI_ACTIVATED */
  wds_embms_tmgi_activate_ind_msg_v01 embms_act_info;

  /* Populated for events: DSI_NET_TMGI_DEACTIVATED */
  wds_embms_tmgi_deactivate_ind_msg_v01 embms_deact_info;

  /* Populated for events: DSI_NET_TMGI_ACTIVATED_DEACTIVATED */
  wds_embms_tmgi_act_deact_ind_msg_v01 embms_act_deact_info;

  /* Populated for events: DSI_NET_SAI_LIST_CHANGED */
  wds_embms_sai_list_ind_msg_v01 embms_sai_info;

  /* Populated for events: DSI_NET_CONTENT_DESC_CONTROL */
  wds_embms_content_desc_control_ind_msg_v01 embms_content_desc_info;

  /* Populated for events: DSI_NET_TMGI_SERVICE_INTERESTED */
  wds_embms_svc_interest_ind_msg_v01 embms_svc_interest_info;

}dsi_embms_tmgi_info_type;


/** Event payload sent with event callback. */
typedef struct evt_info_s
{
  /* Populated for events: DSI_EVT_QOS_STATUS_IND */

#if (!defined(FEATURE_EXTERNAL_AP) && !defined(FEATURE_IPQ_OPENWRT))
  struct qos_info_s
  {
    dsi_qos_id_type              flow_id;     /**< QoS flow ID .*/
    dsi_qos_flow_type            flow_type;   /**< Flow type. */
    dsi_qos_status_event_type    status_evt;  /**< Flow status. See
                                                   dsi_qos_status_event_type. */
    dsi_qmi_qos_reason_code_type reason_code; /**< Reason code if the flow is
                                                   disconnected. */
  } qos_info /** Event information associated with a QoS status indication.
                 See qos_info_s in the next subsection. */;
#endif /* (!defined(FEATURE_EXTERNAL_AP) && !defined(FEATURE_IPQ_OPENWRT)) */

  dsi_embms_tmgi_info_type   embms_info;

  dsi_wds_handoff_info_type  handoff_info;    /**< Event information associated
                                                   with WDS Handoff event
                                                   indication */
  dsi_ip_family_t ip_type;      /* This member is used only while generating
                                   DSI_EVT_WDS_CONNECTED event
                                 */

  uint32_t is_powersave_mode_enabled;
} dsi_evt_payload_t;

/** Callback function prototype for DSI NetCtrl events. */
typedef void (*dsi_net_ev_cb)( dsi_hndl_t         hndl,         /**< Handle for which this event is associated. */
                               void              *user_data,    /**< Application-provided user data. */
                               dsi_net_evt_t      evt,          /**< Event identifier. */
                               dsi_evt_payload_t *payload_ptr   /**< Associated event information. */
                               );


/** Structure used to represent the IP address. */
typedef struct dsi_addr_s
{
  /* indicates if a valid address is available or not */
  char valid_addr; /**< Stores whether the address is valid (for IPv6). */
  /* stores ip address */
  struct sockaddr_storage addr; /**< Address structure. */
} dsi_addr_t;

/** IP address information structure. */
typedef struct dsi_addr_info_s
{
  /* Network interface address */
  dsi_addr_t iface_addr_s; /**< Interface IP address. */
  unsigned int iface_mask; /**< Subnet mask.       */
  /* Gateway server address */
  dsi_addr_t gtwy_addr_s;  /**< Gateway IP address. */
  unsigned int gtwy_mask;  /**< Subnet mask. */
  /* Primary DNS server  address */
  dsi_addr_t dnsp_addr_s;  /**< Primary DNS address. */
  /* Secondary DNS server  address */
  dsi_addr_t dnss_addr_s;  /**< Secondary DNS address. */
} dsi_addr_info_t;

typedef struct
{
  int              is_valid;
  dsi_ce_reason_t  ce_reason;
} dsi_ce_reason_ex_t;

typedef struct dsi_disconnect_info
{
  dsi_ce_reason_ex_t ce_reason4;
  dsi_ce_reason_ex_t ce_reason6;
} dsi_disconnect_info_t;

typedef struct dsi_dev_info
{
  char             dev_node[DSI_CALL_INFO_DEVICE_NAME_MAX_LEN+1];
  int              addr_count;
  dsi_addr_info_t  addr_info[2];
  unsigned int     mtu;
} dsi_dev_info_t;

#define DSI_V2X_DEF_ISOL_CPU       3
#define DSI_V2X_INVALID_CPU       -1

#define DSI_V2X_MAX_SUB            QMI_WDS_V2X_MAX_SUB_V01
#define DSI_V2X_NON_SPS_MAX_FLOWS  WDS_V2X_NON_SPS_MAX_FLOWS_V01

#define DSI_V2X_OPT_PARAM_MASK_PRIORITY                 ((uint64_t) 0x01ull)
#define DSI_V2X_OPT_PARAM_MASK_PERIODICITY              ((uint64_t) 0x02ull)
#define DSI_V2X_OPT_PARAM_MASK_MSG_SIZE                 ((uint64_t) 0x04ull)
#define DSI_V2X_OPT_PARAM_MASK_SERVICE_ID               ((uint64_t) 0x08ull)
#define DSI_V2X_OPT_PARAM_MASK_SPS_PORT                 ((uint64_t) 0x10ull)
#define DSI_V2X_OPT_PARAM_MASK_EVENT_DRIVEN_PORT        ((uint64_t) 0x20ull)
#define DSI_V2X_OPT_PARAM_MASK_PROTOCOL                 ((uint64_t) 0x40ull)
#define DSI_V2X_OPT_PARAM_MASK_PEAK_TX_POWER            ((uint64_t) 0x80ull)
#define DSI_V2X_OPT_PARAM_MASK_MCS_INDEX                ((uint64_t) 0x100ull)
#define DSI_V2X_OPT_PARAM_MASK_RETX_SETTING             ((uint64_t) 0x200ull)
#define DSI_V2X_OPT_PARAM_MASK_TX_POOL_ID               ((uint64_t) 0x400ull)
#define DSI_V2X_OPT_PARAM_MASK_NON_SPS_FLOW_REG_INFO    ((uint64_t) 0x800ull)
#define DSI_V2X_OPT_PARAM_MASK_NON_SPS_FLOW_RESULT      ((uint64_t) 0x1000ull)
#define DSI_V2X_OPT_PARAM_MASK_SERVICE_LIST             ((uint64_t) 0x2000ull)
#define DSI_V2X_OPT_PARAM_MASK_PORT                     ((uint64_t) 0x4000ull)
#define DSI_V2X_OPT_PARAM_MASK_WILDCARD_SUBS            ((uint64_t) 0x8000ull)

typedef enum
{
  DSI_V2X_ERR_TYPE_ENUM_MIN                  = -1,
  DSI_V2X_ERR_NONE                           = 0,
  DSI_V2X_ERR_EXCEED_MAX                     = 1,
  DSI_V2X_ERR_V2X_DISABLED                   = 2,
  DSI_V2X_ERR_UNKNOWN_SERVICE_ID             = 3,
  DSI_V2X_ERR_SRV_ID_L2_ADDRS_NOT_COMPATIBLE = 4,
  DSI_V2X_ERR_PORT_UNAVAIL                   = 5,
  DSI_V2X_ERR_INTERNAL                       = 6,
  DSI_V2X_ERR_INVALID_ARG                    = 7,
  DSI_V2X_ERR_INVALID_HNDL                   = 8,
  DSI_v2X_ERR_UNSUPPORTED                    = 9,
  DSI_V2X_ERR_TYPE_MAX_VAL                   = 0xffff
} dsi_v2x_err_type_t;

typedef struct
{
  uint32_t            service_id;
  dsi_v2x_err_type_t  result;
} dsi_v2x_result_type_t;

typedef enum
{
  DSI_V2X_RETX_INVALID = -1,
  DSI_V2X_RETX_AUTO    = 0,
  DSI_V2X_RETX_ON      = 1,
  DSI_V2X_RETX_OFF     = 2,
  DSI_V2X_RETX_MAX_VAL = 0xff
} dsi_v2x_retx_type_t;

typedef enum
{
  DSI_V2X_PROTOCOL_INVALID_VAL = 0x0,
  DSI_V2X_PROTO_TCP            = 0x01,
  DSI_V2X_PROTO_UDP            = 0x02,
  DSI_V2X_PROTO_TCP_UDP        = 0x03,
  DSI_V2X_PROTO_MAX_VAL        = 0xff
} dsi_protocol_type_t;

typedef enum
{
  DSI_V2X_SERVICE_SUBS_INVALD          = -1,
  DSI_V2X_SERVICE_SUBS_ADD             = 0,
  DSI_V2X_SERVICE_SUBS_REMOVE          = 1,
  DSI_V2X_SERVICE_SUBS_ADD_WILDCARD    = 2,
  DSI_V2X_SERVICE_SUBS_REMOVE_WILDCARD = 3,
  DSI_V2X_SERVICE_SUB_MAX_VAL          = 0xff
} dsi_v2x_service_sub_action_type_t;

typedef struct
{
  uint32_t req_id;
  uint8_t  sps_id;
} dsi_v2x_sps_flow_id_t;

typedef struct
{
  uint64_t             optional_params_mask;
  uint32_t             req_id;
  uint32_t             periodicity;
  uint32_t             msg_size;
  uint32_t             service_id;
  int32_t              peak_tx_power;
  uint16_t             sps_port;
  uint16_t             evt_driven_port;
  dsi_protocol_type_t  protocol;
  dsi_v2x_retx_type_t  retx_setting;
  uint8_t              priority;
  uint8_t              mcs_index;
  uint8_t              tx_pool_id;
} dsi_v2x_sps_flow_reg_req_info_t;

typedef struct
{
  uint64_t optional_params_mask;
  uint32_t req_id;
  uint32_t periodicity;
  uint32_t msg_size;
  int32_t peak_tx_power;
  dsi_v2x_retx_type_t retx_setting;
  uint8_t sps_id;
  uint8_t mcs_index;
  uint8_t tx_pool_id;
} dsi_v2x_sps_flow_update_req_info_t;

typedef struct
{
  uint32_t req_id;
  uint8_t  sps_id;
} dsi_v2x_sps_flow_dereg_req_info_t;

typedef struct
{
  uint32_t req_id;
  uint8_t  sps_id;
} dsi_v2x_sps_flow_get_info_req_t;

typedef struct
{
  uint64_t             optional_params_mask;
  uint32_t             periodicity;
  uint32_t             msg_size;
  uint32_t             service_id;
  int32_t              peak_tx_power;
  uint16_t             sps_port;
  uint16_t             evt_driven_port;
  dsi_protocol_type_t  protocol;
  dsi_v2x_retx_type_t  retx_setting;
  uint8_t              mcs_index;
  uint8_t              priority;
  uint8_t              tx_pool_id;
} dsi_v2x_sps_flow_get_info_resp_t;

typedef struct
{
  uint32_t  service_id;
  uint16_t  port;
} dsi_v2x_non_sps_info_t;

typedef struct
{
  dsi_v2x_non_sps_info_t  reg_info;
  dsi_protocol_type_t     protocol;
} dsi_v2x_non_sps_flow_info_type_t;

typedef struct
{
  uint64_t                         optional_params_mask;
  uint32_t                         req_id;
  dsi_v2x_non_sps_flow_info_type_t non_sps_flow;
  int32_t                          peak_tx_power;
  dsi_v2x_retx_type_t              retx_setting;
  uint8_t                          mcs_index;
  uint8_t                          tx_pool_id;
} dsi_v2x_non_sps_flow_reg_req_info_t;

typedef struct
{
  uint64_t               optional_params_mask;
  dsi_v2x_result_type_t  result;
} dsi_v2x_non_sps_flow_reg_resp_info_t;

typedef struct
{
  uint64_t                optional_params_mask;
  uint32_t                req_id;
  uint32_t                non_sps_flow_info_len;
  dsi_v2x_non_sps_info_t  non_sps_flow_info[DSI_V2X_NON_SPS_MAX_FLOWS];
} dsi_v2x_non_sps_flow_dereg_req_info_t;

typedef struct
{
  uint64_t               optional_params_mask;
  uint32_t               dereg_result_len;
  dsi_v2x_result_type_t  dereg_result[DSI_V2X_NON_SPS_MAX_FLOWS];
} dsi_v2x_non_sps_flow_dereg_resp_info_t;

typedef struct
{
  uint64_t                           optional_params_mask;
  uint32_t                           req_id;
  uint32_t                           service_id_list_len;
  uint32_t                           service_id_list[DSI_V2X_MAX_SUB];
  uint16_t                           port;
  dsi_v2x_service_sub_action_type_t  action;
} dsi_v2x_service_subscribe_req_info_t;

typedef struct
{
  uint64_t                           optional_params_mask;
  uint32_t                           service_id_len;
  uint32_t                           service_id[DSI_V2X_MAX_SUB];
  uint16_t                           dest_port;
  uint8_t                            wildcard_enabled;
}dsi_v2x_service_subscription_resp_info_t;

typedef struct
{
  dsi_v2x_sps_flow_id_t  flow_id;
  dsi_v2x_err_type_t     result;
} dsi_v2x_sps_flow_reg_ind_result_t;

typedef dsi_v2x_sps_flow_reg_ind_result_t dsi_v2x_sps_flow_dereg_ind_result_t;

typedef dsi_v2x_sps_flow_reg_ind_result_t dsi_v2x_sps_flow_update_ind_result_t;

typedef struct
{
  uint64_t               optional_params_mask;
  uint32_t               req_id;
  uint32_t               result_len;
  uint8_t                subscribe_wildcard_result;
  dsi_v2x_result_type_t  result[DSI_V2X_MAX_SUB];
} dsi_v2x_srvc_subscribe_ind_result_t;

typedef enum
{
  DSI_V2X_INVALID_IND = -1,
  DSI_V2X_SPS_FLOW_REG_IND,
  DSI_V2X_SPS_FLOW_DEREG_IND,
  DSI_V2X_SPS_FLOW_UPDATE_IND,
  DSI_V2X_SERVICE_SUBSCRIBE_IND,
  DSI_V2X_MAX_IND
} dsi_v2x_ind_type_t;

typedef struct
{
  dsi_v2x_ind_type_t  ind_type;
  union
  {
    dsi_v2x_sps_flow_reg_ind_result_t      sps_flow_reg_ind_info;
    dsi_v2x_sps_flow_dereg_ind_result_t    sps_flow_dereg_ind_info;
    dsi_v2x_sps_flow_update_ind_result_t   sps_flow_update_ind_info;
    dsi_v2x_srvc_subscribe_ind_result_t    srvc_subscribe_ind_info;
  } v2x_ind_info;
} dsi_v2x_ind_info_t;

typedef struct
{
  pid_t pid;
} dsi_lptd_info_t;

typedef enum
{
  DSI_V2X_REQUEST_INVALID = -1,
  DSI_V2X_REQUEST_REGISTER_SPS_FLOW,
  DSI_V2X_REQUEST_DEREGISTER_SPS_FLOW,
  DSI_V2X_REQUEST_UPDATE_SPS_FLOW,
  DSI_V2X_REQUEST_SPS_FLOW_GET_INFO,
  DSI_V2X_REQUEST_REGISTER_NON_SPS_FLOW,
  DSI_V2X_REQUEST_DEREGISTER_NON_SPS_FLOW,
  DSI_V2X_REQUEST_SERVICE_SUBSCRIBE,
  DSI_V2X_REQUEST_GET_SERVICE_SUBSCRIPTION_INFO,
  DSI_V2X_REQUEST_MAX
} dsi_v2x_req_t;

typedef dsi_embms_tmgi_info_type dsi_embms_tmgi_info_t;
typedef dsi_wds_handoff_info_type dsi_wds_handoff_info_t;

typedef union
{
  dsi_dev_info_t              dev_info;            /**< Event information associated with the
                                                        following events
                                                        - DSI_EVT_NET_IS_CONN
                                                        - DSI_EVT_NET_RECONFIGURED
                                                        - DSI_EVT_NET_NEWADDR
                                                        - DSI_EVT_NET_DELADDR
                                                        - DSI_EVT_NET_PARTIAL_CONN */
  dsi_disconnect_info_t       disconnect_info;     /**< Event information associated with the
                                                        following events
                                                        - DSI_EVT_NET_NO_NET */
  unsigned int                mtu;                 /**< Event information associated with
                                                        - DSI_EVT_NET_NEWMTU */
  dsi_v2x_ind_info_t          v2x_info;            /**< Event information associated with
                                                        - DSI_EVT_V2X_SPS_FLOW_REG_IND
                                                        - DSI_EVT_V2X_SPS_FLOW_DEREG_IND
                                                        - DSI_EVT_V2X_SPS_FLOW_UPDATE_IND
                                                        - DSI_EVT_V2X_SERVICE_SUBSCRIBE_IND, */
#if (!defined(FEATURE_EXTERNAL_AP) && !defined(FEATURE_IPQ_OPENWRT))
  ds_qos_info_t               qos_info;            /** Populated for events
                                                   - DSI_EVT_QOS_STATUS_IND */
#endif /* (!defined(FEATURE_EXTERNAL_AP) && !defined(FEATURE_IPQ_OPENWRT)) */
  dsi_embms_tmgi_info_t       embms_info;
  dsi_wds_handoff_info_t      handoff_info;        /**< Event information associated with WDS
                                                        Handoff event indication */
  uint32_t is_powersave_mode_enabled;

  dsi_lptd_info_t             lptd_info;
} dsi_evt_payload_ex_t;

/** Callback function prototype for DSI NetCtrl events. */
typedef void (*dsi_net_ev_cb_ex)
(
 dsi_hndl_t            hndl,        /**< Handle to which this event is associated */
 void                  *user_data,  /**< Application-provided user data. */
 dsi_net_evt_t         evt,         /**< Event identifier. */
 dsi_evt_payload_ex_t  *payload_ptr /**< Associated event information. */
 );

/** @} */ /* end_addtogroup datatypes */

#define DSI_GET_IP_FAMILY(ipf) ((AF_INET==(ipf))?"AF_INET": \
                                ((AF_INET6==(ipf))?"AF_INET6":"UNKNOWN"))

/** @addtogroup datatypes
@{ */

/** Datatypes used by IOCTL functions */
typedef struct
{
  int                         fqdn_length;
  unsigned char               fqdn_string[DSI_MAX_FQDN_STR_SIZE];
}dsi_wds_fqdn_strings_t;

/** PCSCF address information */
typedef struct dsi_pcscf_addr_info_s
{
  unsigned int addr_count;
  dsi_addr_t pcscf_address[DSI_PCSCF_ADDR_LIST_MAX];
} dsi_pcscf_addr_info_t;

typedef struct dsi_pcscf_fqdn_list_s
{
  unsigned int fqdn_count;
  dsi_wds_fqdn_strings_t pcscf_domain_list[DSI_PCSCF_FQDN_LIST_MAX];
} dsi_pcscf_fqdn_list_t;

typedef struct
{
  unsigned char   ipv6_addr[QMI_WDS_IPV6_ADDR_LEN_V01];
  unsigned char   prefix_len;
} dsi_delegated_ipv6_prefix_type;

/** Enum definition for the IOCTLs */
typedef enum
{
  DSI_IFACE_IOCTL_MIN = 0,
  DSI_IFACE_IOCTL_GET_PCSCF_SERV_ADDRESS = DSI_IFACE_IOCTL_MIN,
  DSI_IFACE_IOCTL_GET_PCSCF_DOMAIN_NAME_LIST,
  DSI_IFACE_IOCTL_REMOVE_DELEGATED_IPV6_PREFIX,
  DSI_IFACE_IOCTL_GET_MODEM_IFACE_V4_MTU,
  DSI_IFACE_IOCTL_GET_MODEM_IFACE_V6_MTU,
  DSI_IFACE_IOCTL_MAX,
  _DSI_IFACE_IOCTL_FORCE_32_BIT = 0x7FFFFFFF // Force 32 bits to be used for enum
}dsi_iface_ioctl_enum_t;

/** @} */ /* end_addtogroup datatypes */

/** @addtogroup datatypes
@{ */

/** Bearer technology types (returned with dsi_get_current_data_bearer_tech). */
typedef enum
{
  DSI_DATA_BEARER_TECH_UNKNOWN,       /**< Unknown bearer. */

  /* CDMA related data bearer technologies */
  DSI_DATA_BEARER_TECH_CDMA_1X,       /**< 1X technology. */
  DSI_DATA_BEARER_TECH_EVDO_REV0,     /**< CDMA Rev 0. */
  DSI_DATA_BEARER_TECH_EVDO_REVA,     /**< CDMA Rev A. */
  DSI_DATA_BEARER_TECH_EVDO_REVB,     /**< CDMA Rev B. */
  DSI_DATA_BEARER_TECH_EHRPD,         /**< EHRPD. */
  DSI_DATA_BEARER_TECH_FMC,           /**< Fixed mobile convergence. */
  DSI_DATA_BEARER_TECH_HRPD,          /**< HRPD */
  DSI_DATA_BEARER_TECH_3GPP2_WLAN,    /**< IWLAN */

  /* UMTS related data bearer technologies */
  DSI_DATA_BEARER_TECH_WCDMA,         /**< WCDMA. */
  DSI_DATA_BEARER_TECH_GPRS,          /**< GPRS. */
  DSI_DATA_BEARER_TECH_HSDPA,         /**< HSDPA. */
  DSI_DATA_BEARER_TECH_HSUPA,         /**< HSUPA. */
  DSI_DATA_BEARER_TECH_EDGE,          /**< EDGE. */
  DSI_DATA_BEARER_TECH_LTE,           /**< LTE. */
  DSI_DATA_BEARER_TECH_HSDPA_PLUS,    /**< HSDPA+. */
  DSI_DATA_BEARER_TECH_DC_HSDPA_PLUS, /**< DC HSDPA+. */
  DSI_DATA_BEARER_TECH_HSPA,          /**< HSPA */
  DSI_DATA_BEARER_TECH_64_QAM,        /**< 64 QAM. */
  DSI_DATA_BEARER_TECH_TDSCDMA,       /**< TD-SCDMA. */
  DSI_DATA_BEARER_TECH_GSM,           /**< GSM */
  DSI_DATA_BEARER_TECH_3GPP_WLAN,      /**< IWLAN */
  DSI_DATA_BEARER_TECH_5G,            /**< 5G */
  DSI_DATA_BEARER_TECH_MAX

} dsi_data_bearer_tech_t;


/** Packet statistics structure (returned with dsi_get_pkt_stats). */
typedef struct
{
  unsigned long pkts_tx;           /**< Number of packets transmitted. */
  unsigned long pkts_rx;           /**< Number of packets received. */
  long long     bytes_tx;          /**< Number of bytes transmitted. */
  long long     bytes_rx;          /**< Number of bytes received. */
  unsigned long pkts_dropped_tx;   /**< Number of transmit packets dropped. */
  unsigned long pkts_dropped_rx;   /**< Number of receive packets dropped. */
} dsi_data_pkt_stats;

/** Data channel rate structure (dsi_get_current_data_channel_rate) */
typedef struct
{
  unsigned long current_tx_rate;   /**< Current TX data rate for the channel*/
  unsigned long current_rx_rate;   /**< Current RX data rate for the channel*/
  unsigned long max_tx_rate;       /**< Max TX data rate for the channel*/
  unsigned long max_rx_rate;       /**< Max RX data rate for the channel*/
} dsi_data_channel_rate_t;


typedef enum
{
  DSI_DATA_DEFAULT_SUBS = 0x0000,
  DSI_DATA_PRIMARY_SUBS = 0x0001,
  DSI_DATA_SECONDARY_SUBS = 0x0002,
  DSI_DATA_TERITIARY_SUBS = 0x0003,
  DSI_DATA_DONT_CARE_SUBS = 0x00FF
}dsi_data_modem_subscription_id;

/** Data session keep alive type */
typedef enum
{
  DSI_DONT_KEEP_DATA_SESSION_ALIVE = 0,
  DSI_KEEP_DATA_SESSION_ALIVE,

  /* Must be the last entry */
  DSI_KEEP_ALIVE_MAX
} dsi_keep_alive_t;

/** @} */ /* end_addtogroup datatypes */

/*===========================================================================
                    EXTERNAL FUNCTION PROTOTYPES
===========================================================================*/

/* these are the currently supported modes
   for dsi_netctrl */
#define DSI_MODE_GENERAL 1 /* generic default mode */
#define DSI_MODE_TEST 8 /* used for test mode */
#define DSI_MODE_SSR 2 /*used for SSR mode*/

typedef uint16_t dsi_init_mode_t;

#define DSI_MODEM_IN_RESET        0x0000   /* Used for indications only */
#define DSI_MODE_GENERAL_EX       0x0001
#define DSI_MODE_SSR_EX           0x0002
#define DSI_MODE_LOW_LATENCY_EX   0x0004
#define DSI_MODE_TEST_EX          0x0008


/* Cached value used to compare with NETMGR mode */
extern dsi_init_mode_t dsi_init_mode;

typedef void (*dsi_init_cb_func_ex2)(dsi_init_mode_t mode, void* userdata);

/*===========================================================================
  FUNCTION:  dsi_init
===========================================================================*/
/** @ingroup dsi_init

    Initializes the DSI_NetCtrl library for the specified operating mode.

    This function must be invoked once per process, typically on process
    startup.

    @note1hang
    Only DSI_MODE_GENERAL is to be used by applications.

    @param[in] mode Mode of operation in which to initialize the library.
                    The library can be initialized to operate in one of
                    two modes: \n
                    - DSI_MODE_GENERAL
                    - DSI_MODE_TEST
                    @tablebulletend

    @return
    DSI_SUCCESS -- Initialization was successful. \n
    DSI_ERROR -- Initialization failed.

    @dependencies
    None.
*/
/*=========================================================================*/
extern int dsi_init(int mode);

/*===========================================================================
  FUNCTION:  dsi_init_ex
===========================================================================*/
/** @ingroup dsi_init_ex

    Initializes the DSI_NetCtrl library for the specified operating mode and
    executes a callback function with the callback data,
    given as an argument after completing init.

    This function must be invoked once per process, typically on process
    startup.

    @note1hang
    Only DSI_MODE_GENERAL is to be used by applications.

    param [in] init mode
    param [in] dsi_init_cb_func
    param [in] dsi_init_cb_data

    @return
    DSI_SUCCESS -- Initialization was successful.
    DSI_ERROR -- Initialization failed.

    @dependencies
    None.
*/
/*=========================================================================*/
extern int dsi_init_ex
(
  int mode,
  void (* dsi_init_cb_func)( void * ),
  void *dsi_init_cb_data
);

/*===========================================================================
  FUNCTION:  dsi_init_ex2
===========================================================================*/
/** @ingroup dsi_init_ex2

    Initializes the DSI_NetCtrl library for the specified operating mode and
    executes a callback function with the callback data,
    given as an argument after completing init.

    This function must be invoked once per process, typically on process
    startup.

    param [in] init mode
    param [in] dsi_init_cb_func_ex2
    param [in] dsi_init_cb_data

    @return
    DSI_SUCCESS -- Initialization was successful.
    DSI_ERROR -- Initialization failed.

    @dependencies
    None.
*/
/*=========================================================================*/
extern int dsi_init_ex2
(
  dsi_init_mode_t      mode,
  dsi_init_cb_func_ex2 cb_func,
  void                 *dsi_init_cb_data
);

/*===========================================================================
  FUNCTION:  dsi_release
===========================================================================*/
/** @ingroup dsi_release

    Clean-up the DSI_NetCtrl library.

    @return
    DSI_SUCCESS -- Cleanup was successful. \n
    DSI_ERROR -- Cleanup failed.

    @dependencies
    None.
*/
/*=========================================================================*/
extern int dsi_release(int mode);

/*===========================================================================
  FUNCTION:  dsi_release_ex
===========================================================================*/
/** @ingroup dsi_release_ex

    Clean-up the DSI_NetCtrl library for the given mode

    @return
    DSI_SUCCESS -- Cleanup was successful. \n
    DSI_ERROR -- Cleanup failed.

    @dependencies
    None.
*/
/*=========================================================================*/
extern int dsi_release_ex(dsi_init_mode_t mode);

/*===========================================================================
  FUNCTION:  dsi_get_data_srvc_hndl
===========================================================================*/
/** @ingroup dsi_get_data_srvc_hndl

    Gets an opaque data service handle. All subsequent functions use this
    handle as an input parameter.

    @note1hang
    The DSI_NetCtrl library waits for initialization from the lower layers
    (QMI ports being opened, the RmNet interfaces being available, etc.) to
    support data services functionality. During initial bootup scenarios,
    these dependencies may not be available, which will cause
    dsi_get_data_srvc_hndl to return an error. In such cases, clients are
    asked to retry this function call repeatedly using a 500 ms timeout
    interval. Once a non-NULL handle is returned, clients can exit out of
    the delayed retry loop.

    @param[in] cb_fn Client callback function used to post event indications.
                     Refer to Section 3.2.3 for the function prototype.
    @param[in] user_data Pointer to the client context block (cookie). The
                         value may be NULL.

    @return
    dsi_hndl_t if successfull, NULL otherwise.

    @dependencies
    dsi_init() must be called.
*/
/*=========================================================================*/
extern dsi_hndl_t dsi_get_data_srvc_hndl
(
  dsi_net_ev_cb cb_fn,
  void * user_data
);
/*===========================================================================
  FUNCTION:  dsi_get_data_srvc_hndl_ex
===========================================================================*/
/** @ingroup dsi_get_data_srvc_hndl_ex

    Gets an opaque data service handle. All subsequent functions use this
    handle as an input parameter.

    @note1hang
    The DSI_NetCtrl library waits for initialization from the lower layers
    (QMI ports being opened, the RmNet interfaces being available, etc.) to
    support data services functionality. During initial bootup scenarios,
    these dependencies may not be available, which will cause
    dsi_get_data_srvc_hndl_ex to return an error. In such cases, clients
    are asked to retry this function call repeatedly using a 500 ms timeout
    interval. Once a non-NULL handle is returned, clients can exit out of
    the delayed retry loop.

    @param [in] user_cb_fn - Client callback function used to post event
                             indications.
    @param [in] mode       - The mode the client wants to use for bringing
                             up the call.
    @param [in] user_data  - Pointer to the client context block (cookie)
                             The value may be NULL.

    @return
    dsi_hndl_t if successfull, NULL otherwise.

    @dependencies
    dsi_init_ex2() must be called.
*/
/*=========================================================================*/
extern dsi_hndl_t dsi_get_data_srvc_hndl_ex
(
  dsi_net_ev_cb_ex user_cb_fn,
  dsi_init_mode_t  mode,
  void             *user_data
);

/*===========================================================================
  FUNCTION:  dsi_rel_data_srvc_hndl
===========================================================================*/
/** @ingroup dsi_rel_data_srvc_hndl

    Releases a data service handle. All resources associated with the
    library are released.

    @note1hang
    If the user starts an interface with this handle,
    the corresponding interface is stopped before the DSI
    hndl is released.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().

    @return
    None.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl().
*/
/*=========================================================================*/
extern void dsi_rel_data_srvc_hndl(dsi_hndl_t hndl);

/*===========================================================================
  FUNCTION:  dsi_rel_data_srvc_hndl_ex
===========================================================================*/
/** @ingroup dsi_rel_data_srvc_hndl_ex

    Releases a data service handle. All resources associated with the
    library are released.

    @note1hang
    If the user starts an interface with this handle,
    the corresponding interface is stopped before the DSI
    hndl is released.

    @param[in] mode
    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().

    @return
    None.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl().
*/
/*=========================================================================*/
extern void dsi_rel_data_srvc_hndl_ex(dsi_hndl_t hndl);

/*===========================================================================
  FUNCTION: dsi_ind_registration
===========================================================================*/
/*!
  @brief
  This function can be used to register/unregister for WDS handoff
  indications

  @return
  DSI_SUCCESS
  DSI_FAILURE

  @note
  This function must be called only after SNI is done and we have
  an iface association. The WDS client binding will happen only at
  that point in time
*/
/*=========================================================================*/
int dsi_ind_registration
(
  dsi_hndl_t              hndl,
  dsi_ind_reg_type        ind_type,
  dsi_ind_registration_t  reg_unreg
);

/*===========================================================================
  FUNCTION:  dsi_start_data_call
===========================================================================*/
/** @ingroup dsi_start_data_call

    Starts a data call.

    An immediate call return value indicates whether the request was sent
    successfully. The client receives asynchronous notfications via a callback
    registered with dsi_get_data_srvc_hndl() indicating the data call bring-up
    status.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().

    @return
    DSI_SUCCESS -- The data call start request was sent successfully. \n
    DSI_ERROR -- The data call start request was unsuccessful.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl().
*/
/*=========================================================================*/
extern int dsi_start_data_call(dsi_hndl_t hndl);

/*===========================================================================
  FUNCTION:  dsi_start_data_call_ex
===========================================================================*/
/** @ingroup dsi_start_data_call_ex
    Starts a data call

    An immediate call return value indicates whether the request was sent
    successfully. The client receives asynchronous notfications via a
    callback registered with dsi_get_data_srvc_hndl() indicating the data
    call bring-up status.

    @param [in] hndl       - Handle received from dsi_get_data_srvc_hndl_ex()
    @param [in] num_params - Number of call parameters
    @param [in] params     - array of call params

    @return
    DSI_SUCCESS -- The data call start request was sent successfully. \n
    DSI_ERROR -- The data call start request was unsuccessful.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl_ex()
*/
/*=========================================================================*/
extern int dsi_start_data_call_ex
(
  dsi_hndl_t             hndl,
  int                    num_params,  /* Number of params */
  dsi_call_param_info_t  *params      /* Array of call params */
);
/*===========================================================================
  FUNCTION:  dsi_stop_data_call
===========================================================================*/
/** @ingroup dsi_stop_data_call

    Stops a data call.

    An immediate call return value indicates whether the request was sent
    successfully. The client receives asynchronous notification via a callback
    registered with dsi_get_data_srvc_hndl() indicating the data call tear-down
    status.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().

    @return
    DSI_SUCCESS -- The data call stop request was sent successfully. \n
    DSI_ERROR -- The data call stop request was unsuccessful.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl(). \n
    The call must have been brought up using dsi_start_data_call().
*/
/*=========================================================================*/
extern int dsi_stop_data_call(dsi_hndl_t hndl);
/*===========================================================================
  FUNCTION:  dsi_set_data_call_param
===========================================================================*/
/** @ingroup dsi_set_data_call_param

    Sets the data call parameter before trying to start a data call.

    Clients may call this function multiple times with various types of
    parameters to be set.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().
    @param[in] identifier Identifies the type of the third input parameter.
    @param[in] info Parameter value that is to be set.

    @return
    DSI_SUCCESS -- The data call parameter was set successfully. \n
    DSI_ERROR -- The data call parameter was not set successfully.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl().
*/
/*=========================================================================*/
extern int dsi_set_data_call_param
(
  dsi_hndl_t hndl,
  dsi_call_param_identifier_t identifier,
  dsi_call_param_value_t *info
);

/*===========================================================================
  FUNCTION:  dsi_get_device_name
===========================================================================*/
/** @ingroup dsi_get_device_name

    Queries the data interface name for the data call associated with the
    specified data service handle.

    @note1hang
    len must be at least DSI_CALL_INFO_DEVICE_NAME_MAX_LEN + 1 long.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().
    @param[out] buf Buffer to hold the data interface name string.
    @param[in] len Length of the buffer allocated by client.

    @return
    DSI_SUCCESS -- The data interface name was returned successfully. \n
    DSI_ERROR -- The data interface name was not returned successfully.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl().
*/
/*=========================================================================*/
extern int dsi_get_device_name(dsi_hndl_t hndl, char * buf, int len);

/*===========================================================================
  FUNCTION:  dsi_get_call_end_reason
===========================================================================*/
/** @ingroup dsi_get_call_end_reason

    Queries for the reason for a call being ended.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().
    @param[out] ce_reason Structure to hold the fields of the call ending
                           reason.
    @param[in] ipf IP family for which the call end reason was requested.

    @return
    DSI_SUCCESS -- The call end reason was queried successfully. \n
    DSI_ERROR -- The call end reason query was unsuccessful.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl().
*/
/*=========================================================================*/
extern int dsi_get_call_end_reason
(
  dsi_hndl_t hndl,
  dsi_ce_reason_t * ce_reason,
  dsi_ip_family_t ipf
);

/*===========================================================================
  FUNCTION:  dsi_get_call_tech
===========================================================================*/
/** @ingroup dsi_get_call_tech

    Gets the techcology on which the call was brought up. This function can
    be called any time after the client receives the DSI_EVT_NET_IS_CONN event
    and before the client releases the dsi handle.

    On successful return, the call_tech parameter is set to a valid call
    technology.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().
    @param[out] call_tech Pointer to the buffer containing the call
                           technology.

    @return
    DSI_SUCCESS -- The call bring-up technology was queried successfully. \n
    DSI_ERROR -- The call bring-up technology query was unsuccessful.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl().
*/
/*=========================================================================*/
extern int dsi_get_call_tech
(
  dsi_hndl_t hndl,
  dsi_call_tech_type *call_tech
);

/*===========================================================================
  FUNCTION:  dsi_get_ip_addr_count
===========================================================================*/
/** @ingroup dsi_get_ip_addr_count

    Gets the number of IP addresses (IPv4 and global IPv6) associated with
    the DSI interface.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().

    @return
    The number of IP addresses associated with the DSI.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl()
*/
/*=========================================================================*/
extern unsigned int dsi_get_ip_addr_count
(
  dsi_hndl_t hndl
);

/*===========================================================================
  FUNCTION:  dsi_get_ip_addr
===========================================================================*/
/** @ingroup dsi_get_ip_addr

    Gets the IP address information structure (network order).

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().
    @param[out] info_ptr Pointer to the buffer containing the network order
                          information.
    @param[in] len Length of the network order information.

    @return
    DSI_SUCCESS -- The network order query was successful. \n
    DSI_ERROR -- The network order query was unsuccessful.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl(). \n
    The length parameter can be obtained by calling dsi_get_ip_addr_count(). \n
    It is assumed that the client has allocated memory for enough structures
    specified by the len field.
*/
/*=========================================================================*/
extern int dsi_get_ip_addr
(
  dsi_hndl_t hndl,
  dsi_addr_info_t * info_ptr,
  int len
);

/*===========================================================================
  FUNCTION  dsi_get_ip_version
===========================================================================*/
/*!
@brief
  Retrieve ip_version from dsi_hndl

@return
  int - DSI_IP_VERSION_4    if ip_version is V4,
        DSI_IP_VERSION_6    if ip_version is V6,
        DSI_IP_VERSION_4_6  if ip_version is V4V6,
        DSI_ERROR           if handle is not valid
*/
/*=========================================================================*/
int dsi_get_ip_version(dsi_hndl_t hndl);

/*===========================================================================
  FUNCTION:  dsi_iface_ioctl
===========================================================================*/
/*!
    @brief
    This function is in interface to get IOCTL values.

    @param[in] dsi_hndl Handle received from dsi_get_data_srvc_hndl().
    @param[in] one of the dsi_iface_ioctl_enum_t values.
    @param[out] argval_ptr Pointer to the buffer containing information.
                      for the requested ioctl.
    @param[out] dsi_err Valid only if the return values is DSI_ERROR.
                Will take one of the following values DSI_ERROR_HNDL_INVALID
                                                      DSI_ERROR_IOCTL_INVALID
                                                      DSI_ERROR_INTERNAL
    @return
    DSI_ERROR
    DSI_SUCCESS
*/
/*=========================================================================*/
extern int dsi_iface_ioctl
(
  dsi_hndl_t dsi_hndl,
  dsi_iface_ioctl_enum_t ioctl_name,
  void *argval_ptr,
  int  *err_code
);

/*===========================================================================
  FUNCTION:  dsi_enable_port_forwarding
===========================================================================*/
/*!
    @brief
    This function can be used to enable port forwarding by installing
    the iptable rules appropriately. If no IWLAN calls are active then
    the client preference is saved and rules are installed on bring up
    of the first IWLAN call.

    @param[in] dsi_hndl Handle received from dsi_get_data_srvc_hndl().
    @param[in] ip_family - AF_INET/AF_INET6

    @return
    DSI_ERROR
    DSI_SUCCESS

    @dependencies
    There has to be at least one iwlan call up for the specified family
    for the API to take effect.
*/
/*=========================================================================*/
extern int dsi_enable_port_forwarding
(
   dsi_hndl_t dsi_hndl,
   int        ip_family
);

/*===========================================================================
  FUNCTION:  dsi_disable_port_forwarding
===========================================================================*/
/*!
    @brief
    This function can be used to disable port forwarding by uninstalling
    the iptable rules appropriately. If no IWLAN calls are active then
    the client preference is saved and rules will not be installed on
    bring up of the first IWLAN call.

    @param[in] dsi_hndl Handle received from dsi_get_data_srvc_hndl().
    @param[in] ip_family - AF_INET/AF_INET6

    @return
    DSI_ERROR
    DSI_SUCCESS
*/
/*=========================================================================*/
extern int dsi_disable_port_forwarding
(
   dsi_hndl_t dsi_hndl,
   int        ip_family
);

/*===========================================================================
  FUNCTION:  dsi_query_port_forwarding
===========================================================================*/
/*!
    @brief
    This function can be used to query the current port forwarding preference
    set by the client.

    @param[in] dsi_hndl Handle received from dsi_get_data_srvc_hndl().
    @param[in] ip_family - AF_INET/AF_INET6
    @param[out] forwarding_status return the current port forwarding status.

    @return
    DSI_ERROR
    DSI_SUCCESS
*/
/*=========================================================================*/
extern int dsi_query_port_forwarding_status
(
   dsi_hndl_t                    dsi_hndl,
   int                           ip_family,
   dsi_port_forwarding_status_t* forwarding_status
);


/*===========================================================================
  FUNCTION:  dsi_embms_enable
===========================================================================*/
/*!
    @brief
    This function can be used to start an EMBMS data call.

    @return
    DSI_ERROR
    DSI_SUCCESS
*/
/*=========================================================================*/
extern int dsi_embms_enable(dsi_hndl_t hndl);

/*===========================================================================
  FUNCTION:  dsi_embms_tmgi_activate
===========================================================================*/
/*!
    @brief
    This function can be used to activate TMGI on EMBMS data call.

    @return
    DSI_ERROR
    DSI_SUCCESS
*/
/*=========================================================================*/
extern int dsi_embms_tmgi_activate
(
   dsi_hndl_t                          hndl,
   char                               *tmgi,
   unsigned int                       *earfcnlist,
   unsigned char                       earfcnlist_len,
   unsigned long                       preemption_priority,
   unsigned int                       *sailist,
   unsigned char                       sailist_len,
   int                                 dbg_trace_id
);

/*===========================================================================
  FUNCTION:  dsi_embms_tmgi_deactivate
===========================================================================*/
/*!
    @brief
    This function can be used to deactivate TMGI on EMBMS data call.

    @return
    DSI_ERROR
    DSI_SUCCESS
*/
/*=========================================================================*/
extern int dsi_embms_tmgi_deactivate
(
   dsi_hndl_t                          hndl,
   char                               *tmgi,
   int                                 dbg_trace_id
);
/*===========================================================================
  FUNCTION:  dsi_embms_tmgi_activate_deactivate
===========================================================================*/
/*!
    @brief
    This function can be used to both activate TMGI and deactivate TMGI on
    EMBMS data call.

    TMGI to be activated must be different than TMGI to be deactivated

    @return
    DSI_ERROR
    DSI_SUCCESS
*/
/*=========================================================================*/
extern int dsi_embms_tmgi_activate_deactivate
(
  dsi_hndl_t                          hndl,
  char                               *activate_tmgi,
  unsigned int                       *earfcnlist,
  unsigned char                       earfcnlist_len,
  unsigned long                       preemption_priority,
  char                               *deactivate_tmgi,
  unsigned int                       *sailist,
  unsigned char                       sailist_len,
  int                                 dbg_trace_id
);

/*===========================================================================
  FUNCTION:  dsi_get_embms_tmgi_deactivate_reason
===========================================================================*/
/*!
    @brief
    used to get tmgi deactivated reason.

    @return
    DSI_ERROR
    DSI_SUCCESS

*/
/*=========================================================================*/
extern int dsi_embms_get_tmgi_deactivate_reason
(
  dsi_hndl_t                                hndl,
  dsi_embms_tmgi_status_field_type          status_field,
  int                                      *dsi_tmgi_deactivate_reason_ptr
);

/*===========================================================================
  FUNCTION:  dsi_embms_tmgi_list_query
===========================================================================*/
/*!
    @brief
    used to query TMGI list(active or available).

    @return
    DSI_ERROR
    DSI_SUCCESS

*/
/*=========================================================================*/
extern int dsi_embms_tmgi_list_query
(
  dsi_hndl_t                               hndl,
  wds_embms_tmgi_list_type_enum_v01        embms_tmgi_list_query,
  wds_embms_tmgi_list_query_resp_msg_v01  *list_info,
  int                                      dbg_trace_id
);

/*===========================================================================
  FUNCTION:  dsi_embms_content_desc_update
===========================================================================*/
/*!
    @brief
    used to update embms content desc.

    @return
    DSI_ERROR
    DSI_SUCCESS

*/
/*=========================================================================*/
int dsi_embms_content_desc_update
(
  dsi_hndl_t                hndl,
  char                     *content_desc_update_tmgi,
  unsigned char             content_desc_valid,
  unsigned int              content_desc_len,
  dsi_embms_content_desc_type  *content_desc,
  int                       dbg_trace_id
);

/*===========================================================================
  FUNCTION:  dsi_embms_svc_interest_list
===========================================================================*/
/*!
    @brief
    used to send embms service interest info.

    @return
    DSI_ERROR
    DSI_SUCCESS

*/
/*=========================================================================*/
int dsi_embms_svc_interest_list
(
  dsi_hndl_t                hndl,
  char                    **svc_interest_tmgi_list,
  unsigned int              svc_interest_tmgi_list_len,
  int                       dbg_trace_id
);

/*===========================================================================
  FUNTION:   dsi_get_current_data_channel_rate
===========================================================================*/
/*!
    @brief
    Returns the current channel rate of the call

    @param
    hndl - dsi interface handle

    @return
    DSI_ERROR
    DSI_SUCCESS

*/
/*=========================================================================*/
int dsi_get_current_data_channel_rate
(
  dsi_hndl_t               hndl,
  dsi_data_channel_rate_t *data_rate
);

/*===========================================================================
  FUNCTION:  dsi_get_current_data_bearer_tech
===========================================================================*/
/** @ingroup dsi_get_current_data_bearer_tech

    Returns the current data bearer technology on which a call was brought up.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().

    @return
    The data bearer technology.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl().
*/
/*=========================================================================*/
dsi_data_bearer_tech_t
dsi_get_current_data_bearer_tech
(
  dsi_hndl_t hndl
);

/*===========================================================================
  FUNCTION:  dsi_reset_pkt_stats
===========================================================================*/
/** @ingroup dsi_reset_pkt_stats

    Resets the packet data transfer statistics.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().

    @return
    DSI_SUCCESS -- The packet data transfer statistics were reset successfully. \n
    DSI_ERROR -- The packet data transfer statistics reset was unsuccessful.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl().
*/
/*=========================================================================*/
extern int
dsi_reset_pkt_stats
(
  dsi_hndl_t  hndl
);


/*===========================================================================
  FUNCTION:  dsi_get_pkt_stats
===========================================================================*/
/** @ingroup dsi_get_pkt_stats

    Queries the packet data transfer statistics from the current packet
    data session.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().
    @param[in] dsi_data_stats Memory to hold the queried statistics details.

    @return
    DSI_SUCCESS -- The packet data transfer statistics were queried successfully. \n
    DSI_ERROR -- The packet data transfer statistics query was unsuccessful.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl()
*/
/*=========================================================================*/
extern int
dsi_get_pkt_stats
(
  dsi_hndl_t          hndl,
  dsi_data_pkt_stats *dsi_data_stats
);

/* These error codes should never overlap with EAI_*** codes */
#define DSI_ERROR_BAD_HANDLE -100
#define DSI_NO_DNS_RESOLVER  -101
#define DSI_DNS_ERROR        -102

/*===========================================================================
  FUNCTION:  dsi_get_qmi_port_name
===========================================================================*/
/** @ingroup dsi_get_qmi_port_name

    Queries the QMI port name for the data call associated with the
    specified data service handle.

    @note1hang
    len must be at least DSI_CALL_INFO_DEVICE_NAME_MAX_LEN + 1 long.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().
    @param[out] buf Buffer to hold the QMI port name string.
    @param[in] len Length of the buffer allocated by client.

    @return
    DSI_SUCCESS -- The data interface name was returned successfully. \n
    DSI_ERROR -- The data interface name was not returned successfully.

    @dependencies
    dsi_init() must be called. \n
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl().
*/
/*=========================================================================*/
extern int dsi_get_qmi_port_name(dsi_hndl_t hndl, char * buf, int len);

/*===========================================================================
  FUNCTION:  dsi_process_screen_state_change
===========================================================================*/
/** @ingroup dsi_process_screen_state_change

    Performs any optimization processing when the screen state is turned off.

    @param[in] screen_state Screen state. 0 - OFF, 1 - ON

    @return
    DSI_SUCCESS -- The API returned success.
    DSI_ERROR -- The API returned failure.

    @dependencies
    dsi_init() must be called.
*/
/*=========================================================================*/
extern int dsi_process_screen_state_change(int screen_state);

/*===========================================================================
  FUNCTION:  dsi_get_link_mtu
===========================================================================*/
/*!
    @brief
    Used to get the MTU of the corresponding link

    @return
    DSI_ERROR
    DSI_SUCCESS

*/
/*=========================================================================*/
extern int dsi_get_link_mtu
(
  dsi_hndl_t    hndl,
  unsigned int  *mtu
);

/*==========================================================================
   FUNCTION:  dsi_set_modem_subs_id
===========================================================================*/
/*!
   @brief
    Sets the modem subscription id for the dsi_netctrl library. Used in
    Multi SIM targets targets for binding the subscription.

   @param
    subs_id - subscription ID the process is intrested in

   @dependencies
   Needs to be called prior to dsi_init()

   @return
   DSI_ERROR
   DSI_SUCCESS
*/
/*=========================================================================*/
extern int dsi_set_modem_subs_id(int subs_id);

/*===========================================================================
  FUNCTION: dsi_update_data_session_keep_alive
===========================================================================*/
/*!
  @brief
  This function can be used to request the modem to keep the data session
  alive corresponding to the given dsi handle

  @return
  DSI_SUCCESS
  DSI_FAILURE

  @note
  A valid call must have been brought up using dsi_start_data_call() on hndl
*/
/*=========================================================================*/
extern int dsi_update_data_session_keep_alive
(
  dsi_hndl_t              hndl,
  dsi_keep_alive_t        keep_alive
);

/*===========================================================================
  FUNCTION:  dsi_v2x_request
===========================================================================*/
/** @ingroup dsi_v2x_request
*/
/*=========================================================================*/
extern int dsi_v2x_request
(
  dsi_hndl_t dsi_hndl,
  dsi_v2x_req_t req_type,
  void *req_info,
  void *resp_info
);

/*===========================================================================
  FUNCTION: dsi_v2x_isolate_core
===========================================================================*/
/**
  Client DSI API to query netmgr to reserve a core for V2X applications

  @param [in] dsi_hndl       - Handle provided to client for DSI operations
  @param [in] interface_name - The name of the interface for which ID is
                               sought
  @return
  DSI_SUCCESS - If core isolation succeeds
  DSI_ERROR   - If a netmgr is unable to perform the isolation or some other
                internal error occurs.

  @dependencies
  - Client should have initialized with DSI using dsi_init_ex2 with low-latency
    mode
  - Client should have requested for a DSI handle using
    dsi_get_data_srvc_hndl_ex
*/
/*=========================================================================*/
extern int dsi_v2x_isolate_core
(
  dsi_hndl_t dsi_hndl,
  pid_t      pid,
  bool       need_isolation,
  void *     opt_params
);

/*===========================================================================
  FUNCTION: dsi_get_interface_identifier_internal
===========================================================================*/
/**
  Internal DSI API to return the interface ID associated with the interface
  name. This interface ID will be used for any additional control path
  communications directly from the client

  @param [in] dsi_hndl       - Handle provided to client for DSI operations
  @param [in] interface_name - The name of the interface for which ID is
                               sought
  @param [out] interface_id  - The interface ID if a valid ID exists
                               -1 otherwise

  @return
  DSI_SUCCESS - If a valid ID exists
  DSI_ERROR   - If a valid ID does not exist or other errors are encountered
                while looking up the ID

  @dependencies
  - Client should have initialized with DSI using dsi_init_ex2 with low-latency
    mode
  - Client should have requested for a DSI handle using
    dsi_get_data_srvc_hndl_ex
*/
/*=========================================================================*/
extern int dsi_get_interface_identifier_internal
(
  dsi_hndl_t dsi_hndl,
  char       *interface_name,
  int        *interface_id
);
/*===========================================================================
  FUNCTION    dsi_set_powersave_filter_mode
===========================================================================*/
/*!
@brief
  API called by client to enable powersave and auto exit mode for
  a particular dsi_hndl

@return
  int - DSI_SUCCESS on successful operation,
        DSI_ERROR if there was an error,
        DSI_SERVICE_NOT_UP if DFS service is not up
*/
/*=========================================================================*/

extern int dsi_set_powersave_filter_mode
(
  dsi_hndl_t    hndl,
  uint8_t       enable_powersave,
  uint8_t       autoexit
);

/*===========================================================================
  FUNCTION    dsi_add_powersave_filters
===========================================================================*/
/*!
@brief
  API called by client to install filters for a particular dsi_hndl

@return
  int - DSI_SUCCESS on successful operation,
        DSI_ERROR if there was any DSI error
        DSI_SERVICE_NOT_UP if dfs service is not up
*/
/*=========================================================================*/

extern int dsi_add_powersave_filters
(
  dsi_hndl_t          hndl,
  int                 no_filter,
  dsi_ip_filter_info *filter_info
);

/*===========================================================================
  FUNCTION    dsi_remove_all_powersave_filters
===========================================================================*/
/*!
@brief
  API called by clients to remove all filters for a particular dsi_hndl

@return
  int - DSI_SUCCESS on successful operation,
        DSI_ERROR if there was an error
        DSI_SERVICE_NOT_UP if DFS service is not up

*/
/*=========================================================================*/

extern int dsi_remove_all_powersave_filters
(
  dsi_hndl_t hndl
);

/*===========================================================================
  FUNCTION    dsi_set_global_powersave_filter_mode
===========================================================================*/
/*!
@brief
  API called by client to enable powersave and auto exit mode for
  all pdn in UP state.
  This API will apply to all up/active PDNs brought up using DSI APIs
  on the same host

@return
  int - DSI_SUCCESS on successful operation,
        DSI_ERROR if there was an error,
        DSI_SERVICE_NOT_UP if DFS service is not up
*/
/*=========================================================================*/

extern int dsi_set_global_powersave_filter_mode
(
  dsi_hndl_t hndl,
  uint8_t    enable_powersave,
  uint8_t    autoexit
);

/*===========================================================================
  FUNCTION    dsi_add_global_powersave_filters
===========================================================================*/
/*!
@brief
  API called by client to install filters for all pdn in UP state.
  This API will apply to all up/active PDNs brought up using DSI APIs
  on the same host
@return
  int - DSI_SUCCESS on successful operation,
        DSI_ERROR if there was any DSI error
        DSI_SERVICE_NOT_UP if dfs service is not up
*/
/*=========================================================================*/

extern int dsi_add_global_powersave_filters
(
  dsi_hndl_t            hndl,
  int                   no_filter,
  dsi_ip_filter_info   *filter_info
);

/*===========================================================================
  FUNCTION    dsi_remove_global_powersave_filters
===========================================================================*/
/*!
@brief
  API called by clients to remove all filters for all pdn in UP State.
  This API will apply to all up/active PDNs brought up using DSI APIs
  on the same host

@return
  int - DSI_SUCCESS on successful operation,
        DSI_ERROR if there was an error
        DSI_SERVICE_NOT_UP if DFS service is not up

*/
/*=========================================================================*/

extern int dsi_remove_global_powersave_filters
(
  dsi_hndl_t hndl
);

/*===========================================================================
  FUNCTION    dsi_get_powersave_filter_mode
===========================================================================*/
/** @ingroup dsi_get_powersave_filter_mode

    Queries the power save mode state specifying the data interface name
    for the data call associated.

    @note1
    len must be at least DSI_CALL_INFO_DEVICE_NAME_MAX_LEN + 1 long.

    @param[in] hndl Handle received from dsi_get_data_srvc_hndl().
    @param[in] intf_name Buffer to hold the data interface name string.
    @param[in] intf_len Length of the buffer allocated by client.
    @param[out] powersave_mode  for this interface if it is in UP state.

    @return
    DSI_SUCCESS(0) -- if interface is UP and powersave_mode will be valid.
    DSI_ERROR (-1) -- for any failure.

    @dependencies
    dsi_init() must be called.
    The handle must be a valid handle obtained by dsi_get_data_srvc_hndl().
*/

/*=========================================================================*/

extern int  dsi_get_powersave_filter_mode
(
  dsi_hndl_t hndl,
  char *     intf_name,
  int        intf_len,
  uint8_t   *powersave_mode
);
#endif /* DSI_NETCTRL_H */
#ifdef __cplusplus
}
#endif

