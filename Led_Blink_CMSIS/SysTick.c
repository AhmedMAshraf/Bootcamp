/*
 * SysTick.c
 *
 *  Created on: Mar 16, 2019
 *      Author: AVE-LAP-062
 */
#include "SysTick.h"
#include "TM4C123GH6PM.h"


#define SYS_CLK 0x04
#define SYS_PIOSC 0x00
#define CLK_SRC SYS_CLK

#define INTEN 0

#define SYSTICK_ENABLE 0x01

#define MS_1            16000
#define SYSTICK_COUNT_FLAG   (1<<16)


void SysTick_Delay(uint32_t delay)
{
    /*Set The ReLoad value of SysTick*/
    SysTick->LOAD = delay * MS_1;

    /*Clear The STCURRENT */
    SysTick->VAL = 0 ;

    /*Operate on System clock disable interrupt */
    SysTick->CTRL |= CLK_SRC | INTEN | SYSTICK_ENABLE ;

    /*Check Count Flag */
    while(!((SysTick->CTRL)&SYSTICK_COUNT_FLAG));
}
