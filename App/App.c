/*
 * App.c
 *
 *  Created on: Jan 26, 2023
 *      Author: HP-Pc
 */

#define F_CPU 16000000UL

#include "../Common/Bit_Math.h"
#include "../Common/Macros.h"
#include "../Common/STD_Types.h"

#include "../MCAL/Timer/Header/Timer_Interface.h"
#include "../MCAL/DIO/Header/DIO_Interface.h"
#include "../MCAL/GIE/Header/GIE_Interface.h"
#include "../MCAL/Bluetooth/Bluetooth_interface.h"

#include <util/delay.h>

#define POSN1		8
#define POSN2		9
#define POSN3		10
#define POSN4		11
#define POSN5		12
#define NaturalPos	13
#define POS7N		14
#define POS8N		15
#define POS9N		16
#define POS10N		18

void PWM(void);

static u16 counter = 0;

void Forward(void);
void Backward(void);
void ToRight(void);
void ToLeft(void);


/*
 * I Take this order across all the code,
 * Leg1: Servo1, Servo2, Servo3.
 * Leg2: Servo4, Servo5, Servo6.
 * Leg3: Servo7, Servo8, Servo9.
 * Leg4: Servo10, Servo11, Servo12.
 */

/*Take the angle range 8 : 16*/
u8 angle1 = POSN3, angle2 = NaturalPos, angle3 = POS8N;
u8 angle4 = POS7N, angle5 = NaturalPos, angle6 = POS8N;
u8 angle7 = NaturalPos, angle8 = NaturalPos, angle9 = POS8N;
u8 angle10 = NaturalPos, angle11 = NaturalPos, angle12 = POS8N;



int main()
{
	/*Enabling Global Interrupt*/
	GIE_VoidEnable();

	/*Enabling Bluetooth Module*/
	Blutooth_Init();
	u8 BluetoothChar = 0;

	/*Initializing and Enabling Timer 0*/
	Timer0_VoidInit();
	Timer0_U8SetCallBack(&PWM);

	/*Make the pins output*/
	/*Leg 1*/
	DIO_VoidSetPinDir(DIO_GroupD, DIO_PIN5, Output);
	DIO_VoidSetPinDir(DIO_GroupD, DIO_PIN6, Output);
	DIO_VoidSetPinDir(DIO_GroupD, DIO_PIN7, Output);
	/*Leg 2*/
	DIO_VoidSetPinDir(DIO_GroupC, DIO_PIN1, Output);
	DIO_VoidSetPinDir(DIO_GroupC, DIO_PIN2, Output);
	DIO_VoidSetPinDir(DIO_GroupC, DIO_PIN3, Output);
	/*Leg 3*/
	DIO_VoidSetPinDir(DIO_GroupD, DIO_PIN3, Output);
	DIO_VoidSetPinDir(DIO_GroupD, DIO_PIN4, Output);
	DIO_VoidSetPinDir(DIO_GroupA, DIO_PIN1, Output);
	/*Leg 4*/
	DIO_VoidSetPinDir(DIO_GroupA, DIO_PIN2, Output);
	DIO_VoidSetPinDir(DIO_GroupA, DIO_PIN3, Output);
	DIO_VoidSetPinDir(DIO_GroupA, DIO_PIN4, Output);

	/*Initial values for all pins is high*/
	/*Leg 1*/
	DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN5, High);
	DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN6, High);
	DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN7, High);
	/*Leg 2*/
	DIO_VoidSetPinValue(DIO_GroupC, DIO_PIN1, High);
	DIO_VoidSetPinValue(DIO_GroupC, DIO_PIN2, High);
	DIO_VoidSetPinValue(DIO_GroupC, DIO_PIN3, High);
	/*Leg 3*/
	DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN3, High);
	DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN4, High);
	DIO_VoidSetPinValue(DIO_GroupA, DIO_PIN1, High);
	/*Leg 4*/
	DIO_VoidSetPinValue(DIO_GroupA, DIO_PIN2, High);
	DIO_VoidSetPinValue(DIO_GroupA, DIO_PIN3, High);
	DIO_VoidSetPinValue(DIO_GroupA, DIO_PIN4, High);

	while(1)
	{
//		BluetoothChar = Blutooth_ReceiveChar();
//
//		if(BluetoothChar == 'f')
//		{
//			Forward();
//		}
//		if(BluetoothChar == 'b')
//		{
//			Backward();
//		}
//		if(BluetoothChar == 'r')
//		{
//			ToRight();
//		}
//		if(BluetoothChar == 'l')
//		{
//			ToLeft();
//		}
		_delay_ms(5000);
		Forward();
	}






}

