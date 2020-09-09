#ifndef _QCMAP_CLIENT_H_
#define _QCMAP_CLIENT_H_
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                        _ Q C M A P _ C L I E N T . H

*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/**
  @file QCMAP_Client.h
  @brief QCMAP Client public function declarations.
         As a note, the client app should not perform time intensive tasks in
         callback context. It should be minimal handling and majority of
         tasks should be handled in client thread context
 */

/*===========================================================================
NOTE: The @brief description above does not appear in the PDF.
      The description that displays in the PDF is maintained in the
      xxx_mainpage.dox file. Contact Tech Pubs for assistance.
===========================================================================*/

/*===========================================================================

FILE:  QCMAP_Client.h

SERVICES:
   QCMAP Client Class

===========================================================================*/
/*===========================================================================

Copyright (c) 2012-2020 Qualcomm Technologies, Inc.
All rights reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/
/*===========================================================================

                         EDIT HISTORY FOR MODULE

  Please notice that the changes are listed in reverse chronological order.

  when       who        what, where, why
  --------   ---        -------------------------------------------------------
  02/21/19   dy         (Tech Comm) Edited/added Doxygen comments and markup.
  12/28/17   leo        (Tech Comm) Edited/added Doxygen comments and markup.
  08/29/16   leo        (Tech Pubs) Edited/added Doxygen comments and markup.
  05/28/15   kl         (Tech Pubs) Edited/added Doxygen comments and markup.
  01/05/15   rk         qtimap off-target support.
  10/20/14   kl         (Tech Pubs) Edited/added Doxygen comments and markup.
  07/11/12   gk         Created module.
  10/26/12   cp         Added support for Dual AP and different types of NAT.
  02/27/13   cp         Added support to get IPV6 WAN status.
  04/17/13   mp         Added support to get IPv6 WWAN/STA mode configuration.
  06/12/13   sg         Added support for DHCP Reservation
  01/11/14   sr         Added support for connected devices information in SoftAP
  02/24/14   vm         Changes to Enable/Disable Station Mode to be in
                        accordance with IoE 9x15
===========================================================================*/
/* group: qcmap */
#ifdef FEATURE_QTIMAP_OFFTARGET
#include <glib.h>
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <assert.h>
#include <sys/time.h>
#include <sys/select.h>
#include <pthread.h>
#ifdef FEATURE_EXTERNAL_AP
#include "string.h"
#else
#include "stringl.h"
#include "comdef.h"
#endif /*FEATURE_EXTERNAL_AP */
#include "ds_util.h"
#include "qualcomm_mobile_access_point_msgr_v01.h"
#include "qcmap_client_util.h"
#ifdef FEATURE_QTIMAP_OFFTARGET
#include <tf_qcmap.h>
#endif

#ifdef USE_GLIB
#include <glib.h>
#define strlcpy g_strlcpy
#define strlcat g_strlcat
#endif

/** @addtogroup qcmap_constants
@{ */
/** Maximum size of the file. */
#define QCMAP_MSGR_MAX_FILE_PATH_LEN 100

/** Minimum IPA initial packet threshold. */
#define SW_PACKET_THRESHOLD      3

/** Maximum port value. */
#define MAX_PORT_VALUE           65535

/** Maximum valid protocol value. */
#define MAX_PROTO_VALUE          255

/** Maximum valid Type of Service (TOS) value. */
#define MAX_TOS_VALUE          255

/** Maximum valid idenfier string length value. */
#define MAX_ID_STRING_LEN          255

/** Macro for Enable Packet Statistics. */
#define PACKET_STATS_ENABLE          1

/** Macro for Disable Packet Statistics. */
#define PACKET_STATS_DISABLE          0

/** Macro for Reset Packet Statistics Data. */
#define PACKET_STATS_RESET          5

/** Macro to enable the peer-to-peer role. */
#define P2P_ROLE_ENABLE  1

/** Macro to disable the peer-to-peer role. */
#define P2P_ROLE_DISABLE  0

/** QCMAP Server Status Message ID */
#define QCMAP_SERVER_STATUS_IND 0xFFFF

/** Macro for n79 hysteresis timer */
#define DEFAULT_N79_HYSTERESIS_TIMER 30

/** Macro for wlan hysteresis timer */
#define DEFAULT_WLAN_HYSTERESIS_TIMER 30

/** Macro for number of retries */
#define DEFAULT_QMI_RETRIES 3

/** Macro for attempts timer */
#define DEFAULT_ATTEMPTS_TIMER 1

/** Macro for default 5G priority */
#define DEFAULT_5G_PRIORITY 1

/** Macro to define the default MTU size for L2TP */
#define STD_MTU_SIZE 1500
/** @} */ /* end_addtogroup qcmap_constants */

#ifdef __cplusplus
extern "C"
{
#endif

  #include "qmi_client.h"

#ifdef __cplusplus
}
#endif

/*===========================================================================
LOG Msg Macros
=============================================================================*/

#ifdef FEATURE_EXTERNAL_AP
#define  LOG_MSG_INFO1(...) \
  printf("INFO1: "); \
  printf(__VA_ARGS__); \
  printf("\n")
#define  LOG_MSG_INFO2(...) \
  printf("INFO2: "); \
  printf(__VA_ARGS__); \
  printf("\n")
#define  LOG_MSG_INFO3(...) \
  printf("INFO3: "); \
  printf(__VA_ARGS__); \
  printf("\n")
#define  LOG_MSG_ERROR(...) \
  printf("ERROR: "); \
  printf(__VA_ARGS__); \
  printf("\n")

#elif defined(FEATURE_QTIMAP_OFFTARGET)
#undef LOG_MSG_INFO1
#define LOG_MSG_INFO1(fmtString, x, y, z) \
{ \
  if ( x != 0 && y !=0 && z != 0) \
    fprintf(stderr, "\nINFO1:" fmtString"\n", x, y, z); \
  else if ( x != 0 && y != 0) \
    fprintf(stderr, "\nINFO1:" fmtString"\n", x, y); \
  else if ( x != 0) \
    fprintf(stderr, "\nINFO1:" fmtString"\n", x); \
  else \
    fprintf(stderr, "\nINFO1:" fmtString"\n"); \
}
#undef LOG_MSG_INFO2
#define LOG_MSG_INFO2(fmtString, x, y, z) \
{ \
  if ( x != 0 && y !=0 && z != 0) \
    fprintf(stderr, "\nINFO1:" fmtString"\n", x, y, z); \
  else if ( x != 0 && y != 0) \
    fprintf(stderr, "\nINFO1:" fmtString"\n", x, y); \
  else if ( x != 0) \
    fprintf(stderr, "\nINFO1:" fmtString"\n", x); \
  else \
    fprintf(stderr, "\nINFO1:" fmtString"\n"); \
}

#undef LOG_MSG_INFO3
#define LOG_MSG_INFO3(fmtString, x, y, z) \
{ \
  if ( x != 0 && y !=0 && z != 0) \
    fprintf(stderr, "\nINFO3:" fmtString"\n", x, y, z); \
  else if ( x != 0 && y != 0) \
    fprintf(stderr, "\nINFO3:" fmtString"\n", x, y); \
  else if ( x != 0) \
    fprintf(stderr, "\nINFO3:" fmtString"\n", x); \
  else \
    fprintf(stderr, "\nINFO3:" fmtString"\n"); \
}

#undef LOG_MSG_ERROR
#define LOG_MSG_ERROR(fmtString, x, y, z) \
{ \
  if ( x != 0 && y !=0 && z != 0) \
    fprintf(stderr, "\nError:" fmtString"\n", x, y, z); \
  else if ( x != 0 && y != 0) \
    fprintf(stderr, "\nError:" fmtString"\n", x, y); \
  else if ( x != 0) \
    fprintf(stderr, "\nError:" fmtString"\n", x); \
  else \
    fprintf(stderr, "\nError:" fmtString"\n"); \
}
#else
/** @addtogroup qcmap_macros
@{ */

/*
Log Message Macros
*/
/** Macro for a high-level message. */
#define LOG_MSG_INFO1_LEVEL           MSG_LEGACY_HIGH

/** Macro for a medium-level message. */
#define LOG_MSG_INFO2_LEVEL           MSG_LEGACY_MED

/** Macro for a low-level message. */
#define LOG_MSG_INFO3_LEVEL           MSG_LEGACY_LOW

/**  Macro for a error message. */
#define LOG_MSG_ERROR_LEVEL           MSG_LEGACY_ERROR

/** Macro to print the log message information. */
#define PRINT_MSG( level, fmtString, x, y, z)                         \
        MSG_SPRINTF_4( MSG_SSID_LINUX_DATA, level, "%s(): " fmtString,      \
                       __FUNCTION__, x, y, z);

/** Macro to print a high-level message. */
#define LOG_MSG_INFO1( fmtString, x, y, z)                            \
{                                                                     \
  PRINT_MSG( LOG_MSG_INFO1_LEVEL, fmtString, x, y, z);                \
}

/** Macro to print a medium-level message. @newpage */
#define LOG_MSG_INFO2( fmtString, x, y, z)                            \
{                                                                     \
  PRINT_MSG( LOG_MSG_INFO2_LEVEL, fmtString, x, y, z);                \
}
/** Macro to print a low-level message. */
#define LOG_MSG_INFO3( fmtString, x, y, z)                            \
{                                                                     \
  PRINT_MSG( LOG_MSG_INFO3_LEVEL, fmtString, x, y, z);                \
}
/** Macro to print an error message. */
#define LOG_MSG_ERROR( fmtString, x, y, z)                            \
{                                                                     \
  PRINT_MSG( LOG_MSG_ERROR_LEVEL, fmtString, x, y, z);                \
}

/** @} */ /* end_addtogroup qcmap_macros */
#endif

/** @addtogroup qcmap_datatypes
@{ */
/* Data type for QCMAP client behavior. */
typedef void (*client_status_ind_t)
(
  qmi_client_type user_handle,   /* QMI user handle. */
  unsigned int msg_id,           /* Indicator message ID. */
  void *ind_buf,                 /* Raw indication data. */
  unsigned int ind_buf_len,      /* Raw data length. */
  void *ind_cb_data              /* User callback handle. */
);

/** Data type for passing callback data. */
typedef struct
{
  client_status_ind_t client_cb;  /* User callback handle. */
  qmi_client_type user_handle;    /* QMI user handle. */
  unsigned int msg_id;            /* Indicator message ID. */
  void *ind_buf;                  /* Raw indication data. */
  unsigned int ind_buf_len;       /* Raw data length. */
  bool release_handle;            /* Flag to release user handle */
}qcmap_user_cb_data_t;

/** Data type for qmi client handle. */
typedef struct
{
  void *obj_handle;               /* QCMAP Client object */
  int instance_id;                /* Instance id of new qmi handle */
}qcmap_qmi_handle_data_t;

/** Data type for IPv4 configuration. */
typedef struct
{
  in_addr public_ip;       /**< Public IP address. */
  in_addr primary_dns;     /**< Primary domain name service (DNS) IP address. */
  in_addr secondary_dns;   /**< Secondary DNS IP
                                address. */
}v4_conf_t;

/** Data type for IPv6 configuration. */
typedef struct
{
  struct in6_addr public_ip_v6;      /**< Public IPv6 address. */
  struct in6_addr primary_dns_v6;    /**< Primary domain name service (DNS)
                                          IPv6 address. */
  struct in6_addr secondary_dns_v6;  /**< Secondary DNS
                                          IPv6 address. @newpagetable */
}v6_conf_t;

/** Data type for the backhaul preference. */
typedef struct
{
  qcmap_msgr_backhaul_type_enum_v01 first;   /**< First backhaul preference. */
  qcmap_msgr_backhaul_type_enum_v01 second;  /**< Second backhaul preference. */
  qcmap_msgr_backhaul_type_enum_v01 third;   /**< Third backhaul preference. */
  qcmap_msgr_backhaul_type_enum_v01 fourth;  /**< Fourth backhaul preference. */
  qcmap_msgr_backhaul_type_enum_v01 fifth;   /**< Fifth backhaul preference. */
}backhaul_pref_t;

/** Data type for the backhaul status. */
typedef struct
{
  boolean                            backhaul_v4_available;
  /**< Enable IPv4 backhaul. */
  boolean                            backhaul_v6_available;
  /**< Enable IPv6 backhaul. */
  qcmap_msgr_backhaul_type_enum_v01  backhaul_type;
  /**< First backhaul preference. */
} qcmap_backhaul_status_info_type;

/** Data type for network configuration. */
typedef union
{
  v4_conf_t v4_conf;      /**< IPv4 configuration. */
  v6_conf_t v6_conf;      /**< IPv6 configuration. */
}qcmap_nw_params_t;

/** Data type for the register indications. */
typedef enum
{
  WWAN_ROAMING_STATUS_IND = 0x0001,
  BACKHAUL_STATUS_IND = 0x0002,
  WWAN_STATUS_IND = 0x0004,
  MOBILE_AP_STATUS_IND = 0x0008,
  STATION_MODE_STATUS_IND = 0x0010,
  CRADLE_MODE_STATUS_IND = 0x0020,
  ETHERNET_MODE_STATUS_IND = 0x0040,
  BT_TETHERING_STATUS_IND = 0x0080,
  BT_TETHERING_WAN_IND = 0x0100,
  WLAN_STATUS_IND = 0x0200,
  MODEM_STATUS_IND = 0x0400,
  PACKET_STATS_STATUS_IND = 0x0800
} qcmap_register_indications_t;

/** Data type for QCMAP Architecture */
typedef enum
{
  QCMAP_LEGACY_ARCH,  /**< LEGACY_ARCH is the default config */
  QCMAP_FUSION_ARCH,  /**< FUSION_ARCH to be used when OEM App has to interface with
                           QCMAP_Server on MDM and EAP */
} qcmap_arch_type;


/** Data type for client selection in Fusion architecture */
typedef enum
{
  QCMAP_CLIENT_LOCAL,  /**< CLIENT_LOCAL is the default config */
  QCMAP_CLIENT_REMOTE  /**< CLIENT_REMOTE to be used when interface with QCMAP_Server
                            on Remote Processor */
} qcmap_client_config;

/** Data type for QCMAP server type for SSR notifications */
typedef enum
{
  QCMAP_MSGR_SERVER_TYPE_MDM = 0x0, /**< QCMAP Server on MDM */
  QCMAP_MSGR_SERVER_TYPE_EAP        /**< QCMAP Server on EAP */
} qcmap_server_type;

/** Data type for QCMAP Server status notifications. */
typedef struct
{
  qcmap_server_type server_type;  /* QCMAP Server location. MDM or EAP*/
  uint8_t server_status;          /* QCMAP Server status. Up or down*/
}qcmap_server_status_t;

/** Data type for the SOCKSv5 configuration parameters. */
typedef struct
{
  qcmap_msgr_socksv5_config_file_paths_v01 config_file_paths;
  /**< File paths to the SOCKSv5 configuration files. */
  unsigned char auth_method;
  /**< Preferred SOCKSv5 authentication method. */
  char lan_iface[QCMAP_MAX_IFACE_NAME_SIZE_V01];
  /**< Preferred SOCKSv5 proxy server listening interface. */
  qcmap_msgr_socksv5_wan_config_v01 wan_service[QCMAP_MAX_NUM_BACKHAULS_V01];
  /**< Specifies the cellular modem profile number and rmnet interface name to
       use as a SOCKSv5 backhaul. */
} socksv5_configuration;

/** Data type for peer to peer configuration */
typedef struct
{
  boolean                 p2p_status;
  /**< Enables peer-to-peer feature. */
  uint8_t                 p2p_role_valid;
  /**< Indicates peer-to-peer role is valid. */
  qcmap_p2p_role_type_v01 p2p_role;
  /**< Gets the peer-to-peer role type. */
} qcmap_p2p_config;

/** Structure for L2TP MTU size config */
typedef struct {
  uint8_t l2tp_state_enable;
  /**< Config to enable/disable L2TP Tunnels. */
  uint8_t l2tp_mss_enable;
  /**< Config to enable/disable L2TP MSS configuration. */
  uint8_t l2tp_mtu_enable;
  /**< Config to enable/disable L2TP MTU configuration. */
  uint32_t mtu_size;
  /**< MTU size in bytes. */
}qcmap_set_l2tp_config;

