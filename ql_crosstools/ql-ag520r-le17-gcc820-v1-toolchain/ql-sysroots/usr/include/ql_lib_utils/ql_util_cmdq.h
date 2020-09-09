/*-----------------------------------------------------------------------------------------------*/
/**
  @file qlu_cmdq.h
  @brief Command queue API (FIFO), all APIs are thread safe
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

#ifndef __qlu_cmdq_H__
#define __qlu_cmdq_H__
#include "ql_util_list.h"
#include "ql_util_mutex.h"     


#define QLU_CMDQ_MAX_LEN_DEFAULT 100


typedef struct qlu_cmdq_handle_struct {
    qlu_mutex_t mutex;
    qlu_list_head_t list;
    int fd_push;
    int fd_pull;
    int max_len;
} qlu_cmdq_handle_t;

typedef struct {
    void * cmd;
    void * param;
    int  param_len;
    qlu_list_head_t next;
} qlu_cmdq_item_t;


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Initializes the command queue
  @param[out] h Command queue handler 
  @param[in] max_len Max length of the command queue
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_cmdq_init(qlu_cmdq_handle_t *h, int max_len);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Push a command to the queue 
  @param[in] h Command queue handler 
  @param[in] cmd Command, user defined
  @param[in] param Parameter, user defined 
  @param[in] param_len Length of the parameter, user defined
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_cmdq_cmd_push(qlu_cmdq_handle_t *h, void *cmd, void *param, int param_len);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Pull a command from the queue(FIFO), maybe block
  @param[in] h Command queue handler 
  @param[in] timeout_ms Timeout in millisecond 
  @param[out] pcmd Storage for command item, must call qlu_cmdq_item_free to release the item
  @return
  0 - timeout \n
  -1 - error ocurred
  1 - get a valid command item, parameter pcmd is valid
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_cmdq_pull(qlu_cmdq_handle_t *h, int timeout_ms, qlu_cmdq_item_t **pcmd);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Get the file descriptors of the queue 
  @param[in] h Command queue handler 
  @return file descriptors of the queue
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_cmdq_get_fd(qlu_cmdq_handle_t *h);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Rlease a command item 
  @param[in] h Command queue handler 
  @param[in] item Getting from qlu_cmdq_pull 
  @return always 0 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_cmdq_item_free(qlu_cmdq_handle_t *h, qlu_cmdq_item_t *item);

#endif

#ifdef __cplusplus
} 
#endif

