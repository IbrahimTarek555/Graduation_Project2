/*
 * Timer_Program.c
 *
 *  Created on: Dec 3, 2022
 *      Author: HP-Pc
 */

#include "../Header/Timer_Interface.h"

static void (*Timer0_PVCallBackFunction) (void) = NULL;

/*
 *
 * prescaler is 8
 * CTC is on
 * every 100 tick (200 microsecond) we generate an interrupt
 *
 */

void Timer0_VoidInit(void)
{
	/* Choosing Timer Waveform Generation Mode */
	Set_Bit(TCCR0, TCCR0_WGM01);
	Clr_Bit(TCCR0, TCCR0_WGM00);

	/* Setting Compare Match Value */
	OCR0 = 250;


	/* Enabling Output Compare Match Interrupt */
	Set_Bit(TIMSK, TIMSK_OCIE0);

	/* Choosing Timer 0 Prescaler Division Factor */
	Clr_Bit(TCCR0, TCCR0_CS00);
	Set_Bit(TCCR0, TCCR0_CS01);
	Clr_Bit(TCCR0, TCCR0_CS02);

}



u8 Timer0_U8SetCallBack(void (*Local_PVCallBackFunctoin) (void))
{
	u8 Local_u8ErrorState = Ok;

	if(Local_PVCallBackFunctoin != NULL)
	{
		Timer0_PVCallBackFunction = Local_PVCallBackFunctoin;
	}
	else
	{
		Local_u8ErrorState = NOk;
	}

	return Local_u8ErrorState;
}

ISR(Timer0_COMP)
{
	if(Timer0_PVCallBackFunction != NULL)
	{
		Timer0_PVCallBackFunction();
	}
}


