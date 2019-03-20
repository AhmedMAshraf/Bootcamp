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
extern QueueHandle_t xBtnQueue ;

/*typedef struct {
    uint8_t Id ;
    uint8_t Count ;
}Btn_Struct;*/


#endif /* MY_TASKS_H_ */
