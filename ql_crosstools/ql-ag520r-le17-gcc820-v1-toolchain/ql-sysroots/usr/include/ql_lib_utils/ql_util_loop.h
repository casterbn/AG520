/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_util_loop.h
  @brief Event loopper interface for single-threaded framework
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
  20180318   tyler.kuang  Created .
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_UTIL_LOOP_H__
#define __QL_UTIL_LOOP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>


#define QLU_EVENT_MASK_WRITE  ((uint32_t)1<<0)
#define QLU_EVENT_MASK_READ   ((uint32_t)1<<1)

typedef void (*qlu_loop_cb_f)(int fd, uint32_t evt_mask, void *user_data);
typedef void (*qlu_loop_fds_cb_f)(fd_set *rfds, fd_set *wfds, void *user_data);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Initialize event loopper
  @param[in] max_event Maximum number of events supported, 0 is default (20)
  @return 
  0 - successful
  -1 -  error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_loop_init(int max_event);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Add a file a file descriptor to event loopper 
  @param[in] fd File descriptor, as socket, pipe, device node 
  @param[in] evt_mask Composed of QLU_EVENT_MASK* 
  @param[in] evt_cb Callback function 
  @param[in] user_data User-defined parameters
  @return 
  0 - successful
  -1 - more than the maximum number
  -2 - invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_loop_add(int fd, uint32_t evt_mask, qlu_loop_cb_f evt_cb, void *user_data);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Add sets of file descriptors to event loopper 
  @param[in] rfds Sets of file descriptors for reading
  @param[in] rfds_max_fd Highest-numbered file descriptor for reading
  @param[in] wfds Sets of file descriptors for writting
  @param[in] wfds_max_fd Highest-numbered file descriptor for writing
  @param[in] evt_cb Callback function 
  @param[in] user_data User-defined parameters
  @return 
  0 - successful
  -1 - more than the maximum number
  -2 - the file descriptor is exist 
  -3 - invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_loop_add_fds(fd_set *rfds,int rfds_max_fd, 
        fd_set *wfds, int wfds_max_fd, 
        qlu_loop_fds_cb_f evt_cb, void *user_data);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Remove a file a file descriptor to event loopper 
  @param[in] fd File descriptor, as socket, pipe, device node 
  @return 
  0 - successful
  -1 - the specified file descriptor could not be found
  -2 - invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_loop_remove(int fd);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Remove sets of file descriptors from event loopper 
  @param[in] rfds Sets of file descriptors for reading
  @param[in] wfds Sets of file descriptors for writting
  @return 
  0 - successful
  -1 - the specified file descriptor could not be found
  -2 - invalid arguments
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_loop_remove_fds(fd_set *rfds, fd_set *wfds);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Execute once and return immediately 
  @param[in] timeout_ms Timeout in millisecond, -1-loop forever, 0-return immediately, 
  >0-Loop specified time and return
  @return 
  >=0 - number of events processed
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_loop_run(int timeout_ms);


#ifdef __cplusplus
} 
#endif

#endif

