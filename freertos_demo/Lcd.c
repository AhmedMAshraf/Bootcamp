/*
 * LCD.C
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-063
 */
#include"Lcd.h"
#include"MagicNumber.h"

void LCD_INIT()
{

    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    //
    // Check if the peripheral access is enabled.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA))
    {
    }
    //
      // Enable the GPIO port that is used for the on-board LED.
      //
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
      //
      // Check if the peripheral access is enabled.
      //
      while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC))
      {
      }
    //
    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIOPinTypeGPIOOutput(PORT1_LCD,LCD_RS|LCD_RW|LCD_E);
    GPIOPinTypeGPIOOutput(PORT2_LCD,LCD_D4|LCD_D5|LCD_D6|LCD_D7);

    LCD_Send_Command (CMND1_4BITMODE);
    SysCtlDelay(200000);
    LCD_Send_Command (CMND2_4BITMODE);
            SysCtlDelay(200000);
            LCD_Send_Command (CMND3_4BITMODE);
            SysCtlDelay(200000);
            LCD_Send_Command (CURSOR_ON);
            SysCtlDelay(200000);
            LCD_Send_Command (CLEAR_LCD);
            SysCtlDelay(200000);
            LCD_Send_Data ('2');

    //

    // Loop forever.
    //

}


void LCD_Send_Command (uint8_t cmd){
    uint8_t J=((Get_Bit(cmd,THREE))) ;

    uint8_t i=((Get_Bit(cmd,THREE))<<SEVEN) ;
    GPIOPinWrite(PORT2_LCD, LCD_D4,Get_Bit(cmd,FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D5,Get_Bit(cmd,FIVE) );
    GPIOPinWrite(PORT2_LCD, LCD_D6,Get_Bit(cmd,SIX) );
    GPIOPinWrite(PORT2_LCD, LCD_D7,Get_Bit(cmd,SEVEN));
    GPIOPinWrite(PORT1_LCD, LCD_RS,0x0);
    GPIOPinWrite(PORT1_LCD, LCD_RW,0x0);
    GPIOPinWrite(PORT1_LCD, LCD_E,LCD_E);
    SysCtlDelay(20000/3);
    GPIOPinWrite(PORT1_LCD, LCD_E,0x0);
    SysCtlDelay(20000/3);

    GPIOPinWrite(PORT2_LCD, LCD_D4,((Get_Bit(cmd,ZERO))<<FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D5,((Get_Bit(cmd,ONE))<<FOUR  ));
    GPIOPinWrite(PORT2_LCD, LCD_D6,((Get_Bit(cmd,TWO)) <<FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D7,((Get_Bit(cmd,THREE))<<FOUR) );
    GPIOPinWrite(PORT1_LCD, LCD_E,LCD_E);
    SysCtlDelay(20000/3);
    GPIOPinWrite(PORT1_LCD, LCD_E,0x0);
    SysCtlDelay(20000/3);
}
void LCD_Send_Data (uint8_t cmd){

    GPIOPinWrite(PORT2_LCD, LCD_D4,Get_Bit(cmd,FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D5,Get_Bit(cmd,FIVE) );
    GPIOPinWrite(PORT2_LCD, LCD_D6,Get_Bit(cmd,SIX) );
    GPIOPinWrite(PORT2_LCD, LCD_D7,Get_Bit(cmd,SEVEN));
    GPIOPinWrite(PORT1_LCD, LCD_RS,LCD_RS);
    GPIOPinWrite(PORT1_LCD, LCD_RW,0x0);
    GPIOPinWrite(PORT1_LCD, LCD_E,LCD_E);
    SysCtlDelay(20000);
    GPIOPinWrite(PORT1_LCD, LCD_E,0x0);
    SysCtlDelay(20000);

    GPIOPinWrite(PORT2_LCD, LCD_D4,((Get_Bit(cmd,ZERO))<<FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D5,((Get_Bit(cmd,ONE))<<FOUR  ));
    GPIOPinWrite(PORT2_LCD, LCD_D6,((Get_Bit(cmd,TWO)) <<FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D7,((Get_Bit(cmd,THREE))<<FOUR) );
    GPIOPinWrite(PORT1_LCD, LCD_E,LCD_E);
    SysCtlDelay(20000);
    GPIOPinWrite(PORT1_LCD, LCD_E,0x0);
    SysCtlDelay(20000);
}
