/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_atc.h 
  @brief AT command API
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
  20191225   stan.li      Modify function description.
  20191225   solomon.cui  Fix possible null pointer dereference.
  20190702   stan.li      Created .
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_ATC_H__
#define __QL_ATC_H__

#ifdef __cplusplus
extern "C" {
#endif

#define QL_ATC_MAX_REQ_MSG_LEN   513    /**<  Maximum request message size. */
#define QL_ATC_MAX_RESP_MSG_LEN  4097   /**<  Maximum response message size. */

typedef void (*ql_atc_async_cb)(int async_index, char *req_buf, char *rsp_buf);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Initialize ATC service.
  @note You must call this function before other functions can be used in this module.
  @return Whether the ATC service was successfully intialized.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_atc_init(void);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief send at command async.
  @param[in] req_buf At command request content
  @param[out] async_index Async AT command index
  @param[in] async_cb Async callback function
  @return Whether to successfully send the AT command asynchronously
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_atc_send_async(char *req_buf, int *async_index, void *async_cb);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief send AT command.
  @param[in] req_buf At command request content
  @param[in] rsp_buf At command response content
  @param[in] rsp_len The length of rsp_buf
  @return Whether to successfully send AT command
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_atc_send(char *req_buf, char *rsp_buf, int rsp_len);


#ifdef __cplusplus
}
#endif


#endif
