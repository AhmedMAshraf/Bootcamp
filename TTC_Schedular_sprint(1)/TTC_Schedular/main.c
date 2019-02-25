/*
 * TTC_Schedular.c
 *
 * Created: 2/23/2019 2:05:27 PM
 * Author : AVE-LAP-062
 */ 
#include "Includes/Schedular.h"


int main(void)
{
	/* Initialize Leds Pins directions */
	DIO_SetPinDirection(12,HIGH);
	DIO_SetPinDirection(13,HIGH);
	DIO_SetPinDirection(14,HIGH);
	DIO_SetPinDirection(15,HIGH);
	
	/* Call SchedulerInit_AndStart to init timer tics to 1 ms */
	SchedulerInit_AndStart();
	
    /* Replace with your application code */
    
}

