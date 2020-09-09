/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_util_mem.h
  @brief Simplified macro for memory allocation and release (support memory tracking).
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

#ifndef __QL_UTIL_MEM_H__
#define __QL_UTIL_MEM_H__
#include <stdio.h>


#define QLU_MEM_ALLOC(size) _qlu_mem_alloc(__FUNCTION__, __LINE__, size)
#define QLU_MEM_FREE(ptr) _qlu_mem_free(__FUNCTION__, __LINE__, (void*)(ptr))


void * _qlu_mem_alloc(const char *func, int line, int size);
void _qlu_mem_free(const char *func, int line, void *ptr);
void qlu_mem_dump(FILE *fp); 


#endif

