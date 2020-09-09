/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_gpio.h
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
  22/06/2018      Stanley.YONG  		   Create
  05/12/2019      larry.zhang		             Code  normalization
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_GPIO_H__
#define __QL_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h>
#include <signal.h>
#include <sys/epoll.h>


typedef enum{
	/*Invalid*/ PINNAME_BEGIN = -1,
	/*PIN-27*/  PINNAME_GPIO_83=83,   
	/*PIN-29*/  PINNAME_GPIO_78=78,      
	/*PIN-30*/  PINNAME_GPIO_53=53,      
	/*PIN-31*/  PINNAME_GPIO_79=79,      
	/*PIN-36*/  PINNAME_GPIO_56=56,    
	/*PIN-39*/  PINNAME_GPIO_57=57,       
	/*PIN-45*/  PINNAME_GPIO_71=71,    
	/*PIN-53*/  PINNAME_GPIO_92=92,    
	/*PIN-54*/  PINNAME_GPIO_97=97,       
	/*PIN-55*/  PINNAME_GPIO_93=93,    
	/*PIN-56*/  PINNAME_GPIO_94=94,    
	/*PIN-58*/  PINNAME_GPIO_95=95,    
	/*PIN-59*/  PINNAME_GPIO_63=63,    
	/*PIN-61*/  PINNAME_GPIO_65=65,    
	/*PIN-62*/  PINNAME_GPIO_66=66,    
	/*PIN-63*/  PINNAME_GPIO_64=64,    
	/*PIN-66*/  PINNAME_GPIO_60=60,          
	/*PIN-67*/  PINNAME_GPIO_45=45,  
	/*PIN-69*/  PINNAME_GPIO_44=44,  
	/*PIN-70*/  PINNAME_GPIO_20=20,      
	/*PIN-71*/  PINNAME_GPIO_23=23,      
	/*PIN-72*/  PINNAME_GPIO_21=21,      
	/*PIN-73*/  PINNAME_GPIO_16=16,       
	/*PIN-74*/  PINNAME_GPIO_22=22,      
	/*PIN-75*/  PINNAME_GPIO_19=19,        
	/*PIN-76*/  PINNAME_GPIO_17=17,         
	/*PIN-77*/  PINNAME_GPIO_86=86,        
	/*PIN-78*/  PINNAME_GPIO_18=18,        
	/*PIN-79*/  PINNAME_GPIO_11=11,       
	/*PIN-80*/  PINNAME_GPIO_10=10,       
	/*PIN-81*/  PINNAME_GPIO_62=62,       
	/*PIN-95*/  PINNAME_GPIO_42=42,        
	/*PIN-100*/ PINNAME_GPIO_84=84,      
	/*PIN-101*/ PINNAME_GPIO_90=90,  
	/*PIN-102*/ PINNAME_GPIO_96=96,     
	/*PIN-104*/ PINNAME_GPIO_99=99,      
	/*PIN-107*/ PINNAME_GPIO_8=8,        
	/*PIN-110*/ PINNAME_GPIO_9=9,        	
	/*PIN-116*/ PINNAME_GPIO_81=81,      
	/*PIN-169*/ PINNAME_GPIO_88=88,       
	/*PIN-181*/ PINNAME_GPIO_91=91,     
	/*PIN-187*/ PINNAME_GPIO_82=82,       
	/*PIN-210*/ PINNAME_GPIO_72=72,      
	/*PIN-213*/ PINNAME_GPIO_74=74,        
	/*PIN-216*/ PINNAME_GPIO_75=75,       
	/*PIN-219*/ PINNAME_GPIO_73=73,      
	/*PIN-222*/ PINNAME_GPIO_89=89,    
	/*PIN-225*/ PINNAME_GPIO_80=80,      
	/*PIN-228*/ PINNAME_GPIO_52=52,        
	/*PIN-243*/ PINNAME_GPIO_85=85,         
	/*PIN-246*/ PINNAME_GPIO_87=87,       
	/*PIN-250*/ PINNAME_GPIO_69=69,      
	/*PIN-253*/ PINNAME_GPIO_70=70,      
	/*PIN-254*/ PINNAME_GPIO_67=67,     
	/*PIN-255*/ PINNAME_GPIO_68=68,      
	/*PIN-261*/ PINNAME_GPIO_14=14,       
	/*PIN-262*/ PINNAME_GPIO_15=15,        
	/*PIN-263*/ PINNAME_GPIO_13=13,        
	/*PIN-265*/ PINNAME_GPIO_12=12,         
	/*PIN-282*/ PINNAME_GPIO_76=76,
    	PINNAME_END=108
}Enum_PinName;


typedef enum{
    PINDIRECTION_IN  = 0,	/** GPIO input direction */
    PINDIRECTION_OUT = 1	/** GPIO output direction */
}Enum_PinDirection;

typedef enum{
    PINLEVEL_LOW  = 0,	/** GPIO low level */
    PINLEVEL_HIGH = 1	/** GPIO high level */
}Enum_PinLevel;

