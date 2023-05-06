/*
 * GIE_Program.c
 *
 *  Created on: Nov 6, 2022
 *      Author: HP-Pc
 */

#include "../Header/GIE_Interface.h"

void GIE_VoidEnable		(void)
{
	Set_Bit(SREG, SREG_I);
}
void GIE_VoidDisable	(void)
{
	Clr_Bit(SREG, SREG_I);
}
