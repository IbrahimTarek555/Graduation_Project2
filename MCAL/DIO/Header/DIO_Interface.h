/*
 * DIO_Interface.h
 *
 *  Created on: Sep 23, 2022
 *      Author: HP-Pc
 */

#ifndef MCAL_DIO_HEADER_DIO_INTERFACE_H_
#define MCAL_DIO_HEADER_DIO_INTERFACE_H_

#include "../../../Common/STD_Types.h"
#include "../../../Common/Macros.h"
#include "../../../Common/Bit_Math.h"

#include "DIO_Private.h"
#include "DIO_Register.h"
#include "DIO_Configuration.h"

void DIO_VoidSetPinDir					 (u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PinState);
void DIO_VoidSetPinValue			 	 (u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PinValue);
u8 	 DIO_U8GetPinValue 			  	     (u8 Local_GroupName, u8 Local_PinNumber);

void DIO_VoidSetPortDir  				 (u8 Local_GroupName, u8 Local_PortState);
void DIO_VoidSetPortValue				 (u8 Local_GroupName, u8 Local_PortValue);
u8 	 DIO_U8GetPortValue			   	     (u8 Local_GroupName);

void DIO_VoidPinInternalPullUpControl	 (u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PullUpState);
void DIO_VoidPortInternalPullUpControl	 (u8 Local_GroupName, u8 Local_PullUpState);

void DIO_VoidManualSetPortDir  				 (u8 Local_GroupName, u8 Local_PortState);
void DIO_VoidManualSetPortValue			 (u8 Local_GroupName, u8 Local_PortValue);



#endif /* MCAL_DIO_HEADER_DIO_INTERFACE_H_ */
