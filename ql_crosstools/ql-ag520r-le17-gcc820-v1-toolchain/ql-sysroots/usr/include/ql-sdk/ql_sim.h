/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_sim.h 
  @brief SIM service API 
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
  20200511   solomon.cui  Add support for multiple slots.
  20191225   solomon.cui  Modify fucntion description.
  20190717   solomon.cui  Created .
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_SIM_H__
#define __QL_SIM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define QL_SIM_IMSI_LENGTH      16      /**<  Maximum length of IMSI data. */
#define QL_SIM_ICCID_LENGTH     20      /**<  Maximum length of ICCID data. */
#define QL_SIM_NUM_OPERATOR_MAX 24      /**<  Maximum number of operators */
#define QL_SIM_PATH_MAX         20      /**<  Maximum length of a full file path in ASCII format. */
#define QL_SIM_DATA_MAX         4096    /**<  Maximum size of data to be read/written. */
#define QL_SIM_PIN_MAX          8       /**<  Maximum length of PIN data. */
#define QL_SIM_MAX_NUM_CARDS    2       /**<  Maximum number of cards. */
#define QL_SIM_PHONE_NUMBER_MAX 82      /**<  Maximum phone number length. */
#define QL_SIM_MCC_LENGHT       3       /**<  Length of the MCC. */
#define QL_SIM_MNC_MAX          3       /**<  Maximum length of the MNC. */

#define QL_SIM_PHONE_BOOK_NAME_MAX      15  /**<  Maximum length of phone book user name. */
#define QL_SIM_PHONE_BOOK_NUMBER_MAX    25  /**<  Maximum length of phone book number. */

#define QL_SIM_APDU_DATA_MAX    1024  /**<  Maximum number of APDU data. */

#define QL_SIM_PB_DEFAULT_PATH   "3F007F106F3A"   /**< Default phone book path. */

/** Ligcial slot */
/**> Currently only one active slot is supported, so slot should be always QL_SIM_SLOT_1.*/
typedef enum 
{
    QL_SIM_SLOT_INVALID = 0x000, /**< Invalid slot.  */   
    QL_SIM_SLOT_1       = 0xB01, /**< Identify card in slot 1.  */
    QL_SIM_SLOT_2       = 0xB02, /**< Identify card in slot 2.  */
} QL_SIM_SLOT_E;

/** Physical slot */
typedef enum 
{
    QL_SIM_PHY_SLOT_INVALID = 0x000, /**< Invalid slot.  */   
    QL_SIM_PHY_SLOT_1       = 0xB01, /**< Identify card in slot 1.  */
    QL_SIM_PHY_SLOT_2       = 0xB02, /**< Identify card in slot 2.  */
} QL_SIM_PHY_SLOT_E;


typedef enum 
{
    QL_SIM_PIN_1 = 0xB01, /**< Level 1 user verification.  */
    QL_SIM_PIN_2 = 0xB02, /**< Level 2 user verification.  */
} QL_SIM_PIN_E;


/** Application Type */
typedef enum
{
    QL_SIM_APP_TYPE_UNKNOWN = 0xB00, /**<  Unknown application type  */
    QL_SIM_APP_TYPE_3GPP    = 0xB01, /**< Identify the SIM/USIM application on the card.  */
    QL_SIM_APP_TYPE_3GPP2   = 0xB02, /**< Identify the RUIM/CSIM application on the card.  */
    QL_SIM_APP_TYPE_ISIM    = 0xB03, /**< Identify the ISIM application on the card.  */
} QL_SIM_APP_TYPE_E;

typedef struct 
{
    char mcc[QL_SIM_MCC_LENGHT];    /**< MCC value in ASCII characters.*/
    uint8_t mnc_len;                /**< The number of elements in the MNC, 2 or 3. */
    char mnc[QL_SIM_MNC_MAX];       /**< MNC value in ASCII characters.*/
} ql_sim_operator_t;

typedef struct 
{
    int len;    /**< Length of actual operators */
    ql_sim_operator_t operators[QL_SIM_NUM_OPERATOR_MAX];
} ql_sim_operator_list_t;

