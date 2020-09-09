/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_data_call.h 
  @brief Data service API 
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

#ifndef __QL_DATA_CALL_H__
#define __QL_DATA_CALL_H__
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "ql_net_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void ql_data_call_param_t; 

typedef struct
{
    int call_id;
    char call_name[QL_NET_MAX_NAME_LEN];
    QL_NET_DATA_CALL_STATUS_E call_status;
    char device[QL_NET_MAX_NAME_LEN];
    uint8_t has_addr;  /**< Valid when data call state is connected*/
    ql_net_addr_t addr;
    uint8_t has_addr6; /**< Valid when data call state is connected*/
    ql_net_addr6_t addr6;
    int call_end_reason_type;  /**< Last data call disconnect reason type */
    int call_end_reason_code;  /**< Last data call disconnect reason code */
} ql_data_call_status_t;

typedef struct
{
    int call_id;
    char call_name[QL_NET_MAX_NAME_LEN];
} ql_data_call_item_t;

typedef struct
{
    QL_NET_IP_VER_E ip_ver;
    QL_NET_AUTH_PREF_E auth_pref;
    char apn_name[QL_NET_MAX_APN_NAME_LEN];
    char username[QL_NET_MAX_APN_USERNAME_LEN];
    char password[QL_NET_MAX_APN_PASSWORD_LEN];
} ql_data_call_apn_config_t;

typedef void (*ql_data_call_status_ind_cb_f)(int call_id, 
        QL_NET_DATA_CALL_STATUS_E pre_call_status,
        ql_data_call_status_t *p_msg);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Initialize the data call service
  @return 
  QL_ERR_OK - successful
  QL_ERR_INVALID_ARG - as defined
  QL_ERR_UNKNOWN - unknown error, failed to connect to service
  QL_ERR_SERVICE_NOT_READY - service is not ready, need to retry
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_init(void);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Create a data call instance 
  @param[in] call_id The unique identifier of the data call instance, specified by the user
  @param[in] call_name Friendly data call name,  specified by the user
  @param[in] is_background Whether the data call status is maintained by the data call service daemon.
  If it is 0, the data call instance will be deleted after the data call process exits.
  @return 
  QL_ERR_OK - successful
  QL_ERR_INVALID_ARG - as defined
  QL_ERR_UNKNOWN - unknown error, failed to connect to service
  QL_ERR_SERVICE_NOT_READY - service is not ready, need to retry
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_create(int call_id, const char *call_name, int is_background);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Alloc for a data call configuration instance
  @return 
  NULL - Not enough memory
  Other - successful 
  */
