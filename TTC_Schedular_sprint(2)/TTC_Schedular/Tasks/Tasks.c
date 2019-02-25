/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:17:12 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/Tasks.h"
#include "../Includes/Schedular.h"


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
	Toggle_Bit(PORTB,LED0);
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
	Toggle_Bit(PORTB,LED1);
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
	Toggle_Bit(PORTB,LED2);
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
	Toggle_Bit(PORTB,LED3);
}

