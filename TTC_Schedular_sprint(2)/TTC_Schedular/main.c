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
	
	/* Initialize OS */
	SchedulerInit();
	
	/* Initialize tasks i want to add */
	vtask Task0 = {BlinkLed0,2000,2000};
	vtask Task1 = {BlinkLed1,2500,2500};
	vtask Task2 = {Blinkled2,3000,3000};
	vtask Task3 = {Blinkled3,3500,3500};
		
	/* Add the tasks */
	if(scheduler_Add_Struct(Task0));
	if(scheduler_Add_Struct(Task1));
	if(scheduler_Add_Struct(Task2));
	if(scheduler_Add_Struct(Task3));
	
	/* Call SchedulerInit_AndStart to init timer tics to 1 ms */
	SchedulerStart();   
}

