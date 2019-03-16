/*
 * Led.c
 *
 *  Created on: Mar 16, 2019
 *      Author: AVE-LAP-062
 */
#include "Led.h"
#include "TM4C123GH6PM.h"


#define LED_PORT 0x20
#define LED1_PIN 0x02
#define LED2_PIN 0x04
#define LED3_PIN 0x08


void Led_Init(void)
{
    /*Activate PORTF Clock*/
    SYSCTL->RCGCGPIO |= LED_PORT ;
    /*Disable Analog Function of PORTF*/
    GPIOF->AMSEL = 0x00 ;
    /*Set Direction of PF1 , PF2 , PF3 output*/
    GPIOF->DIR |= LED1_PIN | LED2_PIN | LED3_PIN ;
    /*Disable Alternate Function of PORTF*/
    GPIOF->AFSEL = 0x00 ;
    /*Enable digital I/O on PF1 , PF2 , PF3 */
    GPIOF->DEN = LED1_PIN | LED2_PIN | LED3_PIN ;
}

void Led1_Toggle(void)
{
    GPIOF->DATA ^= LED1_PIN ;
}
