/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_nw.h 
  @brief network registration API
*/
/*-----------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
  Copyright (c) 2019 Quectel Wireless Solution, Co., Ltd. All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
  EDIT HISTORY
  This section contains comments describing changes made to the file.
  Notice that changes are listed in reverse chronological order.
  $Header: $
  when       who          what, where, why
  --------   ---          ----------------------------------------------------------
  20200518   rambo.shan   Add WEA and ETWS alert indication.
  20191225   stan.li      Modify function description.
  20191202   stan.li      change the name of ql_nw_pref_nwmode_roming_info_t
  20190528   stan.li      Created .
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_NW_H__
#define __QL_NW_H__

#ifdef __cplusplus
extern "C" {
#endif


#define QL_NW_MODE_NONE    0x00    /**<  No network. */
#define QL_NW_MODE_GSM     0x01    /**<  Include GSM networks. */
#define QL_NW_MODE_WCDMA   0x02    /**<  Include WCDMA networks. */
#define QL_NW_MODE_CDMA    0x04    /**<  Include CDMA networks. */
#define QL_NW_MODE_EVDO    0x08    /**<  Include EVDO networks. */
#define QL_NW_MODE_LTE     0x10    /**<  Include LTE networks. */
#define QL_NW_MODE_TDSCDMA 0x20    /**<  Include TDSCDMA networks. */
#define QL_NW_MODE_PRL     0x10000 /**<  Give preference according to the preferred roaming list. */

#define QL_NW_NITZ_BUF_LEN      30
#define QL_NW_SCAN_MAX_LIST_NUM 40
#define QL_NW_MAX_GSM_CELL_INFO_NUM     20
#define QL_NW_MAX_UMTS_CELL_INFO_NUM    20
#define QL_NW_MAX_LTE_CELL_INFO_NUM     20

#define QL_NW_MAX_WEA_ALERT_LENGTH_V01  512
#define QL_NW_MAX_ETWS_ALERT_LENGTH_V01 256

typedef enum QL_NW_SIGNAL_STRENGTH_LEVEL_ENUM
{
    QL_NW_SIGNAL_STRENGTH_LEVEL_MIN             = -1,
    QL_NW_SIGNAL_STRENGTH_LEVEL_NONE            = 0,  /**<  none or unknown signal strength level */
    QL_NW_SIGNAL_STRENGTH_LEVEL_POOR            = 1,  /**<  poor     signal strength level */
    QL_NW_SIGNAL_STRENGTH_LEVEL_MODERATE        = 2,  /**<  moderate signal strength level */
    QL_NW_SIGNAL_STRENGTH_LEVEL_GOOD            = 3,  /**<  good     signal strength level */
    QL_NW_SIGNAL_STRENGTH_LEVEL_GREAT           = 4,  /**<  great    signal strength level */
    QL_NW_SIGNAL_STRENGTH_LEVEL_MAX
}QL_NW_SIGNAL_STRENGTH_LEVEL_E;

typedef enum QL_NW_ROAM_STATE_TYPE_ENUM
{
    QL_NW_ROAM_STATE_OFF  = 0,    /**<  None, or roaming indicator off. */
    QL_NW_ROAM_STATE_ON   = 1     /**<  Roaming indicator on. */
}QL_NW_ROAM_STATE_TYPE_E;

typedef enum QL_NW_NETWORK_STATUS_TYPE_ENUM
{
    QL_NW_NETWORK_STATUS_NONE            = 0,    /**<  Network status not available. */
    QL_NW_NETWORK_STATUS_CURRENT_SERVING = 1,    /**<  Current serving network. */
    QL_NW_NETWORK_STATUS_PREFERRED       = 2,    /**<  Preferred network. */
    QL_NW_NETWORK_STATUS_NOT_PREFERRED   = 3,    /**<  Not the preferred network. */
    QL_NW_NETWORK_STATUS_AVAILABLE       = 4,    /**<  Service available. */
    QL_NW_NETWORK_STATUS_FORBIDDEN       = 5     /**<  Forbidden service. */
}QL_NW_NETWORK_STATUS_TYPE_E;

