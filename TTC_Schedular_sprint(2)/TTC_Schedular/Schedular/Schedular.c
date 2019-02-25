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


/**************************************************/
/* SchedulerInit                                  */
/* Parameters : N/A                               */
/* I/p : N/A                                      */
/* O/p : N/A                                      */
/* Return : void                                  */
/* Function that initalize Scheduler              */
/**************************************************/
void SchedulerInit (void)
{
	Set_Call_Back(Set_Flag);
}


/**************************************************/
/* SchedulerStart                                 */
/* Parameters : N/A                               */
/* I/p : N/A                                      */
/* O/p : N/A                                      */
/* Return : void                                  */
/* Function that Starts Scheduler                 */
/**************************************************/
void SchedulerStart(void)
{
	/*Sort Tasks*/
	SchedularSortTasks();
	/* Init and start the timer */
	timer_init(OS_TICK_INTERVAL_MSEC);
	
	/* For every interupt tick (1ms) call the pre_filled func */
	while(1)
	{
		if(Flag == FLAG_SET)
		{
			Flag = 0 ;
			Pre_filled(TaskArray,No_Of_Elements);
		}
	}
}

/**************************************************/
/* Set_Flag                                       */
/* Parameters : N/A                               */
/* I/p : N/A                                      */
/* O/p : N/A                                      */
/* Return : void                                  */
/* Function that Set The global tick flag         */
/**************************************************/
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
void Pre_filled(vtask ptr[] , uint8 Array_Size)
{
	/* Loop the whole tasks array */
	uint8 i = 0 ;
	for(i ; i<Array_Size ; i++)
	{
		/* Check if the task RTP has passed if not dec. by 1 */
		ptr[i].RunTimeProcessing -- ;
		if(ptr[i].RunTimeProcessing == 0)
		{
			/* Call the task func. */
			ptr[i].TaskPtr();
			ptr[i].RunTimeProcessing = ptr[i].TaskPeriodicity;	
		}
	}
}

/*******************************************************************/
/* scheduler_Add_Struct                                            */
/* Parameters : vtask StructToAdd                                  */
/* I/p : Array of structs (Tasks)                                  */
/* O/p : 1 if added succefully 0 if not                                                      */
/* Return : uint8                                                  */
/* Function that add a new task to the list                        */
/*******************************************************************/
uint8 scheduler_Add_Struct(vtask StructToAdd)
{
	/* Check if the list is full */
	uint8 ReturnCondition = 0 ;
	if(No_Of_Elements < NUM_OF_TASKS)
	{
		/* Add the passed struct the list and inc. the index */
		TaskArray[No_Of_Elements] = StructToAdd ;
		No_Of_Elements ++ ;
		ReturnCondition = 1 ;
	}
	else
		ReturnCondition = 0 ;
	return ReturnCondition ;
}		


/*******************************************************************/
/* SchedularSortTasks                                              */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/A                                                    */
/* Function that sort the tasks according to priority              */
/*******************************************************************/
void SchedularSortTasks(void)
{
	uint8 i , j  ;
	vtask TempStruct ;
	for (i=0; i < No_Of_Elements; ++i)
	{
		for (j = i+1; j < No_Of_Elements; ++j)
		{
			if (TaskArray[i].Priority > TaskArray[j].Priority)
			{				
				TempStruct =  TaskArray[i];
				TaskArray[i] = TaskArray[j];
				TaskArray[j] = TempStruct;
			}	
		}
	}
}
