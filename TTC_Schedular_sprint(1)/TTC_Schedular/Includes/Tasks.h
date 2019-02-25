/*
 * Tasks.h
 *
 * Created: 2/23/2019 3:17:01 PM
 *  Author: AVE-LAP-062
 */ 


#ifndef TASKS_H_
#define TASKS_H_

#include "DIO.h"


#define NUM_OF_TASKS 4
typedef void (*taskType) (void) ;


void BlinkLed0 (void);
void BlinkLed1 (void);
void Blinkled2 (void);
void Blinkled3 (void);

extern taskType TaskArray[NUM_OF_TASKS];


#endif /* TASKS_H_ */