typedef enum QL_NW_RADIO_TECH_TYPE_ENUM
{
    QL_NW_RADIO_TECH_TD_SCDMA = 1,
    QL_NW_RADIO_TECH_GSM      = 2,    /**<  GSM; only supports voice. */
    QL_NW_RADIO_TECH_HSPAP    = 3,    /**<  HSPA+. */
    QL_NW_RADIO_TECH_LTE      = 4,    /**<  LTE. */
    QL_NW_RADIO_TECH_EHRPD    = 5,    /**<  EHRPD. */
    QL_NW_RADIO_TECH_EVDO_B   = 6,    /**<  EVDO B. */
    QL_NW_RADIO_TECH_HSPA     = 7,    /**<  HSPA. */
    QL_NW_RADIO_TECH_HSUPA    = 8,    /**<  HSUPA. */
    QL_NW_RADIO_TECH_HSDPA    = 9,    /**<  HSDPA. */
    QL_NW_RADIO_TECH_EVDO_A   = 10,   /**<  EVDO A. */
    QL_NW_RADIO_TECH_EVDO_0   = 11,   /**<  EVDO 0. */
    QL_NW_RADIO_TECH_1xRTT    = 12,   /**<  1xRTT. */
    QL_NW_RADIO_TECH_IS95B    = 13,   /**<  IS95B. */
    QL_NW_RADIO_TECH_IS95A    = 14,   /**<  IS95A. */
    QL_NW_RADIO_TECH_UMTS     = 15,   /**<  UMTS. */
    QL_NW_RADIO_TECH_EDGE     = 16,   /**<  EDGE. */
    QL_NW_RADIO_TECH_GPRS     = 17,   /**<  GPRS. */
    QL_NW_RADIO_TECH_NONE     = 18    /**<  No technology selected. */
}QL_NW_RADIO_TECH_TYPE_E;

typedef enum QL_NW_TECH_DOMAIN_TYPE_ENUM
{
    QL_NW_TECH_DOMAIN_NONE    = 0,    /**<  None. */
    QL_NW_TECH_DOMAIN_3GPP    = 1,    /**<  3GPP. */
    QL_NW_TECH_DOMAIN_3GPP2   = 2,    /**<  3GPP2. */
}QL_NW_TECH_DOMAIN_TYPE_E;

typedef enum QL_NW_DENY_REASON_TYPE_ENUM
{
    QL_NW_IMSI_UNKNOWN_HLR_DENY_REASON                  = 1, /**<  IMSI unknown in HLR. */
    QL_NW_ILLEGAL_MS_DENY_REASON                        = 2, /**<  Illegal MS. */
    QL_NW_IMSI_UNKNOWN_VLR_DENY_REASON                  = 3, /**<  IMSI unknown in VLR. */
    QL_NW_IMEI_NOT_ACCEPTED_DENY_REASON                 = 4, /**<  IMEI not accepted. */
    QL_NW_ILLEGAL_ME_DENY_REASON                        = 5, /**<  Illegal ME. */
    QL_NW_PLMN_NOT_ALLOWED_DENY_REASON                  = 6, /**<  PLMN not allowed. */
    QL_NW_LA_NOT_ALLOWED_DENY_REASON                    = 7, /**<  Location area not allowed. */
    QL_NW_ROAMING_NOT_ALLOWED_LA_DENY_REASON            = 8, /**<  Roaming not allowed in this location area. */
    QL_NW_NO_SUITABLE_CELLS_LA_DENY_REASON              = 9, /**<  No suitable cells in location area. */
    QL_NW_NETWORK_FAILURE_DENY_REASON                   = 10, /**<  Network failure. */
    QL_NW_MAC_FAILURE_DENY_REASON                       = 11, /**<  MAC failure. */
    QL_NW_SYNCH_FAILURE_DENY_REASON                     = 12, /**<  Sync failure. */
    QL_NW_CONGESTION_DENY_REASON                        = 13, /**<  Congestion. */
    QL_NW_GSM_AUTHENTICATION_UNACCEPTABLE_DENY_REASON   = 14, /**<  GSM authentication unacceptable. */
    QL_NW_NOT_AUTHORIZED_CSG_DENY_REASON                = 15, /**<  Not authorized in this CSG. */
    QL_NW_SERVICE_OPTION_NOT_SUPPORTED_DENY_REASON      = 16, /**<  Service option not supported. */
    QL_NW_REQ_SERVICE_OPTION_NOT_SUBSCRIBED_DENY_REASON = 17, /**<  Requested service option not subscribed. */
    QL_NW_CALL_CANNOT_BE_IDENTIFIED_DENY_REASON         = 18, /**<  Call cannot be identified. */
    QL_NW_SEMANTICALLY_INCORRECT_MSG_DENY_REASON        = 19, /**<  Semantically incorrect message. */
    QL_NW_INVALID_MANDATORY_INFO_DENY_REASON            = 20, /**<  Invalid mandatory information. */
    QL_NW_MSG_TYPE_NON_EXISTENT_DENY_REASON             = 21, /**<  Message type non-existent or not implemented. */
    QL_NW_INFO_ELEMENT_NON_EXISTENT_DENY_REASON         = 22, /**<  Message type not compatible with the protocol state. */
    QL_NW_CONDITIONAL_IE_ERR_DENY_REASON                = 23, /**<  Conditional IE error. */
    QL_NW_MSG_INCOMPATIBLE_PROTOCOL_STATE_DENY_REASON   = 24, /**<  Message not compatible with the protocol state. */
    QL_NW_PROTOCOL_ERROR_DENY_REASON                    = 25, /**<  Unspecified protocol error. */
}QL_NW_DENY_REASON_TYPE_E;

