/*
 * Bluetooth_interface.h
 *
 *  Created on: Nov 12, 2022
 */

#ifndef BLUETOOTH_INTERFACE_H_
#define BLUETOOTH_INTERFACE_H_

void Blutooth_Init(void);

void Blutooth_SendChar(u16 Copy_u8Char);

void Blutooth_SendString(char* Copy_pcString);

u8 Blutooth_ReceiveChar(void);

void Blutooth_receiveBuffer(u8* Copy_pcBuffer,u8 BufferSize);

#endif /* BLUETOOTH_INTERFACE_H_ */
