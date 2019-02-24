/*
 * Schedular.c
 *
 * Created: 2/23/2019 2:07:34 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/Schedular.h"

/*Flag to be set every OS_TICK*/
uint8 volatile Flag = 0 ;


/* Number of current elements */
volatile uint8 No_Of_Elements = 0 ;


/*Initalize the TaskArray used by schedular*/
vtask TaskArray[NUM_OF_TASKS] ;

/* SchedulerInit */
/* Parameters : N/A */
/* I/p : N/A */
/* O/p : N/A */
/* Return : void */
/* Function that initalize Scheduler */
void SchedulerInit (void)
{
	Set_Call_Back(Set_Flag);
}

/* SchedulerStart */
/* Parameters : N/A */
/* I/p : N/A */
/* O/p : N/A */
/* Return : void */
/* Function that Starts Scheduler */
void SchedulerStart(void)
{
	timer_init(OS_TICK_INTERVAL_MSEC);
	while(1)
	{
		if(Flag == FLAG_SET)
		{
			Flag = 0 ;
			Pre_filled(TaskArray,No_Of_Elements);
		}
	}
}

/* Set_Flag */
/* Parameters : N/A */
/* I/p : N/A */
/* O/p : N/A */
/* Return : void */
/* Function that Set The global tick flag */
void Set_Flag(void)
{
	Flag = FLAG_SET;
}


/* Pre_filled */
/* Parameters : TaskType ptr[] , uint8 size */
/* I/p : Array of tasks , size of array */
/* O/p : N/A */
/* Return : void */
/* Function that Set The call back function to the next task */
void Pre_filled(vtask ptr[] , uint8 Array_Size)
{
	uint8 i = 0 ;
	for(i ; i<Array_Size ; i++)
	{
		ptr[i].RunTimeProcessing -- ;
		if(ptr[i].RunTimeProcessing == 0)
		{
			ptr[i].TaskPtr();
			ptr[i].RunTimeProcessing = ptr[i].TaskPeriodicity;	
		}
	}
}

uint8 scheduler_Add_Struct(vtask StructToAdd)
{
	uint8 ReturnCondition = 0 ;
	if(No_Of_Elements < NUM_OF_TASKS)
	{
		TaskArray[No_Of_Elements] = StructToAdd ;
		No_Of_Elements ++ ;
		ReturnCondition =1 ;
	}
	else
		ReturnCondition = 0 ;
	return ReturnCondition ;
}		