typedef enum QL_NW_SERVICE_TYPE_ENUM
{
    QL_NW_SERVICE_NONE    = 0,  /**<  Not registered or no data. */
    QL_NW_SERVICE_LIMITED = 1,  /**<  Registered; emergency service only. */
    QL_NW_SERVICE_FULL    = 2,  /**<  Registered, full service. */
}QL_NW_SERVICE_TYPE_E;

typedef enum QL_NW_SELECTION_TYPE_ENUM
{
    QL_NW_SELECTION_AUTOMATIC = 0,     /**<  Automatic network selection. */
    QL_NW_SELECTION_MANUAL    = 1,     /**<  Manual network selection. */
}QL_NW_SELECTION_TYPE_E;

typedef enum QL_NW_CELL_ACCESS_STATE_TYPE_ENUM
{
    QL_NW_CELL_ACCESS_NONE           = 0,             /**<  Unknown cell access state. */
    QL_NW_CELL_ACCESS_NORMAL_ONLY    = 1,             /**<  Cell access is allowed for normal calls only. */
    QL_NW_CELL_ACCESS_EMERGENCY_ONLY = 2,             /**<  Cell access is allowed for emergency calls only. */
    QL_NW_CELL_ACCESS_NO_CALLS       = 3,             /**<  Cell access is not allowed for any call type. */
    QL_NW_CELL_ACCESS_ALL_CALLS      = 4,             /**<  Cell access is allowed for all call types. */
}QL_NW_CELL_ACCESS_STATE_TYPE_E;

/** wea config items */
typedef enum
{
    QL_NW_WEA_CONFIG_PRESIDENTIAL_ALERT     = (1 << 0),
    QL_NW_WEA_CONFIG_EXTREME_ALERT          = (1 << 1),
    QL_NW_WEA_CONFIG_SERVERE_ALERT          = (1 << 2),
    QL_NW_WEA_CONFIG_AMBER_ALERT            = (1 << 3),
    QL_NW_WEA_CONFIG_PUBLIC_SAFETY_ALERT    = (1 << 4),
    QL_NW_WEA_CONFIG_STATE_LOCAL_TEST_ALERT = (1 << 5),
    QL_NW_WEA_CONFIG_RMT_ALERT              = (1 << 6),
    QL_NW_WEA_CONFIG_EXERCISE_ALERT         = (1 << 7),
    QL_NW_WEA_CONFIG_CMSP_DEFINED_ALERT     = (1 << 8),  
    QL_NW_WEA_CONFIG_SPANISH_ALERT          = (1 << 9), 
} QL_NW_WEA_CONFIG_E;


