/*
 * Timer_Register.h
 *
 *  Created on: Dec 3, 2022
 *      Author: HP-Pc
 */

#ifndef MCAL_TIMER_HEADER_TIMER_REGISTER_H_
#define MCAL_TIMER_HEADER_TIMER_REGISTER_H_

#define TCCR0			*((volatile u8*)0x53)	/* Timer 0 Control Register */
#define TCCR0_FOC0		7						/* Timer 0 Force Output Compare Bit */
#define TCCR0_WGM00		6						/* Timer 0 Waveform Generation Mode Bit 0 */
#define TCCR0_COM01		5						/* Timer 0 Compare Output Mode Bit 1 */
#define TCCR0_COM00		4						/* Timer 0 Compare Output Mode Bit 0 */
#define TCCR0_WGM01		3						/* Timer 0 Waveform Generation Mode Bit 1 */
#define TCCR0_CS02		2						/* Timer 0 Prescaler Bit 2 */
#define TCCR0_CS01		1						/* Timer 0 Prescaler Bit 1 */
#define TCCR0_CS00		0						/* Timer 0 Prescaler Bit 0 */

#define OCR0			*((volatile u8*)0x5c)	/* Timer 0 Output Compare Register */

#define TIMSK			*((volatile u8*)0x59)	/* Timer Interrupt Mask Register */
#define TIMSK_OCIE2		7						/* Timer 2 Output Compare Match Interrupt Enable */
#define TIMSK_TOIE2		6						/* Timer 2 Overflow Interrupt Enable */
#define TIMSK_TICIE1	5						/* Timer 1 Input Capture Interrupt Enable */
#define TIMSK_OCIE1A	4						/* Timer 1 Output Compare A Match Interrupt Enable */
#define TIMSK_OCIE1B	3						/* Timer 1 Output Compare B Match Interrupt Enable */
#define TIMSK_TOIE1		2						/* Timer 1 Overflow Interrupt Enable */
#define TIMSK_OCIE0		1						/* Timer 0 Output Compare Match Interrupt Enable */
#define TIMSK_TOIE0		0						/* Timer 0 Overflow Interrupt Enable */

#define TCCR1A			*((volatile u8*)0x4f)		/* Timer 1 Control Register A */
#define TCCR1A_COM1A1	7						/* Timer 1 Compare Output Mode for Unit A Bit 1 */
#define TCCR1A_COM1A0	6						/* Timer 1 Compare Output Mode for Unit A Bit 0 */
#define TCCR1A_COM1B1	5						/* Timer 1 Compare Output Mode for Unit B Bit 1 */
#define TCCR1A_COM1B0	4						/* Timer 1 Compare Output Mode for Unit B Bit 0 */
#define TCCR1A_FOC1A	3						/* Timer 1 Force Output Compare Bit A */
#define TCCR1A_FOC1B	2						/* Timer 1 Force Output Compare Bit B */
#define TCCR1A_WGM11	1						/* Timer 1 Waveform Generation Mode Bit 1 */
#define TCCR1A_WGM10	0						/* Timer 1 Waveform Generation Mode Bit 0 */

#define TCCR1B			*((volatile u8*)0x4e)	/* Timer 1 Control Register B */
#define TCCR1B_ICNC1	7						/* Timer 1 Input Capture Noise Canceler */
#define TCCR1B_ICES1	6						/* Timer 1 Input Capture Edge Select */
#define TCCR1B_WGM13	4						/* Timer 1 Waveform Generation Mode Bit 3 */
#define TCCR1B_WGM12	3						/* Timer 1 Waveform Generation Mode Bit 2 */
#define TCCR1B_CS12		2						/* Timer 1 Prescaler Bit 2 */
#define TCCR1B_CS11		1						/* Timer 1 Prescaler Bit 1 */
#define TCCR1B_CS10		0						/* Timer 1 Prescaler Bit 0 */

#define OCR1AL			*((volatile u16*)0x4a)	/* Timer 1 Output Compare Register 1 A */
#define OCR1BL			*((volatile u16*)0x48)	/* Timer 1 Output Compare Register 1 B */
#define ICR1L			*((volatile u16*)0x46)	/* Timer 1 Input Capture Register 1 */

#define TCCR2			*((volatile u8*)0x45)	/* Timer 2 Control Register */
#define TCCR2_FOC2		7						/* Timer 2 Force Output Compare Bit */
#define TCCR2_WGM20		6						/* Timer 2 Waveform Generation Mode Bit 0 */
#define TCCR2_COM21		5						/* Timer 2 Compare Output Mode Bit 1 */
#define TCCR2_COM20		4						/* Timer 2 Compare Output Mode Bit 0 */
#define TCCR2_WGM21		3						/* Timer 2 Waveform Generation Mode Bit 1 */
#define TCCR2_CS22		2						/* Timer 2 Prescaler Bit 2 */
#define TCCR2_CS21		1						/* Timer 2 Prescaler Bit 1 */
#define TCCR2_CS20		0						/* Timer 2 Prescaler Bit 0 */

#define OCR2			*((volatile u8*)0x43)	/* Timer 2 Output Compare Register */


#endif /* MCAL_TIMER_HEADER_TIMER_REGISTER_H_ */