/** Data type for V2X request */
typedef struct
{
  union
  {
    qcmap_msgr_v2x_sps_flow_reg_req_msg_v01                 v2x_sps_flow_reg_req_msg;
    /**< Request msg for QCMAP_MSGR_V2X_SPS_FLOW_REG */

    qcmap_msgr_v2x_sps_flow_dereg_req_msg_v01               v2x_sps_flow_dereg_req_msg;
    /**< Request msg for QCMAP_MSGR_V2X_SPS_FLOW_DEREG */

    qcmap_msgr_v2x_sps_flow_update_req_msg_v01              v2x_sps_flow_update_req_msg;
    /**< Request msg for QCMAP_MSGR_V2X_SPS_FLOW_UPDATE */

    qcmap_msgr_v2x_sps_flow_get_info_req_msg_v01            v2x_sps_flow_get_info_req_msg;
    /**< Request msg for QCMAP_MSGR_V2X_SPS_FLOW_GET_INFO */

    qcmap_msgr_v2x_non_sps_flow_reg_req_msg_v01             v2x_non_sps_flow_reg_req_msg;
    /**< Request msg for QCMAP_MSGR_V2X_NON_SPS_FLOW_REG */

    qcmap_msgr_v2x_non_sps_flow_dereg_req_msg_v01           v2x_non_sps_flow_dereg_req_msg;
    /**< Request msg for QCMAP_MSGR_V2X_NON_SPS_FLOW_DEREG */

    qcmap_msgr_v2x_service_subscribe_req_msg_v01            v2x_service_subscribe_req_msg;
    /**< Request msg for QCMAP_MSGR_V2X_SERVICE_SUBSCRIBE */

    qcmap_msgr_v2x_service_get_subscribe_list_req_msg_v01   v2x_service_get_subscribe_list_req_msg;
    /**< Request msg for QCMAP_MSGR_V2X_GET_SERVICE_SUBSCRIPTION_INFO */

    qcmap_msgr_v2x_send_config_file_req_msg_v01             v2x_send_config_file_req_msg;
    /**< Request msg for QCMAP_MSGR_V2X_SEND_CONFIG_FILE */

    qcmap_msgr_v2x_update_src_l2_info_req_msg_v01           v2x_update_src_l2_info_req_msg;
    /**< Request msg for QCMAP_MSGR_V2X_UPDATE_SRC_L2_INFO */

    qcmap_msgr_v2x_tunnel_mode_info_req_msg_v01             v2x_tunnel_mode_info_req_msg;
    /**< Request msg for QCMAP_MSGR_V2X_TUNNEL_MODE_INFO */

    qcmap_msgr_v2x_get_capability_info_req_msg_v01          v2x_get_capability_info_req_msg;
    /**< Request msg for QCMAP_MSGR_V2X_GET_CAPABILITY_INFO */
  } req_msg;
} qcmap_v2x_request;

/** Data type for V2X response */
typedef struct
{
  union
  {
    qcmap_msgr_v2x_sps_flow_reg_resp_msg_v01                 v2x_sps_flow_reg_resp_msg;
    /**< Response msg for QCMAP_MSGR_V2X_SPS_FLOW_REG */

    qcmap_msgr_v2x_sps_flow_dereg_resp_msg_v01               v2x_sps_flow_dereg_resp_msg;
    /**< Response msg for QCMAP_MSGR_V2X_SPS_FLOW_DEREG */

    qcmap_msgr_v2x_sps_flow_update_resp_msg_v01              v2x_sps_flow_update_resp_msg;
    /**< Response msg for QCMAP_MSGR_V2X_SPS_FLOW_UPDATE */

    qcmap_msgr_v2x_sps_flow_get_info_resp_msg_v01            v2x_sps_flow_get_info_resp_msg;
    /**< Response msg for QCMAP_MSGR_V2X_SPS_FLOW_GET_INFO */

    qcmap_msgr_v2x_non_sps_flow_reg_resp_msg_v01             v2x_non_sps_flow_reg_resp_msg;
    /**< Response msg for QCMAP_MSGR_V2X_NON_SPS_FLOW_REG */

    qcmap_msgr_v2x_non_sps_flow_dereg_resp_msg_v01           v2x_non_sps_flow_dereg_resp_msg;
    /**< Response msg for QCMAP_MSGR_V2X_NON_SPS_FLOW_DEREG */

    qcmap_msgr_v2x_service_subscribe_resp_msg_v01            v2x_service_subscribe_resp_msg;
    /**< Response msg for QCMAP_MSGR_V2X_SERVICE_SUBSCRIBE */

    qcmap_msgr_v2x_service_get_subscribe_list_resp_msg_v01   v2x_service_get_subscribe_list_resp_msg;
    /**< Response msg for QCMAP_MSGR_V2X_GET_SERVICE_SUBSCRIPTION_INFO */

    qcmap_msgr_v2x_send_config_file_resp_msg_v01             v2x_send_config_file_resp_msg;
    /**< Response msg for QCMAP_MSGR_V2X_SEND_CONFIG_FILE */

    qcmap_msgr_v2x_update_src_l2_info_resp_msg_v01           v2x_update_src_l2_info_resp_msg;
    /**< Response msg for QCMAP_MSGR_V2X_UPDATE_SRC_L2_INFO */

    qcmap_msgr_v2x_tunnel_mode_info_resp_msg_v01             v2x_tunnel_mode_info_resp_msg;
    /**< Response msg for QCMAP_MSGR_V2X_TUNNEL_MODE_INFO */

    qcmap_msgr_v2x_get_capability_info_resp_msg_v01          v2x_get_capability_info_resp_msg;
    /**< Response msg for QCMAP_MSGR_V2X_GET_CAPABILITY_INFO */

  } resp_msg;
} qcmap_v2x_response;
/** @} */ /* end_addtogroup qcmap_datatypes */

//===================================================================
//              Class Definitions
//===================================================================

/**  @ingroup qcmap_class */
class QCMAP_Client
{
  private:
    boolean                            m_qcmap_msgr_enable;
    /* Whether the QCMAP Connection Manager is enabled. */

    /* @addtogroup qcmap_fields
    @{ */
    /* QMI QCMAP Client handle for Server Instance#0. */
    qmi_client_type                    m_qmi_qcmap_instance0_handle;
    /*< MDM Connection manager messenger handle. */
    /* QMI QCMAP Client handle for Server Instance#1. */
    qmi_client_type                    m_qmi_qcmap_instance1_handle;
    /*< EAP Connection manager messenger handle. */
    /* QMI QCMAP Client Preferred handle. */
    qmi_client_type                    m_qmi_qcmap_preferred_handle;
    /*< Preferred Connection manager messenger handle. */
    qmi_client_type                    m_qmi_qcmap_msgr_notifier;
    /*< Connection manager messenger notifier. */
    qmi_cci_os_signal_type             m_qmi_qcmap_msgr_os_params;
    /*< Connection manager messenger OS parameters.  */
    /* @} */ /* endaddtogroup qcmap_fields */

    qcmap_msgr_arch_type_enum_v01      m_qcmap_arch;
    client_status_ind_t                m_user_cb_ind;
    void                              *m_user_data;

    /* Private Member Functions */
    void Init();
    qmi_client_error_type CreateQMI_ClientHandle(int instance_id);
    static void Invoke_UserCB(void *cb_args);
    static void Invoke_CreateQMI_ClientHandle(void *handle_info);
    void SendQCMAPServerServiceStatus(qmi_client_type user_handle,
                                      qcmap_server_type server_type,
                                      qcmap_msgr_ssr_service_status_enum_v01 server_status);
    static void QMI_QCMAPServerService_ErrCB(qmi_client_type user_handle,
                                             qmi_client_error_type   error,
                                             void                   *err_cb_data);
    static void QMI_ServiceAvailableCB(qmi_client_type                user_handle,
                                       qmi_idl_service_object_type    service_obj,
                                       qmi_client_notify_event_type   service_event,
                                       void                          *notify_cb_data);
  public:
    uint32_t                  mobile_ap_handle;
    /*< Handle for the mobile ap */

    /* @addtogroup qcmap_fields
    @{ */
    /* QMI QCMAP_CM service information. */
    qmi_client_type           qmi_qcmap_msgr_handle;
    /*< Deprecated, don't use. Connection manager messenger handle. */
    qmi_client_type           qmi_qcmap_msgr_notifier;
    /*< Deprecated, don't use. Connection manager messenger notifier. */
    qmi_cci_os_signal_type    qmi_qcmap_msgr_os_params;
    /*< Deprecated, don't use. Connection manager messenger OS parameters.  */

    /* @} */ /* endaddtogroup qcmap_fields */

/*===========================================================================
FUNCTION QCMAP_Client()
===========================================================================*/
/** @ingroup qcmap_class

  Constructor for the client library QCMAP_Client class.

  This constructor calls the QMI common client interface (QCCI) functions
  to connect with the QCMAP_MSGR service and  registers the client callback
  function for any asynchronous indications received from the QCMAP_MSGR
  service.

  @datatypes
  client_status_ind_t

  @param[in,out] client_cb_ind       Client callback function registered with
                                     the QMI framework.
  @param[in] qcmap_arch              Pick QCMAP architecture, default is
                                     QCMAP_LEGACY_ARCH.
  @param[in] client_cb_data          Client callback data pointer registered
                                     with the QMI framework.

  @return
  None.
*/
QCMAP_Client
(
  client_status_ind_t                client_cb_ind,
  qcmap_msgr_arch_type_enum_v01      qcmap_arch     = QCMAP_LEGACY_ARCH_V01,
  void                              *client_cb_data = NULL
);

/*===========================================================================
FUNCTION QCMAP_Client clean up
===========================================================================*/
/** @ingroup qcmap_class

  Destructor for the client object.

  @return
  None.
*/
virtual ~QCMAP_Client
(
  void
);

/* ---------------------------MobileAP Execution---------------------------*/

/*===========================================================================
FUNCTION EnableMobileAP()
===========================================================================*/
/** @ingroup qcmap_enable_mobile_ap

  Enables the MobileAP interface.

  This function enables the QCMobileAP based on the configuration provided.
  The server, as part of enabling the QCMobileAP, gets the appropriate
  dsi_netctrl module and NAS handles.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Successfully sets the dsi_netctrl module and
          NAS client handles. \n
  FALSE -- Any of the above operations failed.

  @dependencies
  None. @newpage
*/
boolean
EnableMobileAP
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION EnableMobileAP_Ext()
===========================================================================*/
/** @ingroup qcmap_enable_mobile_ap

  Enables the QCMobileAP feature based on the configuration provided.
  The server, as part of enabling the QCMobileAP, gets the appropriate
  dsi_netctrl module and NAS handles.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num   Pointer to the error code returned by the server.
  @param[in]  ind_reg_mask  Indication register mask.

  @return
  TRUE -- Successfully sets the dsi_netctrl module and
          NAS client handles. \n
  FALSE -- Any of the above operations failed.

  @dependencies
  None.
*/
boolean
EnableMobileAP_Ext
(
  qmi_error_type_v01 *qmi_err_num,
  uint64_t ind_reg_mask
);

/*===========================================================================
FUNCTION DisableMobileAP()
===========================================================================*/
/** @ingroup qcmap_disable_mobile_ap

  Disables the QCMobileAP feature.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Successfully releases the handles and NAS client. \n
  FALSE -- Any of the above operations failed.

  @dependencies
  QCMobileAP must be enabled.
*/

boolean
DisableMobileAP
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetWWANProfileHandlePreference()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Sets the profile handle to be used for WWAN APIs.

  @datatypes
  profile_handle_type_01 \n
  qmi_error_type_v01

  @param[in]  profile_handle  Profile handle used for WWAN APIs.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.
  @return
  TRUE -- Success. \n
  FALSE -- Failure.


  @dependencies
  None. @newpage
*/
boolean
SetWWANProfileHandlePreference
(
  profile_handle_type_v01  profile_handle,
  qmi_error_type_v01      *qmi_err_num
);

/*===========================================================================
FUNCTION EnableIPV4()
===========================================================================*/
/** @ingroup qcmap_enable_ipv4

  Enables IPv4 functionality. It establishes the IPv4 call using
  the stored network policy if autoconnect is enabled and establishes the
  NAT rules.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
EnableIPV4
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DisableIPV4()
===========================================================================*/
/** @ingroup qcmap_disable_ipv4

  Disables IPv4 functionality. Brings down the IPv4 call if it is already
  connected and disables NAT.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DisableIPV4
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION EnableIPV6()
===========================================================================*/
/** @ingroup qcmap_enable_ipv6

  Enables IPv6 functionality. The IPv6 call is established using the
  stored network policy if autoconnect is enabled and enables IPv6 forwarding.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
EnableIPV6
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DisableIPV6()
===========================================================================*/
/** @ingroup qcmap_disable_ipv6

  Disables IPv6 functionality. Brings down the IPv6 call
  if it is already connected and disables IPv6 forwarding.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DisableIPV6
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION ConnectBackHaul()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Connects the Wireless Wide Area Network (WWAN) backhaul. This
  function connects the WWAN based on the configuration provided.

  @datatypes
  qcmap_msgr_wwan_call_type_v01 \n
  qmi_error_type_v01

  @param[in] call_type     Identifies call type.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
ConnectBackHaul
(
  qcmap_msgr_wwan_call_type_v01 call_type,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DisconnectBackHaul()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Disconnects the WWAN backhaul.

  @datatypes
  qcmap_msgr_wwan_call_type_v01 \n
  qmi_error_type_v01

  @param[in] call_type     Identifies call type.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DisconnectBackHaul
(
  qcmap_msgr_wwan_call_type_v01 call_type,
  qmi_error_type_v01 *qmi_err_num
);


/** @cond */
/*===========================================================================
* FUNCTION EnableSTAMode()
* ===========================================================================*/
/** @ingroup qcmap_enable_sta_mode

  Enables WLAN in STA-Only mode.
  This function is used internally by the eCNE module. Other QCMAP Clients
  must not use this function.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned
                           by the server. A few important error
                           codes are as follows:\n
                                - QMI_ERR_NO_EFFECT_V01 -- WLAN is already enabled. \n
                                - QMI_ERR_NONE_V01 -- Success. \n
                                - QMI_ERR_INTERNAL_V01 -- Failure.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.

*/
boolean
EnableSTAMode
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
* FUNCTION DisableSTAMode()
* ===========================================================================*/
/** @ingroup qcmap_disable_sta_mode

  Disables WLAN in STA-Only mode.
  This is only to be used internally by eCNE module. Other QCMAP clients
  should not use this API.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server
                           The most common error codes are: \n
                           - QMI_ERR_NO_EFFECT_V01 -- WLAN is already enabled \n
                           - QMI_ERR_NONE_V01 -- Success \n
                           - QMI_ERR_INTERNAL_V01 -- Failure

  @return
  TRUE -- Success \n
  FALSE -- Failure

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DisableSTAMode
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION RegisterForWLANStatusIND()
===========================================================================*/
/** @ingroup qcmap_register_for_wlan_status_ind

  Registers for WLAN status indications.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num          Pointer to the error code returned by the
                                   server.
  @param[in]  register_indication  Register for a WLAN status indicators.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
RegisterForWLANStatusIND
(
  qmi_error_type_v01 *qmi_err_num,
  boolean register_indication
);

/*===========================================================================
FUNCTION RegisterForWWANStatusIND()
===========================================================================*/
/** @ingroup qcmap_register_for_wwan_status_ind

  Registers for WWAN status indications.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num         Error code returned by the server.
  @param[in]  register_indication Boolean value to either register or deregister
                                  for a WWAN status indication.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  None.
*/
boolean
RegisterForWWANStatusIND
(
  qmi_error_type_v01 *qmi_err_num,
  boolean register_indication
);

/*===========================================================================
FUNCTION RegisterForIndications()
===========================================================================*/
/** @ingroup qcmap_register_for_indications

  Registers for status indications.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num         Error code returned by the server.
  @param[in]  ind_reg_mask        Indication register mask to register for
                                  status indications.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  None.

  @notes
  Client process should maintain the Indication MASK
*/
boolean
RegisterForIndications

(
  qmi_error_type_v01 *qmi_err_num,
  uint64_t ind_reg_mask
);

/** @endcond */

/*===========================================================================
FUNCTION EnableWLAN()
===========================================================================*/
/** @ingroup qcmap_enable_wlan

  Enables the WLAN. This function enables the WLAN based on the
  hostpad configuration provided. This function inserts the WLAN
  kernel module and advertises the SSID.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
EnableWLAN
(
  qmi_error_type_v01 *qmi_err_num,
  /** @cond */
  boolean privileged_client = false
  /** @endcond */
);

/*===========================================================================
FUNCTION DisableWLAN()
===========================================================================*/
/** @ingroup qcmap_disable_wlan

  Disables the WLAN. This function removes the kernel module
  for the Wi-Fi driver.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DisableWLAN
(
  qmi_error_type_v01 *qmi_err_num,
  /** @cond */
  boolean privileged_client = false
  /** @endcond */
);