void PWM(void)
{
	/*Incrementing counter every time TIF is set*/
	counter++;

	/*Clearing servo pins according to its required angle*/
	/*Leg 1*/
	if(counter == angle1)
	{
		DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN5, Low);
	}
	if(counter == angle2)
	{
		DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN6, Low);
	}
	if(counter == angle3)
	{
		DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN7, Low);
	}
	/*Leg 2*/
	if(counter == angle4)
	{
		DIO_VoidSetPinValue(DIO_GroupC, DIO_PIN1, Low);
	}
	if(counter == angle5)
	{
		DIO_VoidSetPinValue(DIO_GroupC, DIO_PIN2, Low);
	}
	if(counter == angle6)
	{
		DIO_VoidSetPinValue(DIO_GroupC, DIO_PIN3, Low);
	}
	/*Leg 3*/
	if(counter == angle7)
	{
		DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN3, Low);
	}
	if(counter == angle8)
	{
		DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN4, Low);
	}
	if(counter == angle9)
	{
		DIO_VoidSetPinValue(DIO_GroupA, DIO_PIN1, Low);
	}
	/*Leg 4*/
	if(counter == angle10)
	{
		DIO_VoidSetPinValue(DIO_GroupA, DIO_PIN2, Low);
	}
	if(counter == angle11)
	{
		DIO_VoidSetPinValue(DIO_GroupA, DIO_PIN3, Low);
	}
	if(counter == angle12)
	{
		DIO_VoidSetPinValue(DIO_GroupA, DIO_PIN4, Low);
	}

	/*
	 * Here is the end of the period,
	 * to begin a new period, we will set all servo pins,
	 * also, we will reset the counter to begin this new period.
	 */
	if(counter == 160)
	{
		/*Setting all servo pins*/
		/*Leg 1*/
		DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN5, High);
		DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN6, High);
		DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN7, High);
		/*Leg 2*/
		DIO_VoidSetPinValue(DIO_GroupC, DIO_PIN1, High);
		DIO_VoidSetPinValue(DIO_GroupC, DIO_PIN2, High);
		DIO_VoidSetPinValue(DIO_GroupC, DIO_PIN3, High);
		/*Leg 3*/
		DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN3, High);
		DIO_VoidSetPinValue(DIO_GroupD, DIO_PIN4, High);
		DIO_VoidSetPinValue(DIO_GroupA, DIO_PIN1, High);
		/*Leg 4*/
		DIO_VoidSetPinValue(DIO_GroupA, DIO_PIN2, High);
		DIO_VoidSetPinValue(DIO_GroupA, DIO_PIN3, High);
		DIO_VoidSetPinValue(DIO_GroupA, DIO_PIN4, High);

		/*Reseting the counter*/
		counter = 0;
	}
}