typedef struct 
{
    uint64_t   preferred_nw_mode;               /**<   Preferred network mode for connections; a bitmask of QL_NW_MODE_xxxx.*/
    QL_NW_ROAM_STATE_TYPE_E preferred_roaming;  /**<   Roaming preference. 0 -- None, or roaming indicator off, 1 -- roaming indicator on*/
}ql_nw_pref_nwmode_roaming_info_t;

typedef struct 
{
    char     nitz_time[QL_NW_NITZ_BUF_LEN + 1]; /**< format: YY/MM/DD,HH:MM:SS'+/-'TZ,daylight, Here TZ multiplied by 4*/
    uint64_t abs_time;                          /**< 0 means invalid */
    int8_t   leap_sec;                          /**< 0 means invalid */
}ql_nw_nitz_time_info_t;

typedef struct 
{
    char long_eons[512 + 1];    /**<   Long EONS.*/
    char short_eons[512 + 1];   /**<   Short EONS.*/
    char mcc[3 + 1];            /**<   Mobile country code.*/
    char mnc[3 + 1];            /**<   Mobile network code.*/
}ql_nw_mobile_operator_name_info_t;

typedef struct 
{
    ql_nw_mobile_operator_name_info_t operator_name;   /**<   Operator name.*/
    QL_NW_NETWORK_STATUS_TYPE_E       network_status;  /**<   Network status.*/
    QL_NW_RADIO_TECH_TYPE_E           rat;             /**<   Radio technology.*/
}ql_nw_scan_entry_info_t;

typedef struct 
{
    uint32_t                entry_len;                      /**< Must be set to the number of elements in entry. */
    ql_nw_scan_entry_info_t entry[QL_NW_SCAN_MAX_LIST_NUM]; /**<   Scan entry.*/
}ql_nw_scan_result_list_info_t;

typedef struct
{
    QL_NW_TECH_DOMAIN_TYPE_E tech_domain;        /**<   Technology domain: 0 -- None, 1 -- 3GPP, 2 -- 3GPP2.*/
    QL_NW_RADIO_TECH_TYPE_E  radio_tech;         /**<   Radio technology; see #QL_NW_RADIO_TECH_TYPE_E.*/
    QL_NW_ROAM_STATE_TYPE_E  roaming;            /**<   0 -- Off, 1 -- Roaming (3GPP2 has extended values).*/
    QL_NW_DENY_REASON_TYPE_E deny_reason;        /**<   Set when registration state is #QL_NW_DENY_REASON_TYPE_E.*/
    QL_NW_SERVICE_TYPE_E     reg_state;          /**<   Registration state.*/
    char                     mcc[3+1];           /**<   Mobile country code.*/
    char                     mnc[3+1];           /**<   Mobile network code.*/
    uint8_t                  forbidden;          /**<   Forbidden: 0 -- No, 1 -- Yes.*/
    uint32_t                 cid;                /**<   Cell ID for the registered 3GPP system.*/
    uint16_t                 lac;                /**<   Locatin area code for the registered 3GPP system.*/
    uint16_t                 psc;                /**<   Primary scrambling code (WCDMA only); 0 -- None.*/
    uint16_t                 tac;                /**<   Tracking area code information for LTE.*/
    uint8_t                  inPRL;              /**<   0 -- Not in PRL, 1 -- In PRL.*/
    uint8_t                  css;                /**<   Concurrent services supported: 0 -- No, 1 -- Yes.*/
    uint16_t                 sid;                /**<   CDMA system ID.*/
    uint16_t                 nid;                /**<   CDMA network ID.*/
    uint16_t                 bsid;               /**<   Base station ID. @newpagetable */ 
}ql_nw_reg_status_info_t;

typedef struct 
{
    QL_NW_SELECTION_TYPE_E  nw_selection_type;    /**<   Network selection type. */
    char                    mcc[3 + 1];           /**<   Mobile country code for a manual network selection.*/
    char                    mnc[3 + 1];           /**<   Mobile network code for a manual network selection.*/
    QL_NW_RADIO_TECH_TYPE_E rat;                  /**<   Radio technology.*/
}ql_nw_pref_net_t;

