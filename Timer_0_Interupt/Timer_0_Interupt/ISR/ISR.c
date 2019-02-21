/*
 * ISR.c
 *
 * Created: 2/20/2019 4:52:57 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/ISR.h"



uint16 volatile Timer_0_Flag = 0 ;
uint8 volatile Ext_Int_2_Flag = 0 ;

/*Interupt service routine for timer0 overflow */

ISR(TIMER0_COMP_vect)
{
	Timer_0_Flag ++ ;
}

/*Interupt service routine for External INT2 */

ISR(INT2_vect)
{
	Ext_Int_2_Flag = FLAG_SET ;
}