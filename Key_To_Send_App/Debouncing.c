/*
 * Debouncing.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-062
 */
#include "Debouncing.h"
#include "Keypad.h"


uint32_t Debounce_Flag = 0 ;

/*******************************************************************/
/* Debounce_Task                                                   */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* task that detect the debouncing of the keypad buttons           */
/*******************************************************************/
void Debounce_Task(void)
{
    volatile static uint32_t status = 0;
    status = Keypad_GetPressedKey();
    if(status==1 || status==2 || status==3 || status==4 || status==5 || status==6 || status==7 || status==8 || status==9)
    {
        Debounce_Flag ++ ;
    }
    else
    {
        Debounce_Flag = 0 ;
    }
 }
