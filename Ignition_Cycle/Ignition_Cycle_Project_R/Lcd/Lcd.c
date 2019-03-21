/*
 * LCD.C
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-063
 */

#include "FreeRTOS.h"
#include "task.h"
#include "../queue.h"
#include"../Includes/Lcd.h"
#include"../Includes/MagicNumber.h"

extern QueueHandle_t xSPIRecv ;

uint8_t *Messages[6]={"IgnOff,"
                         "M Spd",
                         "Inc Spd",
                        "Dec Spd",
                        "Brake",
                        "FAB!"};

/*******************************************************************/
/* LCD_INIT                                                        */
/* Parameters :                                                    */
/* I/p : void                                                      */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Fn that init LCD                                                */
/*******************************************************************/
void LCD_INIT()
{
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    //
    // Check if the peripheral access is enabled.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA))
    {
    }
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
    vTaskDelay(4);
    LCD_Send_Command (CMND2_4BITMODE);
    vTaskDelay(4);
    LCD_Send_Command (CMND3_4BITMODE);
    vTaskDelay(4);
    LCD_Send_Command (CURSOR_ON);
    vTaskDelay(4);
    LCD_Send_Command (CLEAR_LCD);
    vTaskDelay(4);

}

/*******************************************************************/
/* LCD_Send_Command                                                */
/* Parameters :   uint8                                            */
/* I/p : cmd                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Fn that send cmd to lcd                                         */
/*******************************************************************/
void LCD_Send_Command (uint8_t cmd){

    GPIOPinWrite(PORT2_LCD, LCD_D4,Get_Bit(cmd,FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D5,Get_Bit(cmd,FIVE) );
    GPIOPinWrite(PORT2_LCD, LCD_D6,Get_Bit(cmd,SIX) );
    GPIOPinWrite(PORT2_LCD, LCD_D7,Get_Bit(cmd,SEVEN));
    GPIOPinWrite(PORT1_LCD, LCD_RS,0x0);
    GPIOPinWrite(PORT1_LCD, LCD_RW,0x0);
    GPIOPinWrite(PORT1_LCD, LCD_E,LCD_E);

    vTaskDelay(4);
    GPIOPinWrite(PORT1_LCD, LCD_E,0x0);
    vTaskDelay(4);

    GPIOPinWrite(PORT2_LCD, LCD_D4,((Get_Bit(cmd,ZERO))<<FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D5,((Get_Bit(cmd,ONE))<<FOUR  ));
    GPIOPinWrite(PORT2_LCD, LCD_D6,((Get_Bit(cmd,TWO)) <<FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D7,((Get_Bit(cmd,THREE))<<FOUR) );
    GPIOPinWrite(PORT1_LCD, LCD_E,LCD_E);
    vTaskDelay(4);

    GPIOPinWrite(PORT1_LCD, LCD_E,0x0);
    vTaskDelay(4);
}

/*******************************************************************/
/* LCD_Send_Data                                                   */
/* Parameters :   uint8                                            */
/* I/p : cmd                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Fn that send data to lcd                                        */
/*******************************************************************/
void LCD_Send_Data (uint8_t cmd){

    GPIOPinWrite(PORT2_LCD, LCD_D4,Get_Bit(cmd,FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D5,Get_Bit(cmd,FIVE) );
    GPIOPinWrite(PORT2_LCD, LCD_D6,Get_Bit(cmd,SIX) );
    GPIOPinWrite(PORT2_LCD, LCD_D7,Get_Bit(cmd,SEVEN));
    GPIOPinWrite(PORT1_LCD, LCD_RS,LCD_RS);
    GPIOPinWrite(PORT1_LCD, LCD_RW,0x0);
    GPIOPinWrite(PORT1_LCD, LCD_E,LCD_E);
    vTaskDelay(4);
    GPIOPinWrite(PORT1_LCD, LCD_E,0x0);
    vTaskDelay(4);
    GPIOPinWrite(PORT2_LCD, LCD_D4,((Get_Bit(cmd,ZERO))<<FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D5,((Get_Bit(cmd,ONE))<<FOUR  ));
    GPIOPinWrite(PORT2_LCD, LCD_D6,((Get_Bit(cmd,TWO)) <<FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D7,((Get_Bit(cmd,THREE))<<FOUR) );
    GPIOPinWrite(PORT1_LCD, LCD_E,LCD_E);
    vTaskDelay(4);
    GPIOPinWrite(PORT1_LCD, LCD_E,0x0);
    vTaskDelay(4);

}
/*******************************************************************/
/* LCD_Clear                                                       */
/* Parameters :void                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Fn that Clears LCD                                              */
/*******************************************************************/
void LCD_Clear(void)
{
    LCD_Send_Command(LCD_CMD_CLR);
}

/*******************************************************************/
/* LCD_diplayString                                                */
/* Parameters :pointer to char                                     */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Fn that display string on lcd                                   */
/*******************************************************************/
void LCD_diplayString(uint8_t *str)
{
    uint8_t n=0;
    while(str[n])
    {
        LCD_Send_Data(str[n]);
        n++;
        if (n==LCD_COLS)
        {
            LCD_Send_Command(LCD_CMD_INC_CURSOR);
        }
    }
}

/*******************************************************************/
/* LCD_gotoRowColumn                                               */
/* Parameters : uint8_t,uint8_t                                    */
/* I/p : row,col                                                   */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Fn that goto Row,Col specified                                  */
/*******************************************************************/
void LCD_gotoRowColumn(uint8_t row , uint8_t col)
{
    col--;
    if (row==1)
    {
        LCD_Send_Command(0x80+col);
    }
    if (row==2)
    {
        LCD_Send_Command(0xC0+col);
    }

}

/*******************************************************************/
/* LCD_sendString_RowCol                                           */
/* Parameters : uint8_t,uint8_t ,pointer to unit8                  */
/* I/p : row,col,message                                           */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Fn that goto Row,Col specified and print string                 */
/*******************************************************************/
void LCD_sendString_RowCol(uint8_t *str , uint8_t row , uint8_t col)
{
    LCD_gotoRowColumn(row,col);
    vTaskDelay(10);
    LCD_diplayString(str);
}

/*******************************************************************/
/* Lcd_Task                                                        */
/* Parameters : *pvParameters                                      */
/* I/p : row,col                                                   */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Display Task                                                    */
/*******************************************************************/
void Lcd_Task(void *pvParameters)
{
    LCD_INIT();
    uint32_t DataRecv = 0;
    uint8_t Row1 = 0 ;
    uint8_t Row2 = 0 ;
    double DistanceRecv;
    uint8_t RealDistance;

    LCD_gotoRowColumn(1,1);
    LCD_diplayString("State= ");

    LCD_gotoRowColumn(2,1);
    LCD_diplayString("Distance= ");

    while(1)
    {
        if(uxQueueMessagesWaiting(xSPIRecv))
       {
          xQueueReceive(xSPIRecv,&DataRecv,10);
          Row1 = DataRecv >> 5 ;
          Row2 = DataRecv & 0x1F ;
          LCD_gotoRowColumn(1,8);
          LCD_diplayString("         ");
          LCD_gotoRowColumn(1,8);
          switch(Row1)
          {
          case 0:
              LCD_diplayString("IgnOff");
              LCD_gotoRowColumn(2,11);
              DistanceRecv = ((double)Row2 * 8.5) ; /* back to Real Distance */
              RealDistance = (uint8_t)DistanceRecv;
              LCD_Send_Data((RealDistance/100) +48);
              LCD_Send_Data(((RealDistance/10)%10) +48);
              LCD_Send_Data((RealDistance%10) +48);
              break;
          case 1:
              LCD_diplayString("M Spd");
              LCD_gotoRowColumn(2,11);
              DistanceRecv = ((double)Row2 * 8.5) ; /* back to Real Distance */
              RealDistance = (uint8_t)DistanceRecv;
              LCD_Send_Data((RealDistance/100) +48);
              LCD_Send_Data(((RealDistance/10)%10) +48);
              LCD_Send_Data((RealDistance%10) +48);
              break;
          case 2:
              LCD_diplayString("Inc Spd");
              LCD_gotoRowColumn(2,11);
              DistanceRecv = ((double)Row2 * 8.5) ; /* back to Real Distance */
              RealDistance = (uint8_t)DistanceRecv;
              LCD_Send_Data((RealDistance/100) +48);
              LCD_Send_Data(((RealDistance/10)%10) +48);
              LCD_Send_Data((RealDistance%10) +48);
              break;
          case 3:
              LCD_diplayString("Dec Spd");
              LCD_gotoRowColumn(2,11);
              DistanceRecv = ((double)Row2 * 8.5) ; /* back to Real Distance */
              RealDistance = (uint8_t)DistanceRecv;
              LCD_Send_Data((RealDistance/100) +48);
              LCD_Send_Data(((RealDistance/10)%10) +48);
              LCD_Send_Data((RealDistance%10) +48);
              break;
          case 4:
              LCD_diplayString("Brake");
              LCD_gotoRowColumn(2,11);
              DistanceRecv = ((double)Row2 * 8.5) ; /* back to Real Distance */
              RealDistance = (uint8_t)DistanceRecv;
              LCD_Send_Data((RealDistance/100) +48);
              LCD_Send_Data(((RealDistance/10)%10) +48);
              LCD_Send_Data((RealDistance%10) +48);
              break;
          case 5:
              LCD_diplayString("FAB!");
              LCD_gotoRowColumn(2,11);
              LCD_diplayString("   ");

              break;
          case 6:
              LCD_diplayString("Sys On");
              LCD_gotoRowColumn(2,11);
              DistanceRecv = ((double)Row2 * 8.5) ; /* back to Real Distance */
              RealDistance = (uint8_t)DistanceRecv;
              LCD_Send_Data((RealDistance/100) +48);
              LCD_Send_Data(((RealDistance/10)%10) +48);
              LCD_Send_Data((RealDistance%10) +48);
              break;
          }


       }
        vTaskDelay(100);
    }
}
