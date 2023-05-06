/*
 * Timer_Interface.h
 *
 *  Created on: Dec 3, 2022
 *      Author: HP-Pc
 */

#ifndef MCAL_TIMER_HEADER_TIMER_INTERFACE_H_
#define MCAL_TIMER_HEADER_TIMER_INTERFACE_H_

#include "../../../Common/STD_Types.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/Macros.h"

#include "Timer_Register.h"
#include "Timer_Private.h"
#include "Timer_Configuration.h"


void Timer0_VoidInit(void);

u8 Timer0_U8SetCallBack(void (*Local_PVCallBackFunctoin) (void));

#endif /* MCAL_TIMER_HEADER_TIMER_INTERFACE_H_ */
