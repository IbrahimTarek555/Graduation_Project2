/*
 * Bit_Math.h
 *
 *  Created on: Sep 17, 2022
 *      Author: HP-Pc
 */

#ifndef COMMON_BIT_MATH_H_
#define COMMON_BIT_MATH_H_

#define Set_Bit(Reg,Bit_no)     Reg|=(1<<Bit_no)
#define Clr_Bit(Reg,Bit_no)     Reg&=~(1<<Bit_no)
#define Tog_Bit(Reg,Bit_no)     Reg^=(1<<Bit_no)
#define Get_Bit(Reg,Bit_no)     ((Reg>>Bit_no)&0x01)

#endif /* COMMON_BIT_MATH_H_ */
