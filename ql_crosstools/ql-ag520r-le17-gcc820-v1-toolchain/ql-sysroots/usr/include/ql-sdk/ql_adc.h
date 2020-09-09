/**  
  @file
  ql_adc.h

  @brief
  This file provides the definitions for adc, and declares the 
  API functions.

*/
/*============================================================================
  Copyright (c) 2017 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
 =============================================================================*/
/*===========================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.


WHEN        WHO            WHAT, WHERE, WHY
----------  ------------   ----------------------------------------------------
27/06/2018  Quectel        Changed the parameter of ql_adc_show() from char-type
                           to Enum_QADC.
24/12/2018  juson          add adc2
11/12/2019  larry          Code  normalization
=============================================================================*/

#ifndef _QL_ADC_H_
#define _QL_ADC_H_


#ifdef __cplusplus
extern "C" {
#endif

/**
      ADC channel  enum
*/
typedef enum  ADC_CHANNEL_ENUM{
    QADC_NONE = 0,			/** Invalid  channel*/
    ADC0 = 1,				/** pmu_gpio4 for ADC0 channel  */
    ADC1 = 2,				/** pmu_gpio6 for ADC1 channel  */
    ADC2 = 3,				/** pmu_gpio2 for ADC2 channel */
    PA_THERM1=4,			/** pm_therm1 for ADC3 channel  */
    PA_THERM2=5,			/** pm_therm2  for ADC4 channel*/
    PA_THERM3=6,			/** mdm_case_therm for ADC5 channel */
    QADC_END				/** Invalid  channel*/
}ADC_CHANNEL_E;

/*========================================================================
  FUNCTION:  ql_adc_show
=========================================================================*/
/** @brief 
    This function retrieves the ADC voltage value with the specified 
    ADC channel.
    Support input vol value:
    ADC0 : 0.3V-VBAT_BB(3.8V)
    ADC1 : 0.3V-VBAT_BB
    ADC2 : 0.1V-1.7V

    @param[in] qadc, adc channel definitions, one value of Enum_QADC.

    @return
    adc value(mv) on success
    on failure, the return value is -1;
*/
/*=======================================================================*/
int ql_adc_show(ADC_CHANNEL_E qadc);

#ifdef __cplusplus
}
#endif


#endif
