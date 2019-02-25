/*
 * Schedular.h
 *
 * Created: 2/23/2019 2:07:52 PM
 *  Author: AVE-LAP-062
 */ 


#ifndef SCHEDULAR_H_
#define SCHEDULAR_H_

#include "timer.h"
#include "Tasks.h"


void SchedulerInit_AndStart(void);
void Pre_filled(taskType ptr[], uint8 Array_Size);
void Set_Flag(void);
extern volatile uint8 Flag ;



#endif /* SCHEDULAR_H_ */