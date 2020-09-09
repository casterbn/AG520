/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_dm.h 
  @brief device management API
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
  20200316   stan.li      Optimize the ql_dm_get_modem_state interface
  20191224   stan.li      Add radio on/off API
  20190625   stan.li      Created .
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_DM_H__
#define __QL_DM_H__

#ifdef __cplusplus
extern "C" {
#endif

#define QL_DM_IMEI_MAX_LEN             32
#define QL_DM_MEID_MAX_LEN             32
#define QL_DM_FIRMWARE_REV_MAX_LEN     256
#define QL_DM_NV_ITEM_NAME_MAX_LEN     127
#define QL_DM_NV_ITEM_VALUE_MAX_LEN    4096

//enable
#define QL_DM_QOOS_ENABLE_MAX          2
#define QL_DM_QOOS_ENABLE_MIN          0

//pre_time
#define QL_DM_QOOS_PRE_TIME_MAX        600
#define QL_DM_QOOS_PRE_TIME_MIN        1

//sleep_time
#define QL_DM_QOOS_SLEEP_TIME_MAX      (60*60*12)
#define QL_DM_QOOS_SLEEP_TIME_MIN      1

//acq_time
#define QL_DM_QOOS_ACQ_TIME_MAX        600
#define QL_DM_QOOS_ACQ_TIME_MIN        1

//cir_cnt
#define QL_DM_QOOS_CIR_CNT_MAX         255
#define QL_DM_QOOS_CIR_CNT_MIN         1

//sleep_step
#define QL_DM_QOOS_SLEEP_STEP_MAX      60
#define QL_DM_QOOS_SLEEP_STEP_MIN      0

//acq_step
#define QL_DM_QOOS_ACQ_STEP_MAX        60
#define QL_DM_QOOS_ACQ_STEP_MIN        0        

//adj_cnt
#define QL_DM_QOOS_ADJ_CNT_MAX         5
#define QL_DM_QOOS_ADJ_CNT_MIN         0

//idle_interval
#define QL_DM_QOOS_IDLE_INTERVAL_MAX   60
#define QL_DM_QOOS_IDLE_INTERVAL_MIN   1

typedef enum QL_DW_AIR_PLANE_MODE_TYPE_ENUM
{
    QL_DM_AIR_PLANE_MODE_UNKNOWN   = 0,    /**<  Radio online. */
    QL_DM_AIR_PLANE_MODE_ON        = 1,    /**<  Radio power off or unknown. Airplane ON. */
    QL_DM_AIR_PLANE_MODE_OFF       = 2,    /**<  Radio online. Airplane OFF. */
    QL_DM_AIR_PLANE_MODE_NA        = 3     /**<  Radio Unvailable. */
}QL_DM_AIR_PLANE_MODE_TYPE_E;

typedef enum QL_DM_MODEM_STATE_TYPE_ENUM
{
    QL_DM_MODEM_STATE_UNKNOWN,
    QL_DM_MODEM_STATE_ONLINE,
    QL_DM_MODEM_STATE_OFFLINE
}QL_DM_MODEM_STATE_TYPE_E;

typedef enum QL_DM_QOOS_ENABLE_TYPE_ENUM
{
    QL_DM_QOOS_ENABLE_STATE_OFF           = 0,  /**<  close QOOS function. */
    QL_DM_QOOS_ENABLE_STATE_ON_NO_SERVICE = 1,  /**<  open QOOS function in no service state. */
    QL_DM_QOOS_ENABLE_STATE_ON            = 2,  /**<  open QOOS function in no and limited service state. */
}QL_DM_QOOS_ENABLE_TYPE_E;

typedef struct {
    uint16_t pre_time;      /**<  the upper limit of the first search time, range is 1 to 600, default value is 180, in seconds. */
    uint16_t sleep_time;    /**<  the first sleep time, range is 1 to 43200, default value is 30, in seconds. */
    uint16_t acq_time;      /**<  the first search time, range is 1 to 600, default value is 20, in seconds. */
    uint8_t cir_cnt;        /**<  the number of sleep->search cycle, range is 5 to 255, default value is 10, in seconds. */
    uint8_t sleep_step;     /**<  the sleep time increment, range is 0 to 60, default vaue is 15, in seconds. */
    uint8_t acq_step;       /**<  the acq time increment, range is 0 to 60, default value is 0, in seconds. */
    uint8_t adj_cnt;        /**<  the adjustment times for sleep-search cylce, range is 0 to 5, default value is 2, in seconds. */
    uint8_t idle_interval;  /**<  when the module is registered, check whether the module if offline, range is 1 to 60,default value is 1, in seconds. */
}ql_dm_qoos_config_t;

typedef struct 
{
    uint8_t imei_valid; 
    char imei[QL_DM_IMEI_MAX_LEN + 1];    /**<  imei.*/
    uint8_t meid_valid; 
    char meid[QL_DM_MEID_MAX_LEN + 1];    /**<  meid.*/
}ql_dm_device_serial_numbers_info_t;


typedef void (*ql_dm_air_plane_mode_ind_cb)(QL_DM_AIR_PLANE_MODE_TYPE_E air_plane_mode);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Initialize DM service.
  @note You must call this function before other functions can be used in this module.
  @return Whether the DM service was successfully intialized.
  @retval QL_ERR_OK successful.
  @retval QL_ERR_SERVICE_NOT_READY service is not ready, need to retry.
  @retval Other error code defined by ql_type.h.
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_init(void);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get device software version.
  @param[out] soft_ver Return software version
  @param[in] soft_ver_len The length of soft_ver
  @return Whether to successfully get the software version
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_software_version(char *soft_ver, int soft_ver_len);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get modem state.
  @details QL_DM_MODEM_STATE_ONLINE,if modem starts normally.
  @details QL_DM_MODEM_STATE_OFFLINE,in modem starts abnormally.
  @details QL_DM_MODEM_STATE_UNKNOWN,unknown error.
  @param[out] modem_state The state of modem
  @return Whether to successfully get the modem state
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_modem_state(QL_DM_MODEM_STATE_TYPE_E *modem_state);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get module temperature.
  @param[out] temperature The current temperature
  @return Whether to successfully get the temperature
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_temperature(float *temperature);

    
/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get device serial numbers.
  @param[out] p_info Pointer that point to ql_dm_device_serial_numbers_info_t
  @return Whether to successfully get the serial numbers
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_device_serial_numbers(ql_dm_device_serial_numbers_info_t *p_info);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get device firmware revision identification.
  @param[out] firmware_rev_id Return device firmware revision id
  @param[in] firmware_rev_id_len The length of firmware_rev_id
  @return Whether to successfully get the firmware revision id
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_device_firmware_rev_id(char *firmware_rev_id, int firmware_rev_id_len);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get air plane mode.
  @param[out] p_info Pointer that point to QL_DM_AIR_PLANE_MODE_TYPE_E
  @return Whether to successfully get the air plane mode
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_air_plane_mode(QL_DM_AIR_PLANE_MODE_TYPE_E *p_info);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief set air plane mode.
  @param[in] air_plane_mode 1:ON, 2:OFF
  @return Whether to successfully set the air plane mode
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_set_air_plane_mode(QL_DM_AIR_PLANE_MODE_TYPE_E air_plane_mode);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief register air plane mode event.
  @param[in] cb_func Air plane mode indication callback function
  @return Whether the air plane mode event was successfully registered.
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_set_air_plane_mode_ind_cb(ql_dm_air_plane_mode_ind_cb cb_func);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get cpu occupancy.
  @param[out] cpu_occupancy The percentage of cpu occupancy
  @return Whether to successfully get the cpu occupancy
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_cpu_occupancy(float *cpu_occupancy);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get mem usage.
  @param[out] mem_use The percentage of mem usage
  @return Whether to successfully get the memory usage
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_mem_usage(float *mem_use);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get NV item value.
  @param[in] nv_item_name The NV item name that is either NV item id or NV item path
  @param[out] nv_item_value The NV value buf of nv_item_name
  param[in] nv_item_value_len The length of nv_item_value
  param[out] nv_len The real length of nv_item_name
  @return Whether to successfully get the NV value
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_nv_item_value(char *nv_item_name, unsigned char *nv_item_value, int nv_item_value_len, 
        int *nv_len);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief set NV item value.
  @param[in] nv_item_name The NV item name that is either NV item id or NV item path
  @param[in] nv_item_value The NV value of nv_item_name
  @param[in] nv_item_value_len The length of nv_item_value
  param[out] nv_len The real length of nv_item_name
  @return Whether to successfully set the NV value
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_set_nv_item_value(char *nv_item_name, unsigned char *nv_item_value, int nv_item_value_len, 
        int *nv_len);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief set radio on, its function is the same as at+cfun=1.
  @return Whether to successfully set the radio on
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_set_radio_on(void);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief set radio off, its function is the same as at+cfun=0.
  @return Whether to successfully set the radio off
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_set_radio_off(void);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get modem mem and CPU utilization.
  @param[out] mem_use The percentage of modem utilization
  @return Whether to successfully get the modem utilization
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_modem_cpu_occupancy(float *cpu_occupancy);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get modem mem utilization.
  @param[out] mem_use The percentage of modem utilization
  @return Whether to successfully get the modem utilization
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_modem_mem_usage(float *mem_use);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get QOOS enable state
  @param[out] enable The enable state of QOOS
  @return Whether to successfully get the QOOS enable state
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_qoos_enable(QL_DM_QOOS_ENABLE_TYPE_E *enable);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief set QOOS enable state
  @param[in] enable The enable state of QOOS
  @return Whether to successfully set the QOOS enable state
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_set_qoos_enable(QL_DM_QOOS_ENABLE_TYPE_E enable);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief get QOOS configuration
  @param[out] config The configuration of QOOS
  @return Whether to successfully get the QOOS configuration
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_get_qoos_config(ql_dm_qoos_config_t *config);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief set QOOS configuration
  @param[in] config The configuration of QOOS
  @return Whether to successfully set the QOOS configuration
  @retval QL_ERR_OK successful
  @retval QL_ERR_NOT_INIT uninitialized
  @retval QL_ERR_SERVICE_NOT_READY service is not ready
  @retval QL_ERR_INVALID_ARG Invalid arguments
  @retval Other error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_dm_set_qoos_config(ql_dm_qoos_config_t config);

#ifdef __cplusplus
}
#endif


#endif

