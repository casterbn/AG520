/*-----------------------------------------------------------------------------------------------*/
/**
  @file qlu_util_tmr.h
  @brief Simple timer implementation
*/
/*-----------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
  EDIT HISTORY
  This section contains comments describing changes made to the file.
  Notice that changes are listed in reverse chronological order.
  $Header: $
  when       who          what, where, why
  --------   ---          ----------------------------------------------------------
  20180319   tyler.kuang  Created .
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_UTIL_TMR_H__
#define __QL_UTIL_TMR_H__

#include <stdint.h>

typedef enum QLU_TMR_TYPE_E
{
    QLU_TMR_TYPE_MIN = -1,
    QLU_TMR_TYPE_NORMAL = 0,
    QLU_TMR_TYPE_ALARM = 1,   /* support system wakeup */
    QLU_TMR_TYPE_MAX
} QLU_TMR_TYPE_E;

typedef void (*qlu_tmr_handle_f)(int tmr_id, void *user_data);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Initializes timer service 
  @param[in] max_len Max length of the command queue
  @return
  0 - successful
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmr_init(void);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Create a software timer 
  @param[in] type Defined by QLU_TMR_TYPE_E
  @return
  >0 - time ID,  \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmr_create(QLU_TMR_TYPE_E type);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Configuring the timer
  @param[in] tmr_id Timer ID 
  @param[in] interval_ms Timer period in millisecond
  @param[in] is_repeat Whether it is a loop timer
  @param[in] cb Timer timeout callback function
  @return
  0 - successful
  -1 - error ocurred 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmr_set(int tmr_id, int interval_ms, int is_repeat, qlu_tmr_handle_f cb, void *user_data);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Start the timer
  @param[in] tmr_id Timer ID 
  @return
  0 - successful \n
  -1 - error ocurred 
  -2 - timer is not exist
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmr_start(int tmr_id);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Stop the timer
  @param[in] tmr_id Timer ID 
  @return
  0 - successful
  -1 - error ocurred 
  -2 - timer is not exist
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmr_stop(int tmr_id);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Get the timer status
  @param[in] tmr_id Timer ID 
  @return
  0 - timer exists but does not run\n
  1 - timer is running
  -1 - error ocurred 
  -2 - timer is not exist
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmr_status(int tmr_id);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Delete the timer status
  @param[in] tmr_id Timer ID 
  @return
  0 - successful 
  -1 - error ocurred 
  -2 - timer is not exist
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_tmr_delete(int tmr_id);

#endif