typedef enum {
    /** Card state unknown. */
    QL_SIM_CARD_STATE_UNKNOWN                       = 0xB01,
    /** Card is absent. */
    QL_SIM_CARD_STATE_ABSENT                        = 0xB02,  
    /** Card is present. */
    QL_SIM_CARD_STATE_PRESENT                       = 0xB03,
    /** Unknown error state. */
    QL_SIM_CARD_STATE_ERROR_UNKNOWN                 = 0xB04,
    /** Power down. */
    QL_SIM_CARD_STATE_ERROR_POWER_DOWN              = 0xB05,
    /** Poll error. */
    QL_SIM_CARD_STATE_ERROR_POLL_ERROR              = 0xB06,  
    /**  Failed to receive an answer to reset.  */
    QL_SIM_CARD_STATE_ERROR_NO_ATR_RECEIVED         = 0xB07, 
    /** Voltage mismatch. */
    QL_SIM_CARD_STATE_ERROR_VOLT_MISMATCH           = 0xB08, 
    /** Parity error. */
    QL_SIM_CARD_STATE_ERROR_PARITY_ERROR            = 0xB09,    
    /** Card returned technical problems. */
    QL_SIM_CARD_STATE_ERROR_SIM_TECHNICAL_PROBLEMS  = 0xB0A,  
} QL_SIM_CARD_STATE_E;  /**< Card state. */

typedef enum {
    QL_SIM_SUBSCRIPTION_NONE    = 0xB00, /**<  Nonprovisioning.  */
    QL_SIM_SUBSCRIPTION_PRI     = 0xB01, /**<  Primary provisioning subscription.  */
    QL_SIM_SUBSCRIPTION_SEC     = 0xB02, /**<  Secondary provisioning subscription.  */
} QL_SIM_SUBSCRIPTION_E;

typedef enum
{
    QL_SIM_CARD_TYPE_UNKNOWN    = 0xB00, /**<  Unidentified card type.  */
    QL_SIM_CARD_TYPE_ICC        = 0xB01, /**<  Card of SIM or RUIM type.  */
    QL_SIM_CARD_TYPE_UICC       = 0xB02, /**<  Card of USIM or CSIM type.  */
} QL_SIM_CARD_TYPE_E;

typedef enum {
    QL_SIM_APP_STATE_UNKNOWN                    = 0xB00, /**<  Application state unknown. */
    QL_SIM_APP_STATE_DETECTED                   = 0xB01, /**<  Detected state.  */
    QL_SIM_APP_STATE_PIN1_REQ                   = 0xB02, /**<  PIN1 required.  */
    QL_SIM_APP_STATE_PUK1_REQ                   = 0xB03, /**<  PUK1 required.  */
    QL_SIM_APP_STATE_INITALIZATING              = 0xB04, /**<  Initializing.  */
    QL_SIM_APP_STATE_PERSO_CK_REQ               = 0xB05, /**<  Personalization control key required.  */
    QL_SIM_APP_STATE_PERSO_PUK_REQ              = 0xB06, /**<  Personalization unblock key required.  */
    QL_SIM_APP_STATE_PERSO_PERMANENTLY_BLOCKED  = 0xB07, /**<  Personalization is permanently blocked.  */
    QL_SIM_APP_STATE_PIN1_PERM_BLOCKED          = 0xB08, /**<  PIN1 is permanently blocked.  */
    QL_SIM_APP_STATE_ILLEGAL                    = 0xB09, /**<  Illegal application state.  */
    QL_SIM_APP_STATE_READY                      = 0xB0A, /**<  Application ready state. */
} QL_SIM_APP_STATE_E;

