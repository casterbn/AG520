/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_uart.h
  @brief uart API
*/
/*-----------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
  Copyright (c) 2019 Quectel Wireless Solution, Co., Ltd. All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
  EDIT HISTORY
  This section contains comments describing changes made to the file.
  Notice that changes are listed in reverse chronological order.
  $Header: $
  when                     who                                          what, where, why
  --------             ---                                            ----------------------------------------------------------
  18/07/2016      Stanley.YONG  		   Create
  03/09/2016  	  Stanley.YONG 		   Support more baudrate.
  22/06/2018      Stanley.YONG                       Added the check for value range of argument.
  10/12/2019      larry.zhang		              Code  normalization
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_UART_H__
#define __QL_UART_H__

#ifdef __cplusplus
extern "C" {
#endif


typedef enum {
    FC_NONE = 0,  		 /** None Flow Control*/
    FC_RTSCTS, 			 /** Hardware Flow Control (rtscts)*/
    FC_XONXOFF 		/** Software Flow Control (xon/xoff)  */
}Enum_FlowCtrl;

typedef enum {
    PB_NONE = 0, 		 /** none parity check*/
    PB_ODD,			 /** odd parity check */
    PB_EVEN 			/** even parity check*/
}Enum_ParityBit;

typedef enum {
    DB_CS5 = 5,
    DB_CS6 = 6,
    DB_CS7 = 7,
    DB_CS8 = 8
}Enum_DataBit;

typedef enum {
    SB_1 = 1,
    SB_2 = 2
}Enum_StopBit;

typedef enum {
	B_300 		= 300,
	B_600 		= 600,
	B_1200 		= 1200,
	B_2400 		= 2400,
	B_4800 		= 4800,
	B_9600 		= 9600,
	B_19200 		= 19200,
	B_38400 		= 38400,
	B_57600 		= 57600,
	B_115200 	= 115200,
	B_230400 	= 230400,
	B_460800 	= 460800,
	B_921600	= 921600,
	B_1000000	= 1000000,
	B_2000000	= 2000000,
	B_3000000	= 3000000
}Enum_BaudRate;

typedef struct {
    Enum_BaudRate       baudrate; 		/** baudrate enumeration arrey*/
    Enum_DataBit       	databit;		/** databit enumeration arrey*/
    Enum_StopBit       	stopbit;		/** stopbit enumeration arrey*/
    Enum_ParityBit      parity;			/** parity enumeration arrey*/
    Enum_FlowCtrl       flowctrl;		/** flowctrl enumeration arrey*/
}ST_UARTDCB;


/*-----------------------------------------------------------------------------------------------*/
/**
      Open uart device api
       @brief
         @param[in] port     uart devices path
         @param[in] flags    property setting
       @return
         -fd   file descriptor
         -QL_ERR_TARGET_NOT_EXIST   devices does not exist
      */
/*-----------------------------------------------------------------------------------------------*/
int  ql_uart_open(const char* port, int flags);

/*-----------------------------------------------------------------------------------------------*/
/**
      Uart write api
       @brief
         @param[in] fd      file descriptor for ql_uart_open return value 
         @param[in] buf    write buffer
         @param[in] buf_len   write buffer len
       @return
         -size     write data size 
         -QL_ERR_FAILED   if it write failed
         -QL_ERR_INVALID_ARG   invalid  arguments
      */
/*-----------------------------------------------------------------------------------------------*/
int  ql_uart_write(int fd, const char* buf, unsigned int buf_len);

/*-----------------------------------------------------------------------------------------------*/
/**
      Uart read api
       @brief
         @param[in] fd      file descriptor for ql_uart_open return value 
         @param[in] buf    read buffer
         @param[in] buf_len   read buffer len
       @return
         -other     write data size 
         -QL_ERR_INVALID_ARG   invalid  arguments
      */
/*-----------------------------------------------------------------------------------------------*/
int  ql_uart_read(int fd, char* buf, unsigned int buf_len);

/*-----------------------------------------------------------------------------------------------*/
/**
      Uart ioctrl api
       @brief
         @param[in] fd      file descriptor for ql_uart_open return value 
         @param[in] cmd    ioctl cmd
       @return
         --1     ioctl error
         -0       if it ok
         -QL_ERR_INVALID_ARG   invalid  arguments
      */
/*-----------------------------------------------------------------------------------------------*/
int  ql_uart_ioctl(int fd, unsigned int cmd, void* pValue);

/*-----------------------------------------------------------------------------------------------*/
/**
       Setting parameter api
       @brief
         @param[in] fd      file descriptor for ql_uart_open return value 
         @param[in] dcb   ST_UARTDCB sturct for uart parameter
       @return
         -QL_ERR_OK     if it ok
         -QL_ERR_INVALID_ARG   invalid  arguments
      */
/*-----------------------------------------------------------------------------------------------*/
int  ql_uart_setdcb(int fd, ST_UARTDCB *dcb);

/*-----------------------------------------------------------------------------------------------*/
/**
       Get  parameter api
       @brief
         @param[in] fd      file descriptor for ql_uart_open return value 
         @param[in] dcb   ST_UARTDCB sturct for uart parameter
       @return
         -QL_ERR_OK     if it ok
         -QL_ERR_INVALID_ARG   invalid  arguments
      */
/*-----------------------------------------------------------------------------------------------*/
int  ql_uart_getdcb(int fd, ST_UARTDCB *dcb);

/*-----------------------------------------------------------------------------------------------*/
/**
      Close uart device api
       @brief
         @param[in] fd      file descriptor for ql_uart_open return value 
       @return
         -0       if it ok
         -other  if it failed
      */
/*-----------------------------------------------------------------------------------------------*/
int  ql_uart_close(int fd);

#ifdef __cplusplus
}
#endif


#endif //__QL_UART_H__
