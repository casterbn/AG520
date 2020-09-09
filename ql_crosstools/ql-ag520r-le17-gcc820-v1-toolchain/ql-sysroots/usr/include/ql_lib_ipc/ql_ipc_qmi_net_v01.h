#ifndef QL_NET_SERVICE_01_H
#define QL_NET_SERVICE_01_H
/**
  @file ql_ipc_qmi_net_v01.h

  @brief This is the public header file which defines the ql_net service Data structures.

  This header file defines the types and structures that were defined in
  ql_net. It contains the constant values defined, enums, structures,
  messages, and service message IDs (in that order) Structures that were
  defined in the IDL as messages contain mandatory elements, optional
  elements, a combination of mandatory and optional elements (mandatory
  always come before optionals in the structure), or nothing (null message)

  An optional element in a message is preceded by a uint8_t value that must be
  set to true if the element is going to be included. When decoding a received
  message, the uint8_t values will be set to true or false by the decode
  routine, and should be checked before accessing the values that they
  correspond to.

  Variable sized arrays are defined as static sized arrays with an unsigned
  integer (32 bit) preceding it that must be set to the number of elements
  in the array that are valid. For Example:

  uint32_t test_opaque_len;
  uint8_t test_opaque[16];

  If only 4 elements are added to test_opaque[] then test_opaque_len must be
  set to 4 before sending the message.  When decoding, the _len value is set
  by the decode routine and should be checked so that the correct number of
  elements in the array will be accessed.

*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  

  
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.7 
   It was generated on: Mon Oct 28 2019 (Spin 0)
   From IDL File: ql_ipc_qmi_net_v01.idl */

/** @defgroup ql_net_qmi_consts Constant values defined in the IDL */
/** @defgroup ql_net_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup ql_net_qmi_enums Enumerated types used in QMI messages */
/** @defgroup ql_net_qmi_messages Structures sent as QMI messages */
/** @defgroup ql_net_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup ql_net_qmi_accessor Accessor for QMI service object */
/** @defgroup ql_net_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup ql_net_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define QL_NET_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define QL_NET_V01_IDL_MINOR_VERS 0x01
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define QL_NET_V01_IDL_TOOL_VERS 0x06
/** Maximum Defined Message ID */
#define QL_NET_V01_MAX_MESSAGE_ID 0x0201
/**
    @}
  */


/** @addtogroup ql_net_qmi_consts
    @{
  */
#define QL_NET_MAX_MSG_LEN_V01 512
#define QL_NET_MAX_LONG_MSG_LEN_V01 3072
/**
    @}
  */

/** @addtogroup ql_net_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t msg_id;

  /* Mandatory */
  uint32_t msg_data_len;  /**< Must be set to # of elements in msg_data */
  uint8_t msg_data[QL_NET_MAX_MSG_LEN_V01];
}ql_ipc_qmi_net_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ql_net_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t msg_id;

  /* Mandatory */
  int32_t result;

  /* Mandatory */
  uint32_t msg_data_len;  /**< Must be set to # of elements in msg_data */
  uint8_t msg_data[QL_NET_MAX_MSG_LEN_V01];
}ql_ipc_qmi_net_rsp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ql_net_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t msg_id;

  /* Mandatory */
  int32_t result;

  /* Mandatory */
  uint32_t msg_data_len;  /**< Must be set to # of elements in msg_data */
  uint8_t msg_data[QL_NET_MAX_MSG_LEN_V01];
}ql_ipc_qmi_net_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ql_net_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t msg_id;

  /* Mandatory */
  uint32_t msg_data_len;  /**< Must be set to # of elements in msg_data */
  uint8_t msg_data[QL_NET_MAX_LONG_MSG_LEN_V01];
}ql_ipc_qmi_net_req_long_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ql_net_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t msg_id;

  /* Mandatory */
  int32_t result;

  /* Mandatory */
  uint32_t msg_data_len;  /**< Must be set to # of elements in msg_data */
  uint8_t msg_data[QL_NET_MAX_LONG_MSG_LEN_V01];
}ql_ipc_qmi_net_rsp_long_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ql_net_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t msg_id;

  /* Mandatory */
  int32_t result;

  /* Mandatory */
  uint32_t msg_data_len;  /**< Must be set to # of elements in msg_data */
  uint8_t msg_data[QL_NET_MAX_LONG_MSG_LEN_V01];
}ql_ipc_qmi_net_ind_long_msg_v01;  /* Message */
/**
    @}
  */

/* Conditional compilation tags for message removal */ 

/*Service Message Definition*/
/** @addtogroup ql_net_qmi_msg_ids
    @{
  */
#define QL_IPC_QMI_NET_REQ_V01 0x0100
#define QL_IPC_QMI_NET_RSP_V01 0x0100
#define QL_IPC_QMI_NET_IND_V01 0x0101
#define QL_IPC_QMI_NET_LONG_REQ_V01 0x0200
#define QL_IPC_QMI_NET_LONG_RSP_V01 0x0200
#define QL_IPC_QMI_NET_LONG_IND_V01 0x0201
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro ql_net_get_service_object_v01( ) that takes in no arguments. */
qmi_idl_service_object_type ql_net_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );

/** This macro should be used to get the service object */
#define ql_net_get_service_object_v01( ) \
          ql_net_get_service_object_internal_v01( \
            QL_NET_V01_IDL_MAJOR_VERS, QL_NET_V01_IDL_MINOR_VERS, \
            QL_NET_V01_IDL_TOOL_VERS )
/**
    @}
  */


#ifdef __cplusplus
}
#endif
#endif

