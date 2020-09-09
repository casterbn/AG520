/*-----------------------------------------------------------------------------------------------*/
/**
  @file gpioSysfs.h
  @brief gpio API
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
  15/07/2016      Stanley.YONG  		   Create
  26/07/2016      Stanley.YONG   		   Add interrupt implementation.
  05/12/2019      larry.zhang		             Code  normalization
-------------------------------------------------------------------------------------------------*/

#ifndef __GPIOSYSFS_H__
#define __GPIOSYSFS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <fcntl.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include "ql_gpio.h"
#include <errno.h>

#define off64_t long long

#define boolean unsigned int
#define PAGE_SIZE  4096
typedef void (*_fdMonitor_CB)(Enum_PinName  pinName, boolean activeLevel, void* param);	/**  */

enum {
        RES_OK = 0,
        RES_BAD_PARAMETER  = -1,     ///< Parameter is invalid.
        RES_IO_NOT_SUPPORT = -2,
        RES_IO_ERROR = -3,
        RES_NOT_IMPLEMENTED = -4
};

/*-----------------------------------------------------------------------------------------------*/
/**
    The value of GPIO low or high.
    Translates to the setting of "value" in sysfs
    */
/*-----------------------------------------------------------------------------------------------*/
typedef enum {
    GPIO_LEVEL_LOW, 	/** GPIO Low Value */
    GPIO_LEVEL_HIGH	/** GPIO High Value */
}Enum_GPIO_Level;

/*-----------------------------------------------------------------------------------------------*/
/**
    The polarity of GPIO level low or high.
    Translates to the setting of "active_low" in sysfs
    */
/*-----------------------------------------------------------------------------------------------*/
typedef enum {
    POLARITY_LEVEL_HIGH, 	 /** GPIO Active-High, output signal is 1*/
    POLARITY_LEVEL_LOW 	 /**  GPIO Active-Low, output signal is 0*/
}Enum_GPIO_Polarity_Level;

/*-----------------------------------------------------------------------------------------------*/
/**
    The polarity of GPIO direction.
    Translates to the setting of "direction" in sysfs
    */
/*-----------------------------------------------------------------------------------------------*/
typedef enum {
    GPIO_DIR_INPUT,	 /** GPIO input direction */
    GPIO_DIR_OUTPUT	 /** GPIO output direction*/
}Enum_GPIO_Dir;

/*-----------------------------------------------------------------------------------------------*/
/**
    The polarity of GPIO interrupt awake to system.
    Translates to the setting of "awake" in sysfs
    */
/*-----------------------------------------------------------------------------------------------*/
typedef enum {
    GPIO_AWAKE_DISABLE,	 /** GPIO awake disable */
    GPIO_AWAKE_ENABLE		 /** GPIO awake enable*/
}Enum_GPIO_Awake;


/*-----------------------------------------------------------------------------------------------*/
/**
     The mode of GPIO Edge Sensivity.
     */
/*-----------------------------------------------------------------------------------------------*/
typedef enum {
    GPIO_EDGE_SENSE_NONE,		 /** pin is input, but no an interrupt pin */
    GPIO_EDGE_SENSE_RISING,	 /** Rising edge trigger mode */
    GPIO_EDGE_SENSE_FALLING,	 /** Falling edge trigger mode */
    GPIO_EDGE_SENSE_BOTH		 /** Falling and Rising edge trigger mode  */
}Enum_GpioEdgeSenseMode;


/*-----------------------------------------------------------------------------------------------*/
/**
     The struct of Sysfs object
      */
/*-----------------------------------------------------------------------------------------------*/
typedef struct {
    Enum_PinName pinName;		 /** GPIO enumeration arrey*/
    unsigned int gpioNum;		 /** Pin GPIO number */
    const char gpioName[10];		 /** Pin GPIO Signal Name */ 
    boolean inUse; 				 /**  Is the GPIO currently used*/
    int monitorFd;  				 /**The FD of the file bing monitored*/
    _fdMonitor_CB fdMonitor_proc;	 /** fdMonitor_cb Object associated to this GPIO*/       
    void* param_cb; 				  /** the parameter can be passed into fdMonitor_cb*/
}ST_GpioSysfs;


