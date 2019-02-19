/*
 * Keypad.c
 *
 * Created: 2/18/2019 2:42:14 PM
 * Author : AVE-LAP-062
 */ 

#include "Includes/timer.h"
#include "Includes/Keypad.h"
#include "Includes/BCDSevSegment.h"


int main(void)
{
    /* Replace with your application code */
	uint8 key ;
	timer_init();
	Keypad_init();
	BCDSevegments_enable();
	
    while (1) 
    {	
		timer_delay(20);
		
		key = Keypad_getPressedKey();
		
		if(key != 0)
			BCDSevegments_displayNo(key);
    }
}