void Forward(void)
{
	/*leg 1*/
	angle1 = POSN3;
	angle2 = NaturalPos;
	angle3 = POS8N;

	/*leg 2*/
	angle4 = POS7N;
	angle5 = NaturalPos;
	angle6 = POS8N;

	/*leg 3*/
	angle7 = NaturalPos;
	angle8 = NaturalPos;
	angle9 = POS8N;

	/*leg 4*/
	angle10 = NaturalPos;
	angle11 = NaturalPos;
	angle12 = POS8N;
	_delay_ms(500);

	/*Step 1*/
	/*leg 1*/
	angle2 = POSN5;
	_delay_ms(70);
	angle2 = POSN4;
	_delay_ms(70);
	angle2 = POSN3;
	_delay_ms(70);
	angle2 = POSN2;

	angle3 = POS7N;
	_delay_ms(70);
	angle3 = NaturalPos;
	_delay_ms(70);
	angle3 = POSN5;
	_delay_ms(70);
	angle3 = POSN4;
	_delay_ms(70);
	angle3 = POSN3;
	_delay_ms(500);

	angle1 = POSN4;
	_delay_ms(70);
	angle1 = POSN5;
	_delay_ms(70);
	angle1 = NaturalPos;
	_delay_ms(500);

	angle3 = POSN4;
	_delay_ms(70);
	angle3 = POSN5;
	_delay_ms(70);
	angle3 = NaturalPos;
	_delay_ms(70);
	angle3 = POS7N;
	_delay_ms(70);
	angle3 = POS8N;

	angle2 = POSN3;
	_delay_ms(70);
	angle2 = POSN4;
	_delay_ms(70);
	angle2 = POSN5;
	_delay_ms(70);
	angle2 = NaturalPos;

	_delay_ms(500);

	/*leg 4*/
	angle11 = POSN5;
	_delay_ms(70);
	angle11 = POSN4;
	_delay_ms(70);
	angle11 = POSN3;
	_delay_ms(70);
	angle11 = POSN2;
	angle12 = POS7N;
	_delay_ms(70);
	angle12 = NaturalPos;
	_delay_ms(70);
	angle12 = POSN5;
	_delay_ms(70);
	angle12 = POSN4;
	_delay_ms(70);
	angle12 = POSN3;
	_delay_ms(500);
	angle10 = POSN5;
	_delay_ms(70);
	angle10 = POSN4;
	_delay_ms(70);
	angle10 = POSN3;
	_delay_ms(500);
	angle12 = POSN4;
	_delay_ms(70);
	angle12 = POSN5;
	_delay_ms(70);
	angle12 = NaturalPos;
	_delay_ms(70);
	angle12 = POS7N;
	_delay_ms(70);
	angle12 = POS8N;
	angle11 = POSN3;
	_delay_ms(70);
	angle11 = POSN4;
	_delay_ms(70);
	angle11 = POSN5;
	_delay_ms(70);
	angle11 = NaturalPos;
	_delay_ms(500);

	/*leg 2 and 3*/
	angle4 = NaturalPos;
	angle7 = POS7N;
	_delay_ms(500);

//	/*STOP HERE*/
	/*leg 1*/
	angle1 = NaturalPos;
	angle2 = NaturalPos;
	angle3 = POS8N;

	/*leg 2*/
	angle4 = NaturalPos;
	angle5 = NaturalPos;
	angle6 = POS8N;

	/*leg 3*/
	angle7 = POS7N;
	angle8 = NaturalPos;
	angle9 = POS8N;

	/*leg 4*/
	angle10 = POSN3;
	angle11 = NaturalPos;
	angle12 = POS8N;

	/*Step 2*/
	/*leg 3*/
	angle8 = POSN5;
	_delay_ms(70);
	angle8 = POSN4;
	_delay_ms(70);
	angle8 = POSN3;
	_delay_ms(70);
	angle8 = POSN2;
	angle9 = POS7N;
	_delay_ms(70);
	angle9 = NaturalPos;
	_delay_ms(70);
	angle9 = POSN5;
	_delay_ms(70);
	angle9 = POSN4;
	_delay_ms(70);
	angle9 = POSN3;
	_delay_ms(500);

	angle7 = NaturalPos;
	_delay_ms(500);
	angle9 = POSN4;
	_delay_ms(70);
	angle9 = POSN5;
	_delay_ms(70);
	angle9 = NaturalPos;
	_delay_ms(70);
	angle9 = POS7N;
	_delay_ms(70);
	angle9 = POS8N;
	angle8 = POSN3;
	_delay_ms(70);
	angle8 = POSN4;
	_delay_ms(70);
	angle8 = POSN5;
	_delay_ms(70);
	angle8 = NaturalPos;
	_delay_ms(500);

	/*leg 2*/
	angle5 = POSN2;
	angle6 = POSN3;
	_delay_ms(500);
	angle4 = POS7N;
	_delay_ms(500);
	angle6 = POS8N;
	angle5 = NaturalPos;
	_delay_ms(500);

	/*leg 1 and 4*/
	angle1 = POSN5;
	_delay_ms(70);
	angle1 = POSN4;
	_delay_ms(70);
	angle1 = POSN3;
	angle10 = POSN4;
	_delay_ms(70);
	angle10 = POSN5;
	_delay_ms(70);
	angle10 = NaturalPos;
	_delay_ms(500);
}