typedef struct 
{
    int8_t      rssi;       /**<   RSSI in dBm. Indicates received signal strength. A signed value; -125 or lower indicates no signal.*/
}ql_nw_gsm_signal_info_t;

typedef struct 
{
    int8_t      rssi;       /**<   RSSI in dBm. Indicates forward link pilot Ec. A signed value; -125 or lower indicates no signal.*/
    int16_t     ecio;       /**<   Ec/Io value representing negative 0.5 dB increments, e.g., 2 equals -1 dbm.*/
}ql_nw_wcdma_signal_info_t;

typedef struct 
{
    int8_t      rssi;       /**<   RSSI in dBm. Indicates forward link pilot Ec.    a signed value; -125 or lower indicates no signal.*/
    int8_t      rscp;       /**<   RSCP in dBm.*/
    int16_t     ecio;       /**<   Ec/Io value representing negative 0.5 dB increments, e.g., 2 equals -1 dbm.*/
    int8_t      sinr;       /**<   Measured SINR in dB. @newpagetable */
}ql_nw_tdscdma_signal_info_t;

typedef struct 
{
    int8_t      rssi;       /**<   RSSI in dBm. Indicates forward link pilot Ec. A signed value; -125 or lower indicates no signal.*/
    int8_t      rsrq;       /**<   RSRQ value in dB (signed integer value), as measured by L1. Range: -3 to -20 (-3 equals -3 dB, -20 equals -20 dB).*/
    int16_t     rsrp;       /**<   Current RSRP in dBm, as measured by L1. Range: -44 to -140 (-44 equals -44 dBm, -140 equals -140 dBm).*/
    int16_t     snr;        /**<   SNR level as a scaled integer in units of 0.1 dB; e.g., -16 dB has a value of -160 and 24.6 dB has a value of 246.*/
}ql_nw_lte_signal_info_t;


typedef struct 
{
    int8_t      rssi;       /**<   RSSI in dBm. Indicates forward link pilot Power (AGC) + Ec/Io. A signed value; -125 or lower indicates no signal.*/
    int16_t     ecio;       /**<   Ec/Io value representing negative 0.5 dB increments, e.g., 2 equals -1 dbm.*/
}ql_nw_cdma_signal_info_t;

typedef struct 
{
    int8_t      rssi;       /**<   rssi in dbm. indicates forward link pilot power (agc) + ec/io. a signed value; -125 or lower indicates no signal.*/
    int16_t     ecio;       /**<   ec/io value representing negative 0.5 db increments, e.g., 2 equals -1 dbm.*/
    int8_t      sinr;       /**<   sinr level.*/
    int32_t     io;         /**<   received io in dbm. */
}ql_nw_hdr_signal_info_t;


typedef struct 
{
    uint8_t                     has_gsm;     /**<   Must be set to TRUE if gsm_sig_info is being passed. */
    ql_nw_gsm_signal_info_t     gsm;         /**<   GSM signal information. */
    uint8_t                     has_wcdma;   /**<   Must be set to TRUE if wcdma_sig_info is being passed. */
    ql_nw_wcdma_signal_info_t   wcdma;       /**<   WCDMA signal information. */
    uint8_t                     has_tdscdma; /**<   Must be set to TRUE if tdscdma_sig_info is being passed. */
    ql_nw_tdscdma_signal_info_t tdscdma;     /**<   TDSCDMA signal information. */
    uint8_t                     has_lte;     /**<   Must be set to TRUE if lte_sig_info is being passed. */
    ql_nw_lte_signal_info_t     lte;         /**<   LTE signal information. */
    uint8_t                     has_cdma;    /**<   Must be set to TRUE if cdma_sig_info is being passed. */
    ql_nw_cdma_signal_info_t    cdma;        /**<   CDMA signal information. */
    uint8_t                     has_hdr;     /**<   Must be set to TRUE if hdr_sig_info is being passed. */
    ql_nw_hdr_signal_info_t     hdr;         /**<   HDR signal information. */
}ql_nw_signal_strength_info_t;

