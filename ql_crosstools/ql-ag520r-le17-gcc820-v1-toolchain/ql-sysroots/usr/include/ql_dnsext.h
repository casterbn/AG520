/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_dnsext.h
  @brief Extended domain name resolution 
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
  201810227  tyler.kuang  Created .
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_DNSEXT_H__
#define __QL_DNSEXT_H__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <netdb.h>

typedef enum
{
    QL_WWAN_TYPE_NONE = 0,
    QL_WWAN_TYPE_PUBLIC,    /** Internet */
    QL_WWAN_TYPE_PRIVATE1,  /** Private network 1 */
    QL_WWAN_TYPE_PRIVATE2,  /** Private network 2 */
    QL_WWAN_TYPE_PRIVATE3,  /** Private network 3 */
    QL_WWAN_TYPE_PRIVATE4,  /** Private network 4 */
    QL_WWAN_TYPE_PRIVATE5,  /** Private network 5 */
    QL_WWAN_TYPE_PRIVATE6,  /** Private network 6 */
    QL_WWAN_TYPE_PRIVATE7,  /** Private network 7 */
    QL_WWAN_TYPE_PRIVATE8   /** Private network 8 */
} QL_WWAN_TYPE_E;


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Get network host entry, Extended gethostbyname
  @param[in] name  Here name is either a hostname, or an IPv4 address in standard dot notation
  @param[in] wwan_type Defined by QL_WWAN_TYPE_E
  @return Returns a structure of type hostent for the given host name, same as gethostbyname
  */
/*-----------------------------------------------------------------------------------------------*/
struct hostent * ql_gethostbyname(const char *name, int wwan_type);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Check whether the specified network is connected 
  @param[in] wwan_type Defined by QL_WWAN_TYPE_E
  @return 
  1-Network is connected
  0-Network is disconnected 
  */
/*-----------------------------------------------------------------------------------------------*/
int ql_is_network_ready(int wwan_type);


#ifdef __cplusplus
} 
#endif

#endif

