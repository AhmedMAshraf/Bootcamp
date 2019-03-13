

/**
 * main.c
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "Keypad.h"
#include "Debouncing.h"
#include "UART.h"
#include "Schedular.h"
#include "K2S.h"

int main(void)
{
    Keypad_Init();
    UART0_init();
    scheduler_Init();
    /*Add Four Tasks*/

   scheduler_Add_Task(Debounce_Task,5,priority_1,ID_1);
   scheduler_Add_Task(UART0_Send_Task,50,priority_1,ID_0);
   scheduler_Add_Task(K2S_Task,70,priority_1,ID_2);

    scheduler_Start(OS_TICK_INTERVAL_MSEC);

}