typedef enum{
    PINAWKAE_DISABLE  = 0,	/** GPIO awake disable */
    PINAWAKE_ENABLE = 1	/** GPIO awake enable*/
}Enum_PinAwake;


typedef enum{
    PINPULLSEL_DISABLE  = 0,		 /** Disable pull selection */
    PINPULLSEL_PULLDOWN = 1, 	 /**pull down */
    PINPULLSEL_PULLUP   = 3  		/**pull up */
}Enum_PinPullSel;

/****************************************************************************
 * GPIO Config Items
 ***************************************************************************/
typedef struct{
    Enum_PinName           pinName;		/** GPIO pinName arrey*/
    Enum_PinDirection      pinDirection;   /** GPIO pinDirection arrey*/
    Enum_PinLevel          pinLevel;		 /** GPIO pinLevel arrey*/
    Enum_PinPullSel        pinPullSel;		 /** GPIO pinPullSel arrey*/
}ST_GPIOConfig;

//------------------------------------------------------------------------------
/**
 * The type of GPIO Edge Sensivity.
 */
//------------------------------------------------------------------------------
typedef enum {
    EINT_SENSE_NONE,       // pin is input, but no an interrupt pin.
    EINT_SENSE_RISING,
    EINT_SENSE_FALLING,
    EINT_SENSE_BOTH
}Enum_EintType;

/*****************************************************************
* Function:     Ql_GPIO_Init 
* 
* Description:
*               This function enables the GPIO function of the specified pin,
*               and initialize the configurations, including direction,
*               level and pull selection.
*
* Parameters:
*               pinName:
*                   Pin name, one value of Enum_PinName.
*               dir:
*                   The initial direction of GPIO, one value of Enum_PinDirection.
*               level:
*                   The initial level of GPIO, one value of Enum_PinLevel. 
*               pullSel:
*                   Pull selection, one value of Enum_PinPullSel.
* Return:        
*               RES_OK, this function succeeds.
*               RES_IO_NOT_SUPPORT, the input GPIO is invalid. 
*               RES_IO_ERR, the function failed
*               other place. For example this GPIO has been using as EINT.
*****************************************************************/
int Ql_GPIO_Init(Enum_PinName       pinName, 
                 Enum_PinDirection  dir, 
                 Enum_PinLevel      level, 
                 Enum_PinPullSel    pullSel
                 );

/*****************************************************************
* Function:     Ql_GPIO_Base_Init 
* 
* Description:
*               This function enables the GPIO function of the specified pin.
*
* Parameters:
*               pinName:
*                   Pin name, one value of Enum_PinName.
*            
* Return:        
*               RES_OK, this function succeeds.
*               RES_IO_NOT_SUPPORT, the input GPIO is invalid. 
*               RES_IO_ERR, the function failed
*****************************************************************/
int Ql_GPIO_Base_Init(Enum_PinName pinName );

/*****************************************************************
* Function:     Ql_GPIO_SetLevel 
* 
* Description:
*               This function sets the level of the specified GPIO.
*
* Parameters:
*               pinName:
*                   Pin name, one value of Enum_PinName.
*               level:
*                   The initial level of GPIO, one value of Enum_PinLevel. 
* Return:        
*               RES_OK, this function succeeds.
*               RES_IO_NOT_SUPPORT, the input GPIO is invalid. 
*               RES_IO_ERR, the function failed
*               other place. For example this GPIO has been using as EINT.
*****************************************************************/
int Ql_GPIO_SetLevel(Enum_PinName pinName, Enum_PinLevel level);

/*****************************************************************
* Function:     Ql_GPIO_GetLevel 
* 
* Description:
*               This function gets the level of the specified GPIO.
*
* Parameters:
*               pinName:
*                   Pin name, one value of Enum_PinName.
* Return:        
*               The level value of the specified GPIO, which is 
*               nonnegative integer.
*               RES_IO_NOT_SUPPORT, the input GPIO is invalid.
*****************************************************************/
int Ql_GPIO_GetLevel(Enum_PinName pinName);

/*****************************************************************
* Function:     Ql_GPIO_SetDirection 
* 
* Description:
*               This function sets the direction of the specified GPIO.
*
* Parameters:
*               pinName:
*                   Pin name, one value of Enum_PinName.
*               dir:
*                   The initial direction of GPIO, one value of Enum_PinDirection.
* Return:        
*               RES_OK, this function succeeds.
*               RES_IO_NOT_SUPPORT, the input GPIO is invalid. 
*               RES_IO_ERR, the function failed
*               other place. For example this GPIO has been using as EINT.
*****************************************************************/
int Ql_GPIO_SetDirection(Enum_PinName pinName, Enum_PinDirection dir);