/*-----------------------------------------------------------------------------------------------*/
/**
     Export a GPIO in the sysfs.
     @brief
         @param[in] pinName  GPIO enumeration arrey
     @return
       - RES_OK if exporting was successful
       - RES_IO_NOT_SUPPORT pin is not supported
       - RES_IO_ERROR if it failed
      */
/*-----------------------------------------------------------------------------------------------*/
int GpioSysfs_ExportGpio(const Enum_PinName pinName);

/*-----------------------------------------------------------------------------------------------*/
/**
    Unexport a GPIO in the sysfs.
     @brief
         @param[in] pinName  GPIO enumeration arrey
     @return
      - RES_OK if exporting was successful
      - RES_IO_NOT_SUPPORT pin is not supported
      - RES_IO_ERROR if it failed
    */
/*-----------------------------------------------------------------------------------------------*/
int GpioSysfs_UnexportGpio(const Enum_PinName pinName);

/*-----------------------------------------------------------------------------------------------*/
/**
     setup GPIO Direction INPUT or OUTPUT mode.
     @brief
        @param[in] pinName  GPIO enumeration arrey
        @param[in] direction   reads as either "in" or "out". This value may
         normally be written. Writing as "out" defaults to
         initializing the value as low. To ensure glitch free
         operation, values "low" and "high" may be written to
         configure the GPIO as an output with that initial value
     @return
      - RES_OK  setting direction was successful
      - RES_IO_NOT_SUPPORT pin is not supported
      - RES_IO_ERROR if it failed
   */
/*-----------------------------------------------------------------------------------------------*/
int GpioSysfs_WriteDirection(Enum_PinName  pinName,   Enum_GPIO_Dir dir );

/*-----------------------------------------------------------------------------------------------*/
/**
      PINname get gpio
       @brief
         @param[in] pinName  GPIO enumeration arrey
       @return
         -ST_GpioSysfs*  if it ok
         -NULL  if it failed
      */
/*-----------------------------------------------------------------------------------------------*/
ST_GpioSysfs* GetGpioItemByPin(const Enum_PinName pinName);


/*-----------------------------------------------------------------------------------------------*/
/**
      read GPIO Direction INPUT or OUTPUT mode.
     @brief
        @param[in] pinName  GPIO enumeration arrey
        @param[in] direction  reads as either "in" or "out". This value may
         normally be written. Writing as "out" defaults to
         initializing the value as low. To ensure glitch free
         operation, values "low" and "high" may be written to
         configure the GPIO as an output with that initial value
     @return
     -0  if it output 
     -1  if it input
     */
/*-----------------------------------------------------------------------------------------------*/
int GpioSysfs_ReadDirection(Enum_PinName pinName);

/*-----------------------------------------------------------------------------------------------*/
/**
      write value to GPIO output, low or high
      @brief
        @param[in] pinName  GPIO enumeration arrey
         @param[in] level   High or low
      @return
          - RES_OK  setting direction was successful
          -RES_BAD_PARAMETER  probably not exported
          - RES_IO_NOT_SUPPORT pin is not supported
          - RES_IO_ERROR if it failed
       */
/*-----------------------------------------------------------------------------------------------*/
int GpioSysfs_WriteValue( Enum_PinName pinName,  Enum_GPIO_Level level );

/*-----------------------------------------------------------------------------------------------*/
/**
      read level value from GPIO input mode.
     @brief
        @param[in] pinName  GPIO enumeration arrey
     @return
          - RES_IO_NOT_SUPPORT pin is not supported
          - 1  if it high
          - 0  if it low
     */
/*-----------------------------------------------------------------------------------------------*/
int GpioSysfs_ReadValue(Enum_PinName pinName);

/*-----------------------------------------------------------------------------------------------*/
/**
     setup GPIO interrupt awake  mode.
     @brief
        @param[in] pinName  GPIO enumeration arrey
        @param[in] en   0:disable awake function   1:enable awake function
         
     @return
      - RES_OK  setting direction was successful
      - RES_IO_NOT_SUPPORT pin is not supported
      - RES_IO_ERROR if it failed
   */