typedef struct
{
    uint32_t    cid;        /**<   Cell ID, (0 indicates information is not represent).*/
    char        plmn[3];    /**<   MCC/MNC inforamtion code.(This field should be ignored when cid is not present). */
    uint16_t    lac;        /**<   Location area code.(This field should be ignord when cid is not present). */
    uint16_t    arfcn;      /**<   Absolute RF channel number. */
    uint8_t     bsic;       /**<   Base station identity code. (0 indicates information is not present). */
    int16_t     rssi;       /**<   Received signal strength indicator in dBm.*/
}ql_nw_gsm_info_t;;

typedef struct
{
    uint32_t cid;           /**<   Cell ID (0 indicates information is not present). */
    uint32_t lcid;          /**<   UTRAN Cell ID (0 indicates information is not present). */
    char plmn[3];           /**<   MCC/MNC information code.(This field should be ignored when cid is not present). */
    uint16_t lac;           /**<   Location area code. (This field should be ignored when cid is not present). */
    uint16_t uarfcn;        /**<   UTRA absolute RF channel number. */
    uint16_t psc;           /**<   Primary scrambling code. */
    int16_t  rssi;          /**<   Received signal strength indicator in dBm.*/
}ql_nw_umts_info_t;

typedef struct
{
    uint32_t cid;           /**<   Global cell ID in the system information block (0 indicates information is not present). */
    char plmn[3];           /**<   MCC/MNC information code.(This filed should be ignored when cid is not present). */
    uint16_t tac;           /**<   Tracing area code (This field should be ignored when cid is not present). */
    uint16_t pci;           /**<   Physical cell ID. Range: 0 to 503. */
    uint16_t earfcn;        /**<   E-UTRA absolute radio frequency channel number of the cell. RANGE: 0 TO 65535. */
    int16_t  rssi;          /**<   Received signal strength indicator in dBm.*/
}ql_nw_lte_info_t;

typedef struct 
{
   uint16_t sid;            /**<   System ID. */
   uint16_t nid;            /**<   Network ID. */
   uint16_t bid;            /**<   Base station ID. */
   uint16_t refpn;          /**<   Reference PN. */
   uint32_t base_lat;       /**<   Latitude of the current base station in units of 0.25 sec. */
   uint32_t base_long;      /**<   Longitude of the current base station in units of 0.25 sec. */
   int16_t  rssi;           /**<   Received signal strength indicator in dBm. */
}ql_nw_cdma_info_t;

typedef struct 
{
    QL_NW_RADIO_TECH_TYPE_E serving_rat;
    uint8_t                 gsm_info_valid;                         /**<  Must be set to true if gsm_info is being passed */
    uint8_t                 gsm_info_len;                           /**<  Must be set to the number of elements in entry*/
    ql_nw_gsm_info_t        gsm_info[QL_NW_MAX_GSM_CELL_INFO_NUM];  /**<  GSM cell information (Serving and neighbor. */  
    uint8_t                 umts_info_valid;                        /**<  Must be set to true if umts_info is being passed */
    uint8_t                 umts_info_len;                          /**<  Must be set to the number of elements in entry*/
    ql_nw_umts_info_t       umts_info[QL_NW_MAX_UMTS_CELL_INFO_NUM];/**<  UMTS cell information (Serving and neighbor). */
    uint8_t                 lte_info_valid;                         /**<  Must be set to true if lte_info is being passed */
    uint8_t                 lte_info_len;                           /**<  Must be set to the number of elements in entry*/
    ql_nw_lte_info_t        lte_info[QL_NW_MAX_LTE_CELL_INFO_NUM];  /**<  LTE cell information (Serving and neighbor). */
    uint8_t                 cdma_info_valid;                        /**<  Must be set to true if cdma_info is being passed */
    ql_nw_cdma_info_t       cdma_info;                              /**<  CDMA cell information (Serving). */  
}ql_nw_cell_info_t;

