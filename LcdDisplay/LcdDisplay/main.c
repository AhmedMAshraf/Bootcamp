/*
 * LcdDisplay.c
 *
 * Created: 2/19/2019 10:47:13 AM
 * Author : AVE-LAP-062
 */ 

#include "Includes/DIO.h"
#include "Includes/timer.h"
#include "Includes/LCD.h"


int main(void)
{
    /* Replace with your application code */
	timer_init();
	LCD_init();

	uint8 str[]={"Ahmed"};
	LCD_sendString_RowCol(str,2,4);
	timer_delay(10000);
	LCD_clear();
    while (1) 
    {
    }
}

