#ifndef QCMAP_MSGR_SERVICE_01_H
#define QCMAP_MSGR_SERVICE_01_H
/**
  @file qualcomm_mobile_access_point_msgr_v01.h

  @brief This is the public header file which defines the qcmap_msgr service Data structures.

  This header file defines the types and structures that were defined in
  qcmap_msgr. It contains the constant values defined, enums, structures,
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
  Copyright (c) 2012-2020 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.



  $Header: //source/qcom/qct/interfaces/qmi/rel/deploy/qcmap_msgr/api/qualcomm_mobile_access_point_msgr_v01.h#12 $
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.9
   It was generated on: Thu Apr  9 2020 (Spin 0)
   From IDL File: qualcomm_mobile_access_point_msgr_v01.idl */

/** @defgroup qcmap_msgr_qmi_consts Constant values defined in the IDL */
/** @defgroup qcmap_msgr_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup qcmap_msgr_qmi_enums Enumerated types used in QMI messages */
/** @defgroup qcmap_msgr_qmi_messages Structures sent as QMI messages */
/** @defgroup qcmap_msgr_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup qcmap_msgr_qmi_accessor Accessor for QMI service object */
/** @defgroup qcmap_msgr_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup qcmap_msgr_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define QCMAP_MSGR_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define QCMAP_MSGR_V01_IDL_MINOR_VERS 0x51
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define QCMAP_MSGR_V01_IDL_TOOL_VERS 0x06
/** Maximum Defined Message ID */
#define QCMAP_MSGR_V01_MAX_MESSAGE_ID 0x00F5
/**
    @}
  */


/** @addtogroup qcmap_msgr_qmi_consts
    @{
  */
#define QCMAP_MSGR_MAX_SNAT_ENTRIES_V01 50
#define QCMAP_MSGR_MAX_FIREWALL_ENTRIES_V01 50
#define QCMAP_MSGR_IPV6_ADDR_LEN_V01 16
#define QCMAP_MSGR_MAX_DLNA_DIR_LEN_V01 1000
#define QCMAP_MSGR_MAC_ADDR_LEN_V01 6
#define QCMAP_MSGR_DEVICE_NAME_MAX_V01 100
#define QCMAP_MSGR_MAX_DHCP_RESERVATION_ENTRIES_V01 20
#define QCMAP_MSGR_MAC_ADDR_NUM_CHARS_V01 18
#define QCMAP_MSGR_PCSCF_FQDN_MAX_LENGTH_V01 100
#define QCMAP_MSGR_MAX_SIP_SERVER_ENTRIES_V01 25
#define QCMAP_MSGR_MAX_CONNECTED_DEVICES_V01 40
#define QCMAP_MSGR_MAX_GATEWAY_URL_V01 300
#define QCMAP_MSGR_MAX_DDNS_SERVER_ENTRIES_V01 10
#define QCMAP_MSGR_DDNS_HOSTNAME_LENGTH_V01 100
#define QCMAP_MSGR_DDNS_LOGIN_LENGTH_V01 20
#define QCMAP_MSGR_DDNS_PASSWORD_LENGTH_V01 20
#define QCMAP_MSGR_DDNS_URL_LENGTH_V01 200
#define QCMAP_MSGR_MAX_WLAN_IFACE_V01 5
#define QCMAP_MSGR_MAX_GUEST_AP_COUNT_V01 3
#define QCMAP_MSGR_MAX_IPV6_ADDR_V01 6
#define QCMAP_MAX_IFACE_NAME_SIZE_V01 16
#define QCMAP_MAX_NUM_BACKHAULS_V01 50
#define QCMAP_SOCKSV5_MAX_UNAME_PASSWD_LEN_V01 255
#define QCMAP_SOCKSV5_NO_AUTHENTICATION_V01 0
#define QCMAP_SOCKSV5_UNAME_PASSWD_V01 2
#define QCMAP_SOCKSV5_NO_ACCEPTABLE_V01 255
#define QCMAP_SOCKSV5_MAX_FILE_PATH_LEN_V01 100
#define QCMAP_MSGR_MAX_VLAN_ENTRIES_V01 2000
#define QCMAP_MSGR_MAX_L2TP_FILE_NAME_LENGTH_V01 100
#define QCMAP_MSGR_L2TP_MAX_SESSION_PER_TUNNEL_V01 3
#define QCMAP_MSGR_L2TP_MAX_TUNNELS_V01 2
#define QCMAP_MSGR_MAX_IF_SUPPORTED_V01 32
#define QCMAP_MSGR_PMIP_SERVICE_SELECTION_STRING_LENGTH_V01 255
#define QCMAP_MSGR_PMIP_MN_ID_STRING_LENGTH_V01 255
#define QCMAP_MAX_IPV6_ADDRSTRLEN_V01 46
#define QCMAP_MSGR_V2X_NON_SPS_MAX_FLOWS_V01 255
#define QMI_QCMAP_MSGR_V2X_MAX_SUB_V01 255
#define QMI_QCMAP_MSGR_V2X_CONFIG_FILE_NAME_LEN_MAX_V01 512
#define QMI_QCMAP_MSGR_V2X_INFO_LIST_MAX_V01 50
#define QMI_QCMAP_MSGR_V2X_PERIODICITY_LIST_MAX_V01 20
#define QMI_QCMAP_MSGR_V2X_POOL_ID_LIST_MAX_V01 20
#define QMI_QCMAP_MSGR_V2X_PPPP_LIST_MAX_V01 16
#define QCMAP_MAX_ETH_PORTS_V01 4
/**
    @}
  */

   /* Typedefs */

typedef uint32_t profile_handle_type_v01;

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_GUEST_AP_INDEX_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_GUEST_AP_ONE_V01 = 0x00, /**<  Guest AP 1 index  */
  QCMAP_MSGR_GUEST_AP_TWO_V01 = 0x01, /**<  Guest AP 2 index   */
  QCMAP_MSGR_GUEST_AP_THREE_V01 = 0x02, /**<  Guest AP 3 index   */
  QCMAP_MSGR_GUEST_AP_INDEX_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_guest_ap_index_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_WLAN_IFACE_INDEX_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_WLAN_IFACE_PRIMARY_AP_V01 = 0x00, /**<  Primary AP IFACE  */
  QCMAP_MSGR_WLAN_IFACE_GUEST_AP_ONE_V01 = 0x01, /**<  Guest AP IFACE  */
  QCMAP_MSGR_WLAN_IFACE_GUEST_AP_TWO_V01 = 0x02, /**<  Guest AP 2 IFACE  */
  QCMAP_MSGR_WLAN_IFACE_STATION_V01 = 0x03, /**<  Station IFACE  */
  QCMAP_MSGR_WLAN_IFACE_INDEX_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_wlan_iface_index_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_WLAN_IFACE_ACTIVE_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_WLAN_IFACE_INACTIVE_V01 = 0x00, /**<  IF is Inactive */
  QCMAP_MSGR_WLAN_IFACE_ACTIVE_V01 = 0x01, /**<  IF is Active  */
  QCMAP_MSGR_WLAN_IFACE_ACTIVE_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_wlan_iface_active_state_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_IP_FAMILY_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_IP_FAMILY_V4_V01 = 0x04, /**<  IPv4 version  */
  QCMAP_MSGR_IP_FAMILY_V6_V01 = 0x06, /**<  IPv6 version  */
  QCMAP_MSGR_IP_FAMILY_V4V6_V01 = 0x0A, /**<  Dual mode version  */
  QCMAP_MSGR_IP_FAMILY_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_ip_family_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_WWAN_CALL_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_WWAN_CALL_TYPE_V4_V01 = 0x01, /**<  IPv4 call  */
  QCMAP_MSGR_WWAN_CALL_TYPE_V6_V01 = 0x02, /**<  IPv6 call  */
  QCMAP_MSGR_WWAN_CALL_TYPE_V4V6_V01 = 0x03, /**<  Dual call IPv4 and IPv6  */
  QCMAP_MSGR_V2X_CALL_TYPE_V6_V01 = 0x04, /**<  V2X IPv6 call  */
  QCMAP_MSGR_WWAN_CALL_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_wwan_call_type_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_WWAN_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_WWAN_STATUS_CONNECTING_V01 = 0x01, /**<  IPv4 WWAN is in connecting state  */
  QCMAP_MSGR_WWAN_STATUS_CONNECTING_FAIL_V01 = 0x02, /**<  IPv4 connection to WWAN failed  */
  QCMAP_MSGR_WWAN_STATUS_CONNECTED_V01 = 0x03, /**<  IPv4 WWAN is in connected state  */
  QCMAP_MSGR_WWAN_STATUS_DISCONNECTING_V01 = 0x04, /**<  IPv4 WWAN is disconnecting  */
  QCMAP_MSGR_WWAN_STATUS_DISCONNECTING_FAIL_V01 = 0x05, /**<  IPv4 WWAN failed to disconnect  */
  QCMAP_MSGR_WWAN_STATUS_DISCONNECTED_V01 = 0x06, /**<  IPv4 WWAN is disconnected  */
  QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING_V01 = 0x07, /**<  IPv6 WWAN is in connecting state  */
  QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING_FAIL_V01 = 0x08, /**<  IPv6 connection to WWAN failed  */
  QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTED_V01 = 0x09, /**<  IPv6 WWAN is in connected state  */
  QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING_V01 = 0x0A, /**<  IPv6 WWAN is disconnecting  */
  QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING_FAIL_V01 = 0x0B, /**<  IPv6 WWAN failed to disconnect  */
  QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTED_V01 = 0x0C, /**<  IPv6 WWAN is disconnected  */
  QCMAP_MSGR_WWAN_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_wwan_status_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_MOBILE_AP_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_MOBILE_AP_STATUS_CONNECTED_V01 = 0x01, /**<  Mobile AP is connected  */
  QCMAP_MSGR_MOBILE_AP_STATUS_DISCONNECTED_V01 = 0x02, /**<  Mobile AP is disconnected  */
  QCMAP_MSGR_MOBILE_AP_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_mobile_ap_status_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_PACKET_STATS_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_PACKET_STATS_STATUS_ENABLED_V01 = 0x01, /**<  Packet Stats is Enabled  */
  QCMAP_MSGR_PACKET_STATS_STATUS_DISABLED_V01 = 0x02, /**<  Packet Stats is Disabled  */
  QCMAP_MSGR_PACKET_STATS_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_packet_stats_status_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_STATION_MODE_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_STATION_MODE_CONNECTED_V01 = 0x01, /**<  Station mode is connected  */
  QCMAP_MSGR_STATION_MODE_DISCONNECTED_V01 = 0x02, /**<  Station mode is disconnected  */
  QCMAP_MSGR_STATION_MODE_ASSOCIATION_FAIL_V01 = 0x03, /**<  Station is not able to associated with AP  */
  QCMAP_MSGR_STATION_MODE_DHCP_IP_ASSIGNMENT_FAIL_V01 = 0x04, /**<  Station is not able to get IP address via DHCP  */
  QCMAP_MSGR_STATION_MODE_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_station_mode_status_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_WLAN_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_WLAN_ENABLED_V01 = 0x01, /**<  WLAN is enabled  */
  QCMAP_MSGR_WLAN_DISABLED_V01 = 0x02, /**<  WLAN is disabled  */
  QCMAP_MSGR_WLAN_SWITCH_TO_2G_V01 = 0x03, /**<  WLAN switched to 2G  */
  QCMAP_MSGR_WLAN_SWITCH_TO_5G_V01 = 0x04, /**<  WLAN switched to 5G  */
  QCMAP_MSGR_WLAN_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_wlan_status_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_WLAN_IFACE_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_WLAN_CONNECTING_V01 = 0x1, /**<  Only valid for STATION iface. STATION is associated  */
  QCMAP_MSGR_WLAN_CONNECTED_V01 = 0x2, /**<  For STATION iface occurs when STA got IP.
       For AP occurs when Enabled  */
  QCMAP_MSGR_WLAN_DISCONNECTED_V01 = 0x3, /**<  For STATION iface occurs STATION is disassociated or disabled.
       For AP occurs when Disabled  */
  QCMAP_MSGR_WLAN_IFACE_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_wlan_iface_state_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_WLAN_IFACE_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_WLAN_IFACE_TYPE_AP_V01 = 0x1, /**<  Used when the interface is of AP type  */
  QCMAP_MSGR_WLAN_IFACE_TYPE_STA_V01 = 0x2, /**<  Used when the interface is of STA type  */
  QCMAP_MSGR_WLAN_IFACE_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_wlan_iface_type_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_CRADLE_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_CRADLE_DISCONNECTED_V01 = 0x01, /**<  Cradle is disconnected  */
  QCMAP_MSGR_CRADLE_CONNECTED_V01 = 0x02, /**<  Cradle is connected  */
  QCMAP_MSGR_CRADLE_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_cradle_status_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_NAT_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_NAT_SYMMETRIC_NAT_V01 = 0, /**<  NAT type is symmetric  */
  QCMAP_MSGR_NAT_PORT_RESTRICTED_CONE_NAT_V01 = 1, /**<  NAT type is Port-Restricted Cone NAT  */
  QCMAP_MSGR_NAT_FULL_CONE_NAT_V01 = 2, /**<  NAT type is Full Cone NAT  */
  QCMAP_MSGR_NAT_ADDRESS_RESTRICTED_NAT_V01 = 3, /**<  NAT type is Address-Restricted NAT  */
  QCMAP_MSGR_NAT_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_nat_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_NAT_TIMEOUT_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_NAT_TIMEOUT_GENERIC_V01 = 0x01, /**<   Generic NAT timeout  */
  QCMAP_MSGR_NAT_TIMEOUT_ICMP_V01 = 0x02, /**<   NAT timeout for ICMP  */
  QCMAP_MSGR_NAT_TIMEOUT_TCP_ESTABLISHED_V01 = 0x03, /**<   NAT timeout for the TCP established  */
  QCMAP_MSGR_NAT_TIMEOUT_UDP_V01 = 0x04, /**<   NAT timeout for UDP  */
  QCMAP_MSGR_NAT_TIMEOUT_UDP_STREAM_V01 = 0x05, /**<   NAT timeout for UDP stream  */
  QCMAP_MSGR_NAT_TIMEOUT_ICMPV6_V01 = 0x06, /**<   NAT timeout for ICMPv6  */
  QCMAP_MSGR_NAT_TIMEOUT_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_nat_timeout_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_WLAN_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_WLAN_MODE_AP_V01 = 0x01, /**<  WLAN is in AP mode  */
  QCMAP_MSGR_WLAN_MODE_AP_AP_V01 = 0x02, /**<  WLAN is in AP/AP Mode  */
  QCMAP_MSGR_WLAN_MODE_AP_STA_V01 = 0x03, /**<  WLAN is in AP/STA Mode  */
  QCMAP_MSGR_WLAN_MODE_AP_AP_AP_V01 = 0x04, /**<  WLAN is in AP/AP/AP Mode  */
  QCMAP_MSGR_WLAN_MODE_AP_AP_STA_V01 = 0x05, /**<  WLAN is in AP/AP/STA Mode  */
  QCMAP_MSGR_WLAN_MODE_STA_ONLY_V01 = 0x06, /**<  WLAN is in STA only Mode  */
  QCMAP_MSGR_WLAN_MODE_AP_AP_AP_AP_V01 = 0x07, /**<  WLAN is in AP-AP-AP-AP Mode  */
  QCMAP_MSGR_WLAN_MODE_AP_STA_BRIDGE_V01 = 0x08, /**<  WLAN is in AP/STA Bridge Mode
       Only used for GetWLANStatus  */
  QCMAP_MSGR_WLAN_MODE_AP_AP_STA_BRIDGE_V01 = 0x09, /**<  WLAN is in AP/AP/STA Bridge Mode
       Only used for GetWLANStatus  */
  QCMAP_MSGR_WLAN_MODE_STA_ONLY_BRIDGE_V01 = 0x0A, /**<  WLAN is in STA Bridge Mode
       Only used for GetWLANStatus  */
  QCMAP_MSGR_WLAN_MODE_AP_P2P_V01 = 0x0B, /**<  WLAN is in Concurrent AP/P2P mode  */
  QCMAP_MSGR_WLAN_MODE_STA_P2P_V01 = 0x0C, /**<  WLAN is in Concurrent STA/P2P mode  */
  QCMAP_MSGR_WLAN_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_wlan_mode_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_SCM_IND_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_SCM_INVALID_RECONFIG_IND_V01 = 0x00, /**<  Invalid SCM reconfig */
  QCMAP_MSGR_SCM_DYNAMIC_RECONFIG_IND_V01 = 0x01, /**<  SCM is reconfiguring WLAN */
  QCMAP_MSGR_SCM_STATION_STATE_IND_V01 = 0x02, /**<  Station state change indication from scm */
  QCMAP_MSGR_SCM_SYS_CONTROL_IND_V01 = 0x03, /**<  wlan sys control change indication from SCM */
  QCMAP_MSGR_SCM_IND_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_scm_ind_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_ACCESS_PROFILE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_PROFILE_FULL_ACCESS_V01 = 0, /**<  AP Can Access complete LAN Including Internet  */
  QCMAP_MSGR_PROFILE_INTERNET_ONLY_V01 = 1, /**<  AP Can Access Only Internet  */
  QCMAP_MSGR_ACCESS_PROFILE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_access_profile_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_WLAN_DEVICE_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_WLAN_DEV_INVALID_V01 = 0, /**<  WLAN device is invalid  */
  QCMAP_MSGR_WLAN_DEV_ROME_V01 = 1, /**<  WLAN device is Rome  */
  QCMAP_MSGR_WLAN_DEV_TUF_V01 = 2, /**<  WLAN device is Tuffelo  */
  QCMAP_MSGR_WLAN_DEV_HAST_V01 = 3, /**<  WLAN device is Hastings  */
  QCMAP_MSGR_WLAN_DEV_CUSTOM_V01 = 4, /**<  WLAN device is Custom  */
  QCMAP_MSGR_WLAN_DEVICE_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_wlan_device_type_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_WLAN_SWITCH_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_WLAN_5G_SWITCH_FAIL_V01 = 0, /**<  WLAN 5G Switch Failed  */
  QCMAP_WLAN_2G_SWITCH_FAIL_V01 = 1, /**<  WLAN 2G Switch Failed  */
  QCMAP_WLAN_5G_SWITCH_SUCCESS_V01 = 2, /**<  WLAN 5G Switch Success  */
  QCMAP_WLAN_2G_SWITCH_SUCCESS_V01 = 3, /**<  WLAN 2G Switch Success  */
  QCMAP_WLAN_STA_SWITCH_SUCCESS_V01 = 4, /**<  WLAN STA Switch to either 2G or 5G */
  QCMAP_MSGR_WLAN_SWITCH_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_wlan_switch_status_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_BOOTUP_FLAG_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_DISABLE_ON_BOOT_V01 = 0, /**<  Disable QCMAP Component on bootup  */
  QCMAP_MSGR_ENABLE_ON_BOOT_V01 = 1, /**<  Enable QCMAP Component on bootup  */
  QCMAP_MSGR_BOOTUP_FLAG_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_bootup_flag_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_USB_LINK_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_USB_LINK_RNDIS_V01 = 0x01, /**<  tethered link is RNDIS  */
  QCMAP_MSGR_USB_LINK_ECM_V01 = 0x02, /**<  tethered link is ECM  */
  QCMAP_MSGR_USB_LINK_PPP_V01 = 0x03, /**<  tethered link is PPP  */
  QCMAP_MSGR_TETHERED_LINK_ETH_V01 = 0x04, /**<  tethered link is ETH  */
  QCMAP_MSGR_TETHERED_LINK_RMNET_USB_V01 = 0x05, /**<  tethered link is RMNET_USB  */
  QCMAP_MSGR_USB_LINK_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_usb_link_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_WWAN_CALL_END_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_WWAN_CALL_END_TYPE_INVALID_V01 = 0xFF, /**<  Unknown  */
  QCMAP_MSGR_WWAN_CALL_END_TYPE_MOBILE_IP_V01 = 0x01, /**<  Mobile IP  */
  QCMAP_MSGR_WWAN_CALL_END_TYPE_INTERNAL_V01 = 0x02, /**<  Internal  */
  QCMAP_MSGR_WWAN_CALL_END_TYPE_CALL_MANAGER_DEFINED_V01 = 0x03, /**<  Call manager defined  */
  QCMAP_MSGR_WWAN_CALL_END_TYPE_3GPP_SPEC_DEFINED_V01 = 0x06, /**<  3GPP specification defined  */
  QCMAP_MSGR_WWAN_CALL_END_TYPE_PPP_V01 = 0x07, /**<  PPP  */
  QCMAP_MSGR_WWAN_CALL_END_TYPE_EHRPD_V01 = 0x08, /**<  EHRPD  */
  QCMAP_MSGR_WWAN_CALL_END_TYPE_IPV6_V01 = 0x09, /**<  IPv6  */
  QCMAP_MSGR_WWAN_CALL_END_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_wwan_call_end_type_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_INTERFACE_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_INTERFACE_TYPE_WLAN_V01 = 0x01, /**<  Interface type is WLAN  */
  QCMAP_MSGR_INTERFACE_TYPE_ETH_V01 = 0x02, /**<  Interface type is Ethernet  */
  QCMAP_MSGR_INTERFACE_TYPE_ECM_V01 = 0x03, /**<  Interface type is ECM  */
  QCMAP_MSGR_INTERFACE_TYPE_RNDIS_V01 = 0x04, /**<  Interface type is RNDIS  */
  QCMAP_MSGR_INTERFACE_TYPE_MHI_V01 = 0x05, /**<  Interface type is MHI  */
  QCMAP_MSGR_INTERFACE_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_interface_type_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_GSB_INTERFACE_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_INTERFACE_TYPE_WLAN_AP_V01 = 0x01, /**<  Interface type is WLAN in AP mode */
  QCMAP_MSGR_INTERFACE_TYPE_WLAN_STA_V01 = 0x02, /**<  Interface type is WLAN in STA mode */
  QCMAP_MSGR_INTERFACE_TYPE_ETHERNET_V01 = 0x03, /**<  Interface type is Ethernet  */
  QCMAP_MSGR_GSB_INTERFACE_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_gsb_interface_type_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_DEVICE_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_DEVICE_TYPE_PRIMARY_AP_V01 = 0x01, /**<  Device type is Primary AP  */
  QCMAP_MSGR_DEVICE_TYPE_GUEST_AP_V01 = 0x02, /**<  Device type is Guest AP  */
  QCMAP_MSGR_DEVICE_TYPE_USB_V01 = 0x03, /**<  Device type is USB  */
  QCMAP_MSGR_DEVICE_TYPE_ETHERNET_V01 = 0x04, /**<  Device type is ETHERNET  */
  QCMAP_MSGR_DEVICE_TYPE_GUEST_AP_2_V01 = 0x05, /**<  Device type is Guest AP 2  */
  QCMAP_MSGR_DEVICE_TYPE_GUEST_AP_3_V01 = 0x06, /**<  Device type is Guest AP 3 */
  QCMAP_MSGR_DEVICE_TYPE_BT_V01 = 0x07, /**<  Device type is BT  */
  QCMAP_MSGR_DEVICE_TYPE_ANY_AP_V01 = 0x08, /**<  Device type is Any AP  */
  QCMAP_MSGR_DEVICE_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_device_type_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_BACKHAUL_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_WWAN_BACKHAUL_V01 = 0x01, /**<  WWAN Backhaul  */
  QCMAP_MSGR_USB_CRADLE_BACKHAUL_V01 = 0x02, /**<  Cradle  Backhaul  */
  QCMAP_MSGR_WLAN_BACKHAUL_V01 = 0x03, /**<  WLAN  Backhaul  */
  QCMAP_MSGR_ETHERNET_BACKHAUL_V01 = 0x04, /**<  ETHERNET  Backhaul  */
  QCMAP_MSGR_BT_BACKHAUL_V01 = 0x05, /**<  BT WAN Backhaul  */
  QCMAP_MSGR_BACKHAUL_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_backhaul_type_enum_v01;
/**
    @}
  */

typedef uint64_t qcmap_msgr_tech_pref_mask_v01;
#define QCMAP_MSGR_MASK_TECH_PREF_ANY_V01 ((qcmap_msgr_tech_pref_mask_v01)0x0ull) /**<  ANY (3GPP or 3GPP2)  */
#define QCMAP_MSGR_MASK_TECH_PREF_3GPP_V01 ((qcmap_msgr_tech_pref_mask_v01)0x01ull) /**<  3GPP  */
#define QCMAP_MSGR_MASK_TECH_PREF_3GPP2_V01 ((qcmap_msgr_tech_pref_mask_v01)0x02ull) /**<  3GPP2  */
typedef uint64_t qcmap_msgr_addr_type_mask_v01;
#define QCMAP_MSGR_MASK_V4_ADDR_V01 ((qcmap_msgr_addr_type_mask_v01)0x00000001ull) /**<  IPv4 address  */
#define QCMAP_MSGR_MASK_V6_ADDR_V01 ((qcmap_msgr_addr_type_mask_v01)0x00000002ull) /**<  IPv6 address  */
#define QCMAP_MSGR_MASK_V4_DNS_ADDR_V01 ((qcmap_msgr_addr_type_mask_v01)0x00000004ull) /**<  IPv4 DNS address   */
#define QCMAP_MSGR_MASK_V6_DNS_ADDR_V01 ((qcmap_msgr_addr_type_mask_v01)0x00000008ull) /**<  IPv6 DNS address  */
typedef uint64_t qcmap_msgr_alg_type_mask_v01;
#define QCMAP_MSGR_MASK_RTSP_ALG_V01 ((qcmap_msgr_alg_type_mask_v01)0x01ull) /**<  RTSP ALG   */
#define QCMAP_MSGR_MASK_SIP_ALG_V01 ((qcmap_msgr_alg_type_mask_v01)0x02ull) /**<  SIP ALG
 All other bits are reserved and will be ignored by the service
   ADD more MASK depending on new ALG modules added
   */
/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_ARCH_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_LEGACY_ARCH_V01 = 0x00, /**<  QCMAP_LEGACY_ARCH is the default config  */
  QCMAP_FUSION_ARCH_V01 = 0x01, /**<  QCMAP_FUSION_ARCH to be used when OEM App has to interface with
       QCMAP_Server on MDM and EAP  */
  QCMAP_MSGR_ARCH_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_arch_type_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_STA_CONNECTION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_STA_CONNECTION_DYNAMIC_V01 = 0x01, /**<  Dynamic  */
  QCMAP_MSGR_STA_CONNECTION_STATIC_V01 = 0x02, /**<  Static  */
  QCMAP_MSGR_STA_CONNECTION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_sta_connection_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_UPNP_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_UPNP_MODE_UP_V01 = 0x01, /**<  UPNP is in AP mode  */
  QCMAP_MSGR_UPNP_MODE_DOWN_V01 = 0x02, /**<  UPNP is in AP/AP Mode  */
  QCMAP_MSGR_UPNP_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_upnp_mode_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_DLNA_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_DLNA_MODE_UP_V01 = 0x01, /**<  DLNA is in AP mode  */
  QCMAP_MSGR_DLNA_MODE_DOWN_V01 = 0x02, /**<  DLNA is in AP/AP Mode  */
  QCMAP_MSGR_DLNA_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_dlna_mode_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_MDNS_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_MDNS_MODE_UP_V01 = 0x01, /**<  MDNS is in AP mode  */
  QCMAP_MSGR_MDNS_MODE_DOWN_V01 = 0x02, /**<  MDNS is in AP/AP Mode  */
  QCMAP_MSGR_MDNS_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_mdns_mode_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_ACTIVATE_HOSTAPD_AP_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_PRIMARY_AP_V01 = 0x01, /**<  Primary AP.  */
  QCMAP_MSGR_GUEST_AP_V01 = 0x02, /**<  Guest AP.  */
  QCMAP_MSGR_GUEST_AP_2_V01 = 0x03, /**<  Guest AP 2.  */
  QCMAP_MSGR_GUEST_AP_3_V01 = 0x04, /**<  Guest AP 3.  */
  QCMAP_MSGR_ALL_AP_V01 = 0x05, /**<  All the Primary and Guest AP's.  */
  QCMAP_MSGR_ACTIVATE_HOSTAPD_AP_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_activate_hostapd_ap_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_ACTIVATE_HOSTAPD_ACTION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_HOSTAPD_START_V01 = 0x01, /**<  Start hostapd.  */
  QCMAP_MSGR_HOSTAPD_STOP_V01 = 0x02, /**<  Stop hostapd.  */
  QCMAP_MSGR_HOSTAPD_RESTART_V01 = 0x03, /**<  Restart hostapd.  */
  QCMAP_MSGR_ACTIVATE_HOSTAPD_ACTION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_activate_hostapd_action_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_PCSCF_INFO_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_PCSCF_IP_ADDRESS_V01 = 0x01, /**<  PCSCF IP Address  */
  QCMAP_MSGR_PCSCF_FQDN_V01 = 0x02, /**<  PCSCF Fully Qualified Domain Name */
  QCMAP_MSGR_PCSCF_INFO_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_pcscf_info_type_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_ODU_MODE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_ODU_BRIDGE_MODE_V01 = 0x01, /**<  ODU bridge mode  */
  QCMAP_MSGR_ODU_ROUTER_MODE_V01 = 0x02, /**<  ODU router mode, default mode  */
  QCMAP_MSGR_ODU_MODE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_odu_mode_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_CRADLE_MODE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_CRADLE_DISABLED_V01 = 0x00, /**<  Cradle mode disabled  */
  QCMAP_MSGR_CRADLE_LAN_BRIDGE_V01 = 0x01, /**<  Cradle mode LAN bridge  */
  QCMAP_MSGR_CRADLE_LAN_ROUTER_V01 = 0x02, /**<  Cradle mode LAN router  */
  QCMAP_MSGR_CRADLE_WAN_BRIDGE_V01 = 0x03, /**<  Cradle mode WAN bridge  */
  QCMAP_MSGR_CRADLE_WAN_ROUTER_V01 = 0x04, /**<  Cradle mode WAN router  */
  QCMAP_MSGR_CRADLE_MODE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_cradle_mode_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_TINY_PROXY_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_TINY_PROXY_MODE_UP_V01 = 0x01, /**<  Tiny Proxy is in UP mode  */
  QCMAP_MSGR_TINY_PROXY_MODE_DOWN_V01 = 0x02, /**<  Tiny Proxy is in DOWN Mode  */
  QCMAP_MSGR_TINY_PROXY_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_tiny_proxy_mode_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_CRADLE_STATUS_IND_REG_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_CRADLE_STATUS_IND_DEREG_V01 = 0, /**<  0 -- Do not register or deregister the control point
      if already registered  */
  QCMAP_MSGR_CRADLE_STATUS_IND_REG_V01 = 1, /**<  1 -- Register for the indication; ignore if already registered  */
  QCMAP_CRADLE_STATUS_IND_REG_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_cradle_status_ind_reg_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_SOCKSV5_CONFIG_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_SOCKSV5_SET_CONFIG_FILE_PATH_V01 = 0, /**<  Set config file path  */
  QCMAP_MSGR_SOCKSV5_SET_AUTH_METHOD_V01 = 1, /**<  Set auth Method  */
  QCMAP_MSGR_SOCKSV5_EDIT_LAN_IFACE_V01 = 2, /**<  Edit LAN Iface  */
  QCMAP_MSGR_SOCKSV5_ADD_UNAME_ASSOC_V01 = 3, /**<  Add UNAME Association for Private Auth Method  */
  QCMAP_MSGR_SOCKSV5_DELETE_UNAME_ASSOC_V01 = 4, /**<  Delete UNAME Association for Private Auth Method  */
  QCMAP_SOCKSV5_CONFIG_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_socksv5_config_type_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_ETHERNET_MODE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_ETHERNET_LAN_ROUTER_V01 = 0x00, /**<  ETH mode LAN router */
  QCMAP_MSGR_ETHERNET_WAN_ROUTER_V01 = 0x01, /**<   ETH mode WAN router  */
  QCMAP_MSGR_ETHERNET_WAN_LAN_ROUTER_V01 = 0x02, /**<   ETH mode WAN_LAN router  */
  QCMAP_MSGR_ETHERNET_MODE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_ethernet_mode_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_ETHERNET_STATUS_IND_REG_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_ETHERNET_STATUS_IND_DEREG_V01 = 0, /**<   0 -- Do not register or deregister the control point
                if already registered   */
  QCMAP_MSGR_ETHERNET_STATUS_IND_REG_V01 = 1, /**<   1 -- Register for the indication; ignore if already registered   */
  QCMAP_ETHERNET_STATUS_IND_REG_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_ethernet_status_ind_reg_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_ETHERNET_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_ETH_BACKHAUL_DISCONNECTED_V01 = 1, /**<  ETH Backhaul is disconnected  */
  QCMAP_MSGR_ETH_BACKHAUL_CONNECTED_V01 = 2, /**<  ETH Backhaul is connected   */
  QCMAP_MSGR_ETHERNET_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_ethernet_status_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_IP_PASSTHROUGH_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_IP_PASSTHROUGH_MODE_DOWN_V01 = 0x00, /**<  IP Passthrough mode is down  */
  QCMAP_MSGR_IP_PASSTHROUGH_MODE_UP_V01 = 0x01, /**<  IP Passthrough mode is up  */
  QCMAP_MSGR_IP_PASSTHROUGH_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_ip_passthrough_mode_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_BT_TETHERING_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_BT_TETHERING_MODE_UP_V01 = 0x01, /**<  BT Tethering is UP  */
  QCMAP_MSGR_BT_TETHERING_MODE_DOWN_V01 = 0x02, /**<  BT Tethering is DOWN  */
  QCMAP_MSGR_BT_TETHERING_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_bt_tethering_status_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_BT_TETHERING_STATUS_IND_REG_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_BT_TETHERING_STATUS_IND_DEREG_V01 = 0, /**<  0 -- Do not register or deregister the control point
      if already registered  */
  QCMAP_MSGR_BT_TETHERING_STATUS_IND_REG_V01 = 1, /**<  1 -- Register for the indication; ignore if already registered  */
  QCMAP_BT_TETHERING_STATUS_IND_REG_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_bt_tethering_status_ind_reg_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_PACKET_STATS_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_PACKET_STATS_CLIENT_DISCONNECTED_V01 = 0x00, /**<  A client is disconnected  */
  QCMAP_MSGR_PACKET_STATS_CLIENT_CONNECTED_V01 = 0x01, /**<  A new client connected */
  QCMAP_MSGR_PACKET_STATS_IPV4_UPDATED_V01 = 0x02, /**<  IPv4 Updated  */
  QCMAP_MSGR_PACKET_STATS_IPV6_UPDATED_V01 = 0x03, /**<  IPV6 Updated  */
  QCMAP_MSGR_PACKET_STATS_WLAN_DISABLED_V01 = 0x04, /**<  WLAN is disabled  */
  QCMAP_MSGR_PACKET_STATS_MOBILEAP_DISABLED_V01 = 0x05, /**<  QCMAP CM is disabled  */
  QCMAP_MSGR_PACKET_STATS_IPV6_WWAN_DISCONNECTED_V01 = 0x06, /**<  IPV6 WWAN connection is lost */
  QCMAP_MSGR_PACKET_STATS_IPV4_WWAN_DISCONNECTED_V01 = 0x07, /**<  IPV4 WWAN connection is lost */
  QCMAP_MSGR_PACKET_STATS_BH_SWITCHED_V01 = 0x08, /**<  Backhaul is switched */
  QCMAP_MSGR_PACKET_STATS_USB_DISCONNECTED_V01 = 0x09, /**<  USB is disconnected  */
  QCMAP_MSGR_PACKET_STATS_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_packet_stats_state_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_BT_TETHERING_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_BT_MODE_LAN_V01 = 0, /**<  0 -- Station will act as Backahul  */
  QCMAP_MSGR_BT_MODE_WAN_V01 = 1, /**<  1 -- BT-Pan will act as Backahul  */
  QCMAP_BT_TETHERING_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_bt_tethering_mode_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_BT_TETHERING_WAN_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_BT_WAN_MODE_CONNECTED_V01 = 0x01, /**<  BT WAN Backahul mode is connected  */
  QCMAP_MSGR_BT_WAN_MODE_DISCONNECTED_V01 = 0x02, /**<  BT WAN Backahul mode is disconnected  */
  QCMAP_MSGR_BT_TETHERING_WAN_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_bt_tethering_wan_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_BT_TETHERING_WAN_IND_REG_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_BT_TETHERING_WAN_IND_DEREG_V01 = 0, /**<  0 -- Do not register or deregister the control point
      if already registered  */
  QCMAP_MSGR_BT_TETHERING_WAN_IND_REG_V01 = 1, /**<  1 -- Register for the indication; ignore if already registered  */
  QCMAP_BT_TETHERING_WAN_IND_REG_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_bt_tethering_wan_ind_reg_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_FIREWALL_RULE_DIRECTION_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_UL_FIREWALL_V01 = 0x01, /**<  Firewall rule will be applied in UL direction  */
  QCMAP_MSGR_DL_FIREWALL_V01 = 0x02, /**<  Firewall rule will be applied in DL direction  */
  QCMAP_MSGR_FIREWALL_RULE_DIRECTION_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_firewall_rule_direction_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_L2TP_ENCAP_PROTOCOL_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_L2TP_ENCAP_IP_V01 = 0x01, /**<  IP Protocol Encapsulation   */
  QCMAP_MSGR_L2TP_ENCAP_UDP_V01 = 0x02, /**<  UP Protocol Encapsulation   */
  QCMAP_MSGR_L2TP_ENCAP_PROTOCOL_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_l2tp_encap_protocol_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_L2TP_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_L2TP_ROUTER_MODE_V01 = 0x01, /**<  L2TP Router mode  */
  QCMAP_MSGR_L2TP_BRIDGE_MODE_V01 = 0x02, /**<  L2TP Bridge mode   */
  QCMAP_MSGR_L2TP_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_l2tp_mode_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_VLAN_ID_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_VLAN_ID_NONE_V01 = 0x00, /**<  Min VLAN ID   */
  QCMAP_MSGR_VLAN_ID_MAX_V01 = 0xFFF, /**<  Max VLAN ID   */
  QCMAP_MSGR_VLAN_ID_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_vlan_id_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_UPDATE_PROFILE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_UPDATE_TECH_TYPE_V01 = 0x01, /**<  Update Tech Type  */
  QCMAP_MSGR_UPDATE_V4_3GPP_PROFILE_INDEX_V01 = 0x02, /**<  Update V4 3GPP Profile Index  */
  QCMAP_MSGR_UPDATE_V4_3GPP2_PROFILE_INDEX_V01 = 0x03, /**<  Update V4 3GPP2 Profile Index  */
  QCMAP_MSGR_UPDATE_V6_3GPP_PROFILE_INDEX_V01 = 0x04, /**<  Update V6 3GPP Profile Index  */
  QCMAP_MSGR_UPDATE_V6_3GPP2_PROFILE_INDEX_V01 = 0x05, /**<  Update V6 3GPP2 Profile Index  */
  QCMAP_MSGR_UPDATE_ALL_PROFILE_INDEX_V01 = 0x06, /**<  Update All Profile Index  */
  QCMAP_MSGR_SET_DEFAULT_PROFILE_V01 = 0x07, /**<  Set this as default profile  */
  QCMAP_MSGR_UPDATE_PROFILE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_update_profile_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_PMIPV4_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_PMIPV4_MODE_CPE_V01 = 1, /**<  MIPV4 MODE is CPE  */
  QCMAP_MSGR_PMIPV4_MODE_SECONDARY_ROUTER_V01 = 2, /**<  PMIPV4 MODE is SECONDARY ROUTER  */
  QCMAP_MSGR_PMIPV4_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_pmipv4_mode_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_PMIP_MOBILE_NODE_IDENTIFIER_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_PMIP_MOBILE_NODE_IDENTIFIER_MAC_V01 = 0, /**<  PMIP MOBILE NODE IDENTIFIER is MAC of mobile Node  */
  QCMAP_MSGR_PMIP_MOBILE_NODE_IDENTIFIER_STRING_V01 = 1, /**<  PMIP MOBILE NODE IDENTIFIER is custom string  */
  QCMAP_MSGR_PMIP_MOBILE_NODE_IDENTIFIER_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_pmip_mobile_node_identifier_enum_v01;
/**
    @}
  */

typedef uint64_t qcmap_msgr_v2x_indication_mask_v01;
#define QCMAP_MSGR_V2X_SPS_SCHEDULING_INFO_IND_MASK_V01 ((qcmap_msgr_v2x_indication_mask_v01)0x00000001ull) /**<  V2X SPS Scheduling Indication Mask  */
#define QCMAP_MSGR_V2X_SRC_L2_INFO_IND_MASK_V01 ((qcmap_msgr_v2x_indication_mask_v01)0x00000002ull) /**<  V2X Src L2 Info Indication Mask  */
#define QCMAP_MSGR_V2X_CAPABILITY_INFO_IND_MASK_V01 ((qcmap_msgr_v2x_indication_mask_v01)0x00000004ull) /**<  V2X Capability Info Indication Mask  */
/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure used to obtain wlan if number dynamically
 */
typedef struct {

  qcmap_msgr_wlan_iface_index_enum_v01 wlan_ap_type;
  /**<   wlan ap type (primary or guest etc) */

  char if_name[QCMAP_MAX_IFACE_NAME_SIZE_V01];
  /**<   wlan if name and number provided */

  qcmap_msgr_wlan_iface_active_state_enum_v01 state;
  /**<   wlan if state */

  qcmap_msgr_wlan_device_type_v01 wlan_dev_type;
  /**<   wlan ifdev type */
}qcmap_msgr_wlan_if_info_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure used to add a static NAT entry.
 */
typedef struct {

  uint32_t private_ip_addr;
  /**<   Private IP address. */

  uint16_t private_port;
  /**<   Private port. */

  uint16_t global_port;
  /**<   Global port. */

  uint8_t protocol;
  /**<   Protocol. */
}qcmap_msgr_snat_entry_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure used to add a static NAT V6 entry.
 */
typedef struct {

  uint8_t port_fwding_private_ip6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   Private IP address. */

  uint16_t private_port;
  /**<   Private port. */

  uint16_t global_port;
  /**<   Global port. */

  uint8_t protocol;
  /**<   Protocol. */
}qcmap_msgr_snat_v6_entry_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_WWAN_ROAMING_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_ROAM_STATUS_OFF_V01 = 0x00,
  QCMAP_MSGR_ROAM_STATUS_ON_V01 = 0x01,
  QCMAP_MSGR_ROAM_STATUS_BLINK_V01 = 0x02,
  QCMAP_MSGR_ROAM_STATUS_OUT_OF_NEIGHBORHOOD_V01 = 0x03,
  QCMAP_MSGR_ROAM_STATUS_OUT_OF_BLDG_V01 = 0x04,
  QCMAP_MSGR_ROAM_STATUS_PREF_SYS_V01 = 0x05,
  QCMAP_MSGR_ROAM_STATUS_AVAIL_SYS_V01 = 0x06,
  QCMAP_MSGR_ROAM_STATUS_ALLIANCE_PARTNER_V01 = 0x07,
  QCMAP_MSGR_ROAM_STATUS_PREMIUM_PARTNER_V01 = 0x08,
  QCMAP_MSGR_ROAM_STATUS_FULL_SVC_V01 = 0x09,
  QCMAP_MSGR_ROAM_STATUS_PARTIAL_SVC_V01 = 0x0A,
  QCMAP_MSGR_ROAM_STATUS_BANNER_ON_V01 = 0x0B,
  QCMAP_MSGR_ROAM_STATUS_BANNER_OFF_V01 = 0x0C,
  QCMAP_MSGR_WWAN_ROAMING_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_wwan_roaming_status_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_TECHNOLOGY_NAME_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_TECHNOLOGY_NAME_CDMA_V01 = -32767, /**<   QCMAP_TECHNOLOGY_NAME_CDMA (-32767) --  0x8001 -- CDMA  */
  QCMAP_TECHNOLOGY_NAME_UMTS_V01 = -32764, /**<  QCMAP_TECHNOLOGY_NAME_UMTS (-32764) --  0x8004 -- UMTS  */
  QCMAP_TECHNOLOGY_NAME_WLAN_LOCAL_BRKOUT_V01 = -32736, /**<  QCMAP_TECHNOLOGY_NAME_WLAN_LOCAL_BRKOUT (-32736) --  0x8020 -- WLAN_LOCAL_BRKOUT  */
  QCMAP_TECHNOLOGY_NAME_IWLAN_S2B_V01 = -32735, /**<  QCMAP_TECHNOLOGY_NAME_IWLAN_S2B (-32735) --  0x8021 -- IWLAN_S2B  */
  QCMAP_TECHNOLOGY_NAME_EPC_V01 = -30592, /**<  QCMAP_TECHNOLOGY_NAME_EPC (-30592) --  0x8880 -- EPC  */
  QCMAP_TECHNOLOGY_NAME_EMBMS_V01 = -30590, /**<  QCMAP_TECHNOLOGY_NAME_EMBMS (-30590) --  0x8882 -- EMBMS  */
  QCMAP_TECHNOLOGY_NAME_NON_IP_V01 = -30588, /**<  QCMAP_TECHNOLOGY_NAME_NON_IP (-30588) --  0x8884 -- Non-IP  */
  QCMAP_TECHNOLOGY_NAME_MODEM_LINK_LOCAL_V01 = -30584, /**<  QCMAP_TECHNOLOGY_NAME_MODEM_LINK_LOCAL (-30584) --  0x8888 -- Modem link local  */
  QCMAP_TECHNOLOGY_NAME_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_technology_name_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_L2TP_HW_OFFLOAD_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_L2TP_HW_OFFLOAD_NONE_V01 = 0, /**<  L2TP no hardware offload mode  */
  QCMAP_MSGR_L2TP_HW_L2L_MODE_V01 = 0x01, /**<  L2TP Lan to Lan mode  */
  QCMAP_MSGR_L2TP_HW_E2E_MODE_V01 = 0x02, /**<  L2TP End to End mode  */
  QCMAP_MSGR_L2TP_HW_OFFLOAD_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_l2tp_hw_offload_mode_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_DEVICE_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_DEVICE_NONE_V01 = 0x00, /**<   Device no hardware offload mode   */
  QCMAP_MSGR_DEVICE_L2L_V01 = 0x01, /**<   Device Lan to Lan mode   */
  QCMAP_MSGR_DEVICE_E2E_V01 = 0x02, /**<   Device End to End mode   */
  QCMAP_MSGR_DEVICE_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_device_mode_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_DATA_BEARER_TECH_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_DATA_BEARER_TECH_UNKNOWN_V01 = 0, /**<  Unknown bearer.  */
  QCMAP_MSGR_DATA_BEARER_TECH_CDMA_1X_V01 = 1, /**<  1X technology.  */
  QCMAP_MSGR_DATA_BEARER_TECH_EVDO_REV0_V01 = 2, /**<  CDMA Rev 0.  */
  QCMAP_MSGR_DATA_BEARER_TECH_EVDO_REVA_V01 = 3, /**<  CDMA Rev A.  */
  QCMAP_MSGR_DATA_BEARER_TECH_EVDO_REVB_V01 = 4, /**<  CDMA Rev B.  */
  QCMAP_MSGR_DATA_BEARER_TECH_EHRPD_V01 = 5, /**<  EHRPD.  */
  QCMAP_MSGR_DATA_BEARER_TECH_FMC_V01 = 6, /**<  Fixed mobile convergence.  */
  QCMAP_MSGR_DATA_BEARER_TECH_HRPD_V01 = 7, /**<  HRPD  */
  QCMAP_MSGR_DATA_BEARER_TECH_3GPP2_WLAN_V01 = 8, /**<  IWLAN  */
  QCMAP_MSGR_DATA_BEARER_TECH_WCDMA_V01 = 9, /**<  WCDMA.  */
  QCMAP_MSGR_DATA_BEARER_TECH_GPRS_V01 = 10, /**<  GPRS.  */
  QCMAP_MSGR_DATA_BEARER_TECH_HSDPA_V01 = 11, /**<  HSDPA.  */
  QCMAP_MSGR_DATA_BEARER_TECH_HSUPA_V01 = 12, /**<  HSUPA.  */
  QCMAP_MSGR_DATA_BEARER_TECH_EDGE_V01 = 13, /**<  EDGE.  */
  QCMAP_MSGR_DATA_BEARER_TECH_LTE_V01 = 14, /**<  LTE.  */
  QCMAP_MSGR_DATA_BEARER_TECH_HSDPA_PLUS_V01 = 15, /**<  HSDPA+.  */
  QCMAP_MSGR_DATA_BEARER_TECH_DC_HSDPA_PLUS_V01 = 16, /**<  DC HSDPA+.  */
  QCMAP_MSGR_DATA_BEARER_TECH_HSPA_V01 = 17, /**<  HSPA  */
  QCMAP_MSGR_DATA_BEARER_TECH_64_QAM_V01 = 18, /**<  64 QAM.  */
  QCMAP_MSGR_DATA_BEARER_TECH_TDSCDMA_V01 = 19, /**<  TD-SCDMA.  */
  QCMAP_MSGR_DATA_BEARER_TECH_GSM_V01 = 20, /**<  GSM  */
  QCMAP_MSGR_DATA_BEARER_TECH_3GPP_WLAN_V01 = 21, /**<  IWLAN  */
  QCMAP_MSGR_DATA_BEARER_TECH_5G_V01 = 22, /**<  5G  */
  QCMAP_MSGR_DATA_BEARER_TECH_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_data_bearer_tech_type_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_V2X_REQUEST_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_V2X_INVALID_V01 = 0, /**<  Invalid  */
  QCMAP_MSGR_V2X_SPS_FLOW_REG_V01 = 1, /**<  V2X SPS Flow Reg   */
  QCMAP_MSGR_V2X_SPS_FLOW_DEREG_V01 = 2, /**<  V2X SPS Flow Dereg   */
  QCMAP_MSGR_V2X_SPS_FLOW_UPDATE_V01 = 3, /**<  V2X SPS Flow Update   */
  QCMAP_MSGR_V2X_SPS_FLOW_GET_INFO_V01 = 4, /**<  V2X SPS Flow Get Info   */
  QCMAP_MSGR_V2X_NON_SPS_FLOW_REG_V01 = 5, /**<  V2X Non SPS Flow Reg   */
  QCMAP_MSGR_V2X_NON_SPS_FLOW_DEREG_V01 = 6, /**<  V2X Non SPS Flow DeReg   */
  QCMAP_MSGR_V2X_SERVICE_SUBSCRIBE_V01 = 7, /**<  V2X Service Subscribe   */
  QCMAP_MSGR_V2X_GET_SERVICE_SUBSCRIPTION_INFO_V01 = 8, /**<  V2X Get Service Subscription info   */
  QCMAP_MSGR_V2X_SEND_CONFIG_FILE_V01 = 9, /**<  V2X Send Config File   */
  QCMAP_MSGR_V2X_UPDATE_SRC_L2_INFO_V01 = 10, /**<  V2X Update Src L2 Info   */
  QCMAP_MSGR_V2X_TUNNEL_MODE_INFO_V01 = 11, /**<  V2X Tunnel Mode Info  */
  QCMAP_MSGR_V2X_GET_CAPABILITY_INFO_V01 = 12, /**<  V2X Get Capability Info  */
  QCMAP_MSGR_V2X_REQUEST_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_v2x_request_type_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_V2X_ERR_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_V2X_ERR_NONE_V01 = 0, /**<  None \n  */
  QCMAP_MSGR_V2X_ERR_EXCEED_MAX_V01 = 1, /**<  Exceeded maximum \n */
  QCMAP_MSGR_V2X_ERR_V2X_DISABLED_V01 = 2, /**<  V2X disabled \n */
  QCMAP_MSGR_V2X_ERR_UNKNOWN_SERVICE_ID_V01 = 3, /**<  Unknown service ID \n  */
  QCMAP_MSGR_V2X_ERR_SRV_ID_L2_ADDRS_NOT_COMPATIBLE_V01 = 4, /**<  Serivce ID L2 address not compatible \n */
  QCMAP_MSGR_V2X_ERR_PORT_UNAVAIL_V01 = 5, /**<  Port unavailable \n */
  QCMAP_MSGR_V2X_ERR_INTERNAL_V01 = 6, /**<  Internal error  */
  QCMAP_MSGR_V2X_ERR_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_v2x_err_type_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_V2X_RETX_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_V2X_RETX_AUTO_V01 = 0, /**<  Default; retransmission is determined by the QCMAP \n  */
  QCMAP_MSGR_V2X_RETX_ON_V01 = 1, /**<  Retransmission for TX packets on \n */
  QCMAP_MSGR_V2X_RETX_OFF_V01 = 2, /**<  Retransmission for TX packets off  */
  QCMAP_MSGR_V2X_RETX_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_v2x_retx_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_PROTOCOL_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_PROTO_INVALID_V01 = 0x00, /**<  Invalid Protocol \n  */
  QCMAP_MSGR_PROTO_TCP_V01 = 0x01, /**<  Transmission Control Protocol \n  */
  QCMAP_MSGR_PROTO_UDP_V01 = 0x02, /**<  User Datagram Protocol \n  */
  QCMAP_MSGR_PROTO_TCP_UDP_V01 = 0x03, /**<  Transmission Control Protocol/User Datagram Protocol  */
  QCMAP_MSGR_PROTOCOL_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_protocol_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_V2X_SERVICE_SUB_ACTION_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_V2X_SERVICE_SUBS_ADD_V01 = 0, /**<  Add a set of service IDs \n
   */
  QCMAP_MSGR_V2X_SERVICE_SUBS_REMOVE_V01 = 1, /**<  Remove a set of service IDs \n
   */
  QCMAP_MSGR_V2X_SERVICE_SUBS_ADD_WILDCARD_V01 = 2, /**<  Subscribe to all services, do not filter any packets
       associated with the corresponding service_id \n
   */
  QCMAP_MSGR_V2X_SERVICE_SUBS_REMOVE_WILDCARD_V01 = 3, /**<  Start filtering on service_ids that are provided through the ADD action. \n
   */
  QCMAP_MSGR_V2X_SERVICE_SUB_ACTION_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_v2x_service_sub_action_type_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_V2X_CONFIG_FILE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_V2X_CONFIG_FILE_XML_V01 = 1, /**<  XML.  */
  QCMAP_MSGR_V2X_CONFIG_FILE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_v2x_config_file_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_V2X_CONFIG_FILE_SEND_RESULT_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_V2X_CONFIG_FILE_SUCCESS_V01 = 0, /**<  Success. \n  */
  QCMAP_MSGR_V2X_CONFIG_FILE_FAILURE_INTERNAL_V01 = 1, /**<  Internal failure. \n  */
  QCMAP_MSGR_V2X_CONFIG_FILE_FAILURE_TIMEOUT_V01 = 2, /**<  Timeout failure. \n  */
  QCMAP_MSGR_V2X_CONFIG_FILE_FAILURE_OUT_OF_ORDER_V01 = 3, /**<  Out of order failure. \n  */
  QCMAP_MSGR_V2X_CONFIG_FILE_FAILURE_DECODED_ERR_V01 = 4, /**<  Decoded error failure. \n  */
  QCMAP_MSGR_V2X_CONFIG_FILE_FAILURE_INVALID_STATE_V01 = 5, /**<  Invalid state failure.  */
  QCMAP_MSGR_V2X_CONFIG_FILE_SEND_RESULT_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_v2x_config_file_send_result_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_SSR_SERVICE_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_SERVICE_UP_V01 = 0x00, /**<  0 -- Service up event  */
  QCMAP_MSGR_SERVICE_DOWN_V01 = 0x01, /**<  1 -- Service down event  */
  QCMAP_MSGR_SSR_SERVICE_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_ssr_service_status_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_MSGR_N79_PRIORITY_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_WLAN_PRIORITY_V01 = 0, /**<  WLAN 5GHz priority \n
   */
  QCMAP_MSGR_N79_PRIORITY_V01 = 1, /**<  N79 PRIORITY \n
   */
  QCMAP_MSGR_N79_PRIORITY_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_msgr_n79_priority_enum_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_ETH_NETWORK_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_MSGR_ETHERNET_LAN_TYPE_V01 = 0x00,
  QCMAP_MSGR_ETHERNET_WAN_TYPE_V01 = 0x01,
  QCMAP_ETH_NETWORK_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_eth_network_type_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  < ETH LAN
 < ETH WAN
 Data structure for the network policy used to enable mobile AP.
 */
typedef struct {

  qcmap_msgr_tech_pref_mask_v01 tech_pref;
  /**<   Bitmap indicating the technology preference. A single connection
 is attempted using the following specified technology preferences.
 Values: \n
      - QCMAP_MSGR_MASK_TECH_PREF_ANY (0x0) --  ANY (3GPP or 3GPP2)
      - QCMAP_MSGR_MASK_TECH_PREF_3GPP (0x01) --  3GPP
      - QCMAP_MSGR_MASK_TECH_PREF_3GPP2 (0x02) --  3GPP2

 \vspace{3pt}
 All other bits are reserved and ignored even if they are set
 in the request. If a single value of the technology preference
 bitmask is set, the device attempts to use that technology. If two
 or more bits in the technology preference bitmask are set, the
 device determines the technology to be used from those specified.
 */

  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version to be used. Values: \n
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  uint8_t v4_profile_id_3gpp2;
  /**<   CDMA profile ID for IPv4. */

  uint8_t v4_profile_id_3gpp;
  /**<   UMTS profile ID for IPv4. */

  uint8_t v6_profile_id_3gpp2;
  /**<   CDMA profile ID for IPv6. */

  uint8_t v6_profile_id_3gpp;
  /**<   UMTS profile ID for IPv6. */
}qcmap_msgr_net_policy_info_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for the network policy used to enable mobile AP.
 */
typedef struct {

  profile_handle_type_v01 profile_handle;
  /**<   Profile_handle for PDN
  */

  qcmap_msgr_tech_pref_mask_v01 tech_pref;
  /**<   Bitmap indicating the technology preference. A single connection
 is attempted using the following specified technology preferences.
 Values: \n
      - QCMAP_MSGR_MASK_TECH_PREF_ANY (0x0) --  ANY (3GPP or 3GPP2)
      - QCMAP_MSGR_MASK_TECH_PREF_3GPP (0x01) --  3GPP
      - QCMAP_MSGR_MASK_TECH_PREF_3GPP2 (0x02) --  3GPP2

 \vspace{3pt}
 All other bits are reserved and ignored even if they are set
 in the request. If a single value of the technology preference
 bitmask is set, the device attempts to use that technology. If two
 or more bits in the technology preference bitmask are set, the
 device determines the technology to be used from those specified.
 */

  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version to be used. Values: \n
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  uint8_t v4_profile_id_3gpp2;
  /**<   CDMA profile ID for IPv4. */

  uint8_t v4_profile_id_3gpp;
  /**<   UMTS profile ID for IPv4. */

  uint8_t v6_profile_id_3gpp2;
  /**<   CDMA profile ID for IPv6. */

  uint8_t v6_profile_id_3gpp;
  /**<   UMTS profile ID for IPv6. */
}qcmap_msgr_net_profile_and_policy_info_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for WWAN statistics.
 */
typedef struct {

  uint64_t bytes_rx;
  /**<   Bytes received on WWAN. */

  uint64_t bytes_tx;
  /**<   Bytes transmitted on WWAN. */

  uint32_t pkts_rx;
  /**<   Packets received on WWAN. */

  uint32_t pkts_tx;
  /**<   Packets transmitted on WWAN. */

  uint32_t pkts_dropped_rx;
  /**<   Packets dropped on Rx WWAN. */

  uint32_t pkts_dropped_tx;
  /**<   Packets dropped on Tx WWAN. */
}qcmap_msgr_wwan_statistics_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for IPv4 address and subnet mask.
 */
typedef struct {

  uint32_t addr;
  /**<   IPv4 address as specified in the IPv4 protocol
       specification (RFC 791 \hyperref[S2]{[S2]}).
  */

  uint32_t subnet_mask;
  /**<   IPv4 subnet mask as specified in the IPv4
       protocol specification (RFC 791 \hyperref[S2]{[S2]}).
  */
}qcmap_ip4_addr_subnet_mask_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for the IPv6 address and prefix.
 */
typedef struct {

  uint8_t addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   IPv6 address as specified in the IPv6
       protocol specification (RFC 2460 \hyperref[S5]{[S5]}).
  */

  uint8_t prefix_len;
  /**<   IPv6 prefix length as specified in the IPv6
       protocol specification (RFC 3513 \hyperref[S6]{[S6]}).
  */
}qcmap_ip6_addr_prefix_len_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for TCP, UDP, and TCP_UDP port and range.
 */
typedef struct {

  uint16_t port;
  /**<   TCP/UDP port as specified in the
       TCP and UDP protocols (RFC 793 \hyperref[S4]{[S4]},
       RFC 768 \hyperref[S1]{[S1]}).
  */

  uint16_t range;
  /**<   TCP/UDP port range as specified in the
       TCP and UDP protocols (RFC 793 \hyperref[S4]{[S4]},
       RFC 768 \hyperref[S1]{[S1]}).
  */
}qcmap_tcp_udp_port_range_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for IPv4 type of service.
 */
typedef struct {

  uint8_t value;
  /**<   TOS value as specified in the IPv4 protocol
       (RFC 791 \hyperref[S2]{[S2]}). */

  uint8_t mask;
  /**<   IPv4 TOS mask */
}qcmap_ip4_tos_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for IPv6 traffic class.
 */
typedef struct {

  uint8_t value;
  /**<   IPv6 traffic class value as specified in the IPv6 protocol
       (RFC 2460 \hyperref[S5]{[S5]}). */

  uint8_t mask;
  /**<   IPv6 traffic class mask */
}qcmap_ip6_traffic_class_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for DHCP configuration.
 */
typedef struct {

  uint32_t dhcp_start_ip;
  /**<   DHCP start IP address. */

  uint32_t dhcp_end_ip;
  /**<   DHCP end IP address. */

  uint32_t lease_time;
  /**<   DHCP lease time, in seconds.*/
}qcmap_msgr_dhcp_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for IP Passthrough configuration.
 */
typedef struct {

  qcmap_msgr_device_type_enum_v01 device_type;
  /**<   Identifies the IP Passthrough device type */

  uint8_t mac_addr[QCMAP_MSGR_MAC_ADDR_LEN_V01];
  /**<   Identifies the device MAC address */

  char client_device_name[QCMAP_MSGR_DEVICE_NAME_MAX_V01];
  /**<   Device name. */
}qcmap_msgr_ip_passthrough_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for adding AP configuration.
 */
typedef struct {

  uint32_t gw_ip;
  /**<   IP address of the gateway. */

  uint32_t netmask;
  /**<   Subnet mask. */

  uint8_t enable_dhcp;
  /**<   Whether to enable DHCP; boolean value. */

  qcmap_msgr_dhcp_config_v01 dhcp_config;
  /**<   DHCP configuration. Used only when DHCP is enabled. */
}qcmap_msgr_lan_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for WLAN configuration.
 */
typedef struct {

  uint32_t gw_ip;
  /**<   IP address of the WLAN gateway. */

  uint32_t netmask;
  /**<   Subnet mask for WLAN. */

  qcmap_msgr_dhcp_config_v01 dhcp_config;
  /**<   WLAN DHCP configuration. */
}qcmap_msgr_wlan_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for USB configuration.
 */
typedef struct {

  uint32_t gw_ip;
  /**<   USB gateway IP address. */

  uint32_t netmask;
  /**<   Subnet mask for USB TE. */

  uint32_t usb_ip;
  /**<   USB TE IP address. */

  uint32_t lease_time;
  /**<   DHCP lease time, in seconds.*/
}qcmap_msgr_usb_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for WLAN and USB TE configuration present on Access Point
 */
typedef struct {

  qcmap_msgr_wlan_config_v01 wlan_config;
  /**<   WLAN configuration */

  qcmap_msgr_usb_config_v01 usb_config;
  /**<   USB TE configuration */
}qcmap_msgr_ap_mode_wlan_usb_ip_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for static IP configuration in station mode.
 */
typedef struct {

  uint32_t ip_addr;
  /**<   IP address to be assigned. */

  uint32_t gw_ip;
  /**<   IP address of the gateway. */

  uint32_t netmask;
  /**<   Subnet mask. */

  uint32_t dns_addr;
  /**<   DNS address. */
}qcmap_msgr_sta_static_ip_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for adding station mode configuration.
 */
typedef struct {

  qcmap_msgr_sta_connection_enum_v01 conn_type;
  /**<   Connection type. */

  qcmap_msgr_sta_static_ip_config_v01 static_ip_config;
  /**<   Static IP configuration. Used only when the connection type is static. */

  uint8_t ap_sta_bridge_mode;
  /**<   Used to Set Bridge/Router Mode when STA is active */
}qcmap_msgr_station_mode_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure the reason the WWAN call ends
 */
typedef struct {

  qcmap_msgr_wwan_call_end_type_enum_v01 wwan_call_end_reason_type;
  /**<   WWAN call end type. */

  int32_t wwan_call_end_reason_code;
  /**<   WWAN call end reason code. */
}qcmap_msgr_wwan_call_end_reason_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for bitrates
 */
typedef struct {

  uint64_t tx_rate;
  /**<   current tx rate. */

  uint64_t rx_rate;
  /**<   current rx rate. */

  uint64_t max_tx_rate;
  /**<   max tx rate. */

  uint64_t max_rx_rate;
  /**<   max rx rate. */
}qcmap_msgr_data_bitrate_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for DHCP reservation.
 */
typedef struct {

  uint8_t client_mac_addr[QCMAP_MSGR_MAC_ADDR_LEN_V01];
  /**<   MAC address of the device. */

  uint32_t client_reserved_ip;
  /**<   Reserved IP for the AP client. */

  char client_device_name[QCMAP_MSGR_DEVICE_NAME_MAX_V01];
  /**<   Device name. */

  uint8_t enable_reservation;
  /**<   To enable/disable DHCP reservation; boolean value. */
}qcmap_msgr_dhcp_reservation_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  qcmap_msgr_pcscf_info_type_v01 pcscf_info_type;
  /**<   Identifies the type of PCSCF information contained*/

  uint32_t pcscf_ip_addr;
  /**<   Identifies the PCSCF IP address */

  char pcscf_fqdn[QCMAP_MSGR_PCSCF_FQDN_MAX_LENGTH_V01];
  /**<   Identifies the default PCSCF FQDN */
}qcmap_msgr_sip_server_info_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   IPv6 address of client. */
}qcmap_msgr_client_ipv6_addr_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t client_mac_addr[QCMAP_MSGR_MAC_ADDR_LEN_V01];
  /**<   MAC address of the client. */

  qcmap_msgr_device_type_enum_v01 device_type;
  /**<   Device type primary AP/guest AP/USB/eth client. */

  char host_name[QCMAP_MSGR_DEVICE_NAME_MAX_V01];
  /**<   Host name of dynamically IP allocated WLAN/USB/eth clients. */

  uint32_t lease_expiry_time;
  /**<   Lease expiry time in minutes for dynamically IP allocated WLAN/USB clients. */

  uint32_t ipv4_addr;
  /**<   IPv4 address of the client. */

  uint8_t ll_ipv6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   Link Local IPv6 address of the client. */

  qcmap_msgr_client_ipv6_addr_v01 ipv6[QCMAP_MSGR_MAX_IPV6_ADDR_V01];
  /**<   All IPv6 addresses of single client. */

  uint64_t bytes_rx;
  /**<   Bytes received by client */

  uint64_t bytes_tx;
  /**<   Bytes transmitted by client . */

  int16_t vlan_id;
  /**<   VLAN Id of the client. */

  uint8_t ula_ipv6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   Link Local IPv6 address of the client. */
}qcmap_msgr_connected_device_info_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  qcmap_msgr_pcscf_info_type_v01 pcscf_info_type;
  /**<   Identifies the type of PCSCF information contained */

  uint8_t pcscf_ipv6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   Identifies the PCSCF IP6 address */

  char pcscf_fqdn[QCMAP_MSGR_PCSCF_FQDN_MAX_LENGTH_V01];
  /**<   Identifies the PCSCF FQDN */
}qcmap_msgr_ipv6_sip_server_info_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  char server_url[QCMAP_MSGR_DDNS_URL_LENGTH_V01];
  /**<   Identifies the server URL */
}qcmap_msgr_ddns_server_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  qcmap_msgr_wlan_iface_state_enum_v01 wlan_iface_state;

  char wlan_iface_name[QCMAP_MSGR_DEVICE_NAME_MAX_V01];

  qcmap_msgr_wlan_iface_type_enum_v01 wlan_iface_type;

  uint32_t ip4_addr;

  uint8_t ip6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];

  qcmap_msgr_ip_family_enum_v01 ip_type;
}qcmap_msgr_wlan_iface_state_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  qcmap_msgr_access_profile_v01 guest_ap_profile[QCMAP_MSGR_MAX_GUEST_AP_COUNT_V01];
}qcmap_msgr_guest_profile_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  char wan_iface[QCMAP_MAX_IFACE_NAME_SIZE_V01];
  /**<   As per linux/if.h, MAX_IFACE_NAME_SIZE is 16 for kernel v3.18
  */

  uint32_t service_no;
}qcmap_msgr_socksv5_wan_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  char uname[QCMAP_SOCKSV5_MAX_UNAME_PASSWD_LEN_V01];
  /**<   RFC 1929 max len is 255 for uname
  */

  uint32_t service_no;
}qcmap_msgr_socksv5_uname_assoc_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  char conf_file[QCMAP_SOCKSV5_MAX_UNAME_PASSWD_LEN_V01];
  /**<   File path to conf file
  */

  char auth_file[QCMAP_SOCKSV5_MAX_UNAME_PASSWD_LEN_V01];
  /**<   File path to auth file
  */
}qcmap_msgr_socksv5_config_file_paths_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure used to add gsb config entry
 */
typedef struct {

  char if_name[QCMAP_MAX_IFACE_NAME_SIZE_V01];
  /**<   name of Interface ex:eth0 or wlan1 etc */

  uint32_t bw_reqd_in_mb;
  /**<   bw requirement for interface */

  uint16_t if_high_watermark;
  /**<   high watermark requirement for interface */

  uint16_t if_low_watermark;
  /**<   low watermark requirement for interface */

  qcmap_msgr_gsb_interface_type_enum_v01 if_type;
  /**<   interface type. No need to use WLAN IF types
  for reference platforms For reference platform, WLAN IF
  is bridged to IPA dynamically.*/

  uint32_t ap_ip;
  /**<   ip address of A7. A7 ip information is managed
  with QCMAP if this parameter is not passed with API.
  Without QCMAP, this information should be passed to
  GSB using API*/
}qcmap_msgr_gsb_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure used for setting up SW IP channels
 */
typedef struct {

  char if_name[QCMAP_MAX_IFACE_NAME_SIZE_V01];
  /**<   Name of interface */

  uint32_t static_ip_addr;
  /**<   IP Address of logical interface*/

  uint8_t neigh_ll[QCMAP_MSGR_MAC_ADDR_LEN_V01];
  /**<   Neighbor link local address */

  uint32_t neigh_ip_address;
  /**<   Neighbor IP address */
}qcmap_msgr_sw_ip_ch_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  char local_iface[QCMAP_MAX_IFACE_NAME_SIZE_V01];

  int16_t vlan_id;

  uint8_t ipa_offload;
}qcmap_msgr_vlan_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  qcmap_msgr_interface_type_enum_v01 intf_type;

  int16_t vlan_id;

  uint8_t is_accelerated;
}qcmap_msgr_vlan_config_ex_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t enable;
}qcmap_msgr_set_unmanaged_l2tp_state_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t session_id;

  uint32_t peer_session_id;

  qcmap_ip4_addr_subnet_mask_v01 v4_addr;

  qcmap_ip6_addr_prefix_len_v01 v6_addr;
}qcmap_msgr_l2tp_session_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t local_tunnel_id;

  uint32_t peer_tunnel_id;

  char local_iface[QCMAP_MAX_IFACE_NAME_SIZE_V01];

  qcmap_msgr_ip_family_enum_v01 ip_family;

  uint8_t peer_ipv6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];

  uint32_t peer_ipv4_addr;

  qcmap_msgr_l2tp_encap_protocol_enum_v01 proto;

  uint16_t local_udp_port;

  uint16_t peer_udp_port;

  qcmap_msgr_l2tp_session_config_v01 session_config[QCMAP_MSGR_L2TP_MAX_SESSION_PER_TUNNEL_V01];
}qcmap_msgr_l2tp_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t enable;
}qcmap_msgr_l2tp_mtu_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t enable;
}qcmap_msgr_l2tp_TCP_MSS_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t tunnel_id;
}qcmap_msgr_delete_l2tp_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN. */

  int16_t vlan_id;
  /**<   vlan id. */
}qcmap_msgr_pdn_to_vlan_mapping_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  char iface_name[QCMAP_MAX_IFACE_NAME_SIZE_V01];

  uint32_t v4_addr;
  /**<   IPv4 address. */

  uint8_t v6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   IPv6 address. */

  uint32_t v4_prim_dns_addr;
  /**<   IPv4 primary DNS address. */

  uint32_t v4_sec_dns_addr;
  /**<   IPv4 secondary DNS address. */

  uint8_t v6_prim_dns_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   IPv6 primary DNS address. */

  uint8_t v6_sec_dns_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   IPv6 secondary DNS address. */
}qcmap_msgr_wwan_info_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data struct to represent WWAN details.
    Note, this struct has additional fields than qcmap_msgr_wwan_info struct

 */
typedef struct {

  uint32_t profile_handle;
  /**<   QCMAP Profile Handle. */

  int16_t profile_index_3gpp;
  /**<   3GPP Profile Index */

  int16_t profile_index_3gpp2;
  /**<   3GPP2 Profile Index */

  char iface_name[QCMAP_MAX_IFACE_NAME_SIZE_V01];
  /**<   WWAN interface on which backhaul is established */

  qcmap_msgr_data_bearer_tech_type_enum_v01 bearer_tech;
  /**<   Bearer Technology. Values: \n
      - QCMAP_MSGR_DATA_BEARER_TECH_UNKNOWN (0) --  Unknown bearer.
      - QCMAP_MSGR_DATA_BEARER_TECH_CDMA_1X (1) --  1X technology.
      - QCMAP_MSGR_DATA_BEARER_TECH_EVDO_REV0 (2) --  CDMA Rev 0.
      - QCMAP_MSGR_DATA_BEARER_TECH_EVDO_REVA (3) --  CDMA Rev A.
      - QCMAP_MSGR_DATA_BEARER_TECH_EVDO_REVB (4) --  CDMA Rev B.
      - QCMAP_MSGR_DATA_BEARER_TECH_EHRPD (5) --  EHRPD.
      - QCMAP_MSGR_DATA_BEARER_TECH_FMC (6) --  Fixed mobile convergence.
      - QCMAP_MSGR_DATA_BEARER_TECH_HRPD (7) --  HRPD
      - QCMAP_MSGR_DATA_BEARER_TECH_3GPP2_WLAN (8) --  IWLAN
      - QCMAP_MSGR_DATA_BEARER_TECH_WCDMA (9) --  WCDMA.
      - QCMAP_MSGR_DATA_BEARER_TECH_GPRS (10) --  GPRS.
      - QCMAP_MSGR_DATA_BEARER_TECH_HSDPA (11) --  HSDPA.
      - QCMAP_MSGR_DATA_BEARER_TECH_HSUPA (12) --  HSUPA.
      - QCMAP_MSGR_DATA_BEARER_TECH_EDGE (13) --  EDGE.
      - QCMAP_MSGR_DATA_BEARER_TECH_LTE (14) --  LTE.
      - QCMAP_MSGR_DATA_BEARER_TECH_HSDPA_PLUS (15) --  HSDPA+.
      - QCMAP_MSGR_DATA_BEARER_TECH_DC_HSDPA_PLUS (16) --  DC HSDPA+.
      - QCMAP_MSGR_DATA_BEARER_TECH_HSPA (17) --  HSPA
      - QCMAP_MSGR_DATA_BEARER_TECH_64_QAM (18) --  64 QAM.
      - QCMAP_MSGR_DATA_BEARER_TECH_TDSCDMA (19) --  TD-SCDMA.
      - QCMAP_MSGR_DATA_BEARER_TECH_GSM (20) --  GSM
      - QCMAP_MSGR_DATA_BEARER_TECH_3GPP_WLAN (21) --  IWLAN
      - QCMAP_MSGR_DATA_BEARER_TECH_5G (22) --  5G
 */

  uint32_t v4_addr;
  /**<   Public IPv4 Address */

  uint32_t v4_gw_addr;
  /**<   IPv4 Gateway Address */

  uint32_t v4_pri_dns_addr;
  /**<   IPv4 Primary DNS Address */

  uint32_t v4_sec_dns_addr;
  /**<   IPv4 Secondary DNS Address */

  uint8_t v6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   Public IPv6 Address */

  uint8_t v6_gw_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   IPv6 Gateway Address */

  uint8_t v6_pri_dns_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   IPv6 Primary DNS Address */

  uint8_t v6_sec_dns_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   IPv6 Secondary DNS Address */
}qcmap_msgr_wwan_info_ex_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure for IPv4 address and subnet mask for pmipv4 Secondary Router case
 */
typedef struct {

  uint32_t dmnp_prefix;
  /**<   DMNP prefix
  */

  uint8_t prefix_len;
  /**<   DMNP prefix length
  */
}qcmap_pmipv4_sec_router_param_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  int16_t curr_bridge;
  /**<   Current bridge number. */

  uint16_t num_of_bridges;
  /**<   count for number of bridges. */

  int16_t bridge_arr[QCMAP_MSGR_MAX_VLAN_ENTRIES_V01];
  /**<   Array of Bridge - VLAN IDs. */
}qcmap_msgr_bridge_list_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t service_id;
  /**<   Service ID. */

  qcmap_msgr_v2x_err_type_enum_v01 result;
  /**<   Result. */
}qcmap_msgr_v2x_result_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t service_id;
  /**<   Service ID. */

  uint16_t port;
  /**<   Port. */
}qcmap_msgr_v2x_non_sps_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t req_id;
  /**<  Request ID. */

  uint8_t sps_id;
  /**<   SPS ID.*/
}qcmap_msgr_v2x_sps_flow_id_info_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  qcmap_msgr_v2x_sps_flow_id_info_v01 flow_id;
  /**<   SPS flow IDs. */

  qcmap_msgr_v2x_err_type_enum_v01 result;
  /**<   Result. */
}qcmap_msgr_v2x_sps_flow_result_info_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  qcmap_msgr_v2x_non_sps_info_type_v01 reg_info;

  qcmap_msgr_protocol_enum_v01 protocol;
  /**<   Only UDP is currently supported.
  */
}qcmap_msgr_v2x_non_sps_flow_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t req_id;
  /**<   Request ID. */

  qcmap_msgr_v2x_service_sub_action_type_enum_v01 action;
  /**<   Action for service subscription.*/
}qcmap_msgr_v2x_service_sub_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t num_segments;
  /**<   Total number of segments for the configuration file.
  */

  uint16_t seg_index;
  /**<   Segment index. Starts from 1, increment by 1 only.
       Must be less than or equal to the total number of segments.
  */
}qcmap_msgr_v2x_config_file_seg_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  /*  Source L2 ID */
  uint32_t src_l2_id;
  /**<   Trusted Source L2 ID.
  */

  /*  Time Confidence Level */
  uint16_t time_confidence_level;
  /**<   Time confidence level. The range is from 0 to 127; 0  is
       invalid/unavailable, and 127 is the most confident.
  */

  /*  Position Confidence Level */
  uint16_t position_confidence_level;
  /**<   Position confidence level. The range is from 0 to 127; 0  is
       invalid/unavailable, and 127 is the most confident.
  */

  /*  Propagation Delay */
  uint32_t propagation_delay;
  /**<   Propagation delay in microseconds.
  */
}qcmap_msgr_v2x_trusted_ue_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  /*  Source L2 ID */
  uint32_t src_l2_id;
  /**<   Trusted source L2 ID.
  */

  /*  Time Uncertainty */
  float time_uncertainty;
  /**<   Time uncertainty in microseconds.
  */

  /*  Position Confidence Level */
  uint16_t position_confidence_level;
  /**<   Position confidence level. The range is from 0 to 127; 0  is
       invalid/unavailable, and 127 is the most confident.
  */

  /*  Propagation Delay */
  uint32_t propagation_delay;
  /**<   Propagation delay in microseconds.
  */
}qcmap_msgr_v2x_trusted_ue_info_ex_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t sps_id;
  /**<   SPS ID. */

  uint64_t utc_time;
  /**<   Absolute UTC start time of the next selected grant in nanoseconds. */

  uint32_t periodicity;
  /**<   Periodicity of the grant in milliseconds. */
}qcmap_msgr_v2x_sps_scheduling_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t pool_id;
  /**<  Pool ID */

  uint16_t min_freq;
  /**<   Minimum frequency in MHz */

  uint16_t max_freq;
  /**<   Maximum frequency in MHz */
}qcmap_msgr_v2x_tx_pool_id_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t priority;
  /**<   Promixmity service per packet priority from 1 to 8
       with 1 being the highest priority and 8 being the lowest. */

  uint16_t pdb;
  /**<  Packet delay budget in milliseconds. */
}qcmap_msgr_v2x_pppp_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t n79_hysteresis_timer;
  /**<   N79 Hysteresis Timer in seconds*/

  uint32_t wlan_hysteresis_timer;
  /**<   WLAN Hysteresis Timer in seconds*/

  uint32_t retries;
  /**<   Number Of Retries */

  uint32_t delay_between_retries;
  /**<   Delay Between Retries in seconds*/

  qcmap_msgr_n79_priority_enum_v01 priority;
  /**<   N79 vs WLAN priority */
}qcmap_msgr_n79_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_aggregates
    @{
  */
/**  Data structure used to obtain ETH port configuration
 */
typedef struct {

  qcmap_eth_network_type_v01 eth_nw_type;
  /**<   eth network type (LAN or WAN) */

  uint16_t port_num;
  /**<   port number ranging between 1-4 */

  int16_t vlan_id;
  /**<   VLAN id ranging between 1-4094 of the port number */
}qcmap_msgr_eth_port_config_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Registers or deregisters the control point to receive indications */
typedef struct {

  /* Optional */
  /*  Register backhaul status Indication */
  uint8_t backhaul_status_valid;  /**< Must be set to true if backhaul_status is being passed */
  uint8_t backhaul_status;
  /**<   Specifies whether to register for backhaul status information. Values:  \n
       - 0 -- Do not register for backahul status indication\n (default)
       - 1 -- Register for QMI_QCMAP_MSGR_BACKHAUL_STATUS_IND message
  */

  /* Optional */
  /*  Register wwan roaming status Indication */
  uint8_t wwan_roaming_valid;  /**< Must be set to true if wwan_roaming is being passed */
  uint8_t wwan_roaming;
  /**<   Specifies whether to register for wwan roaming status information. Values:  \n
       - 0 -- Do not register for wwan roaming status indication\n (default)
       - 1 -- Register for QMI_QCMAP_MSGR_WWAN_ROAMING_STATUS_IND message
  */

  /* Optional */
  /*  Register mobileap status Indication */
  uint8_t mobile_ap_status_valid;  /**< Must be set to true if mobile_ap_status is being passed */
  uint8_t mobile_ap_status;
  /**<   Specifies whether to register for mobileap status information. Values:  \n
       - 0 -- Do not register for mobileap status indication\n (default)
       - 1 -- Register for QMI_QCMAP_MSGR_MOBILE_AP_STATUS_IND message
  */

  /* Optional */
  /*  Register wwan status Indication */
  uint8_t wwan_status_valid;  /**< Must be set to true if wwan_status is being passed */
  uint8_t wwan_status;
  /**<   Specifies whether to register for wwan backhaul status information. Values:  \n
       - 0 -- Do not register for wwan backahul status indication\n (default)
       - 1 -- Register for QMI_QCMAP_MSGR_WWAN_STATUS_IND message
  */

  /* Optional */
  /*  Register station mode status Indication */
  uint8_t station_mode_status_valid;  /**< Must be set to true if station_mode_status is being passed */
  uint8_t station_mode_status;
  /**<   Specifies whether to register for station mode or WLAN backhaul status information. Values:  \n
       - 0 -- Do not register for station mode or WLAN backhaul status indication\n (default)
       - 1 -- Register for QMI_QCMAP_MSGR_STATION_MODE_STATUS_IND message
  */

  /* Optional */
  /*  Register wlan status Indication */
  uint8_t wlan_status_valid;  /**< Must be set to true if wlan_status is being passed */
  uint8_t wlan_status;
  /**<   Specifies whether to register for wlan status information. Values:  \n
       - 0 -- Do not register for wlan status indication\n (default)
       - 1 -- Register for QMI_QCMAP_MSGR_WLAN_STATUS_IND message
  */

  /* Optional */
  /*  Register cradle mode status Indication */
  uint8_t cradle_mode_status_valid;  /**< Must be set to true if cradle_mode_status is being passed */
  uint8_t cradle_mode_status;
  /**<   Specifies whether to register for cradle mode status information. Values:  \n
       - 0 -- Do not register for cradle mode status indication\n (default)
       - 1 -- Register for QMI_QCMAP_MSGR_CRADLE_MODE_STATUS_IND message
  */

  /* Optional */
  /*  Register ethernet mode status Indication */
  uint8_t ethernet_mode_status_valid;  /**< Must be set to true if ethernet_mode_status is being passed */
  uint8_t ethernet_mode_status;
  /**<   Specifies whether to register for ethernet mode status information. Values:  \n
       - 0 -- Do not register for ethernet mode status indication\n (default)
       - 1 -- Register for QMI_QCMAP_MSGR_ETHERNET_MODE_STATUS_IND message
  */

  /* Optional */
  /*  Register bt tethering status Indication */
  uint8_t bt_tethering_status_valid;  /**< Must be set to true if bt_tethering_status is being passed */
  uint8_t bt_tethering_status;
  /**<   Specifies whether to register for bluetooth tethering status information. Values:  \n
       - 0 -- Do not register for bluetooth tethering status indication\n (default)
       - 1 -- Register for QMI_QCMAP_MSGR_BT_TETHERING_STATUS_IND message
  */

  /* Optional */
  /*  Register bt tethering wan Indication */
  uint8_t bt_tethering_wan_valid;  /**< Must be set to true if bt_tethering_wan is being passed */
  uint8_t bt_tethering_wan;
  /**<   Specifies whether to register for bluetooth tethering wan information. Values:  \n
       - 0 -- Do not register for bluetooth tethering wan indication\n (default)
       - 1 -- Register for QMI_QCMAP_MSGR_BT_TETHERING_WAN_IND message
  */

  /* Optional */
  /*  Register packet stats status Indication */
  uint8_t packet_stats_status_valid;  /**< Must be set to true if packet_stats_status is being passed */
  uint8_t packet_stats_status;
  /**<   Specifies whether to register for packet status information. Values:  \n
       - 0 -- Do not register for packet status indication\n (default)
       - 1 -- Register for QMI_QCMAP_MSGR_PACKET_STATS_STATUS_IND message
  */

  /* Optional */
  /*  Register V2X Service Indication */
  uint8_t v2x_service_ind_mask_valid;  /**< Must be set to true if v2x_service_ind_mask is being passed */
  qcmap_msgr_v2x_indication_mask_v01 v2x_service_ind_mask;
  /**<   Specifies whether to register for V2X Service status information. Values: \n
      - QCMAP_MSGR_V2X_SPS_SCHEDULING_INFO_IND_MASK (0x00000001) --  V2X SPS Scheduling Indication Mask
      - QCMAP_MSGR_V2X_SRC_L2_INFO_IND_MASK (0x00000002) --  V2X Src L2 Info Indication Mask
      - QCMAP_MSGR_V2X_CAPABILITY_INFO_IND_MASK (0x00000004) --  V2X Capability Info Indication Mask
 */

  /* Optional */
  /*  Register Modem Status Indication */
  uint8_t modem_status_valid;  /**< Must be set to true if modem_status is being passed */
  uint8_t modem_status;
  /**<   Specifies whether to register for modem status information. Values:  \n
       - 0 -- Do not register for modem status indication\n (default)
       - 1 -- Register for QMI_QCMAP_MSGR_MODEM_STATUS_IND message
  */
}qcmap_msgr_indication_register_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Registers or deregisters the control point to receive indications */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_indication_register_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables the mobile AP functionality via a single mobile AP instance
    on the ARM\reg Cortex\tmns-A5 processor. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_mobile_ap_enable_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables the mobile AP functionality via a single mobile AP instance
    on the ARM\reg Cortex\tmns-A5 processor. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Mobile AP Handle */
  uint8_t mobile_ap_handle_valid;  /**< Must be set to true if mobile_ap_handle is being passed */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The mobile AP handle must be retained by the control point and
       specified in all mobile AP-specific QCMAP_MSGR messages. For example,
       QMI_QCMAP_MSGR_ MOBILE_AP_ DISABLE, QMI_ QCMAP_MSGR_BRING_UP_WWAN, etc.
       The mobile_ap_handle can be a handle from a previous successful
       mobile AP call activation. */
}qcmap_msgr_mobile_ap_enable_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Disables the mobile AP functionality for a mobile AP instance on
           the Cortex-A5 processor. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_mobile_ap_disable_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Disables the mobile AP functionality for a mobile AP instance on
           the Cortex-A5 processor. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_mobile_ap_disable_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables IPv4 and brings up an IPv4 WWAN call if autoconnect is enabled. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_enable_ipv4_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables IPv4 and brings up an IPv4 WWAN call if autoconnect is enabled. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_ipv4_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Disables IPv4 and brings down an IPv4 WWAN call if connected. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_disable_ipv4_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Disables IPv4 and brings down an IPv4 WWAN call if connected. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_ipv4_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the IPv4 state. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_ipv4_state_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the IPv4 state. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  IPV4 State Value */
  uint8_t ipv4_state_valid;  /**< Must be set to true if ipv4_state is being passed */
  uint8_t ipv4_state;
  /**<   Indicates whether IPv4 is enabled.
  */
}qcmap_msgr_get_ipv4_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables IPv6 and brings up an IPv6 WWAN call if autoconnect is enabled. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_enable_ipv6_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables IPv6 and brings up an IPv6 WWAN call if autoconnect is enabled. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_ipv6_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Disables IPv6 and brings down an IPv6 WWAN call if connected. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_disable_ipv6_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Disables IPv6 and brings down an IPv6 WWAN call if connected. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_ipv6_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the IPv6 state. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_ipv6_state_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the IPv6 state. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  IPv6 State Value */
  uint8_t ipv6_state_valid;  /**< Must be set to true if ipv6_state is being passed */
  uint8_t ipv6_state;
  /**<   Indicates whether IPv6 is enabled.
  */
}qcmap_msgr_get_ipv6_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Invokes bringing up the WWAN from the mobile AP. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WWAN Call Type */
  uint8_t call_type_valid;  /**< Must be set to true if call_type is being passed */
  qcmap_msgr_wwan_call_type_v01 call_type;
  /**<   Type of WWAN call to be brought up. Values: \n
      - QCMAP_MSGR_WWAN_CALL_TYPE_V4 (0x01) --  IPv4 call
      - QCMAP_MSGR_WWAN_CALL_TYPE_V6 (0x02) --  IPv6 call
      - QCMAP_MSGR_WWAN_CALL_TYPE_V4V6 (0x03) --  Dual call IPv4 and IPv6
      - QCMAP_MSGR_V2X_CALL_TYPE_V6 (0x04) --  V2X IPv6 call
 */

  /* Optional */
  /*  WWAN Profile number */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_bring_up_wwan_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Invokes bringing up the WWAN from the mobile AP. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  WWAN Connection Status */
  uint8_t conn_status_valid;  /**< Must be set to true if conn_status is being passed */
  qcmap_msgr_wwan_status_enum_v01 conn_status;
  /**<   WWAN connection status. Values: \n
      - QCMAP_MSGR_WWAN_STATUS_CONNECTING (0x01) --  IPv4 WWAN is in connecting state
      - QCMAP_MSGR_WWAN_STATUS_CONNECTING_FAIL (0x02) --  IPv4 connection to WWAN failed
      - QCMAP_MSGR_WWAN_STATUS_CONNECTED (0x03) --  IPv4 WWAN is in connected state
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTING (0x04) --  IPv4 WWAN is disconnecting
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTING_FAIL (0x05) --  IPv4 WWAN failed to disconnect
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTED (0x06) --  IPv4 WWAN is disconnected
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING (0x07) --  IPv6 WWAN is in connecting state
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING_FAIL (0x08) --  IPv6 connection to WWAN failed
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTED (0x09) --  IPv6 WWAN is in connected state
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING (0x0A) --  IPv6 WWAN is disconnecting
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING_FAIL (0x0B) --  IPv6 WWAN failed to disconnect
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTED (0x0C) --  IPv6 WWAN is disconnected
 */
}qcmap_msgr_bring_up_wwan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates the completion of processing a
           QMI_QCMAP_MSGR_BRING_UP_WWAN_REQ request. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Mandatory */
  /*  WWAN Connection Status */
  qcmap_msgr_wwan_status_enum_v01 conn_status;
  /**<   WWAN connection status. Values: \n
      - QCMAP_MSGR_WWAN_STATUS_CONNECTING (0x01) --  IPv4 WWAN is in connecting state
      - QCMAP_MSGR_WWAN_STATUS_CONNECTING_FAIL (0x02) --  IPv4 connection to WWAN failed
      - QCMAP_MSGR_WWAN_STATUS_CONNECTED (0x03) --  IPv4 WWAN is in connected state
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTING (0x04) --  IPv4 WWAN is disconnecting
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTING_FAIL (0x05) --  IPv4 WWAN failed to disconnect
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTED (0x06) --  IPv4 WWAN is disconnected
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING (0x07) --  IPv6 WWAN is in connecting state
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING_FAIL (0x08) --  IPv6 connection to WWAN failed
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTED (0x09) --  IPv6 WWAN is in connected state
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING (0x0A) --  IPv6 WWAN is disconnecting
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING_FAIL (0x0B) --  IPv6 WWAN failed to disconnect
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTED (0x0C) --  IPv6 WWAN is disconnected
 */

  /* Optional */
  /*  WWAN Call End Reason */
  uint8_t wwan_call_end_reason_valid;  /**< Must be set to true if wwan_call_end_reason is being passed */
  qcmap_msgr_wwan_call_end_reason_v01 wwan_call_end_reason;
  /**<   \n For values, refer to \hyperref[Q3]{[Q3]}.
   */

  /* Optional */
  /*  WWAN Profile number */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  WWAN Information */
  uint8_t wwan_info_valid;  /**< Must be set to true if wwan_info is being passed */
  qcmap_msgr_wwan_info_v01 wwan_info;
  /**<   Contains details of wwan information like device name
       primary and secondary ip addresses */
}qcmap_msgr_bring_up_wwan_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Tears down the WWAN. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WWAN Call Type */
  uint8_t call_type_valid;  /**< Must be set to true if call_type is being passed */
  qcmap_msgr_wwan_call_type_v01 call_type;
  /**<   Type of WWAN call to be brought down. Values: \n
      - QCMAP_MSGR_WWAN_CALL_TYPE_V4 (0x01) --  IPv4 call
      - QCMAP_MSGR_WWAN_CALL_TYPE_V6 (0x02) --  IPv6 call
      - QCMAP_MSGR_WWAN_CALL_TYPE_V4V6 (0x03) --  Dual call IPv4 and IPv6
      - QCMAP_MSGR_V2X_CALL_TYPE_V6 (0x04) --  V2X IPv6 call
 */

  /* Optional */
  /*  WWAN Profile number */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_tear_down_wwan_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Tears down the WWAN. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  WWAN Connection Status */
  uint8_t conn_status_valid;  /**< Must be set to true if conn_status is being passed */
  qcmap_msgr_wwan_status_enum_v01 conn_status;
  /**<   WWAN connection status. Values: \n
      - QCMAP_MSGR_WWAN_STATUS_CONNECTING (0x01) --  IPv4 WWAN is in connecting state
      - QCMAP_MSGR_WWAN_STATUS_CONNECTING_FAIL (0x02) --  IPv4 connection to WWAN failed
      - QCMAP_MSGR_WWAN_STATUS_CONNECTED (0x03) --  IPv4 WWAN is in connected state
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTING (0x04) --  IPv4 WWAN is disconnecting
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTING_FAIL (0x05) --  IPv4 WWAN failed to disconnect
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTED (0x06) --  IPv4 WWAN is disconnected
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING (0x07) --  IPv6 WWAN is in connecting state
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING_FAIL (0x08) --  IPv6 connection to WWAN failed
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTED (0x09) --  IPv6 WWAN is in connected state
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING (0x0A) --  IPv6 WWAN is disconnecting
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING_FAIL (0x0B) --  IPv6 WWAN failed to disconnect
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTED (0x0C) --  IPv6 WWAN is disconnected
 */
}qcmap_msgr_tear_down_wwan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates the completion of processing a
           QMI_QCMAP_MSGR_TEAR_DOWN_WWAN_REQ request. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Mandatory */
  /*  WWAN Connection Status */
  qcmap_msgr_wwan_status_enum_v01 conn_status;
  /**<   WWAN connection status. Values: \n
      - QCMAP_MSGR_WWAN_STATUS_CONNECTING (0x01) --  IPv4 WWAN is in connecting state
      - QCMAP_MSGR_WWAN_STATUS_CONNECTING_FAIL (0x02) --  IPv4 connection to WWAN failed
      - QCMAP_MSGR_WWAN_STATUS_CONNECTED (0x03) --  IPv4 WWAN is in connected state
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTING (0x04) --  IPv4 WWAN is disconnecting
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTING_FAIL (0x05) --  IPv4 WWAN failed to disconnect
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTED (0x06) --  IPv4 WWAN is disconnected
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING (0x07) --  IPv6 WWAN is in connecting state
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING_FAIL (0x08) --  IPv6 connection to WWAN failed
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTED (0x09) --  IPv6 WWAN is in connected state
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING (0x0A) --  IPv6 WWAN is disconnecting
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING_FAIL (0x0B) --  IPv6 WWAN failed to disconnect
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTED (0x0C) --  IPv6 WWAN is disconnected
 */

  /* Optional */
  /*  WWAN Call End Reason */
  uint8_t wwan_call_end_reason_valid;  /**< Must be set to true if wwan_call_end_reason is being passed */
  qcmap_msgr_wwan_call_end_reason_v01 wwan_call_end_reason;
  /**<   \n For possible values, refer to \hyperref[Q3]{[Q3]}.
   */

  /* Optional */
  /*  WWAN Profile number */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_tear_down_wwan_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the current mobile AP WWAN connection status. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
        QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Mandatory */
  /*  Packet Service Status */
  qcmap_msgr_wwan_status_enum_v01 wwan_status;
  /**<   Indicates the WWAN status. Values: \n
      - QCMAP_MSGR_WWAN_STATUS_CONNECTING (0x01) --  IPv4 WWAN is in connecting state
      - QCMAP_MSGR_WWAN_STATUS_CONNECTING_FAIL (0x02) --  IPv4 connection to WWAN failed
      - QCMAP_MSGR_WWAN_STATUS_CONNECTED (0x03) --  IPv4 WWAN is in connected state
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTING (0x04) --  IPv4 WWAN is disconnecting
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTING_FAIL (0x05) --  IPv4 WWAN failed to disconnect
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTED (0x06) --  IPv4 WWAN is disconnected
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING (0x07) --  IPv6 WWAN is in connecting state
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING_FAIL (0x08) --  IPv6 connection to WWAN failed
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTED (0x09) --  IPv6 WWAN is in connected state
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING (0x0A) --  IPv6 WWAN is disconnecting
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING_FAIL (0x0B) --  IPv6 WWAN failed to disconnect
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTED (0x0C) --  IPv6 WWAN is disconnected
 */

  /* Optional */
  /*  WWAN Call End Reason */
  uint8_t wwan_call_end_reason_valid;  /**< Must be set to true if wwan_call_end_reason is being passed */
  qcmap_msgr_wwan_call_end_reason_v01 wwan_call_end_reason;
  /**<   \n For possible values, refer to \hyperref[Q3]{[Q3]}.
   */

  /* Optional */
  /*  WWAN Profile number */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  WWAN Information */
  uint8_t wwan_info_valid;  /**< Must be set to true if wwan_info is being passed */
  qcmap_msgr_wwan_info_v01 wwan_info;
  /**<   Contains details of wwan information like device name
       primary and secondary ip addresses */
}qcmap_msgr_wwan_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the current mobile AP status. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Mandatory */
  /*  Mobile AP Status */
  qcmap_msgr_mobile_ap_status_enum_v01 mobile_ap_status;
  /**<   Indicates the mobile AP status. Values: \n
      - QCMAP_MSGR_MOBILE_AP_STATUS_CONNECTED (0x01) --  Mobile AP is connected
      - QCMAP_MSGR_MOBILE_AP_STATUS_DISCONNECTED (0x02) --  Mobile AP is disconnected
 */
}qcmap_msgr_mobile_ap_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the current station mode status. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Mandatory */
  /*  Station Mode Status */
  qcmap_msgr_station_mode_status_enum_v01 station_mode_status;
  /**<   Indicates the mobile AP status. Values: \n
      - QCMAP_MSGR_STATION_MODE_CONNECTED (0x01) --  Station mode is connected
      - QCMAP_MSGR_STATION_MODE_DISCONNECTED (0x02) --  Station mode is disconnected
      - QCMAP_MSGR_STATION_MODE_ASSOCIATION_FAIL (0x03) --  Station is not able to associated with AP
      - QCMAP_MSGR_STATION_MODE_DHCP_IP_ASSIGNMENT_FAIL (0x04) --  Station is not able to get IP address via DHCP
 */
}qcmap_msgr_station_mode_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables the WLAN. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  Privileged Client. */
  uint8_t privileged_client_valid;  /**< Must be set to true if privileged_client is being passed */
  uint8_t privileged_client;
  /**<   This flag indicates that the client who is trying to
       EnableWLAN is a privileged client which can access
       without enabling MobileAP.
  */
}qcmap_msgr_enable_wlan_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables the WLAN. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_wlan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Disables the WLAN. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  Privileged Client. */
  uint8_t privileged_client_valid;  /**< Must be set to true if privileged_client is being passed */
  uint8_t privileged_client;
  /**<   This flag indicates that the client who is trying to
       DisableWLAN is a privileged client which can access
       without enabling MobileAP.
  */
}qcmap_msgr_disable_wlan_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Disables the WLAN. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_wlan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the N79 configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  N79 Configuration Enable Flag */
  uint8_t enable;
  /**<   Values: \n
     - 0 -- Disable Configuration \n
     - 1 -- Enable Configuration
  */

  /* Optional */
  /*  Configuration */
  uint8_t n79_config_valid;  /**< Must be set to true if n79_config is being passed */
  qcmap_msgr_n79_config_v01 n79_config;
  /**<   Structure for N79 configuration
  */
}qcmap_msgr_set_n79_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the N79 configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_n79_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves the current N79 configuration. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_n79_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves the current N79 configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  N79 Configuration Is Enabled */
  uint8_t is_enabled_valid;  /**< Must be set to true if is_enabled is being passed */
  uint8_t is_enabled;

  /* Optional */
  /*  N79 configuration */
  uint8_t n79_config_valid;  /**< Must be set to true if n79_config is being passed */
  qcmap_msgr_n79_config_v01 n79_config;
}qcmap_msgr_get_n79_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Adds a static NAT entry. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  SNAT Entry Configuration */
  uint8_t snat_entry_config_valid;  /**< Must be set to true if snat_entry_config is being passed */
  qcmap_msgr_snat_entry_config_v01 snat_entry_config;

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  IP family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  /* Optional */
  /*  SNAT v6 Entry Configuration */
  uint8_t snat_v6_entry_config_valid;  /**< Must be set to true if snat_v6_entry_config is being passed */
  qcmap_msgr_snat_v6_entry_config_v01 snat_v6_entry_config;
  /**<   SNAT V6 configuration information.
  */
}qcmap_msgr_add_static_nat_entry_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Adds a static NAT entry. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_add_static_nat_entry_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Deletes a static NAT entry. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  SNAT Entry Configuration */
  uint8_t snat_entry_config_valid;  /**< Must be set to true if snat_entry_config is being passed */
  qcmap_msgr_snat_entry_config_v01 snat_entry_config;

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  IP family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  /* Optional */
  /*  SNAT V6 Entry Configuration */
  uint8_t snat_v6_entry_config_valid;  /**< Must be set to true if snat_v6_entry_config is being passed */
  qcmap_msgr_snat_v6_entry_config_v01 snat_v6_entry_config;
  /**<   SNAT V6 configuration information
  */
}qcmap_msgr_delete_static_nat_entry_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Deletes a static NAT entry. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_delete_static_nat_entry_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries all static NAT entries. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  IP family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */
}qcmap_msgr_get_static_nat_entries_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries all static NAT entries. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  SNAT Configuration */
  uint8_t snat_config_valid;  /**< Must be set to true if snat_config is being passed */
  uint32_t snat_config_len;  /**< Must be set to # of elements in snat_config */
  qcmap_msgr_snat_entry_config_v01 snat_config[QCMAP_MSGR_MAX_SNAT_ENTRIES_V01];

  /* Optional */
  /*  SNAT v6 Configuration */
  uint8_t snat_v6_config_valid;  /**< Must be set to true if snat_v6_config is being passed */
  uint32_t snat_v6_config_len;  /**< Must be set to # of elements in snat_v6_config */
  qcmap_msgr_snat_v6_entry_config_v01 snat_v6_config[QCMAP_MSGR_MAX_SNAT_ENTRIES_V01];
  /**<   IPv6 SNAT configuration entries returned.
  */
}qcmap_msgr_get_static_nat_entries_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the DMZ (perimeter network) IP address for the mobile AP. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  DMZ IP Address */
  uint8_t dmz_ip_addr_valid;  /**< Must be set to true if dmz_ip_addr is being passed */
  uint32_t dmz_ip_addr;
  /**<   DMZ IP address. */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  IP family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  /* Optional */
  /*  DMZ IPv6 Address */
  uint8_t dmz_ip6_addr_valid;  /**< Must be set to true if dmz_ip6_addr is being passed */
  uint8_t dmz_ip6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   DMZ IPv6 address. */
}qcmap_msgr_set_dmz_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the DMZ (perimeter network) IP address for the mobile AP. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_dmz_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the DMZ IP address on the mobile AP. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  IP family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */
}qcmap_msgr_get_dmz_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the DMZ IP address on the mobile AP. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  DMZ IP Address */
  uint8_t dmz_ip_addr_valid;  /**< Must be set to true if dmz_ip_addr is being passed */
  uint32_t dmz_ip_addr;
  /**<   DMZ IP address. */

  /* Optional */
  /*  DMZ IPv6 Address */
  uint8_t dmz_ip6_addr_valid;  /**< Must be set to true if dmz_ip6_addr is being passed */
  uint8_t dmz_ip6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   DMZ IPv6 address. */
}qcmap_msgr_get_dmz_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Deletes the DMZ entry or DMZ IP address. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  IP family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */
}qcmap_msgr_delete_dmz_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Deletes the DMZ entry or DMZ IP address. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_delete_dmz_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets WWAN statistics. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  IP Family */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version to be used. Values: \n
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_get_wwan_stats_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets WWAN statistics. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  WWAN Statistics */
  uint8_t wwan_stats_valid;  /**< Must be set to true if wwan_stats is being passed */
  qcmap_msgr_wwan_statistics_type_v01 wwan_stats;
}qcmap_msgr_get_wwan_stats_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Resets WWAN statistics. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  WWAN Entry With IP Version Configured */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version to be used. Values: \n
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_reset_wwan_stats_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Resets WWAN statistics. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_reset_wwan_stats_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Configures the Internet Protocol security (IPSec)
           Virtual Private Network (VPN) passthrough setting. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  VPN Passthrough Value */
  uint8_t vpn_pass_through_value;
  /**<   Indicates whether an IPSec VPN passthrough is allowed.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  IP Family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */
}qcmap_msgr_set_ipsec_vpn_pass_through_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Configures the Internet Protocol security (IPSec)
           Virtual Private Network (VPN) passthrough setting. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_ipsec_vpn_pass_through_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the IPSec VPN passthrough setting. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  IP Family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */
}qcmap_msgr_get_ipsec_vpn_pass_through_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the IPSec VPN passthrough setting. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  VPN Passthrough Value */
  uint8_t vpn_pass_through_value_valid;  /**< Must be set to true if vpn_pass_through_value is being passed */
  uint8_t vpn_pass_through_value;
  /**<   Indicates whether an IPSec VPN passthrough is allowed.
  */
}qcmap_msgr_get_ipsec_vpn_pass_through_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Configures the Point-to-Point Tunneling Protocol (PPTP) VPN
           passthrough setting. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  VPN Passthrough Value */
  uint8_t vpn_pass_through_value;
  /**<   Indicates whether a PPTP VPN passthrough is allowed.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  IP Family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */
}qcmap_msgr_set_pptp_vpn_pass_through_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Configures the Point-to-Point Tunneling Protocol (PPTP) VPN
           passthrough setting. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_pptp_vpn_pass_through_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the PPTP VPN passthrough setting. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  IP Family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */
}qcmap_msgr_get_pptp_vpn_pass_through_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the PPTP VPN passthrough setting. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  VPN Passthrough Value */
  uint8_t vpn_pass_through_value_valid;  /**< Must be set to true if vpn_pass_through_value is being passed */
  uint8_t vpn_pass_through_value;
  /**<   Indicates whether a PPTP VPN passthrough is allowed.
  */
}qcmap_msgr_get_pptp_vpn_pass_through_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Configures the Layer 2 Tunneling Protocol (L2TP) VPN passthrough
           setting. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  VPN Passthrough Value */
  uint8_t vpn_pass_through_value;
  /**<   Indicates whether an L2TP VPN passthrough is allowed.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  IP Family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */
}qcmap_msgr_set_l2tp_vpn_pass_through_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Configures the Layer 2 Tunneling Protocol (L2TP) VPN passthrough
           setting. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_l2tp_vpn_pass_through_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the L2TP VPN passthrough setting. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  IP Family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */
}qcmap_msgr_get_l2tp_vpn_pass_through_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the L2TP VPN passthrough setting. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  VPN Passthrough Value */
  uint8_t vpn_pass_through_value_valid;  /**< Must be set to true if vpn_pass_through_value is being passed */
  uint8_t vpn_pass_through_value;
  /**<   Indicates whether an L2TP VPN passthrough is allowed.
  */
}qcmap_msgr_get_l2tp_vpn_pass_through_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Configures the NAT type setting. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MOBILE_AP_ ENABLE_REQ.
   */

  /* Mandatory */
  /*  NAT Type Value */
  qcmap_msgr_nat_enum_v01 nat_type;
  /**<   Indicates the type of NAT. Values: \n
      - QCMAP_MSGR_NAT_SYMMETRIC_NAT (0) --  NAT type is symmetric
      - QCMAP_MSGR_NAT_PORT_RESTRICTED_CONE_NAT (1) --  NAT type is Port-Restricted Cone NAT
      - QCMAP_MSGR_NAT_FULL_CONE_NAT (2) --  NAT type is Full Cone NAT
      - QCMAP_MSGR_NAT_ADDRESS_RESTRICTED_NAT (3) --  NAT type is Address-Restricted NAT
 */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_set_nat_type_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Configures the NAT type setting. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_nat_type_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the NAT type setting. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
    The value must be the handle previously returned by
    QMI_QCMAP_MOBILE_AP_ ENABLE_REQ.
   */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_get_nat_type_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the NAT type setting. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  NAT Type Value */
  uint8_t nat_type_valid;  /**< Must be set to true if nat_type is being passed */
  qcmap_msgr_nat_enum_v01 nat_type;
  /**<   Indicates the type of NAT. Values: \n
      - QCMAP_MSGR_NAT_SYMMETRIC_NAT (0) --  NAT type is symmetric
      - QCMAP_MSGR_NAT_PORT_RESTRICTED_CONE_NAT (1) --  NAT type is Port-Restricted Cone NAT
      - QCMAP_MSGR_NAT_FULL_CONE_NAT (2) --  NAT type is Full Cone NAT
      - QCMAP_MSGR_NAT_ADDRESS_RESTRICTED_NAT (3) --  NAT type is Address-Restricted NAT
 */
}qcmap_msgr_get_nat_type_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the autoconnect flag. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Autoconnect Mode Flag */
  uint8_t enable;
  /**<   Enable/disable autoconnect. Values:\n
      - TRUE -- Enable\n
      - FALSE -- Disable
   */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_set_auto_connect_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the autoconnect flag. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_auto_connect_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the autoconnect flag. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_get_auto_connect_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the autoconnect flag. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Autoconnect Mode */
  uint8_t auto_conn_flag_valid;  /**< Must be set to true if auto_conn_flag is being passed */
  uint8_t auto_conn_flag;
  /**<   Autoconnect status. Values: \n
       - TRUE -- Enabled \n
       - FALSE -- Disabled
   */
}qcmap_msgr_get_auto_connect_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Configures whether QCMAP_MSGR initiates WWAN data calls while roaming. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Roaming Mode */
  uint8_t allow_wwan_calls_while_roaming;
  /**<   Whether QCMAP_MSGR connects a data call while roaming.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_set_roaming_pref_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Configures whether QCMAP_MSGR initiates WWAN data calls while roaming. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_roaming_pref_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the roaming flag. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_get_roaming_pref_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the roaming flag. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Roaming Mode */
  uint8_t allow_wwan_calls_while_roaming_valid;  /**< Must be set to true if allow_wwan_calls_while_roaming is being passed */
  uint8_t allow_wwan_calls_while_roaming;
  /**<   Whether QCMAP_MSGR connects a data call while device is in roaming.
  */
}qcmap_msgr_get_roaming_pref_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Adds IP filter-based firewall rules. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
         The value must be the handle previously returned by
         QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
    */

  /* Mandatory */
  /*  IP Version */
  qcmap_msgr_ip_family_enum_v01 ip_version;
  /**<   Identifies the firewall family version. Values: \n
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  /* Optional */
  /*  Next Protocol Header After the IP Header */
  uint8_t next_hdr_prot_valid;  /**< Must be set to true if next_hdr_prot is being passed */
  uint8_t next_hdr_prot;
  /**<   IPv4/IPv6 next header protocol. */

  /* Optional */
  /*  TCP, UDP, and TCP_UDP Source Port */
  uint8_t tcp_udp_src_valid;  /**< Must be set to true if tcp_udp_src is being passed */
  qcmap_tcp_udp_port_range_v01 tcp_udp_src;

  /* Optional */
  /*  TCP, UDP, and TCP_UDP Destination Port */
  uint8_t tcp_udp_dst_valid;  /**< Must be set to true if tcp_udp_dst is being passed */
  qcmap_tcp_udp_port_range_v01 tcp_udp_dst;

  /* Optional */
  /*  ICMP Type */
  uint8_t icmp_type_valid;  /**< Must be set to true if icmp_type is being passed */
  uint8_t icmp_type;
  /**<   ICMP type, as specified in the ICMP protocol
         (RFC 792 \hyperref[S3]{[S3]}). */

  /* Optional */
  /*  ICMP Code */
  uint8_t icmp_code_valid;  /**< Must be set to true if icmp_code is being passed */
  uint8_t icmp_code;
  /**<   ICMP code as specified in the ICMP protocol
         (RFC 792 \hyperref[S3]{[S3]}). */

  /* Optional */
  /*  ESP Security Parameter Index */
  uint8_t esp_spi_valid;  /**< Must be set to true if esp_spi is being passed */
  uint32_t esp_spi;
  /**<   Security parameter index, as specified in the ESP protocol
        (RFC 4303 \hyperref[S7]{[S7]}). */

  /* Optional */
  /*  IPv4 Source Address and Subnet Mask */
  uint8_t ip4_src_addr_valid;  /**< Must be set to true if ip4_src_addr is being passed */
  qcmap_ip4_addr_subnet_mask_v01 ip4_src_addr;

  /* Optional */
  /*  IPv4 Destination Address and Subnet Mask */
  uint8_t ip4_dst_addr_valid;  /**< Must be set to true if ip4_dst_addr is being passed */
  qcmap_ip4_addr_subnet_mask_v01 ip4_dst_addr;

  /* Optional */
  /*  IPv4 TOS Value and Mask */
  uint8_t ip4_tos_valid;  /**< Must be set to true if ip4_tos is being passed */
  qcmap_ip4_tos_v01 ip4_tos;

  /* Optional */
  /*  IPv6 Source Address and Prefix Length */
  uint8_t ip6_src_addr_valid;  /**< Must be set to true if ip6_src_addr is being passed */
  qcmap_ip6_addr_prefix_len_v01 ip6_src_addr;

  /* Optional */
  /*  IPv6 Destination Address and Prefix Length */
  uint8_t ip6_dst_addr_valid;  /**< Must be set to true if ip6_dst_addr is being passed */
  qcmap_ip6_addr_prefix_len_v01 ip6_dst_addr;

  /* Optional */
  /*  IPv6 Traffic Class Value and Mask */
  uint8_t ip6_trf_cls_valid;  /**< Must be set to true if ip6_trf_cls is being passed */
  qcmap_ip6_traffic_class_v01 ip6_trf_cls;

  /* Optional */
  /*  Firewall entry by UPNP Client */
  uint8_t upnp_pinhole_valid;  /**< Must be set to true if upnp_pinhole is being passed */
  uint8_t upnp_pinhole;
  /**<   This indicates if the firewall entry is being added
             through upnp client or not .
      */

  /* Optional */
  /*  Firewall Direction. */
  uint8_t direction_valid;  /**< Must be set to true if direction is being passed */
  qcmap_msgr_firewall_rule_direction_v01 direction;
  /**<   This indicates if the firewall entry needs to be applied
 in UL or DL direction. Values: \n
      - QCMAP_MSGR_UL_FIREWALL (0x01) --  Firewall rule will be applied in UL direction
      - QCMAP_MSGR_DL_FIREWALL (0x02) --  Firewall rule will be applied in DL direction
 */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
    */

  /* Optional */
  /*  IPv6 NAT FIREWALL ENTRY ENABLED */
  uint8_t ipv6_nat_firewall_entry_enabled_valid;  /**< Must be set to true if ipv6_nat_firewall_entry_enabled is being passed */
  uint8_t ipv6_nat_firewall_entry_enabled;
  /**<   IPv6 NAT Firewall entry enabled.
    */
}qcmap_msgr_add_firewall_entry_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Adds IP filter-based firewall rules. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Firewall Handle */
  uint8_t firewall_handle_valid;  /**< Must be set to true if firewall_handle is being passed */
  uint32_t firewall_handle;
  /**<   Identifies the handle for the added firewall rule. */
}qcmap_msgr_add_firewall_entry_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the handles of all firewall rules. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       Value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Mandatory */
  /*  IP Version */
  qcmap_msgr_ip_family_enum_v01 ip_version;
  /**<   Identifies the firewall family version. Values: \n
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_get_firewall_entries_handle_list_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the handles of all firewall rules. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Firewall Handle List */
  uint8_t firewall_handle_list_valid;  /**< Must be set to true if firewall_handle_list is being passed */
  uint32_t firewall_handle_list_len;  /**< Must be set to # of elements in firewall_handle_list */
  uint32_t firewall_handle_list[QCMAP_MSGR_MAX_FIREWALL_ENTRIES_V01];
  /**<   Handles identifying the firewall entry. The value must be the handle
       previously returned by QMI_QCMAP_MSGR_ ADD_FIREWALL_ENTRY_RESP.
   */
}qcmap_msgr_get_firewall_entries_handle_list_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets firewall rules. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Mandatory */
  /*  Firewall Handle */
  uint32_t firewall_handle;
  /**<   Handle identifying the firewall entry. The value must be the handle
       previously returned by
       QMI_QCMAP_MSGR_ADD_ FIREWALL_ENTRY_RESP,
       QMI_QCMAP_MSGR_GET_ FIREWALL_ENTRY_RESP, or
       QMI_QCMAP_MSGR_GET_ FIREWALL_ENTRIES_HANDLE_ LIST_RESP.
   */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_get_firewall_entry_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets firewall rules. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  IP Version */
  uint8_t ip_version_valid;  /**< Must be set to true if ip_version is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_version;
  /**<   Identifies the firewall family version. Values: \n
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  /* Optional */
  /*  Next Header Protocol */
  uint8_t next_hdr_prot_valid;  /**< Must be set to true if next_hdr_prot is being passed */
  uint8_t next_hdr_prot;
  /**<   IPv4/IPv6 next header protocol. */

  /* Optional */
  /*  TCP, UDP, and TCP_UDP Source Port */
  uint8_t tcp_udp_src_valid;  /**< Must be set to true if tcp_udp_src is being passed */
  qcmap_tcp_udp_port_range_v01 tcp_udp_src;

  /* Optional */
  /*  TCP, UDP, and TCP_UDP Destination Port */
  uint8_t tcp_udp_dst_valid;  /**< Must be set to true if tcp_udp_dst is being passed */
  qcmap_tcp_udp_port_range_v01 tcp_udp_dst;

  /* Optional */
  /*  ICMP Type */
  uint8_t icmp_type_valid;  /**< Must be set to true if icmp_type is being passed */
  uint8_t icmp_type;
  /**<   ICMP type, as specified in the ICMP protocol
       (RFC 792 \hyperref[S3]{[S3]}). */

  /* Optional */
  /*  ICMP Code */
  uint8_t icmp_code_valid;  /**< Must be set to true if icmp_code is being passed */
  uint8_t icmp_code;
  /**<   ICMP code, as specified in the ICMP protocol
       (RFC 792 \hyperref[S3]{[S3]}). */

  /* Optional */
  /*  ESP Security Parameter Index */
  uint8_t esp_spi_valid;  /**< Must be set to true if esp_spi is being passed */
  uint32_t esp_spi;
  /**<   Security parameter index, as specified in the ESP protocol
       (RFC 4303 \hyperref[S7]{[S7]}). */

  /* Optional */
  /*  IPv4 Source Address and Subnet Mask */
  uint8_t ip4_src_addr_valid;  /**< Must be set to true if ip4_src_addr is being passed */
  qcmap_ip4_addr_subnet_mask_v01 ip4_src_addr;

  /* Optional */
  /*  IPv4 Destination Address and Subnet Mask */
  uint8_t ip4_dst_addr_valid;  /**< Must be set to true if ip4_dst_addr is being passed */
  qcmap_ip4_addr_subnet_mask_v01 ip4_dst_addr;

  /* Optional */
  /*  IPv4 TOS Value and Mask */
  uint8_t ip4_tos_valid;  /**< Must be set to true if ip4_tos is being passed */
  qcmap_ip4_tos_v01 ip4_tos;

  /* Optional */
  /*  IPv6 Source Address and Prefix Length */
  uint8_t ip6_src_addr_valid;  /**< Must be set to true if ip6_src_addr is being passed */
  qcmap_ip6_addr_prefix_len_v01 ip6_src_addr;

  /* Optional */
  /*  IPv6 Destination Address and Prefix Length */
  uint8_t ip6_dst_addr_valid;  /**< Must be set to true if ip6_dst_addr is being passed */
  qcmap_ip6_addr_prefix_len_v01 ip6_dst_addr;

  /* Optional */
  /*  IPv6 Traffic Class Value and Mask */
  uint8_t ip6_trf_cls_valid;  /**< Must be set to true if ip6_trf_cls is being passed */
  qcmap_ip6_traffic_class_v01 ip6_trf_cls;

  /* Optional */
  /*  Firewall Direction. */
  uint8_t direction_valid;  /**< Must be set to true if direction is being passed */
  qcmap_msgr_firewall_rule_direction_v01 direction;

  /* Optional */
  /*  IPv6 NAT FIREWALL ENTRY ENABLED */
  uint8_t ipv6_nat_firewall_entry_enabled_valid;  /**< Must be set to true if ipv6_nat_firewall_entry_enabled is being passed */
  uint8_t ipv6_nat_firewall_entry_enabled;
  /**<   IPv6 NAT Firewall entry enabled.
  */
}qcmap_msgr_get_firewall_entry_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Deletes a firewall rule identified by a handle. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
         Value must be the handle previously returned by
         QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
    */

  /* Mandatory */
  /*  Firewall Handle */
  uint32_t firewall_handle;
  /**<   Handle identifying the firewall entry.
    */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
    */
}qcmap_msgr_delete_firewall_entry_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Deletes a firewall rule identified by a handle. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_delete_firewall_entry_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the WWAN IP configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Address Type */
  qcmap_msgr_addr_type_mask_v01 addr_type_op;
  /**<   WWAN configuration mask. Values: \n
      - QCMAP_MSGR_MASK_V4_ADDR (0x00000001) --  IPv4 address
      - QCMAP_MSGR_MASK_V6_ADDR (0x00000002) --  IPv6 address
      - QCMAP_MSGR_MASK_V4_DNS_ADDR (0x00000004) --  IPv4 DNS address
      - QCMAP_MSGR_MASK_V6_DNS_ADDR (0x00000008) --  IPv6 DNS address
 */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_get_wwan_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the WWAN IP configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  IPv4 Address */
  uint8_t v4_addr_valid;  /**< Must be set to true if v4_addr is being passed */
  uint32_t v4_addr;
  /**<   IPv4 address. */

  /* Optional */
  /*  IPv6 Address */
  uint8_t v6_addr_valid;  /**< Must be set to true if v6_addr is being passed */
  uint8_t v6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   IPv6 address. */

  /* Optional */
  /*  IPv4 Primary DNS Address */
  uint8_t v4_prim_dns_addr_valid;  /**< Must be set to true if v4_prim_dns_addr is being passed */
  uint32_t v4_prim_dns_addr;
  /**<   IPv4 primary DNS address. */

  /* Optional */
  /*  IPv4 Secondary DNS Address */
  uint8_t v4_sec_dns_addr_valid;  /**< Must be set to true if v4_sec_dns_addr is being passed */
  uint32_t v4_sec_dns_addr;
  /**<   IPv4 secondary DNS address. */

  /* Optional */
  /*  IPv6 Primary DNS Address */
  uint8_t v6_prim_dns_addr_valid;  /**< Must be set to true if v6_prim_dns_addr is being passed */
  uint8_t v6_prim_dns_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   IPv6 primary DNS address. */

  /* Optional */
  /*  IPv6 Secondary DNS Address */
  uint8_t v6_sec_dns_addr_valid;  /**< Must be set to true if v6_sec_dns_addr is being passed */
  uint8_t v6_sec_dns_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   IPv6 secondary DNS address. */
}qcmap_msgr_get_wwan_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Indicates a change in the current mobile AP status. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
         The value must be the handle previously returned by
         QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */
}qcmap_msgr_mobile_ap_status_req_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Indicates a change in the current mobile AP status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Mobile AP Status */
  uint8_t mobile_ap_status_valid;  /**< Must be set to true if mobile_ap_status is being passed */
  qcmap_msgr_mobile_ap_status_enum_v01 mobile_ap_status;
  /**<   Indicates the mobile AP status. Values: \n
      - QCMAP_MSGR_MOBILE_AP_STATUS_CONNECTED (0x01) --  Mobile AP is connected
      - QCMAP_MSGR_MOBILE_AP_STATUS_DISCONNECTED (0x02) --  Mobile AP is disconnected
 */
}qcmap_msgr_mobile_ap_status_resp_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the WWAN status. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WWAN Call Type */
  uint8_t call_type_valid;  /**< Must be set to true if call_type is being passed */
  qcmap_msgr_wwan_call_type_v01 call_type;
  /**<   WWAN call type for which the status is needed. Values: \n
      - QCMAP_MSGR_WWAN_CALL_TYPE_V4 (0x01) --  IPv4 call
      - QCMAP_MSGR_WWAN_CALL_TYPE_V6 (0x02) --  IPv6 call
      - QCMAP_MSGR_WWAN_CALL_TYPE_V4V6 (0x03) --  Dual call IPv4 and IPv6
      - QCMAP_MSGR_V2X_CALL_TYPE_V6 (0x04) --  V2X IPv6 call
 */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_wwan_status_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the WWAN status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  WWAN Connection Status */
  uint8_t conn_status_valid;  /**< Must be set to true if conn_status is being passed */
  qcmap_msgr_wwan_status_enum_v01 conn_status;
  /**<   WWAN connection status. Values: \n
      - QCMAP_MSGR_WWAN_STATUS_CONNECTING (0x01) --  IPv4 WWAN is in connecting state
      - QCMAP_MSGR_WWAN_STATUS_CONNECTING_FAIL (0x02) --  IPv4 connection to WWAN failed
      - QCMAP_MSGR_WWAN_STATUS_CONNECTED (0x03) --  IPv4 WWAN is in connected state
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTING (0x04) --  IPv4 WWAN is disconnecting
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTING_FAIL (0x05) --  IPv4 WWAN failed to disconnect
      - QCMAP_MSGR_WWAN_STATUS_DISCONNECTED (0x06) --  IPv4 WWAN is disconnected
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING (0x07) --  IPv6 WWAN is in connecting state
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTING_FAIL (0x08) --  IPv6 connection to WWAN failed
      - QCMAP_MSGR_WWAN_STATUS_IPV6_CONNECTED (0x09) --  IPv6 WWAN is in connected state
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING (0x0A) --  IPv6 WWAN is disconnecting
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTING_FAIL (0x0B) --  IPv6 WWAN failed to disconnect
      - QCMAP_MSGR_WWAN_STATUS_IPV6_DISCONNECTED (0x0C) --  IPv6 WWAN is disconnected
 */
}qcmap_msgr_wwan_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the Station Mode status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_station_mode_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the Station Mode status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  WWAN Connection Status */
  uint8_t conn_status_valid;  /**< Must be set to true if conn_status is being passed */
  qcmap_msgr_station_mode_status_enum_v01 conn_status;
  /**<   Station Mode connection status. Values: \n
      - QCMAP_MSGR_STATION_MODE_CONNECTED (0x01) --  Station mode is connected
      - QCMAP_MSGR_STATION_MODE_DISCONNECTED (0x02) --  Station mode is disconnected
      - QCMAP_MSGR_STATION_MODE_ASSOCIATION_FAIL (0x03) --  Station is not able to associated with AP
      - QCMAP_MSGR_STATION_MODE_DHCP_IP_ASSIGNMENT_FAIL (0x04) --  Station is not able to get IP address via DHCP
 */
}qcmap_msgr_get_station_mode_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Configures different types of NAT timeouts. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  NAT Timeout Type */
  qcmap_msgr_nat_timeout_enum_v01 nat_timeout_type;
  /**<   Indicates the NAT Timeout type to be used. Values: \n
      - QCMAP_MSGR_NAT_TIMEOUT_GENERIC (0x01) --   Generic NAT timeout
      - QCMAP_MSGR_NAT_TIMEOUT_ICMP (0x02) --   NAT timeout for ICMP
      - QCMAP_MSGR_NAT_TIMEOUT_TCP_ESTABLISHED (0x03) --   NAT timeout for the TCP established
      - QCMAP_MSGR_NAT_TIMEOUT_UDP (0x04) --   NAT timeout for UDP
      - QCMAP_MSGR_NAT_TIMEOUT_UDP_STREAM (0x05) --   NAT timeout for UDP stream
      - QCMAP_MSGR_NAT_TIMEOUT_ICMPV6 (0x06) --   NAT timeout for ICMPv6
 */

  /* Mandatory */
  /*  NAT Timeout Value */
  uint32_t timeout_value;
  /**<   Indicates the NAT Timeout value to be used, in seconds.
  */
}qcmap_msgr_set_nat_timeout_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Configures different types of NAT timeouts. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_nat_timeout_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the NAT timeout setting. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  NAT Timeout Type */
  qcmap_msgr_nat_timeout_enum_v01 nat_timeout_type;
  /**<   Indicates the NAT Timeout type to be used. Values:\n
      - QCMAP_MSGR_NAT_TIMEOUT_GENERIC (0x01) --   Generic NAT timeout
      - QCMAP_MSGR_NAT_TIMEOUT_ICMP (0x02) --   NAT timeout for ICMP
      - QCMAP_MSGR_NAT_TIMEOUT_TCP_ESTABLISHED (0x03) --   NAT timeout for the TCP established
      - QCMAP_MSGR_NAT_TIMEOUT_UDP (0x04) --   NAT timeout for UDP
      - QCMAP_MSGR_NAT_TIMEOUT_UDP_STREAM (0x05) --   NAT timeout for UDP stream
      - QCMAP_MSGR_NAT_TIMEOUT_ICMPV6 (0x06) --   NAT timeout for ICMPv6
 */
}qcmap_msgr_get_nat_timeout_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the NAT timeout setting. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  NAT Timeout */
  uint8_t timeout_value_valid;  /**< Must be set to true if timeout_value is being passed */
  uint32_t timeout_value;
  /**<   Indicates the required timeout value, in seconds.
  */
}qcmap_msgr_get_nat_timeout_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the LAN configuration. */
typedef struct {

  /* Optional */
  /*  AP LAN Configuration */
  uint8_t lan_config_valid;  /**< Must be set to true if lan_config is being passed */
  qcmap_msgr_lan_config_v01 lan_config;
}qcmap_msgr_set_lan_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the LAN configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_lan_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the WLAN configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WLAN Mode */
  uint8_t wlan_mode_valid;  /**< Must be set to true if wlan_mode is being passed */
  qcmap_msgr_wlan_mode_enum_v01 wlan_mode;
  /**<   Identifies the WLAN mode. Values: \n
      - QCMAP_MSGR_WLAN_MODE_AP (0x01) --  WLAN is in AP mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP (0x02) --  WLAN is in AP/AP Mode
      - QCMAP_MSGR_WLAN_MODE_AP_STA (0x03) --  WLAN is in AP/STA Mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP_AP (0x04) --  WLAN is in AP/AP/AP Mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP_STA (0x05) --  WLAN is in AP/AP/STA Mode
      - QCMAP_MSGR_WLAN_MODE_STA_ONLY (0x06) --  WLAN is in STA only Mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP_AP_AP (0x07) --  WLAN is in AP-AP-AP-AP Mode
      - QCMAP_MSGR_WLAN_MODE_AP_STA_BRIDGE (0x08) --  WLAN is in AP/STA Bridge Mode
       Only used for GetWLANStatus
      - QCMAP_MSGR_WLAN_MODE_AP_AP_STA_BRIDGE (0x09) --  WLAN is in AP/AP/STA Bridge Mode
       Only used for GetWLANStatus
      - QCMAP_MSGR_WLAN_MODE_STA_ONLY_BRIDGE (0x0A) --  WLAN is in STA Bridge Mode
       Only used for GetWLANStatus
      - QCMAP_MSGR_WLAN_MODE_AP_P2P (0x0B) --  WLAN is in Concurrent AP/P2P mode
      - QCMAP_MSGR_WLAN_MODE_STA_P2P (0x0C) --  WLAN is in Concurrent STA/P2P mode
 */

  /* Optional */
  /*  Guest AP Access profile */
  uint8_t guest_ap_access_profile_valid;  /**< Must be set to true if guest_ap_access_profile is being passed */
  qcmap_msgr_access_profile_v01 guest_ap_access_profile;
  /**<   Sets guest ap access profile \n
  */

  /* Optional */
  /*  Guest AP 2 Access profile */
  uint8_t guest_ap_2_access_profile_valid;  /**< Must be set to true if guest_ap_2_access_profile is being passed */
  qcmap_msgr_access_profile_v01 guest_ap_2_access_profile;
  /**<   Sets second guest ap access profile \n
  */

  /* Optional */
  /*  Guest AP 3 Access profile */
  uint8_t guest_ap_3_access_profile_valid;  /**< Must be set to true if guest_ap_3_access_profile is being passed */
  qcmap_msgr_access_profile_v01 guest_ap_3_access_profile;
  /**<   Sets third guest ap access profile \n
  */

  /* Optional */
  /*  Station Configuration */
  uint8_t station_config_valid;  /**< Must be set to true if station_config is being passed */
  qcmap_msgr_station_mode_config_v01 station_config;
}qcmap_msgr_set_wlan_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the WLAN configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_wlan_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the WLAN status. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
        The value must be the handle previously returned by
        QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
   */
}qcmap_msgr_get_wlan_status_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the WLAN status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  WLAN Mode */
  uint8_t wlan_mode_valid;  /**< Must be set to true if wlan_mode is being passed */
  qcmap_msgr_wlan_mode_enum_v01 wlan_mode;
  /**<   Identifies the WLAN mode. Values: \n
      - QCMAP_MSGR_WLAN_MODE_AP (0x01) --  WLAN is in AP mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP (0x02) --  WLAN is in AP/AP Mode
      - QCMAP_MSGR_WLAN_MODE_AP_STA (0x03) --  WLAN is in AP/STA Mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP_AP (0x04) --  WLAN is in AP/AP/AP Mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP_STA (0x05) --  WLAN is in AP/AP/STA Mode
      - QCMAP_MSGR_WLAN_MODE_STA_ONLY (0x06) --  WLAN is in STA only Mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP_AP_AP (0x07) --  WLAN is in AP-AP-AP-AP Mode
      - QCMAP_MSGR_WLAN_MODE_AP_STA_BRIDGE (0x08) --  WLAN is in AP/STA Bridge Mode
       Only used for GetWLANStatus
      - QCMAP_MSGR_WLAN_MODE_AP_AP_STA_BRIDGE (0x09) --  WLAN is in AP/AP/STA Bridge Mode
       Only used for GetWLANStatus
      - QCMAP_MSGR_WLAN_MODE_STA_ONLY_BRIDGE (0x0A) --  WLAN is in STA Bridge Mode
       Only used for GetWLANStatus
      - QCMAP_MSGR_WLAN_MODE_AP_P2P (0x0B) --  WLAN is in Concurrent AP/P2P mode
      - QCMAP_MSGR_WLAN_MODE_STA_P2P (0x0C) --  WLAN is in Concurrent STA/P2P mode
 */
}qcmap_msgr_get_wlan_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Activates the WLAN with the latest configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_activate_wlan_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Activates the WLAN with the latest configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_activate_wlan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Activates the LAN with the latest configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_activate_lan_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Activates the LAN with the latest configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_activate_lan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the LAN configuration. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_lan_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the LAN configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  AP Configuration */
  uint8_t lan_config_valid;  /**< Must be set to true if lan_config is being passed */
  qcmap_msgr_lan_config_v01 lan_config;

  /* Optional */
  /*  WLAN and USB Configuration on Access Point */
  uint8_t ap_wlan_usb_ip_config_valid;  /**< Must be set to true if ap_wlan_usb_ip_config is being passed */
  qcmap_msgr_ap_mode_wlan_usb_ip_config_v01 ap_wlan_usb_ip_config;
}qcmap_msgr_get_lan_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the WLAN configuration. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_wlan_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the WLAN configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  WLAN mode */
  uint8_t wlan_mode_valid;  /**< Must be set to true if wlan_mode is being passed */
  qcmap_msgr_wlan_mode_enum_v01 wlan_mode;
  /**<   Identifies the WLAN mode. Values: \n
      - QCMAP_MSGR_WLAN_MODE_AP (0x01) --  WLAN is in AP mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP (0x02) --  WLAN is in AP/AP Mode
      - QCMAP_MSGR_WLAN_MODE_AP_STA (0x03) --  WLAN is in AP/STA Mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP_AP (0x04) --  WLAN is in AP/AP/AP Mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP_STA (0x05) --  WLAN is in AP/AP/STA Mode
      - QCMAP_MSGR_WLAN_MODE_STA_ONLY (0x06) --  WLAN is in STA only Mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP_AP_AP (0x07) --  WLAN is in AP-AP-AP-AP Mode
      - QCMAP_MSGR_WLAN_MODE_AP_STA_BRIDGE (0x08) --  WLAN is in AP/STA Bridge Mode
       Only used for GetWLANStatus
      - QCMAP_MSGR_WLAN_MODE_AP_AP_STA_BRIDGE (0x09) --  WLAN is in AP/AP/STA Bridge Mode
       Only used for GetWLANStatus
      - QCMAP_MSGR_WLAN_MODE_STA_ONLY_BRIDGE (0x0A) --  WLAN is in STA Bridge Mode
       Only used for GetWLANStatus
      - QCMAP_MSGR_WLAN_MODE_AP_P2P (0x0B) --  WLAN is in Concurrent AP/P2P mode
      - QCMAP_MSGR_WLAN_MODE_STA_P2P (0x0C) --  WLAN is in Concurrent STA/P2P mode
 */

  /* Optional */
  /*  Station Configuration */
  uint8_t station_config_valid;  /**< Must be set to true if station_config is being passed */
  qcmap_msgr_station_mode_config_v01 station_config;

  /* Optional */
  /*  Guest Configuration on Access Point */
  uint8_t guest_ap_access_profile_valid;  /**< Must be set to true if guest_ap_access_profile is being passed */
  qcmap_msgr_access_profile_v01 guest_ap_access_profile;

  /* Optional */
  /*  Guest Configuration on Access Point 2 */
  uint8_t guest_ap_2_access_profile_valid;  /**< Must be set to true if guest_ap_2_access_profile is being passed */
  qcmap_msgr_access_profile_v01 guest_ap_2_access_profile;

  /* Optional */
  /*  Guest Configuration on Access Point 3 */
  uint8_t guest_ap_3_access_profile_valid;  /**< Must be set to true if guest_ap_3_access_profile is being passed */
  qcmap_msgr_access_profile_v01 guest_ap_3_access_profile;
}qcmap_msgr_get_wlan_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Activates the HOSTAPD with the latest configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  AP type */
  uint8_t ap_type_valid;  /**< Must be set to true if ap_type is being passed */
  qcmap_msgr_activate_hostapd_ap_enum_v01 ap_type;
  /**<   Identifies the AP for which settings need to be activated. Values: \n
      - QCMAP_MSGR_PRIMARY_AP (0x01) --  Primary AP.
      - QCMAP_MSGR_GUEST_AP (0x02) --  Guest AP.
      - QCMAP_MSGR_GUEST_AP_2 (0x03) --  Guest AP 2.
      - QCMAP_MSGR_GUEST_AP_3 (0x04) --  Guest AP 3.
      - QCMAP_MSGR_ALL_AP (0x05) --  All the Primary and Guest AP's.
 */

  /* Optional */
  /*  Action Type */
  uint8_t action_type_valid;  /**< Must be set to true if action_type is being passed */
  qcmap_msgr_activate_hostapd_action_enum_v01 action_type;
  /**<   Identifies the hostapd action which needs to be activated. Values: \n
      - QCMAP_MSGR_HOSTAPD_START (0x01) --  Start hostapd.
      - QCMAP_MSGR_HOSTAPD_STOP (0x02) --  Stop hostapd.
      - QCMAP_MSGR_HOSTAPD_RESTART (0x03) --  Restart hostapd.
 */

  /* Optional */
  /*  Privileged Client. */
  uint8_t privileged_client_valid;  /**< Must be set to true if privileged_client is being passed */
  uint8_t privileged_client;
  /**<   This flag indicates the client that is trying to
       activate hostapd is a privileged client which can access
       without enabling MobileAP.
  */
}qcmap_msgr_activate_hostapd_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Activates the HOSTAPD with the latest configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_activate_hostapd_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Activates the supplicant with the latest configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_activate_supplicant_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Activates the supplicant with the latest configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_activate_supplicant_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets up a link for RNDIS/ECM/PPP/ETH tethering. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  USB Interface Name */
  qcmap_msgr_usb_link_enum_v01 usb_link;
  /**<   Identifies the USB tethered link type. Values: \n
      - QCMAP_MSGR_USB_LINK_RNDIS (0x01) --  tethered link is RNDIS
      - QCMAP_MSGR_USB_LINK_ECM (0x02) --  tethered link is ECM
      - QCMAP_MSGR_USB_LINK_PPP (0x03) --  tethered link is PPP
      - QCMAP_MSGR_TETHERED_LINK_ETH (0x04) --  tethered link is ETH
      - QCMAP_MSGR_TETHERED_LINK_RMNET_USB (0x05) --  tethered link is RMNET_USB
 */

  /* Optional */
  /*  USB Device ID */
  uint8_t dev_id_valid;  /**< Must be set to true if dev_id is being passed */
  uint16_t dev_id;
  /**<   Identifies the USB tethered link id.
  */
}qcmap_msgr_usb_link_up_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets up a link for RNDIS/ECM/PPP/ETH tethering. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_usb_link_up_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Brings down a link for RNDIS/ECM/PPP/ETH tethering. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  USB Interface Name */
  qcmap_msgr_usb_link_enum_v01 usb_link;
  /**<   Identifies the USB tethered link type. Values: \n
      - QCMAP_MSGR_USB_LINK_RNDIS (0x01) --  tethered link is RNDIS
      - QCMAP_MSGR_USB_LINK_ECM (0x02) --  tethered link is ECM
      - QCMAP_MSGR_USB_LINK_PPP (0x03) --  tethered link is PPP
      - QCMAP_MSGR_TETHERED_LINK_ETH (0x04) --  tethered link is ETH
      - QCMAP_MSGR_TETHERED_LINK_RMNET_USB (0x05) --  tethered link is RMNET_USB
 */

  /* Optional */
  /*  USB Device ID */
  uint8_t dev_id_valid;  /**< Must be set to true if dev_id is being passed */
  uint16_t dev_id;
  /**<   Identifies the USB tethered link id.
  */
}qcmap_msgr_usb_link_down_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Brings down a link for RNDIS/ECM/PPP/ETH tethering. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_usb_link_down_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the WWAN policy. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
   */

  /* Mandatory */
  /*  WWAN Policy */
  qcmap_msgr_net_policy_info_v01 wwan_policy;
}qcmap_msgr_set_wwan_policy_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the WWAN policy. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_set_wwan_policy_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Create a WWAN policy. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
   */

  /* Mandatory */
  /*  WWAN Policy */
  qcmap_msgr_net_policy_info_v01 wwan_policy;
}qcmap_msgr_create_wwan_policy_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Create a WWAN policy. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  WWAN Profile number */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_create_wwan_policy_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Update a WWAN policy. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
   */

  /* Optional */
  /*  Profile Handle */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;

  /* Optional */
  /*  Profile enum */
  uint8_t update_req_valid;  /**< Must be set to true if update_req is being passed */
  qcmap_msgr_update_profile_enum_v01 update_req;
  /**<   This indicates whether tech type or V4/V6 or 3GPP/3GPP2
       info for profile needs to be updated
  */

  /* Optional */
  /*  WWAN Policy */
  uint8_t wwan_policy_valid;  /**< Must be set to true if wwan_policy is being passed */
  qcmap_msgr_net_policy_info_v01 wwan_policy;
}qcmap_msgr_update_wwan_policy_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Update a WWAN policy. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_update_wwan_policy_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the WWAN policy. */
typedef struct {

  /* Optional */
  /*  WWAN Profile number */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_get_wwan_policy_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the WWAN policy. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  WWAN Policy */
  uint8_t wwan_policy_valid;  /**< Must be set to true if wwan_policy is being passed */
  qcmap_msgr_net_policy_info_v01 wwan_policy;
}qcmap_msgr_get_wwan_policy_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables UPnP discovery of other networked devices. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_enable_upnp_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables UPnP discovery of other networked devices. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_upnp_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Disables UPnP discovery of other networked devices. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_disable_upnp_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Disables UPnP discovery of other networked devices. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_upnp_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables a DLNA media server to share content with network devices. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_enable_dlna_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables a DLNA media server to share content with network devices. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_dlna_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Disables a DLNA media server from sharing content with network devices. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_disable_dlna_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Disables a DLNA media server from sharing content with network devices. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_dlna_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the firewall configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Firewall Enabled */
  uint8_t firewall_enabled;
  /**<   Indicates whether the firewall is to be enabled or disabled.
  */

  /* Optional */
  /*  Accept or Drop Packets */
  uint8_t pkts_allowed_valid;  /**< Must be set to true if pkts_allowed is being passed */
  uint8_t pkts_allowed;
  /**<   Indicates whether packets are to be accepted or dropped.
  */

  /* Optional */
  /*  Allow or Deny UPNP Pinhole */
  uint8_t upnp_pinhole_flag_valid;  /**< Must be set to true if upnp_pinhole_flag is being passed */
  uint8_t upnp_pinhole_flag;
  /**<   Indicates whether pinhole can be allowed or not through UPNP client.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */

  /* Optional */
  /*  Firewall v6 Enabled */
  uint8_t firewall_v6_enabled_valid;  /**< Must be set to true if firewall_v6_enabled is being passed */
  uint8_t firewall_v6_enabled;
  /**<   Indicates whether the v6 firewall is to be enabled or disabled
  */

  /* Optional */
  /*  Accept or Drop v6 Packets */
  uint8_t v6_pkts_allowed_valid;  /**< Must be set to true if v6_pkts_allowed is being passed */
  uint8_t v6_pkts_allowed;
  /**<   Indicates whether v6 packets are to be accepted or dropped
  */
}qcmap_msgr_set_firewall_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the firewall configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_firewall_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the firewall configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_get_firewall_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the firewall configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Firewall Enabled */
  uint8_t firewall_enabled_valid;  /**< Must be set to true if firewall_enabled is being passed */
  uint8_t firewall_enabled;
  /**<   Indicates whether the firewall is enabled or disabled.
  */

  /* Optional */
  /*  Accept or Drop Packets */
  uint8_t pkts_allowed_valid;  /**< Must be set to true if pkts_allowed is being passed */
  uint8_t pkts_allowed;
  /**<   Indicates whether packets are accepted or dropped.
  */

  /* Optional */
  /*  Allow or Deny UPNP Pinhole */
  uint8_t upnp_pinhole_flag_valid;  /**< Must be set to true if upnp_pinhole_flag is being passed */
  uint8_t upnp_pinhole_flag;
  /**<   Indicates the current status of upnp pinhole.
  */

  /* Optional */
  /*  Firewall v6 Enabled */
  uint8_t v6_firewall_enabled_valid;  /**< Must be set to true if v6_firewall_enabled is being passed */
  uint8_t v6_firewall_enabled;
  /**<   Indicates whether the firewall v6 is enabled or disabled.
  */

  /* Optional */
  /*  Accept or Drop v6 Packets */
  uint8_t v6_pkts_allowed_valid;  /**< Must be set to true if v6_pkts_allowed is being passed */
  uint8_t v6_pkts_allowed;
  /**<   Indicates whether v6 packets are accepted or dropped.
  */
}qcmap_msgr_get_firewall_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables service discovery over a local LAN using multicast DNS. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_enable_multicast_dns_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables service discovery over a local LAN using multicast DNS. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_multicast_dns_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Disables service discovery over a local LAN using multicast DNS. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_disable_multicast_dns_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Disables service discovery over a local LAN using multicast DNS. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_multicast_dns_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the UPnP status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_upnp_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the UPnP status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  UPNP Mode */
  uint8_t upnp_mode_valid;  /**< Must be set to true if upnp_mode is being passed */
  qcmap_msgr_upnp_mode_enum_v01 upnp_mode;
  /**<   Identifies the UPnP mode. Values: \n
      - QCMAP_MSGR_UPNP_MODE_UP (0x01) --  UPNP is in AP mode
      - QCMAP_MSGR_UPNP_MODE_DOWN (0x02) --  UPNP is in AP/AP Mode
 */
}qcmap_msgr_get_upnp_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the DLNA status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_dlna_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the DLNA status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  DLNA Mode */
  uint8_t dlna_mode_valid;  /**< Must be set to true if dlna_mode is being passed */
  qcmap_msgr_dlna_mode_enum_v01 dlna_mode;
  /**<   Identifies the DLNA mode. Values: \n
      - QCMAP_MSGR_DLNA_MODE_UP (0x01) --  DLNA is in AP mode
      - QCMAP_MSGR_DLNA_MODE_DOWN (0x02) --  DLNA is in AP/AP Mode
 */
}qcmap_msgr_get_dlna_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the Multicast DNS status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_multicast_dns_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the Multicast DNS status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  MDNS Mode */
  uint8_t mdns_mode_valid;  /**< Must be set to true if mdns_mode is being passed */
  qcmap_msgr_mdns_mode_enum_v01 mdns_mode;
  /**<   Identifies the Multicast DNS mode. Values: \n
      - QCMAP_MSGR_MDNS_MODE_UP (0x01) --  MDNS is in AP mode
      - QCMAP_MSGR_MDNS_MODE_DOWN (0x02) --  MDNS is in AP/AP Mode
 */
}qcmap_msgr_get_multicast_dns_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets Bootup values for MobileAP components. */
typedef struct {

  /* Optional */
  /*  Mobile AP Bootup Flag */
  uint8_t mobileap_bootup_flag_valid;  /**< Must be set to true if mobileap_bootup_flag is being passed */
  qcmap_msgr_bootup_flag_v01 mobileap_bootup_flag;
  /**<   This flag is used to start Mobile AP on bootup.
        If set to true Mobile AP would be enabled on bootup.
  */

  /* Optional */
  /*  WLAN Bootup Flag */
  uint8_t wlan_bootup_flag_valid;  /**< Must be set to true if wlan_bootup_flag is being passed */
  qcmap_msgr_bootup_flag_v01 wlan_bootup_flag;
  /**<   This flag is used to bring up WLAN on bootup.
        If set to true, then WLAN would be enabled on bootup.
  */
}qcmap_msgr_set_qcmap_bootup_cfg_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets Bootup values for MobileAP components. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_qcmap_bootup_cfg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets Bootup values for QCMAP components
    on the ARM\reg Cortex\tmns-A5 processor. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_qcmap_bootup_cfg_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets Bootup values for QCMAP components
    on the ARM\reg Cortex\tmns-A5 processor. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Mobile AP Bootup Flag */
  uint8_t mobileap_bootup_flag_valid;  /**< Must be set to true if mobileap_bootup_flag is being passed */
  qcmap_msgr_bootup_flag_v01 mobileap_bootup_flag;
  /**<   This flag will indicate the bootup behaviour of Mobile AP.
        If found to be true, Mobile AP would be enabled on bootup.
  */

  /* Optional */
  /*  WLAN Bootup Flag */
  uint8_t wlan_bootup_flag_valid;  /**< Must be set to true if wlan_bootup_flag is being passed */
  qcmap_msgr_bootup_flag_v01 wlan_bootup_flag;
  /**<   This flag indicated the bootup behaviour of WLAN.
        If found to be true, WLAN would be enabled on bootup.
  */
}qcmap_msgr_get_qcmap_bootup_cfg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the DLNA media directory. */
typedef struct {

  /* Mandatory */
  /*  Media Directory */
  uint32_t media_dir_len;  /**< Must be set to # of elements in media_dir */
  char media_dir[QCMAP_MSGR_MAX_DLNA_DIR_LEN_V01];
}qcmap_msgr_set_dlna_media_dir_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the DLNA media directory. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_dlna_media_dir_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves the DLNA media directory. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_dlna_media_dir_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves the DLNA media directory. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Media Directory */
  uint8_t media_dir_valid;  /**< Must be set to true if media_dir is being passed */
  uint32_t media_dir_len;  /**< Must be set to # of elements in media_dir */
  char media_dir[QCMAP_MSGR_MAX_DLNA_DIR_LEN_V01];
}qcmap_msgr_get_dlna_media_dir_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves the current data bitrates. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  WWAN Profile number */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN.
  */
}qcmap_msgr_get_data_bitrate_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves the current data bitrates. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Media Directory */
  uint8_t data_rate_valid;  /**< Must be set to true if data_rate is being passed */
  qcmap_msgr_data_bitrate_v01 data_rate;
}qcmap_msgr_get_data_bitrate_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves UPnP notify interval. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_upnp_notify_interval_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves UPnP notify interval. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Notify Interval */
  uint8_t notify_interval_valid;  /**< Must be set to true if notify_interval is being passed */
  int32_t notify_interval;
  /**<   Specifies the UPnP notify interval in seconds, 30-60000. \n
  */
}qcmap_msgr_get_upnp_notify_interval_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the UPnP notify interval. */
typedef struct {

  /* Optional */
  /*  Notify Interval */
  uint8_t notify_interval_valid;  /**< Must be set to true if notify_interval is being passed */
  int32_t notify_interval;
  /**<   Specifies the UPnP notify interval in seconds, 30-60000. \n
  */
}qcmap_msgr_set_upnp_notify_interval_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the UPnP notify interval. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_upnp_notify_interval_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves DLNA notify interval. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_dlna_notify_interval_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves DLNA notify interval. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Notify Interval */
  uint8_t notify_interval_valid;  /**< Must be set to true if notify_interval is being passed */
  int32_t notify_interval;
  /**<   Specifies the DLNA notify interval in seconds, 30-60000. \n
  */
}qcmap_msgr_get_dlna_notify_interval_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the DLNA notify interval. */
typedef struct {

  /* Optional */
  /*  Notify Interval */
  uint8_t notify_interval_valid;  /**< Must be set to true if notify_interval is being passed */
  int32_t notify_interval;
  /**<   Specifies the DLNA notify interval in seconds, 30-60000. \n
  */
}qcmap_msgr_set_dlna_notify_interval_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the DLNA notify interval. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_dlna_notify_interval_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Adds DHCP reservation record. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  DHCP Reservation Configuration */
  qcmap_msgr_dhcp_reservation_v01 dhcp_reservation_record;
}qcmap_msgr_add_dhcp_reservation_record_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Adds DHCP reservation record. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_add_dhcp_reservation_record_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries all DHCP records and display */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_get_dhcp_reservation_records_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries all DHCP records and display */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Display All DHCP Records */
  uint8_t dhcp_reservation_records_valid;  /**< Must be set to true if dhcp_reservation_records is being passed */
  uint32_t dhcp_reservation_records_len;  /**< Must be set to # of elements in dhcp_reservation_records */
  qcmap_msgr_dhcp_reservation_v01 dhcp_reservation_records[QCMAP_MSGR_MAX_DHCP_RESERVATION_ENTRIES_V01];
}qcmap_msgr_get_dhcp_reservation_records_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Edit a DHCP record */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  Client Reserved IP to Access Record */
  uint8_t client_reserved_ip_valid;  /**< Must be set to true if client_reserved_ip is being passed */
  uint32_t client_reserved_ip;

  /* Optional */
  /*  DHCP Record to Edit */
  uint8_t dhcp_reservation_record_valid;  /**< Must be set to true if dhcp_reservation_record is being passed */
  qcmap_msgr_dhcp_reservation_v01 dhcp_reservation_record;
}qcmap_msgr_edit_dhcp_reservation_record_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Edit a DHCP record */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_edit_dhcp_reservation_record_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Deletes a DHCP record */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  Client IP */
  uint8_t client_reserved_ip_valid;  /**< Must be set to true if client_reserved_ip is being passed */
  uint32_t client_reserved_ip;
}qcmap_msgr_delete_dhcp_reservation_record_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Deletes a DHCP record */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_delete_dhcp_reservation_record_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables ALG Module. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  ALG Type */
  qcmap_msgr_alg_type_mask_v01 alg_type_op;
  /**<   ALG configuration mask. Values: \n
      - QCMAP_MSGR_MASK_RTSP_ALG (0x01) --  RTSP ALG
      - QCMAP_MSGR_MASK_SIP_ALG (0x02) --  SIP ALG
 All other bits are reserved and will be ignored by the service
   ADD more MASK depending on new ALG modules added

 */
}qcmap_msgr_enable_alg_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables ALG Module. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_alg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Disables  ALG and stops data transfer if in progress. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  ALG Type */
  qcmap_msgr_alg_type_mask_v01 alg_type_op;
  /**<   ALG configuration mask. Values: \n
      - QCMAP_MSGR_MASK_RTSP_ALG (0x01) --  RTSP ALG
      - QCMAP_MSGR_MASK_SIP_ALG (0x02) --  SIP ALG
 All other bits are reserved and will be ignored by the service
   ADD more MASK depending on new ALG modules added

 */
}qcmap_msgr_disable_alg_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Disables  ALG and stops data transfer if in progress. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_alg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Configures the webserver access from WWAN interface. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Webserver WWAN Access Flag */
  uint8_t webserver_wwan_access;
  /**<   Indicates whether webserver can be accessed from WWAN interface or not.
  */
}qcmap_msgr_set_webserver_wwan_access_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Configures the webserver access from WWAN interface. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_webserver_wwan_access_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the webserver WWAN access setting. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_get_webserver_wwan_access_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the webserver WWAN access setting. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Webserver WWAN Access Value */
  uint8_t webserver_wwan_access_valid;  /**< Must be set to true if webserver_wwan_access is being passed */
  uint8_t webserver_wwan_access;
  /**<   Indicates whether webserver can be accessed from WWAN.
  */
}qcmap_msgr_get_webserver_wwan_access_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the SIP server information. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Default SIP Server Information */
  qcmap_msgr_sip_server_info_v01 default_sip_server_info;
  /**<   Identifies the default PCSCF information which will be
       provided through DHCP to the Access Point clients*/
}qcmap_msgr_set_sip_server_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the SIP server information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_sip_server_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the SIP server information. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_get_sip_server_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the SIP server information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Default SIP Server Information */
  uint8_t default_sip_server_info_valid;  /**< Must be set to true if default_sip_server_info is being passed */
  qcmap_msgr_sip_server_info_v01 default_sip_server_info;
  /**<   Identifies the default PCSCF information which will be
       provided through DHCP to the Access Point clients*/

  /* Optional */
  /*  Network SIP Server Information */
  uint8_t network_sip_server_info_valid;  /**< Must be set to true if network_sip_server_info is being passed */
  uint32_t network_sip_server_info_len;  /**< Must be set to # of elements in network_sip_server_info */
  qcmap_msgr_sip_server_info_v01 network_sip_server_info[QCMAP_MSGR_MAX_SIP_SERVER_ENTRIES_V01];
  /**<   Identifies the network assigned PCSCF information which will be
       provided through DHCP to the Access Point clients*/
}qcmap_msgr_get_sip_server_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Resets to factory configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_restore_factory_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Resets to factory configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_restore_factory_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the list of all device connected to SoftAP device. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_get_connected_devices_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the list of all device connected to SoftAP device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Connected Devices Information */
  uint8_t connected_devices_info_valid;  /**< Must be set to true if connected_devices_info is being passed */
  uint32_t connected_devices_info_len;  /**< Must be set to # of elements in connected_devices_info */
  qcmap_msgr_connected_device_info_v01 connected_devices_info[QCMAP_MSGR_MAX_CONNECTED_DEVICES_V01];
}qcmap_msgr_get_connected_devices_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the IPV6 SIP server information. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_get_ipv6_sip_server_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the IPV6 SIP server information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Network SIP Server Information */
  uint8_t network_ipv6_sip_server_info_valid;  /**< Must be set to true if network_ipv6_sip_server_info is being passed */
  uint32_t network_ipv6_sip_server_info_len;  /**< Must be set to # of elements in network_ipv6_sip_server_info */
  qcmap_msgr_ipv6_sip_server_info_v01 network_ipv6_sip_server_info[QCMAP_MSGR_MAX_SIP_SERVER_ENTRIES_V01];
  /**<   Identifies the network assigned IPV6 PCSCF information which will be
       provided through DHCP to the Access Point clients*/
}qcmap_msgr_get_ipv6_sip_server_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Starts/stops wpa_supplicant and wpa_cli based on
    supplicant_config_status flag. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  uint8_t supplicant_config_status;
}qcmap_msgr_set_supplicant_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Starts/stops wpa_supplicant and wpa_cli based on
    supplicant_config_status flag. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_supplicant_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves Cradle mode. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_cradle_mode_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves Cradle mode. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Cradle Mode */
  uint8_t mode_valid;  /**< Must be set to true if mode is being passed */
  qcmap_msgr_cradle_mode_v01 mode;
  /**<   Identifies the Cradle mode. Values: \n
      - QCMAP_MSGR_CRADLE_DISABLED (0x00) --  Cradle mode disabled
      - QCMAP_MSGR_CRADLE_LAN_BRIDGE (0x01) --  Cradle mode LAN bridge
      - QCMAP_MSGR_CRADLE_LAN_ROUTER (0x02) --  Cradle mode LAN router
      - QCMAP_MSGR_CRADLE_WAN_BRIDGE (0x03) --  Cradle mode WAN bridge
      - QCMAP_MSGR_CRADLE_WAN_ROUTER (0x04) --  Cradle mode WAN router
 */
}qcmap_msgr_get_cradle_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the Cradle mode. */
typedef struct {

  /* Mandatory */
  /*  Cradle Mode */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Cradle Mode */
  qcmap_msgr_cradle_mode_v01 mode;
  /**<   Identifies the Cradle mode. Values: \n
      - QCMAP_MSGR_CRADLE_DISABLED (0x00) --  Cradle mode disabled
      - QCMAP_MSGR_CRADLE_LAN_BRIDGE (0x01) --  Cradle mode LAN bridge
      - QCMAP_MSGR_CRADLE_LAN_ROUTER (0x02) --  Cradle mode LAN router
      - QCMAP_MSGR_CRADLE_WAN_BRIDGE (0x03) --  Cradle mode WAN bridge
      - QCMAP_MSGR_CRADLE_WAN_ROUTER (0x04) --  Cradle mode WAN router
 */
}qcmap_msgr_set_cradle_mode_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the Cradle mode. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_cradle_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the current cradle mode status. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Mandatory */
  /*  Station Mode Status */
  qcmap_msgr_cradle_status_enum_v01 cradle_status;
  /**<   Indicates the Cradle status. Values: \n
      - QCMAP_MSGR_CRADLE_DISCONNECTED (0x01) --  Cradle is disconnected
      - QCMAP_MSGR_CRADLE_CONNECTED (0x02) --  Cradle is connected
 */
}qcmap_msgr_cradle_mode_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves Prefix Delegation configuration. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_prefix_delegation_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves Prefix Delegation configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Prefix Delegation Configuration */
  uint8_t prefix_delegation_valid;  /**< Must be set to true if prefix_delegation is being passed */
  uint8_t prefix_delegation;
  /**<   Identifies the Prefix Delegation config.*/
}qcmap_msgr_get_prefix_delegation_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the Prefix Delegation configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Prefix Delegation Configuration */
  uint8_t prefix_delegation;
  /**<   Identifies the Prefix Delegation config.
  */
}qcmap_msgr_set_prefix_delegation_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the Prefix Delegation configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_prefix_delegation_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves the current Prefix Delegation mode. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_prefix_delegation_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves the current Prefix Delegation mode. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Prefix Delegation Configuration */
  uint8_t prefix_delegation_valid;  /**< Must be set to true if prefix_delegation is being passed */
  uint8_t prefix_delegation;
  /**<   Identifies whether Prefix Delegation mode is enabled or not*/
}qcmap_msgr_get_prefix_delegation_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the gateway URL. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Gateway URL */
  uint32_t gateway_url_len;  /**< Must be set to # of elements in gateway_url */
  char gateway_url[QCMAP_MSGR_MAX_GATEWAY_URL_V01];
}qcmap_msgr_set_gateway_url_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the gateway URL. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_gateway_url_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves the gateway URL. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_gateway_url_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves the gateway URL. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Gateway URL */
  uint8_t gateway_url_valid;  /**< Must be set to true if gateway_url is being passed */
  uint32_t gateway_url_len;  /**< Must be set to # of elements in gateway_url */
  char gateway_url[QCMAP_MSGR_MAX_GATEWAY_URL_V01];
}qcmap_msgr_get_gateway_url_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables a Dynamic DNS */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_enable_dynamic_dns_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables a Dynamic DNS */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_dynamic_dns_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Disable a Dynamic DNS */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_disable_dynamic_dns_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Disable a Dynamic DNS */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_dynamic_dns_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Set Dynamic DNS configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  DDNS Server Configuration */
  char ddns_server[QCMAP_MSGR_DDNS_URL_LENGTH_V01 + 1];

  /* Mandatory */
  /*  DDNS hostname */
  char hostname[QCMAP_MSGR_DDNS_HOSTNAME_LENGTH_V01 + 1];

  /* Mandatory */
  /*  DDNS service login */
  char login[QCMAP_MSGR_DDNS_LOGIN_LENGTH_V01 + 1];

  /* Mandatory */
  /*  DDNS service password */
  char password[QCMAP_MSGR_DDNS_PASSWORD_LENGTH_V01 + 1];

  /* Optional */
  /*  DDNS refresh timeout */
  uint8_t timeout_valid;  /**< Must be set to true if timeout is being passed */
  uint32_t timeout;
  /**<   Dynamic DNS refresh timeout in seconds. */
}qcmap_msgr_set_dynamic_dns_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Set Dynamic DNS configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_dynamic_dns_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves Dynamic DNS configuration. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_dynamic_dns_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves Dynamic DNS configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  DDNS Server Configuration */
  uint8_t ddns_config_valid;  /**< Must be set to true if ddns_config is being passed */
  uint32_t ddns_config_len;  /**< Must be set to # of elements in ddns_config */
  qcmap_msgr_ddns_server_config_v01 ddns_config[QCMAP_MSGR_MAX_DDNS_SERVER_ENTRIES_V01];

  /* Optional */
  /*  DDNS Status */
  uint8_t enable_valid;  /**< Must be set to true if enable is being passed */
  uint8_t enable;
  /**<  Indicates whether Dynamic DNS service is enabled or disabled. */

  /* Optional */
  /*  DDNS hostname */
  uint8_t hostname_valid;  /**< Must be set to true if hostname is being passed */
  char hostname[QCMAP_MSGR_DDNS_HOSTNAME_LENGTH_V01 + 1];

  /* Optional */
  /*  DDNS refresh timeout */
  uint8_t timeout_valid;  /**< Must be set to true if timeout is being passed */
  uint32_t timeout;
  /**<   Dynamic DNS will be refreshed for every timeout in seconds. */
}qcmap_msgr_get_dynamic_dns_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the Tiny Proxy status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_tiny_proxy_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the Tiny Proxy status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Tiny Proxy Mode */
  uint8_t tiny_proxy_mode_valid;  /**< Must be set to true if tiny_proxy_mode is being passed */
  qcmap_msgr_tiny_proxy_mode_enum_v01 tiny_proxy_mode;
  /**<   Identifies the Tiny Proxy mode. Values: \n
      - QCMAP_MSGR_TINY_PROXY_MODE_UP (0x01) --  Tiny Proxy is in UP mode
      - QCMAP_MSGR_TINY_PROXY_MODE_DOWN (0x02) --  Tiny Proxy is in DOWN Mode
 */
}qcmap_msgr_get_tiny_proxy_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables a Tiny Proxy */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_enable_tiny_proxy_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables a Tiny Proxy */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_tiny_proxy_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Disable a Tiny Proxy */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_disable_tiny_proxy_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Disable a Tiny Proxy */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_tiny_proxy_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the DLNA WHITELISTING. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  DLNA Whielisting Enabled */
  uint8_t dlna_whitelist_allow;
  /**<   Indicates whether the DLNA whitelisting is to be enabled or disabled.
  */
}qcmap_msgr_set_dlna_whitelisting_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the DLNA WHITELISTING. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_dlna_whitelisting_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the DLNA Whitelisting status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_dlna_whitelisting_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the DLNA Whitelisting status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  DLNA Whielisting Status */
  uint8_t dlna_whitelist_allow_valid;  /**< Must be set to true if dlna_whitelist_allow is being passed */
  uint8_t dlna_whitelist_allow;
  /**<   Indicates whether the dlna whitelisting is enabled or disabled.
  */
}qcmap_msgr_get_dlna_whitelisting_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Adds the DLNA Whitelisting IP for the mobile AP. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  DLNAWhitelist IP Address */
  uint32_t dlna_whitelist_ip_addr;
  /**<   DLNAWhitelist IP address. */
}qcmap_msgr_add_dlna_whitelistip_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Adds the DLNA Whitelisting IP for the mobile AP. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_add_dlna_whitelistip_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Deletes the DLNA Whitelist IP address. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  DLNAWhitelist IP Address */
  uint32_t dlna_whitelist_ip_addr;
  /**<   DLNAWhitelist IP address. */
}qcmap_msgr_delete_dlna_whitelist_ip_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Deletes the DLNA Whitelist IP address. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_delete_dlna_whitelist_ip_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables the STA Mode. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_enable_sta_mode_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables the STA Mode. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_sta_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Disables the STA Mode. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_disable_sta_mode_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Disables the STA Mode. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_sta_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the current wlan status. */
typedef struct {

  /* Mandatory */
  /*  WLAN Mode Status */
  qcmap_msgr_wlan_status_enum_v01 wlan_status;
  /**<   Indicates the current WLAN State. \n
      - QCMAP_MSGR_WLAN_ENABLED (0x01) --  WLAN is enabled
      - QCMAP_MSGR_WLAN_DISABLED (0x02) --  WLAN is disabled
      - QCMAP_MSGR_WLAN_SWITCH_TO_2G (0x03) --  WLAN switched to 2G
      - QCMAP_MSGR_WLAN_SWITCH_TO_5G (0x04) --  WLAN switched to 5G
 */

  /* Mandatory */
  /*  WLAN Mode Status */
  uint32_t wlan_state_len;  /**< Must be set to # of elements in wlan_state */
  qcmap_msgr_wlan_iface_state_v01 wlan_state[QCMAP_MSGR_MAX_WLAN_IFACE_V01];
  /**<   Indicates the current WLAN State for each Iface. \n
  */

  /* Mandatory */
  /*  WLAN Mode */
  qcmap_msgr_wlan_mode_enum_v01 wlan_mode;
  /**<   Identifies the current WLAN mode. Values: \n
      - QCMAP_MSGR_WLAN_MODE_AP (0x01) --  WLAN is in AP mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP (0x02) --  WLAN is in AP/AP Mode
      - QCMAP_MSGR_WLAN_MODE_AP_STA (0x03) --  WLAN is in AP/STA Mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP_AP (0x04) --  WLAN is in AP/AP/AP Mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP_STA (0x05) --  WLAN is in AP/AP/STA Mode
      - QCMAP_MSGR_WLAN_MODE_STA_ONLY (0x06) --  WLAN is in STA only Mode
      - QCMAP_MSGR_WLAN_MODE_AP_AP_AP_AP (0x07) --  WLAN is in AP-AP-AP-AP Mode
      - QCMAP_MSGR_WLAN_MODE_AP_STA_BRIDGE (0x08) --  WLAN is in AP/STA Bridge Mode
       Only used for GetWLANStatus
      - QCMAP_MSGR_WLAN_MODE_AP_AP_STA_BRIDGE (0x09) --  WLAN is in AP/AP/STA Bridge Mode
       Only used for GetWLANStatus
      - QCMAP_MSGR_WLAN_MODE_STA_ONLY_BRIDGE (0x0A) --  WLAN is in STA Bridge Mode
       Only used for GetWLANStatus
      - QCMAP_MSGR_WLAN_MODE_AP_P2P (0x0B) --  WLAN is in Concurrent AP/P2P mode
      - QCMAP_MSGR_WLAN_MODE_STA_P2P (0x0C) --  WLAN is in Concurrent STA/P2P mode
 */

  /* Optional */
  /*  SCM indication type */
  uint8_t scm_ind_valid;  /**< Must be set to true if scm_ind is being passed */
  qcmap_msgr_scm_ind_enum_v01 scm_ind;
  /**<   Identifies the SCM ind. Values: \n
      - QCMAP_MSGR_SCM_INVALID_RECONFIG_IND (0x00) --  Invalid SCM reconfig
      - QCMAP_MSGR_SCM_DYNAMIC_RECONFIG_IND (0x01) --  SCM is reconfiguring WLAN
      - QCMAP_MSGR_SCM_STATION_STATE_IND (0x02) --  Station state change indication from scm
      - QCMAP_MSGR_SCM_SYS_CONTROL_IND (0x03) --  wlan sys control change indication from SCM
 */

  /* Optional */
  /*  WLAN STA Mode */
  uint8_t bridge_mode_valid;  /**< Must be set to true if bridge_mode is being passed */
  uint8_t bridge_mode;
  /**<   Identifies the WLAN STA mode. Values: \n
       - 0 -- Router Mode \n
       - 1 -- Bridge Mode
  */

  /* Optional */
  /*  WLAN 2G/5G Switch Status */
  uint8_t wlan_switch_status_valid;  /**< Must be set to true if wlan_switch_status is being passed */
  qcmap_msgr_wlan_switch_status_enum_v01 wlan_switch_status;
  /**<   Identifies the WLAN switch to 2G/5G status. Values: \n
      - QCMAP_WLAN_5G_SWITCH_FAIL (0) --  WLAN 5G Switch Failed
      - QCMAP_WLAN_2G_SWITCH_FAIL (1) --  WLAN 2G Switch Failed
      - QCMAP_WLAN_5G_SWITCH_SUCCESS (2) --  WLAN 5G Switch Success
      - QCMAP_WLAN_2G_SWITCH_SUCCESS (3) --  WLAN 2G Switch Success
      - QCMAP_WLAN_STA_SWITCH_SUCCESS (4) --  WLAN STA Switch to either 2G or 5G
 */
}qcmap_msgr_wlan_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Set backhaul priority for backhaul switching. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  First Priority backhaul */
  qcmap_msgr_backhaul_type_enum_v01 first_priority_backhaul;

  /* Mandatory */
  /*  Second Priority backhaul */
  qcmap_msgr_backhaul_type_enum_v01 second_priority_backhaul;

  /* Mandatory */
  /*  Third Priority backhaul */
  qcmap_msgr_backhaul_type_enum_v01 third_priority_backhaul;

  /* Mandatory */
  /*  Fourth Priority backhaul */
  qcmap_msgr_backhaul_type_enum_v01 fourth_priority_backhaul;

  /* Mandatory */
  /*  Fifth Priority backhaul */
  qcmap_msgr_backhaul_type_enum_v01 fifth_priority_backhaul;
}qcmap_msgr_set_backhaul_pref_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Set backhaul priority for backhaul switching. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_backhaul_pref_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Get backhaul priority for backhaul switching. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_backhaul_pref_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Get backhaul priority for backhaul switching. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  First Priority backhaul */
  uint8_t first_priority_backhaul_valid;  /**< Must be set to true if first_priority_backhaul is being passed */
  qcmap_msgr_backhaul_type_enum_v01 first_priority_backhaul;

  /* Optional */
  /*  Second Priority backhaul */
  uint8_t second_priority_backhaul_valid;  /**< Must be set to true if second_priority_backhaul is being passed */
  qcmap_msgr_backhaul_type_enum_v01 second_priority_backhaul;

  /* Optional */
  /*  Third Priority backhaul */
  uint8_t third_priority_backhaul_valid;  /**< Must be set to true if third_priority_backhaul is being passed */
  qcmap_msgr_backhaul_type_enum_v01 third_priority_backhaul;

  /* Optional */
  /*  Fourth Priority backhaul */
  uint8_t fourth_priority_backhaul_valid;  /**< Must be set to true if fourth_priority_backhaul is being passed */
  qcmap_msgr_backhaul_type_enum_v01 fourth_priority_backhaul;

  /* Optional */
  /*  Fifth Priority backhaul */
  uint8_t fifth_priority_backhaul_valid;  /**< Must be set to true if fifth_priority_backhaul is being passed */
  qcmap_msgr_backhaul_type_enum_v01 fifth_priority_backhaul;
}qcmap_msgr_get_backhaul_pref_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves Ethernet mode. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_ethernet_mode_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves Ethernet mode. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  ETH Backhaul Mode */
  uint8_t mode_valid;  /**< Must be set to true if mode is being passed */
  qcmap_msgr_ethernet_mode_v01 mode;
  /**<   Identifies the ETHERNET mode. Values: \n
      - QCMAP_MSGR_ETHERNET_LAN_ROUTER (0x00) --  ETH mode LAN router
      - QCMAP_MSGR_ETHERNET_WAN_ROUTER (0x01) --   ETH mode WAN router
      - QCMAP_MSGR_ETHERNET_WAN_LAN_ROUTER (0x02) --   ETH mode WAN_LAN router
 */

  /* Optional */
  /*  Ethernet port configuration */
  uint8_t eth_port_valid;  /**< Must be set to true if eth_port is being passed */
  uint32_t eth_port_len;  /**< Must be set to # of elements in eth_port */
  qcmap_msgr_eth_port_config_v01 eth_port[QCMAP_MAX_ETH_PORTS_V01];
  /**<   Identifies the ETH ports for WAN_LAN Ethernet mode only
  */
}qcmap_msgr_get_ethernet_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the ETHERNET mode. */
typedef struct {

  /* Mandatory */
  /*  Ethernet Mode */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Ethernet Mode */
  qcmap_msgr_ethernet_mode_v01 mode;
  /**<   Identifies the Ethernet mode. Values: \n
      - QCMAP_MSGR_ETHERNET_LAN_ROUTER (0x00) --  ETH mode LAN router
      - QCMAP_MSGR_ETHERNET_WAN_ROUTER (0x01) --   ETH mode WAN router
      - QCMAP_MSGR_ETHERNET_WAN_LAN_ROUTER (0x02) --   ETH mode WAN_LAN router
 */

  /* Optional */
  /*  Ethernet port configuration */
  uint8_t eth_port_valid;  /**< Must be set to true if eth_port is being passed */
  uint32_t eth_port_len;  /**< Must be set to # of elements in eth_port */
  qcmap_msgr_eth_port_config_v01 eth_port[QCMAP_MAX_ETH_PORTS_V01];
  /**<   Identifies the ETH ports for WAN_LAN Ethernet mode only
  */
}qcmap_msgr_set_ethernet_mode_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the ETHERNET mode. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_ethernet_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the current Ethernet mode status. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Mandatory */
  /*  Ethernet Backhaul Status */
  qcmap_msgr_ethernet_status_enum_v01 eth_status;
  /**<   Indicates the Ethernet Backhaul status. Values: \n
      - QCMAP_MSGR_ETH_BACKHAUL_DISCONNECTED (1) --  ETH Backhaul is disconnected
      - QCMAP_MSGR_ETH_BACKHAUL_CONNECTED (2) --  ETH Backhaul is connected
 */
}qcmap_msgr_ethernet_mode_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the IP Passthrough Flag */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  IP Passthrough Mode. */
  qcmap_msgr_ip_passthrough_mode_enum_v01 enable_state;
  /**<   Enable/Disable Passthrough. Values: \n
      - QCMAP_MSGR_IP_PASSTHROUGH_MODE_DOWN (0x00) --  IP Passthrough mode is down
      - QCMAP_MSGR_IP_PASSTHROUGH_MODE_UP (0x01) --  IP Passthrough mode is up
 */

  /* Optional */
  /*  IP Passthrough configuration. */
  uint8_t passthrough_config_valid;  /**< Must be set to true if passthrough_config is being passed */
  qcmap_msgr_ip_passthrough_config_v01 passthrough_config;

  /* Optional */
  /*  IP Passthrough NAT Options */
  uint8_t ip_passthrough_nat_disabled_valid;  /**< Must be set to true if ip_passthrough_nat_disabled is being passed */
  uint8_t ip_passthrough_nat_disabled;
}qcmap_msgr_set_ip_passthrough_flag_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the IP Passthrough Flag */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_ip_passthrough_flag_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Get IP Passthrough Configuration */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_ip_passthrough_flag_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Get IP Passthrough Configuration */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  IP Passthrough Mode. */
  uint8_t enable_state_valid;  /**< Must be set to true if enable_state is being passed */
  qcmap_msgr_ip_passthrough_mode_enum_v01 enable_state;
  /**<   Indicates whether IP Passthrough is enabled or disabled. Values: \n
      - QCMAP_MSGR_IP_PASSTHROUGH_MODE_DOWN (0x00) --  IP Passthrough mode is down
      - QCMAP_MSGR_IP_PASSTHROUGH_MODE_UP (0x01) --  IP Passthrough mode is up
 */

  /* Optional */
  /*  IP Passthrough configuration. */
  uint8_t passthrough_config_valid;  /**< Must be set to true if passthrough_config is being passed */
  qcmap_msgr_ip_passthrough_config_v01 passthrough_config;

  /* Optional */
  /*  IP Passthrough NAT Options */
  uint8_t ip_passthrough_nat_disabled_valid;  /**< Must be set to true if ip_passthrough_nat_disabled is being passed */
  uint8_t ip_passthrough_nat_disabled;
}qcmap_msgr_get_ip_passthrough_flag_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Get IP Passthrough state */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_ip_passthrough_state_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Get IP Passthrough state */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  State */
  uint8_t state_valid;  /**< Must be set to true if state is being passed */
  uint8_t state;
  /**<   IP Passthrough Active state. */
}qcmap_msgr_get_ip_passthrough_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Bring Up BT Tethering. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  Bluetooth Tethering mode */
  uint8_t bt_mode_valid;  /**< Must be set to true if bt_mode is being passed */
  qcmap_bt_tethering_mode_enum_v01 bt_mode;
  /**<   Identifies the BT tethering mode. Values: \n
      - QCMAP_MSGR_BT_MODE_LAN (0) --  0 -- Station will act as Backahul
      - QCMAP_MSGR_BT_MODE_WAN (1) --  1 -- BT-Pan will act as Backahul
 */
}qcmap_msgr_bring_up_bt_tethering_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Bring Up BT Tethering. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_bring_up_bt_tethering_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Bring down BT tethering. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_bring_down_bt_tethering_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Bring down BT tethering. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_bring_down_bt_tethering_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets bt tethering  status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_bt_tethering_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets bt tethering  status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  BT Tethring Status */
  uint8_t bt_tethering_status_valid;  /**< Must be set to true if bt_tethering_status is being passed */
  uint8_t bt_tethering_status;
  /**<   BT tethering  status. Values: \n
  - TRUE -- Enabled \n
  - FALSE -- Disabled
   */

  /* Optional */
  /*  BT Tethring Mode */
  uint8_t bt_tethering_mode_valid;  /**< Must be set to true if bt_tethering_mode is being passed */
  qcmap_bt_tethering_mode_enum_v01 bt_tethering_mode;
  /**<   Indicates the BT tethering Mode \n
      - QCMAP_MSGR_BT_MODE_LAN (0) --  0 -- Station will act as Backahul
      - QCMAP_MSGR_BT_MODE_WAN (1) --  1 -- BT-Pan will act as Backahul
 */
}qcmap_msgr_get_bt_tethering_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the current mobile AP status. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Mandatory */
  /*  Bluetooth tethering Status */
  qcmap_msgr_bt_tethering_status_enum_v01 bt_tethering_status;
  /**<   Indicates the BT Tethering status. Values: \n
      - QCMAP_MSGR_BT_TETHERING_MODE_UP (0x01) --  BT Tethering is UP
      - QCMAP_MSGR_BT_TETHERING_MODE_DOWN (0x02) --  BT Tethering is DOWN
 */
}qcmap_msgr_bt_tethering_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the BT WAN backahul status. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Mandatory */
  /*  Bluetooth tethering Indication */
  qcmap_msgr_bt_tethering_wan_enum_v01 bt_tethering_wan;
  /**<   Indicates the BT Tethering WAN status \n
      - QCMAP_MSGR_BT_WAN_MODE_CONNECTED (0x01) --  BT WAN Backahul mode is connected
      - QCMAP_MSGR_BT_WAN_MODE_DISCONNECTED (0x02) --  BT WAN Backahul mode is disconnected
 */
}qcmap_msgr_bt_tethering_wan_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the initial packet threshold for software path. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Packet Count */
  uint32_t packet_count;
}qcmap_msgr_set_initial_packet_threshold_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the initial packet threshold for software path. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_initial_packet_threshold_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the initial packet threshold. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_initial_packet_threshold_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the initial packet threshold. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Packet Count */
  uint8_t packet_count_valid;  /**< Must be set to true if packet_count is being passed */
  uint32_t packet_count;
}qcmap_msgr_get_initial_packet_threshold_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables a SOCKSV5 Proxy */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_enable_socksv5_proxy_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables a SOCKSV5 Proxy */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_socksv5_proxy_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Disable a SOCKSV5 Proxy */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_disable_socksv5_proxy_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Disable a SOCKSV5 Proxy */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_socksv5_proxy_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Get a SOCKSV5 Proxy Configuration */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_socksv5_proxy_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Get a SOCKSV5 Proxy Configuration */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  SOCKSV5 Config File Path */
  uint8_t config_file_paths_valid;  /**< Must be set to true if config_file_paths is being passed */
  qcmap_msgr_socksv5_config_file_paths_v01 config_file_paths;
  /**<   file paths for socksv5 proxy daemon to parse
  */

  /* Optional */
  /*  SOCKSV5 Authentication method */
  uint8_t auth_method_valid;  /**< Must be set to true if auth_method is being passed */
  uint8_t auth_method;
  /**<   As per RFC 1928, 0x00 shall mean NO_AUTHENTICATION
                        0x02 shall mean USERNAME_PASSWORD
       As of now, no other auth method supported.
  */

  /* Optional */
  /*  Interface Name */
  uint8_t lan_iface_valid;  /**< Must be set to true if lan_iface is being passed */
  char lan_iface[QCMAP_MAX_IFACE_NAME_SIZE_V01];

  /* Optional */
  /*  SOCKSV5 WAN Configuration */
  uint8_t socksv5_wan_service_valid;  /**< Must be set to true if socksv5_wan_service is being passed */
  qcmap_msgr_socksv5_wan_config_v01 socksv5_wan_service[QCMAP_MAX_NUM_BACKHAULS_V01];
}qcmap_msgr_get_socksv5_proxy_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Set a SOCKSV5 Proxy Configuration */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  SOCKSV5 Configuration Type */
  qcmap_socksv5_config_type_v01 config_type;
  /**<   To identify configuration type for SOCKSV5. Values: \n
      - QCMAP_MSGR_SOCKSV5_SET_CONFIG_FILE_PATH (0) --  Set config file path
      - QCMAP_MSGR_SOCKSV5_SET_AUTH_METHOD (1) --  Set auth Method
      - QCMAP_MSGR_SOCKSV5_EDIT_LAN_IFACE (2) --  Edit LAN Iface
      - QCMAP_MSGR_SOCKSV5_ADD_UNAME_ASSOC (3) --  Add UNAME Association for Private Auth Method
      - QCMAP_MSGR_SOCKSV5_DELETE_UNAME_ASSOC (4) --  Delete UNAME Association for Private Auth Method
 */

  /* Optional */
  /*  SOCKSV5 Configuration File Path */
  uint8_t config_file_paths_valid;  /**< Must be set to true if config_file_paths is being passed */
  qcmap_msgr_socksv5_config_file_paths_v01 config_file_paths;
  /**<   file paths for socksv5 proxy daemon to parse
  */

  /* Optional */
  /*  SOCKSV5 Authentication method */
  uint8_t auth_method_valid;  /**< Must be set to true if auth_method is being passed */
  uint8_t auth_method;
  /**<   As per RFC 1928, 0x00 shall mean NO_AUTHENTICATION
                        0x02 shall mean USERNAME_PASSWORD
       As of now, no other auth method supported.
  */

  /* Optional */
  /*  Interface name */
  uint8_t lan_iface_valid;  /**< Must be set to true if lan_iface is being passed */
  char lan_iface[QCMAP_MAX_IFACE_NAME_SIZE_V01];

  /* Optional */
  /*  SOCKSV5 username associated */
  uint8_t uname_assoc_valid;  /**< Must be set to true if uname_assoc is being passed */
  qcmap_msgr_socksv5_uname_assoc_v01 uname_assoc;
}qcmap_msgr_set_socksv5_proxy_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Set a SOCKSV5 Proxy Configuration */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_socksv5_proxy_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enable Packet statistics feature. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_enable_packet_stats_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enable Packet statistics feature. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_packet_stats_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; disable packet statistics. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_disable_packet_stats_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; disable packet statistics. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_packet_stats_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; resets packet statistics. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_reset_packet_stats_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; resets packet statistics. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_reset_packet_stats_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; packet statistics status */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_packet_stats_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; packet statistics status */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Packet Stats Status */
  uint8_t status_valid;  /**< Must be set to true if status is being passed */
  qcmap_msgr_packet_stats_status_enum_v01 status;
  /**<   Indicates the packet stats status values: \n
      - QCMAP_MSGR_PACKET_STATS_STATUS_ENABLED (0x01) --  Packet Stats is Enabled
      - QCMAP_MSGR_PACKET_STATS_STATUS_DISABLED (0x02) --  Packet Stats is Disabled
 */
}qcmap_msgr_packet_stats_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates information about connected and diconnected clients. */
typedef struct {

  /* Mandatory */
  /*  Connection status change */
  qcmap_msgr_packet_stats_state_enum_v01 conn_status;
  /**<   Indicates the type of change for the client in indication message to be sent. Values: \n
      - QCMAP_MSGR_PACKET_STATS_CLIENT_DISCONNECTED (0x00) --  A client is disconnected
      - QCMAP_MSGR_PACKET_STATS_CLIENT_CONNECTED (0x01) --  A new client connected
      - QCMAP_MSGR_PACKET_STATS_IPV4_UPDATED (0x02) --  IPv4 Updated
      - QCMAP_MSGR_PACKET_STATS_IPV6_UPDATED (0x03) --  IPV6 Updated
      - QCMAP_MSGR_PACKET_STATS_WLAN_DISABLED (0x04) --  WLAN is disabled
      - QCMAP_MSGR_PACKET_STATS_MOBILEAP_DISABLED (0x05) --  QCMAP CM is disabled
      - QCMAP_MSGR_PACKET_STATS_IPV6_WWAN_DISCONNECTED (0x06) --  IPV6 WWAN connection is lost
      - QCMAP_MSGR_PACKET_STATS_IPV4_WWAN_DISCONNECTED (0x07) --  IPV4 WWAN connection is lost
      - QCMAP_MSGR_PACKET_STATS_BH_SWITCHED (0x08) --  Backhaul is switched
      - QCMAP_MSGR_PACKET_STATS_USB_DISCONNECTED (0x09) --  USB is disconnected
 */

  /* Mandatory */
  /*  Number of Clients */
  uint32_t number_of_entries;
  /**<   Indicates the number of clients whose indication is sent. \n
  */

  /* Mandatory */
  /*  Connected Device Info */
  qcmap_msgr_connected_device_info_v01 info[QCMAP_MSGR_MAX_CONNECTED_DEVICES_V01];
  /**<   Indicates the information of connected or disconnected clients \n
  */
}qcmap_msgr_packet_stats_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Delete a particular wwan policy. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Optional */
  /*  WWAN Profile number (Deprecated) */
  uint8_t profile_handle_valid;  /**< Must be set to true if profile_handle is being passed */
  profile_handle_type_v01 profile_handle;
}qcmap_msgr_delete_wwan_policy_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Delete a particular wwan policy. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_delete_wwan_policy_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries all the WWAN policy. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_wwan_policy_list_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries all the WWAN policy. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Default Profile Handle */
  uint8_t default_profile_handle_valid;  /**< Must be set to true if default_profile_handle is being passed */
  profile_handle_type_v01 default_profile_handle;

  /* Optional */
  /*  WWAN Policy */
  uint8_t wwan_policy_valid;  /**< Must be set to true if wwan_policy is being passed */
  uint32_t wwan_policy_len;  /**< Must be set to # of elements in wwan_policy */
  qcmap_msgr_net_profile_and_policy_info_v01 wwan_policy[QCMAP_MAX_NUM_BACKHAULS_V01];
}qcmap_msgr_wwan_policy_list_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets VLAN configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  VLAN Config */
  qcmap_msgr_vlan_config_v01 config;
  /**<   VLAN configuration
  */
}qcmap_msgr_set_vlan_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets VLAN configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  IPA offload status */
  uint8_t is_ipa_offload_enabled_valid;  /**< Must be set to true if is_ipa_offload_enabled is being passed */
  uint8_t is_ipa_offload_enabled;
  /**<   IPA offload status. Values: \n
       - 1 -- IPA offload enabled \n
       - 0 -- IPA offload disabled
  */
}qcmap_msgr_set_vlan_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Create VLAN configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  VLAN Config */
  uint8_t vlan_config_valid;  /**< Must be set to true if vlan_config is being passed */
  qcmap_msgr_vlan_config_ex_v01 vlan_config;
  /**<   VLAN configuration
  */
}qcmap_msgr_create_vlan_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Create VLAN configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Accelerated data-path */
  uint8_t is_accelerated_valid;  /**< Must be set to true if is_accelerated is being passed */
  uint8_t is_accelerated;
  /**<   Accelerated data-path status. Values: \n
       - 1 -- Acceleration is enabled \n
       - 0 -- Acceleration is disabled (Default)
  */
}qcmap_msgr_create_vlan_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves VLAN Config. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_vlan_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves VLAN Config. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  VLAN CONFIG (Deprecated) */
  uint8_t vlan_config_list_valid;  /**< Must be set to true if vlan_config_list is being passed */
  uint32_t vlan_config_list_len;  /**< Must be set to # of elements in vlan_config_list */
  qcmap_msgr_vlan_config_v01 vlan_config_list[QCMAP_MSGR_MAX_VLAN_ENTRIES_V01];
  /**<   Identifies the VLAN Config.\n
       This has been deprecated, use vlan_config_list_ex
  */

  /* Optional */
  /*  VLAN CONFIGURATION EX */
  uint8_t vlan_config_list_ex_valid;  /**< Must be set to true if vlan_config_list_ex is being passed */
  uint32_t vlan_config_list_ex_len;  /**< Must be set to # of elements in vlan_config_list_ex */
  qcmap_msgr_vlan_config_ex_v01 vlan_config_list_ex[QCMAP_MSGR_MAX_VLAN_ENTRIES_V01];
  /**<   Identifies the VLAN Config Ex.\n
  */
}qcmap_msgr_get_vlan_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Deletes VLAN configuration. */
typedef struct {

  /* Mandatory */
  /*  MobileAP handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  VLAN Config */
  qcmap_msgr_vlan_config_v01 config;
  /**<   VLAN configuration
  */
}qcmap_msgr_delete_vlan_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Deletes VLAN configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_delete_vlan_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Deletes VLAN configuration. */
typedef struct {

  /* Mandatory */
  /*  MobileAP handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  VLAN Config */
  uint8_t vlan_config_valid;  /**< Must be set to true if vlan_config is being passed */
  qcmap_msgr_vlan_config_ex_v01 vlan_config;
  /**<   VLAN configuration
  */
}qcmap_msgr_delete_vlan_config_ex_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Deletes VLAN configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_delete_vlan_config_ex_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables/ Disables L2TP Configuration for unmanaged tunnels. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  L2TP Config */
  qcmap_msgr_set_unmanaged_l2tp_state_config_v01 config;
  /**<   Enable L2TP configuration
  */
}qcmap_msgr_set_unmanaged_l2tp_state_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables/ Disables L2TP Configuration for unmanaged tunnels. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_unmanaged_l2tp_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets L2TP configuration. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  L2TP Mode */
  qcmap_msgr_l2tp_mode_enum_v01 mode;

  /* Mandatory */
  /*  L2TP Config */
  qcmap_msgr_l2tp_config_v01 config;
  /**<   VLAN configuration
  */
}qcmap_msgr_set_l2tp_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets L2TP configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_l2tp_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables or Disables MTU Config for L2TP. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  L2TP MTU Config */
  qcmap_msgr_l2tp_mtu_config_v01 config;
  /**<   L2TP MTU Config
  */

  /* Optional */
  /*  L2TP MTU Size */
  uint8_t mtu_size_valid;  /**< Must be set to true if mtu_size is being passed */
  uint32_t mtu_size;
  /**<   L2TP MTU Size in bytes
  */
}qcmap_msgr_set_MTU_for_l2tp_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables or Disables MTU Config for L2TP. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_MTU_for_l2tp_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables or Disables TCP MSS Config for L2TP. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  L2TP TCP MSS Config */
  qcmap_msgr_l2tp_TCP_MSS_config_v01 config;
  /**<   L2TP TCP MSS Config
  */
}qcmap_msgr_set_TCP_MSS_for_l2tp_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables or Disables TCP MSS Config for L2TP. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_TCP_MSS_for_l2tp_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves L2TP Config. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_l2tp_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves L2TP Config. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  L2TP Mode */
  uint8_t mode_valid;  /**< Must be set to true if mode is being passed */
  qcmap_msgr_l2tp_mode_enum_v01 mode;
  /**<   Identifies the L2TP Mode.\n
  */

  /* Optional */
  /*  L2TP MTU Config */
  uint8_t mtu_config_valid;  /**< Must be set to true if mtu_config is being passed */
  qcmap_msgr_l2tp_mtu_config_v01 mtu_config;
  /**<   Identifies the L2TP MTU Config.\n
  */

  /* Optional */
  /*  L2TP TCP MSS Config */
  uint8_t tcp_mss_config_valid;  /**< Must be set to true if tcp_mss_config is being passed */
  qcmap_msgr_l2tp_TCP_MSS_config_v01 tcp_mss_config;
  /**<   Identifies the L2TP TCP MSS Config.\n
  */

  /* Optional */
  /*  L2TP CONFIG */
  uint8_t l2tp_config_list_valid;  /**< Must be set to true if l2tp_config_list is being passed */
  uint32_t l2tp_config_list_len;  /**< Must be set to # of elements in l2tp_config_list */
  qcmap_msgr_l2tp_config_v01 l2tp_config_list[QCMAP_MSGR_L2TP_MAX_TUNNELS_V01];
  /**<   Identifies the L2TP Config.\n
  */

  /* Optional */
  /*  L2TP MTU Size */
  uint8_t mtu_size_valid;  /**< Must be set to true if mtu_size is being passed */
  uint32_t mtu_size;
  /**<   Identifies the L2TP MTU Size in bytes.\n
  */
}qcmap_msgr_get_l2tp_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Deletes L2TP tunnels and session configuration for given tunnel ID. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  L2TP Config */
  qcmap_msgr_delete_l2tp_config_v01 config;
  /**<   L2TP configuration
  */
}qcmap_msgr_delete_l2tp_tunnel_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Deletes L2TP tunnels and session configuration for given tunnel ID. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_delete_l2tp_tunnel_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Adds the PDN to VLAN mapping. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  WWAN Profile Number */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN. */

  /* Mandatory */
  /*  VLAN ID */
  int16_t vlan_id;
  /**<   vlan id. */
}qcmap_msgr_add_pdn_to_vlan_mapping_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Adds the PDN to VLAN mapping. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_add_pdn_to_vlan_mapping_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Deletes PDN to VLAN mapping. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  WWAN Profile Number */
  profile_handle_type_v01 profile_handle;
  /**<   Profile number to be used for PDN. */

  /* Mandatory */
  /*  VLAN ID */
  int16_t vlan_id;
  /**<   vlan id. */
}qcmap_msgr_delete_pdn_to_vlan_mapping_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Deletes PDN to VLAN mapping. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_delete_pdn_to_vlan_mapping_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Retrieves all the PDN to VLAN mappings. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_pdn_to_vlan_mappings_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Retrieves all the PDN to VLAN mappings. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  PDN to VLAN Mappings */
  uint8_t pdn_to_vlan_mappings_valid;  /**< Must be set to true if pdn_to_vlan_mappings is being passed */
  uint32_t pdn_to_vlan_mappings_len;  /**< Must be set to # of elements in pdn_to_vlan_mappings */
  qcmap_msgr_pdn_to_vlan_mapping_v01 pdn_to_vlan_mappings[QCMAP_MAX_NUM_BACKHAULS_V01];
  /**<   PDN to VLAN mappings. */
}qcmap_msgr_get_pdn_to_vlan_mappings_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enable GSB on configured interface. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_enable_gsb_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enable GSB on configured interface. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_enable_gsb_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; disable gsb on all configured interfaces. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */
}qcmap_msgr_disable_gsb_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; disable gsb on all configured interfaces. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_disable_gsb_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; obtain gsb configuration */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_gsb_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; obtain gsb configuration */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  get gsb config */
  uint8_t config_valid;  /**< Must be set to true if config is being passed */
  uint32_t config_len;  /**< Must be set to # of elements in config */
  qcmap_msgr_gsb_config_v01 config[QCMAP_MSGR_MAX_IF_SUPPORTED_V01];
  /**<   returns the configuration of gsb for all interfaces \n
  */
}qcmap_msgr_get_gsb_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; set gsb configuration */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  GSB Configuration */
  uint8_t config_valid;  /**< Must be set to true if config is being passed */
  qcmap_msgr_gsb_config_v01 config;
  /**<   Configuration of GSB for a given interface \n
  */
}qcmap_msgr_set_gsb_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; set gsb configuration */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_gsb_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; delete gsb configuration */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Interface Name */
  char if_name[QCMAP_MAX_IFACE_NAME_SIZE_V01];
  /**<   Interface name for which the configuration needs to be removed. */
}qcmap_msgr_delete_gsb_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; delete gsb configuration */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_delete_gsb_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Switch WWAN Profile preference. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
   */

  /* Mandatory */
  /*  Profile handle */
  profile_handle_type_v01 profile_handle;
}qcmap_msgr_set_wwan_profile_preference_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Switch WWAN Profile preference. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_wwan_profile_preference_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the DUN dongle mode */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  DUN Dongle Mode */
  uint8_t enable_dun_dongle_mode;
  /**<   Enable/disable Dundonglemode. Values:\n
      - TRUE -- Enable\n
      - FALSE -- Disable
   */
}qcmap_msgr_set_dun_dongle_mode_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the DUN dongle mode */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_dun_dongle_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the DUN dongle mode */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_dun_dongle_mode_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the DUN dongle mode */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Dun dongle Mode */
  uint8_t dun_dongle_mode_valid;  /**< Must be set to true if dun_dongle_mode is being passed */
  uint8_t dun_dongle_mode;
  /**<   Dun dongle mode status. Values: \n
       - TRUE -- Enabled \n
       - FALSE -- Disabled
   */
}qcmap_msgr_get_dun_dongle_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the Early Ethernet Mode */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  Enable Early Ethernet Mode */
  uint8_t enable_early_eth_mode;
  /**<   Enable/disable EarlyEthernetMode. Values:\n
      - TRUE -- Enable\n
      - FALSE -- Disable
   */
}qcmap_msgr_set_early_ethernet_mode_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the Early Ethernet Mode */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_early_ethernet_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the current Early Ethernet Mode */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_early_ethernet_mode_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the current Early Ethernet Mode */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Early Ethernet Mode Status */
  uint8_t early_eth_mode_status_valid;  /**< Must be set to true if early_eth_mode_status is being passed */
  uint8_t early_eth_mode_status;
  /**<   EarlyEthernetMode status. Values: \n
       - TRUE -- Enabled \n
       - FALSE -- Disabled
   */
}qcmap_msgr_get_early_ethernet_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the SW IP Channel configuration for fusion devices */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_sw_ip_ch_cfg_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the SW IP Channel configuration for fusion devices */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Configuration for SW IP channel */
  uint8_t config_valid;  /**< Must be set to true if config is being passed */
  qcmap_msgr_sw_ip_ch_config_v01 config;
  /**<   Returns the configuration for sw ip channel \n
  */
}qcmap_msgr_get_sw_ip_ch_cfg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets up SW IP Channel configuration for fusion devices */
typedef struct {

  /* Mandatory */
  /*  Config Operation */
  uint8_t enable_sw_ip_cfg;
  /**<   Sets/deletes sw ip channel config. Values:\n
      - TRUE -- Sets the configuration \n
      - FALSE -- Deletes the configuration
   */

  /* Optional */
  /*  Configuration for SW IP channel */
  uint8_t config_valid;  /**< Must be set to true if config is being passed */
  qcmap_msgr_sw_ip_ch_config_v01 config;
  /**<   Configuration for sw ip channel \n
  */
}qcmap_msgr_set_sw_ip_ch_cfg_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets up SW IP Channel configuration for fusion devices */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_sw_ip_ch_cfg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; set data path optimization status */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;

  /* Mandatory */
  /*  Data Path Optimization Status */
  uint8_t data_path_opt_status;
  /**<   Set data path status \n
       - 1 -- Enable \n
       - 0 --Disable \n
    */
}qcmap_msgr_set_data_path_opt_status_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; set data path optimization status */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_data_path_opt_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; set data path opt configuration */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_data_path_opt_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; set data path opt configuration */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Data Path Optimization Status */
  uint8_t data_path_opt_status_valid;  /**< Must be set to true if data_path_opt_status is being passed */
  uint8_t data_path_opt_status;
}qcmap_msgr_get_data_path_opt_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the current Proxy MIP mode */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_pmip_mode_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the current Proxy MIP mode */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  PMIP Debug Mode */
  uint8_t pmip_debug_mode_valid;  /**< Must be set to true if pmip_debug_mode is being passed */
  uint8_t pmip_debug_mode;
  /**<   Indicates the current value of PMIP debug mode. Values: \n
       - 0 -- Disabled \n
       - 1 -- Pmip debug mode is enabled
  */

  /* Optional */
  /*  PMIP Mode Status */
  uint8_t pmip_mode_valid;  /**< Must be set to true if pmip_mode is being passed */
  uint8_t pmip_mode;
  /**<   Indicates the current value of PMIP mode. Values: \n
       - 0 -- Disabled \n
       - 1 -- Enable PMIP mode
  */

  /* Optional */
  /*  PMIP Mode IP Type */
  uint8_t pmip_mode_type_valid;  /**< Must be set to true if pmip_mode_type is being passed */
  qcmap_msgr_ip_family_enum_v01 pmip_mode_type;
  /**<   Indicates the IP type of PMIP mode. Values: \n
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  /* Optional */
  /*  PMIP Mobile Node Identifier Type */
  uint8_t pmip_mobile_node_identifier_type_valid;  /**< Must be set to true if pmip_mobile_node_identifier_type is being passed */
  qcmap_msgr_pmip_mobile_node_identifier_enum_v01 pmip_mobile_node_identifier_type;
  /**<   Pmip mobile node identifier type. Values: \n
      - QCMAP_MSGR_PMIP_MOBILE_NODE_IDENTIFIER_MAC (0) --  PMIP MOBILE NODE IDENTIFIER is MAC of mobile Node
      - QCMAP_MSGR_PMIP_MOBILE_NODE_IDENTIFIER_STRING (1) --  PMIP MOBILE NODE IDENTIFIER is custom string
 */

  /* Optional */
  /*  PMIP Service Selection String */
  uint8_t pmip_service_selection_string_valid;  /**< Must be set to true if pmip_service_selection_string is being passed */
  char pmip_service_selection_string[QCMAP_MSGR_PMIP_SERVICE_SELECTION_STRING_LENGTH_V01 + 1];
  /**<  Pmip Modify Service Selection String.
      This is valid only if pmip_mobile_node_identifier_type
      is QCMAP_MSGR_PMIP_MOBILE_NODE_IDENTIFIER_STRING
   */

  /* Optional */
  /*  PMIP Mobile Node Identifier String */
  uint8_t pmip_mn_id_string_valid;  /**< Must be set to true if pmip_mn_id_string is being passed */
  char pmip_mn_id_string[QCMAP_MSGR_PMIP_MN_ID_STRING_LENGTH_V01 + 1];
  /**<   Pmip mobile node identifier mn id string. */

  /* Optional */
  /* PMIP v4 Mode type */
  uint8_t pmipv4_mode_type_valid;  /**< Must be set to true if pmipv4_mode_type is being passed */
  qcmap_msgr_pmipv4_mode_enum_v01 pmipv4_mode_type;
  /**<   pmip v4 mode type. Values: \n
      - QCMAP_MSGR_PMIPV4_MODE_CPE (1) --  MIPV4 MODE is CPE
      - QCMAP_MSGR_PMIPV4_MODE_SECONDARY_ROUTER (2) --  PMIPV4 MODE is SECONDARY ROUTER
 */

  /* Optional */
  /*  LMA v4 IP */
  uint8_t lma_ipv4_addr_valid;  /**< Must be set to true if lma_ipv4_addr is being passed */
  uint32_t lma_ipv4_addr;
  /**<     IPv4 address of the client. */

  /* Optional */
  /*  Pmipv4 secondary router param */
  uint8_t pmipv4_sec_router_param_valid;  /**< Must be set to true if pmipv4_sec_router_param is being passed */
  qcmap_pmipv4_sec_router_param_v01 pmipv4_sec_router_param;

  /* Optional */
  /*  LMA v6 IP */
  uint8_t lma_ipv6_addr_valid;  /**< Must be set to true if lma_ipv6_addr is being passed */
  uint8_t lma_ipv6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<     Link Local IPv6 address of the client. */
}qcmap_msgr_get_pmip_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the current Proxy MIP mode */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Mandatory */
  /*  PMIP Debug Mode */
  uint8_t enable_pmip_debug_mode;
  /**<   Specifies if PMIP to be enabled in debug mode. Values: \n
       - 0 -- Do not enable (default) \n
       - 1 -- Enable PMIP in Debug mode
  */

  /* Mandatory */
  /*  PMIP mode */
  uint8_t enable_pmip_mode;
  /**<   Specifies if PMIP mode to be enabled. Values: \n
       - 0 -- Do not enable (default) \n
       - 1 -- Enable PMIP mode
  */

  /* Mandatory */
  /*  PMIP Mode IP Type */
  qcmap_msgr_ip_family_enum_v01 pmip_mode_type;
  /**<   Indicates the IP type of PMIP mode. Values: \n
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  /* Optional */
  /*  Pmip mobile node identifier type */
  uint8_t pmip_mobile_node_identifier_type_valid;  /**< Must be set to true if pmip_mobile_node_identifier_type is being passed */
  qcmap_msgr_pmip_mobile_node_identifier_enum_v01 pmip_mobile_node_identifier_type;
  /**<   Pmip mobile node identifier type. Values: \n
      - QCMAP_MSGR_PMIP_MOBILE_NODE_IDENTIFIER_MAC (0) --  PMIP MOBILE NODE IDENTIFIER is MAC of mobile Node
      - QCMAP_MSGR_PMIP_MOBILE_NODE_IDENTIFIER_STRING (1) --  PMIP MOBILE NODE IDENTIFIER is custom string
 */

  /* Optional */
  /*  PMIP Service Selection String */
  uint8_t pmip_service_selection_string_valid;  /**< Must be set to true if pmip_service_selection_string is being passed */
  char pmip_service_selection_string[QCMAP_MSGR_PMIP_SERVICE_SELECTION_STRING_LENGTH_V01 + 1];
  /**<  Pmip Modify Service Selection String.
      This is valid only if pmip_mobile_node_identifier_type
      is QCMAP_MSGR_PMIP_MOBILE_NODE_IDENTIFIER_STRING
   */

  /* Optional */
  /*  PMIP Mobile Node Identifier String */
  uint8_t pmip_mn_id_string_valid;  /**< Must be set to true if pmip_mn_id_string is being passed */
  char pmip_mn_id_string[QCMAP_MSGR_PMIP_MN_ID_STRING_LENGTH_V01 + 1];
  /**<   Pmip mobile node identifier mn id string. */

  /* Optional */
  /*  PMIP V4 Mode Type */
  uint8_t pmipv4_mode_type_valid;  /**< Must be set to true if pmipv4_mode_type is being passed */
  qcmap_msgr_pmipv4_mode_enum_v01 pmipv4_mode_type;
  /**<   PMIP v4 mode type. Values: \n
      - QCMAP_MSGR_PMIPV4_MODE_CPE (1) --  MIPV4 MODE is CPE
      - QCMAP_MSGR_PMIPV4_MODE_SECONDARY_ROUTER (2) --  PMIPV4 MODE is SECONDARY ROUTER
 */

  /* Optional */
  /*  LMA v4 IP */
  uint8_t lma_ipv4_addr_valid;  /**< Must be set to true if lma_ipv4_addr is being passed */
  uint32_t lma_ipv4_addr;
  /**<     IPv4 address of the client. */

  /* Optional */
  /*  Pmipv4 secondary router param */
  uint8_t pmipv4_sec_router_param_valid;  /**< Must be set to true if pmipv4_sec_router_param is being passed */
  qcmap_pmipv4_sec_router_param_v01 pmipv4_sec_router_param;

  /* Optional */
  /*  LMA v6 IP */
  uint8_t lma_ipv6_addr_valid;  /**< Must be set to true if lma_ipv6_addr is being passed */
  uint8_t lma_ipv6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<     Link Local IPv6 address of the client. */
}qcmap_msgr_set_pmip_mode_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the current Proxy MIP mode */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_pmip_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets Backhaul status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_backhaul_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets Backhaul status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Current backhaul IPV4 status */
  uint8_t backhaul_v4_status_valid;  /**< Must be set to true if backhaul_v4_status is being passed */
  uint8_t backhaul_v4_status;
  /**<   Indicates the current backhaul IPV4 status. Values: \n
       - 0 -- IPV4 Backhaul is not connected\n
       - 1 -- IPV4 Backhaul is connected
  */

  /* Optional */
  /*  Current backhaul IPV6 status */
  uint8_t backhaul_v6_status_valid;  /**< Must be set to true if backhaul_v6_status is being passed */
  uint8_t backhaul_v6_status;
  /**<   Indicates the current backhaul IPV6 status. Values: \n
       - 0 -- IPV6 Backhaul is not connected\n
       - 1 -- IPV6 Backhaul is connected
  */

  /* Optional */
  /*  Current backhaul type */
  uint8_t backhaul_type_valid;  /**< Must be set to true if backhaul_type is being passed */
  qcmap_msgr_backhaul_type_enum_v01 backhaul_type;
  /**<   Indicates the current active backhaul type if backhaul is in connected state\n
      - QCMAP_MSGR_WWAN_BACKHAUL (0x01) --  WWAN Backhaul
      - QCMAP_MSGR_USB_CRADLE_BACKHAUL (0x02) --  Cradle  Backhaul
      - QCMAP_MSGR_WLAN_BACKHAUL (0x03) --  WLAN  Backhaul
      - QCMAP_MSGR_ETHERNET_BACKHAUL (0x04) --  ETHERNET  Backhaul
      - QCMAP_MSGR_BT_BACKHAUL (0x05) --  BT WAN Backhaul
 */
}qcmap_msgr_get_backhaul_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the backhaul status. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Optional */
  /*  Backhaul IPV4 Status */
  uint8_t backhaul_v4_status_valid;  /**< Must be set to true if backhaul_v4_status is being passed */
  uint8_t backhaul_v4_status;
  /**<   Indicates the active backhaul IPV4 status Values: \n
       - 0 -- IPV4 Backhaul is not connected\n
       - 1 -- IPV4 Backhaul is connected
  */

  /* Optional */
  /*  Backhaul IPV6 Status */
  uint8_t backhaul_v6_status_valid;  /**< Must be set to true if backhaul_v6_status is being passed */
  uint8_t backhaul_v6_status;
  /**<   Indicates the active backhaul IPV6 status Values: \n
       - 0 -- IPV6 Backhaul is not connected\n
       - 1 -- IPV6 Backhaul is connected
  */

  /* Optional */
  /*  Backhaul type */
  uint8_t backhaul_type_valid;  /**< Must be set to true if backhaul_type is being passed */
  qcmap_msgr_backhaul_type_enum_v01 backhaul_type;
  /**<   Indicates the active backhaul type if backhaul is in connected state. Values: \n
      - QCMAP_MSGR_WWAN_BACKHAUL (0x01) --  WWAN Backhaul
      - QCMAP_MSGR_USB_CRADLE_BACKHAUL (0x02) --  Cradle  Backhaul
      - QCMAP_MSGR_WLAN_BACKHAUL (0x03) --  WLAN  Backhaul
      - QCMAP_MSGR_ETHERNET_BACKHAUL (0x04) --  ETHERNET  Backhaul
      - QCMAP_MSGR_BT_BACKHAUL (0x05) --  BT WAN Backhaul
 */
}qcmap_msgr_backhaul_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets wwan roaming status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_wwan_roaming_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets wwan roaming status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  WWAN Roaming status */
  uint8_t wwan_roaming_status_valid;  /**< Must be set to true if wwan_roaming_status is being passed */
  qcmap_msgr_wwan_roaming_status_enum_v01 wwan_roaming_status;
  /**<   Indicates the current wwan roaming status \n
      - QCMAP_MSGR_ROAM_STATUS_OFF (0x00) --
      - QCMAP_MSGR_ROAM_STATUS_ON (0x01) --
      - QCMAP_MSGR_ROAM_STATUS_BLINK (0x02) --
      - QCMAP_MSGR_ROAM_STATUS_OUT_OF_NEIGHBORHOOD (0x03) --
      - QCMAP_MSGR_ROAM_STATUS_OUT_OF_BLDG (0x04) --
      - QCMAP_MSGR_ROAM_STATUS_PREF_SYS (0x05) --
      - QCMAP_MSGR_ROAM_STATUS_AVAIL_SYS (0x06) --
      - QCMAP_MSGR_ROAM_STATUS_ALLIANCE_PARTNER (0x07) --
      - QCMAP_MSGR_ROAM_STATUS_PREMIUM_PARTNER (0x08) --
      - QCMAP_MSGR_ROAM_STATUS_FULL_SVC (0x09) --
      - QCMAP_MSGR_ROAM_STATUS_PARTIAL_SVC (0x0A) --
      - QCMAP_MSGR_ROAM_STATUS_BANNER_ON (0x0B) --
      - QCMAP_MSGR_ROAM_STATUS_BANNER_OFF (0x0C) --
 */
}qcmap_msgr_get_wwan_roaming_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the wwan roaming status. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
   */

  /* Mandatory */
  /*  WWAN Roaming status Indication */
  qcmap_msgr_wwan_roaming_status_enum_v01 wwan_roaming_status;
  /**<   Indicates the wwan roaming status \n
      - QCMAP_MSGR_ROAM_STATUS_OFF (0x00) --
      - QCMAP_MSGR_ROAM_STATUS_ON (0x01) --
      - QCMAP_MSGR_ROAM_STATUS_BLINK (0x02) --
      - QCMAP_MSGR_ROAM_STATUS_OUT_OF_NEIGHBORHOOD (0x03) --
      - QCMAP_MSGR_ROAM_STATUS_OUT_OF_BLDG (0x04) --
      - QCMAP_MSGR_ROAM_STATUS_PREF_SYS (0x05) --
      - QCMAP_MSGR_ROAM_STATUS_AVAIL_SYS (0x06) --
      - QCMAP_MSGR_ROAM_STATUS_ALLIANCE_PARTNER (0x07) --
      - QCMAP_MSGR_ROAM_STATUS_PREMIUM_PARTNER (0x08) --
      - QCMAP_MSGR_ROAM_STATUS_FULL_SVC (0x09) --
      - QCMAP_MSGR_ROAM_STATUS_PARTIAL_SVC (0x0A) --
      - QCMAP_MSGR_ROAM_STATUS_BANNER_ON (0x0B) --
      - QCMAP_MSGR_ROAM_STATUS_BANNER_OFF (0x0C) --
 */
}qcmap_msgr_wwan_roaming_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets LAN Bridges currently configured */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_lan_bridges_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets LAN Bridges currently configured */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Bridge List */
  uint8_t bridge_list_valid;  /**< Must be set to true if bridge_list is being passed */
  qcmap_msgr_bridge_list_v01 bridge_list;
}qcmap_msgr_get_lan_bridges_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Switch LAN Bridge preference. */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
   */

  /* Mandatory */
  /*  VLAN ID */
  int16_t bridge_vlan_id;
}qcmap_msgr_select_lan_bridge_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Switch LAN Bridge preference. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_select_lan_bridge_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the information of all active wlan Interfaces. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_active_wlan_if_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the information of all active wlan Interfaces. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Active Entries */
  uint8_t active_entries_valid;  /**< Must be set to true if active_entries is being passed */
  uint8_t active_entries;
  /**<   Number of active WLAN interfaces \n
  */

  /* Optional */
  /*  WLAN Interface Information */
  uint8_t wlan_if_info_valid;  /**< Must be set to true if wlan_if_info is being passed */
  uint32_t wlan_if_info_len;  /**< Must be set to # of elements in wlan_if_info */
  qcmap_msgr_wlan_if_info_v01 wlan_if_info[QCMAP_MSGR_MAX_WLAN_IFACE_V01];
  /**<   Info for all active wlan IF \n
  */
}qcmap_msgr_get_active_wlan_if_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets Always on WLAN feature */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
   */

  /* Mandatory */
  /*  Always on WLAN state */
  uint8_t enable_always_on_wlan;
  /**<   Enable/disable always on wlan. Values:\n
      - TRUE  -- Enable\n
      - FALSE -- Disable(default)
   */
}qcmap_msgr_set_always_on_wlan_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets Always on WLAN feature */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_always_on_wlan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets current status of Always on WLAN flag */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_always_on_wlan_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets current status of Always on WLAN flag */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Always on WLAN status */
  uint8_t always_on_wlan_status_valid;  /**< Must be set to true if always_on_wlan_status is being passed */
  uint8_t always_on_wlan_status;
  /**<   Always on WLAN status. Values: \n
       - TRUE -- Enabled \n
       - FALSE -- Disabled
   */
}qcmap_msgr_get_always_on_wlan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_enums
    @{
  */
typedef enum {
  QCMAP_P2P_ROLE_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QCMAP_P2P_ROLE_GO_V01 = 0x00, /**<  Peer-to-peer role Group Owner  */
  QCMAP_P2P_ROLE_CLI_V01 = 0x01, /**<  Peer-to-peer role Client  */
  QCMAP_P2P_ROLE_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qcmap_p2p_role_type_v01;
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets p2p status and config params */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
   */

  /* Mandatory */
  /*  Peer-to-Peer Status */
  uint8_t p2p_status;
  /**<   Enable/disable P2P role status. Values:\n
      - TRUE  -- Enable\n
      - FALSE -- Disable(default)
   */

  /* Optional */
  /*  Peer-to-Peer role */
  uint8_t p2p_role_valid;  /**< Must be set to true if p2p_role is being passed */
  qcmap_p2p_role_type_v01 p2p_role;
  /**<   Specifies the peer-to-peer role type. Values: \n
      - QCMAP_P2P_ROLE_GO (0x00) --  Peer-to-peer role Group Owner
      - QCMAP_P2P_ROLE_CLI (0x01) --  Peer-to-peer role Client
 */
}qcmap_msgr_set_p2p_role_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets p2p status and config params */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_p2p_role_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Get current status of whether P2P is enabled or disabled */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_p2p_role_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Get current status of whether P2P is enabled or disabled */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Peer-to-Peer Status */
  uint8_t p2p_status_valid;  /**< Must be set to true if p2p_status is being passed */
  uint8_t p2p_status;
  /**<   P2P enable/disable status. Values: \n
       - TRUE -- Enabled \n
       - FALSE -- Disabled
   */

  /* Optional */
  /*  Peer-to-Peer role */
  uint8_t p2p_role_valid;  /**< Must be set to true if p2p_role is being passed */
  qcmap_p2p_role_type_v01 p2p_role;
  /**<   Specifies the peer-to-peer role type. Values: \n
      - QCMAP_P2P_ROLE_GO (0x00) --  Peer-to-peer role Group Owner
      - QCMAP_P2P_ROLE_CLI (0x01) --  Peer-to-peer role Client
 */
}qcmap_msgr_get_p2p_role_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets WWAN Profile preference */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_wwan_profile_preference_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets WWAN Profile preference */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Current Profile Handle */
  uint8_t current_profile_handle_valid;  /**< Must be set to true if current_profile_handle is being passed */
  profile_handle_type_v01 current_profile_handle;
  /**<   Profile number to be used for PDN. */
}qcmap_msgr_get_wwan_profile_preference_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the current l2tp hw offload mode set at device (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_l2tp_hw_offload_mode_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the current l2tp hw offload mode set at device (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  L2TP Hardware Offload Mode */
  uint8_t l2tp_hw_offload_mode_valid;  /**< Must be set to true if l2tp_hw_offload_mode is being passed */
  qcmap_msgr_l2tp_hw_offload_mode_enum_v01 l2tp_hw_offload_mode;
  /**<   Identifies L2TP Hw Offload mode. Values: \n
      - QCMAP_MSGR_L2TP_HW_OFFLOAD_NONE (0) --  L2TP no hardware offload mode
      - QCMAP_MSGR_L2TP_HW_L2L_MODE (0x01) --  L2TP Lan to Lan mode
      - QCMAP_MSGR_L2TP_HW_E2E_MODE (0x02) --  L2TP End to End mode
 */
}qcmap_msgr_get_l2tp_hw_offload_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the l2tp Hw offload mode (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  L2TP Hardware Offload Mode */
  uint8_t l2tp_hw_offload_mode_valid;  /**< Must be set to true if l2tp_hw_offload_mode is being passed */
  qcmap_msgr_l2tp_hw_offload_mode_enum_v01 l2tp_hw_offload_mode;
  /**<   Identifies L2TP Hw Offload mode. Values: \n
      - QCMAP_MSGR_L2TP_HW_OFFLOAD_NONE (0) --  L2TP no hardware offload mode
      - QCMAP_MSGR_L2TP_HW_L2L_MODE (0x01) --  L2TP Lan to Lan mode
      - QCMAP_MSGR_L2TP_HW_E2E_MODE (0x02) --  L2TP End to End mode
 */
}qcmap_msgr_set_l2tp_hw_offload_mode_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the l2tp Hw offload mode (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_l2tp_hw_offload_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Returns the IP configuration to the requested client. */
typedef struct {

  /* Optional */
  /*  IP family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version to query. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */
}qcmap_msgr_get_ip_assignment_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Returns the IP configuration to the requested client. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  IP family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version of result. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */

  /* Optional */
  /*  IPv4 Address And Subnet Mask */
  uint8_t ipv4_addr_valid;  /**< Must be set to true if ipv4_addr is being passed */
  qcmap_ip4_addr_subnet_mask_v01 ipv4_addr;
  /**<   Preferred IPv4 and subnet mask address assigned to the TE.
       The assigned value is provided to the host via DHCP.
   */

  /* Optional */
  /*  IPv4 Gateway Address */
  uint8_t ipv4_gateway_addr_valid;  /**< Must be set to true if ipv4_gateway_addr is being passed */
  uint32_t ipv4_gateway_addr;
  /**<   IPv4 Gateway address.
   */

  /* Optional */
  /*  IPv6 Address and Prefix Length */
  uint8_t ipv6_addr_valid;  /**< Must be set to true if ipv6_addr is being passed */
  qcmap_ip6_addr_prefix_len_v01 ipv6_addr;
  /**<   Preferred IPv6 address assigned to the TE.
       The assigned value is provided to the host.
   */

  /* Optional */
  /*  IPv6 Gateway Address */
  uint8_t ipv6_gateway_addr_valid;  /**< Must be set to true if ipv6_gateway_addr is being passed */
  uint8_t ipv6_gateway_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<   IPv6 Gateway address.
   */

  /* Optional */
  /*  MTU Size */
  uint8_t mtu_valid;  /**< Must be set to true if mtu is being passed */
  uint32_t mtu;
  /**<   MTU Size.
   */

  /* Optional */
  /*  Technology Name */
  uint8_t technology_name_valid;  /**< Must be set to true if technology_name is being passed */
  qcmap_technology_name_enum_v01 technology_name;
  /**<   Identifies the technology name. Values:
      - QCMAP_TECHNOLOGY_NAME_CDMA (-32767) --   QCMAP_TECHNOLOGY_NAME_CDMA (-32767) --  0x8001 -- CDMA
      - QCMAP_TECHNOLOGY_NAME_UMTS (-32764) --  QCMAP_TECHNOLOGY_NAME_UMTS (-32764) --  0x8004 -- UMTS
      - QCMAP_TECHNOLOGY_NAME_WLAN_LOCAL_BRKOUT (-32736) --  QCMAP_TECHNOLOGY_NAME_WLAN_LOCAL_BRKOUT (-32736) --  0x8020 -- WLAN_LOCAL_BRKOUT
      - QCMAP_TECHNOLOGY_NAME_IWLAN_S2B (-32735) --  QCMAP_TECHNOLOGY_NAME_IWLAN_S2B (-32735) --  0x8021 -- IWLAN_S2B
      - QCMAP_TECHNOLOGY_NAME_EPC (-30592) --  QCMAP_TECHNOLOGY_NAME_EPC (-30592) --  0x8880 -- EPC
      - QCMAP_TECHNOLOGY_NAME_EMBMS (-30590) --  QCMAP_TECHNOLOGY_NAME_EMBMS (-30590) --  0x8882 -- EMBMS
      - QCMAP_TECHNOLOGY_NAME_NON_IP (-30588) --  QCMAP_TECHNOLOGY_NAME_NON_IP (-30588) --  0x8884 -- Non-IP
      - QCMAP_TECHNOLOGY_NAME_MODEM_LINK_LOCAL (-30584) --  QCMAP_TECHNOLOGY_NAME_MODEM_LINK_LOCAL (-30584) --  0x8888 -- Modem link local
 */
}qcmap_msgr_get_ip_assignment_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets WWAN Interface Name. */
typedef struct {

  /* Optional */
  /*  IP family */
  uint8_t ip_family_valid;  /**< Must be set to true if ip_family is being passed */
  qcmap_msgr_ip_family_enum_v01 ip_family;
  /**<   Identifies the IP version to query. Values:
      - QCMAP_MSGR_IP_FAMILY_V4 (0x04) --  IPv4 version
      - QCMAP_MSGR_IP_FAMILY_V6 (0x06) --  IPv6 version
      - QCMAP_MSGR_IP_FAMILY_V4V6 (0x0A) --  Dual mode version
 */
}qcmap_msgr_get_wwan_iface_name_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets WWAN Interface Name. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Interface name */
  uint8_t iface_name_valid;  /**< Must be set to true if iface_name is being passed */
  char iface_name[QCMAP_MAX_IFACE_NAME_SIZE_V01];
}qcmap_msgr_get_wwan_iface_name_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the Early Ethernet Configuration (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  Early Ethernet IPv6 Address */
  uint8_t ipv6_addr_valid;  /**< Must be set to true if ipv6_addr is being passed */
  uint8_t ipv6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<     IPv6 address for early ethernet interface. */

  /* Optional */
  /*  Early Ethernet MAC Address */
  uint8_t mac_addr_valid;  /**< Must be set to true if mac_addr is being passed */
  uint8_t mac_addr[QCMAP_MSGR_MAC_ADDR_LEN_V01];
  /**<   MAC address of the early ethernet interface. */
}qcmap_msgr_set_early_ethernet_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the Early Ethernet Configuration (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_early_ethernet_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the Early Ethernet Configuration (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_early_ethernet_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the Early Ethernet Configuration (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Early Ethernet IPv6 Address */
  uint8_t ipv6_addr_valid;  /**< Must be set to true if ipv6_addr is being passed */
  uint8_t ipv6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01];
  /**<     IPv6 address for early ethernet interface. */

  /* Optional */
  /*  Early Ethernet MAC Address */
  uint8_t mac_addr_valid;  /**< Must be set to true if mac_addr is being passed */
  uint8_t mac_addr[QCMAP_MSGR_MAC_ADDR_LEN_V01];
  /**<   MAC address of the early ethernet interface. */
}qcmap_msgr_get_early_ethernet_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Enables/Disables IPV6 NAT */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  Enable IPv6 NAT */
  uint8_t enable_ipv6_nat_valid;  /**< Must be set to true if enable_ipv6_nat is being passed */
  uint8_t enable_ipv6_nat;
  /**<   Indicates whether a IPv6 nat is allowed
  */

  /* Optional */
  /*  IPv6 NAT Type */
  uint8_t nat_type_valid;  /**< Must be set to true if nat_type is being passed */
  qcmap_msgr_nat_enum_v01 nat_type;
  /**<   Indicates the type of NAT. Values:\n
      - QCMAP_MSGR_NAT_SYMMETRIC_NAT (0) --  NAT type is symmetric
      - QCMAP_MSGR_NAT_PORT_RESTRICTED_CONE_NAT (1) --  NAT type is Port-Restricted Cone NAT
      - QCMAP_MSGR_NAT_FULL_CONE_NAT (2) --  NAT type is Full Cone NAT
      - QCMAP_MSGR_NAT_ADDRESS_RESTRICTED_NAT (3) --  NAT type is Address-Restricted NAT
 */
}qcmap_msgr_set_ipv6_nat_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Enables/Disables IPV6 NAT */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_ipv6_nat_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Queries the IPv6 NAT setting. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_ipv6_nat_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Queries the IPv6 NAT setting. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  IPv6 NAT Value */
  uint8_t ipv6_nat_status_valid;  /**< Must be set to true if ipv6_nat_status is being passed */
  uint8_t ipv6_nat_status;
  /**<   Indicates the current status of IPv6 NAT on the device
  */

  /* Optional */
  /*  IPv6 NAT Type */
  uint8_t nat_type_valid;  /**< Must be set to true if nat_type is being passed */
  qcmap_msgr_nat_enum_v01 nat_type;
  /**<   Indicates the type of NAT. Values:\n
      - QCMAP_MSGR_NAT_SYMMETRIC_NAT (0) --  NAT type is symmetric
      - QCMAP_MSGR_NAT_PORT_RESTRICTED_CONE_NAT (1) --  NAT type is Port-Restricted Cone NAT
      - QCMAP_MSGR_NAT_FULL_CONE_NAT (2) --  NAT type is Full Cone NAT
      - QCMAP_MSGR_NAT_ADDRESS_RESTRICTED_NAT (3) --  NAT type is Address-Restricted NAT
 */
}qcmap_msgr_get_ipv6_nat_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets the current device mode set at device */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_device_mode_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets the current device mode set at device */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Device Mode */
  uint8_t device_mode_valid;  /**< Must be set to true if device_mode is being passed */
  qcmap_msgr_device_mode_enum_v01 device_mode;
  /**<   Identifies Device mode. Values: \n
      - QCMAP_MSGR_DEVICE_NONE (0x00) --   Device no hardware offload mode
      - QCMAP_MSGR_DEVICE_L2L (0x01) --   Device Lan to Lan mode
      - QCMAP_MSGR_DEVICE_E2E (0x02) --   Device End to End mode
 */
}qcmap_msgr_get_device_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sets the device mode */
typedef struct {

  /* Mandatory */
  /*  Mobile AP Handle */
  uint32_t mobile_ap_handle;
  /**<   Handle identifying the mobile AP call instance.
       The value must be the handle previously returned by
       QMI_QCMAP_ MSGR_MOBILE_AP_ENABLE_REQ.
  */

  /* Optional */
  /*  Device Mode */
  uint8_t device_mode_valid;  /**< Must be set to true if device_mode is being passed */
  qcmap_msgr_device_mode_enum_v01 device_mode;
  /**<   Identifies device mode. Values: \n
      - QCMAP_MSGR_DEVICE_NONE (0x00) --   Device no hardware offload mode
      - QCMAP_MSGR_DEVICE_L2L (0x01) --   Device Lan to Lan mode
      - QCMAP_MSGR_DEVICE_E2E (0x02) --   Device End to End mode
 */
}qcmap_msgr_set_device_mode_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sets the device mode */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_set_device_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Get all connected PDN information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_all_connected_pdn_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Get all connected PDN information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Connected PDN information */
  uint8_t wwan_info_ex_valid;  /**< Must be set to true if wwan_info_ex is being passed */
  uint32_t wwan_info_ex_len;  /**< Must be set to # of elements in wwan_info_ex */
  qcmap_msgr_wwan_info_ex_v01 wwan_info_ex[QCMAP_MAX_NUM_BACKHAULS_V01];
  /**<   Connected PDN information.
  */
}qcmap_msgr_get_all_connected_pdn_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Get Bearer Techonology. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_get_bearer_tech_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Get Bearer Techonology. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Bearer Technology */
  uint8_t bearer_tech_valid;  /**< Must be set to true if bearer_tech is being passed */
  qcmap_msgr_data_bearer_tech_type_enum_v01 bearer_tech;
  /**<   Bearer Technology. Values: \n
      - QCMAP_MSGR_DATA_BEARER_TECH_UNKNOWN (0) --  Unknown bearer.
      - QCMAP_MSGR_DATA_BEARER_TECH_CDMA_1X (1) --  1X technology.
      - QCMAP_MSGR_DATA_BEARER_TECH_EVDO_REV0 (2) --  CDMA Rev 0.
      - QCMAP_MSGR_DATA_BEARER_TECH_EVDO_REVA (3) --  CDMA Rev A.
      - QCMAP_MSGR_DATA_BEARER_TECH_EVDO_REVB (4) --  CDMA Rev B.
      - QCMAP_MSGR_DATA_BEARER_TECH_EHRPD (5) --  EHRPD.
      - QCMAP_MSGR_DATA_BEARER_TECH_FMC (6) --  Fixed mobile convergence.
      - QCMAP_MSGR_DATA_BEARER_TECH_HRPD (7) --  HRPD
      - QCMAP_MSGR_DATA_BEARER_TECH_3GPP2_WLAN (8) --  IWLAN
      - QCMAP_MSGR_DATA_BEARER_TECH_WCDMA (9) --  WCDMA.
      - QCMAP_MSGR_DATA_BEARER_TECH_GPRS (10) --  GPRS.
      - QCMAP_MSGR_DATA_BEARER_TECH_HSDPA (11) --  HSDPA.
      - QCMAP_MSGR_DATA_BEARER_TECH_HSUPA (12) --  HSUPA.
      - QCMAP_MSGR_DATA_BEARER_TECH_EDGE (13) --  EDGE.
      - QCMAP_MSGR_DATA_BEARER_TECH_LTE (14) --  LTE.
      - QCMAP_MSGR_DATA_BEARER_TECH_HSDPA_PLUS (15) --  HSDPA+.
      - QCMAP_MSGR_DATA_BEARER_TECH_DC_HSDPA_PLUS (16) --  DC HSDPA+.
      - QCMAP_MSGR_DATA_BEARER_TECH_HSPA (17) --  HSPA
      - QCMAP_MSGR_DATA_BEARER_TECH_64_QAM (18) --  64 QAM.
      - QCMAP_MSGR_DATA_BEARER_TECH_TDSCDMA (19) --  TD-SCDMA.
      - QCMAP_MSGR_DATA_BEARER_TECH_GSM (20) --  GSM
      - QCMAP_MSGR_DATA_BEARER_TECH_3GPP_WLAN (21) --  IWLAN
      - QCMAP_MSGR_DATA_BEARER_TECH_5G (22) --  5G
 */
}qcmap_msgr_get_bearer_tech_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Registers V2X SPS flow. */
typedef struct {

  /* Mandatory */
  /*  Request ID */
  uint32_t req_id;
  /**<   Request ID.*/

  /* Mandatory */
  /*  Priority */
  uint8_t priority;
  /**<   Priority is an integer from 1 to 8, one
        being the highest priority.
   */

  /* Mandatory */
  /*  Periodicity */
  uint32_t periodicity;
  /**<   Periodicity in milliseconds. */

  /* Mandatory */
  /*  Message Size */
  uint32_t msg_size;
  /**<   Message size in bytes. */

  /* Optional */
  /*  Service ID */
  uint8_t service_id_valid;  /**< Must be set to true if service_id is being passed */
  uint32_t service_id;
  /**<   Service ID.   */

  /* Optional */
  /*  SPS Port */
  uint8_t sps_port_valid;  /**< Must be set to true if sps_port is being passed */
  uint16_t sps_port;
  /**<   SPS port.   */

  /* Optional */
  /*  Event Driven Port */
  uint8_t evt_driven_port_valid;  /**< Must be set to true if evt_driven_port is being passed */
  uint16_t evt_driven_port;
  /**<   Event driven port.   */

  /* Optional */
  /*  Protocol */
  uint8_t protocol_valid;  /**< Must be set to true if protocol is being passed */
  qcmap_msgr_protocol_enum_v01 protocol;
  /**<   Only UDP is supported.
 Values: \n
      - QCMAP_MSGR_PROTO_INVALID (0x00) --  Invalid Protocol \n
      - QCMAP_MSGR_PROTO_TCP (0x01) --  Transmission Control Protocol \n
      - QCMAP_MSGR_PROTO_UDP (0x02) --  User Datagram Protocol \n
      - QCMAP_MSGR_PROTO_TCP_UDP (0x03) --  Transmission Control Protocol/User Datagram Protocol
 */

  /* Optional */
  /*  Peak Transmission Power */
  uint8_t peak_tx_power_valid;  /**< Must be set to true if peak_tx_power is being passed */
  int32_t peak_tx_power;
  /**<   Peak Transmission Power in dBm.
  */

  /* Optional */
  /*  Modulation and Coding Scheme (MCS) Index */
  uint8_t mcs_index_valid;  /**< Must be set to true if mcs_index is being passed */
  uint8_t mcs_index;
  /**<   Modulation and Coding Scheme Index
       (as defined in the IEEE 802.11n-2009 Specification.)
  */

  /* Optional */
  /*  TX Packet Retransmission Setting */
  uint8_t retx_setting_valid;  /**< Must be set to true if retx_setting is being passed */
  qcmap_msgr_v2x_retx_enum_v01 retx_setting;
  /**<   TX packets retransmission setting.
 Values: \n
      - QCMAP_MSGR_V2X_RETX_AUTO (0) --  Default; retransmission is determined by the QCMAP \n
      - QCMAP_MSGR_V2X_RETX_ON (1) --  Retransmission for TX packets on \n
      - QCMAP_MSGR_V2X_RETX_OFF (2) --  Retransmission for TX packets off
 */

  /* Optional */
  /*  Transmission Pool ID */
  uint8_t tx_pool_id_valid;  /**< Must be set to true if tx_pool_id is being passed */
  uint8_t tx_pool_id;
  /**<   Transmission pool ID.
  */
}qcmap_msgr_v2x_sps_flow_reg_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Registers V2X SPS flow. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_v2x_sps_flow_reg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates the result of the SPS flow registration request. */
typedef struct {

  /* Mandatory */
  /*  SPS Flow Registration Result */
  qcmap_msgr_v2x_sps_flow_result_info_v01 reg_result;
}qcmap_msgr_v2x_sps_flow_reg_result_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Deregisters the V2X SPS flow. */
typedef struct {

  /* Mandatory */
  /*  SPS Flow IDs */
  qcmap_msgr_v2x_sps_flow_id_info_v01 flow_id;
}qcmap_msgr_v2x_sps_flow_dereg_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Deregisters the V2X SPS flow. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_v2x_sps_flow_dereg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates the SPS flow deregistration result. */
typedef struct {

  /* Mandatory */
  /*  SPS Flow Deregistration Result */
  qcmap_msgr_v2x_sps_flow_result_info_v01 dereg_result;
}qcmap_msgr_v2x_sps_flow_dereg_result_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Updates the configuration parameters for an existing SPS flow. */
typedef struct {

  /* Mandatory */
  /*  SPS Flow IDs */
  qcmap_msgr_v2x_sps_flow_id_info_v01 flow_id;

  /* Optional */
  /*  Periodicity */
  uint8_t periodicity_valid;  /**< Must be set to true if periodicity is being passed */
  uint32_t periodicity;
  /**<   Periodicity in milliseconds. */

  /* Optional */
  /*  Message Size */
  uint8_t msg_size_valid;  /**< Must be set to true if msg_size is being passed */
  uint32_t msg_size;
  /**<   Message size in bytes. */

  /* Optional */
  /*  Peak Transmission Power */
  uint8_t peak_tx_power_valid;  /**< Must be set to true if peak_tx_power is being passed */
  int32_t peak_tx_power;
  /**<   Peak transmission power in dBm.
  */

  /* Optional */
  /*  Modulation and Coding Scheme (MCS) Index */
  uint8_t mcs_index_valid;  /**< Must be set to true if mcs_index is being passed */
  uint8_t mcs_index;
  /**<   Modulation and coding scheme index.
  */

  /* Optional */
  /*  TX Packet Retransmission Setting */
  uint8_t retx_setting_valid;  /**< Must be set to true if retx_setting is being passed */
  qcmap_msgr_v2x_retx_enum_v01 retx_setting;
  /**<   TX packet retransmission setting.
 Values: \n
      - QCMAP_MSGR_V2X_RETX_AUTO (0) --  Default; retransmission is determined by the QCMAP \n
      - QCMAP_MSGR_V2X_RETX_ON (1) --  Retransmission for TX packets on \n
      - QCMAP_MSGR_V2X_RETX_OFF (2) --  Retransmission for TX packets off
 */

  /* Optional */
  /*  Transmission Pool ID */
  uint8_t tx_pool_id_valid;  /**< Must be set to true if tx_pool_id is being passed */
  uint8_t tx_pool_id;
  /**<   Transmission pool ID.
  */
}qcmap_msgr_v2x_sps_flow_update_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Updates the configuration parameters for an existing SPS flow. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_v2x_sps_flow_update_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Indicates the SPS flow update result. */
typedef struct {

  /* Mandatory */
  /*  SPS Flow Update Result */
  qcmap_msgr_v2x_sps_flow_result_info_v01 update_result;
}qcmap_msgr_v2x_sps_flow_update_result_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Requests V2X SPS flow information. */
typedef struct {

  /* Mandatory */
  /*  SPS Flow IDs */
  qcmap_msgr_v2x_sps_flow_id_info_v01 flow_id;
}qcmap_msgr_v2x_sps_flow_get_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Requests V2X SPS flow information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Priority */
  uint8_t priority_valid;  /**< Must be set to true if priority is being passed */
  uint8_t priority;
  /**<   Priority is an integer from 1 to 8, 1
        being the highest priority.
   */

  /* Optional */
  /*  Periodicity */
  uint8_t periodicity_valid;  /**< Must be set to true if periodicity is being passed */
  uint32_t periodicity;
  /**<   Periodicity in milliseconds */

  /* Optional */
  /*  Message Size */
  uint8_t msg_size_valid;  /**< Must be set to true if msg_size is being passed */
  uint32_t msg_size;
  /**<   Message size in bytes */

  /* Optional */
  /*  Service ID */
  uint8_t service_id_valid;  /**< Must be set to true if service_id is being passed */
  uint32_t service_id;
  /**<   Service ID. */

  /* Optional */
  /*  SPS Port */
  uint8_t sps_port_valid;  /**< Must be set to true if sps_port is being passed */
  uint16_t sps_port;
  /**<    SPS port. */

  /* Optional */
  /*  Event Driven Port */
  uint8_t evt_driven_port_valid;  /**< Must be set to true if evt_driven_port is being passed */
  uint16_t evt_driven_port;
  /**<   Event driven port.  */

  /* Optional */
  /*  Protocol */
  uint8_t protocol_valid;  /**< Must be set to true if protocol is being passed */
  qcmap_msgr_protocol_enum_v01 protocol;
  /**<   Only UDP is currently supported.
 Values: \n
      - QCMAP_MSGR_PROTO_INVALID (0x00) --  Invalid Protocol \n
      - QCMAP_MSGR_PROTO_TCP (0x01) --  Transmission Control Protocol \n
      - QCMAP_MSGR_PROTO_UDP (0x02) --  User Datagram Protocol \n
      - QCMAP_MSGR_PROTO_TCP_UDP (0x03) --  Transmission Control Protocol/User Datagram Protocol
 */

  /* Optional */
  /*  Peak Transmission Power */
  uint8_t peak_tx_power_valid;  /**< Must be set to true if peak_tx_power is being passed */
  int32_t peak_tx_power;
  /**<   Peak Transmission Power in dBm.
  */

  /* Optional */
  /*  Modulation and Coding Scheme (MCS) Index */
  uint8_t mcs_index_valid;  /**< Must be set to true if mcs_index is being passed */
  uint8_t mcs_index;
  /**<   Modulation and coding scheme index.
  */

  /* Optional */
  /*  TX Packet Retransmission Setting */
  uint8_t retx_setting_valid;  /**< Must be set to true if retx_setting is being passed */
  qcmap_msgr_v2x_retx_enum_v01 retx_setting;
  /**<   TX packet retransmission setting.
 Values: \n
      - QCMAP_MSGR_V2X_RETX_AUTO (0) --  Default; retransmission is determined by the QCMAP \n
      - QCMAP_MSGR_V2X_RETX_ON (1) --  Retransmission for TX packets on \n
      - QCMAP_MSGR_V2X_RETX_OFF (2) --  Retransmission for TX packets off
 */

  /* Optional */
  /*  Transmission Pool ID */
  uint8_t tx_pool_id_valid;  /**< Must be set to true if tx_pool_id is being passed */
  uint8_t tx_pool_id;
  /**<   Transmission pool ID.
  */
}qcmap_msgr_v2x_sps_flow_get_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Registers V2X non-SPS flow. */
typedef struct {

  /* Mandatory */
  /*  Request ID */
  uint32_t req_id;
  /**<    Request ID. */

  /* Optional */
  /*  Non-SPS Flow Registration Information */
  uint8_t non_sps_flow_valid;  /**< Must be set to true if non_sps_flow is being passed */
  qcmap_msgr_v2x_non_sps_flow_info_type_v01 non_sps_flow;
  /**<   */

  /* Optional */
  /*  Peak Transmission Power */
  uint8_t peak_tx_power_valid;  /**< Must be set to true if peak_tx_power is being passed */
  int32_t peak_tx_power;
  /**<   Peak transmission power in dBm.
  */

  /* Optional */
  /*  Modulation and Coding Scheme (MCS) Index */
  uint8_t mcs_index_valid;  /**< Must be set to true if mcs_index is being passed */
  uint8_t mcs_index;
  /**<   Modulation and coding scheme index,
       as defined in the IEEE 802.11n-2009 Specification.
  */

  /* Optional */
  /*  TX Packet Retransmission Setting */
  uint8_t retx_setting_valid;  /**< Must be set to true if retx_setting is being passed */
  qcmap_msgr_v2x_retx_enum_v01 retx_setting;
  /**<   TX packet retransmission setting.
 Values: \n
      - QCMAP_MSGR_V2X_RETX_AUTO (0) --  Default; retransmission is determined by the QCMAP \n
      - QCMAP_MSGR_V2X_RETX_ON (1) --  Retransmission for TX packets on \n
      - QCMAP_MSGR_V2X_RETX_OFF (2) --  Retransmission for TX packets off
 */

  /* Optional */
  /*  Transmission Pool ID */
  uint8_t tx_pool_id_valid;  /**< Must be set to true if tx_pool_id is being passed */
  uint8_t tx_pool_id;
  /**<   Transmission pool ID.
  */
}qcmap_msgr_v2x_non_sps_flow_reg_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Registers V2X non-SPS flow. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Registration Result */
  uint8_t result_valid;  /**< Must be set to true if result is being passed */
  qcmap_msgr_v2x_result_type_v01 result;
  /**<
   */
}qcmap_msgr_v2x_non_sps_flow_reg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Deregisters V2X non-SPS flows. */
typedef struct {

  /* Mandatory */
  /*  Request ID */
  uint32_t req_id;
  /**<   Request ID. */

  /* Optional */
  /*  Deregistration Information */
  uint8_t non_sps_flow_info_valid;  /**< Must be set to true if non_sps_flow_info is being passed */
  uint32_t non_sps_flow_info_len;  /**< Must be set to # of elements in non_sps_flow_info */
  qcmap_msgr_v2x_non_sps_info_type_v01 non_sps_flow_info[QCMAP_MSGR_V2X_NON_SPS_MAX_FLOWS_V01];
}qcmap_msgr_v2x_non_sps_flow_dereg_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Deregisters V2X non-SPS flows. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Non-SPS Flow Deregistration Result */
  uint8_t dereg_result_valid;  /**< Must be set to true if dereg_result is being passed */
  uint32_t dereg_result_len;  /**< Must be set to # of elements in dereg_result */
  qcmap_msgr_v2x_result_type_v01 dereg_result[QCMAP_MSGR_V2X_NON_SPS_MAX_FLOWS_V01];
}qcmap_msgr_v2x_non_sps_flow_dereg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Subscribes to V2X services. */
typedef struct {

  /* Mandatory */
  /*  Service Subscription Information */
  qcmap_msgr_v2x_service_sub_info_type_v01 service_info;

  /* Optional */
  /*  Service ID List */
  uint8_t service_id_list_valid;  /**< Must be set to true if service_id_list is being passed */
  uint32_t service_id_list_len;  /**< Must be set to # of elements in service_id_list */
  uint32_t service_id_list[QMI_QCMAP_MSGR_V2X_MAX_SUB_V01];
  /**<   Service ID. */

  /* Optional */
  /*  Port */
  uint8_t port_valid;  /**< Must be set to true if port is being passed */
  uint16_t port;
  /**<   Port. */
}qcmap_msgr_v2x_service_subscribe_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Subscribes to V2X services. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_v2x_service_subscribe_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates the V2X service subscription result. */
typedef struct {

  /* Mandatory */
  /*  Request ID */
  uint32_t req_id;
  /**<   Request ID. */

  /* Optional */
  /*  Result of Wildcard Subscription */
  uint8_t subscribe_wildcard_result_valid;  /**< Must be set to true if subscribe_wildcard_result is being passed */
  uint8_t subscribe_wildcard_result;
  /**<   Result for the ADD_WILDCARD and REMOVE_WILDCARD actions.
       Values: \n
       - 0 -- Success \n
       - 1 -- Failure
  */

  /* Optional */
  /*  Service Subscription Result List */
  uint8_t reg_result_valid;  /**< Must be set to true if reg_result is being passed */
  uint32_t reg_result_len;  /**< Must be set to # of elements in reg_result */
  qcmap_msgr_v2x_result_type_v01 reg_result[QMI_QCMAP_MSGR_V2X_MAX_SUB_V01];
  /**<     */
}qcmap_msgr_v2x_service_subscribe_result_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Requests for V2X service subscription information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_v2x_service_get_subscribe_list_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Requests for V2X service subscription information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Wildcard Enabled */
  uint8_t wildcard_enabled_valid;  /**< Must be set to true if wildcard_enabled is being passed */
  uint8_t wildcard_enabled;
  /**<   Indicates whether WILDCARD is enabled.
       Values: \n
       - 0 -- ADD_WILDCARD enabled\n
       - 1 -- ADD_WILDCARD not enabled
  */

  /* Optional */
  /*  List of Service IDs */
  uint8_t service_id_valid;  /**< Must be set to true if service_id is being passed */
  uint32_t service_id_len;  /**< Must be set to # of elements in service_id */
  uint32_t service_id[QMI_QCMAP_MSGR_V2X_MAX_SUB_V01];
  /**<   List of service IDs. */

  /* Optional */
  /*  Destination Port */
  uint8_t dest_port_valid;  /**< Must be set to true if dest_port is being passed */
  uint16_t dest_port;
  /**<   Destination port information. */
}qcmap_msgr_v2x_service_get_subscribe_list_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Gets V2X capability information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_v2x_get_capability_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Gets V2X capability information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Maximum Number of SPS Flows */
  uint8_t max_sps_flow_cnt_valid;  /**< Must be set to true if max_sps_flow_cnt is being passed */
  uint8_t max_sps_flow_cnt;
  /**<   Maximum number of SPS flows.
  */

  /* Optional */
  /*  Maximum Number of Event Driven Flows */
  uint8_t max_event_driven_flow_cnt_valid;  /**< Must be set to true if max_event_driven_flow_cnt is being passed */
  uint16_t max_event_driven_flow_cnt;
  /**<   Maximum number of event driven flows.
  */

  /* Optional */
  /*  WWAN Concurrency Capability */
  uint8_t is_concurrency_supported_valid;  /**< Must be set to true if is_concurrency_supported is being passed */
  uint8_t is_concurrency_supported;
  /**<   Values:\n
       -0 -- Concurrency is not supported\n
       -1 -- Concurrency is supported
  */

  /* Optional */
  /*  Promixmity Service per Packet Priority Information */
  uint8_t pppp_info_valid;  /**< Must be set to true if pppp_info is being passed */
  uint32_t pppp_info_len;  /**< Must be set to # of elements in pppp_info */
  qcmap_msgr_v2x_pppp_info_type_v01 pppp_info[QMI_QCMAP_MSGR_V2X_PPPP_LIST_MAX_V01];
  /**<
  */

  /* Optional */
  /*  Supported Minimum Transmission Power */
  uint8_t min_tx_pwr_valid;  /**< Must be set to true if min_tx_pwr is being passed */
  int32_t min_tx_pwr;
  /**<   Supported minimum transmission power in dBm.
  */

  /* Optional */
  /*  Supported Maximum Transmission Power */
  uint8_t max_tx_pwr_valid;  /**< Must be set to true if max_tx_pwr is being passed */
  int32_t max_tx_pwr;
  /**<   Supported maximum transmission power in dBm.
  */

  /* Optional */
  /*  Supported SPS Periodicity List */
  uint8_t supported_periodicity_list_valid;  /**< Must be set to true if supported_periodicity_list is being passed */
  uint32_t supported_periodicity_list_len;  /**< Must be set to # of elements in supported_periodicity_list */
  uint32_t supported_periodicity_list[QMI_QCMAP_MSGR_V2X_PERIODICITY_LIST_MAX_V01];
  /**<   List of supported SPS periodicities in milliseconds.
  */

  /* Optional */
  /*  Transmission Pool ID List */
  uint8_t tx_pool_id_list_valid;  /**< Must be set to true if tx_pool_id_list is being passed */
  uint32_t tx_pool_id_list_len;  /**< Must be set to # of elements in tx_pool_id_list */
  qcmap_msgr_v2x_tx_pool_id_info_type_v01 tx_pool_id_list[QMI_QCMAP_MSGR_V2X_POOL_ID_LIST_MAX_V01];
  /**<
  */
}qcmap_msgr_v2x_get_capability_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates the V2X capability information. */
typedef struct {

  /* Optional */
  /*  Maximum Number of SPS Flows */
  uint8_t max_sps_flow_cnt_valid;  /**< Must be set to true if max_sps_flow_cnt is being passed */
  uint8_t max_sps_flow_cnt;
  /**<   Maximum number of SPS flows.
  */

  /* Optional */
  /*  Maximum Number of Event Driven Flows */
  uint8_t max_event_driven_flow_cnt_valid;  /**< Must be set to true if max_event_driven_flow_cnt is being passed */
  uint16_t max_event_driven_flow_cnt;
  /**<   Maximum number of event driven flows.
  */

  /* Optional */
  /*  WWAN Concurrency Capability */
  uint8_t is_concurrency_supported_valid;  /**< Must be set to true if is_concurrency_supported is being passed */
  uint8_t is_concurrency_supported;
  /**<   WWAN Concurrency capability. Values:\n
       -0 -- Concurrency is not supported\n
       -1 -- Concurrency is supported
  */

  /* Optional */
  /*  Promixmity Service per Packet Priority Information */
  uint8_t pppp_info_valid;  /**< Must be set to true if pppp_info is being passed */
  uint32_t pppp_info_len;  /**< Must be set to # of elements in pppp_info */
  qcmap_msgr_v2x_pppp_info_type_v01 pppp_info[QMI_QCMAP_MSGR_V2X_PPPP_LIST_MAX_V01];
  /**<
  */

  /* Optional */
  /*  Supported Minimum Transmission Power */
  uint8_t min_tx_pwr_valid;  /**< Must be set to true if min_tx_pwr is being passed */
  int32_t min_tx_pwr;
  /**<   Supported minimum transmission power in dBm.
  */

  /* Optional */
  /*  Supported Maximum Transmission Power */
  uint8_t max_tx_pwr_valid;  /**< Must be set to true if max_tx_pwr is being passed */
  int32_t max_tx_pwr;
  /**<   Supported maximum transmission power in dBm.
  */

  /* Optional */
  /*  Supported SPS Periodicity List */
  uint8_t supported_periodicity_list_valid;  /**< Must be set to true if supported_periodicity_list is being passed */
  uint32_t supported_periodicity_list_len;  /**< Must be set to # of elements in supported_periodicity_list */
  uint32_t supported_periodicity_list[QMI_QCMAP_MSGR_V2X_PERIODICITY_LIST_MAX_V01];
  /**<   List of supported SPS periodicities in milliseconds.
  */

  /* Optional */
  /*  Transmission Pool ID List */
  uint8_t tx_pool_id_list_valid;  /**< Must be set to true if tx_pool_id_list is being passed */
  uint32_t tx_pool_id_list_len;  /**< Must be set to # of elements in tx_pool_id_list */
  qcmap_msgr_v2x_tx_pool_id_info_type_v01 tx_pool_id_list[QMI_QCMAP_MSGR_V2X_POOL_ID_LIST_MAX_V01];
  /**<   Transmission pool ID list.
  */
}qcmap_msgr_v2x_capability_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates the modem status to the control point. */
typedef struct {

  /* Mandatory */
  /*  Modem Status */
  qcmap_msgr_ssr_service_status_enum_v01 service_status;
  /**<   Indicates the status of the modem. Values: \n
      - QCMAP_MSGR_SERVICE_UP (0x00) --  0 -- Service up event
      - QCMAP_MSGR_SERVICE_DOWN (0x01) --  1 -- Service down event
 */
}qcmap_msgr_modem_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sends V2X configuration file to the QCMAP. */
typedef struct {

  /* Mandatory */
  /*  Configuration File Path */
  uint32_t cfg_file_path_len;  /**< Must be set to # of elements in cfg_file_path */
  uint8_t cfg_file_path[QMI_QCMAP_MSGR_V2X_CONFIG_FILE_NAME_LEN_MAX_V01];
  /**<   Configuration file path. */
}qcmap_msgr_v2x_send_config_file_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sends V2X configuration file to the QCMAP. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_v2x_send_config_file_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates the result of sending the V2X configuration file. */
typedef struct {

  /* Mandatory */
  /*  Result */
  qcmap_msgr_v2x_config_file_send_result_enum_v01 result;
  /**<   Result of the V2X configuration file send operation. Values: \n
      - QCMAP_MSGR_V2X_CONFIG_FILE_SUCCESS (0) --  Success. \n
      - QCMAP_MSGR_V2X_CONFIG_FILE_FAILURE_INTERNAL (1) --  Internal failure. \n
      - QCMAP_MSGR_V2X_CONFIG_FILE_FAILURE_TIMEOUT (2) --  Timeout failure. \n
      - QCMAP_MSGR_V2X_CONFIG_FILE_FAILURE_OUT_OF_ORDER (3) --  Out of order failure. \n
      - QCMAP_MSGR_V2X_CONFIG_FILE_FAILURE_DECODED_ERR (4) --  Decoded error failure. \n
      - QCMAP_MSGR_V2X_CONFIG_FILE_FAILURE_INVALID_STATE (5) --  Invalid state failure.
 */
}qcmap_msgr_v2x_send_config_file_result_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Sends V2X Tunnel mode information. */
typedef struct {

  /* Optional */
  /*  Malicious Remote UE Source L2 ID List */
  uint8_t malicious_src_l2_id_list_valid;  /**< Must be set to true if malicious_src_l2_id_list is being passed */
  uint32_t malicious_src_l2_id_list_len;  /**< Must be set to # of elements in malicious_src_l2_id_list */
  uint32_t malicious_src_l2_id_list[QMI_QCMAP_MSGR_V2X_INFO_LIST_MAX_V01];
  /**<   List of malicious remote UE source L2 IDs.
  */

  /* Optional */
  /*  Trusted Remote UE Source L2 Information List Ex */
  uint8_t trusted_l2_info_ex_valid;  /**< Must be set to true if trusted_l2_info_ex is being passed */
  uint32_t trusted_l2_info_ex_len;  /**< Must be set to # of elements in trusted_l2_info_ex */
  qcmap_msgr_v2x_trusted_ue_info_ex_type_v01 trusted_l2_info_ex[QMI_QCMAP_MSGR_V2X_INFO_LIST_MAX_V01];
  /**<
  */
}qcmap_msgr_v2x_tunnel_mode_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Sends V2X Tunnel mode information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_v2x_tunnel_mode_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Request Message; Requests to update the source L2 information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}qcmap_msgr_v2x_update_src_l2_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Response Message; Requests to update the source L2 information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}qcmap_msgr_v2x_update_src_l2_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates the V2X source L2 information. */
typedef struct {

  /* Mandatory */
  /*  Source L2 ID */
  uint32_t src_l2_id;
  /**<   Source L2 ID
  */
}qcmap_msgr_v2x_src_l2_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qcmap_msgr_qmi_messages
    @{
  */
/** Indication Message; Indicates the V2X SPS scheduling information from the QCMAP. */
typedef struct {

  /* Mandatory */
  /*  V2X SPS Scheduling Information */
  qcmap_msgr_v2x_sps_scheduling_info_type_v01 info;
  /**<     */
}qcmap_msgr_v2x_sps_scheduling_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/* Conditional compilation tags for message removal */
//#define REMOVE_QMI_QCMAP_MSGR_ACTIVATE_HOSTAPD_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_ACTIVATE_LAN_V01
//#define REMOVE_QMI_QCMAP_MSGR_ACTIVATE_SUPPLICANT_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_ACTIVATE_WLAN_V01
//#define REMOVE_QMI_QCMAP_MSGR_ADD_DHCP_RESERVATION_RECORD_V01
//#define REMOVE_QMI_QCMAP_MSGR_ADD_DLNA_WHITELISTIP_V01
//#define REMOVE_QMI_QCMAP_MSGR_ADD_FIREWALL_ENTRY_V01
//#define REMOVE_QMI_QCMAP_MSGR_ADD_PDN_TO_VLAN_MAPPING_V01
//#define REMOVE_QMI_QCMAP_MSGR_ADD_STATIC_NAT_ENTRY_V01
//#define REMOVE_QMI_QCMAP_MSGR_BACKHAUL_STATUS_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_BRING_DOWN_BT_TETHERING_V01
//#define REMOVE_QMI_QCMAP_MSGR_BRING_UP_BT_TETHERING_V01
//#define REMOVE_QMI_QCMAP_MSGR_BRING_UP_WWAN_V01
//#define REMOVE_QMI_QCMAP_MSGR_BRING_UP_WWAN_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_BT_TETHERING_STATUS_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_BT_TETHERING_WAN_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_CRADLE_MODE_STATUS_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_CREATE_VLAN_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_CREATE_WWAN_POLICY_V01
//#define REMOVE_QMI_QCMAP_MSGR_DELETE_DHCP_RESERVATION_RECORD_V01
//#define REMOVE_QMI_QCMAP_MSGR_DELETE_DLNA_WHITELIST_IP_V01
//#define REMOVE_QMI_QCMAP_MSGR_DELETE_DMZ_V01
//#define REMOVE_QMI_QCMAP_MSGR_DELETE_FIREWALL_ENTRY_V01
//#define REMOVE_QMI_QCMAP_MSGR_DELETE_GSB_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_DELETE_L2TP_TUNNEL_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_DELETE_PDN_TO_VLAN_MAPPING_V01
//#define REMOVE_QMI_QCMAP_MSGR_DELETE_STATIC_NAT_ENTRY_V01
//#define REMOVE_QMI_QCMAP_MSGR_DELETE_VLAN_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_DELETE_VLAN_CONFIG_EX_V01
//#define REMOVE_QMI_QCMAP_MSGR_DELETE_WWAN_POLICY_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_ALG_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_DLNA_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_DYNAMIC_DNS_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_GSB_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_IPV4_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_IPV6_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_MULTICAST_DNS_RESPONDER_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_PACKET_STATS_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_SOCKSV5_PROXY_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_STA_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_TINY_PROXY_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_UPNP_V01
//#define REMOVE_QMI_QCMAP_MSGR_DISABLE_WLAN_V01
//#define REMOVE_QMI_QCMAP_MSGR_EDIT_DHCP_RESERVATION_RECORD_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_ALG_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_DLNA_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_DYNAMIC_DNS_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_GSB_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_IPV4_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_IPV6_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_MULTICAST_DNS_RESPONDER_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_PACKET_STATS_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_SOCKSV5_PROXY_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_STA_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_TINY_PROXY_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_UPNP_V01
//#define REMOVE_QMI_QCMAP_MSGR_ENABLE_WLAN_V01
//#define REMOVE_QMI_QCMAP_MSGR_ETHERNET_MODE_STATUS_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_ACTIVE_WLAN_IF_INFO_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_ALL_CONNECTED_PDN_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_AUTO_CONNECT_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_AlWAYS_ON_WLAN_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_BACKHAUL_PREF_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_BACKHAUL_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_BEARER_TECH_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_BT_TETHERING_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_CONNECTED_DEVICES_INFO_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_CRADLE_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_DATA_BITRATE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_DATA_PATH_OPT_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_DEVICE_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_DHCP_RESERVATION_RECORDS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_DLNA_MEDIA_DIR_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_DLNA_NOTIFY_INTERVAL_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_DLNA_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_DLNA_WHITELISTING_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_DMZ_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_DUN_DONGLE_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_DYNAMIC_DNS_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_EARLY_ETHERNET_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_EARLY_ETHERNET_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_ETHERNET_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_FIREWALL_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_FIREWALL_ENTRIES_HANDLE_LIST_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_FIREWALL_ENTRY_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_GATEWAY_URL_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_GSB_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_INITIAL_PACKET_THRESHOLD_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_IPSEC_VPN_PASS_THROUGH_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_IPV4_STATE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_IPV6_NAT_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_IPV6_SIP_SERVER_INFO_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_IPV6_STATE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_IP_ASSIGNMENT_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_IP_PASSTHROUGH_FLAG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_IP_PASSTHROUGH_STATE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_L2TP_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_L2TP_HW_OFFLOAD_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_L2TP_VPN_PASS_THROUGH_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_LAN_BRIDGES_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_LAN_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_MULTICAST_DNS_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_N79_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_NAT_TIMEOUT_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_NAT_TYPE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_P2P_ROLE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_PDN_TO_VLAN_MAPPINGS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_PMIP_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_PPTP_VPN_PASS_THROUGH_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_PREFIX_DELEGATION_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_PREFIX_DELEGATION_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_QCMAP_BOOTUP_CFG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_ROAMING_PREF_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_SIP_SERVER_INFO_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_SOCKSV5_PROXY_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_STATIC_NAT_ENTRIES_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_STATION_MODE_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_SW_IP_CH_CFG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_TINY_PROXY_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_UPNP_NOTIFY_INTERVAL_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_UPNP_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_VLAN_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_WEBSERVER_WWAN_ACCESS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_WLAN_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_WLAN_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_WWAN_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_WWAN_IFACE_NAME_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_WWAN_POLICY_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_WWAN_PROFILE_PREFERENCE_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_WWAN_ROAMING_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_GET_WWAN_STATS_V01
//#define REMOVE_QMI_QCMAP_MSGR_INDICATION_REGISTER_V01
//#define REMOVE_QMI_QCMAP_MSGR_MOBILE_AP_DISABLE_V01
//#define REMOVE_QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_V01
//#define REMOVE_QMI_QCMAP_MSGR_MOBILE_AP_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_MOBILE_AP_STATUS_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_MODEM_STATUS_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_PACKET_STATS_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_PACKET_STATS_STATUS_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_RESET_PACKET_STATS_V01
//#define REMOVE_QMI_QCMAP_MSGR_RESET_WWAN_STATS_V01
//#define REMOVE_QMI_QCMAP_MSGR_RESTORE_FACTORY_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SELECT_LAN_BRIDGE_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_AUTO_CONNECT_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_AlWAYS_ON_WLAN_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_BACKHAUL_PREF_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_CRADLE_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_DATA_PATH_OPT_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_DEVICE_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_DLNA_MEDIA_DIR_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_DLNA_NOTIFY_INTERVAL_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_DLNA_WHITELISTING_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_DMZ_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_DUN_DONGLE_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_DYNAMIC_DNS_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_EARLY_ETHERNET_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_EARLY_ETHERNET_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_ETHERNET_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_FIREWALL_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_GATEWAY_URL_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_GSB_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_INITIAL_PACKET_THRESHOLD_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_IPSEC_VPN_PASS_THROUGH_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_IPV6_NAT_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_IP_PASSTHROUGH_FLAG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_L2TP_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_L2TP_HW_OFFLOAD_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_L2TP_VPN_PASS_THROUGH_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_LAN_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_MTU_FOR_L2TP_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_N79_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_NAT_TIMEOUT_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_NAT_TYPE_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_P2P_ROLE_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_PMIP_MODE_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_PPTP_VPN_PASS_THROUGH_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_PREFIX_DELEGATION_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_QCMAP_BOOTUP_CFG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_ROAMING_PREF_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_SIP_SERVER_INFO_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_SOCKSV5_PROXY_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_SUPPLICANT_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_SW_IP_CH_CFG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_TCP_MSS_FOR_L2TP_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_UNMANAGED_L2TP_STATE_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_UPNP_NOTIFY_INTERVAL_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_VLAN_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_WEBSERVER_WWAN_ACCESS_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_WLAN_CONFIG_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_WWAN_POLICY_V01
//#define REMOVE_QMI_QCMAP_MSGR_SET_WWAN_PROFILE_PREFERENCE_V01
//#define REMOVE_QMI_QCMAP_MSGR_STATION_MODE_STATUS_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_TEAR_DOWN_WWAN_V01
//#define REMOVE_QMI_QCMAP_MSGR_TEAR_DOWN_WWAN_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_UPDATE_WWAN_POLICY_V01
//#define REMOVE_QMI_QCMAP_MSGR_USB_LINK_DOWN_V01
//#define REMOVE_QMI_QCMAP_MSGR_USB_LINK_UP_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_CAPABILITY_INFO_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_GET_CAPABILITY_INFO_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_GET_SERVICE_SUBSCRIPTION_INFO_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_NON_SPS_FLOW_DEREG_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_NON_SPS_FLOW_REG_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SEND_CONFIG_FILE_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SEND_CONFIG_FILE_RESULT_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SERVICE_SUBSCRIBE_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SERVICE_SUBSCRIBE_RESULT_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SPS_FLOW_DEREG_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SPS_FLOW_DEREG_RESULT_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SPS_FLOW_GET_INFO_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SPS_FLOW_REG_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SPS_FLOW_REG_RESULT_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SPS_FLOW_UPDATE_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SPS_FLOW_UPDATE_RESULT_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SPS_SCHEDULING_INFO_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_SRC_L2_INFO_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_TUNNEL_MODE_INFO_V01
//#define REMOVE_QMI_QCMAP_MSGR_V2X_UPDATE_SRC_L2_INFO_V01
//#define REMOVE_QMI_QCMAP_MSGR_WLAN_STATUS_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_WWAN_POLICY_LIST_V01
//#define REMOVE_QMI_QCMAP_MSGR_WWAN_ROAMING_STATUS_IND_V01
//#define REMOVE_QMI_QCMAP_MSGR_WWAN_STATUS_V01
//#define REMOVE_QMI_QCMAP_MSGR_WWAN_STATUS_IND_V01

/*Service Message Definition*/
/** @addtogroup qcmap_msgr_qmi_msg_ids
    @{
  */
#define QMI_QCMAP_MSGR_INDICATION_REGISTER_REQ_V01 0x0003
#define QMI_QCMAP_MSGR_INDICATION_REGISTER_RESP_V01 0x0003
#define QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_REQ_V01 0x0020
#define QMI_QCMAP_MSGR_MOBILE_AP_ENABLE_RESP_V01 0x0020
#define QMI_QCMAP_MSGR_MOBILE_AP_DISABLE_REQ_V01 0x0021
#define QMI_QCMAP_MSGR_MOBILE_AP_DISABLE_RESP_V01 0x0021
#define QMI_QCMAP_MSGR_BRING_UP_WWAN_REQ_V01 0x0022
#define QMI_QCMAP_MSGR_BRING_UP_WWAN_RESP_V01 0x0022
#define QMI_QCMAP_MSGR_BRING_UP_WWAN_IND_V01 0x0022
#define QMI_QCMAP_MSGR_TEAR_DOWN_WWAN_REQ_V01 0x0023
#define QMI_QCMAP_MSGR_TEAR_DOWN_WWAN_RESP_V01 0x0023
#define QMI_QCMAP_MSGR_TEAR_DOWN_WWAN_IND_V01 0x0023
#define QMI_QCMAP_MSGR_WWAN_STATUS_IND_V01 0x0024
#define QMI_QCMAP_MSGR_ENABLE_WLAN_REQ_V01 0x0025
#define QMI_QCMAP_MSGR_ENABLE_WLAN_RESP_V01 0x0025
#define QMI_QCMAP_MSGR_DISABLE_WLAN_REQ_V01 0x0026
#define QMI_QCMAP_MSGR_DISABLE_WLAN_RESP_V01 0x0026
#define QMI_QCMAP_MSGR_MOBILE_AP_STATUS_IND_V01 0x0027
#define QMI_QCMAP_MSGR_ADD_STATIC_NAT_ENTRY_REQ_V01 0x0028
#define QMI_QCMAP_MSGR_ADD_STATIC_NAT_ENTRY_RESP_V01 0x0028
#define QMI_QCMAP_MSGR_DELETE_STATIC_NAT_ENTRY_REQ_V01 0x0029
#define QMI_QCMAP_MSGR_DELETE_STATIC_NAT_ENTRY_RESP_V01 0x0029
#define QMI_QCMAP_MSGR_GET_STATIC_NAT_ENTRIES_REQ_V01 0x002A
#define QMI_QCMAP_MSGR_GET_STATIC_NAT_ENTRIES_RESP_V01 0x002A
#define QMI_QCMAP_MSGR_SET_DMZ_REQ_V01 0x002B
#define QMI_QCMAP_MSGR_SET_DMZ_RESP_V01 0x002B
#define QMI_QCMAP_MSGR_DELETE_DMZ_REQ_V01 0x002C
#define QMI_QCMAP_MSGR_DELETE_DMZ_RESP_V01 0x002C
#define QMI_QCMAP_MSGR_GET_DMZ_REQ_V01 0x002D
#define QMI_QCMAP_MSGR_GET_DMZ_RESP_V01 0x002D
#define QMI_QCMAP_MSGR_GET_WWAN_STATS_REQ_V01 0x002E
#define QMI_QCMAP_MSGR_GET_WWAN_STATS_RESP_V01 0x002E
#define QMI_QCMAP_MSGR_RESET_WWAN_STATS_REQ_V01 0x002F
#define QMI_QCMAP_MSGR_RESET_WWAN_STATS_RESP_V01 0x002F
#define QMI_QCMAP_MSGR_GET_IPSEC_VPN_PASS_THROUGH_REQ_V01 0x0030
#define QMI_QCMAP_MSGR_GET_IPSEC_VPN_PASS_THROUGH_RESP_V01 0x0030
#define QMI_QCMAP_MSGR_SET_IPSEC_VPN_PASS_THROUGH_REQ_V01 0x0031
#define QMI_QCMAP_MSGR_SET_IPSEC_VPN_PASS_THROUGH_RESP_V01 0x0031
#define QMI_QCMAP_MSGR_GET_PPTP_VPN_PASS_THROUGH_REQ_V01 0x0032
#define QMI_QCMAP_MSGR_GET_PPTP_VPN_PASS_THROUGH_RESP_V01 0x0032
#define QMI_QCMAP_MSGR_SET_PPTP_VPN_PASS_THROUGH_REQ_V01 0x0033
#define QMI_QCMAP_MSGR_SET_PPTP_VPN_PASS_THROUGH_RESP_V01 0x0033
#define QMI_QCMAP_MSGR_GET_L2TP_VPN_PASS_THROUGH_REQ_V01 0x0034
#define QMI_QCMAP_MSGR_GET_L2TP_VPN_PASS_THROUGH_RESP_V01 0x0034
#define QMI_QCMAP_MSGR_SET_L2TP_VPN_PASS_THROUGH_REQ_V01 0x0035
#define QMI_QCMAP_MSGR_SET_L2TP_VPN_PASS_THROUGH_RESP_V01 0x0035
#define QMI_QCMAP_MSGR_SET_NAT_TYPE_REQ_V01 0x0036
#define QMI_QCMAP_MSGR_SET_NAT_TYPE_RESP_V01 0x0036
#define QMI_QCMAP_MSGR_GET_NAT_TYPE_REQ_V01 0x0037
#define QMI_QCMAP_MSGR_GET_NAT_TYPE_RESP_V01 0x0037
#define QMI_QCMAP_MSGR_SET_AUTO_CONNECT_REQ_V01 0x0038
#define QMI_QCMAP_MSGR_SET_AUTO_CONNECT_RESP_V01 0x0038
#define QMI_QCMAP_MSGR_GET_AUTO_CONNECT_REQ_V01 0x0039
#define QMI_QCMAP_MSGR_GET_AUTO_CONNECT_RESP_V01 0x0039
#define QMI_QCMAP_MSGR_ADD_FIREWALL_ENTRY_REQ_V01 0x003A
#define QMI_QCMAP_MSGR_ADD_FIREWALL_ENTRY_RESP_V01 0x003A
#define QMI_QCMAP_MSGR_GET_FIREWALL_ENTRIES_HANDLE_LIST_REQ_V01 0x003B
#define QMI_QCMAP_MSGR_GET_FIREWALL_ENTRIES_HANDLE_LIST_RESP_V01 0x003B
#define QMI_QCMAP_MSGR_GET_FIREWALL_ENTRY_REQ_V01 0x003C
#define QMI_QCMAP_MSGR_GET_FIREWALL_ENTRY_RESP_V01 0x003C
#define QMI_QCMAP_MSGR_DELETE_FIREWALL_ENTRY_REQ_V01 0x003D
#define QMI_QCMAP_MSGR_DELETE_FIREWALL_ENTRY_RESP_V01 0x003D
#define QMI_QCMAP_MSGR_GET_WWAN_CONFIG_REQ_V01 0x003E
#define QMI_QCMAP_MSGR_GET_WWAN_CONFIG_RESP_V01 0x003E
#define QMI_QCMAP_MSGR_MOBILE_AP_STATUS_REQ_V01 0x003F
#define QMI_QCMAP_MSGR_MOBILE_AP_STATUS_RESP_V01 0x003F
#define QMI_QCMAP_MSGR_WWAN_STATUS_REQ_V01 0x0040
#define QMI_QCMAP_MSGR_WWAN_STATUS_RESP_V01 0x0040
#define QMI_QCMAP_MSGR_SET_NAT_TIMEOUT_REQ_V01 0x0041
#define QMI_QCMAP_MSGR_SET_NAT_TIMEOUT_RESP_V01 0x0041
#define QMI_QCMAP_MSGR_GET_NAT_TIMEOUT_REQ_V01 0x0042
#define QMI_QCMAP_MSGR_GET_NAT_TIMEOUT_RESP_V01 0x0042
#define QMI_QCMAP_MSGR_SET_LAN_CONFIG_REQ_V01 0x0043
#define QMI_QCMAP_MSGR_SET_LAN_CONFIG_RESP_V01 0x0043
#define QMI_QCMAP_MSGR_GET_WLAN_STATUS_REQ_V01 0x0044
#define QMI_QCMAP_MSGR_GET_WLAN_STATUS_RESP_V01 0x0044
#define QMI_QCMAP_MSGR_ACTIVATE_WLAN_REQ_V01 0x0045
#define QMI_QCMAP_MSGR_ACTIVATE_WLAN_RESP_V01 0x0045
#define QMI_QCMAP_MSGR_GET_LAN_CONFIG_REQ_V01 0x0046
#define QMI_QCMAP_MSGR_GET_LAN_CONFIG_RESP_V01 0x0046
#define QMI_QCMAP_MSGR_USB_LINK_UP_REQ_V01 0x0047
#define QMI_QCMAP_MSGR_USB_LINK_UP_RESP_V01 0x0047
#define QMI_QCMAP_MSGR_USB_LINK_DOWN_REQ_V01 0x0048
#define QMI_QCMAP_MSGR_USB_LINK_DOWN_RESP_V01 0x0048
#define QMI_QCMAP_MSGR_ENABLE_IPV6_REQ_V01 0x0049
#define QMI_QCMAP_MSGR_ENABLE_IPV6_RESP_V01 0x0049
#define QMI_QCMAP_MSGR_DISABLE_IPV6_REQ_V01 0x004A
#define QMI_QCMAP_MSGR_DISABLE_IPV6_RESP_V01 0x004A
#define QMI_QCMAP_MSGR_SET_ROAMING_PREF_REQ_V01 0x004B
#define QMI_QCMAP_MSGR_SET_ROAMING_PREF_RESP_V01 0x004B
#define QMI_QCMAP_MSGR_GET_ROAMING_PREF_REQ_V01 0x004C
#define QMI_QCMAP_MSGR_GET_ROAMING_PREF_RESP_V01 0x004C
#define QMI_QCMAP_MSGR_SET_WWAN_POLICY_REQ_V01 0x004D
#define QMI_QCMAP_MSGR_SET_WWAN_POLICY_RESP_V01 0x004D
#define QMI_QCMAP_MSGR_GET_WWAN_POLICY_REQ_V01 0x004E
#define QMI_QCMAP_MSGR_GET_WWAN_POLICY_RESP_V01 0x004E
#define QMI_QCMAP_MSGR_GET_IPV6_STATE_REQ_V01 0x004F
#define QMI_QCMAP_MSGR_GET_IPV6_STATE_RESP_V01 0x004F
#define QMI_QCMAP_MSGR_ENABLE_UPNP_REQ_V01 0x0050
#define QMI_QCMAP_MSGR_ENABLE_UPNP_RESP_V01 0x0050
#define QMI_QCMAP_MSGR_DISABLE_UPNP_REQ_V01 0x0051
#define QMI_QCMAP_MSGR_DISABLE_UPNP_RESP_V01 0x0051
#define QMI_QCMAP_MSGR_ENABLE_DLNA_REQ_V01 0x0052
#define QMI_QCMAP_MSGR_ENABLE_DLNA_RESP_V01 0x0052
#define QMI_QCMAP_MSGR_DISABLE_DLNA_REQ_V01 0x0053
#define QMI_QCMAP_MSGR_DISABLE_DLNA_RESP_V01 0x0053
#define QMI_QCMAP_MSGR_SET_FIREWALL_CONFIG_REQ_V01 0x0054
#define QMI_QCMAP_MSGR_SET_FIREWALL_CONFIG_RESP_V01 0x0054
#define QMI_QCMAP_MSGR_GET_FIREWALL_CONFIG_REQ_V01 0x0055
#define QMI_QCMAP_MSGR_GET_FIREWALL_CONFIG_RESP_V01 0x0055
#define QMI_QCMAP_MSGR_ENABLE_MULTICAST_DNS_RESPONDER_REQ_V01 0x0056
#define QMI_QCMAP_MSGR_ENABLE_MULTICAST_DNS_RESPONDER_RESP_V01 0x0056
#define QMI_QCMAP_MSGR_DISABLE_MULTICAST_DNS_RESPONDER_REQ_V01 0x0057
#define QMI_QCMAP_MSGR_DISABLE_MULTICAST_DNS_RESPONDER_RESP_V01 0x0057
#define QMI_QCMAP_MSGR_GET_UPNP_STATUS_REQ_V01 0x0058
#define QMI_QCMAP_MSGR_GET_UPNP_STATUS_RESP_V01 0x0058
#define QMI_QCMAP_MSGR_GET_DLNA_STATUS_REQ_V01 0x0059
#define QMI_QCMAP_MSGR_GET_DLNA_STATUS_RESP_V01 0x0059
#define QMI_QCMAP_MSGR_GET_MULTICAST_DNS_STATUS_REQ_V01 0x005A
#define QMI_QCMAP_MSGR_GET_MULTICAST_DNS_STATUS_RESP_V01 0x005A
#define QMI_QCMAP_MSGR_STATION_MODE_STATUS_IND_V01 0x005B
#define QMI_QCMAP_MSGR_GET_STATION_MODE_STATUS_REQ_V01 0x005C
#define QMI_QCMAP_MSGR_GET_STATION_MODE_STATUS_RESP_V01 0x005C
#define QMI_QCMAP_MSGR_SET_QCMAP_BOOTUP_CFG_REQ_V01 0x005D
#define QMI_QCMAP_MSGR_SET_QCMAP_BOOTUP_CFG_RESP_V01 0x005D
#define QMI_QCMAP_MSGR_GET_QCMAP_BOOTUP_CFG_REQ_V01 0x005E
#define QMI_QCMAP_MSGR_GET_QCMAP_BOOTUP_CFG_RESP_V01 0x005E
#define QMI_QCMAP_MSGR_SET_DLNA_MEDIA_DIR_REQ_V01 0x005F
#define QMI_QCMAP_MSGR_SET_DLNA_MEDIA_DIR_RESP_V01 0x005F
#define QMI_QCMAP_MSGR_GET_DLNA_MEDIA_DIR_REQ_V01 0x0060
#define QMI_QCMAP_MSGR_GET_DLNA_MEDIA_DIR_RESP_V01 0x0060
#define QMI_QCMAP_MSGR_SET_WLAN_CONFIG_REQ_V01 0x0061
#define QMI_QCMAP_MSGR_SET_WLAN_CONFIG_RESP_V01 0x0061
#define QMI_QCMAP_MSGR_ACTIVATE_LAN_REQ_V01 0x0062
#define QMI_QCMAP_MSGR_ACTIVATE_LAN_RESP_V01 0x0062
#define QMI_QCMAP_MSGR_GET_WLAN_CONFIG_REQ_V01 0x0063
#define QMI_QCMAP_MSGR_GET_WLAN_CONFIG_RESP_V01 0x0063
#define QMI_QCMAP_MSGR_ENABLE_IPV4_REQ_V01 0x0064
#define QMI_QCMAP_MSGR_ENABLE_IPV4_RESP_V01 0x0064
#define QMI_QCMAP_MSGR_DISABLE_IPV4_REQ_V01 0x0065
#define QMI_QCMAP_MSGR_DISABLE_IPV4_RESP_V01 0x0065
#define QMI_QCMAP_MSGR_GET_IPV4_STATE_REQ_V01 0x0066
#define QMI_QCMAP_MSGR_GET_IPV4_STATE_RESP_V01 0x0066
#define QMI_QCMAP_MSGR_GET_DATA_BITRATE_REQ_V01 0x0067
#define QMI_QCMAP_MSGR_GET_DATA_BITRATE_RESP_V01 0x0067
#define QMI_QCMAP_MSGR_GET_UPNP_NOTIFY_INTERVAL_REQ_V01 0x0068
#define QMI_QCMAP_MSGR_GET_UPNP_NOTIFY_INTERVAL_RESP_V01 0x0068
#define QMI_QCMAP_MSGR_SET_UPNP_NOTIFY_INTERVAL_REQ_V01 0x0069
#define QMI_QCMAP_MSGR_SET_UPNP_NOTIFY_INTERVAL_RESP_V01 0x0069
#define QMI_QCMAP_MSGR_GET_DLNA_NOTIFY_INTERVAL_REQ_V01 0x006A
#define QMI_QCMAP_MSGR_GET_DLNA_NOTIFY_INTERVAL_RESP_V01 0x006A
#define QMI_QCMAP_MSGR_SET_DLNA_NOTIFY_INTERVAL_REQ_V01 0x006B
#define QMI_QCMAP_MSGR_SET_DLNA_NOTIFY_INTERVAL_RESP_V01 0x006B
#define QMI_QCMAP_MSGR_ADD_DHCP_RESERVATION_RECORD_REQ_V01 0x006C
#define QMI_QCMAP_MSGR_ADD_DHCP_RESERVATION_RECORD_RESP_V01 0x006C
#define QMI_QCMAP_MSGR_GET_DHCP_RESERVATION_RECORDS_REQ_V01 0x006D
#define QMI_QCMAP_MSGR_GET_DHCP_RESERVATION_RECORDS_RESP_V01 0x006D
#define QMI_QCMAP_MSGR_EDIT_DHCP_RESERVATION_RECORD_REQ_V01 0x006E
#define QMI_QCMAP_MSGR_EDIT_DHCP_RESERVATION_RECORD_RESP_V01 0x006E
#define QMI_QCMAP_MSGR_DELETE_DHCP_RESERVATION_RECORD_REQ_V01 0x006F
#define QMI_QCMAP_MSGR_DELETE_DHCP_RESERVATION_RECORD_RESP_V01 0x006F
#define QMI_QCMAP_MSGR_ACTIVATE_HOSTAPD_CONFIG_REQ_V01 0x0070
#define QMI_QCMAP_MSGR_ACTIVATE_HOSTAPD_CONFIG_RESP_V01 0x0070
#define QMI_QCMAP_MSGR_ACTIVATE_SUPPLICANT_CONFIG_REQ_V01 0x0071
#define QMI_QCMAP_MSGR_ACTIVATE_SUPPLICANT_CONFIG_RESP_V01 0x0071
#define QMI_QCMAP_MSGR_ENABLE_ALG_REQ_V01 0x0072
#define QMI_QCMAP_MSGR_ENABLE_ALG_RESP_V01 0x0072
#define QMI_QCMAP_MSGR_DISABLE_ALG_REQ_V01 0x0073
#define QMI_QCMAP_MSGR_DISABLE_ALG_RESP_V01 0x0073
#define QMI_QCMAP_MSGR_GET_WEBSERVER_WWAN_ACCESS_REQ_V01 0x0074
#define QMI_QCMAP_MSGR_GET_WEBSERVER_WWAN_ACCESS_RESP_V01 0x0074
#define QMI_QCMAP_MSGR_SET_WEBSERVER_WWAN_ACCESS_REQ_V01 0x0075
#define QMI_QCMAP_MSGR_SET_WEBSERVER_WWAN_ACCESS_RESP_V01 0x0075
#define QMI_QCMAP_MSGR_SET_SIP_SERVER_INFO_REQ_V01 0x0076
#define QMI_QCMAP_MSGR_SET_SIP_SERVER_INFO_RESP_V01 0x0076
#define QMI_QCMAP_MSGR_GET_SIP_SERVER_INFO_REQ_V01 0x0077
#define QMI_QCMAP_MSGR_GET_SIP_SERVER_INFO_RESP_V01 0x0077
#define QMI_QCMAP_MSGR_RESTORE_FACTORY_CONFIG_REQ_V01 0x0078
#define QMI_QCMAP_MSGR_RESTORE_FACTORY_CONFIG_RESP_V01 0x0078
#define QMI_QCMAP_MSGR_GET_CONNECTED_DEVICES_INFO_REQ_V01 0x0079
#define QMI_QCMAP_MSGR_GET_CONNECTED_DEVICES_INFO_RESP_V01 0x0079
#define QMI_QCMAP_MSGR_GET_IPV6_SIP_SERVER_INFO_REQ_V01 0x007A
#define QMI_QCMAP_MSGR_GET_IPV6_SIP_SERVER_INFO_RESP_V01 0x007A
#define QMI_QCMAP_MSGR_SET_SUPPLICANT_CONFIG_REQ_V01 0x007B
#define QMI_QCMAP_MSGR_SET_SUPPLICANT_CONFIG_RESP_V01 0x007B
#define QMI_QCMAP_MSGR_GET_CRADLE_MODE_REQ_V01 0x007C
#define QMI_QCMAP_MSGR_GET_CRADLE_MODE_RESP_V01 0x007C
#define QMI_QCMAP_MSGR_SET_CRADLE_MODE_REQ_V01 0x007D
#define QMI_QCMAP_MSGR_SET_CRADLE_MODE_RESP_V01 0x007D
#define QMI_QCMAP_MSGR_CRADLE_MODE_STATUS_IND_V01 0x007E
#define QMI_QCMAP_MSGR_GET_PREFIX_DELEGATION_CONFIG_REQ_V01 0x007F
#define QMI_QCMAP_MSGR_GET_PREFIX_DELEGATION_CONFIG_RESP_V01 0x007F
#define QMI_QCMAP_MSGR_SET_PREFIX_DELEGATION_CONFIG_REQ_V01 0x0080
#define QMI_QCMAP_MSGR_SET_PREFIX_DELEGATION_CONFIG_RESP_V01 0x0080
#define QMI_QCMAP_MSGR_GET_PREFIX_DELEGATION_STATUS_REQ_V01 0x0081
#define QMI_QCMAP_MSGR_GET_PREFIX_DELEGATION_STATUS_RESP_V01 0x0081
#define QMI_QCMAP_MSGR_SET_GATEWAY_URL_REQ_V01 0x0082
#define QMI_QCMAP_MSGR_SET_GATEWAY_URL_RESP_V01 0x0082
#define QMI_QCMAP_MSGR_GET_GATEWAY_URL_REQ_V01 0x0083
#define QMI_QCMAP_MSGR_GET_GATEWAY_URL_RESP_V01 0x0083
#define QMI_QCMAP_MSGR_ENABLE_DYNAMIC_DNS_REQ_V01 0x0084
#define QMI_QCMAP_MSGR_ENABLE_DYNAMIC_DNS_RESP_V01 0x0084
#define QMI_QCMAP_MSGR_DISABLE_DYNAMIC_DNS_REQ_V01 0x0085
#define QMI_QCMAP_MSGR_DISABLE_DYNAMIC_DNS_RESP_V01 0x0085
#define QMI_QCMAP_MSGR_SET_DYNAMIC_DNS_CONFIG_REQ_V01 0x0086
#define QMI_QCMAP_MSGR_SET_DYNAMIC_DNS_CONFIG_RESP_V01 0x0086
#define QMI_QCMAP_MSGR_GET_DYNAMIC_DNS_CONFIG_REQ_V01 0x0087
#define QMI_QCMAP_MSGR_GET_DYNAMIC_DNS_CONFIG_RESP_V01 0x0087
#define QMI_QCMAP_MSGR_GET_TINY_PROXY_STATUS_REQ_V01 0x0088
#define QMI_QCMAP_MSGR_GET_TINY_PROXY_STATUS_RESP_V01 0x0088
#define QMI_QCMAP_MSGR_ENABLE_TINY_PROXY_REQ_V01 0x0089
#define QMI_QCMAP_MSGR_ENABLE_TINY_PROXY_RESP_V01 0x0089
#define QMI_QCMAP_MSGR_DISABLE_TINY_PROXY_REQ_V01 0x008A
#define QMI_QCMAP_MSGR_DISABLE_TINY_PROXY_RESP_V01 0x008A
#define QMI_QCMAP_MSGR_SET_DLNA_WHITELISTING_REQ_V01 0x008B
#define QMI_QCMAP_MSGR_SET_DLNA_WHITELISTING_RESP_V01 0x008B
#define QMI_QCMAP_MSGR_GET_DLNA_WHITELISTING_REQ_V01 0x008C
#define QMI_QCMAP_MSGR_GET_DLNA_WHITELISTING_RESP_V01 0x008C
#define QMI_QCMAP_MSGR_ADD_DLNA_WHITELISTIP_REQ_V01 0x008D
#define QMI_QCMAP_MSGR_ADD_DLNA_WHITELISTIP_RESP_V01 0x008D
#define QMI_QCMAP_MSGR_DELETE_DLNA_WHITELIST_IP_REQ_V01 0x008E
#define QMI_QCMAP_MSGR_DELETE_DLNA_WHITELIST_IP_RESP_V01 0x008E
#define QMI_QCMAP_MSGR_ENABLE_STA_MODE_REQ_V01 0x008F
#define QMI_QCMAP_MSGR_ENABLE_STA_MODE_RESP_V01 0x008F
#define QMI_QCMAP_MSGR_WLAN_STATUS_IND_V01 0x0090
#define QMI_QCMAP_MSGR_SET_BACKHAUL_PREF_REQ_V01 0x0091
#define QMI_QCMAP_MSGR_SET_BACKHAUL_PREF_RESP_V01 0x0091
#define QMI_QCMAP_MSGR_GET_BACKHAUL_PREF_REQ_V01 0x0092
#define QMI_QCMAP_MSGR_GET_BACKHAUL_PREF_RESP_V01 0x0092
#define QMI_QCMAP_MSGR_DISABLE_STA_MODE_REQ_V01 0x0093
#define QMI_QCMAP_MSGR_DISABLE_STA_MODE_RESP_V01 0x0093
#define QMI_QCMAP_MSGR_GET_ETHERNET_MODE_REQ_V01 0x0094
#define QMI_QCMAP_MSGR_GET_ETHERNET_MODE_RESP_V01 0x0094
#define QMI_QCMAP_MSGR_SET_ETHERNET_MODE_REQ_V01 0x0095
#define QMI_QCMAP_MSGR_SET_ETHERNET_MODE_RESP_V01 0x0095
#define QMI_QCMAP_MSGR_ETHERNET_MODE_STATUS_IND_V01 0x0096
#define QMI_QCMAP_MSGR_SET_IP_PASSTHROUGH_FLAG_REQ_V01 0x0097
#define QMI_QCMAP_MSGR_SET_IP_PASSTHROUGH_FLAG_RESP_V01 0x0097
#define QMI_QCMAP_MSGR_GET_IP_PASSTHROUGH_FLAG_REQ_V01 0x0098
#define QMI_QCMAP_MSGR_GET_IP_PASSTHROUGH_FLAG_RESP_V01 0x0098
#define QMI_QCMAP_MSGR_GET_IP_PASSTHROUGH_STATE_REQ_V01 0x0099
#define QMI_QCMAP_MSGR_GET_IP_PASSTHROUGH_STATE_RESP_V01 0x0099
#define QMI_QCMAP_MSGR_BRING_UP_BT_TETHERING_REQ_V01 0x009A
#define QMI_QCMAP_MSGR_BRING_UP_BT_TETHERING_RESP_V01 0x009A
#define QMI_QCMAP_MSGR_BRING_DOWN_BT_TETHERING_REQ_V01 0x009B
#define QMI_QCMAP_MSGR_BRING_DOWN_BT_TETHERING_RESP_V01 0x009B
#define QMI_QCMAP_MSGR_GET_BT_TETHERING_STATUS_REQ_V01 0x009C
#define QMI_QCMAP_MSGR_GET_BT_TETHERING_STATUS_RESP_V01 0x009C
#define QMI_QCMAP_MSGR_BT_TETHERING_STATUS_IND_V01 0x009D
#define QMI_QCMAP_MSGR_BT_TETHERING_WAN_IND_V01 0x009E
#define QMI_QCMAP_MSGR_SET_INITIAL_PACKET_THRESHOLD_REQ_V01 0x009F
#define QMI_QCMAP_MSGR_SET_INITIAL_PACKET_THRESHOLD_RESP_V01 0x009F
#define QMI_QCMAP_MSGR_GET_INITIAL_PACKET_THRESHOLD_REQ_V01 0x00A0
#define QMI_QCMAP_MSGR_GET_INITIAL_PACKET_THRESHOLD_RESP_V01 0x00A0
#define QMI_QCMAP_MSGR_ENABLE_SOCKSV5_PROXY_REQ_V01 0x00A1
#define QMI_QCMAP_MSGR_ENABLE_SOCKSV5_PROXY_RESP_V01 0x00A1
#define QMI_QCMAP_MSGR_DISABLE_SOCKSV5_PROXY_REQ_V01 0x00A2
#define QMI_QCMAP_MSGR_DISABLE_SOCKSV5_PROXY_RESP_V01 0x00A2
#define QMI_QCMAP_MSGR_GET_SOCKSV5_PROXY_CONFIG_REQ_V01 0x00A3
#define QMI_QCMAP_MSGR_GET_SOCKSV5_PROXY_CONFIG_RESP_V01 0x00A3
#define QMI_QCMAP_MSGR_SET_SOCKSV5_PROXY_CONFIG_REQ_V01 0x00A4
#define QMI_QCMAP_MSGR_SET_SOCKSV5_PROXY_CONFIG_RESP_V01 0x00A4
#define QMI_QCMAP_MSGR_ENABLE_PACKET_STATS_REQ_V01 0x00A5
#define QMI_QCMAP_MSGR_ENABLE_PACKET_STATS_RESP_V01 0x00A5
#define QMI_QCMAP_MSGR_DISABLE_PACKET_STATS_REQ_V01 0x00A6
#define QMI_QCMAP_MSGR_DISABLE_PACKET_STATS_RESP_V01 0x00A6
#define QMI_QCMAP_MSGR_RESET_PACKET_STATS_REQ_V01 0x00A7
#define QMI_QCMAP_MSGR_RESET_PACKET_STATS_RESP_V01 0x00A7
#define QMI_QCMAP_MSGR_PACKET_STATS_STATUS_REQ_V01 0x00A8
#define QMI_QCMAP_MSGR_PACKET_STATS_STATUS_RESP_V01 0x00A8
#define QMI_QCMAP_MSGR_PACKET_STATS_STATUS_IND_V01 0x00A9
#define QMI_QCMAP_MSGR_DELETE_WWAN_POLICY_REQ_V01 0x00AA
#define QMI_QCMAP_MSGR_DELETE_WWAN_POLICY_RESP_V01 0x00AA
#define QMI_QCMAP_MSGR_WWAN_POLICY_LIST_REQ_V01 0x00AB
#define QMI_QCMAP_MSGR_WWAN_POLICY_LIST_RESP_V01 0x00AB
#define QMI_QCMAP_MSGR_SET_VLAN_CONFIG_REQ_V01 0x00AC
#define QMI_QCMAP_MSGR_SET_VLAN_CONFIG_RESP_V01 0x00AC
#define QMI_QCMAP_MSGR_GET_VLAN_CONFIG_REQ_V01 0x00AD
#define QMI_QCMAP_MSGR_GET_VLAN_CONFIG_RESP_V01 0x00AD
#define QMI_QCMAP_MSGR_DELETE_VLAN_CONFIG_REQ_V01 0x00AE
#define QMI_QCMAP_MSGR_DELETE_VLAN_CONFIG_RESP_V01 0x00AE
#define QMI_QCMAP_MSGR_SET_UNMANAGED_L2TP_STATE_REQ_V01 0x00AF
#define QMI_QCMAP_MSGR_SET_UNMANAGED_L2TP_STATE_RESP_V01 0x00AF
#define QMI_QCMAP_MSGR_SET_L2TP_CONFIG_REQ_V01 0x00B0
#define QMI_QCMAP_MSGR_SET_L2TP_CONFIG_RESP_V01 0x00B0
#define QMI_QCMAP_MSGR_SET_MTU_FOR_L2TP_CONFIG_REQ_V01 0x00B1
#define QMI_QCMAP_MSGR_SET_MTU_FOR_L2TP_CONFIG_RESP_V01 0x00B1
#define QMI_QCMAP_MSGR_SET_TCP_MSS_FOR_L2TP_CONFIG_REQ_V01 0x00B2
#define QMI_QCMAP_MSGR_SET_TCP_MSS_FOR_L2TP_CONFIG_RESP_V01 0x00B2
#define QMI_QCMAP_MSGR_GET_L2TP_CONFIG_REQ_V01 0x00B3
#define QMI_QCMAP_MSGR_GET_L2TP_CONFIG_RESP_V01 0x00B3
#define QMI_QCMAP_MSGR_DELETE_L2TP_TUNNEL_CONFIG_REQ_V01 0x00B4
#define QMI_QCMAP_MSGR_DELETE_L2TP_TUNNEL_CONFIG_RESP_V01 0x00B4
#define QMI_QCMAP_MSGR_ADD_PDN_TO_VLAN_MAPPING_REQ_V01 0x00B5
#define QMI_QCMAP_MSGR_ADD_PDN_TO_VLAN_MAPPING_RESP_V01 0x00B5
#define QMI_QCMAP_MSGR_GET_PDN_TO_VLAN_MAPPINGS_REQ_V01 0x00B6
#define QMI_QCMAP_MSGR_GET_PDN_TO_VLAN_MAPPINGS_RESP_V01 0x00B6
#define QMI_QCMAP_MSGR_CREATE_WWAN_POLICY_REQ_V01 0x00B7
#define QMI_QCMAP_MSGR_CREATE_WWAN_POLICY_RESP_V01 0x00B7
#define QMI_QCMAP_MSGR_UPDATE_WWAN_POLICY_REQ_V01 0x00B8
#define QMI_QCMAP_MSGR_UPDATE_WWAN_POLICY_RESP_V01 0x00B8
#define QMI_QCMAP_MSGR_SET_WWAN_PROFILE_PREFERENCE_REQ_V01 0x00B9
#define QMI_QCMAP_MSGR_SET_WWAN_PROFILE_PREFERENCE_RESP_V01 0x00B9
#define QMI_QCMAP_MSGR_ENABLE_GSB_REQ_V01 0x00BA
#define QMI_QCMAP_MSGR_ENABLE_GSB_RESP_V01 0x00BA
#define QMI_QCMAP_MSGR_DISABLE_GSB_REQ_V01 0x00BB
#define QMI_QCMAP_MSGR_DISABLE_GSB_RESP_V01 0x00BB
#define QMI_QCMAP_MSGR_GET_GSB_CONFIG_REQ_V01 0x00BC
#define QMI_QCMAP_MSGR_GET_GSB_CONFIG_RESP_V01 0x00BC
#define QMI_QCMAP_MSGR_SET_GSB_CONFIG_REQ_V01 0x00BD
#define QMI_QCMAP_MSGR_SET_GSB_CONFIG_RESP_V01 0x00BD
#define QMI_QCMAP_MSGR_DELETE_GSB_CONFIG_REQ_V01 0x00BE
#define QMI_QCMAP_MSGR_DELETE_GSB_CONFIG_RESP_V01 0x00BE
#define QMI_QCMAP_MSGR_SET_DUN_DONGLE_MODE_REQ_V01 0x00BF
#define QMI_QCMAP_MSGR_SET_DUN_DONGLE_MODE_RESP_V01 0x00BF
#define QMI_QCMAP_MSGR_GET_DUN_DONGLE_MODE_REQ_V01 0x00C0
#define QMI_QCMAP_MSGR_GET_DUN_DONGLE_MODE_RESP_V01 0x00C0
#define QMI_QCMAP_MSGR_GET_DATA_PATH_OPT_STATUS_REQ_V01 0x00C1
#define QMI_QCMAP_MSGR_GET_DATA_PATH_OPT_STATUS_RESP_V01 0x00C1
#define QMI_QCMAP_MSGR_SET_DATA_PATH_OPT_STATUS_REQ_V01 0x00C2
#define QMI_QCMAP_MSGR_SET_DATA_PATH_OPT_STATUS_RESP_V01 0x00C2
#define QMI_QCMAP_MSGR_GET_PMIP_MODE_REQ_V01 0x00C3
#define QMI_QCMAP_MSGR_GET_PMIP_MODE_RESP_V01 0x00C3
#define QMI_QCMAP_MSGR_SET_PMIP_MODE_REQ_V01 0x00C4
#define QMI_QCMAP_MSGR_SET_PMIP_MODE_RESP_V01 0x00C4
#define QMI_QCMAP_MSGR_GET_BACKHAUL_STATUS_REQ_V01 0x00C5
#define QMI_QCMAP_MSGR_GET_BACKHAUL_STATUS_RESP_V01 0x00C5
#define QMI_QCMAP_MSGR_BACKHAUL_STATUS_IND_V01 0x00C6
#define QMI_QCMAP_MSGR_GET_WWAN_ROAMING_STATUS_REQ_V01 0x00C7
#define QMI_QCMAP_MSGR_GET_WWAN_ROAMING_STATUS_RESP_V01 0x00C7
#define QMI_QCMAP_MSGR_WWAN_ROAMING_STATUS_IND_V01 0x00C8
#define QMI_QCMAP_MSGR_DELETE_PDN_TO_VLAN_MAPPING_REQ_V01 0x00C9
#define QMI_QCMAP_MSGR_DELETE_PDN_TO_VLAN_MAPPING_RESP_V01 0x00C9
#define QMI_QCMAP_MSGR_GET_LAN_BRIDGES_REQ_V01 0x00CA
#define QMI_QCMAP_MSGR_GET_LAN_BRIDGES_RESP_V01 0x00CA
#define QMI_QCMAP_MSGR_SELECT_LAN_BRIDGE_REQ_V01 0x00CB
#define QMI_QCMAP_MSGR_SELECT_LAN_BRIDGE_RESP_V01 0x00CB
#define QMI_QCMAP_MSGR_GET_ACTIVE_WLAN_IF_INFO_REQ_V01 0x00CC
#define QMI_QCMAP_MSGR_GET_ACTIVE_WLAN_IF_INFO_RESP_V01 0x00CC
#define QMI_QCMAP_MSGR_SET_AlWAYS_ON_WLAN_REQ_V01 0x00CD
#define QMI_QCMAP_MSGR_SET_AlWAYS_ON_WLAN_RESP_V01 0x00CD
#define QMI_QCMAP_MSGR_GET_AlWAYS_ON_WLAN_REQ_V01 0x00CE
#define QMI_QCMAP_MSGR_GET_AlWAYS_ON_WLAN_RESP_V01 0x00CE
#define QMI_QCMAP_MSGR_GET_WWAN_PROFILE_PREFERENCE_REQ_V01 0x00CF
#define QMI_QCMAP_MSGR_GET_WWAN_PROFILE_PREFERENCE_RESP_V01 0x00CF
#define QMI_QCMAP_MSGR_SET_P2P_ROLE_REQ_V01 0x00D0
#define QMI_QCMAP_MSGR_SET_P2P_ROLE_RESP_V01 0x00D0
#define QMI_QCMAP_MSGR_GET_P2P_ROLE_REQ_V01 0x00D1
#define QMI_QCMAP_MSGR_GET_P2P_ROLE_RESP_V01 0x00D1
#define QMI_QCMAP_MSGR_SET_EARLY_ETHERNET_MODE_REQ_V01 0x00D2
#define QMI_QCMAP_MSGR_SET_EARLY_ETHERNET_MODE_RESP_V01 0x00D2
#define QMI_QCMAP_MSGR_GET_EARLY_ETHERNET_MODE_REQ_V01 0x00D3
#define QMI_QCMAP_MSGR_GET_EARLY_ETHERNET_MODE_RESP_V01 0x00D3
#define QMI_QCMAP_MSGR_GET_L2TP_HW_OFFLOAD_MODE_REQ_V01 0x00D4
#define QMI_QCMAP_MSGR_GET_L2TP_HW_OFFLOAD_MODE_RESP_V01 0x00D4
#define QMI_QCMAP_MSGR_SET_L2TP_HW_OFFLOAD_MODE_REQ_V01 0x00D5
#define QMI_QCMAP_MSGR_SET_L2TP_HW_OFFLOAD_MODE_RESP_V01 0x00D5
#define QMI_QCMAP_MSGR_GET_IP_ASSIGNMENT_REQ_V01 0x00D6
#define QMI_QCMAP_MSGR_GET_IP_ASSIGNMENT_RESP_V01 0x00D6
#define QMI_QCMAP_MSGR_GET_WWAN_IFACE_NAME_REQ_V01 0x00D7
#define QMI_QCMAP_MSGR_GET_WWAN_IFACE_NAME_RESP_V01 0x00D7
#define QMI_QCMAP_MSGR_SET_EARLY_ETHERNET_CONFIG_REQ_V01 0x00D8
#define QMI_QCMAP_MSGR_SET_EARLY_ETHERNET_CONFIG_RESP_V01 0x00D8
#define QMI_QCMAP_MSGR_GET_EARLY_ETHERNET_CONFIG_REQ_V01 0x00D9
#define QMI_QCMAP_MSGR_GET_EARLY_ETHERNET_CONFIG_RESP_V01 0x00D9
#define QMI_QCMAP_MSGR_SET_IPV6_NAT_REQ_V01 0x00DA
#define QMI_QCMAP_MSGR_SET_IPV6_NAT_RESP_V01 0x00DA
#define QMI_QCMAP_MSGR_GET_IPV6_NAT_REQ_V01 0x00DB
#define QMI_QCMAP_MSGR_GET_IPV6_NAT_RESP_V01 0x00DB
#define QMI_QCMAP_MSGR_GET_DEVICE_MODE_REQ_V01 0x00DC
#define QMI_QCMAP_MSGR_GET_DEVICE_MODE_RESP_V01 0x00DC
#define QMI_QCMAP_MSGR_SET_DEVICE_MODE_REQ_V01 0x00DD
#define QMI_QCMAP_MSGR_SET_DEVICE_MODE_RESP_V01 0x00DD
#define QMI_QCMAP_MSGR_GET_BEARER_TECH_REQ_V01 0x00DE
#define QMI_QCMAP_MSGR_GET_BEARER_TECH_RESP_V01 0x00DE
#define QMI_QCMAP_MSGR_GET_ALL_CONNECTED_PDN_REQ_V01 0x00DF
#define QMI_QCMAP_MSGR_GET_ALL_CONNECTED_PDN_RESP_V01 0x00DF
#define QMI_QCMAP_MSGR_CREATE_VLAN_CONFIG_REQ_V01 0x00E0
#define QMI_QCMAP_MSGR_CREATE_VLAN_CONFIG_RESP_V01 0x00E0
#define QMI_QCMAP_MSGR_DELETE_VLAN_CONFIG_EX_REQ_V01 0x00E1
#define QMI_QCMAP_MSGR_DELETE_VLAN_CONFIG_EX_RESP_V01 0x00E1
#define QMI_QCMAP_MSGR_V2X_SPS_FLOW_REG_REQ_V01 0x00E2
#define QMI_QCMAP_MSGR_V2X_SPS_FLOW_REG_RESP_V01 0x00E2
#define QMI_QCMAP_MSGR_V2X_SPS_FLOW_REG_RESULT_IND_V01 0x00E2
#define QMI_QCMAP_MSGR_V2X_SPS_FLOW_DEREG_REQ_V01 0x00E3
#define QMI_QCMAP_MSGR_V2X_SPS_FLOW_DEREG_RESP_V01 0x00E3
#define QMI_QCMAP_MSGR_V2X_SPS_FLOW_DEREG_RESULT_IND_V01 0x00E3
#define QMI_QCMAP_MSGR_V2X_SPS_FLOW_UPDATE_REQ_V01 0x00E4
#define QMI_QCMAP_MSGR_V2X_SPS_FLOW_UPDATE_RESP_V01 0x00E4
#define QMI_QCMAP_MSGR_V2X_SPS_FLOW_UPDATE_RESULT_IND_V01 0x00E4
#define QMI_QCMAP_MSGR_V2X_SPS_FLOW_GET_INFO_REQ_V01 0x00E5
#define QMI_QCMAP_MSGR_V2X_SPS_FLOW_GET_INFO_RESP_V01 0x00E5
#define QMI_QCMAP_MSGR_V2X_NON_SPS_FLOW_REG_REQ_V01 0x00E6
#define QMI_QCMAP_MSGR_V2X_NON_SPS_FLOW_REG_RESP_V01 0x00E6
#define QMI_QCMAP_MSGR_V2X_NON_SPS_FLOW_DEREG_REQ_V01 0x00E7
#define QMI_QCMAP_MSGR_V2X_NON_SPS_FLOW_DEREG_RESP_V01 0x00E7
#define QMI_QCMAP_MSGR_V2X_SERVICE_SUBSCRIBE_REQ_V01 0x00E8
#define QMI_QCMAP_MSGR_V2X_SERVICE_SUBSCRIBE_RESP_V01 0x00E8
#define QMI_QCMAP_MSGR_V2X_SERVICE_SUBSCRIBE_RESULT_IND_V01 0x00E8
#define QMI_QCMAP_MSGR_V2X_GET_SERVICE_SUBSCRIPTION_INFO_REQ_V01 0x00E9
#define QMI_QCMAP_MSGR_V2X_GET_SERVICE_SUBSCRIPTION_INFO_RESP_V01 0x00E9
#define QMI_QCMAP_MSGR_V2X_SEND_CONFIG_FILE_REQ_V01 0x00EA
#define QMI_QCMAP_MSGR_V2X_SEND_CONFIG_FILE_RESP_V01 0x00EA
#define QMI_QCMAP_MSGR_V2X_SEND_CONFIG_FILE_RESULT_IND_V01 0x00EA
#define QMI_QCMAP_MSGR_V2X_SPS_SCHEDULING_INFO_IND_V01 0x00EB
#define QMI_QCMAP_MSGR_V2X_UPDATE_SRC_L2_INFO_REQ_V01 0x00EC
#define QMI_QCMAP_MSGR_V2X_UPDATE_SRC_L2_INFO_RESP_V01 0x00EC
#define QMI_QCMAP_MSGR_V2X_SRC_L2_INFO_IND_V01 0x00ED
#define QMI_QCMAP_MSGR_V2X_TUNNEL_MODE_INFO_REQ_V01 0x00EE
#define QMI_QCMAP_MSGR_V2X_TUNNEL_MODE_INFO_RESP_V01 0x00EE
#define QMI_QCMAP_MSGR_V2X_GET_CAPABILITY_INFO_REQ_V01 0x00EF
#define QMI_QCMAP_MSGR_V2X_GET_CAPABILITY_INFO_RESP_V01 0x00EF
#define QMI_QCMAP_MSGR_V2X_CAPABILITY_INFO_IND_V01 0x00F0
#define QMI_QCMAP_MSGR_MODEM_STATUS_IND_V01 0x00F1
#define QMI_QCMAP_MSGR_SET_N79_CONFIG_REQ_V01 0x00F2
#define QMI_QCMAP_MSGR_SET_N79_CONFIG_RESP_V01 0x00F2
#define QMI_QCMAP_MSGR_GET_N79_CONFIG_REQ_V01 0x00F3
#define QMI_QCMAP_MSGR_GET_N79_CONFIG_RESP_V01 0x00F3
#define QMI_QCMAP_MSGR_GET_SW_IP_CH_CFG_REQ_V01 0x00F4
#define QMI_QCMAP_MSGR_GET_SW_IP_CH_CFG_RESP_V01 0x00F4
#define QMI_QCMAP_MSGR_SET_SW_IP_CH_CFG_REQ_V01 0x00F5
#define QMI_QCMAP_MSGR_SET_SW_IP_CH_CFG_RESP_V01 0x00F5
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro qcmap_msgr_get_service_object_v01( ) that takes in no arguments. */
qmi_idl_service_object_type qcmap_msgr_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );

/** This macro should be used to get the service object */
#define qcmap_msgr_get_service_object_v01( ) \
          qcmap_msgr_get_service_object_internal_v01( \
            QCMAP_MSGR_V01_IDL_MAJOR_VERS, QCMAP_MSGR_V01_IDL_MINOR_VERS, \
            QCMAP_MSGR_V01_IDL_TOOL_VERS )
/**
    @}
  */


#ifdef __cplusplus
}
#endif
#endif

