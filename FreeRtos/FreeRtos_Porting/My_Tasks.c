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
#include "driverlib/sysctl.h"
#include "driverlib/debug.h"
#include "Leds.h"
#include "Btn.h"

static uint8_t SBtnState = 0 ;
static uint8_t LedTaskPeriodicity = 100 ;
static uint8_t BtnTaskPeriodicity = 100 ;

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
        Leds_Init();
        Btns_Init();
        vTaskSuspend(NULL);

     }
}

/*******************************************************************/
/* Led_Task                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/a                                                    */
/* Task that switch leds                                           */
/*******************************************************************/
void Led_Task(void *pvParameters)
{
    while(1)
    {
        if(SBtnState == 1)
        {
            Led1_Switch(LED1_ON);
        }
        else if(SBtnState == BTN1_OFF)
        {
            Led1_Switch(LED1_OFF);
        }
        //Led1_Switch(LED1_ON);
        vTaskDelay(LedTaskPeriodicity);
    }
}

/*******************************************************************/
/* Btn_Task                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/a                                                    */
/* Task that read btn1                                             */
/*******************************************************************/
void Btn1_Task(void *pvParameters)
{
    while(1)
    {
        uint32_t Btn1_State ;
        /* Read BTN1 */
        Btn1_State = Btn1_Read();

        if(Btn1_State == BTN1_ON){
            SBtnState = BTN1_ON ;
        }

        else if(Btn1_State == BTN1_OFF){
            SBtnState = BTN1_OFF ;
        }
        vTaskDelay(BtnTaskPeriodicity);
    }

}
