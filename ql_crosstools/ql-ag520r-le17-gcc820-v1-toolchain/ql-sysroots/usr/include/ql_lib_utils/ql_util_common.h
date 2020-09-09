/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_util_common.h
  @brief Common API
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
  20180809   tyler.kuang  Created .
-------------------------------------------------------------------------------------------------*/

#ifdef __cplusplus
 extern "C" {
#endif

#ifndef _QL_UTIL_COMMON_H_
#define _QL_UTIL_COMMON_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

#define QLU_COM_BUF_ZERO(buf)                memset(buf, 0, sizeof(buf))
#define QLU_COM_STR_EMPTY(string)            (!string || !string[0])
#define QLU_COM_STR_NCPY(src, dst)           strncpy(src, dst, sizeof(src))
#define QLU_COM_ARRAY_SIZE(array)            (sizeof(array)/sizeof((array)[0]))

#define LOG_V(fmt, ...) 
#define LOG_D(fmt, ...) 
#define LOG_I(fmt, ...) 
#define LOG_W(fmt, ...) 
#define LOG_E(fmt, ...) 
#define LOG_F(fmt, ...) 


typedef struct {
    int value;
    const char *name;
} qlu_value_name_item_t;


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Debug utils, get value by name 
  @param[in] vnlist Array of qlu_value_name_item_t, must end by {-1, NULL}
  @param[in] value 
  @return name, or null_unknow
  */
/*-----------------------------------------------------------------------------------------------*/
const char *qlu_v2n(qlu_value_name_item_t *vnlist, int value);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Debug utils, get name by value
  @param[in] vnlist Array of qlu_value_name_item_t, must end by {-1, NULL}
  @param[in] name
  @return value, or -1
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_n2v(qlu_value_name_item_t *vnlist, const char *name);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Get file size
  @param[in] file_path file path
  @return
  0 - succeed \n
  -1 - invalid param \n
  >0 - file size
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_com_file_get_size(const char *file_path);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Check wheather the file is exist
  @param[in] file_path file path
  @return
  0 - file is exist \n
  -1 - invalid param \n
  1 - file is not exist
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_com_file_exist(const char *file_path);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Synchronize the file's in-core state with storage device.(using shell cmd : fsync -d xxx)
  @param[in] file_path file path
  @return
  0 - succeed \n
  -1 - invalid param \n
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_com_file_sync(const char *file_path);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Check wheather the process is running
  @param[in] app_name Process name showed in PS 
  @return
  0 - the process is running \n
  1 - the process is not running \n
  -1 - error ocurred, check errno \n
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_com_app_exist(const char *app_name);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Execute a shell command, max command length is 256
  @param[in] fmt
  @param[in] others 
  @return same as system
  -1 - error ocurred, check errno \n
  other - status of the command
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_com_system(const char *fmt, ...)
__attribute__((__format__(printf, 1, 2)));


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Get Current system time.(using gettimeofday)
  @return Current system time in millisecond
  */
/*-----------------------------------------------------------------------------------------------*/
uint64_t qlu_com_get_tmr_ms(void);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Get system uptime, it does not include any time that the system is suspended
  @return uptime in sec, 0 is error
  */
/*-----------------------------------------------------------------------------------------------*/
uint64_t qlu_com_get_uptime_ms(void);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Get system uptime, it does not include any time that the system is suspended
  @param[out] psec Storage for second
  @param[out] pusec Storage for microsecond
  @return 
  0 - succeed \n
  -1 - error ocurred, check errno 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_com_get_uptime(uint32_t *psec, uint32_t *pusec);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Get system uptime, it also includes any time that the system is suspended
  @param[out] psec Storage for second
  @param[out] pusec Storage for microsecond
  @return 
  0 - succeed \n
  -1 - error ocurred, check errno 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_com_get_uptime_all(uint32_t *psec, uint32_t *pusec);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Enable or disable nonblocking 
  @param[in] fd file descriptor, returned by socket() or open()
  @param[in] is_noblock 1-enable or 0-disable
  @return 
  0 - succeed
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_com_fd_noblock(int fd, int is_noblock);


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Check wheather the file descriptor is ready for reading
  @param[in] fd file descriptor, returned by socket() or open()
  @return 
  0 - not ready
  1 - ready for reading 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_com_fd_has_data(int fd); 

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Enable the close-on-exec flag for the new file descriptor, 
  @param[in] fd file descriptor, returned by socket() or open()
  @return 
  0 - successful
  <0 - error ocurred, check errno
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_com_fd_cloexec(int fd, int is_enable); 

/*-------------------------------------------------------------------------------------------------
  @brief Get the caller's thread ID 
  @return The caller's thread ID 
  -----------------------------------------------------------------------------------------------*/
int qlu_com_gettid(void);

/*-------------------------------------------------------------------------------------------------
  @brief Create a flag file in dir tmp/ql_srv_flags, and write uptime on it 
  @param[in] flag_name Flag file name
  @return 
  0 - successful
  -1 - failure 
  -----------------------------------------------------------------------------------------------*/
int qlu_com_add_flag_file(const char *flag_name);

/*-------------------------------------------------------------------------------------------------
  @brief Create a flag file in dir tmp/ql_srv_flags, and write uptime on it 
  @param[in] flag_name Flag file name
  @return 
  0 - successful
  -1 - failure 
  -----------------------------------------------------------------------------------------------*/
int qlu_com_del_flag_file(const char *flag_name);

/*-------------------------------------------------------------------------------------------------
  @brief Start background services
  @param[out] p_pid Return process ID
  @param[fmt]
  @return 
  0 - successful
  -1 - invalid arguments
  -2 - failed to create handle
  -3 - failed to fork
  -4 - failed to waitpid
  -5 - failed to run subproccess
  -----------------------------------------------------------------------------------------------*/
int qlu_com_start_daemon(int *p_pid, const char *fmt, ...);

/*-------------------------------------------------------------------------------------------------
  @brief Same as kill ${pid}, If a name is specified, the name and PID are checked for matching
  @param[in] pid 
  @param[in] app_name
  @param[in] is_force
  @return 
  0 - successful
  -1 - same as kill 
  -2 - name and PID do not match
  -3 - pid does not exist
  -----------------------------------------------------------------------------------------------*/
int qlu_com_kill(int pid, const char *app_name, int is_force);

/*-------------------------------------------------------------------------------------------------
  @brief Read file content to buffer, same as fread
  @param[in] file_name
  @param[out] buf
  @param[in] buf_len
  @return 
  >=0 - number of bytes read
  -1 - error ocurred
  -----------------------------------------------------------------------------------------------*/
int qlu_com_read_file(const char *file_name, char *buf, int buf_len);


#endif

#ifdef __cplusplus
} 
#endif

