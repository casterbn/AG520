/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_util_mutex.h
  @brief Simplified macro for mutex (support mutex tracking).
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

#ifndef __QL_UTIL_MUTEX_H__
#define __QL_UTIL_MUTEX_H__
#include <pthread.h>

#define QLU_MUTEX_LOCK(mutex)   _qlu_mutex_lock(__FUNCTION__, __LINE__, mutex)
#define QLU_MUTEX_UNLOCK(mutex) _qlu_mutex_unlock(__FUNCTION__, __LINE__, mutex)

typedef pthread_mutex_t qlu_mutex_t;

int qlu_mutex_init(qlu_mutex_t *mutex, const char *name);
int qlu_mutex_destroy(qlu_mutex_t *mutex);

int _qlu_mutex_lock(const char *func, int line, qlu_mutex_t *mutex);
int _qlu_mutex_unlock(const char *func, int line, qlu_mutex_t *mutex);

int qlu_mutex_dump(FILE *fp);

#endif

