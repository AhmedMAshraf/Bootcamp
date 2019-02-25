/*
 * Schedular.c
 *
 * Created: 2/23/2019 2:07:34 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/Schedular.h"

uint8 volatile Flag = 0 ;


/*******************************************************************/
/* SchedulerInit_AndStart                                          */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Function that initalize Scheduler                               */
/*******************************************************************/
void SchedulerInit_AndStart(void)
{
	/* Init and start the timer */
	timer_init(OS_TICK_INTERVAL_MSEC);
	
	/* Set the call back fun to Set_Flag */
	Set_Call_Back(Set_Flag);
	
	/* For every interrupt call the pre_filled */
	while(1)
	{
		if(Flag == FLAG_SET)
		{
			Flag = 0 ;
			Pre_filled(TaskArray,NUM_OF_TASKS);
		}
	}
}

/*******************************************************************/
/* Set_Flag                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Function that Set The global tick flag                          */
/*******************************************************************/
void Set_Flag(void)
{
	Flag = FLAG_SET;
}

/*******************************************************************/
/* Pre_filled                                                      */
/* Parameters : TaskType ptr[] , uint8 size                        */
/* I/p : Array of tasks , size of array                            */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Function that Set The call back function to the next task       */
/*******************************************************************/
void Pre_filled(taskType ptr[] , uint8 Array_Size)
{
	/* Loop all the tasks and call them */
	uint8 i = 0 ;
	for(i ; i<Array_Size ; i++)
	{
		ptr[i]() ;
	}
}
