/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_can.h 
  @brief Inject CAN information to CAN service
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
  20191209   tyler.kuang  Create
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_CAN_H__
#define __QL_CAN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Check can service initialization is ready. Note that the following APIs can only be invoked 
  after the can service is ready.
  @return 
  QL_ERR_OK - CAN service is ready
  QL_ERR_SERVICE_NOT_READY - CAN service is not ready, need to wait and recheck
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_can_is_ready(void);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Inject speed information to CAN service (QDR). Note that the speed unit is m/h
  @param[in] timestamp Timestamp in ms
  @param[in] data Speed info in M/H
  @return 
  QL_ERR_OK - successful
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_can_send_speed(int64_t timestamp, uint32_t data);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Inject gear info to CAN service (QDR).
  @param[in] timestamp Timestamp in ms
  @param[in] data Gear info, 0-Park, 1-Neutral, 3-Reverse, 4-Forward
  @return 
  QL_ERR_OK - successful
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_can_send_gear(int64_t timestamp, uint32_t data);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Inject speed info bufferd in MCU or kernel to CAN service (QDR). Note that speed unit is M/H
  @param[in] timestamp Timestamp in ms
  @param[in] data Speed info in M/H
  @return 
  QL_ERR_OK - successful
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_can_send_speed_buffer(int64_t timestamp, uint32_t data);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Inject gear info bufferd in MCU or kernel to CAN service (QDR).
  @param[in] timestamp Timestamp in ms
  @param[in] data Gear info, 0-Park, 1-Neutral, 3-Reverse, 4-Forward
  @return 
  QL_ERR_OK - successful
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_can_send_gear_buffer(int64_t timestamp, uint32_t data);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Inject suspend signal to CAN service, CAN service will save key info to ROM
  @param[in] timestamp Timestamp in ms
  @param[in] data Reserved, not used
  @return 
  QL_ERR_OK - successful
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_can_send_suspend(int64_t timestamp, uint32_t data);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Inject resume signal to CAN service
  @param[in] timestamp Timestamp in ms
  @param[in] data Reserved, not used
  @return 
  QL_ERR_OK - successful
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_can_send_resume(int64_t timestamp, uint32_t data);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Inject shutdown signal to CAN service, CAN service will save key info to ROM, 
  then system will shut down
  @param[in] timestamp Timestamp in ms
  @param[in] data Reserved, not used
  @return 
  QL_ERR_OK - successful
  Other - error code defined by ql_type.h
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_can_send_shutdown(int64_t timestamp, uint32_t data);

#ifdef __cplusplus
}
#endif

#endif

