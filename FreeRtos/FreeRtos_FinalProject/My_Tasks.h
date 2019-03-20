/*
 * My_Tasks.h
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-062
 */

#ifndef MY_TASKS_H_
#define MY_TASKS_H_

extern void TaskInit(void *pvParameters);
extern void Btn1_Task(void *pvParameters);
extern void Btn2_Task(void *pvParameters);
extern void Lcd_Task(void *pvParameters);
extern void Keypad_Task(void *pvParameters);
extern void UartSend_Task(void *pvParameters);
extern void UartRecv_Task(void *pvParameters);

extern QueueHandle_t xKeypadQueue ;
extern QueueHandle_t xUartSend ;
extern QueueHandle_t xUartRecv ;
extern EventGroupHandle_t xBtnEventGroup;



#endif /* MY_TASKS_H_ */
