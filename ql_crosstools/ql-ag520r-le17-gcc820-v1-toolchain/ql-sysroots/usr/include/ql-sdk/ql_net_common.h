#ifndef __QL_NET_COMMON_H__
#define __QL_NET_COMMON_H__


/**  Maximum length of the APN name. */
#define QL_NET_MAX_APN_NAME_LEN   150

/**  Maximum length of the APN user name. */
#define QL_NET_MAX_APN_USERNAME_LEN   127

/**  Maximum length of the password. */
#define QL_NET_MAX_APN_PASSWORD_LEN   127

/**  Maximum address length. */
#define QL_NET_MAX_ADDR_LEN       46

#define QL_NET_MAX_DATA_CALL_NUM  16

/**  Maximum lenth of the device name. */
#define QL_NET_MAX_NAME_LEN         32
#define QL_NET_MAX_RECONNECT_INTERVAL_LEN  20
#define QL_NET_MAX_APN_ID                  16
#define QL_NET_USB_DEV_MAX_NUM             16

typedef enum {
  QL_NET_SRV_STATUS_MIN = 0,
  QL_NET_SRV_STATUS_NO_SERVICE = 0x01, 
  QL_NET_SRV_STATUS_OUT_OF_SERVICE = 0x02, 
  QL_NET_SRV_STATUS_IN_SERVICE = 0x03, 
  QL_NET_SRV_SRV_STATUS_MAX
} QL_NET_SRV_STATUS_E;
 
typedef enum {
  QL_NET_DATA_CALL_STATUS_MIN = -1,
  QL_NET_DATA_CALL_STATUS_NONE = 0x0,    /**< Call state is NONE     */
  QL_NET_DATA_CALL_STATUS_CREATED = 0x1, /**< Call state was created  */
  QL_NET_DATA_CALL_STATUS_IDLE = 0x2,    /**< Call state is IDLE.    */
  QL_NET_DATA_CALL_STATUS_CONNECTING = 0x3,           /**< Call is connecting.    */
  QL_NET_DATA_CALL_STATUS_PARTIAL_V4_CONNECTED = 0x4, /**< V4V6 mode, V4 is connected.  */
  QL_NET_DATA_CALL_STATUS_PARTIAL_V6_CONNECTED = 0x5, /**< V4V6 mode, V6 is connected.  */
  QL_NET_DATA_CALL_STATUS_CONNECTED = 0x6,            /**< Call is connected.     */
  QL_NET_DATA_CALL_STATUS_DISCONNECTED = 0x7,         /**< Call is disconnected.  */
  QL_NET_DATA_CALL_STATUS_ERROR = 0x8,                /**< Error ocurred   */
  QL_NET_DATA_CALL_STATUS_DELETED = 0x9,              /**< Data Call was deleted   */
  QL_NET_DATA_CALL_STATUS_MAX
} QL_NET_DATA_CALL_STATUS_E;

#define IS_QL_NET_DATA_CALL_STATUS_VALID(status) \
    ((status)>QL_NET_DATA_CALL_STATUS_MIN && (status)<QL_NET_DATA_CALL_STATUS_MAX)

typedef enum {
  QL_NET_DATA_CALL_RECONNECT_MODE_MIN = -1,
  QL_NET_DATA_CALL_RECONNECT_DISABLE = 0x0, 
  QL_NET_DATA_CALL_RECONNECT_NORMAL = 0x1, /**< Normal mode, interval defined by reconnect_interval[0] in sec  */
  QL_NET_DATA_CALL_RECONNECT_MODE_1 = 0x2, /**< Mode 1, time interval list defined by reconnect_interval in sec,
    if the time interval list is T1,T2,T3...Tn, the reconnection interval is T1,T2,T3...Tn,Tn,Tn...Tn  */
  QL_NET_DATA_CALL_RECONNECT_MODE_2 = 0x3, /**< Mode 2, time interval list defined by reconnect_interval in sec,
    if the time interval list is T1,T2,T3...Tn, the reconnection interval is T1,T2,T3..Tn,T1,T2,T3..Tn,T1..   */
  QL_NET_DATA_CALL_RECONONECT_MODE_MAX
} QL_NET_DATA_CALL_RECONNECT_MODE_E;

#define IS_QL_NET_DATA_CALL_RECONNECT_MODE_VALID(mode) \
    ((mode)>QL_NET_DATA_CALL_RECONNECT_MODE_MIN && (mode)<QL_NET_DATA_CALL_RECONONECT_MODE_MAX)