typedef enum {
    /**  Unknown personalization feature.  */
    QL_SIM_PERSO_FEATURE_UNKNOWN                = 0xB00,
    /**  Featurization based on 3GPP MCC and MNC.  */
    QL_SIM_PERSO_FEATURE_3GPP_NETWORK           = 0xB01, 
    /**  Featurization based on 3GPP MCC, MNC, and IMSI digits 6 and 7.  */
    QL_SIM_PERSO_FEATURE_3GPP_NETWORK_SUBSET    = 0xB02, 
    /**  Featurization based on 3GPP MCC, MNC, and GID1.  */
    QL_SIM_PERSO_FEATURE_3GPP_SERVICE_PROVIDER  = 0xB03,
    /**  Featurization based on 3GPP MCC, MNC, GID1, and GID2.  */
    QL_SIM_PERSO_FEATURE_3GPP_CORPORATE         = 0xB04, 
    /**  Featurization based on the 3GPP IMSI.  */
    QL_SIM_PERSO_FEATURE_3GPP_SIM               = 0xB05, 
    /**  Featurization based on 3GPP2 MCC and MNC.  */
    QL_SIM_PERSO_FEATURE_3GPP2_NETWORK_TYPE_1   = 0xB06, 
    /**  Featurization based on 3GPP2 IRM code.  */
    QL_SIM_PERSO_FEATURE_3GPP2_NETWORK_TYPE_2   = 0xB07, 
    /**  Featurization based on 3GPP2 IMSI_M.  */
    QL_SIM_PERSO_FEATURE_3GPP2_RUIM             = 0xB08, 
} QL_SIM_PERSO_FEATURE_E;

typedef enum {
    /** Unknown PIN state. */
    QL_SIM_PIN_STATE_UNKNOWN                = 0xB01, 
    /**  PIN required, but has not been verified.  */
    QL_SIM_PIN_STATE_ENABLED_NOT_VERIFIED   = 0xB02, 
    /**  PIN required and has been verified.  */
    QL_SIM_PIN_STATE_ENABLED_VERIFIED       = 0xB03, 
    /**  PIN not required.  */
    QL_SIM_PIN_STATE_DISABLED               = 0xB04, 
    /**  PIN verification has failed too many times and is blocked. Recoverable through PUK verification.  */
    QL_SIM_PIN_STATE_BLOCKED                = 0xB05, 
    /**  PUK verification has failed too many times and is not recoverable.  */
    QL_SIM_PIN_STATE_PERMANENTLY_BLOCKED    = 0xB06, 
 } QL_SIM_PIN_STATE_E;

typedef struct {
    /**   Type of subscription (i.e., primary, secondary, etc.). */
    QL_SIM_SUBSCRIPTION_E subscription;
    /**   Current state of the application. */
    QL_SIM_APP_STATE_E app_state;
    /**   Current personalization state and feature enabled. */
    QL_SIM_PERSO_FEATURE_E perso_feature;
    /**   Number of personalization retries. */
    uint8_t perso_retries;
    /**   Number of personalization unblock retries. */
    uint8_t perso_unblock_retries;
    /**   Current PIN 1 state. */
    QL_SIM_PIN_STATE_E pin1_state;
    /**   Number of PIN 1 retries. */
    uint8_t pin1_num_retries;
    /**   Number of PUK 1 retries. */
    uint8_t puk1_num_retries;
    /**   Current PIN 2 state. */
    QL_SIM_PIN_STATE_E pin2_state;
    /**   Number of PIN 2 retries. */
    uint8_t pin2_num_retries; 
    /**   Number of PUK 2 retries. */
    uint8_t puk2_num_retries;
}ql_sim_app_info_t;  /* Type */

typedef struct
{
    QL_SIM_CARD_STATE_E state;
    QL_SIM_CARD_TYPE_E type;
    ql_sim_app_info_t app_3gpp;     /**<   Stores 3GPP application information. */
    ql_sim_app_info_t app_3gpp2;    /**<   Stores 3GPP2 application information. */
    ql_sim_app_info_t app_isim;     /**<   Stores ISIM application information. */
} ql_sim_card_info_t;