/*-----------------------------------------------------------------------------------------------*/
ql_data_call_param_t *ql_data_call_param_alloc(void);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Initialize the data call configuration instance
  @param[in] param Point to the data call configuration instance
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_init(ql_data_call_param_t *param);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Release the data call configuration instance
  @param[in] param Point to the data call configuration instance
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_free(ql_data_call_param_t *param);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Bind APN ID, range:1-16
  @param[in] param Point to the data call configuration instance
  @param[in] apn_id APN ID, range:1-16
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_set_apn_id(ql_data_call_param_t *param, int apn_id);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get APN name from configuration instance
  @param[in] param Point to the data call configuration instance
  @param[out] buf APN ID 
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_get_apn_id(ql_data_call_param_t *param, int *apn_id);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Configure APN name 
  @param[in] param Point to the data call configuration instance
  @param[in] apn_name APN name 
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_set_apn_name(ql_data_call_param_t *param, const char *apn_name);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get APN name from configuration instance
  @param[in] param Point to the data call configuration instance
  @param[out] buf APN name buffer 
  @param[in] buf_len APN name buffer size
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_get_apn_name(ql_data_call_param_t *param, char *buf, int buf_len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Configure APN user name 
  @param[in] param Point to the data call configuration instance
  @param[in] user_name APN user name
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_set_user_name(ql_data_call_param_t *param, const char *user_name);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get APN user name from configuration instance
  @param[in] param Point to the data call configuration instance
  @param[out] buf APN user name buffer
  @param[in] buf_len APN user name buffer size
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_get_user_name(ql_data_call_param_t *param, char *buf, int buf_len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Configure APN user password 
  @param[in] param Point to the data call configuration instance
  @param[in] user_password APN user password
  @return 
  QL_ERR_OK - Not enough memory 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_set_user_password(ql_data_call_param_t *param, const char *user_password);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get APN user password from configuration instance
  @param[in] param Point to the data call configuration instance
  @param[out] buf APN user password buffer
  @param[in] buf_len APN user password buffer size
  @return 
  QL_ERR_OK - Not enough memory 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_get_user_password(ql_data_call_param_t *param, char *buf, int buf_len);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Configure the data call authentication method
  @param[in] param Point to the data call configuration instance
  @param[in] auth_pref Defined by QL_DATA_CALL_AUTH_PREF_E  
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_set_auth_pref(ql_data_call_param_t *param, int auth_pref);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Configure the data call authentication method
  @param[in] param Point to the data call configuration instance
  @param[out] p_data Store return value
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_get_auth_pref(ql_data_call_param_t *param, int *p_data);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Configure the data call IP version 
  @param[in] param Point to the data call configuration instance
  @param[in] ip_ver Defined by QL_NET_IP_VER_E 
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_set_ip_version(ql_data_call_param_t *param, int ip_ver);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get IP version from configuration instance
  @param[in] param Point to the data call configuration instance
  @param[out] p_ver Store return value
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_get_ip_version(ql_data_call_param_t *param, int *p_ver);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Configure the data call auto reconnection mode
  @param[in] param Point to the data call configuration instance
  @param[in] mode Defined by QL_NET_DATA_CALL_RECONNECT_MODE_E  
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_set_reconnect_mode(ql_data_call_param_t *param, int reconnect_mode);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get auto reconnection mode from configuration instance
  @param[in] param Point to the data call configuration instance
  @param[out] p_mode Store return value 
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_get_reconnect_mode(ql_data_call_param_t *param, int *p_mode);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Configure the data call auto reconnection interval
  @param[in] param Point to the data call configuration instance
  @param[in] time_list Interval time list in ms
  @param[in] num Number of time list
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_set_reconnect_interval(ql_data_call_param_t *param, int *time_list, int num);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get auto reconnection interval from configuration instance
  @param[in] param Point to the data call configuration instance
  @param[out] time_list Store return value 
  @param[in,out] p_num 
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_param_get_reconnect_interval(ql_data_call_param_t *param, int *time_list, int *p_num);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Configure the specified data call instance
  @param[in] call_id Specify a data call instance
  @param[in] param Point to the data call configuration instance
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_config(int call_id, ql_data_call_param_t *param);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get the specified data call configuration instance
  @param[in] call_id Specify a data call instance
  @param[in] param Point to the data call configuration instance
  @return 
  QL_ERR_OK - Successful 
  QL_ERR_INVALID_ARG - Invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_get_config(int call_id, ql_data_call_param_t *param);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Start data call 
  @param[in] call_id Specify a data call instance
  @return 
  QL_ERR_OK - successful
  QL_ERR_NOT_INIT - uninitialized
  QL_ERR_SERVICE_NOT_READY - service is not ready
  QL_ERR_INVALID_ARG - Invalid arguments
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_start(int call_id);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Stop data call 
  @param[in] call_id Specify a data call instance
  @return 
  QL_ERR_OK - successful
  QL_ERR_NOT_INIT - uninitialized
  QL_ERR_SERVICE_NOT_READY - service is not ready
  QL_ERR_INVALID_ARG - Invalid arguments
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_stop(int call_id);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Delete a data call instance
  @param[in] call_id Specify a data call instance
  @return 
  QL_ERR_OK - successful
  QL_ERR_NOT_INIT - uninitialized
  QL_ERR_SERVICE_NOT_READY - service is not ready
  QL_ERR_INVALID_ARG - Invalid arguments
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_delete(int call_id);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get the current data call instance list
  @param[out] list Data call instance array
  @param[in,out] list_len, in-> Data call instance array size, out->current data call instance number
  @return 
  QL_ERR_OK - successful
  QL_ERR_NOT_INIT - uninitialized
  QL_ERR_SERVICE_NOT_READY - service is not ready
  QL_ERR_INVALID_ARG - Invalid arguments
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_get_list(ql_data_call_item_t *list, int *list_len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get the data call status
  @param[in] call_id Specify a data call instance
  @param[out] p_sta Point to status instance 
  @return 
  QL_ERR_OK - successful
  QL_ERR_NOT_INIT - uninitialized
  QL_ERR_SERVICE_NOT_READY - service is not ready
  QL_ERR_INVALID_ARG - Invalid arguments
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_get_status(int call_id, ql_data_call_status_t *p_sta);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Register data call status change event
  @param[in] cb 
  @return 
  QL_ERR_OK - successful
  QL_ERR_NOT_INIT - uninitialized
  QL_ERR_SERVICE_NOT_READY - service is not ready
  QL_ERR_INVALID_ARG - Invalid arguments
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_set_status_ind_cb(ql_data_call_status_ind_cb_f cb);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Set APN related configuration.If the apn does not exist, it is automatically created.
  @param[in] apn_id APN ID, range:1-16
  @param[in] p_info APN configuration
  @return 
  QL_ERR_OK - successful
  QL_ERR_NOT_INIT - uninitialized
  QL_ERR_SERVICE_NOT_READY - service is not ready
  QL_ERR_INVALID_ARG - Invalid arguments
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_set_apn_config(int apn_id, ql_data_call_apn_config_t *p_info);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief  Set APN related configuration. If the apn does not exist, it is automatically created and 
  the default parameters are set.
  @param[in] apn_id APN ID, range:1-16
  @param[out] p_info APN configuration
  @return 
  QL_ERR_OK - successful
  QL_ERR_NOT_INIT - uninitialized
  QL_ERR_SERVICE_NOT_READY - service is not ready
  QL_ERR_INVALID_ARG - Invalid arguments
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_data_call_get_apn_config(int apn_id, ql_data_call_apn_config_t *p_info);

#ifdef __cplusplus
} 
#endif

#endif