typedef enum {
  QL_NET_RAT_INFO_MIN = -1,
  QL_NET_RAT_INFO_NULL_BEARER = 0x0,  /**< NULL bearer   */
  QL_NET_RAT_INFO_3GPP_WCDMA = 0x1,   /**< 3GPP WCDMA      */
  QL_NET_RAT_INFO_3GPP_GERAN = 0x2,   /**< 3GPP GERAN   */
  QL_NET_RAT_INFO_3GPP_LTE = 0x3,     /**< 3GPP LTE   */
  QL_NET_RAT_INFO_3GPP_TDSCDMA = 0x4, /**< 3GPP TDSCDMA   */
  QL_NET_RAT_INFO_3GPP_WLAN = 0x5,    /**< 3GPP WLAN   */
  QL_NET_RAT_INFO_3GPP_MAX = 0x6,     /**< 3GPP maximum   */
  QL_NET_RAT_INFO_3GPP2_1X = 0x7,     /**< 3GPP2 1X   */
  QL_NET_RAT_INFO_3GPP2_HRPD = 0x8,   /**< 3GPP2 HRPD   */
  QL_NET_RAT_INFO_3GPP2_EHRPD = 0x9,  /**< 3GPP2 EHRPD   */
  QL_NET_RAT_INFO_3GPP2_WLAN = 0xA,   /**< 3GPP2 WLAN   */
  QL_NET_RAT_INFO_3GPP2_MAX = 0xB,    /**< 3GPP2 maximum   */
  QL_NET_RAT_INFO_WLAN = 0xC,         /**< WLAN   */
  QL_NET_RAT_INFO_WLAN_MAX = 0xD,     /**< WLAN maximum   */
  QL_NET_RAT_INFO_MAX
} QL_NET_RAT_INFO_E;

typedef enum {
  QL_NET_BEARER_TECH_TYPE_MIN = -1,
  QL_NET_BEARER_TECH_TYPE_UNKNOWN = 0x00, /**<  Unknown technology  */
  QL_NET_BEARER_TECH_TYPE_CDMA_1X = 0x01, /**<  1X technology.  */
  QL_NET_BEARER_TECH_TYPE_EVDO_REV0 = 0x02, /**<  CDMA Rev 0.  */
  QL_NET_BEARER_TECH_TYPE_EVDO_REVA = 0x03, /**<  CDMA Rev A.  */
  QL_NET_BEARER_TECH_TYPE_EVDO_REVB = 0x04, /**<  CDMA Rev B.  */
  QL_NET_BEARER_TECH_TYPE_EHRPD = 0x05, /**<  EHRPD.  */
  QL_NET_BEARER_TECH_TYPE_FMC = 0x06, /**<  Fixed mobile convergence.  */
  QL_NET_BEARER_TECH_TYPE_HRPD = 0x07, /**<  HRPD.  */
  QL_NET_BEARER_TECH_TYPE_3GPP2_WLAN = 0x08, /**<  IWLAN.  */
  QL_NET_BEARER_TECH_TYPE_WCDMA = 0x09, /**<  WCDMA.  */
  QL_NET_BEARER_TECH_TYPE_GPRS = 0x0A, /**<  GPRS.  */
  QL_NET_BEARER_TECH_TYPE_HSDPA = 0x0B, /**<  HSDPA.  */
  QL_NET_BEARER_TECH_TYPE_HSUPA = 0x0C, /**<  HSUPA.  */
  QL_NET_BEARER_TECH_TYPE_EDGE = 0x0D, /**<  EDGE.  */
  QL_NET_BEARER_TECH_TYPE_LTE = 0x0E, /**<  LTE.  */
  QL_NET_BEARER_TECH_TYPE_HSDPA_PLUS = 0x0F, /**<  HSDPA+.  */
  QL_NET_BEARER_TECH_TYPE_DC_HSDPA_PLUS = 0x10, /**<  DC HSDPA+.  */
  QL_NET_BEARER_TECH_TYPE_HSPA = 0x11, /**<  HSPA.  */
  QL_NET_BEARER_TECH_TYPE_64_QAM = 0x12, /**<  64 QAM.  */
  QL_NET_BEARER_TECH_TYPE_TDSCDMA = 0x13, /**<  TD-SCDMA.  */
  QL_NET_BEARER_TECH_TYPE_GSM = 0x14, /**<  GSM.  */
  QL_NET_BEARER_TECH_TYPE_3GPP_WLAN = 0x15, /**<  IWLAN.  */
  QL_NET_BEARER_TECH_TYPE_T_MAX_ENUM_VAL = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
} QL_NET_BEARER_TECH_TYPE_E;