/*-----------------------------------------------------------------------------------------------*/
int GpioSysfs_WriteAwake( Enum_PinName  pinName,   Enum_GPIO_Awake  en );

/*-----------------------------------------------------------------------------------------------*/
/**
      read level value from GPIO input mode.
     @brief
        @param[in] pinName  GPIO enumeration arrey
     @return
          - RES_IO_NOT_SUPPORT pin is not supported
          - 1  if it is enable awake function
          - 0  if it is disable awake function
     */
/*-----------------------------------------------------------------------------------------------*/
int GpioSysfs_ReadAawke(Enum_PinName pinName);

/*-----------------------------------------------------------------------------------------------*/
/**
     Open the device file of level value, monitoring correct GPIO value
     @brief
	   @param[in] pinName  GPIO enumeration arrey
      @return
         - RES_IO_NOT_SUPPORT pin is not supported
 
 */
/*-----------------------------------------------------------------------------------------------*/
int GpioSysfs_OpenValue(Enum_PinName pinName);

/*-----------------------------------------------------------------------------------------------*/
/**
    Close the device file of level value opened by GpioSysfs_OpenValue.
     @brief
	   @param[in] handle  file descriptor
 
     @return
       -0 
    */
/*-----------------------------------------------------------------------------------------------*/
int GpioSysfs_CloseValue(int handle);

/*-----------------------------------------------------------------------------------------------*/
/**
     Rising or Falling of Edge sensitivity,This file exists only if the pin can be configured as an,interrupt generating input pin.
      @brief
       @param[in] pinName GPIO enumeration arrey
       @param[in] edgeSense The mode of GPIO Edge Sensivity.
	    "edge" ... reads as either "none", "rising", "falling", or
               "both". Write these strings to select the signal edge(s)
                   that will make poll(2) on the "value" file return.   
      @return
        - RES_IO_NOT_SUPPORT pin is not supported
        - RES_OK  setting direction was successful
        - RES_IO_ERROR if it failed
     */
/*-----------------------------------------------------------------------------------------------*/
int GpioSysfs_SetEdgeSense(Enum_PinName  pinName,  Enum_GpioEdgeSenseMode edgeSense);

/*-----------------------------------------------------------------------------------------------*/
/**
      set gpio pull
      @brief
       @param[in] pinName GPIO enumeration arrey
       @param[in] val The mode of GPIO Edge Sensivity.
	  0-----gpio no pull
            1-----gpio pull down
            3-----gpio pull up
       @return
       - RES_IO_NOT_SUPPORT pin is not supported
       - RES_OK  setting direction was successful
       - RES_IO_ERROR if it failed
     */
/*-----------------------------------------------------------------------------------------------*/
int Ql_Write_Register(Enum_PinName  pinName, unsigned char val);


/*-----------------------------------------------------------------------------------------------*/
/**
      get gpio pull
     @brief
	 @param[in] pinName GPIO enumeration arrey
     @return
       - RES_IO_NOT_SUPPORT pin is not supported
       - RES_IO_ERROR if it failed
       -0  not pull
       -1  pull down
       -3  pull up
*/
/*-----------------------------------------------------------------------------------------------*/
int Ql_Read_Register(Enum_PinName  pinName);

/*-----------------------------------------------------------------------------------------------*/
/**
       setup GPIO polarity.
        @brief
	 @param[in] pinName GPIO enumeration arrey
	 @param[in] level  Active-high or active-low
       @return 
         - RES_IO_NOT_SUPPORT pin is not supported
         - RES_OK  setting direction was successful
         - RES_IO_ERROR if it failed  
        */
/*-----------------------------------------------------------------------------------------------*/
int GpioSysfs_WritePolarity(Enum_PinName  pinName, Enum_GPIO_Polarity_Level level );

#ifdef __cplusplus
}
#endif

#endif    //__GPIOSYSFS_H__
