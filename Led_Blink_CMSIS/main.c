

/**
 * main.c
 */
#include "TM4C123GH6PM.h"
#include "Led.h"
#include "SysTick.h"

int main(void)
{
    Led_Init();

    while(1)
    {
        /*Toggle Led every 1 sec */
        Led1_Toggle();
        SysTick_Delay(1000);
    }

	return 0;
}