typedef struct {
    uint32_t path_len;          /**< Must be set to the number of elements in the path. */
    char path[QL_SIM_PATH_MAX]; /**< File path in ASCII characters. */
    /** Offset is only required for write transparent file access where data length is indicated.*/
    uint16_t offset; 
    /** Index of records involved in file access. A record index of 0 indicates transparent file access.*/
    uint8_t record_idx;

    /* == filled by caller when writing file == */
    uint32_t data_len;  /**< When reading file, it's the length of file data been read.
                             When writing file, it's the length of file data to be written. */
    uint8_t data[QL_SIM_DATA_MAX];
} ql_sim_file_t;  /* Type */

typedef enum {
    QL_SIM_FILE_TYPE_UNKNOWN        = 0xB00, /**<  Unknown file type  */
    QL_SIM_FILE_TYPE_TRANSPARENT    = 0xB01, /**< File structure consisting of a sequence of bytes.  */
    QL_SIM_FILE_TYPE_CYCLIC         = 0xB02, /**< File structure consisting of a sequence of records,
                                                  each containing the same fixed size in 
                                                  chronological order.Once all the records have been
                                                  used, the oldest data is overwritten.  */
    QL_SIM_FILE_TYPE_LINEAR_FIXED   = 0xB03, /**< File structure consisting of a sequence of records, 
                                                  each containing the same fixed size.  */
} QL_SIM_FILE_TYPE_E;


typedef struct {
    /* == filled by caller == */
    uint32_t path_len;          /**< Must be set to the number of elements in the path. */
    char path[QL_SIM_PATH_MAX]; /**< File path in ASCII characters. */

    /* == filled by callee == */
    QL_SIM_FILE_TYPE_E file_type;   /**<   File type */
    uint16_t file_size;             /**<   Size of transparent files.*/
    uint16_t record_size;           /**<   Size of each cyclic or linear fixed file record.*/
    uint16_t record_count;          /**<   Number of cyclic or linear fixed file records.*/
} ql_sim_file_info_t;  /* Type */

typedef struct 
{
    /** User name. Null-terminated */
    char name[QL_SIM_PHONE_BOOK_NAME_MAX];   
    /** Phone number, a '+' can also be preappended to the number. Null-terminated. */
    char number[QL_SIM_PHONE_BOOK_NUMBER_MAX]; 
} ql_sim_phone_book_record_t;

typedef struct
{
    uint32_t req_apdu_len;                      /**< Request APDU data length. */
    uint8_t req_apdu[QL_SIM_APDU_DATA_MAX];     /**< Request APDU data. */

    uint32_t resp_apdu_len;                     /**< Response APDU data length. */
    uint8_t resp_apdu[QL_SIM_APDU_DATA_MAX];    /**< Response APDU data. */
} ql_sim_apdu_t;

typedef void (*ql_sim_card_status_cb_f)(QL_SIM_SLOT_E slot, ql_sim_card_info_t *p_info);