typedef struct 
{
    uint8_t Presidential_alert;         /**<  Enable Presidential_alert: 0 -- Disable(can't Disable); 1 -- Enable */
    uint8_t Extreme_alert;              /**<  Enable or disable Extreme_alert: 0 -- Disable; 1 -- Enable */
    uint8_t Servere_alert;              /**<  Enable or disable Servere_alert: 0 -- Disable; 1 -- Enable */
    uint8_t Amber_alert;                /**<  Enable or disable Amber_alert: 0 -- Disable; 1 -- Enable */
    uint8_t PublicSafety_alert;         /**<  Enable or disable PublicSafety_alert: 0 -- Disable; 1 -- Enable */
    uint8_t StateLocalTest_alert;       /**<  Enable or disable StateLocalTest_alert: 0 -- Disable; 1 -- Enable */
    uint8_t RMT_alert;                  /**<  Enable or disable RMT_alert: 0 -- Disable; 1 -- Enable */
    uint8_t Exercise_alert;             /**<  Enable or disable Exercise_alert: 0 -- Disable; 1 -- Enable */
    uint8_t CMSPDefined_alert;          /**<  Enable or disable CMSPDefined_alert: 0 -- Disable; 1 -- Enable */
    uint8_t Spanish_alert;              /**<  Enable or disable Spanish_alert: 0 -- Disable; 1 -- Enable */
}ql_nw_wea_config_t;
    

typedef struct 
{
    uint8_t wea_alert_info_valid; 
    char wea_alert_info[QL_NW_MAX_WEA_ALERT_LENGTH_V01];
}ql_nw_wea_alert_info_t;

typedef struct 
{
    uint8_t etws_primary_info_valid;
    char etws_primary_info[QL_NW_MAX_ETWS_ALERT_LENGTH_V01];
    uint8_t etws_secondary_info_valid;
    char etws_secondary_info[QL_NW_MAX_ETWS_ALERT_LENGTH_V01];
}ql_nw_etws_alert_info_t;

typedef void (*ql_nw_voice_reg_ind_cb)(ql_nw_reg_status_info_t *p_info);

typedef void (*ql_nw_data_reg_ind_cb)(ql_nw_reg_status_info_t *p_info);

typedef void (*ql_nw_signal_strength_ind_cb)(ql_nw_signal_strength_info_t *p_info, QL_NW_SIGNAL_STRENGTH_LEVEL_E level);

typedef void (*ql_nw_cell_access_status_ind_cb)(QL_NW_CELL_ACCESS_STATE_TYPE_E status);

typedef void (*ql_nw_nitz_time_update_ind_cb)(ql_nw_nitz_time_info_t *p_info);

typedef void (*ql_nw_network_scan_async_cb)(int async_index, ql_nw_scan_result_list_info_t *p_info);

typedef void (*ql_nw_wea_reg_ind_cb)(ql_nw_wea_alert_info_t *p_info);