/*===========================================================================
FUNCTION SetWLANConfig()
===========================================================================*/
/** @ingroup qcmap_set_wlan_config

  Sets the WLAN configuration: WLAN mode, guest access profile, and
  station mode configuration.

  @datatypes
  qcmap_msgr_wlan_mode_enum_v01 \n
  qcmap_msgr_access_profile_v01 \n
  qcmap_msgr_station_mode_config_v01 \n
  qmi_error_type_v01 \n
  qcmap_msgr_guest_profile_config_v01

  @param[in] wlan_mode                 Sets WLAN mode. \n
  @values
  - QCMAP_MSGR_WLAN_MODE_AP_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_STA_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_AP_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_AP_AP_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_STA_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_STA_BRIDGE_V01\n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_STA_ BRIDGE_V01
  @tablebulletend
  @param[in] guest_ap_access_profile  Guest AP access profile configuration.
                                      This parameter is for the legacy Single
                                      Guest AP mode. \n
  @values
  - QCMAP_MSGR_PROFILE_FULL_ACCESS_V01 -- AP can access complete LAN, including
  the internet. \n
  - QCMAP_MSGR_PROFILE_INTERNET_ONLY_V01 -- AP can only access the internet.
  @tablebulletend
  @param[in] station_config            Station mode WLAN configuration. \n
  @values
  - qcmap_msgr_sta_connection_enum_v01 -- Connection type; either STATIC or
  DYNAMIC. \n
  - qcmap_msgr_sta_static_ip_config_v01 -- Used only when the connection type
  is static. \n
  - ap_sta_bridge_mode -- Used to Set Bridge/Router mode when STA is active.
  @tablebulletend
  @param[out] qmi_err_num              Pointer to the error code returned by
                                       the server.
  @param[in] guest_profile             (Optional) Data structure pointer to set
                                       guest AP profile information.
                                       Must be used if more than one
                                       guest APs is configured. \n
                                       @values qcmap_msgr_access_profile_v01

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetWLANConfig
(
  qcmap_msgr_wlan_mode_enum_v01 wlan_mode,
  qcmap_msgr_access_profile_v01 guest_ap_access_profile,
  qcmap_msgr_station_mode_config_v01 station_config,
  qmi_error_type_v01 *qmi_err_num,
  qcmap_msgr_guest_profile_config_v01 *guest_profile = NULL
);

/*===========================================================================
FUNCTION GetWLANConfig()
===========================================================================*/
/** @ingroup qcmap_get_wlan_config

  Gets the WLAN configuration: WLAN mode, guest access profile, and
  station mode configuration.

  @datatypes
  qcmap_msgr_wlan_mode_enum_v01 \n
  qcmap_msgr_access_profile_v01 \n
  qcmap_msgr_station_mode_config_v01 \n
  qmi_error_type_v01 \n
  qcmap_msgr_guest_profile_config_v01

  @param[out] wlan_mode                 Sets WLAN mode. \n
  @values
  - QCMAP_MSGR_WLAN_MODE_AP_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_STA_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_AP_V01  \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_AP_AP_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_STA_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_STA_BRIDGE_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_STA_ BRIDGE_V01
  @tablebulletend
  @param[out] guest_ap_access_profile  Guest AP access profile configuration.
                                       This parameter is for the legacy Single
                                       Guest AP mode. \n
  @values
  - QCMAP_MSGR_PROFILE_FULL_ACCESS_V01 -- AP can access complete LAN, including
  the internet. \n
  - QCMAP_MSGR_PROFILE_INTERNET_ONLY_V01 -- AP can only access the internet
  @tablebulletend
  @param[out] station_config            Station mode WLAN configuration. \n
  @values
  - qcmap_msgr_sta_connection_enum_v01 -- Connection type; either STATIC or
  DYNAMIC. \n
  - qcmap_msgr_sta_static_ip_config_v01 -- Used only  when the connection type
    is static. \n
  - ap_sta_bridge_mode -- Used to Set Bridge/Router mode when STA is active.
  @tablebulletend
  @param[out] qmi_err_num              Pointer to the error code returned by
                                       the server.
  @param[out] guest_profile            (Optional) Data structure pointer to set
                                       guest AP profile information
                                       Must be used if more than one
                                       guest APs is configured. \n
                                       @values qcmap_msgr_access_profile_v01

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetWLANConfig
(
  qcmap_msgr_wlan_mode_enum_v01 *wlan_mode,
  qcmap_msgr_access_profile_v01 *guest_ap_access_profile,
  qcmap_msgr_station_mode_config_v01 *station_config,
  qmi_error_type_v01 *qmi_err_num,
  qcmap_msgr_guest_profile_config_v01 *guest_profile = NULL
);

/*===========================================================================
FUNCTION ActivateWLAN()
===========================================================================*/
/** @ingroup qcmap_activate_wlan

  Activates the WLAN with the latest configuration. This
  activation might cause the WLAN to be disabled and re-enabled depending
  on the changes to the configuration.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
ActivateWLAN
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetLANConfig()
===========================================================================*/
/** @ingroup qcmap_set_lan_config

  Sets the LAN configuration parameters such as gateway IP, subnet mask
  and the enable DHCP flag, along with DHCP parameters. All LAN
  interfaces are bridged together using a bridge interface. A single
  instance of the DHCP server, running on the bridge interface,
  assigns IP addresses to all clients including WLAN clients and USB
  Terminal Equipment (TE). Therefore, all the clients get IP addresses
  allocated from the same subnet and address range.

  @datatypes
  qcmap_msgr_lan_config_v01 \n
  qmi_error_type_v01

  @param[in]  lan_config   LAN configuration parameters to set.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetLANConfig
(
  qcmap_msgr_lan_config_v01 lan_config,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetLANConfig()
===========================================================================*/
/** @ingroup qcmap_get_lan_config

  Gets the configured LAN configuration parameters. All LAN interfaces
  are bridged together using a bridge interface. A single instance of
  a DHCP server, running on the bridge interface, assigns IP addresses
  to all clients including WLAN clients and USB TE. Therefore, all the
  clients get IP addresses allocated from the same subnet and
  address range.

  @datatypes
  qcmap_msgr_lan_config_v01 \n
  qmi_error_type_v01

  @param[out] lan_config   LAN configuration buffer to use.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetLANConfig
(
  qcmap_msgr_lan_config_v01 *lan_config,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION ActivateLAN()
===========================================================================*/
/** @ingroup qcmap_activate_lan

  Activates the LAN with the latest configuration.

  This activation might cause the WLAN to be disabled and reenabled depending
  on the changes to the configuration. In either case, the backhaul
  is not affected.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
ActivateLAN
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetWLANStatus()
===========================================================================*/
/** @ingroup qcmap_get_wlan_status

  Gets the WLAN status.

  @datatypes
  qcmap_msgr_wlan_mode_enum_v01
  qmi_error_type_v01

  @param[out] wlan_mode    Gets the WLAN status.  \n
   @values
  - QCMAP_MSGR_WLAN_MODE_AP_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_STA_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_AP_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_STA_V01 \n
  - QCMAP_MSGR_WLAN_MODE_STA_ONLY_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_STA_BRIDGE_V01 \n
  - QCMAP_MSGR_WLAN_MODE_AP_AP_STA_ BRIDGE_V01 \n
  - QCMAP_MSGR_WLAN_MODE_STA_ONLY_ BRIDGE_V01
  @tablebulletend
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetWLANStatus
(
  qcmap_msgr_wlan_mode_enum_v01 *wlan_mode,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION ActivateHostapdConfig()
===========================================================================*/
/** @ingroup qcmap_activate_hostapd_config

  Activates the hostapd configuration after the
  appropriate hostapd.conf is modified.

  @datatypes
  qcmap_msgr_activate_hostapd_ap_enum_v01 \n
  qcmap_msgr_activate_hostapd_action_enum_v01 \n
  qmi_error_type_v01

  @param[in] ap_type             Indicates hostapd.conf associated with the
                                 ap_type to be activated. \n
                                   @values
                                 - QCMAP_MSGR_PRIMARY_AP_V01 \n
                                 - QCMAP_MSGR_GUEST_AP_V01 \n
                                 - QCMAP_MSGR_GUEST_AP_2_V01 \n
                                 - QCMAP_MSGR_ALL_AP_V01
  @tablebulletend
  @param[in] action_type         Indicates the action to be performed such as
                                 start, stop, and restart. \n
                                 @values
                                 - QCMAP_MSGR_HOSTAPD_START_V01 \n
                                 - QCMAP_MSGR_HOSTAPD_STOP_V01 \n
                                 - QCMAP_MSGR_HOSTAPD_RESTART_V01
  @tablebulletend
  @param[out] qmi_err_num        Pointer to the error code returned by the
                                 server.
  @param[in]  privileged_client  Sets the status of the privileged client.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
ActivateHostapdConfig
(
  qcmap_msgr_activate_hostapd_ap_enum_v01 ap_type,
  qcmap_msgr_activate_hostapd_action_enum_v01 action_type,
  qmi_error_type_v01 *qmi_err_num,
  boolean privileged_client = false
);

/*===========================================================================
FUNCTION ActivateSupplicantConfig()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wlan

  Activates the WPA supplicant configuration after wpa_supplicant.conf
  is modified.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
ActivateSupplicantConfig
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
  FUNCTION GetActiveWlanIfInfo()
  ===========================================================================*/
