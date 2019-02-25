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

typedef struct
{
	void (*TaskPtr)(void);
	uint16 TaskPeriodicity ;
	uint16 RunTimeProcessing;
	uint8 Priority ;
}vtask;


void SchedulerInit (void);
void SchedulerStart (void);
void Pre_filled(vtask ptr[] , uint8 Array_Size);
void Set_Flag(void);
uint8 scheduler_Add_Struct(vtask StructToAdd);


extern volatile uint8 Flag ;
extern volatile uint8 No_Of_Elements ;
extern vtask TaskArray[NUM_OF_TASKS] ;



#endif /* SCHEDULAR_H_ */