void Backward(void)
{
	/*leg 1*/
	angle1 = POSN3;
	angle2 = NaturalPos;
	angle3 = POS8N;

	/*leg 2*/
	angle4 = POS7N;
	angle5 = NaturalPos;
	angle6 = POS8N;

	/*leg 3*/
	angle7 = NaturalPos;
	angle8 = NaturalPos;
	angle9 = POS8N;

	/*leg 4*/
	angle10 = NaturalPos;
	angle11 = NaturalPos;
	angle12 = POS8N;
	_delay_ms(500);

	/*Step 1*/
	/*leg 1*/
	angle2 = POSN5;
	_delay_ms(70);
	angle2 = POSN4;
	_delay_ms(70);
	angle2 = POSN3;
	_delay_ms(70);
	angle2 = POSN2;

	angle3 = POS7N;
	_delay_ms(70);
	angle3 = NaturalPos;
	_delay_ms(70);
	angle3 = POSN5;
	_delay_ms(70);
	angle3 = POSN4;
	_delay_ms(70);
	angle3 = POSN3;
	_delay_ms(500);

	angle1 = POSN4;
	_delay_ms(70);
	angle1 = POSN5;
	_delay_ms(70);
	angle1 = NaturalPos;
	_delay_ms(500);

	angle3 = POSN4;
	_delay_ms(70);
	angle3 = POSN5;
	_delay_ms(70);
	angle3 = NaturalPos;
	_delay_ms(70);
	angle3 = POS7N;
	_delay_ms(70);
	angle3 = POS8N;

	angle2 = POSN3;
	_delay_ms(70);
	angle2 = POSN4;
	_delay_ms(70);
	angle2 = POSN5;
	_delay_ms(70);
	angle2 = NaturalPos;

	_delay_ms(500);

	/*leg 4*/
	angle11 = POSN5;
	_delay_ms(70);
	angle11 = POSN4;
	_delay_ms(70);
	angle11 = POSN3;
	_delay_ms(70);
	angle11 = POSN2;
	angle12 = POS7N;
	_delay_ms(70);
	angle12 = NaturalPos;
	_delay_ms(70);
	angle12 = POSN5;
	_delay_ms(70);
	angle12 = POSN4;
	_delay_ms(70);
	angle12 = POSN3;
	_delay_ms(500);
	angle10 = POSN5;
	_delay_ms(70);
	angle10 = POSN4;
	_delay_ms(70);
	angle10 = POSN3;
	_delay_ms(500);
	angle12 = POSN4;
	_delay_ms(70);
	angle12 = POSN5;
	_delay_ms(70);
	angle12 = NaturalPos;
	_delay_ms(70);
	angle12 = POS7N;
	_delay_ms(70);
	angle12 = POS8N;
	angle11 = POSN3;
	_delay_ms(70);
	angle11 = POSN4;
	_delay_ms(70);
	angle11 = POSN5;
	_delay_ms(70);
	angle11 = NaturalPos;
	_delay_ms(500);

	/*leg 2 and 3*/
	angle4 = NaturalPos;
	angle7 = POS7N;
	_delay_ms(500);

//	/*STOP HERE*/
	/*leg 1*/
	angle1 = NaturalPos;
	angle2 = NaturalPos;
	angle3 = POS8N;

	/*leg 2*/
	angle4 = NaturalPos;
	angle5 = NaturalPos;
	angle6 = POS8N;

	/*leg 3*/
	angle7 = POS7N;
	angle8 = NaturalPos;
	angle9 = POS8N;

	/*leg 4*/
	angle10 = POSN3;
	angle11 = NaturalPos;
	angle12 = POS8N;

	/*Step 2*/
	/*leg 3*/
	angle8 = POSN5;
	_delay_ms(70);
	angle8 = POSN4;
	_delay_ms(70);
	angle8 = POSN3;
	_delay_ms(70);
	angle8 = POSN2;
	angle9 = POS7N;
	_delay_ms(70);
	angle9 = NaturalPos;
	_delay_ms(70);
	angle9 = POSN5;
	_delay_ms(70);
	angle9 = POSN4;
	_delay_ms(70);
	angle9 = POSN3;
	_delay_ms(500);

	angle7 = NaturalPos;
	_delay_ms(500);
	angle9 = POSN4;
	_delay_ms(70);
	angle9 = POSN5;
	_delay_ms(70);
	angle9 = NaturalPos;
	_delay_ms(70);
	angle9 = POS7N;
	_delay_ms(70);
	angle9 = POS8N;
	angle8 = POSN3;
	_delay_ms(70);
	angle8 = POSN4;
	_delay_ms(70);
	angle8 = POSN5;
	_delay_ms(70);
	angle8 = NaturalPos;
	_delay_ms(500);

	/*leg 2*/
	angle5 = POSN2;
	angle6 = POSN3;
	_delay_ms(500);
	angle4 = POS7N;
	_delay_ms(500);
	angle6 = POS8N;
	angle5 = NaturalPos;
	_delay_ms(500);

	/*leg 1 and 4*/
	angle1 = POSN5;
	_delay_ms(70);
	angle1 = POSN4;
	_delay_ms(70);
	angle1 = POSN3;
	angle10 = POSN4;
	_delay_ms(70);
	angle10 = POSN5;
	_delay_ms(70);
	angle10 = NaturalPos;
	_delay_ms(500);
}

