/*
 * timer.c
 *
 * Created: 2/13/2019 4:41:51 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/timer.h"
void timer_init()
{
	/* CTC Mode */
	Set_Bit(TCCR0,3);
	Clear_Bit(TCCR0,6);
	
	
	
	/* Clear TCNT0 & set OCR0 to 250 */
	TCNT0 = 0x00 ;
	OCR0 = 250 ;
	
	/* 64 Prescaler */
	Set_Bit(TCCR0,0);
	Set_Bit(TCCR0,1);
	Clear_Bit(TCCR0,2);
}

void timer_delay(uint32 n)
{
	
	/* Reset Over Flow flag*/
	Set_Bit(TIFR,0);
	/* Reset Timer count */
	TCNT0 = 0x00 ;
	
	/* Each OF = 1ms */
	for(n ; n>0 ; n--)
	{
		while(!(TIFR&0x02));
		TIFR |= 0x02 ;
	}
	
}