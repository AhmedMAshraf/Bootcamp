/*
 * timer.c
 *
 * Created: 2/13/2019 4:41:51 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/timer.h"
#include <avr/interrupt.h>

uint16 volatile OS_Ticks = 0 ;
uint8 volatile TaskStatus = 0 ;
void (*CallBack)(void);


/* timer_init */
/* Parameters : N/A */
/* I/p : N/A */
/* O/p : N/A */
/* Return : void */
/* Function that initalize timer zero */

void timer_init(uint8 OCRVal)
{
	/* CTC Mode */
	Set_Bit(TCCR0,3);
	Clear_Bit(TCCR0,6);
	
	/* Set Timer 0 compare match interupt enable */
	Set_Bit(TIMSK,OCIE0);
	
	/* Clear TCNT0 & set OCR0 to 124 (1M sec) */
	TCNT0 = ZERO ;
	OCR0 = OCRVal ;
	
	/* 64 Prescaler */
	Set_Bit(TCCR0,0);
	Set_Bit(TCCR0,1);
	Clear_Bit(TCCR0,2);
	
	/* Set global interupt register */
	Set_Bit(SREG,GIE);
}

/* Set_Call_Back */
/* Parameters : GlobalPtr */
/* I/p : Ptr to function to be set */
/* O/p : N/A */
/* Return : void */
/* Function that assigns value of call back function to the global function pointer*/

void Set_Call_Back(void (*GlobalPtr)(void))
{
	CallBack = GlobalPtr ;
}

/*Interupt service routine for timer0 overflow */

ISR(TIMER0_COMP_vect)
{
	CallBack();
}