typedef void (*ql_nw_etws_reg_ind_cb)(ql_nw_etws_alert_info_t *p_info);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Initialize NW service.
  @note You must call this function before other functions can be used in this module.
  @return Whether the NW service was successfully intialized.
  @retval QL_ERR_OK successful
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_init(void);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief scan network status.
  @param[out] async_index The index of request msg
  @param[in] async_cb The callback function of request msg
  @return Whether to successfully trigger the network scan operation
  @retval QL_ERR_OK  successful
  @retval QL_ERR_NOT_INIT  uninitialized
  @retval QL_ERR_SERVICE_NOT_READY  service is not ready
  @retval QL_ERR_INVALID_ARG  Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_network_scan(int *async_index, ql_nw_network_scan_async_cb async_cb);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief set power mode.
  @param[in] lower_mode, 0:normal power mode, other:lower power mode
  @return Whether to successfully set the power mode
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_set_power_mode(uint8_t lower_mode);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief set perferred NW mode and roaming indicator.
  @param[in] p_info Pointer that point to ql_nw_pref_nwmode_roaming_info_t
  @return Whether to successfully set nwmode and roaming
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_set_pref_nwmode_roaming(ql_nw_pref_nwmode_roaming_info_t *p_info);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get perferred NW mode and roaming indicator.
  @param[out] p_info Pointer that point to ql_nw_pref_nwmode_roaming_info_t 
  @return Whether to successfully get nwmode and roaming
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_get_pref_nwmode_roaming(ql_nw_pref_nwmode_roaming_info_t *p_info);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get mobile operator name.
  @param[out] p_info Pointer that point to ql_nw_mobile_operator_name_info_t
  @return Whether to successfully get the mobile operator name
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_get_mobile_operator_name(ql_nw_mobile_operator_name_info_t *p_info);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get cell information.
  @param[out] p_info Pointer that point to ql_nw_cell_info_t
  @return Whether to successfully get the cell information
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_get_cell_info(ql_nw_cell_info_t *p_info);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get voice registration status.
  @param[out] p_info Pointer that point to ql_nw_reg_status_info_t
  @return Whether to successfully get the voice registration status
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_get_voice_reg_status(ql_nw_reg_status_info_t *p_info);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get data registration status.
  @param[out] p_info Pointer that point to ql_nw_reg_status_info_t
  @return Whether to successfully get the data registration status
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_get_data_reg_status(ql_nw_reg_status_info_t *p_info);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get current signal strength.
  @param[out] p_info Pointer that point to ql_nw_signal_strength_info_t
  @param[out] p_level: signal strength level
  @return Whether to successfully get the signal strength
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_get_signal_strength(ql_nw_signal_strength_info_t *p_info, QL_NW_SIGNAL_STRENGTH_LEVEL_E* p_level);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get current cell acccess status.
  @param[out] p_info Pointer that point to QL_NW_CELL_ACCESS_STATE_TYPE_E
  @return Whether to successfully get the cell access status
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_get_cell_access_status(QL_NW_CELL_ACCESS_STATE_TYPE_E *p_info);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get network time.
  @param[out] p_info Pointer that point to ql_nw_nitz_time_info_t 
  @return Whether to successfully get the network time
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_get_nitz_time_info(ql_nw_nitz_time_info_t *p_info);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief register voice registration event.
  @param[in] cb_func Voice registration indication callback function
  @return Whether the voice registration event was successfully registered.
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
 */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_set_voice_reg_ind_cb(ql_nw_voice_reg_ind_cb cb_func);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief register data registration event.
  @param[in] cb_func Data registration indication callback function
  @return Whether the data registration event was successfully registered.
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_set_data_reg_ind_cb(ql_nw_data_reg_ind_cb cb_func);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief register signal strength event.
  @param[in] cb_func Signal strength indication callback function
  @return Whether the signal strength event was successfully registered
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_set_signal_strength_ind_cb(ql_nw_signal_strength_ind_cb cb_func);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief register cell access status event.
  @param[in] cb_func Cell access status indication callback function
  @return Whether the cell access status event was successfully registered
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_set_cell_access_status_ind_cb(ql_nw_cell_access_status_ind_cb cb_func);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief register network time event.
  @param[in] cb_func nitz time update indication callback function
  @return Whether the network time event was successfully registered
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_set_nitz_time_update_ind_cb(ql_nw_nitz_time_update_ind_cb cb_func);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief register wea alert event.
  @param[in] cb_func wea alert indication callback function
  @return Whether the network time event was successfully registered
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_set_wea_alert_ind_cb(ql_nw_wea_reg_ind_cb cb_func);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief register etws alert event.
  @param[in] cb_func etws alert indication callback function
  @return Whether the network time event was successfully registered
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_set_etws_alert_ind_cb(ql_nw_etws_reg_ind_cb cb_func);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief set wea alert config.
  @param[in] item Items to set.
  @param[in] p_info Pointer that point to ql_nw_wea_config_t.
  @return Whether to successfully set the wea config.
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_set_wea_config(int item, ql_nw_wea_config_t *p_info);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Gets wea config.
  @param[out] p_config wea config.
  @return Whether the wea config was successfully obtained.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_INVALID_ARG invalid argument.
  @retval QL_ERR_UNKNOWN unknown error, failed to connect to service.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_get_wea_config(ql_nw_wea_config_t *p_config);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief set etws alert config.
  @param[in] etws config.
  @return Whether to successfully set the etws config.
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_set_etws_config(uint8_t enable_etws);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get etws alert config.
  @param[out] p_enable_etws Pointer.
  @return Whether to successfully set the etws config.
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nw_get_etws_config(uint8_t* p_enable_etws);

#ifdef __cplusplus
}
#endif

#endif
