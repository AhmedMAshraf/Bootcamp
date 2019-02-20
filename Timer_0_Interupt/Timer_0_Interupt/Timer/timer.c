/*
 * timer.c
 *
 * Created: 2/13/2019 4:41:51 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/timer.h"
#include <avr/interrupt.h>

/* timer_init */
/* Parameters : N/A */
/* I/p : N/A */
/* O/p : N/A */
/* Return : void */
/* Function that initalize timer zero */
void timer_init()
{
	/* CTC Mode */
	Set_Bit(TCCR0,3);
	Clear_Bit(TCCR0,6);
	
	/* Set Timer 0 compare match interupt enable */
	Set_Bit(TIMSK,OCIE0);
	
	/* Clear TCNT0 & set OCR0 to 250 */
	TCNT0 = 0x00 ;
	OCR0 = 124 ;
	
	/* 64 Prescaler */
	Set_Bit(TCCR0,0);
	Set_Bit(TCCR0,1);
	Clear_Bit(TCCR0,2);
	
	/* Set global interupt register */
	Set_Bit(SREG,GIE);
}

#if 0
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
#endif