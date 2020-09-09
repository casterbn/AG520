/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_nf.h 
  @brief Network framework API 
*/
/*-----------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd. All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
  EDIT HISTORY
  This section contains comments describing changes made to the file.
  Notice that changes are listed in reverse chronological order.
  $Header: $
  when       who          what, where, why
  --------   ---          ----------------------------------------------------------
  20181024   tyler.kuang  Created .
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_NF_H__
#define __QL_NF_H__
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "ql_net_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char name[QL_NET_MAX_NAME_LEN];
    char ifname[QL_NET_MAX_NAME_LEN];
    char pre_status[16];
    char status[16];
    uint8_t has_addr;
    ql_net_addr_t addr;
    uint8_t has_addr6;
    ql_net_addr6_t addr6;
} ql_nf_interface_status_t;

typedef void (*ql_nf_interface_status_ind_cb_f)(ql_nf_interface_status_t *p_msg);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Initialize network service
  @return 
  QL_ERR_OK - successful
  QL_ERR_INVALID_ARG - as defined
  QL_ERR_UNKNOWN - unknown error, failed to connect to service
  QL_ERR_SERVICE_NOT_READY - service is not ready, need to retry
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nf_init(void);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Send a command and wait for a response
  @param[in] cmd Command
  @param[out] resp_buf Response 
  @param[in] resp_len Response buffer length 
  @return 
  QL_ERR_OK - successful
  QL_ERR_INVALID_ARG - as defined
  QL_ERR_UNKNOWN - unknown error, failed to connect to service
  QL_ERR_SERVICE_NOT_READY - service is not ready, need to retry
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nf_cmd(const char *cmd, char *resp_buf, int resp_len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Send a command and wait for a response
  @param[in] cmd Command
  @param[out] resp_buf Response 
  @param[in] resp_len Response buffer length 
  @return 
  QL_ERR_OK - successful
  QL_ERR_INVALID_ARG - as defined
  QL_ERR_UNKNOWN - unknown error, failed to connect to service
  QL_ERR_SERVICE_NOT_READY - service is not ready, need to retry
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nf_cmd_json(const char *cmd, char *resp_buf, int resp_len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Register NF interface status change event event
  @param[in] cb 
  @return 
  QL_ERR_OK - successful
  QL_ERR_NOT_INIT - uninitialized
  QL_ERR_SERVICE_NOT_READY - service is not ready
  QL_ERR_INVALID_ARG - Invalid arguments
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_nf_set_interface_status_ind_cb(ql_nf_interface_status_ind_cb_f cb);


#ifdef __cplusplus
} 
#endif

#endif