typedef enum {
  QL_NET_IP_VER_MIN = -0,
  QL_NET_IP_VER_V4 = 0x1, 
  QL_NET_IP_VER_V6 = 0x2, 
  QL_NET_IP_VER_V4V6 = 0x3, 
  QL_NET_IP_VER_MAX
} QL_NET_IP_VER_E;

#define IS_QL_NET_IP_VER_VALID(ver) \
    ((ver)>QL_NET_IP_VER_MIN && (ver)<QL_NET_IP_VER_MAX)

typedef enum {
  QL_NET_AUTH_PREF_MIN = -1,
  QL_NET_AUTH_PREF_PAP_CHAP_NOT_ALLOWED = 0, 
  QL_NET_AUTH_PREF_PAP_ONLY_ALLOWED = 1, 
  QL_NET_AUTH_PREF_CHAP_ONLY_ALLOWED = 2, 
  QL_NET_AUTH_PREF_PAP_CHAP_BOTH_ALLOWED = 3, 
  QL_NET_AUTH_PREF_MAX
} QL_NET_AUTH_PREF_E;

#define IS_QL_NET_AUTH_PREF_VALID(pref) \
    ((pref)>QL_NET_AUTH_PREF_MIN && (pref)<QL_NET_AUTH_PREF_MAX)

typedef enum {
  QL_NET_USB_DEV_TYPE_MIN = 0,
  QL_NET_USB_DEV_TYPE_ECM = 1, 
  QL_NET_USB_DEV_TYPE_NCM = 2, 
  QL_NET_USB_DEV_TYPE_RNDIS = 3, 
  QL_NET_USB_DEV_TYPE_MBIM = 4, 
  QL_NET_USB_DEV_TYPE_MAX
} QL_NET_USB_DEV_TYPE_E;

typedef enum {
  QL_NET_USB_DEV_STATUS_MIN = -1,
  QL_NET_USB_DEV_STATUS_NONE = 0, 
  QL_NET_USB_DEV_STATUS_LINKDOWN = 1, 
  QL_NET_USB_DEV_STATUS_LINKUP = 2, 
  QL_NET_USB_DEV_STATUS_MAX
} QL_NET_USB_DEV_STATUS_E;

typedef enum {
  QL_NET_NF_CMD_FORMAT_MIN = -1,
  QL_NET_NF_CMD_FORMAT_COMMON = 0, 
  QL_NET_NF_CMD_FORMAT_JSON = 1, 
  QL_NET_NF_CMD_FORMAT_MAX
} QL_NET_NF_CMD_FORMAT_E;

typedef struct {
  char device[QL_NET_MAX_NAME_LEN];
  QL_NET_USB_DEV_TYPE_E type;
  QL_NET_USB_DEV_STATUS_E status;
  int8_t inst_id;
} ql_net_usb_dev_t;

typedef struct {
  char addr[QL_NET_MAX_ADDR_LEN];    /**< IPV4 address format string */
  char netmask[QL_NET_MAX_ADDR_LEN]; /**< Subnet mask, format */
  uint8_t subnet_bits;                     /**< Subnet mask bit number, exp:
                                            255.255.255.0 is 24, 255.255.0.0 is 16 */
  char gateway[QL_NET_MAX_ADDR_LEN]; /**< Gateway, IPV4 address*/
  char dnsp[QL_NET_MAX_ADDR_LEN];    /**< Primary DNS server address. */
  char dnss[QL_NET_MAX_ADDR_LEN];    /**< Secondary DNS server address. */
} ql_net_addr_t;

typedef struct 
{
  char addr[QL_NET_MAX_ADDR_LEN];    /**< IPV6 address format string */ 
  char prefix[QL_NET_MAX_ADDR_LEN];
  int32_t prefix_bits;
  char gateway[QL_NET_MAX_ADDR_LEN]; /**< Gateway address. */
  char dnsp[QL_NET_MAX_ADDR_LEN];    /**< Primary DNS server address. */
  char dnss[QL_NET_MAX_ADDR_LEN];    /**< Secondary DNS server address. */
} ql_net_addr6_t;


#endif

