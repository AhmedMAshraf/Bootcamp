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
#include "Keypad.h"
#include "UART.h"
#include "My_Tasks.h"

#define BIT_0   ( 1 << 0 )
#define BIT_1   ( 1 << 1)
#define BIT_4   ( 1 << 4 )

QueueHandle_t xKeypadQueue ;
QueueHandle_t xUartSend ;
QueueHandle_t xUartRecv ;
EventGroupHandle_t xBtnEventGroup;

static uint8_t BtnTaskPeriodicity = 25 ;
static uint32_t Lcd_Periodicity = 50 ;
static uint32_t Keypad_Periodicity = 25 ;
static uint32_t Uart_Periodicity = 10 ;

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
        Keypad_Init();
        Btns_Init();
        UART0_init();
        /*create the Queue. */

        vTaskSuspend(NULL);
     }
}


/*******************************************************************/
/* Keypad_Task                                                     */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/a                                                    */
/* Keypad Task                                                     */
/*******************************************************************/
void Keypad_Task(void *pvParameters)
{
    uint8_t Key=0 , Key_Prev = 0 ;
    LCD_INIT();
    uint8_t count = 1 ;
    while(1)
    {

     /* Read falling edge of BTN1 */
     Key = Keypad_GetPressedKey();
     if(Key && Key_Prev == 0)
     {
        /* Send the message to the queue, waiting for 10 ticks for space to become
        available if the queue is already full. */
         count = Key ;
        xQueueSendToBack(xKeypadQueue, &count , 10 );
        xQueueSendToBack(xUartSend, &count , 10 );
     }
     Key_Prev = Key;

     vTaskDelay(Keypad_Periodicity);
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
    while(1)
    {
        /* Read falling edge of BTN1 */
        Btn1_State = Btn1_Read();
        if(!Btn1_State && Btn1_State_Prev)
        {
            /* Send the message to the queue, waiting for 10 ticks for space to become
            available if the queue is already full. */
            xEventGroupSetBits(xBtnEventGroup, BIT_4);
        }
        Btn1_State_Prev = Btn1_State;

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
    EventBits_t uxBits;
    const TickType_t xTicksToWait = 100 / portTICK_PERIOD_MS;

    static uint8_t j = 1 ;

    LCD_INIT();

    while(1)
    {
        uint8_t data=0 ;
        uint8_t data_recv = 0 ;
        uint8_t col = 0 ;
        uint8_t i = 0 ;


        /* Recv Sender data */
        xQueueReceive(xKeypadQueue,&data,10);

        /* Recv Reciever data */

        while(i < uxQueueMessagesWaiting(xUartRecv))
        {
           xQueueReceive(xUartRecv,&data_recv,10);
           LCD_gotoRowColumn(2,1+col);
           LCD_Send_Data(data_recv+48);
           col++;
         }

        if(data)
        {
            LCD_gotoRowColumn(1,j);
            LCD_Send_Data(data+48);
            j++;
        }
        /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
                the event group.  Clear the bits before exiting. */
        uxBits = xEventGroupWaitBits(
                                  xBtnEventGroup,   /* The event group being tested. */
                                  BIT_0 | BIT_4, /* The bits within the event group to wait for. */
                                  pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
                                  pdFALSE,       /* Don't wait for both bits, either bit will do. */
                                  xTicksToWait );/* Wait a maximum of 100ms for either bit to be set. */

        if( ( uxBits & BIT_0 ) != 0 && (uxBits & BIT_4) == 0)
        {
        }
        else if( ( uxBits & BIT_1 ) != 0 )
        {
            j=0;
            //vTaskDelay(2000);
            LCD_gotoRowColumn(1,1);
           LCD_diplayString("              ");
        }
        else
        {
        }
        vTaskDelay(Lcd_Periodicity);
    }
}

/*******************************************************************/
/* UartSend_Task                                                 */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* task that send data on UART0                                    */
/*******************************************************************/
void UartSend_Task(void *pvParameters)
{
    EventBits_t uxBits;
    const TickType_t xTicksToWait = 100 / portTICK_PERIOD_MS;

    while(1)
    {
        uint8_t data = 0 ;
        uint8_t i = 0 ;
        /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
                the event group.  Clear the bits before exiting. */
        uxBits = xEventGroupWaitBits(
                                  xBtnEventGroup,   /* The event group being tested. */
                                  BIT_0 | BIT_4, /* The bits within the event group to wait for. */
                                  pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
                                  pdFALSE,       /* Don't wait for both bits, either bit will do. */
                                  xTicksToWait );/* Wait a maximum of 100ms for either bit to be set. */

        if( ( uxBits & BIT_0 ) != 0 && (uxBits & BIT_4) == 0)
        {
        }
        else if( ( uxBits & BIT_4 ) != 0 )
        {
           while(i < uxQueueMessagesWaiting(xUartSend))
           {
               xQueueReceive(xUartSend,&data,10);
               UART0_Send(data);
           }
           xEventGroupSetBits(xBtnEventGroup, BIT_1);
        }
        else
        {}
        vTaskDelay(Uart_Periodicity);
    }
}

/*******************************************************************/
/* UartRecv_Task                                                   */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* task that recv data on UART0                                    */
/*******************************************************************/
void UartRecv_Task(void *pvParameters)
{
    LCD_INIT();
    while(1)
    {
        uint8_t data = 0 ;
        data = UART0_Recv();
        if(data)
        {
            xQueueSendToBack(xUartRecv, &data , 10 );
        }
        vTaskDelay(Uart_Periodicity);
    }
}
