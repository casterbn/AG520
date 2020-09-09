/*
 *@file     ql_lpm.h
 *@date     2020-04-01
 *@author   gale
 *@brief    the function is suitable for this product: 
*/

#ifndef __QL_LPM_H__
#define __QL_LPM_H__

typedef enum 
{
    E_QL_LPM_FALLING	= 0, /* Falling, Means wakeupin falling to wakeup the module, or wakeupout falling to wakeup mcu. */
    E_QL_LPM_RISING	= 1, /* Rising, Means  wakeupin rising to wakeup the module,  or wakeupout rising to wakeup  mcu. */
}ql_lpm_edge_t;

/* Callback function registered via QL_Lpm_Init();
 * It will be called when wakeup_in state changed.
 * lpm_edge: report the wakeup_in state.
*/
typedef void (*ql_lpm_handler_t)
(
	ql_lpm_edge_t lpm_edge
);

/* Init QL LPM Init function.
 * Para:
 * 	ql_lpm_handler: the callback handler.
 * 	
 * Return value:
 *	0  --> success
 * 	-1 --> failed
*/
extern int ql_lpm_init(ql_lpm_handler_t ql_lpm_handler);

/* Deinit QL LPM function
 * Rmmod ql_lpm kmod, remove lpm handler.
 * Return value:
 * 	0  --> success
 *	-1 --> failed 
*/
extern int ql_lpm_deinit(void);

#endif // __QL_LPM_H__

