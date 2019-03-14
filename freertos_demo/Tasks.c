//*****************************************************************************
//
// led_task.c - A simple flashing LED task.
//
// Copyright (c) 2012-2017 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.4.178 of the EK-TM4C123GXL Firmware Package.
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include <Tasks.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "drivers/rgb.h"
#include "drivers/buttons.h"
#include "utils/uartstdio.h"
#include "priorities.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "driverlib/sysctl.h"
#include "driverlib/debug.h"
#include "Leds.h"
#include "Btn.h"
#include "Buzzer.h"
#include "Lcd.h"

//*****************************************************************************
//
// The stack size for the LED toggle task.
//
//*****************************************************************************
#define LEDTASKSTACKSIZE        128         // Stack size in words

//*****************************************************************************
//
// The item size and queue size for the LED message queue.
//
//*****************************************************************************
#define LED_ITEM_SIZE           sizeof(uint8_t)
#define LED_QUEUE_SIZE          5

//*****************************************************************************
//
// Default LED toggle delay value. LED toggling frequency is twice this number.
//
//*****************************************************************************
#define LED_TOGGLE_DELAY        250

//*****************************************************************************
//
// The queue that holds messages sent to the LED task.
//
//*****************************************************************************
xQueueHandle g_pLEDQueue;

//
// [G, R, B] range is 0 to 0xFFFF per color.
//

extern xSemaphoreHandle g_pUARTSemaphore;

//*****************************************************************************
//
// Initializes the LED task.
//
//*****************************************************************************
uint16_t Led1_Periodicity = 100 ;
uint16_t Led2_Periodicity = 200 ;
uint16_t Led3_Periodicity = 1000 ;
uint16_t Buzzer_Periodicity = 10 ;
uint16_t Lcd_Periodicity = 1000;
uint8_t Leds_DIS = 0 ;
uint8_t *Messages[10] = {"Test1","Test2","Test3","Test4","Test5","Test6","Test7","Test8","Test9","Test10"};
void TaskInit(void *pvParameters)
{
    while(1)
    {
        Leds_Init();
        //Btns_Init();
        Buzzer_Init();
        LCD_INIT();
        vTaskSuspend(NULL);
     }

}

void LED1Task(void *pvParameters)
{
    while(1)
    {
       if(Leds_DIS == 1)
       {
         GPIOPinWrite(LED1PORT, LED1PIN,LED1_LOW);
       }
       else
       {
          Led1_Blink();
       }
       vTaskDelay(Led1_Periodicity);
    }
}
void LED2Task(void *pvParameters)
{
    while(1)
    {
        if(Leds_DIS == 1)
        {
            GPIOPinWrite(LED2PORT, LED2PIN,LED2_LOW);
        }
        else
        {
            Led2_Blink();
        }
        vTaskDelay(Led2_Periodicity);
    }
}
void LED3Task(void *pvParameters)
{
    while(1)
    {
        if(Leds_DIS == 1)
        {
            GPIOPinWrite(LED3PORT, LED3PIN,LED3_LOW);
        }
        else
        {
            Led3_Blink();
        }
        vTaskDelay(Led3_Periodicity);
    }
}
extern void BtnTask(void *pvParameters)
{
    uint8_t Btn = 0 , BtnPrev = 0 ;
    uint32_t BtnCount = 0 ;
    while(1)
    {
       Btn = Btn1_Read();
       if(Btn == 1)
       {
           BtnCount ++ ;
       }
       BtnPrev = Btn ;

       if(BtnPrev == 1 && BtnCount >= 500)
       {
           Led1_Periodicity += 100 ;
           Led2_Periodicity += 100 ;
           Led3_Periodicity += 100 ;
       }


       if(Btn == 0)
       {
           BtnCount = 0 ;
       }
       vTaskDelay(1);
    }
}
extern void BuzzerTask(void *pvParameters)
{
    while(1)
    {
        Buzzer_Toggle();
        vTaskDelay(Buzzer_Periodicity);
    }
}
extern void LcdTask(void *pvParameters)
{
    while(1)
    {
        LCD_Send_Data('D');

        vTaskDelay(Lcd_Periodicity);
    }
}
