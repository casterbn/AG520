/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_util_record.h
  @brief Record information to file
*/
/*-----------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
  EDIT HISTORY
  This section contains comments describing changes made to the file.
  Notice that changes are listed in reverse chronological order.
  $Header: $
  when       who          what, where, why
  --------   ---          ----------------------------------------------------------
  20200717   tyler.kuang  Created .
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_UTIL_RECORD_H__
#define __QL_UTIL_RECORD_H__
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct qlu_rec_struct {
    char file_name[256];
    int limit_cnt;
    int limit_size;
    int file_size;
    FILE *fp;
    int multi_process;
    pthread_mutex_t mutex;
} qlu_rec_t;



/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Initialization
  @param[out] h Point to handle 
  @return 
  0 - succeed
  -1 - Invalid parameter
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_rec_init(qlu_rec_t *h);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Configuration  
  @param[in] p_h Point to handle
  @param[in] file_name The file name of the record information
  @param[in] limit_size Size of a single file, unit is Byte
  @param[in] limit_cnt Maximum number of files
  @param[in] multi_process Is multithreading supported,0-unsupport, 1-support
  @return 
  0 - succeed
  -1 - Invalid parameters
  -2 - parameter 'file_name' is invalid
  -3 - Failed to open file
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_rec_cfg(qlu_rec_t *h, const char *file_name, int limit_size, int limit_cnt, int multi_process);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Record information 
  @param[in] h Point to handle
  @param[in] fmt Such as printf 
  @return 
  0 - succeed
  -1 - Invalid parameters
  -2 - Internal error, handle is uninitialized 
  -3 - Failed to write file, check errno
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_rec_print(qlu_rec_t *h, const char *fmt, ...);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Record information 
  @param[in] h Point to handle
  @param[in] buf Data buffer 
  @param[in] len BUffer length
  @return 
  0 - succeed
  -1 - Invalid parameters
  -2 - Internal error, handle is uninitialized 
  -3 - Failed to write file, check errno
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_rec_write(qlu_rec_t *h, void *buf, int len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief De initialization
  @param[in] p_h Point to handle 
  @return 
  0 - succeed
  -1 - Invalid parameters
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_rec_uinit(qlu_rec_t *h);

#ifdef __cplusplus
} 
#endif

#endif

