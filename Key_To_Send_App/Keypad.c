/*
 * Keypad.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-062
 */

#include "Keypad.h"



/*******************************************************************/
/* Keypad_Init                                                     */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Function that initalize Keypad                                  */
/*******************************************************************/
void Keypad_Init(void)
{
    /* Set ROWS and Cols Pins off keypad peripheral clock (PORT A,D,B) */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));

    /* Set Cols pins to O/P */
    GPIOPinTypeGPIOOutput(KEYPADCOL1PORT, KEYPADCOL1PIN);
    GPIOPinTypeGPIOOutput(KEYPADCOL2PORT, KEYPADCOL2PIN);
    GPIOPinTypeGPIOOutput(KEYPADCOL3PORT, KEYPADCOL3PIN);


    /* Set Rows To I/p */
    GPIOPinTypeGPIOInput(KEYPADROW1PORT, KEYPADROW1PIN);
    GPIOPinTypeGPIOInput(KEYPADROW2PORT, KEYPADROW2PIN);
    GPIOPinTypeGPIOInput(KEYPADROW3PORT, KEYPADROW3PIN);

    /* Set Internal Pull Ups */
    GPIOPadConfigSet(KEYPADROW1PORT,KEYPADROW1PIN,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
    GPIOPadConfigSet(KEYPADROW2PORT,KEYPADROW2PIN,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
    GPIOPadConfigSet(KEYPADROW3PORT,KEYPADROW3PIN,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);




}


/*******************************************************************/
/* Keypad_getPressedKey                                            */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : uint8_t                                                */
/* Function that detect the key pressed by user on keypad          */
/*******************************************************************/
uint8_t Keypad_GetPressedKey(void)
{
    uint8_t key=0;
    /* Set Column 1 */
    GPIOPinWrite(KEYPADCOL1PORT, KEYPADCOL1PIN,LOW);
    GPIOPinWrite(KEYPADCOL2PORT, KEYPADCOL2PIN,KEYPADCOL2PIN);
    GPIOPinWrite(KEYPADCOL3PORT, KEYPADCOL3PIN,KEYPADCOL3PIN);

    if(!GPIOPinRead(KEYPADROW1PORT,KEYPADROW1PIN))
    {
       key = 1 ;
       return key ;
    }
    else if(!GPIOPinRead(KEYPADROW2PORT,KEYPADROW2PIN))
    {
       key = 4 ;
       return key ;
    }
    else if(!GPIOPinRead(KEYPADROW3PORT,KEYPADROW3PIN))
    {
        key = 7 ;
        return key ;
    }

    /* Set Column 2 */
    GPIOPinWrite(KEYPADCOL1PORT, KEYPADCOL1PIN,KEYPADCOL1PIN);
    GPIOPinWrite(KEYPADCOL2PORT, KEYPADCOL2PIN,LOW);
    GPIOPinWrite(KEYPADCOL3PORT, KEYPADCOL3PIN,KEYPADCOL3PIN);

   if(!GPIOPinRead(KEYPADROW1PORT,KEYPADROW1PIN))
   {
      key = 2 ;
      return key ;
    }
   else if(!GPIOPinRead(KEYPADROW2PORT,KEYPADROW2PIN))
   {
      key = 5 ;
      return key ;
   }
   else if(!GPIOPinRead(KEYPADROW3PORT,KEYPADROW3PIN))
   {
      key = 8 ;
      return key ;
   }

   /* Set Column 3 */
   GPIOPinWrite(KEYPADCOL1PORT, KEYPADCOL1PIN,KEYPADCOL1PIN);
   GPIOPinWrite(KEYPADCOL2PORT, KEYPADCOL2PIN,KEYPADCOL2PIN);
   GPIOPinWrite(KEYPADCOL3PORT, KEYPADCOL3PIN,LOW);

  if(!GPIOPinRead(KEYPADROW1PORT,KEYPADROW1PIN))
  {
       key = 3 ;
       return key ;
  }
  else if(!GPIOPinRead(KEYPADROW2PORT,KEYPADROW2PIN))
  {
      key = 6 ;
      return key ;
  }
  else if(!GPIOPinRead(KEYPADROW3PORT,KEYPADROW3PIN))
  {
      key = 9 ;
      return key ;
  }


  return key ;
}

