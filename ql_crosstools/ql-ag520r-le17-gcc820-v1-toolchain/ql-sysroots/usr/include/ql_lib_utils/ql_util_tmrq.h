/*-----------------------------------------------------------------------------------------------*/
/**
  @file qlu_util_tmrq.h
  @brief Timer queue, all APIs are thread safe
*/
/*-----------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
  EDIT HISTORY
  This section contains comments describing changes made to the file.
  Notice that changes are listed in reverse chronological order.
  $Header: $
  when       who          what, where, why
  --------   ---          ----------------------------------------------------------
  20180809   tyler.kuang  Created .
-------------------------------------------------------------------------------------------------*/

#ifdef __cplusplus
 extern "C" {
#endif


#ifndef __QL_UTIL_TMRQ_H__
#define __QL_UTIL_TMRQ_H__

#include <stdint.h>
#include "ql_util_list.h"
#include "ql_util_mutex.h"


#define QLU_TMRQ_MAX_LEN_DEFAULT 100


typedef struct qlu_tmrq_handle_struct {
    qlu_mutex_t mutex;
    qlu_list_head_t list;
    int fd_push;
    int fd_pull;
    int tmr_index;
    int max_len;
} qlu_tmrq_handle_t;

typedef struct qlu_tmrq_item_struct {
    void *cmd;
    void *param;
    int  param_len;
    int  id;
    uint32_t expire_sec;
    uint32_t expire_usec;
    uint32_t interval_ms;
    int is_cycle;
    qlu_list_head_t next;
} qlu_tmrq_item_t;



/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Initializes the timer queue
  @param[out] h Timer queue handler 
  @param[in] max_len Max length of the timer queue, 0 meas using default (100)
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmrq_init(qlu_tmrq_handle_t *h, int max_len);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Add a timer to the queue 
  @param[in] h Timer queue handler 
  @param[in] cmd Command, user defined
  @param[in] param Parameter, user defined 
  @param[in] param_len Length of the parameter, user defined
  @param[in] interval_ms Timer timeout in millisecond
  @param[in] is_cycle Whether the timer is executed cyclically
  @return
  -1 - error ocurred \n
  other - timer id, range 1-2147483647(0x7FFFFFFF)
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmrq_tmr_add(qlu_tmrq_handle_t *h, void *cmd, void *param, int param_len, 
        uint32_t interval_ms, int is_cycle);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Check whether the timer is exist 
  @param[in] h Timer queue handler 
  @param[in] tmr_id Timer id 
  @return
  1 - timer is exist \n
  0 - timer is not exist 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmrq_tmr_is_exist(qlu_tmrq_handle_t *h, int tmr_id);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Delete the timer 
  @param[in] h Timer queue handler 
  @param[in] tmr_id Timer id 
  @return
  0 - succeed \n
  -1 - error ocurred 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmrq_tmr_del(qlu_tmrq_handle_t *h, int tmr_id);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Reset the timer 
  @param[in] h Timer queue handler 
  @param[in] tmr_id Timer id 
  @param[in] cmd Command, user defined
  @param[in] param Parameter, user defined 
  @param[in] param_len Length of the parameter, user defined
  @param[in] interval_ms Timer timeout in millisecond
  @param[in] is_cycle Whether the timer is executed cyclically
  @return
  0 - succeed \n
  -1 - error ocurred 
  1 - timer is not exist
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmrq_tmr_set(qlu_tmrq_handle_t *h, int tmr_id, void *cmd, void *param, int param_len, uint32_t interval_ms, int is_cycle);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Pull a timer item from the queue, maybe block
  @param[in] h Timer queue handler 
  @param[out] pitem Storage for timer item, must call qlu_tmrq_item_free to relase the item
  @return
  0 - timeout \n
  -1 - error ocurred
  1 - get a valid command item, parameter pitem is valid
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmrq_pull(qlu_tmrq_handle_t *h, qlu_tmrq_item_t **pitem);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Rlease a timer item 
  @param[in] item Getting from qlu_tmrq_pull 
  @return always 0 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmrq_item_free(qlu_tmrq_handle_t *h, qlu_tmrq_item_t *item);

#endif

#ifdef __cplusplus
} 
#endif

