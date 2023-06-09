

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BITNO) 		(VAR|=(1<<BITNO))
#define CLR_BIT(VAR,BITNO) 		(VAR&=(~(1<<BITNO)))
#define TOGGLE_BIT(VAR,BITNO)	(VAR^=(1<<BITNO))
#define GET_BIT(VAR,BITNO) 		((VAR>>BITNO)&1)

#endif