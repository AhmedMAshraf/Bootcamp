/*
 * ISR.c
 *
 * Created: 2/20/2019 4:52:57 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/ISR.h"



uint16 static volatile Timer_0_Tick ;
uint16 Timer_0_Flag = 0 ;
uint8 Ext_Int_2_Flag = 0 ;

/*Interupt service routine for timer0 overflow */

void ISR_INT2_Init(void)
{
	Set_Bit(MCUCSR,ISC2);
	Set_Bit(GICR,INT2);
}

ISR(TIMER0_COMP_vect)
{
	Timer_0_Flag ++ ;
}

ISR(INT2_vect)
{
	Ext_Int_2_Flag = 1 ;
}