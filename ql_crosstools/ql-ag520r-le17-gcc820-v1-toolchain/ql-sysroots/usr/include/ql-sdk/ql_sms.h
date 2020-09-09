/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_sms.h 
  @brief SMS service API.
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
  20200107   solomon.cui      Add GSM-7bit and ISO 8859-1 conversion.
  20191225   solomon.cui      Modify fucntion description.
  20191017   solomon.cui      Free async reponse not user data.
  20190815   solomon.cui      Add service type for sending message.
  20190627   solomon.cui      Support asynchronously send msg and pdu
  20190625   solomon.cui      Convert timestamp frome hex to dec.
  20190614   solomon.cui      Created .
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_SMS_H__
#define __QL_SMS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define QL_SMS_MAX_SEND_MSG_LENGTH  1440    /**<  Maximum length of an sending SMS (9*160). */
#define QL_SMS_MAX_SEND_PDU_LENGTH  255     /**<  Maximum length of an sms PDU. */
#define QL_SMS_MAX_RECV_MSG_LENGTH  160     /**<  Maximum length of an recv SMS. */
#define QL_SMS_MAX_ADDR_LENGTH      252     /**<  Maximum length of SCA addr. */

/** The SMS message format. */
typedef enum 
{
    QL_SMS_MSG_FORMAT_GSM_7BIT      = 0,
    QL_SMS_MSG_FORMAT_BINARY_DATA   = 1,
    QL_SMS_MSG_FORMAT_UCS2          = 2,
} QL_SMS_MSG_FORMAT_E;

/** The SMS message structure. */
typedef struct 
{
    QL_SMS_MSG_FORMAT_E format;
    char addr[QL_SMS_MAX_ADDR_LENGTH + 1]; /**< Source or destinamtion address. */
    int content_size;
    char content[QL_SMS_MAX_SEND_MSG_LENGTH];
} ql_sms_msg_t;

typedef struct 
{
    uint8_t year;       /**< Year. since 2000. e.g. 19 means 2019 */
    uint8_t month;      /**< Month.*/
    uint8_t day;        /**< Day.*/
    uint8_t hours;      /**< Hour. 00 ~ 23 */
    uint8_t minutes;    /**< Minutes.*/
    uint8_t seconds;    /**< Seconds.*/
    /** 
     * The Time Zone indicates the difference, expressed in quarters of an hour, 
     * between the local time and GMT. 
     * */
    uint8_t timezone;
} ql_sms_timestamp_t;

typedef struct
{
    
    uint8_t valid;       /**< Indicate whether following is valid, 1 - valid; 0 - invalid; */
    uint8_t total_seg;   /**< The number of long message segment*/
    uint8_t cur_seg_num; /**< Current number.*/
    uint8_t ref_num;     /**< reference number.*/
} ql_sms_user_data_head_t;

typedef void (*ql_sms_msg_async_cb_f)(int id, int result);
typedef void (*ql_sms_msg_recv_cb_f)(ql_sms_msg_t *p_msg, ql_sms_timestamp_t *timestamp,
                                             ql_sms_user_data_head_t *head);

/** The SMS PDU format. */
typedef enum
{
    QL_SMS_PDU_FORMAT_CDMA  = 0,
    QL_SMS_PDU_FORMAT_GW_PP = 6,
} QL_SMS_PDU_FORMAT_E;

/** The SMS PDU structure. */
typedef struct 
{
    QL_SMS_PDU_FORMAT_E format;
    int content_size;
    char content[QL_SMS_MAX_SEND_PDU_LENGTH];
} ql_sms_pdu_t;

typedef void (*ql_sms_pdu_async_cb_f)(int id, int result);
typedef void (*ql_sms_pdu_recv_cb_f)(ql_sms_pdu_t *p_pdu);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Initializes SMS service.
  @return Whether the SMS service was initialized successfully.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_UNKNOWN unknown error, failed to connect to service.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sms_init(void);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Deinitializes SMS service.
  @return Whether the SMS service was deinitialized successfully.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_UNKNOWN unknown error, failed to connect to service.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sms_deinit(void);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Sets the service center address.
  @param[in] addr service center address.
  @param[in] len  service center address length.
  @return Whether the service center address was set successfully.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_INVALID_ARG invalid argument.
  @retval QL_ERR_UNKNOWN unknown error, failed to connect to service.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sms_set_service_center_addr(char *addr, int len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Gets the service center address.
  @param[out] addr service center address.
  @param[in] len  service center address length.
  @return Whether the service center address was successfully obtained.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_INVALID_ARG invalid argument.
  @retval QL_ERR_UNKNOWN unknown error, failed to connect to service.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sms_get_service_center_addr(char *addr, int len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Sends message synchronously.
  @param[in] p_msg pointer to ql_sms_msg_t.
  @return Whether the message was successfully sent synchronously.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_INVALID_ARG invalid argument.
  @retval QL_ERR_UNKNOWN unknown error, failed to connect to service.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sms_send_msg(ql_sms_msg_t *p_msg);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Sends message asynchronously.
  @param[in] p_msg  pointer to ql_sms_msg_t
  @param[out] id    id for this async operation
  @param[in] cb     async callback
  @return Whether the message was successfully sent asynchronously.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_INVALID_ARG invalid argument.
  @retval QL_ERR_UNKNOWN unknown error, failed to connect to service.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sms_send_msg_async(ql_sms_msg_t *p_msg, int *id, ql_sms_msg_async_cb_f cb);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Sets SMS message reception callback hanlder.
  @param[in] cb message reception callback handler.
  @return Whether the message reception callback hanlder was set successfully.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_INVALID_ARG invalid argument.
  @retval QL_ERR_UNKNOWN unknown error, failed to connect to service.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sms_set_msg_recv_cb(ql_sms_msg_recv_cb_f cb);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Sends PDU synchronously.
  @param[in] p_pdu SMS PDU.
  @return Whether the PDU was successfully sent synchronously.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_INVALID_ARG invalid argument.
  @retval QL_ERR_UNKNOWN unknown error, failed to connect to service.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sms_send_pdu(ql_sms_pdu_t *p_pdu);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Sends PDU asynchronously.
  @param[in] p_pdu sms pdu.
  @param[out] id id for this async operation.
  @param[in] cb async callback.
  @return Whether the PDU was successfully sent asynchronously.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_INVALID_ARG invalid argument.
  @retval QL_ERR_UNKNOWN unknown error, failed to connect to service.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sms_send_pdu_async(ql_sms_pdu_t *p_pdu, int *id, ql_sms_pdu_async_cb_f cb);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Sets SMS PDU reception callback hanlder.
  @param[in] cb PDU reception callback handler.
  @return Whether the PDU reception callback hanlder was set successfully.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_INVALID_ARG invalid argument.
  @retval QL_ERR_UNKNOWN unknown error, failed to connect to service.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_sms_set_pdu_recv_cb(ql_sms_pdu_recv_cb_f cb);

#ifdef __cplusplus
}
#endif

#endif  /* __QL_SMS_H__ */