/*****************************************************************
* Function:     Ql_GPIO_GetDirection 
* 
* Description:
*               This function gets the direction of the specified GPIO.
*
* Parameters:
*               pinName:
*                   Pin name, one value of Enum_PinName.
* Return:        
*               0  INPUT
*               1  OUTPUT
*               RES_IO_NOT_SUPPORT, the input GPIO is invalid. 
*               other place. For example this GPIO has been using as EINT.
*****************************************************************/
int Ql_GPIO_GetDirection(Enum_PinName pinName);


/*****************************************************************
* Function:     Ql_GPIO_SetAwake
* 
* Description:
*               This function sets the interrupt awake of the specified GPIO.
*
* Parameters:
*               pinName:
*                   Pin name, one value of Enum_PinName.
*               en:
*                   1:enable   0:disable
* Return:        
*               RES_OK, this function succeeds.
*               RES_IO_NOT_SUPPORT, the input GPIO is invalid. 
*               RES_IO_ERR, the function failed
*   Notes: The GPIO must be configured as  input and interrupt 
*****************************************************************/
int Ql_GPIO_SetAwake(Enum_PinName pinName, Enum_PinAwake en);

/*****************************************************************
* Function:     Ql_GPIO_GetAwake 
* 
* Description:
*               This function gets the interrupt awake of the specified GPIO.
*
* Parameters:
*               pinName:
*                   Pin name, one value of Enum_PinName.
* Return:        
*	     -0 : disable awake
*	     -1 : enable awake
*               RES_IO_NOT_SUPPORT, the input GPIO is invalid.
*****************************************************************/
int Ql_GPIO_GetAwake(Enum_PinName pinName);


/*****************************************************************
* Function:     Ql_GPIO_SetPullSelection 
* 
* Description:
*               This function sets the pull selection of the specified GPIO.
*
* Parameters:
*               pinName:
*                   Pin name, one value of Enum_PinName.
*               Enum_PinPullSel:
*                   Pull selection, one value of Enum_PinPullSel.
* Return:        
*               RES_OK, this function succeeds.
*               RES_IO_NOT_SUPPORT, the input GPIO is invalid. 
*               RES_IO_ERR, the function failed
*               other place. For example this GPIO has been using as EINT.
*****************************************************************/
int Ql_GPIO_SetPullSelection(Enum_PinName pinName, Enum_PinPullSel pullSel);

/*****************************************************************
* Function:     Ql_GPIO_GetPullSelection 
* 
* Description:
*               This function gets the pull selection of the specified GPIO.
*
* Parameters:
*               pinName:
*                   Pin name, one value of Enum_PinName.
* Return:        
*               0   no pull
*               1   pull down
*               3   pull up
*****************************************************************/
int Ql_GPIO_GetPullSelection(Enum_PinName pinName);

/*****************************************************************
* Function:     Ql_GPIO_Uninit 
* 
* Description:
*               This function releases the specified GPIO that was 
*               initialized by calling Ql_GPIO_Init() previously.
*               After releasing, the GPIO can be used for other purpose.
* Parameters:
*               pinName:
*                   Pin name, one value of Enum_PinName.
* Return:        
*               RES_OK, this function succeeds.
*               RES_IO_NOT_SUPPORT, the input GPIO is invalid. 
*               RES_IO_ERR, the function failed
*               other place. For example this GPIO has been using as EINT.
*****************************************************************/
int Ql_GPIO_Uninit(Enum_PinName pinName);

//------------------------------------------------------------------------------
/*
* Description:
*     Definition for EINT callback function.
* 
* Parameters:
*     PinName:
*         EINT pin name, one value of Enum_PinName.
*
*     level:
*         The EINT level value, one value of Enum_PinLevel. 
*         0 or 1
*/
//------------------------------------------------------------------------------
typedef void (*Ql_EINT_Callback)(Enum_PinName eintPinName, int level);

//------------------------------------------------------------------------------
/*
* Function:     Ql_EINT_Enable 
* 
* Description:
*               Set the interrupt sense mode, and enable interrupt. 
*
* Parameters:
*               eintPinName:
*                   EINT pin name, one value of Enum_PinName that has 
*                   the interrupt function.
*
*               eintType:
*                   Interrupt type, level-triggered or edge-triggered.
*                   Now, only edge-triggered interrupt is supported.
*
*               eint_callback:
*                   call back function
*
* Return:        
*               RES_OK, this function succeeds.
*               else failed to execute the function. 
*/
//------------------------------------------------------------------------------
int Ql_EINT_Enable(Enum_PinName eintPinName, Enum_EintType eintType, Ql_EINT_Callback eint_callback);


//------------------------------------------------------------------------------
/*
* Function:     Ql_EINT_Disable 
* 
* Description:
*               Disable the interrupt sense. 
*
* Parameters:
*               eintPinName:
*                   EINT pin name, one value of Enum_PinName that has 
*                   the interrupt function.
*
* Return:        
*               RES_OK, this function succeeds.
*               else failed to execute the function. 
*/
//------------------------------------------------------------------------------
int Ql_EINT_Disable(Enum_PinName eintPinName);

#ifdef __cplusplus
}
#endif

#endif  // __QL_GPIO_H__