void ToRight(void)
{
	/*leg 1*/
	angle1 = POSN3;
	angle2 = NaturalPos;
	angle3 = POS8N;

	/*leg 2*/
	angle4 = POS7N;
	angle5 = NaturalPos;
	angle6 = POS8N;

	/*leg 3*/
	angle7 = NaturalPos;
	angle8 = NaturalPos;
	angle9 = POS8N;

	/*leg 4*/
	angle10 = NaturalPos;
	angle11 = NaturalPos;
	angle12 = POS8N;
	_delay_ms(500);

	/*Step 1*/
	/*leg 1*/
	angle2 = POSN5;
	_delay_ms(70);
	angle2 = POSN4;
	_delay_ms(70);
	angle2 = POSN3;
	_delay_ms(70);
	angle2 = POSN2;

	angle3 = POS7N;
	_delay_ms(70);
	angle3 = NaturalPos;
	_delay_ms(70);
	angle3 = POSN5;
	_delay_ms(70);
	angle3 = POSN4;
	_delay_ms(70);
	angle3 = POSN3;
	_delay_ms(500);

	angle1 = POSN4;
	_delay_ms(70);
	angle1 = POSN5;
	_delay_ms(70);
	angle1 = NaturalPos;
	_delay_ms(500);

	angle3 = POSN4;
	_delay_ms(70);
	angle3 = POSN5;
	_delay_ms(70);
	angle3 = NaturalPos;
	_delay_ms(70);
	angle3 = POS7N;
	_delay_ms(70);
	angle3 = POS8N;

	angle2 = POSN3;
	_delay_ms(70);
	angle2 = POSN4;
	_delay_ms(70);
	angle2 = POSN5;
	_delay_ms(70);
	angle2 = NaturalPos;

	_delay_ms(500);

	/*leg 4*/
	angle11 = POSN5;
	_delay_ms(70);
	angle11 = POSN4;
	_delay_ms(70);
	angle11 = POSN3;
	_delay_ms(70);
	angle11 = POSN2;
	angle12 = POS7N;
	_delay_ms(70);
	angle12 = NaturalPos;
	_delay_ms(70);
	angle12 = POSN5;
	_delay_ms(70);
	angle12 = POSN4;
	_delay_ms(70);
	angle12 = POSN3;
	_delay_ms(500);
	angle10 = POSN5;
	_delay_ms(70);
	angle10 = POSN4;
	_delay_ms(70);
	angle10 = POSN3;
	_delay_ms(500);
	angle12 = POSN4;
	_delay_ms(70);
	angle12 = POSN5;
	_delay_ms(70);
	angle12 = NaturalPos;
	_delay_ms(70);
	angle12 = POS7N;
	_delay_ms(70);
	angle12 = POS8N;
	angle11 = POSN3;
	_delay_ms(70);
	angle11 = POSN4;
	_delay_ms(70);
	angle11 = POSN5;
	_delay_ms(70);
	angle11 = NaturalPos;
	_delay_ms(500);

	/*leg 2 and 3*/
	angle4 = NaturalPos;
	angle7 = POS7N;
	_delay_ms(500);

//	/*STOP HERE*/
	/*leg 1*/
	angle1 = NaturalPos;
	angle2 = NaturalPos;
	angle3 = POS8N;

	/*leg 2*/
	angle4 = NaturalPos;
	angle5 = NaturalPos;
	angle6 = POS8N;

	/*leg 3*/
	angle7 = POS7N;
	angle8 = NaturalPos;
	angle9 = POS8N;

	/*leg 4*/
	angle10 = POSN3;
	angle11 = NaturalPos;
	angle12 = POS8N;

	/*Step 2*/
	/*leg 3*/
	angle8 = POSN5;
	_delay_ms(70);
	angle8 = POSN4;
	_delay_ms(70);
	angle8 = POSN3;
	_delay_ms(70);
	angle8 = POSN2;
	angle9 = POS7N;
	_delay_ms(70);
	angle9 = NaturalPos;
	_delay_ms(70);
	angle9 = POSN5;
	_delay_ms(70);
	angle9 = POSN4;
	_delay_ms(70);
	angle9 = POSN3;
	_delay_ms(500);

	angle7 = NaturalPos;
	_delay_ms(500);
	angle9 = POSN4;
	_delay_ms(70);
	angle9 = POSN5;
	_delay_ms(70);
	angle9 = NaturalPos;
	_delay_ms(70);
	angle9 = POS7N;
	_delay_ms(70);
	angle9 = POS8N;
	angle8 = POSN3;
	_delay_ms(70);
	angle8 = POSN4;
	_delay_ms(70);
	angle8 = POSN5;
	_delay_ms(70);
	angle8 = NaturalPos;
	_delay_ms(500);

	/*leg 2*/
	angle5 = POSN2;
	angle6 = POSN3;
	_delay_ms(500);
	angle4 = POS7N;
	_delay_ms(500);
	angle6 = POS8N;
	angle5 = NaturalPos;
	_delay_ms(500);

	/*leg 1 and 4*/
	angle1 = POSN5;
	_delay_ms(70);
	angle1 = POSN4;
	_delay_ms(70);
	angle1 = POSN3;
	angle10 = POSN4;
	_delay_ms(70);
	angle10 = POSN5;
	_delay_ms(70);
	angle10 = NaturalPos;
	_delay_ms(500);
}