typedef struct 
{
    int active_slots_len;
    QL_SIM_PHY_SLOT_E active_slots[QL_SIM_MAX_NUM_CARDS];
} ql_sim_active_slots_t;
/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Initializes SIM service.
  @note You must call this function before other functions can be used in this module.
  @return Whether the SIM service was intialized successfully.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_init(void);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Deinitializes SIM service.
  @return Whether the SIM service was deintialized successfully.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_deinit(void);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Gets the IMSI (for 3GPP) or IMSI_M (for 3GPP2) from the SIM in ASCII form.
  @param [in] slot Slot to be used.
  @param [in] app_type Application type.
  @param [out] imsi Buffer to fill IMSI data.
  @param [in] imsi_len Buffer length.
  @return Whether the IMSI was successfully obtained.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_get_imsi(QL_SIM_SLOT_E slot, QL_SIM_APP_TYPE_E app_type, char *imsi, int imsi_len);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Retrieves the Integrated Circuit Card ID (ICCID) stored on the card.
  @param [in] slot Slot to be used.
  @param [out] iccid Buffer to fill ICCID data.
  @param [in] iccid_len Buffer length.
  @return Whether the ICCID was successfully obtained.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_get_iccid(QL_SIM_SLOT_E slot, char *iccid, int iccid_len);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Retrieves the device phone number stored on the card.
  @param [in] slot Slot to be used.
  @param [in] app_type Application type.
  @param [out] phone_num Buffer to fill phone number.
  @param [in] phone_num_len Buffer length.
  @return Whether the phone number was successfully retrieved.
  @retval QL_ERR_OK successful
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_get_phone_num(QL_SIM_SLOT_E slot, QL_SIM_APP_TYPE_E app_type, 
                          char *phone_num, int phone_num_len);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Retrieves the preferred operators stored on the card.
  @param [in] slot Slot to be used.
  @param [in] list Buffer to hold operators
  @note This function is only supported by 3GPP applications.
  @return Whether the preferred operators were successfully retrieved.
  @retval QL_ERR_OK successful
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_get_operators(QL_SIM_SLOT_E slot, ql_sim_operator_list_t *list);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Enables the PIN on an application.
  @param [in] slot Slot to be used.
  @param [in] app_type Application type.
  @param [in] pin PIN to be used.
  @param [in] pin_value PIN value. NULL terminated.
  @return Whether the PIN was successfully enabled.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_enable_pin(QL_SIM_SLOT_E slot, QL_SIM_APP_TYPE_E app_type, 
                             QL_SIM_PIN_E pin, const char *pin_value);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Disables the PIN on an application.
  @param [in] slot Slot to be used.
  @param [in] app_type Application type.
  @param [in] pin PIN to be used.
  @param [in] pin_value PIN value. NULL terminated.
  @return Whether the PIN was successfully disabled.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_disable_pin(QL_SIM_SLOT_E slot, QL_SIM_APP_TYPE_E app_type, 
                             QL_SIM_PIN_E pin, const char *pin_value);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Verifies the PIN value of an application.
  @param [in] slot Slot to be used.
  @param [in] app_type Application type.
  @param [in] pin PIN to be used.
  @param [in] pin_value PIN value. NULL terminated.
  @note PIN must be enabled before calling this function.
  @return Whether the PIN was successfully verified.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_verify_pin(QL_SIM_SLOT_E slot, QL_SIM_APP_TYPE_E app_type, 
                             QL_SIM_PIN_E pin, const char *pin_value);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Changes the PIN value of an application.
  @param [in] slot Slot to be used.
  @param [in] app_type Application type.
  @param [in] pin PIN to be used.
  @param [in] old_pin_value Old PIN value. NULL terminated.
  @param [in] new_pin_value New PIN value. NULL terminated.
  @return Whether the PIN was successfully changed.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_change_pin(QL_SIM_SLOT_E slot, QL_SIM_APP_TYPE_E app_type, 
                             QL_SIM_PIN_E pin, const char *old_pin_value, const char *new_pin_value);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Unblocks a blocked PIN using the PUK code.
  @param [in] slot Slot to be used.
  @param [in] app_type Application type.
  @param [in] pin PIN to be used.
  @param [in] puk_value PUK value.  NULL terminated.
  @param [in] pin_value New PIN value.  NULL terminated.
  @note The user must pass PUK1 to unblock PIN1 or PUK2 to unblock PIN2.
  @return Whether the PIN was successfully unblocked.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_unblock_pin(QL_SIM_SLOT_E slot, QL_SIM_APP_TYPE_E app_type, 
                             QL_SIM_PIN_E pin, const char *puk_value, const char *pin_value);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Retrieves the card info stored on a card.
  @param [in] slot Slot to be used.
  @param [out] p_info Pointer of ql_sim_card_info_t.
  @return Whether the card info was successfully retrieved.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_get_card_info(QL_SIM_SLOT_E slot, ql_sim_card_info_t *p_info);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Reads data from a specific file on a specified application on the card.
  @param [in] slot Slot to be used.
  @param [in] app_type Application type.
  @param [inout] p_file Pointer of ql_sim_file_t.
  @return Whether the file was successfully read.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_read_file(QL_SIM_SLOT_E slot, QL_SIM_APP_TYPE_E app_type, ql_sim_file_t *p_file);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Writes data to a specific file on a specified application on the card. 
  @param [in] slot Slot to be used.
  @param [in] app_type Application type.
  @param [in] p_file Pointer of ql_sim_file_t
  @note The type of file is determined by the record number field,
    which indicates a transparent file when zero and a record-based file otherwise.
  @return Whether the file was successfully written.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_write_file(QL_SIM_SLOT_E slot, QL_SIM_APP_TYPE_E app_type, ql_sim_file_t *p_file);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Retrieves the info of a specific file on a specified application on the card.
  @param [in] slot Slot to be used.
  @param [in] app_type Application type.
  @param [inout] p_info Pointer of ql_sim_file_info_t.
  @return Whether the file info was successfully retrieved.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_get_file_info(QL_SIM_SLOT_E slot, QL_SIM_APP_TYPE_E app_type, 
                                 ql_sim_file_info_t *p_info);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Reads phone book on a specified application on the card.
  @param [in] slot Slot to be used.
  @param [in] app_type Spplication type.
  @param [in] pb_path Phone book path. NULL terminated.
  @param [in] record_idx Record index to read. Starts from 1.
  @param [out] p_record Pointer of ql_sim_phone_book_record_t.
  @return Whether the phone book record was successfully retrieved.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_read_phone_book(QL_SIM_SLOT_E slot, QL_SIM_APP_TYPE_E app_type,
                                    const char *pb_path, uint8_t record_idx,
                                    ql_sim_phone_book_record_t *p_record);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Writes phone book on a specified application on the card.
  @param [in] slot Slot to be used.
  @param [in] app_type Application type.
  @param [in] pb_path Phone book path. NULL terminated.
  @param [in] record_idx Record index to write. Starts from 1.
  @param [in] p_record Pointer of ql_sim_phone_book_record_t.
  @note If p_record->name[0] = 0 and p_record->number[0] = 0, record will be deleted.
  @return Whether the phone book record was successfully saved.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_write_phone_book(QL_SIM_SLOT_E slot, QL_SIM_APP_TYPE_E app_type, 
                                    const char *pb_path, uint8_t record_idx,
                                    ql_sim_phone_book_record_t *p_record);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Opens a logical channel on a UICC card.
  @param [in] slot Slot to be used.
  @param [out] channel_id Channel opened.
  @return Whether the logical channel was successfully opened.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_open_logical_channel(QL_SIM_SLOT_E slot, uint8_t *channel_id);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Closes a logical channel on a UICC card.
  @param [in] slot Slot to be used.
  @param [in] channel_id Channel to be closed.
  @return Whether the logical channel was successfully closed.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_close_logical_channel(QL_SIM_SLOT_E slot, uint8_t channel_id);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Sends an APDU to the card.
  @param [in] slot Slot to be used.
  @param [in] channel_id Channel to be used.
  @param [inout] p_apdu Pointer of ql_sim_apdu_t.
  @note You must call ql_sim_open_logical_channel before sending an APDU.
  @return Whether the APDU was successfully sent.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_send_apdu(QL_SIM_SLOT_E slot, uint8_t channel_id, ql_sim_apdu_t *p_apdu);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Sets SIM card status callback handler
  @param[in] cb call back handler.
  @return Whether the card status callback handler was successfully set.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_set_card_status_cb(ql_sim_card_status_cb_f cb);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Switches slot.
  @param [in] log_slot Logical slot to be switched.
  @param [in] phy_slot Physical slot to be switched.
  @return Whether the slot was successfully switched.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_switch_slot(QL_SIM_SLOT_E log_slot, QL_SIM_PHY_SLOT_E phy_slot);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief  Gets active slots.
  @param [Out] p_active_slots Active slots.
  @return Whether the active slots were successfully obtained.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sim_get_active_slots(ql_sim_active_slots_t *p_active_slots);

#ifdef __cplusplus
}
#endif

#endif  /* __QL_SIM_H__ */

