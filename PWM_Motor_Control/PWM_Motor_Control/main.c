/*
 * PWM_Motor_Control.c
 *
 * Created: 2/21/2019 11:51:58 AM
 * Author : AVE-LAP-062
 */ 

#include "Includes/PWM.h"
#include "Includes/timer.h"

int main(void)
{
    /* Replace with your application code */
	
	timer_init();
	Timer1_PWM_Init();
	uint8 duty = DUTY0 ;
    while (1) 
    {
		for(duty=0 ; duty<= DUTY100 ; duty+=10)
		{
			Timer1_PWM_Change_Duty(duty);
			timer_delay(ONE_SECOND);
		}
		if(duty >= 100)
			duty = DUTY0 ;
		timer_delay(ONE_SECOND);
    }
}