void ToLeft(void)
{
	/*leg 1*/
	angle1 = POSN3;
	angle2 = NaturalPos;
	angle3 = POS8N;

	/*leg 2*/
	angle4 = POS7N;
	angle5 = NaturalPos;
	angle6 = POS8N;

	/*leg 3*/
	angle7 = NaturalPos;
	angle8 = NaturalPos;
	angle9 = POS8N;

	/*leg 4*/
	angle10 = NaturalPos;
	angle11 = NaturalPos;
	angle12 = POS8N;
	_delay_ms(500);

	/*Step 1*/
	/*leg 1*/
	angle2 = POSN5;
	_delay_ms(70);
	angle2 = POSN4;
	_delay_ms(70);
	angle2 = POSN3;
	_delay_ms(70);
	angle2 = POSN2;

	angle3 = POS7N;
	_delay_ms(70);
	angle3 = NaturalPos;
	_delay_ms(70);
	angle3 = POSN5;
	_delay_ms(70);
	angle3 = POSN4;
	_delay_ms(70);
	angle3 = POSN3;
	_delay_ms(500);

	angle1 = POSN4;
	_delay_ms(70);
	angle1 = POSN5;
	_delay_ms(70);
	angle1 = NaturalPos;
	_delay_ms(500);

	angle3 = POSN4;
	_delay_ms(70);
	angle3 = POSN5;
	_delay_ms(70);
	angle3 = NaturalPos;
	_delay_ms(70);
	angle3 = POS7N;
	_delay_ms(70);
	angle3 = POS8N;

	angle2 = POSN3;
	_delay_ms(70);
	angle2 = POSN4;
	_delay_ms(70);
	angle2 = POSN5;
	_delay_ms(70);
	angle2 = NaturalPos;

	_delay_ms(500);

	/*leg 4*/
	angle11 = POSN5;
	_delay_ms(70);
	angle11 = POSN4;
	_delay_ms(70);
	angle11 = POSN3;
	_delay_ms(70);
	angle11 = POSN2;
	angle12 = POS7N;
	_delay_ms(70);
	angle12 = NaturalPos;
	_delay_ms(70);
	angle12 = POSN5;
	_delay_ms(70);
	angle12 = POSN4;
	_delay_ms(70);
	angle12 = POSN3;
	_delay_ms(500);
	angle10 = POSN5;
	_delay_ms(70);
	angle10 = POSN4;
	_delay_ms(70);
	angle10 = POSN3;
	_delay_ms(500);
	angle12 = POSN4;
	_delay_ms(70);
	angle12 = POSN5;
	_delay_ms(70);
	angle12 = NaturalPos;
	_delay_ms(70);
	angle12 = POS7N;
	_delay_ms(70);
	angle12 = POS8N;
	angle11 = POSN3;
	_delay_ms(70);
	angle11 = POSN4;
	_delay_ms(70);
	angle11 = POSN5;
	_delay_ms(70);
	angle11 = NaturalPos;
	_delay_ms(500);

	/*leg 2 and 3*/
	angle4 = NaturalPos;
	angle7 = POS7N;
	_delay_ms(500);

//	/*STOP HERE*/
	/*leg 1*/
	angle1 = NaturalPos;
	angle2 = NaturalPos;
	angle3 = POS8N;

	/*leg 2*/
	angle4 = NaturalPos;
	angle5 = NaturalPos;
	angle6 = POS8N;

	/*leg 3*/
	angle7 = POS7N;
	angle8 = NaturalPos;
	angle9 = POS8N;

	/*leg 4*/
	angle10 = POSN3;
	angle11 = NaturalPos;
	angle12 = POS8N;

	/*Step 2*/
	/*leg 3*/
	angle8 = POSN5;
	_delay_ms(70);
	angle8 = POSN4;
	_delay_ms(70);
	angle8 = POSN3;
	_delay_ms(70);
	angle8 = POSN2;
	angle9 = POS7N;
	_delay_ms(70);
	angle9 = NaturalPos;
	_delay_ms(70);
	angle9 = POSN5;
	_delay_ms(70);
	angle9 = POSN4;
	_delay_ms(70);
	angle9 = POSN3;
	_delay_ms(500);

	angle7 = NaturalPos;
	_delay_ms(500);
	angle9 = POSN4;
	_delay_ms(70);
	angle9 = POSN5;
	_delay_ms(70);
	angle9 = NaturalPos;
	_delay_ms(70);
	angle9 = POS7N;
	_delay_ms(70);
	angle9 = POS8N;
	angle8 = POSN3;
	_delay_ms(70);
	angle8 = POSN4;
	_delay_ms(70);
	angle8 = POSN5;
	_delay_ms(70);
	angle8 = NaturalPos;
	_delay_ms(500);

	/*leg 2*/
	angle5 = POSN2;
	angle6 = POSN3;
	_delay_ms(500);
	angle4 = POS7N;
	_delay_ms(500);
	angle6 = POS8N;
	angle5 = NaturalPos;
	_delay_ms(500);

	/*leg 1 and 4*/
	angle1 = POSN5;
	_delay_ms(70);
	angle1 = POSN4;
	_delay_ms(70);
	angle1 = POSN3;
	angle10 = POSN4;
	_delay_ms(70);
	angle10 = POSN5;
	_delay_ms(70);
	angle10 = NaturalPos;
	_delay_ms(500);
}

