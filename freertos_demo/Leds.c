/*
 * Leds.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-062
 */

#include "Leds.h"

void Leds_Init(void)
{
    /* Set Leds peripheral clock (PORT F) */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    /* Set leds pins to O/P */
    GPIOPinTypeGPIOOutput(LED1PORT, LED1PIN);
    GPIOPinTypeGPIOOutput(LED2PORT, LED2PIN);
    GPIOPinTypeGPIOOutput(LED3PORT, LED3PIN);
}

void Led1_Blink(void)
{
    static uint8_t i = 0 ;
    /* Enable Led1 */
    if(i==0)
    {
        GPIOPinWrite(LED1PORT, LED1PIN,LED1_HIGH);
        i = 1 ;
    }
    else if(i==1)
    {
        GPIOPinWrite(LED1PORT, LED1PIN,LED1_LOW);
        i = 0 ;
    }

}

void Led2_Blink(void)
{
    static uint8_t i = 0 ;
        /* Enable Led1 */
        if(i==0)
        {
            GPIOPinWrite(LED2PORT, LED2PIN,LED2_HIGH);
            i = 1 ;
        }
        else if(i==1)
        {
            GPIOPinWrite(LED2PORT, LED2PIN,LED2_LOW);
            i = 0 ;
        }
}

void Led3_Blink(void)
{
    static uint8_t i = 0 ;
    /* Enable Led1 */
     if(i==0)
     {
        GPIOPinWrite(LED3PORT, LED3PIN,LED3_HIGH);
        i = 1 ;
     }
     else if(i==1)
     {
         GPIOPinWrite(LED3PORT, LED3PIN,LED3_LOW);
         i = 0 ;
      }
}
