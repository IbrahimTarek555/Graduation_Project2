/*
 * Blutooth_program.c
 *
 *  Created on: Nov 12, 2022
 */

#include "STD_TYPES.h"

#include "USART_interface.h"
#include "Bluetooth_interface.h"

void Blutooth_Init(void)
{
	USART_voidInit();
}

void Blutooth_SendChar(u16 Copy_u8Char)
{
	USART_voidSendCharSynch(Copy_u8Char);
}

void Blutooth_SendString(char* Copy_pcString)
{
	if(Copy_pcString != NULL)
	{
		USART_u8SendStringSynch(Copy_pcString);
	}
}

u8 Blutooth_ReceiveChar(void)
{
	u8 Data=0;
	USART_u8ReceiveCharSynch(&Data);
	return Data;
}

void Blutooth_receiveBuffer(u8* Copy_pcBuffer,u8 BufferSize)
{
	USART_u8ReceiveBufferSynch(Copy_pcBuffer,BufferSize);
}
