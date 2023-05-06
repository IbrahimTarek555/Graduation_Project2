/*
 * DIO_Program.c
 *
 *  Created on: Sep 23, 2022
 *      Author: HP-Pc
 */

#include "../Header/DIO_Interface.h"

void DIO_VoidSetPinDir(u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PinState)
{
	if((Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA)
			&&
			(Local_PinNumber <= DIO_PIN8 && Local_PinNumber >= DIO_PIN1))
	{
		if(Local_PinState == Input)
		{
			switch(Local_GroupName)
			{
				case DIO_GroupA : DIO_DDRA &= ~(1<<Local_PinNumber);
				break;

				case DIO_GroupB : DIO_DDRB &= ~(1<<Local_PinNumber);
				break;

				case DIO_GroupC : DIO_DDRC &= ~(1<<Local_PinNumber);
				break;

				case DIO_GroupD : DIO_DDRD &= ~(1<<Local_PinNumber);
				break;
			}
		}
		else if(Local_PinState == Output)
		{
			switch(Local_GroupName)
			{
				case DIO_GroupA : DIO_DDRA |= (1<<Local_PinNumber);
				break;

				case DIO_GroupB : DIO_DDRB |= (1<<Local_PinNumber);
				break;

				case DIO_GroupC : DIO_DDRC |= (1<<Local_PinNumber);
				break;

				case DIO_GroupD : DIO_DDRD |= (1<<Local_PinNumber);
				break;
			}
		}
	}
}

void DIO_VoidSetPinValue(u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PinValue)
{
	if((Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA)
			&&
			(Local_PinNumber <= DIO_PIN8 && Local_PinNumber >= DIO_PIN1))
	{
		if(Local_PinValue == Low)
		{
			switch(Local_GroupName)
			{
				case DIO_GroupA : DIO_PORTA &= ~(1<<Local_PinNumber);
				break;

				case DIO_GroupB : DIO_PORTB &= ~(1<<Local_PinNumber);
				break;

				case DIO_GroupC : DIO_PORTC &= ~(1<<Local_PinNumber);
				break;

				case DIO_GroupD : DIO_PORTD &= ~(1<<Local_PinNumber);
				break;
			}
		}
		else if(Local_PinValue == High)
		{
			switch(Local_GroupName)
			{
				case DIO_GroupA : DIO_PORTA |= (1<<Local_PinNumber);
				break;

				case DIO_GroupB : DIO_PORTB |= (1<<Local_PinNumber);
				break;

				case DIO_GroupC : DIO_PORTC |= (1<<Local_PinNumber);
				break;

				case DIO_GroupD : DIO_PORTD |= (1<<Local_PinNumber);
				break;
			}
		}
	}
}

u8 DIO_U8GetPinValue(u8 Local_GroupName, u8 Local_PinNumber)
{
	if((Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA)
			&&
			(Local_PinNumber <= DIO_PIN8 && Local_PinNumber >= DIO_PIN1))
	{
		switch(Local_GroupName)
		{
			case DIO_GroupA : return ((DIO_PINA >> Local_PinNumber) & 0x01);
			case DIO_GroupB : return ((DIO_PINB >> Local_PinNumber) & 0x01);
			case DIO_GroupC : return ((DIO_PINC >> Local_PinNumber) & 0x01);
			case DIO_GroupD : return ((DIO_PIND >> Local_PinNumber) & 0x01);
		}
	}

	return 2;
}


void DIO_VoidSetPortDir(u8 Local_GroupName, u8 Local_PortState)
{
	if(Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA)
	{
		if(Local_PortState == OUTPUT)
		{
			switch(Local_GroupName)
			{
				case DIO_GroupA : DIO_DDRA = 0xff;
				break;
				case DIO_GroupB : DIO_DDRB = 0xff;
				break;
				case DIO_GroupC : DIO_DDRC = 0xff;
				break;
				case DIO_GroupD : DIO_DDRD = 0xff;
				break;
			}
		}
		else if(Local_PortState == INPUT)
		{
			switch(Local_GroupName)
			{
				case DIO_GroupA : DIO_DDRA = 0x00;
				break;
				case DIO_GroupB : DIO_DDRB = 0x00;
				break;
				case DIO_GroupC : DIO_DDRC = 0x00;
				break;
				case DIO_GroupD : DIO_DDRD = 0x00;
				break;
			}
		}
	}
}

