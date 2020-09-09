/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_util_rawdata.h
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
  20200611   baker.liu    Created .
-------------------------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _QL_RAWDATA_API_H_
#define _QL_RAWDATA_API_H_

#include "ql_util_rawdata_item.h"

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief rawdata write interface
  @param[in] id Item ID in the rawdata block
  @param[in] data Value to write to rawdata block
  @param[in] len Length of the value write to rawdata block
  @return
  len - successful \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_rawdata_write_item(int id, void* data, int len);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief rawdata read interface
  @param[in] id Item ID in the rawdata block
  @param[out] data Value from rawdata block
  @param[in] len Length of the read data from rawdata block
  @return
  len - successful \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_rawdata_read_item(int id, void* data, int len);

#endif //_QL_RAWDATA_API_H_

#ifdef __cplusplus
}
#endif