/** @ingroup section_qcmap_backhaul_wlan

  Gets information from the active WLAN interfaces.

  @datatypes
  qcmap_msgr_wlan_if_info_t \n
  qmi_error_type_v01

  @param[out] wlan_if_info  Gets message from an active WLAN interface.
  @param[out] qmi_err_num   Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.

*/
boolean GetActiveWlanIfInfo
(
  qcmap_msgr_wlan_if_info_t *wlan_if_info,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION AddStaticNatEntry()
===========================================================================*/
/** @ingroup qcmap_add_static_nat_entry

  Adds a static entry in the Network Address Translation (NAT) table and
  updates the XML file with the new entry.

  @datatypes
  qcmap_msgr_snat_entry_config_v01 \n
  qmi_error_type_v01

  @param[in]  snat_entry       Add a static NAT configuration entry.
  @param[out] qmi_err_num      Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/

boolean
AddStaticNatEntry
(
  qcmap_msgr_snat_entry_config_v01 *snat_entry,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION AddStaticNatEntry_Ipv6()
===========================================================================*/
/** @ingroup qcmap_add_static_nat_entry_ipv6

  Adds a static entry in the Network Address Translation (NAT) table and
  updates the XML file with the new entry.

  @datatypes
  qcmap_msgr_snat_entry_config_v01\n
  qmi_error_type_v01

  @param[in] snat_entry        Static NAT configuration to add.
  @param[out] qmi_err_num      Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/

boolean
AddStaticNatEntry_Ipv6
(
  qcmap_msgr_snat_v6_entry_config_v01 *snat_entry,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DeleteStaticNatEntry()
===========================================================================*/
/** @ingroup qcmap_delete_static_nat_entry

  Deletes the static entry from the NAT table. If the deletion is
  successful, this function also deletes the entry from the XML
  file.

  @datatypes
  qcmap_msgr_snat_entry_config_v01\n
  qmi_error_type_v01

  @param[in] snat_entry    Deletes a static NAT entry.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DeleteStaticNatEntry
(
  qcmap_msgr_snat_entry_config_v01 *snat_entry,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DeleteStaticNatEntry_Ipv6()
===========================================================================*/
/** @ingroup qcmap_delete_static_nat_entry_ipv6

  Deletes the static entry from the NAT table. If the deletion is
  successful, this function also deletes the entry from the XML
  file.

  @datatypes
  qcmap_msgr_snat_v6_entry_config_v01\n
  qmi_error_type_v01

  @param[in] snat_entry         Static NAT configuration to be deleted.
  @param[out] qmi_err_num       Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DeleteStaticNatEntry_Ipv6
(
  qcmap_msgr_snat_v6_entry_config_v01 *snat_entry,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetStaticNatConfig()
===========================================================================*/
/** @ingroup qcmap_get_static_nat_config

  Gets the static entries in the NAT table.

  @datatypes
  qcmap_msgr_snat_entry_config_v01 \n
  qmi_error_type_v01

  @param[out] snat_config  Gets the static NAT entries.
  @param[out] num_entries  Number of static NAT entries configured.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetStaticNatConfig
(
  qcmap_msgr_snat_entry_config_v01 *snat_config,
  int *num_entries,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetStaticNatConfig_Ipv6()
===========================================================================*/
/** @ingroup qcmap_get_static_nat_v6_config

  Gets the static entries in the NAT table.

  @datatypes
  qcmap_msgr_snat_entry_config_v01\n
  qmi_error_type_v01

  @param[out] snat_config       Static NAT entries configured.
  @param[out] num_entries       Number of static NAT entries configured.
  @param[out] qmi_err_num       Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetStaticNatConfig_Ipv6
(
  qcmap_msgr_snat_v6_entry_config_v01 *snat_config,
  int *num_entries,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION AddDMZ()
===========================================================================*/
/** @ingroup qcmap_add_dmz

  Adds the DMZ IP address and updates the XML file.

  This function gets the DMZ IP from the user and sends it to the QCMAP_MSGR
  server to be added as the DMZ server. It also updates the DMZ IP in the
  XML file.

  @datatypes
  qmi_error_type_v01

  @param[in] dmz_ip          DMZ IP to be added; address is in host byte order.
  @param[out] qmi_err_num    Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
AddDMZ
(
  uint32 dmz_ip,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION AddDMZ_Ipv6()
===========================================================================*/
/** @ingroup qcmap_add_dmz for IPv6

  Adds the DMZ IP address and updates the XML file.

  This function gets the DMZ IP from the user and sends it to the QCMAP_MSGR
  server to be added as the DMZ server. It also updates the DMZ IP in the
  XML file.

  @datatypes
  qmi_error_type_v01

  @param[in] dmz_ip            DMZ IP to be added; address is in host byte order.
  @param[out] qmi_err_num      IPv6 NAT disabled.
  @param[out] qmi_err_num      Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
AddDMZ_Ipv6
(
  struct in6_addr dmz_ip,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DeleteDMZ()
===========================================================================*/
/** @ingroup qcmap_delete_dmz

  Deletes the DMZ IP address and updates the DMZ IP address in the
  configuration XML file.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DeleteDMZ
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DeleteDMZ_Ipv6()
===========================================================================*/
/** @ingroup qcmap_delete_dmz

  Deletes the DMZ IP address and updates the DMZ IP address in the
  configuration XML file.

  @datatypes
  qmi_error_type_v01
  @param[out] qmi_err_num      IPv6 NAT disabled.
  @param[out] qmi_err_num      Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DeleteDMZ_Ipv6
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetDMZ()
===========================================================================*/
/** @ingroup qcmap_get_dmz

  Queries the DMZ entry that was previously set with the
  QMI_QCMAP_MSGR_SET_DMZ command. If no DMZ is set by the client, an
  IP address of 0.0.0.0 is returned.

  @datatypes
  qmi_error_type_v01

  @param[out] dmz_ip       DMZ IP configured.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetDMZ
(
  uint32_t *dmz_ip,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetDMZ_Ipv6()
===========================================================================*/
/** @ingroup qcmap_get_dmz

  Queries the DMZ entry that was previously set with the
  QMI_QCMAP_MSGR_SET_DMZ command. If no DMZ is set by the client, an
  IP address of :: is returned.

  @datatypes
  qmi_error_type_v01

  @param[out] dmz_ip            DMZ IP configured.
  @param[out] qmi_err_num       Error code returned by the server.
  @param[out] ipv6_nat_disabled IPv6 NAT disabled
  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetDMZ_Ipv6
(
  struct in6_addr *dmz_ip,
  qmi_error_type_v01 *qmi_err_num
);
/*===========================================================================
FUNCTION GetWWANStatistics()
===========================================================================*/
/* TODO fix formatting/values on params!!*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets the WWAN statistics.

  This function populates the QCMAP_Client::wwan_stats obtained from the
  QCMAP_MSGR server.

  @datatypes
  qcmap_msgr_ip_family_enum_v01\n
  qcmap_msgr_wwan_statistics_type_v01\n
  qmi_error_type_v01

  @param[in] ip_family     @values
                           - 4 -- Gets the IPv4 WWAN statistics.\n
                           - 6 -- Gets the IPv6 WWAN statistics.
                           @tablebulletend
  @param[out] wwan_stats   Statistics for the identified IP version.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/
boolean
GetWWANStatistics
(
  qcmap_msgr_ip_family_enum_v01 ip_family,
  qcmap_msgr_wwan_statistics_type_v01 *wwan_stats,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION ResetWWANStatistics()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Resets the WWAN statistics for the specified IP version family.

  @datatypes
  qcmap_msgr_ip_family_enum_v01\n
  qmi_error_type_v01

  @param[in] ip_family     Values:\n
                           - 4 -- Resets the IPv4 WWAN statistics.
                           - 6 -- Resets the IPv6 WWAN statistics.
                           @tablebulletend
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/
boolean
ResetWWANStatistics
(
  qcmap_msgr_ip_family_enum_v01 ip_family,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetIPSECVpnPassthrough()
===========================================================================*/
/** @ingroup qcmap_set_ipsec_vpn_passthrough

  Sets the Internet Protocol Security (IPSec) Virtual Private Network (VPN)
  passthrough control flag.

  @datatypes
  qmi_error_type_v01

  @param[in]  enable        Sets the IPSec VPN passthrough control flag.
  @param[out] qmi_err_num   Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetIPSECVpnPassthrough
(
  boolean enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetIPSECVpnPassthrough()
===========================================================================*/
/** @ingroup qcmap_get_ipsec_vpn_passthrough

  Gets the IPSec VPN passthrough control flag.

  @datatypes
  qmi_error_type_v01

  @param[out] enable       Gets the IPSec VPN passthrough control flag.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetIPSECVpnPassthrough
(
  boolean *enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetPPTPVpnPassthrough()
===========================================================================*/
/** @ingroup qcmap_set_pptp_vpn_passthrough

  Sets the Point-to-Point Tunneling Protocol (PPTP) VPN
  passthrough control flag.

  @datatypes
  qmi_error_type_v01

  @param[in]  enable       Sets the PPTP VPN passthrough control flag.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetPPTPVpnPassthrough
(
  boolean enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetPPTPVpnPassthrough()
===========================================================================*/
/** @ingroup qcmap_get_pptp_vpn_passthrough

  Gets the PPTP VPN passthrough control flag.

  @datatypes
  qmi_error_type_v01

  @param[out] enable       Gets the PPTP VPN passthrough control flag.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetPPTPVpnPassthrough
(
  boolean *enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetL2TPVpnPassthrough()
===========================================================================*/
/** @ingroup qcmap_set_l2tp_vpn_passthrough

  Sets the Layer 2 Tunneling Protocol (L2TP) VPN passthrough control flag.

  @datatypes
  qmi_error_type_v01

  @param[in] enable           Sets the L2TP VPN passthrough control flag
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetL2TPVpnPassthrough
(
  boolean enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetL2TPVpnPassthrough()
===========================================================================*/
/** @ingroup qcmap_get_l2tp_vpn_passthrough

  Gets the L2TP VPN passthrough control flag.

  @datatypes
  qmi_error_type_v01

  @param[out] enable          Gets the L2TP VPN passthrough control flag
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetL2TPVpnPassthrough
(
  boolean *enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetIPSECVpnPassthrough_Ipv6()
===========================================================================*/
/** @ingroup qcmap_set_ipsec_vpn_passthrough_ipv6

  Sets the Internet Protocol Security (IPSec) Virtual Private Network (VPN)
  passthrough control flag for IPv6

  @datatypes
  qmi_error_type_v01

  @param[in] enable            Sets the IPSec VPN passthrough control flag.
  @param[out] qmi_err_num      Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetIPSECVpnPassthrough_Ipv6
(
  boolean enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetIPSECVpnPassthrough_Ipv6()
===========================================================================*/
/** @ingroup qcmap_get_ipsec_vpn_passthrough

  Gets the IPSec VPN passthrough control flag

  @datatypes
  qmi_error_type_v01

  @param[out] enable           Gets the IPSec VPN passthrough control flag.
  @param[out] qmi_err_num      Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetIPSECVpnPassthrough_Ipv6
(
  boolean *enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetPPTPVpnPassthrough_Ipv6()
===========================================================================*/
/** @ingroup qcmap_set_pptp_vpn_passthrough

  Sets the Point-to-Point Tunneling Protocol (PPTP) VPN
  passthrough control flag.

  @datatypes
  qmi_error_type_v01

  @param[in] enable           Sets the PPTP VPN passthrough control flag.
  @param[out] qmi_err_num     Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetPPTPVpnPassthrough_Ipv6
(
  boolean enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetPPTPVpnPassthrough_Ipv6()
===========================================================================*/
/** @ingroup qcmap_get_pptp_vpn_passthrough

  Gets the PPTP VPN passthrough control flag.

  @datatypes
  qmi_error_type_v01

  @param[out] enable          Gets the PPTP VPN passthrough control flag.
  @param[out] qmi_err_num     Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetPPTPVpnPassthrough_Ipv6
(
  boolean *enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetL2TPVpnPassthrough_Ipv6()
===========================================================================*/
/** @ingroup qcmap_set_l2tp_vpn_passthrough

  Sets the Layer 2 Tunneling Protocol (L2TP) VPN passthrough control flag.

  @datatypes
  qmi_error_type_v01

  @param[in] enable           Sets the L2TP VPN passthrough control flag
  @param[out] qmi_err_num     Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetL2TPVpnPassthrough_Ipv6
(
  boolean enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetL2TPVpnPassthrough_Ipv6()
===========================================================================*/
/** @ingroup qcmap_get_l2tp_vpn_passthrough

  Gets the L2TP VPN passthrough control flag.

  @datatypes
  qmi_error_type_v01

  @param[out] enable          Gets the L2TP VPN passthrough control flag
  @param[out] qmi_err_num     Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetL2TPVpnPassthrough_Ipv6
(
  boolean *enable,
  qmi_error_type_v01 *qmi_err_num
);


/*===========================================================================
FUNCTION SetWebserverWWANAccess()
===========================================================================*/
/** @ingroup qcmap_set_webserver_wwan_access

  Sets whether or not the webserver can be accessed from the WWAN
  interface. The command handler overwrites any previously
  configured value with the current value.

  @datatypes
  qmi_error_type_v01

  @param[in] enable           Sets the web server WWAN access flag.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetWebserverWWANAccess
(
  boolean enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetWebserverWWANAccess()
===========================================================================*/
/** @ingroup qcmap_get_webserver_wwan_access

  Queries the webserver WWAN access status on the device.

  @datatypes
  qmi_error_type_v01

  @param[out] enable         Gets the web server WWAN access status.
  @param[out] qmi_err_num    Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetWebserverWWANAccess
(
  boolean *enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetNatType()
===========================================================================*/
/** @ingroup qcmap_set_nat_type

  Sets the NAT type on the device. The command
  handler overwrites any previously configured value with the current value.

  @datatypes
  qcmap_msgr_nat_enum_v01\n
  qmi_error_type_v01

  @param[in] nat_type      Sets the NAT type.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetNatType
(
  qcmap_msgr_nat_enum_v01 nat_type,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetNatType()
===========================================================================*/
/** @ingroup qcmap_get_nat_type

  Gets the configured NAT type.

  @datatypes
  qcmap_msgr_nat_enum_v01 \n
  qmi_error_type_v01

  @param[out] nat_type      Gets the NAT type.
  @param[out] qmi_err_num   Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetNatType
(
  qcmap_msgr_nat_enum_v01 *nat_type,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetAutoconnect()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Sets the Auto Connect flag, which is then updated in the
  configuration file by the Connection Manager. This enables the
  QCMobileAP to connect to the backhaul after the QCMobileAP is
  enabled and to retry to connect to the backhaul on failure.

  @datatypes
  qmi_error_type_v01

  @param[in]  enable       Sets the auto connect flag.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/
boolean
SetAutoconnect
(
  boolean enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetAutoconnect()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets the status of the auto connect flag.

  @datatypes
  qmi_error_type_v01

  @param[out] enable        Gets the auto connect control flag status.
  @param[out] qmi_err_num   Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetAutoconnect
(
  boolean *enable,
  qmi_error_type_v01 *qmi_err_num
);


/*===========================================================================
  FUNCTION GetBackhaulStatus()
  ===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  If connected, gets the backahul status, backhaul type, and IP version.

  @datatypes
  qcmap_backhaul_status_info_type \n
  qmi_error_type_v01

  @param[out] backhaul_status_info  Gets the current active backhaul type and
                                    IP version.
  @param[out] qmi_err_num           Pointer to the error code returned by the
                                    server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
 */
boolean GetBackhaulStatus
(
  qcmap_backhaul_status_info_type *backhaul_status_info,
  qmi_error_type_v01 *qmi_err_num
);


/*===========================================================================
FUNCTION SetRoaming()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Sets the roaming flag.

  The roaming flag is then updated in the configuration file by the
  Connection Manager. This enables the QCMobileAP to connect to the network
  in roaming mode.

  @datatypes
  qmi_error_type_v01

  @param[in]  enable          Sets the roaming flag.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetRoaming
(
  boolean enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetRoaming()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets the status of the roaming flag.

  @datatypes
  qmi_error_type_v01

  @param[out] enable          Gets the status of the roaming flag.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetRoaming
(
  boolean *enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetNetworkConfiguration()
===========================================================================*/
/** @ingroup qcmap_get_network_configuration

  Gets the network configuration.

  @datatypes
  qcmap_msgr_ip_family_enum_v01 \n
  qcmap_nw_params_t \n
  qmi_error_type_v01

  @param[in]  ip_family         IP family for which to get the configuration.
  @param[out] qcmap_nw_params   Network configuration, such as public IP, and
                                primary and secondary DNS IP addresses.
  @param[out] qmi_err_num       Pointer to the error code returned by the
                                server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetNetworkConfiguration
(
  qcmap_msgr_ip_family_enum_v01 ip_family,
  qcmap_nw_params_t *qcmap_nw_params,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetIPv4NetworkConfiguration()
===========================================================================*/
/** @ingroup qcmap_get_ipv4_network_configuration

  Gets the IPv4 network configuration.

  @datatypes
  qmi_error_type_v01

  @param[out] public_ip      Public IP address.
  @param[out] primary_dns    Primary DNS IP address.
  @param[out] secondary_dns  Secondary DNS IP address.
  @param[out] qmi_err_num    Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetIPv4NetworkConfiguration
(
  in_addr_t *public_ip,
  uint32 *primary_dns,
  in_addr_t *secondary_dns,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetIPv6NetworkConfiguration()
===========================================================================*/
/** @ingroup qcmap_get_ipv6_network_configuration

  Gets the IPV6 configuration.

  @datatypes
  qmi_error_type_v01

  @param[out] public_ip      Public IP address.
  @param[out] primary_dns    Primary DNS IP address.
  @param[out] secondary_dns  Secondary DNS IP address.
  @param[out] qmi_err_num    Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetIPv6NetworkConfiguration
(
  struct in6_addr    *public_ip,
  struct in6_addr    *primary_dns,
  struct in6_addr    *secondary_dns,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetNatTimeout()
===========================================================================*/
/** @ingroup qcmap_set_nat_timeout

  Sets different NAT timeouts on the device. The command
  handler overwrites any previously configured value with the current value.

  @datatypes
  qcmap_msgr_nat_timeout_enum_v01 \n
  qmi_error_type_v01

  @param[in] timeout_type      NAT timeout type for which the timeout is
                               to be set.
  @param[in] timeout_value     Timeout value.
  @param[out] qmi_err_num      Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetNatTimeout
(
  qcmap_msgr_nat_timeout_enum_v01 timeout_type,
  uint32 timeout_value,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetNatTimeout()
===========================================================================*/
/** @ingroup qcmap_get_nat_timeout

  Gets the NAT timeout value configured for the NAT type.

  @datatypes
  qcmap_msgr_nat_timeout_enum_v01 \n
  qmi_error_type_v01

  @param[in]  timeout_type     NAT timeout type for which the timeout is
                               to be fetched.
  @param[out] timeout_value    Timeout value.
  @param[out] qmi_err_num      Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetNatTimeout
(
  qcmap_msgr_nat_timeout_enum_v01 timeout_type,
  uint32 *timeout_value,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetFireWallHandlesList()
===========================================================================*/
/** @ingroup qcmap_get_fire_wall_handles_list

  Gets all the firewall handles associated with a single
  MobileAP instance.

  @datatypes
  qcmap_msgr_get_firewall_handle_list_conf_t \n
  qmi_error_type_v01

  @param[out] handlelist     Gets the list of firewall handles.
  @param[out] qmi_err_num    Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/

boolean
GetFireWallHandlesList
(
  qcmap_msgr_get_firewall_handle_list_conf_t *handlelist,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION AddFireWallEntry()
===========================================================================*/
/** @ingroup qcmap_add_fire_wall_entry

  Adds the firewall rule, which is then updated in
  the configuration file by the Connection Manager

  @datatypes
  qcmap_msgr_firewall_conf_t\n
  qmi_error_type_v01

  @param[in] extd_firewall_entry  Sets the firewall rule.
  @param[out] qmi_err_num         Pointer to the error code returned by the
                                  server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
AddFireWallEntry
(
  qcmap_msgr_firewall_conf_t *extd_firewall_entry,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION AddUPNPPinholeEntry()
===========================================================================*/
/** @ingroup qcmap_add_upnp_pinhole_entry

  Adds a UPNP pinhole entry.

  @datatypes
  qcmap_msgr_firewall_conf_t\n
  qmi_error_type_v01

  @param[in]  extd_firewall_entry   Sets the UPNP pinhole entry.
  @param[out] qmi_err_num           Pointer to the error code returned by
                                    the server.
  @param[in]  upnp_pinhole          Indicates whether to add the pinhole entry.


  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
AddUPNPPinholeEntry
(
  qcmap_msgr_firewall_conf_t *extd_firewall_entry,
  qmi_error_type_v01 *qmi_err_num,
  boolean upnp_pinhole = false
);

/*===========================================================================
FUNCTION GetFireWallEntry()
===========================================================================*/
/** @ingroup qcmap_get_fire_wall_entry

  Gets a firewall rule associated with a single firewall handle.

  @datatypes
  qcmap_msgr_firewall_entry_conf_t \n
  qmi_error_type_v01

  @param[in,out] firewall_entry  Gets the firewall entry pointed to by the
                                 handle requested.
  @param[out] qmi_err_num        Pointer to the error code returned by the
                                 server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetFireWallEntry
(
  qcmap_msgr_firewall_entry_conf_t *firewall_entry,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DeleteFireWallEntry()
===========================================================================*/
/** @ingroup qcmap_delete_fire_wall_entry

  Deletes the firewall rule pointed by the handle, which is
  then updated by the Connection Manager in the configuration file.

  @datatypes
  qmi_error_type_v01

  @param[in]  handle          Deletes the handle that points to the firewall.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
int
DeleteFireWallEntry
(
  int handle,
  qmi_error_type_v01  *qmi_err_num
);

/*===========================================================================
FUNCTION GetMobileAPStatus()
===========================================================================*/
/** @ingroup qcmap_get_mobile_ap_status

  Gets the QCMobileAP status.

  @datatypes
  qcmap_msgr_mobile_ap_status_enum_v01 \n
  qmi_error_type_v01

  @param[out] status         Gets the QCMobileAP status.
  @param[out] qmi_err_num    Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetMobileAPStatus
(
  qcmap_msgr_mobile_ap_status_enum_v01 *status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetWWANStatus()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets the status of the WWAN connection.

  @datatypes
  qcmap_msgr_wwan_status_enum_v01 \n
  qcmap_msgr_wwan_status_enum_v01 \n
  qmi_error_type_v01

  @param[out] v4_status    Gets WWAN connection status for the IPv4 call type.
  @param[out] v6_status    Gets WWAN connection status for the IPv6 call type.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/
boolean
GetWWANStatus
(
  qcmap_msgr_wwan_status_enum_v01 *v4_status,
  qcmap_msgr_wwan_status_enum_v01 *v6_status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetStationModeStatus()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wlan

  Gets the status of the WLAN station mode connection.

  @datatypes
  qcmap_msgr_station_mode_status_enum_v01 \n
  qmi_error_type_v01

  @param[out] status       Gets WLAN station mode connection status.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetStationModeStatus
(
  qcmap_msgr_station_mode_status_enum_v01 *status,
  qmi_error_type_v01 *qmi_err_num
);

/*=====================================sec======================================
FUNCTION SetFirewall()
===========================================================================*/
/** @ingroup qcmap_set_firewall

  Enables or disables the firewall and sets the configuration to
  drop or accept the packets matching the rules.

  @datatypes
  qmi_error_type_v01

  @param[in] enable_firewall  Indicates whether the firewall is enabled.
  @param[in] pkts_allowed     Indicates whether to accept or drop packets
                              matching the rules.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetFirewall
(
  boolean enable_firewall,
  boolean pkts_allowed,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetFirewall()
===========================================================================*/
/** @ingroup qcmap_get_firewall

  Gets the firewall configuration. This function indicates whether the firewall
  is enabled or disabled and whether the firewall is configured to drop or
  accept the packets matching the rules.

  @datatypes
  qmi_error_type_v01

  @param[out] enable_firewall   Indicates whether the firewall is enabled.
  @param[out] pkts_allowed      Indicates whether to accept or drop packets
                                matching the rules.
  @param[out] qmi_err_num       Pointer to the error code returned by the
                                server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetFirewall
(
  boolean *enable_firewall,
  boolean *pkts_allowed,
  qmi_error_type_v01 *qmi_err_num
);


/*=====================================sec======================================
FUNCTION SetUPNPState()
===========================================================================*/
/** @ingroup qcmap_set_upnp_state

  Enables or disables the UPNP pinhole.

  @datatypes
  qmi_error_type_v01

  @param[in] firewall_state      Indicates whether the firewall is enabled.
  @param[in] upnp_pinhole_flag   Indicates whether to enable or disable the
                                 UPNP pinhole.
  @param[out] qmi_err_num        Pointer to the error code returned by the
                                 server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/

boolean
SetUPNPState
(
  boolean firewall_state,
  boolean upnp_pinhole_flag,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetUPNPState()
===========================================================================*/
/** @ingroup qcmap_get_upnp_state

  Gets the pinhole state.

  @datatypes
  qmi_error_type_v01

  @param[out] upnp_pinhole_flag    Indicates whether the pinhole is enabled.
  @param[out] qmi_err_num          Pointer to the error code returned by the
                                   server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetUPNPState
(
  boolean *upnp_pinhole_flag,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetIPv4State()
===========================================================================*/
/** @ingroup qcmap_get_ipv4_state

  Gets the current IPv4 state.

  @datatypes
  qmi_error_type_v01

  @param[out] ipv4_state   Indicates whether IPv4 is enabled.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetIPv4State
(
  boolean *ipv4_state,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetIPv6State()
===========================================================================*/
/** @ingroup qcmap_get_ipv6_state

  Gets the current IPv6 state.

  @datatypes
  qmi_error_type_v01

  @param[out] ipv6_state   Indicates whether IPv6 is enabled.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetIPv6State
(
  boolean            *ipv6_state,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetWWANPolicy()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets the current configured WWAN policy.

  @datatypes
  qcmap_msgr_net_policy_info_v01 \n
  qmi_error_type_v01

  @param[out] WWAN_config  WWAN policy configured in the XML file.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetWWANPolicy
(
  qcmap_msgr_net_policy_info_v01  *WWAN_config,
  qmi_error_type_v01              *qmi_err_num
);

/*===========================================================================
FUNCTION GetWWANPolicyList()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets all configured WWAN policy.

  @datatypes
  qcmap_msgr_wwan_policy_list_resp_msg_v01\n
  qmi_error_type_v01

  @param[out] WWAN_config       WWAN policy configured in the XML file.
  @param[out] qmi_err_num       Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean GetWWANPolicyList
(
  qcmap_msgr_wwan_policy_list_resp_msg_v01   *WWAN_policy,
  qmi_error_type_v01                         *qmi_err_num
 );


/*===========================================================================
FUNCTION SetWWANPolicy()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Configures the WWAN policy.

  @datatypes
  qcmap_msgr_net_policy_info_v01 \n
  qmi_error_type_v01

  @param[in] WWAN_config       WWAN policy information to be configured.
  @param[out] qmi_err_num      Pointer to the error code returned by the
                               server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  -# QCMobileAP must be enabled.
  -# It is recommended to use same WWAN profile index for both
     IPv4 and IPv6 data calls, intended for Internet or default PDN.
 @newpage
*/
boolean
SetWWANPolicy
(
  qcmap_msgr_net_policy_info_v01  WWAN_config,
  qmi_error_type_v01             *qmi_err_num
);

/*===========================================================================
FUNCTION CreateWWANPolicy()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Creates a WWAN policy.

  @datatypes
  qcmap_msgr_net_policy_info_v01 \n
  qmi_error_type_v01

  @param[in] WWAN_config     Sets the WWAN policy information.
  @param[out] qmi_err_num    Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/
boolean
CreateWWANPolicy
(
  qcmap_msgr_net_policy_info_v01   WWAN_policy,
  qmi_error_type_v01              *qmi_err_num
);

/*===========================================================================
FUNCTION UpdateWWANPolicy()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Updates WWAN policy.

  @datatypes
  qcmap_msgr_update_profile_enum_v01 \n
  qcmap_msgr_net_policy_info_v01 \n
  qmi_error_type_v01

  @param[in] update_req      Policy field to be modified.
  @param[in] WWAN_config     Sets the WWAN policy information.
  @param[out] qmi_err_num    Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/
boolean
UpdateWWANPolicy
(
  qcmap_msgr_update_profile_enum_v01 update_req,
  qcmap_msgr_net_policy_info_v01     WWAN_policy,
  qmi_error_type_v01                *qmi_err_num
);

/*===========================================================================
FUNCTION DeleteWWANPolicy()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Deletes WWAN policy.

  @datatypes
  profile_handle\n
  qmi_error_type_v01

  @param[in]  profile_handle  Identifies profile_handle.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DeleteWWANPolicy
(
   qmi_error_type_v01       *qmi_err_num
);

/*===========================================================================
FUNCTION EnableUPNP()
===========================================================================*/
/** @ingroup qcmap_enable_upnp

  Enables the Universal Plug and Play (UPnP) daemon, unless it is already
  running.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
EnableUPNP
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DisableUPNP()
===========================================================================*/
/** @ingroup qcmap_disable_upnp

  Disables the UPnP daemon, if it is running.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num   Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
DisableUPNP
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetUPNPStatus()
===========================================================================*/
/** @ingroup qcmap_get_upnp_status

  Returns the status of the UPnP daemon.

  @datatypes
  qcmap_msgr_upnp_mode_enum_v01 \n
  qmi_error_type_v01

  @param[out] upnp_status   Gets the UPnP status.
  @param[out] qmi_err_num   Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetUPNPStatus
(
  qcmap_msgr_upnp_mode_enum_v01 *upnp_status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION EnableDLNA()
===========================================================================*/
/** @ingroup qcmap_enable_dlna

  Enables the Digital Living Network Alliance (DLNA) daemon,
  unless it is already running

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
EnableDLNA
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DisableDLNA()
===========================================================================*/
/** @ingroup qcmap_disable_dlna

  Disables the DLNA daemon, if it is running.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
DisableDLNA
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetDLNAStatus()
===========================================================================*/
/** @ingroup qcmap_get_dlna_status

  Returns the status of the DLNA daemon.

  @datatypes
  qcmap_msgr_dlna_mode_enum_v01 \n
  qmi_error_type_v01

  @param[out] dlna_status  Gets the DLNA status.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetDLNAStatus
(
  qcmap_msgr_dlna_mode_enum_v01 *dlna_status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetDLNAMediaDir()
===========================================================================*/
/** @ingroup qcmap_get_dlna_media_dir

  Returns the DLNA media directory.

  @datatypes
  qmi_error_type_v01

  @param[out] media_dir    Gets the DLNA media directory path.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetDLNAMediaDir
(
  char media_dir[],
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetDLNAMediaDir()
===========================================================================*/
/** @ingroup qcmap_set_dlna_media_dir

  Sets the DLNA media directory.

  @datatypes
  qmi_error_type_v01

  @param[in] media_dir        Sets the DLNA media directory.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetDLNAMediaDir
(
  char media_dir[],
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION EnableMDNS()
===========================================================================*/
/** @ingroup qcmap_enable_mdns

  Enables the Multicast DNS (MDNS) responder for QCMAP.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
EnableMDNS
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DisableMDNS()
===========================================================================*/
/** @ingroup qcmap_disable_mdns

  Disables the MDNS responder for QCMAP.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
DisableMDNS
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetMDNSStatus()
===========================================================================*/
/** @ingroup qcmap_get_mdns_status

  Returns the status of the Multicast DNS mode.

  @datatypes
  qcmap_msgr_mdns_mode_enum_v01 \n
  qmi_error_type_v01

  @param[out] mdns_status  MDNS status.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetMDNSStatus
(
  qcmap_msgr_mdns_mode_enum_v01 *mdns_status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetQCMAPBootupCfg()
===========================================================================*/
/** @ingroup qcmap_set_qcmap_bootup_cfg

  Sets the MobileAP boot-up configuration.

  @datatypes
  qcmap_msgr_bootup_flag_v01 \n
  qcmap_msgr_bootup_flag_v01 \n
  qmi_error_type_v01

  @param[in] mobileap_enable  Sets flag to indicate MobileAP bringup at bootup.
  @param[in] wlan_enable      Sets flag to indicate WLAN bringup at bootup.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetQCMAPBootupCfg
(
  qcmap_msgr_bootup_flag_v01 mobileap_enable,
  qcmap_msgr_bootup_flag_v01 wlan_enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetQCMAPBootupCfg()
===========================================================================*/
/** @ingroup qcmap_get_qcmap_bootup_cfg

  Gets the MobileAP boot-up configuration.

  @datatypes
  qcmap_msgr_bootup_flag_v01 \n
  qcmap_msgr_bootup_flag_v01 \n
  qmi_error_type_v01

  @param[out] mobileap_enable  Gets flag to indicate MobileAP bringup at bootup.
  @param[out] wlan_enable      Gets flog to indicate WLAN bringup at bootup.
  @param[out] qmi_err_num      Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetQCMAPBootupCfg
(
  qcmap_msgr_bootup_flag_v01 *mobileap_enable,
  qcmap_msgr_bootup_flag_v01 *wlan_enable,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetDataRate()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets the current and maximum transmit and receive data rates.

  @datatypes
  qcmap_msgr_data_bitrate_v01 \n
  qmi_error_type_v01

  @param[out] data_rate    Gets Tx and Rx current and maximum data rates in bps.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetDataRate
(
  qcmap_msgr_data_bitrate_v01 *data_rate,
  qmi_error_type_v01 *qmi_err_num
);


/*===========================================================================
FUNCTION SetUPNPNotifyInterval()
===========================================================================*/
/** @ingroup qcmap_set_upnp_notify_interval

  Sets the UPnP notify interval.

  @datatypes
  qmi_error_type_v01

  @param[in] notify_int       Sets notify interval in seconds.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetUPNPNotifyInterval
(
  int notify_int,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetUPNPNotifyInterval()
===========================================================================*/
/** @ingroup qcmap_get_upnp_notify_interval

  Gets the UPnP notify interval.

  @datatypes
  qmi_error_type_v01

  @param[out] notify_int      Gets notify interval in seconds.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetUPNPNotifyInterval
(
  int *notify_int,
  qmi_error_type_v01 *qmi_err_num
);

/* Set/Get the DLNA SSDP notify interval rate */
/*===========================================================================
FUNCTION SetDLNANotifyInterval()
===========================================================================*/
/** @ingroup qcmap_set_dlna_notify_interval

  Sets the DLNA notify interval.

  @datatypes
  qmi_error_type_v01

  @param[in] notify_int       Sets notify interval in seconds.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetDLNANotifyInterval
(
  int notify_int,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetDLNANotifyInterval()
===========================================================================*/
/** @ingroup qcmap_get_dlna_notify_interval

  Gets the DLNA notify interval.

  @datatypes
  qmi_error_type_v01

  @param[out] notify_int      Gets notify interval in seconds.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetDLNANotifyInterval
(
  int *notify_int,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION AddDHCPReservRecord()
===========================================================================*/
/** @ingroup qcmap_add_dhcp_reserv_record

  Adds a DHCP reservation record.

  @datatypes
  qcmap_msgr_dhcp_reservation_v01 \n
  qmi_error_type_v01

  @param[in]  dhcp_reserv_record  Sets a DHCP reservation record.
  @param[out] qmi_err_num         Pointer to the error code returned by the
                                  server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
AddDHCPReservRecord
(
  qcmap_msgr_dhcp_reservation_v01 *dhcp_reserv_record,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetDHCPReservRecords()
===========================================================================*/
/** @ingroup qcmap_get_dhcp_reserv_records

  Gets all the configured DHCP reservation records.

  @datatypes
  qcmap_msgr_dhcp_reservation_v01 \n
  qmi_error_type_v01

  @param[out] dhcp_reserv_record       Gets DHCP reservation records.
  @param[out] num_entries              Number of DHCP reservation records.
  @param[out] qmi_err_num              Pointer to the error code returned by
                                       the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetDHCPReservRecords
(
  qcmap_msgr_dhcp_reservation_v01 *dhcp_reserv_record,
  uint32_t *num_entries,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION EditDHCPReservRecord()
===========================================================================*/
/** @ingroup qcmap_edit_dhcp_reserv_record

  Edits an already configured DHCP reservation record.

  @datatypes
  qcmap_msgr_dhcp_reservation_v01 \n
  qmi_error_type_v01

  @param[in] addr                     IP address used as an index in the DHCP
                                      reservation record list.
  @param[in] dhcp_reserv_record       Modifies a DHCP reservation record.
  @param[out] qmi_err_num             Pointer to the error code returned by
                                      the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
EditDHCPReservRecord
(
  uint32_t *addr,
  qcmap_msgr_dhcp_reservation_v01 *dhcp_reserv_record,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DeleteDHCPReservRecord()
===========================================================================*/
/** @ingroup qcmap_delete_dhcp_reserv_record

  Deletes a DHCP reservation record.

  @datatypes
  qmi_error_type_v01

  @param[in] addr           IP address used to index into the DHCP
                            reservation record list.
  @param[out] qmi_err_num   Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DeleteDHCPReservRecord
(
  uint32_t *addr,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION EnableAlg()
===========================================================================*/
/** @ingroup qcmap_enable_alg

  Enables Application Level Gateways (ALGs) specified in the bitmask at
  runtime.

  @datatypes
  qcmap_msgr_alg_type_mask_v01 \n
  qmi_error_type_v01

  @param[in] alg_types     Enables bitmask indicating the ALGs to be loaded.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
EnableAlg
(
  qcmap_msgr_alg_type_mask_v01 alg_types,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DisableAlg()
===========================================================================*/
/** @ingroup qcmap_disable_alg

  Disables the ALGs specified in the bitmask at runtime.

  @datatypes
  qcmap_msgr_alg_type_mask_v01 \n
  qmi_error_type_v01

  @param[in] alg_types     Disables bitmask indicating the algorithms to be
                           loaded.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DisableAlg
(
  qcmap_msgr_alg_type_mask_v01 alg_types,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetSIPServerInfo()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Sets the default SIP server information in the QCMAP server,
  which is propagated to the LAN clients through DHCP.

  @datatypes
  qcmap_msgr_sip_server_info_v01 \n
  qmi_error_type_v01

  @param[in] sip_server_info  Sets the default SIP server information.
  @param[out] qmi_err_num     Pointer to the error codee returned by the
                              server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None. @newpage
*/
boolean
SetSIPServerInfo
(
  qcmap_msgr_sip_server_info_v01 *sip_server_info,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetSIPServerInfo()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Obtains the default SIP server information and the network assigned SIP
  server information from the QCMAP server.

  @datatypes
  qcmap_msgr_sip_server_info_v01 \n
  qmi_error_type_v01

  @param[out] default_sip_info         Gets default SIP server information.
  @param[out] network_sip_info         Network assigned SIP server information.
  @param[out] count_network_sip_info   Number of network assigned SIP servers
                                       returned.
  @param[out] qmi_err_num              Pointer to the error code returned by
                                       the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None. @newpage
*/
boolean
GetSIPServerInfo
(
  qcmap_msgr_sip_server_info_v01 *default_sip_info,
  qcmap_msgr_sip_server_info_v01 *network_sip_info,
  int *count_network_sip_info,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetV6SIPServerInfo()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan


  Sends a QMI message to the QCMAP server to get the V6SIP server information.
  This function populates the necessary fields for the
  QMI_QCMAP_MSGR_GET_IPV6_SIP_SERVER_INFO_REQ request.

  @datatypes
  qcmap_msgr_ipv6_sip_server_info_v01 \n
  qmi_error_type_v01

  @param[out] network_v6_sip_info     Gets network V6 assigned SIP server
                                      information.
  @param[out] count_network_sip_info  Number of network V6 assigned SIP
                                      servers returned.
  @param[out] qmi_err_num             Pointer to the error code returned by
                                      the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetV6SIPServerInfo
(
  qcmap_msgr_ipv6_sip_server_info_v01 *network_v6_sip_info,
  int *count_network_sip_info,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION RestoreFactoryConfig()
===========================================================================*/
/** @ingroup qcmap_restore_factory_config

  Restores the QCMAP configuration to a factory default state
  and reboots the device.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
RestoreFactoryConfig
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetConnectedDevicesInfo()
===========================================================================*/
/** @ingroup qcmap_get_connected_devices_info

  Gets information about the connected LAN hosts.

  LAN hosts include both USB and WLAN clients. The information includes the
  MAC address, IP address, host name, and lease expiry time.

  @datatypes
  qcmap_msgr_connected_device_info_v01\n
  qmi_error_type_v01

  @param[out] conn_dev_info     Gets connected device information from
                                the server.
  @param[out] num_entries       Number of entries.
  @param[out] qmi_err_num       Pointer to the error code returned by the
                                server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetConnectedDevicesInfo
(
  qcmap_msgr_connected_device_info_v01 *conn_dev_info,
  int *num_entries,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetSupplicantConfig()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wlan

  Activates and deactivates the WPA supplicant and WPA CLI based on the
  supplicant configuration status flag.

  @datatypes
  qmi_error_type_v01

  @param[out] status       Gets flag indicating whether to activate or
                           deactivate the WPA supplicant.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean SetSupplicantConfig
(
  boolean status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetCradleMode()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_cradle

  Gets the current cradle mode configured on the device.

  @datatypes
  qcmap_msgr_cradle_mode_v01 \n
  qmi_error_type_v01

  @param[out] mode         Gets the cradle mode.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None. @newpage
*/
boolean
GetCradleMode
(
  qcmap_msgr_cradle_mode_v01 *mode,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetCradleMode()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_cradle

  Configures a new cradle mode unless the mode is already set.

  @datatypes
  qcmap_msgr_cradle_mode_v01 \n
  qmi_error_type_v01

  @param[in] mode          Sets the cradle mode.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetCradleMode
(
  qcmap_msgr_cradle_mode_v01 mode,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetPrefixDelegationConfig()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets whether the prefix delegation configuration is enabled or disabled.

  @datatypes
  qmi_error_type_v01

  @param[out] pd_mode      Gets the prefix delegation configuration.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetPrefixDelegationConfig
(
  boolean *pd_mode,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetPrefixDelegationConfig()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Sets the prefix delegation configuration.

  @datatypes
  qmi_error_type_v01

  @param[in] pd_mode       Sets the prefix delegation configuration.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetPrefixDelegationConfig
(
  boolean pd_mode,
  qmi_error_type_v01 *qmi_err_num
);

/*====================================================================
FUNCTION GetPrefixDelegationStatus()
=====================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets the current prefix delegation mode.

  @datatypes
  qmi_error_type_v01

  @param[out] pd_mode      Gets the prefix delegation mode.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetPrefixDelegationStatus
(
  boolean *pd_mode,
  qmi_error_type_v01 *qmi_err_num
);

/*====================================================================
FUNCTION SetGatewayUrl()
=====================================================================*/
/** @ingroup qcmap_set_gateway_url

  Sets the default gateway URL for the access point.

  @datatypes
  qmi_error_type_v01

  @param[in] url           Sets the URL.
  @param[in] url_len       Sets the URL length.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetGatewayUrl
(
  uint8_t *url,
  uint32_t url_len,
  qmi_error_type_v01 *qmi_err_num
);

/*====================================================================
FUNCTION GetGatewayUrl()
=====================================================================*/
/** @ingroup qcmap_get_gateway_url

  Gets the default gateway URL for the access point.

  @datatypes
  qmi_error_type_v01

  @param[out] url             Gets the URL.
  @param[out] url_len         Gets the URL length.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetGatewayUrl
(
  uint8_t *url,
  uint32_t *url_len,
  qmi_error_type_v01 *qmi_err_num
);

/*====================================================================
FUNCTION EnableDDNS()
=====================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Enables dynamic DNS, which updates the IP address of the name
  server in the Domain Name System.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
EnableDDNS
(
  qmi_error_type_v01 *qmi_err_num
);

/*====================================================================
FUNCTION DisableDDNS()
=====================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Disables the dynamic DNS service.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None. @newpage
*/
boolean
DisableDDNS
(
  qmi_error_type_v01 *qmi_err_num
);

/*====================================================================
FUNCTION SetDDNSConfig()
=====================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Sets the dynamic DNS configuration.

  @datatypes
  qcmap_msgr_set_dynamic_dns_config_req_msg_v01 \n
  qmi_error_type_v01

  @param[in] setddns_cfg_req       Sets the required dynamic DNS
                                   configuration
  @param[out] qmi_err_num          Pointer to the error code returned by
                                   the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetDDNSConfig
(
  qcmap_msgr_set_dynamic_dns_config_req_msg_v01 *setddns_cfg_req,
  qmi_error_type_v01 *qmi_err_num
);

/*====================================================================
FUNCTION GetDDNSConfig()
=====================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets the current dynamic DNS configuration.

  @datatypes
  qcmap_msgr_get_dynamic_dns_config_resp_msg_v01\n
  qmi_error_type_v01

  @param[in] ddns_server     Gets the dynamic DNS configuration.
  @param[out] qmi_err_num    Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetDDNSConfig
(
  qcmap_msgr_get_dynamic_dns_config_resp_msg_v01 *ddns_server,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetTinyProxyStatus()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Returns the status of the Tiny Proxy.

  @datatypes
  qcmap_msgr_tiny_proxy_mode_enum_v01 \n
  qmi_error_type_v01

  @param[out] tiny_proxy_status  Tiny Proxy status.
  @param[out] qmi_err_num        Pointer to the error code returned by the
                                 server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/

boolean
 GetTinyProxyStatus(qcmap_msgr_tiny_proxy_mode_enum_v01 *tiny_proxy_status,
                                    qmi_error_type_v01 *qmi_err_num);


/*====================================================================
FUNCTION EnableTinyProxy()
=====================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Enables Tiny Proxy.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean EnableTinyProxy(qmi_error_type_v01 *qmi_err_num);

/*====================================================================
FUNCTION DisableTinyProxy()
=====================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Disables the Tiny Proxy.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None. @newpage
*/

boolean DisableTinyProxy(qmi_error_type_v01 *qmi_err_num);

/*====================================================================
FUNCTION SetDLNAWhitelisting()
=====================================================================*/
/** @ingroup qcmap_set_dlna_whitelisting

  Sets the DLNA whitelisting state.

  @datatypes
  qmi_error_type_v01

  @param[in] dlna_whitelisting_allow       Sets the whitelisting IP state.
  @param[out] qmi_err_num                  Pointer to the error code
                                           returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/

boolean SetDLNAWhitelisting(boolean dlna_whitelisting_allow,
qmi_error_type_v01 *qmi_err_num);

/*====================================================================
FUNCTION GetDLNAWhitelisting()
=====================================================================*/
/** @ingroup qcmap_get_dlna_whitelisting

  Gets the DLNA whitelisting state.

  @datatypes
  qmi_error_type_v01

  @param[out] dlna_whitelisting_allow     Gets the whitelisting IP state.
  @param[out] qmi_err_num                 Pointer to the error code returned
                                          by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/

boolean GetDLNAWhitelisting(boolean *dlna_whitelisting_allow,
qmi_error_type_v01 *qmi_err_num);

/*====================================================================
FUNCTION AddDLNAWhitelistIP()
=====================================================================*/
/** @ingroup qcmap_add_dlna_whitelist_ip

  Adds the DLNA whitelisting IP.

  @datatypes
  qmi_error_type_v01

  @param[in] dlna_whitelisting_ip       Adds a DLNA whitelisting IP.
  @param[out] qmi_err_num               Pointer to the error code returned
                                        by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/


boolean AddDLNAWhitelistIP(uint32 dlna_whitelisting_ip ,
qmi_error_type_v01 *qmi_err_num);

/*====================================================================
FUNCTION DeleteDLNAWhitelistIP()
=====================================================================*/
/** @ingroup qcmap_delete_dlna_whitelist_ip

  Deletes the DLNA whitelisting IP.

  @datatypes
  qmi_error_type_v01

  @param[in] dlna_whitelisting_ip       Deletes a DLNA whitelisting IP.
  @param[out] qmi_err_num               Pointer to the error code returned
                                        by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/

boolean DeleteDLNAWhitelistIP(uint32 dlna_whitelisting_ip,
qmi_error_type_v01 *qmi_err_num);

/*====================================================================
FUNCTION SetActiveBackhaulPref()
=====================================================================*/
/** @ingroup section_qcmap_backhaul_pref

  Sets the backhaul preference.

  @datatypes
  qcmap_msgr_set_backhaul_pref_req_msg_v01 \n
  qmi_error_type_v01

  @param[in] backhaul_pref_req   Sets the backhaul preference.
  @param[out] qmi_err_num        Pointer to the error code returned
                                 by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetActiveBackhaulPref
(
  backhaul_pref_t *backhaul_pref_req,
  qmi_error_type_v01 *qmi_err_num
);

/*====================================================================
FUNCTION GetBackhaulPref()
=====================================================================*/
/** @ingroup section_qcmap_backhaul_pref

  Gets the backhaul preference.

  @datatypes
  qcmap_msgr_backhaul_type_enum_v01
  qmi_error_type_v01

  @param[in] resp            Gets the backhaul preference.
  @param[out] qmi_err_num    Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetBackhaulPref
(
  backhaul_pref_t *resp,
  qmi_error_type_v01 *qmi_err_num
);
/*===========================================================================
FUNCTION GetEthernetMode()
===========================================================================*/
/** @ingroup section_backhaul_ethernet_mode

  Gets the current Ethernet mode configured on the device.

  @datatypes
  qcmap_msgr_eth_mode_v01 \n
  qmi_error_type_v01

  @param[out] mode         Gets the Ethernet backhaul mode. \n
  @values
  - QCMAP_MSGR_ETH_BACKHAUL_LAN_ROUTER \n
  - QCMAP_MSGR_ETH_BACKHAUL_WAN_BRIDGE (currently not supported.) \n
  - QCMAP_MSGR_ETH_BACKHAUL_WAN_ROUTER @tablebulletend
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
  @newpage
*/
boolean
GetEthernetMode
(
  qcmap_msgr_ethernet_mode_v01 *mode,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetEthernetMode()
===========================================================================*/
/** @ingroup section_backhaul_ethernet_mode

  Configures a new Ethernet mode unless the mode is already set.

  @datatypes
  qcmap_msgr_ethernet_mode_v01 \n
  qmi_error_type_v01

  @param[in] mode               Sets the Ethernet backhaul mode. \n
  @values
  -  ETH tethering in LAN mode. \n
  -  ETH tethering in WAN router mode. @tablebulletend
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetEthernetMode
(
  qcmap_msgr_ethernet_mode_v01 mode,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetIPPassthroughConfig()
===========================================================================*/
/** @ingroup qcmap_set_ip_passthrough_config

  IP passthrough functionality enables the tethered client to get the WWAN interface IP.

  As part of this functionality, the existing private IP is not deleted from the bridge interface.
  Instead, another public IP, which is the WWAN interface gateway IP is added to the bridge interface.
  This allows support for embedded application concurrency with the passthrough client.

  The WWAN interface is assigned a private IP. This API sets the IP passthrough flag and
  configuration for a tethered client (USB or Ethernet).

  When the flag is set to FALSE, IP passthrough is deactivated.

  When the flag is set to TRUE, there is a provision for reusing or overwriting the previously
  used configuration of the tethered client.
  The XML is updated with the information provided via this API.
  Even if the flag is set to TRUE in XML,
  IP passthrough is activated only when all required conditions are met.

  @datatypes
  qcmap_msgr_ip_passthrough_mode_enum_v01 \n
  qcmap_msgr_ip_passthrough_config_v01 \n
  qmi_error_type_v01

  @param[in] enable_state              Sets IP passthrough enable state. \n
  @values
  - QCMAP_MSGR_IP_PASSTHROUGH_MODE_DOWN_V01 \n
  - QCMAP_MSGR_IP_PASSTHROUGH_MODE_UP_V01 @tablebulletend
  @param[in] new_config                Use new or existing configuration.
  @param[in] ip_passthrough_config     IP passthrough configuration.
  @param[out] qmi_err_num              Pointer to the error code returned by
                                       the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetIPPassthroughConfig
(
  qcmap_msgr_ip_passthrough_mode_enum_v01 enable_state,
  bool new_config,
  qcmap_msgr_ip_passthrough_config_v01 *ip_passthrough_config,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetIPPassthroughConfig()
===========================================================================*/
/** @ingroup qcmap_get_ip_passthrough_config

  Gets the current IP passthrough flag and configuration from XML.

  @datatypes
  qcmap_msgr_ip_passthrough_mode_enum_v01 \n
  qcmap_msgr_ip_passthrough_config_v01 \n
  qmi_error_type_v01

  @param[out] enable_state             Gets current state of IP passthrough. \n
  @values
  - QCMAP_MSGR_IP_PASSTHROUGH_MODE_DOWN_V01 \n
  - QCMAP_MSGR_IP_PASSTHROUGH_MODE_UP_V01 @tablebulletend
  @param[out] ip_passthrough_config    IP passthrough configuration.
  @param[out] qmi_err_num              Pointer to the error code returned by
                                       the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetIPPassthroughConfig
(
  qcmap_msgr_ip_passthrough_mode_enum_v01 *enable_state,
  qcmap_msgr_ip_passthrough_config_v01 *ip_passthrough_config,
  qmi_error_type_v01 * qmi_err_num
);

/*===========================================================================
FUNCTION GetIPPassthroughState()
===========================================================================*/
/** @ingroup qcmap_get_ip_passthrough_state

  Gets the IP passthrough current active state. Even if the flag is set to TRUE in XML,
  IP passthrough may not be in the Active state if the required conditions are not met.

  @datatypes
  qmi_error_type_v01

  @param[out] state                  Gets current active state of IP passthrough.
  @param[out] qmi_err_num            Pointer to the error code returned by
                                     the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean GetIPPassthroughState
(
  boolean *state,
  qmi_error_type_v01 *qmi_err_num
);


/*====================================================================
FUNCTION BringupBTTethering()
=====================================================================*/
/** @ingroup section_qcmap_backhaul_bt_tethering

  Brings up Bluetooth tethering from the QCMAP side.

  This API is called by the QCMAP client BT PAN module.

  The Bluetooth PAN module calls this API when the first Bluetooth client is
  connected. A call to this API brings up the Bluetooth interface, adds
  to the bridge interface, and assigns a private IP to the Bluetooth
  interface.

  @datatypes
  qmi_error_type_v01 \n
  qcmap_bt_tethering_mode_enum_v01

  @param[out] qmi_err_num        Point to the error code returned by the
  server.
  @param[out] bt_tethering_mode  Calls the Bluetooth tethering mode. \n
  @values
  - QCMAP_MSGR_BT_MODE_LAN_V01 \n
  - QCMAP_MSGR_BT_MODE_WAN_V01 @tablebulletend

  @return
  - TRUE -- Success. \n
  - FALSE -- Failure.

  @dependencies
  None. @newpage
*/
boolean BringupBTTethering
(
  qmi_error_type_v01 *qmi_err_num,
  qcmap_bt_tethering_mode_enum_v01 bt_tethering_mode = QCMAP_MSGR_BT_MODE_LAN_V01
);

/*====================================================================
FUNCTION BringdownBTTethering()
=====================================================================*/
/** @ingroup section_qcmap_backhaul_bt_tethering

  Brings down Bluetooth tethering from the QCMAP side.

  The QCMAP client Bluetooth PAN module calls this API when no Bluetooth
  client is connected. A call to this API brings the Bluetooth interface
  down and removes the changes from the bringup Bluetooth tethering.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None. @newpage
*/
boolean BringdownBTTethering(qmi_error_type_v01 *qmi_err_num);

/*===========================================================================
FUNCTION GetBTTetheringStatus()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_bt_tethering

  Gets the Bluetooth tethering status.

  This API is called  by the QCMAP client BT PAN module
  to check the Bluetooth tethering status.

  @datatypes
  qcmap_msgr_bt_tethering_status_enum_v01 \n
  qmi_error_type_v01 \n
  qcmap_bt_tethering_mode_enum_v01

  @param[out] bt_teth_status  Gets the Bluetooth tethering status. \n
  @values
  - QCMAP_MSGR_BT_TETHERING_MODE_UP_V01 \n
  - QCMAP_MSGR_BT_TETHERING_MODE_DOWN_V01 @tablebulletend
  @param[out] qmi_err_num     Point to the error code returned by the server.
  @param[out] bt_teth_mode    Gets the Bluetooth tethering mode. \n
  @values
  - QCMAP_MSGR_BT_MODE_LAN_V01 \n
  - QCMAP_MSGR_BT_MODE_WAN_V01 @tablebulletend

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None. @newpage
*/
boolean GetBTTetheringStatus
(
  qcmap_msgr_bt_tethering_status_enum_v01 *bt_teth_status,
  qmi_error_type_v01 *qmi_err_num,
  qcmap_bt_tethering_mode_enum_v01 *bt_teth_mode = NULL
);

/*===========================================================================
FUNCTION SetInitialPacketLimit()
===========================================================================*/
/** @ingroup qcmap_set_initial_packet_limit

  Sets the packet threshold count to delay the time for the initial
  packets to flow through HW or SFE path. Until the packet threshold is reached
  packets take the software path.


  @datatypes
  qmi_error_type_v01

  @param[in] pkt_limit     Sets the packet limit value.
  @param[out] qmi_err_num  The pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/
  boolean SetInitialPacketLimit
  (
     uint32 pkt_limit,
     qmi_error_type_v01 *qmi_err_num
  );

/*===========================================================================
FUNCTION GetInitialPacketLimit()
===========================================================================*/
/** @ingroup qcmap_get_initial_packet_limit

  Gets the packet threshold count to delay the time for the initial
  packets to flow through HW or SFE path.

  @datatypes
  qmi_error_type_v01

  @param[out] pkt_limit    Gets the packet limit value.
  @param[out] qmi_err_num  The pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/

boolean GetInitialPacketLimit
(
    uint32 *pkt_limit,
    qmi_error_type_v01 *qmi_err_num
);

/*====================================================================
FUNCTION EnableSOCKSv5Proxy()
=====================================================================*/
/** @ingroup section_qcmap_socksv5_proxy

  Enables the SOCKSv5 proxy.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean EnableSOCKSv5Proxy(qmi_error_type_v01 *qmi_err_num);

/*====================================================================
FUNCTION DisableSOCKSv5Proxy()
=====================================================================*/
/** @ingroup section_qcmap_socksv5_proxy

  Disables the SOCKSv5 proxy.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/

boolean DisableSOCKSv5Proxy(qmi_error_type_v01 *qmi_err_num);

/*===========================================================================
FUNCTION GetSOCKSv5Config()
===========================================================================*/
/** @ingroup section_qcmap_socksv5_proxy

  Prints the SOCKSv5 proxy configuration parameters.

  @datatypes
  socksv5_configuration \n
  qmi_error_type_v01

  @param[out] configuration  Gets the proxy configuration parameters.
  @param[out] qmi_err_num    Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/

boolean GetSOCKSv5Config(socksv5_configuration *configuration, qmi_error_type_v01 *qmi_err_num);

/*===========================================================================
FUNCTION SetSOCKSv5Config()
===========================================================================*/
/** @ingroup section_qcmap_socksv5_proxy

  Sets the SOCKSv5 proxy configuration parameters.

  @datatypes
  qcmap_socksv5_config_type_v01 \n
  qmi_error_type_v01

  @param[out] config        Deletes the existing proxy configuration parameters.
  @param[in]  config_type   Sets the proxy configuration parameters.
  @param[out] qmi_err_num   Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/

boolean SetSOCKSv5Config(void *config, qcmap_socksv5_config_type_v01 config_type,
                         qmi_error_type_v01 *qmi_err_num);

/*===========================================================================
FUNCTION EnablePacketStats()
===========================================================================*/
/** @ingroup  qcmap_enable_packet_stats

  Enable the packet statistics.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean EnablePacketStats
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DisablePacketStats()
===========================================================================*/
/** @ingroup  qcmap_disable_packet_stats

  Disables the packet statistics.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean DisablePacketStats
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION ResetPacketStats()
===========================================================================*/
/** @ingroup  qcmap_reset_packet_stats

  Resets the packet statistics.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num   Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean ResetPacketStats
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetPacketStatsStatus()
===========================================================================*/
/** @ingroup  qcmap_packet_stats_status

  Gets the packet statistics state.

  @datatypes
  qcmap_msgr_packet_stats_status_enum_v01 \n
  qmi_error_type_v01

  @param[out] status           Gets the packets statistics state.
  @param[out] qmi_err_num      Pointer to the error code returned by the
                               server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean GetPacketStatsStatus
(
  qcmap_msgr_packet_stats_status_enum_v01* status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetVLANConfig()
===========================================================================*/
/** @ingroup section_vlan_config

  Sets the VLAN configuration.

  @datatypes
  qcmap_msgr_vlan_config_v01 \n
  qmi_error_type_v01

  @param[in]  vlan_config       Sets the VLAN configuration.
  @param[out] qmi_err_num       Pointer to the error code returned by the
                                server.
  @param[out] is_ipa_offloaded  IPA offload status returned by server

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None. @newpage
*/
boolean
SetVLANConfig
(
  qcmap_msgr_vlan_config_v01 vlan_config,
  qmi_error_type_v01 *qmi_err_num,
  bool *is_ipa_offloaded
);

/*===========================================================================
FUNCTION GetVLANConfig()
===========================================================================*/
/** @ingroup section_vlan_config

  Gets the current VLAN configuration.

  @datatypes
  qcmap_msgr_vlan_conf_t \n
  qmi_error_type_v01

  @param[out] vlan_config  Gets the VLAN configuration.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetVLANConfig
(
  qcmap_msgr_vlan_conf_t *vlan_config,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DeleteVLANConfig()
===========================================================================*/
/** @ingroup section_vlan_config

  Deletes the current VLAN configuration.

  @datatypes
  qcmap_msgr_vlan_config_v01 \n
  qmi_error_type_v01

  @param[in] vlan_config   Deletes the VLAN configuration.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
DeleteVLANConfig
(
  qcmap_msgr_vlan_config_v01 vlan_config,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetUnmanagedL2TPState()
===========================================================================*/
/** @ingroup qcmap_set_unmanaged_l2tp_state

  Sets the L2TP enable and disable configuration for unmanaged tunnels.
  If MTU to be configured, use SetUnmanagedL2TPStateEx api, else the following
  default API will be used which sets the default MTU calculated.

  @datatypes
  qcmap_msgr_set_unmanaged_l2tp_state_config_v01 \n
  qcmap_msgr_l2tp_mtu_config_v01 \n
  qcmap_msgr_l2tp_TCP_MSS_config_v01 \n
  qmi_error_type_v01

  @param[in] l2tp_enable_config  Sets configuration to enable or disable L2TP.
  @param[in] MTU_config          Sets configuration to enable or disable MTU.
  @param[in] TCP_MSS_config      Sets configuration to enable or disable
                                 TCP MSS.
  @param[out] qmi_err_num        Pointer to the error code returned by the
                                 server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetUnmanagedL2TPState
(
  qcmap_msgr_set_unmanaged_l2tp_state_config_v01 l2tp_enable_config,
  qcmap_msgr_l2tp_mtu_config_v01                 MTU_config,
  qcmap_msgr_l2tp_TCP_MSS_config_v01             TCP_MSS_config,
  qmi_error_type_v01                            *qmi_err_num
);

/*===========================================================================
FUNCTION SetUnmanagedL2TPStateEx()
=============================================================================
  Sets the L2TP enable and disable configuration for unmanaged tunnels.

  @datatypes
  qcmap_msgr_set_l2tp_config \n
  qmi_error_type_v01

  @param[in] l2tp_enable_config  Sets configuration to enable or disable L2TP
                                 Tunnels/MSS config/MTU config.
  @param[out] qmi_err_num        Pointer to the error code returned by the
                                 server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetUnmanagedL2TPStateEx
(
  qcmap_set_l2tp_config            l2tp_config,
  qmi_error_type_v01              *qmi_err_num
);

/*===========================================================================
FUNCTION SetL2TPConfig()
===========================================================================*/
/** @ingroup qcmap_set_l2tp_config

  Sets the L2TP tunnel configuration by setting the MTU size on underlying interfaces.

  @datatypes
  qcmap_msgr_l2tp_mode_enum_v01 \n
  qcmap_msgr_l2tp_config_v01 \n
  qmi_error_type_v01

  @param[in]  mode         Sets the L2TP mode of operation. \n
   @values
   - local_tunnel_id \n
   - peer_tunnel_id \n
   - local_iface[QCMAP_MAX_IFACE_NAME_SIZE_V01] \n
   - ip_family \n
   - peer_ipv6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01] \n
   - peer_ipv4_addr \n
   - proto \n
   - local_udp_port \n
   - peer_tunnel_id @tablebulletend
  @param[in]  l2tp_config  Sets the L2TP configuration. \n
   @values session_config[QCMAP_MSGR_L2TP_MAX_SESSION_PER_TUNNEL_V01]
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
SetL2TPConfig
(
  qcmap_msgr_l2tp_mode_enum_v01 mode,
  qcmap_msgr_l2tp_config_v01 l2tp_config,
  qmi_error_type_v01 *qmi_err_num
);
/*===========================================================================
FUNCTION GetL2TPConfig()
===========================================================================*/
/** @ingroup qcmap_get_l2tp_config

  Gets the current L2TP configuration.

  @datatypes
  qcmap_msgr_l2tp_conf_t \n
  qmi_error_type_v01

  @param[out] l2tp_config  Gets the L2TP configuration.
    @values
  - local_tunnel_id \n
  - peer_tunnel_id \n
  - local_iface[QCMAP_MAX_IFACE_NAME_SIZE_V01] \n
  - ip_family \n
  - peer_ipv6_addr[QCMAP_MSGR_IPV6_ADDR_LEN_V01] \n
  - peer_ipv4_addr \n
  - proto \n
  - local_udp_port \n
  - peer_tunnel_id \n
  - mtu_size \n
  - session_config[QCMAP_MSGR_L2TP_MAX_SESSION_ PER_TUNNEL_V01] -- Session
  configuration @tablebulletend
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetL2TPConfig
(
  qcmap_msgr_l2tp_conf_t *l2tp_config,
  qmi_error_type_v01     *qmi_err_num
);

/*===========================================================================
FUNCTION DeleteL2TPTunnelConfig()
===========================================================================*/
/** @ingroup qcmap_delete_l2tp_tunnel_config

  Deletes the L2TP tunnel configuration.

  @datatypes
  qcmap_msgr_delete_l2tp_config_v01 \n
  qmi_error_type_v01

  @param[in]  l2tp_config  Deletes the current configuration.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
DeleteL2TPTunnelConfig
(
  qcmap_msgr_delete_l2tp_config_v01 l2tp_config,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION AddPDNToVLANMapping()
===========================================================================*/
/** @ingroup section_pdn_to_vlan_mapping

  Adds a PDN to the VLAN mapping.

  @datatypes
  profile_handle_type_v01 \n
  qmi_error_type_v01

  @param[in]  vlan_id         Sets the VLAN ID.
  @param[in]  profile_handle  Sets the PDN.
  @param[out] qmi_err_num     Point to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None. @newpage
*/
boolean AddPDNToVLANMapping(int16_t vlan_id, profile_handle_type_v01 profile_handle,
                            qmi_error_type_v01 *qmi_err_num);

/*===========================================================================
FUNCTION DeletePDNToVLANMapping()
===========================================================================*/
/** @ingroup section_pdn_to_vlan_mapping

  Deletes a PDN from the VLAN mapping.

  @datatypes
  profile_handle_type_v01 \n
  qmi_error_type_v01
  @param[in]  vlan_id         Sets the VLAN ID.
  @param[in]  profile_handle  Deletes the PDN.
  @param[out] qmi_err_num     Pointer to the error code returned by the
                              server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None. @newpage
*/
boolean DeletePDNToVLANMapping(int16_t vlan_id, profile_handle_type_v01 profile_handle,
                            qmi_error_type_v01 *qmi_err_num);

/*===========================================================================
FUNCTION GetPDNtoVLANMappings()
===========================================================================*/
/** @ingroup section_pdn_to_vlan_mapping

  Gets a list of all PDN to VLAN mappings.

  @datatypes
  qcmap_msgr_pdn_to_vlan_mapping_v01 \n
  qmi_error_type_v01

  @param[out] pdn_vlan_mappings  The VLAN mapping for the PDNs.
  @param[out] num_entries        Number of PDNs.
  @param[out] qmi_err_num        Pointer to the error code returned by the
                                 server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean GetPDNtoVLANMappings
(
  qcmap_msgr_pdn_to_vlan_mapping_v01 *pdn_vlan_mappings,
  int *num_entries,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION EnableGSB()
===========================================================================*/
/** @ingroup qcmap_enable_gsb

  Enables the GSB. This function loads a generic software bridge kernel module
  and sends the configuration to GSB.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
EnableGSB
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DisableGSB()
===========================================================================*/
/** @ingroup qcmap_disable_gsb

  Disables the GSB. This function unloads a generic software bridge kernel module.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DisableGSB
(
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetGSBConfig()
===========================================================================*/
/** @ingroup qcmap_set_gsb_config

  Sets the GSB configuration.

  @datatypes
  qcmap_msgr_gsb_config_v01
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetGSBConfig
(
  qcmap_msgr_gsb_config_v01 *config,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetGSBConfig()
===========================================================================*/
/** @ingroup qcmap_get_gsb_config

  Gets the GSB configuration.

  @datatypes
  qcmap_msgr_gsb_config_v01
  num_of_entries
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
GetGSBConfig
(
  qcmap_msgr_gsb_config_v01 *config,
  uint8 *num_of_entries,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION DeleteGSBConfig()
===========================================================================*/
/** @ingroup qcmap_delete_gsb_config

  Deletes the configuration stored for GSB.

  @datatypes
  qmi_error_type_v01

  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
DeleteGSBConfig
(
  char* if_name,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetDunDongleMode()
===========================================================================*/
/** @ingroup qcmap_set_dun_dongle_mode

  Sets the DUN dongle mode.

  @datatypes
  qmi_error_type_v01

  @param[in]  dun_dongle_mode_state  Sets the DUN dongle mode.
  @param[out] qmi_err_num            Pointer to the error code returned by
                                     the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/
boolean
SetDunDongleMode

(
  boolean dun_dongle_mode_state,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetDunDongleMode()
===========================================================================*/
/** @ingroup qcmap_get_dun_dongle_mode

  Gets the status of the DUN dongle mode.

  @datatypes
  qmi_error_type_v01

  @param[out] dun_dongle_mode_status  Gets the DUN dongle mode status.
  @param[out] qmi_err_num             Pointer to the error code returned by
                                      the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetDunDongleMode

(
  boolean *dun_dongle_mode_status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetDataPathOptStatus()
===========================================================================*/
/** @ingroup qcmap_get_data_path_opt_status

  Gets the status of the data path optimizer. It is either enabled or
  disabled.

  @datatypes
  qmi_error_type_v01

  @param[out]  data_path_opt_status  Gets the data path optimizer status.
  @param[out]  qmi_err_num           Pointer to the error code returned by
                                     the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/

boolean
GetDataPathOptStatus
(
  boolean *data_path_opt_status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetDataPathOptStatus()
===========================================================================*/
/** @ingroup qcmap_set_data_path_opt_status

  Enable or disable the data path optimizer.

  @datatypes
  qmi_error_type_v01

  @param[in]  data_path_opt_status  Sets the data path optimizer.
  @param[out] qmi_err_num           Pointer to the error code returned by
                                    the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/

boolean
SetDataPathOptStatus
(
  boolean data_path_opt_status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetPMIPMode()
===========================================================================*/
/** @ingroup qcmap_get_pmip_mode

  Gets the PMIP mode and configuration.

  @datatypes
  qcmap_msgr_get_pmip_mode_resp_msg_v01 \n
  qmi_error_type_v01

  @param[out] get_pmip_mode_resp_msg  Pointer to the response message.
  @param[out] qmi_err_num             Pointer the error code returned by
                                      the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None. @newpage
*/
boolean GetPMIPMode
(
  qcmap_msgr_get_pmip_mode_resp_msg_v01 * get_pmip_mode_resp_msg,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION SetPMIPMode()
===========================================================================*/
/** @ingroup qcmap_set_pmip_mode

  Sets the PMIP mode and configuration.

  @datatypes
  qcmap_msgr_set_pmip_mode_req_msg_v01 \n
  qmi_error_type_v01

  @param[in] set_pmip_mode_req_msg  Sets the PMIP mode and configuration.
  @param[out] qmi_err_num           Pointer the error code returned by the
                                    server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean SetPMIPMode
(
  qcmap_msgr_set_pmip_mode_req_msg_v01 * set_pmip_mode_req_msg,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetWWANRoamStatus()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets current wwan roaming status

  @datatypes
  qmi_error_type_v01

  @param[out] wwan_roam_status  Gets the current roaming status. \n
  @values
  - QCMAP_MSGR_ROAM_STATUS_OFF_V01 \n
  - QCMAP_MSGR_ROAM_STATUS_ON_V01 \n
  - QCMAP_MSGR_ROAM_STATUS_BLINK_V01 \n
  - QCMAP_MSGR_ROAM_STATUS_OUT_OF_NEIGHBORHOOD_V01 \n
  - QCMAP_MSGR_ROAM_STATUS_OUT_OF_BLDG_V01 \n
  - QCMAP_MSGR_ROAM_STATUS_PREF_SYS_V01 \n
  - QCMAP_MSGR_ROAM_STATUS_AVAIL_SYS_V01 \n
  - QCMAP_MSGR_ROAM_STATUS_ALLIANCE_PARTNER_V01 \n
  - QCMAP_MSGR_ROAM_STATUS_PREMIUM_PARTNER_V01 \n
  - QCMAP_MSGR_ROAM_STATUS_FULL_SVC_V01 \n
  - QCMAP_MSGR_ROAM_STATUS_PARTIAL_SVC_V01 \n
  - QCMAP_MSGR_ROAM_STATUS_BANNER_ON_V01 \n
  - QCMAP_MSGR_ROAM_STATUS_BANNER_OFF_V01 @tablebulletend
  @param[out] qmi_err_num       Pointer to the error code returned by the
                                server.

  @return
  - TRUE -- Success. \n
  - FALSE -- Failure.

  @dependencies
  None. @newpage
*/
boolean
GetWWANRoamStatus
(
  uint8_t *wwan_roam_status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION ConnectBackHaulAsync()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Connects the Wireless Wide Area Network (WWAN) backhaul asynchronously. This
  function connects the WWAN based on the configuration provided.

  @datatypes
  qcmap_msgr_wwan_call_type_v01 \n
  profile_handle_type_v01 \n
  qmi_client_recv_msg_async_cb

  @param[in] call_type       Identifies call type, such as IPv4, IPv6, or both.
  @param[in] profile_handle  Modem profile number used for backhaul.
  @param[in] resp_cb         Asynchronous response callback for this request.
  @param[in] user_data       Cookie user data value supplied by the client.

  @return
   TRUE -- Success. \n
   FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/
boolean
ConnectBackHaulAsync
(
  qcmap_msgr_wwan_call_type_v01 call_type,
  profile_handle_type_v01  profile_handle,
  qmi_client_recv_msg_async_cb resp_cb,
  void *user_data
);

/*===========================================================================
FUNCTION DisconnectBackHaulAsync()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Disconnects the WWAN backhaul asynchronously.

  @datatypes
  qcmap_msgr_wwan_call_type_v01 \n
  profile_handle_type_v01 \n
  qmi_client_recv_msg_async_cb

  @param[in] call_type       Identifies call type, suchas IPv4, IPv6, or both.
  @param[in] profile_handle  Modem profile number used for backhaul.
  @param[in] resp_cb         Asynchronous response callback for this request.
  @param[in] user_data       Cookie user data value supplied by the client.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/
boolean
DisconnectBackHaulAsync
(
  qcmap_msgr_wwan_call_type_v01 call_type,
  profile_handle_type_v01  profile_handle,
  qmi_client_recv_msg_async_cb resp_cb,
  void *user_data
);

/*===========================================================================
FUNCTION CreateWWANPolicyAsync()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Creates WWAN policy asynchronously.

  @datatypes
  qcmap_msgr_net_policy_info_v01 \n
  qmi_client_recv_msg_async_cb

  @param[in] WWAN_policy       WWAN policy information to be configured.
  @param[in] resp_cb           Asynchronous response callback for this request.
  @param[in] user_data         Cookie user data value supplied by the client.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/
boolean
CreateWWANPolicyAsync
(
  qcmap_msgr_net_policy_info_v01   WWAN_policy,
  qmi_client_recv_msg_async_cb resp_cb,
  void *user_data
);

/*===========================================================================
FUNCTION GetWWANPolicyListAsync()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets all configured WWAN policy asynchronously.

  @datatypes
  qcmap_msgr_wwan_policy_list_resp_msg_v01

  @param[in] resp_cb    Asynchronous response callback for this request.
  @param[in] user_data  Cookie user data value supplied by the client.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean
GetWWANPolicyListAsync
(
  qmi_client_recv_msg_async_cb resp_cb,
  void *user_data
);

/*===========================================================================
FUNCTION GetLANBridges()
===========================================================================*/
/** @ingroup  qcmap_get_lan_bridges

  Gets a list of all configured LAN bridges.

  @datatypes
  qcmap_msgr_bridge_list_v01 \n
  qmi_error_type_v01

  @param[out] bridge_list  Gets a list of the LAN bridges.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean GetLANBridges(qcmap_msgr_bridge_list_v01* bridge_list,
                      qmi_error_type_v01* qmi_err_num);

/*===========================================================================
FUNCTION SelectLANBridges()
===========================================================================*/
/** @ingroup  qcmap_select_lan_bridges

  Sets the LAN bridge context for LAN configuration menu items.

  @datatypes
  qmi_error_type_v01

  @param[out] bridge_vlan_id  Sets the LAN bridge context.
  @param[out] qmi_err_num     Pointer to the error code returned by the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None.
*/
boolean SelectLANBridge(int16_t bridge_vlan_id, qmi_error_type_v01* qmi_err_num);


/*===========================================================================
FUNCTION SetAlwaysOnWLAN()
===========================================================================*/
/** @ingroup qcmap_set_always_on_wlan

  Sets the Always on WLAN setting to either enabled or disabled.

  @datatypes
  qmi_error_type_v01

  @param[in]  always_on_wlan_state  Sets the WLAN always on setting.
  @param[out] qmi_err_num           Pointer to the error code returned by the
                                    server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetAlwaysOnWLAN
(
  boolean always_on_wlan_state,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetAlwaysOnWLAN()
===========================================================================*/
/** @ingroup qcmap_get_always_on_wlan

  Gets the Always on WLAN setting status.

  @datatypes
  qmi_error_type_v01

  @param[out] always_on_wlan_status  Gets the Always on WLAN status.
  @param[out] qmi_err_num            Pointer to the error code return by the
                                     server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None
*/
boolean
GetAlwaysOnWLAN
(
  boolean *always_on_wlan_status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetWWANProfilePreference()
===========================================================================*/
/** @ingroup section_qcmap_backhaul_wwan

  Gets the WWAN profile preference.

  @datatypes
  profile_handle_type_v01 \n
  qmi_error_type_v01

  @param[out] current_profile_handle  Gets the current profile handle.
  @param[out] qmi_err_num             Pointer to the error code returned by
                                      the server.

  @return
  TRUE -- Success. \n
  FALSE -- Failure.

  @dependencies
  None
*/
boolean
GetWWANProfilePreference
(
  profile_handle_type_v01 *current_profile_handle,
  qmi_error_type_v01 *qmi_err_num
);


/*===========================================================================
FUNCTION set_p2p_role()
===========================================================================*/
/** @ingroup qcmap_set_p2p_role

  Sets the peer-to-peer (P2P) configuration. The p2p_status is set to enable or
  disable P2P role. The P2P role specifies whether it is a P2P Group Owner
  or P2P Client.

  @datatypes
  qcmap_p2p_config \n
  qmi_error_type_v01

  @param[in]  p2p_config   Sets the P2P configuration.
  @param[out] qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled. @newpage
*/
boolean
set_p2p_role
(
  qcmap_p2p_config p2p_config,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION get_p2p_role()
===========================================================================*/
/** @ingroup qcmap_get_p2p_role

  Gets the peer-to-peer (P2P) configuration. The functions shows if
  P2P role is enabled or disabled. The function also specifies whether the P2P
  role is a P2P Group Owner or a P2P Client.

  @datatypes
  qcmap_p2p_config \n
  qmi_error_type_v01

  @param[out]  p2p_config   Gets the P2P configuration.
  @param[out]  qmi_err_num  Pointer to the error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/

boolean
get_p2p_role
(
  qcmap_p2p_config* p2p_config,
  qmi_error_type_v01* qmi_err_num
);

/*===========================================================================
FUNCTION SetEarlyEthMode()
===========================================================================*/
/** @ingroup qcmap_set_early_ethernet_mode

  Set Early Ethernet mode.

  @datatypes
  qmi_error_type_v01

  @param[in]  enable          Sets the early ethernet mode.
  @param[out] qmi_err_num     Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
boolean
SetEarlyEthMode
(
  boolean early_eth_mode_status,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetEarlyEthMode()
===========================================================================*/
/** @ingroup qcmap_msgr_get_early_ethernet_mode

  Gets the status of the early ethernet mode.

  @datatypes
  qmi_error_type_v01

  @param[out] enable          Gets the early ethernet mode status.
  @param[out] qmi_err_num     Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  None
*/
boolean
GetEarlyEthMode
(
  boolean *early_eth_mode_status,
  qmi_error_type_v01 *qmi_err_num
);


/*===========================================================================
FUNCTION SetDeviceMode()
===========================================================================*/
/**
  Use to set device mode.

  @datatypes
  qmi_error_type_v01

  @param[out] device_mode                 Option of device mode
  @param[out] qmi_err_num                 Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @Dependencies
  QCMobileAP must be enabled.
*/

boolean
SetDeviceMode
(
  qcmap_msgr_device_mode_enum_v01 device_mode,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION GetDeviceMode()
===========================================================================*/
/**
  Use to get the device mode currently set.
  @datatypes
  qmi_error_type_v01

  @param [in] device_mode                Option of device mode
  @param[out] qmi_err_num                Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @Dependencies
  None
*/

boolean
GetDeviceMode

(
  qcmap_msgr_device_mode_enum_v01 *device_mode,
  qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
FUNCTION EnableTetheredLink()
===========================================================================*/
/**
  Enable's tethered link

  @datatypes
  boolean
  qmi_error_type_v01

  @param[in]  link_type             link to bring-up
  @param[in]  dev_id                dev_id for the link
  @param[out] qmi_err_num           Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
/*=========================================================================*/
boolean
EnableTetheredLink
(
  qcmap_msgr_usb_link_enum_v01        link_type,
  uint16                              dev_id,
  qmi_error_type_v01                 *qmi_err_num
);

/*===========================================================================
FUNCTION DisableTetheredLink()
===========================================================================*/
/**
  Enable's tethered link

  @datatypes
  boolean
  qmi_error_type_v01

  @param[in]  link_type             link to bring-down
  @param[in]  dev_id                dev_id for the link
  @param[out] qmi_err_num           Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
/*=========================================================================*/
boolean DisableTetheredLink
(
  qcmap_msgr_usb_link_enum_v01        link_type,
  uint16                              dev_id,
  qmi_error_type_v01                 *qmi_err_num
);

/*===========================================================================
FUNCTION GetIPAddressAssignment()
===========================================================================*/
/**
  Get IPv4 or IPv6 address for host on external AP.

  @datatypes
  boolean
  qmi_error_type_v01

  @param[in]   ip_family             IP Family for which assignment is required.
  @param[out]  resp_msg              Response Message
  @param[out]  qmi_err_num           Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
/*=========================================================================*/
boolean GetIPAddressAssignment
(
  qcmap_msgr_ip_family_enum_v01               ip_family,
  qcmap_msgr_get_ip_assignment_resp_msg_v01  *resp_msg,
  qmi_error_type_v01                         *qmi_err_num
);

/*===========================================================================
FUNCTION GetWWANDeviceName()
===========================================================================*/
/** @ingroup qcmap_msgr_get_wwan_device_name

  Get WWAN Device Name.

  @datatypes
  boolean
  qmi_error_type_v01

  @param[in]   ip_family             IP Family for which assignment is required.
  @param[out]  resp_msg              Response Message
  @param[out]  qmi_err_num           Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @dependencies
  QCMobileAP must be enabled.
*/
/*=========================================================================*/
boolean GetWWANIFaceName
(
  qcmap_msgr_ip_family_enum_v01                  ip_family,
  qcmap_msgr_get_wwan_iface_name_resp_msg_v01   *resp_msg,
  qmi_error_type_v01                            *qmi_err_num
);

/*===========================================================================
FUNCTION SetN79Config()
===========================================================================*/
/**
  Use to set n79 config;

  @datatypes
  qmi_error_type_v01

  @param[out] n79_config        N79 configuration
  @param[out] qmi_err_num       Error code returned by the server.

  @return
  TRUE upon success. \n
  FALSE upon failure.

  @Dependencies
  QCMobileAP must be enabled.
*/
/*=========================================================================*/
bool SetN79Config
(
  qcmap_msgr_n79_config_v01 n79_config,
  bool                      config_enable,
  qmi_error_type_v01        *qmi_err_num
);

/*===========================================================================
  FUNCTION GetN79Config
  ===========================================================================*/
/*!
  @brief
  Gets the current configured N79Configuration.

  @return
  true  - on Success
  false - on Failure

  @note

  - Dependencies
  - None

  - Side Effects
  - None
 */
/*=========================================================================*/
bool GetN79Config
(
  qcmap_msgr_n79_config_v01 *n79_config,
  boolean                   *config_enable,
  qmi_error_type_v01        *qmi_err_num
);

/*===========================================================================
  FUNCTION SetIPv6NAT
  ===========================================================================*/
/*!
  @brief
  Will enable/disable the IPv6 NAT

  @return
  true  - on Success
  false - on Failure

  @note

  - Dependencies
  - None

  - Side Effects
  - None
 */
/*=========================================================================*/
boolean SetIPv6NAT
(
   boolean enable,
   qcmap_msgr_nat_enum_v01 v6_nat_type,
   qmi_error_type_v01 *qmi_err_num
);

/*===========================================================================
  FUNCTION GetIPv6NAT
  ===========================================================================*/
/*!
  @brief
  Will get the IPv6 NAT value

  @return
  true  - on Success
  false - on Failure

  @note

  - Dependencies
  - None

  - Side Effects
  - None
 */
/*=========================================================================*/
boolean GetIPv6NAT(boolean *flag,qmi_error_type_v01 *qmi_err_num);

/*===========================================================================
  FUNCTION IsReady
  ===========================================================================*/
/*!
  @brief
  Check if QCMAP QMI Service is ready.

  @return
  true  - on Success
  false - on Failure

  @note

  - Dependencies
  - None

  - Side Effects
  - None
 */
/*=========================================================================*/
  boolean IsReady();

/*===========================================================================
  FUNCTION SetClientConfig
  ===========================================================================*/
/*!
  @brief
  Set Client configuration in Fusion Arch.

  @return
  true  - on Success
  false - on Failure

  @note

  - Dependencies
  - Client should be create in Fusion Arch

  - Side Effects
  - None
 */
/*=========================================================================*/
  boolean SetClientConfig
  (
    qcmap_client_config client_config, qmi_error_type_v01 *qmi_err_num
  );


  /*===========================================================================
  FUNCTION CreateVLANConfig()
  ===========================================================================*/
  /** @ingroup section_vlan_config

    Creates the VLAN configuration.

    @datatypes
    qcmap_msgr_vlan_config_ex_v01 \n
    qmi_error_type_v01

    @param[in]  vlan_config       Sets the VLAN configuration.
    @param[out] qmi_err_num       Pointer to the error code returned by the
                                  server.
    @param[out] is_accelerated    Is Accelerated returned by server

    @return
    TRUE -- Success. \n
    FALSE -- Failure.

    @dependencies
    None. @newpage
  */
  /*=========================================================================*/
  boolean CreateVLANConfig
  (
    qcmap_msgr_vlan_config_ex_v01   vlan_config,
    qmi_error_type_v01             *qmi_err_num,
    bool                           *is_accelerated
  );

  /*===========================================================================
    FUNCTION DeleteVLANConfig()
  ===========================================================================*/
  /** @ingroup section_vlan_config

    Delete's the current VLAN configuration.

    @datatypes
    int16_t \n
    qcmap_msgr_interface_type_enum_v01 \n
    qmi_error_type_v01

    @param[in] vlan_id       vlan_id of the configuration.
    @param[in] intf_type     Interface type of the configuration.
    @param[out] qmi_err_num  Pointer to the error code returned by the server.

    @return
    TRUE -- Success. \n
    FALSE -- Failure.

    @dependencies
    None.
  */
  /*=========================================================================*/
  boolean DeleteVLANConfig
  (
    int16_t                             vlan_id,
    qcmap_msgr_interface_type_enum_v01  intf_type,
    qmi_error_type_v01                 *qmi_err_num
  );

  /*===========================================================================
     FUNCTION GetBearerTech()
   ===========================================================================*/
   /** @ingroup section_qcmap_backhaul_wwan

   Gets the current bearer tech.

   @datatypes
   qcmap_msgr_data_bearer_tech_type_enum_v01 \n
   qmi_error_type_v01

   @param[out] bearer_tech     Bearer Tech is returned by the server.
   @param[out] qmi_err_num     Pointer to the error code returned by the server.

   @return
   TRUE -- Success. \n
   FALSE -- Failure.

   @dependencies
   None.
   */
  /*=========================================================================*/
  boolean GetBearerTech
  (
    qcmap_msgr_data_bearer_tech_type_enum_v01   *bearer_tech,
    qmi_error_type_v01                          *qmi_err_num
  );

  /*===========================================================================
    FUNCTION GetAllConnectedPDN()
  ===========================================================================*/
  /** @ingroup section_qcmap_backhaul_wwan

   Gets the current data bearer technology.

   @datatypes
   uint8 \n
   qcmap_msgr_wwan_info_ex_v01 \n
   qmi_error_type_v01

   @param[out] num_intf       Number of interfaces returned by the server.
   @param[out] wwan_info_ex   wwan_info returned by the server.
                              OEM App or User App needs to alloc sufficient memory
                              at least sizeof(qcmap_msgr_wwan_info_list) * QCMAP_MAX_NUM_BACKHAULS_V01
   @param[out] qmi_err_num    Pointer to the error code returned by the server.

   @return
   TRUE -- Success. \n
   FALSE -- Failure.

   @dependencies
   None.
  */
  /*=========================================================================*/
  boolean GetAllConnectedPDN
  (
    uint8                           *num_intf,
    qcmap_msgr_wwan_info_ex_v01     *wwan_info_ex,
    qmi_error_type_v01              *qmi_err_num
  );

  /*===========================================================================
    FUNCTION ProcessCV2XRequest()
  ===========================================================================*/
  /** @ingroup section_qcmap_cv2x

   Process CV2X non-call setup releated msgs.

   @datatypes
   qcmap_msgr_v2x_request_type_enum \n
   qcmap_v2x_request \n
   qcmap_v2x_response \n
   qmi_error_type_v01

   @param[in] qcmap_msgr_v2x_request_type_enum     CV2X Request Msg Type
   @param[in] req_msg                              CV2X request Msg
   @param[out] resp_msg                            CV2X response Msg returned by server
   @param[out] qmi_err_num  Pointer to the error code returned by the server.

   @return
   TRUE -- Success. \n
   FALSE -- Failure.

   @dependencies
   None.
  */
  /*=========================================================================*/
  boolean ProcessCV2XRequest
  (
    qcmap_msgr_v2x_request_type_enum_v01   v2x_req_type,
    qcmap_v2x_request                      v2x_request,
    qcmap_v2x_response                    *v2x_response,
    qmi_error_type_v01                    *qmi_err_num
  );
};

#endif  /* QCMAP_CLIENT_H */