void DIO_VoidSetPortValue(u8 Local_GroupName, u8 Local_PortValue)
{
	if(Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA)
	{
		if(Local_PortValue == HIGH)
		{
			switch(Local_GroupName)
			{
				case DIO_GroupA : DIO_PORTA = 0xff;
				break;
				case DIO_GroupB : DIO_PORTB = 0xff;
				break;
				case DIO_GroupC : DIO_PORTC = 0xff;
				break;
				case DIO_GroupD : DIO_PORTD = 0xff;
				break;
			}
		}
		else if(Local_PortValue == LOW)
		{
			switch(Local_GroupName)
			{
				case DIO_GroupA : DIO_PORTA = 0x00;
				break;
				case DIO_GroupB : DIO_PORTB = 0x00;
				break;
				case DIO_GroupC : DIO_PORTC = 0x00;
				break;
				case DIO_GroupD : DIO_PORTD = 0x00;
				break;
			}
		}
	}
}

u8 DIO_U8GetPortValue(u8 Local_GroupName)
{
	if(Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA)
	{
		switch(Local_GroupName)
		{
			case DIO_GroupA : return DIO_PINA;
			case DIO_GroupB : return DIO_PINB;
			case DIO_GroupC : return DIO_PINC;
			case DIO_GroupD : return DIO_PIND;
		}
	}
	return 2;
}

void DIO_VoidPinInternalPullUpControl(u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PullUpState)
{
	if((Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA)
			&&
			(Local_PinNumber <= DIO_PIN8 && Local_PinNumber >= DIO_PIN1))
	{
		if(Local_PullUpState == DIO_PullUpDis)
		{
			switch(Local_GroupName)
			{
				case DIO_GroupA : DIO_PORTA &= ~(1<<Local_PinNumber);
				break;

				case DIO_GroupB : DIO_PORTB &= ~(1<<Local_PinNumber);
				break;

				case DIO_GroupC : DIO_PORTC &= ~(1<<Local_PinNumber);
				break;

				case DIO_GroupD : DIO_PORTD &= ~(1<<Local_PinNumber);
				break;
			}
		}

		else if(Local_PullUpState == DIO_PullUpEn)
		{
			switch(Local_GroupName)
			{
				case DIO_GroupA : DIO_PORTA |= (1<<Local_PinNumber);
				break;

				case DIO_GroupB : DIO_PORTB |= (1<<Local_PinNumber);
				break;

				case DIO_GroupC : DIO_PORTC |= (1<<Local_PinNumber);
				break;

				case DIO_GroupD : DIO_PORTD |= (1<<Local_PinNumber);
				break;
			}
		}
	}
}

void DIO_VoidPortInternalPullUpControl(u8 Local_GroupName, u8 Local_PullUpState)
{
	if(Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA)
	{
		if(Local_PullUpState == DIO_PullUpDis)
		{
			switch(Local_GroupName)
			{
				case DIO_GroupA : DIO_PORTA = 0x00;
				break;

				case DIO_GroupB : DIO_PORTB = 0x00;
				break;

				case DIO_GroupC : DIO_PORTC = 0x00;
				break;

				case DIO_GroupD : DIO_PORTD = 0x00;
				break;
			}
		}

		else if(Local_PullUpState == DIO_PullUpEn)
		{
			switch(Local_GroupName)
			{
				case DIO_GroupA : DIO_PORTA = 0xff;
				break;

				case DIO_GroupB : DIO_PORTB = 0xff;
				break;

				case DIO_GroupC : DIO_PORTC = 0xff;
				break;

				case DIO_GroupD : DIO_PORTD = 0xff;
				break;
			}
		}
	}
}

void DIO_VoidManualSetPortDir(u8 Local_GroupName, u8 Local_PortState)
{
	if(Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA)
	{
		switch(Local_GroupName)
		{
			case DIO_GroupA : DIO_DDRA = Local_PortState;
			break;
			case DIO_GroupB : DIO_DDRB = Local_PortState;
			break;
			case DIO_GroupC : DIO_DDRC = Local_PortState;
			break;
			case DIO_GroupD : DIO_DDRD = Local_PortState;
			break;
		}
	}
}

void DIO_VoidManualSetPortValue(u8 Local_GroupName, u8 Local_PortValue)
{
	if(Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA)
	{
		switch(Local_GroupName)
		{
			case DIO_GroupA : DIO_PORTA = Local_PortValue;
			break;
			case DIO_GroupB : DIO_PORTB = Local_PortValue;
			break;
			case DIO_GroupC : DIO_PORTC = Local_PortValue;
			break;
			case DIO_GroupD : DIO_PORTD = Local_PortValue;
			break;
		}
	}
}
