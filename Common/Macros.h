/*
 * Macros.h
 *
 *  Created on: Sep 17, 2022
 *      Author: HP-Pc
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define NULL	((void*)0)

#define En		1
#define Dis		0

#define Ok		0
#define NOk		1

#define Zero	0
#define	One		1
#define	Two		2
#define Three	3
#define Four	4
#define Five	5
#define Six		6
#define Seven	7
#define Eight	8
#define Nine	9

#define Pressed 	1
#define NotPressed 	0

#define High		1
#define Low			0

#define Output		1
#define Input		0

#define HIGH		0xff
#define LOW			0x00

#define OUTPUT		0xff
#define INPUT		0x00


//ISR Parameters
#define ISR(Vector)		void Vector(void)	__attribute__ ((signal));\
						void Vector(void)

#define INT0			__vector_1
#define INT1			__vector_2
#define INT2			__vector_3
#define Timer0_COMP		__vector_10
#define Timer0_OVF		__vector_11
#define ADC_INT			__vector_16




#endif /* COMMON_MACROS_H_ */
