/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_net_usb_dev.h 
  @brief USB net device API 
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
  20190709   tyler.kuang  Created .
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_NET_USB_DEV_H__
#define __QL_NET_USB_DEV_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "ql_net_common.h"


typedef void (*ql_net_usb_dev_ind_cb_f)(const char *device,
        QL_NET_USB_DEV_STATUS_E pre_status,
        ql_net_usb_dev_t *p_dev);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Initialize the USB net device service
  @return 
  QL_ERR_OK - successful
  QL_ERR_INVALID_ARG - as defined
  QL_ERR_UNKNOWN - unknown error, failed to connect to service
  QL_ERR_SERVICE_NOT_READY - service is not ready, need to retry
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_net_usb_dev_init(void);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get USB network device status
  @param[in] device Device name, such as ecm0, rndis0..
  @param[out] p_dev Return device status information
  @return 
  QL_ERR_OK - successful
  QL_ERR_INVALID_ARG - as defined
  QL_ERR_UNKNOWN - unknown error, failed to connect to service
  QL_ERR_SERVICE_NOT_READY - service is not ready, need to retry
  QL_ERR_INTERFACE_NOT_FOUND - device does not exist
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_net_usb_dev_get_status(const char *device, ql_net_usb_dev_t *p_dev);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get all USB network device list
  @param[out] list USB network device array
  @param[in,out] list_len, in-> array size, out->current instance number
  @return 
  QL_ERR_OK - successful
  QL_ERR_INVALID_ARG - as defined
  QL_ERR_UNKNOWN - unknown error, failed to connect to service
  QL_ERR_SERVICE_NOT_READY - service is not ready, need to retry
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_net_usb_dev_get_list(ql_net_usb_dev_t *list, int *list_len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Set USB network device MTU. If it does not currently exist, then set it after the device 
  appears.
  @param[in] device Device name, such as ecm0, rndis0..
  @param[in] mtu MTU 
  @return 
  QL_ERR_OK - successful
  QL_ERR_INVALID_ARG - as defined
  QL_ERR_UNKNOWN - unknown error, failed to connect to service
  QL_ERR_SERVICE_NOT_READY - service is not ready, need to retry
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_net_usb_dev_set_mtu(const char *device, int mtu);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get USB network device MTU
  @param[in] device Device name, such as ecm0, rndis0..
  @param[out] p_mtu Reutn device MTU
  @return 
  QL_ERR_OK - successful
  QL_ERR_INVALID_ARG - as defined
  QL_ERR_UNKNOWN - unknown error, failed to connect to service
  QL_ERR_SERVICE_NOT_READY - service is not ready, need to retry
  QL_ERR_INTERFACE_NOT_FOUND - device does not exist
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_net_usb_dev_get_mtu(const char *device, int *p_mtu);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Set USB network device MAC address. If it does not currently exist, then set it after the device 
  appears.
  @param[in] device Device name, such as ecm0, rndis0..
  @param[in] macaddr MAC address, format: XX:XX:XX:XX:XX:XX 
  @return 
  QL_ERR_OK - successful
  QL_ERR_INVALID_ARG - as defined
  QL_ERR_UNKNOWN - unknown error, failed to connect to service
  QL_ERR_SERVICE_NOT_READY - service is not ready, need to retry
  QL_ERR_INTERFACE_NOT_FOUND - device does not exist
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_net_usb_dev_set_macaddr(const char *device, const char *macaddr);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get USB network device MAC address
  @param[in] device Device name, such as ecm0, rndis0..
  @param[out] macaddr_buf Return MAC address
  @param[in] buf_len Buffer size
  @return 
  QL_ERR_OK - successful
  QL_ERR_INVALID_ARG - as defined
  QL_ERR_UNKNOWN - unknown error, failed to connect to service
  QL_ERR_SERVICE_NOT_READY - service is not ready, need to retry
  QL_ERR_INTERFACE_NOT_FOUND - device does not exist
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_net_usb_dev_get_macaddr(const char *device, char *macaddr_buf, int buf_len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Register USB network device status change event
  @param[in] cb 
  @return 
  QL_ERR_OK - successful
  QL_ERR_NOT_INIT - uninitialized
  QL_ERR_SERVICE_NOT_READY - service is not ready
  QL_ERR_INVALID_ARG - Invalid arguments
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_net_usb_dev_set_ind_cb(ql_net_usb_dev_ind_cb_f cb);

#ifdef __cplusplus
} 
#endif

#endif

