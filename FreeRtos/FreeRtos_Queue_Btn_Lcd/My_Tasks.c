/*
 * My_Tasks.c
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-062
 */

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "driverlib/sysctl.h"
#include "driverlib/debug.h"
#include "Btn.h"
#include "Lcd.h"
#include "My_Tasks.h"

#define BTN1_ID 1
#define BTN2_ID 2


QueueHandle_t xBtnQueue ;

static uint8_t BtnTaskPeriodicity = 25 ;
static uint32_t Lcd_Periodicity = 50 ;


uint8_t *Messages[2] = {"Count1 : ","Count2 : "};

/*******************************************************************/
/* TaskInit                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/a                                                    */
/* Task that init modules                                          */
/*******************************************************************/
void TaskInit(void *pvParameters)
{
    while(1)
    {
        LCD_INIT();
        Btns_Init();
        /*create the Queue. */

        vTaskSuspend(NULL);
     }
}

/*******************************************************************/
/* Btn1_Task                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/a                                                    */
/* Task that read btn1                                             */
/*******************************************************************/
void Btn1_Task(void *pvParameters)
{

    uint8_t Btn1_State=0 , Btn1_State_Prev = 0 ;
    LCD_INIT();
    uint8_t count = 1 ;
    while(1)
    {

        /* Read falling edge of BTN1 */
        Btn1_State = Btn1_Read();
        if(!Btn1_State && Btn1_State_Prev)
        {
            /* Send the message to the queue, waiting for 10 ticks for space to become
            available if the queue is already full. */
            xQueueSendToBack( xBtnQueue, &count , 10 );
        }
        Btn1_State_Prev = Btn1_State;

        vTaskDelay(BtnTaskPeriodicity);
    }

}

/*******************************************************************/
/* Btn2_Task                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/a                                                    */
/* Task that read btn2                                             */
/*******************************************************************/
void Btn2_Task(void *pvParameters)
{
    uint32_t Btn2_State=0 , Btn2_State_Prev = 0;
    LCD_INIT();
    uint8_t count = 2 ;
    while(1)
    {
        /* Read falling edge BTN2 */
        Btn2_State = Btn2_Read();
        if(!Btn2_State && Btn2_State_Prev)
        {
            /* Send the message to the queue, waiting for 10 ticks for space to become
            available if the queue is already full. */
            xQueueSendToBack( xBtnQueue, &count , 10 );
        }
        Btn2_State_Prev = Btn2_State ;

        vTaskDelay(BtnTaskPeriodicity);
    }
}

/*******************************************************************/
/* Lcd_Task                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/a                                                    */
/* Task that writes on lcd                                         */
/*******************************************************************/
void Lcd_Task(void *pvParameters)
{
    uint8_t data_recv = 0 ;
    uint8_t count1 = 0 , count2 = 0 ;
    LCD_INIT();
    LCD_sendString_RowCol(Messages[0], 1, 1);
    LCD_sendString_RowCol(Messages[1], 2, 1);

    while(1)
    {

        if( xQueueReceive( xBtnQueue, &data_recv, 10 ) != pdPASS )
        {
            /* Nothing was received from the queue – even after blocking to wait
            for data to arrive. */
            //LCD_Send_Data('a');
        }
        else
        {
            /* xMessage now contains the received data. */
            if(data_recv == 1)
            {
                LCD_gotoRowColumn(1,9);
                count1 ++ ;
                if(count1>9)
                {
                  LCD_Send_Data(count1/10 + 48);
                  LCD_Send_Data(count1%10 + 48);
                }
                else if(count1>99)
                {
                    LCD_Send_Data(count1/100 + 48);
                    LCD_Send_Data(count1/10 + 48);
                    LCD_Send_Data(count1%10 + 48);
                }
                else
                {
                    LCD_Send_Data(count1 + 48);
                }

            }
            else if(data_recv == 2)
            {
                LCD_gotoRowColumn(2,9);
                count2 ++ ;
                if(count2>9)
                {
                  LCD_Send_Data(count2/10 + 48);
                  LCD_Send_Data(count2%10 + 48);
                }
                else if(count2>99)
                {
                    LCD_Send_Data(count2/100 + 48);
                    LCD_Send_Data(count2/10 + 48);
                    LCD_Send_Data(count2%10 + 48);
                }
                else
                {
                    LCD_Send_Data(count2 + 48);
                }
            }
            else
            {

            }
        }

        vTaskDelay(Lcd_Periodicity);
    }
}
