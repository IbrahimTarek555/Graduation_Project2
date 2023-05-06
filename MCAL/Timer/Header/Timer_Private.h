/*
 * Timer_Private.h
 *
 *  Created on: Dec 3, 2022
 *      Author: HP-Pc
 */

#ifndef MCAL_TIMER_HEADER_TIMER_PRIVATE_H_
#define MCAL_TIMER_HEADER_TIMER_PRIVATE_H_

// Timer 0 Waveform Generation Mode Choices:
#define Timer0_NormalMode			0b10110111
#define Timer0_PWMMode				0b11110111
#define Timer0_CTCMode				0b10111111
#define Timer0_FastPWMMode			0b11111111

// Timer 0 Prescaler Division Factor Choices:
#define Timer_NoClockSource			0
#define Timer_DivideBy1				1
#define Timer_DivideBy8				2
#define Timer_DivideBy64			3
#define Timer_DivideBy256			4
#define Timer_DivideBy1024			5

// Masks:
#define Timer0_WGMMask				0b10110111
#define Timer_PrescalerMask			0b11111000


#endif /* MCAL_TIMER_HEADER_TIMER_PRIVATE_H_ */
