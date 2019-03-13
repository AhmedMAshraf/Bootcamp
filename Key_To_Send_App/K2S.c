/*
 * K2S.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-062
 */

#include "K2S.h"

/****************************************************************************************/
/* K2S_Task                                                                             */
/* Parameters : N/A                                                                     */
/* I/p : N/A                                                                            */
/* O/p : N/A                                                                            */
/* Return : void                                                                        */
/* Function that is called by the schedular and get the data to send from keypad to uart*/
/****************************************************************************************/
void K2S_Task(void)
{

    if(Debounce_Flag >= 5)
    {
        DataToSend = Keypad_GetPressedKey();
        UART_Flag = 1 ;
    }
}
