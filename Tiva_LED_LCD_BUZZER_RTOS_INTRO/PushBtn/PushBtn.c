/*
 * PushBtn.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-062
 */

#include "PushBtn.h"

void Btns_Init(void)
{
    /* Set Btn1 peripheral clock (PORT D) */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));

    /* Set Btn pins to I/P */
    GPIOPinTypeGPIOInput(PUSHBTN1PORT, PUSHBTN1PIN);

}

uint8_t Btn1_Read(void)
{
    uint8_t BtnState = 0 ;
    BtnState = GPIOPinRead(PUSHBTN1PORT,PUSHBTN1PIN);
    if (BtnState)
        BtnState = 1 ;
    if(!BtnState)
        BtnState = 0 ;
    return BtnState ;
}
