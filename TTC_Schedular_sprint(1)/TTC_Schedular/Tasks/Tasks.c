/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:17:12 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/Tasks.h"


taskType TaskArray[NUM_OF_TASKS]= {BlinkLed0 , BlinkLed1 , Blinkled2 , Blinkled3};
	
/*******************************************************************/
/* BlinkLed0                                                       */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Function that set led0                                          */
/*******************************************************************/
void BlinkLed0 (void)
{
	/* Check if the periodcity of task has passed to call it*/
	static uint16 Gticks = 0 ;
	Gticks++;
	if(Gticks >= 2000)
	{
		Toggle_Bit(PORTB,4);
		Gticks = 0;
	}
	
}

/*******************************************************************/
/* BlinkLed1                                                       */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Function that set led1                                          */
/*******************************************************************/
void BlinkLed1 (void)
{
	/* Check if the periodcity of task has passed to call it*/
	static uint16 Gticks = 0 ;
	Gticks++;
	if(Gticks >= 2500)
	{
		Toggle_Bit(PORTB,5);
		Gticks = 0;
	}
}

/*******************************************************************/
/* BlinkLed2                                                       */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Function that set led2                                          */
/*******************************************************************/
void Blinkled2 (void)
{
	/* Check if the periodcity of task has passed to call it*/
	static uint16 Gticks = 0 ;
	Gticks++;
	if(Gticks >= 3000)
	{
		Toggle_Bit(PORTB,6);
		Gticks = 0 ;
	}
}

/*******************************************************************/
/* BlinkLed3                                                       */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Function that set led3                                          */
/*******************************************************************/
void Blinkled3 (void)
{
	/* Check if the periodcity of task has passed to call it*/
	static uint16 Gticks = 0 ;
	Gticks++;
	if(Gticks >= 3500)
	{
		Toggle_Bit(PORTB,7);
		Gticks = 0;
	}
}

