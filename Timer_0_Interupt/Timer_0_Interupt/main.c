/*
 * Timer_0_Interupt.c
 *
 * Created: 2/20/2019 4:49:23 PM
 * Author : AVE-LAP-062
 */ 

#include "Includes/DIO.h"
#include "Includes/timer.h"
#define GO 0
#define STOP 1
#define GET_READY 2

extern uint16 Timer_0_Flag ;
extern uint8 Ext_Int_2_Flag ;

int main(void)
{
    /* Replace with your application code */
	timer_init();
	/* Initialize External interupt */
	Set_Bit(MCUCSR,ISC2);
	Set_Bit(GICR,INT2);
	
	
	uint8 State = GO ;
	
	DIO_SetPinDirection(PINB5,HIGH); /*Set DDRB5 (LED1) Output*/
	DIO_SetPinDirection(PINB6,HIGH); /*Set DDRB6 (LED2) Output*/
	DIO_SetPinDirection(PINB7,HIGH); /*Set DDRB7 (LED3) Output*/
	DIO_SetPinDirection(PINB2,LOW); /*Set DDRB2 (BTN1) Input*/
	
	DIO_WritePin(PINB5,LOW); /*Led is off*/
	DIO_WritePin(PINB6,LOW); /*Led is off*/
	DIO_WritePin(PINB7,LOW); /*Led is off*/
	
    while (1) 
    {
		switch (State)
		{
			case GO :
			DIO_WritePin(PINB5,HIGH); /*GO State*/
			DIO_WritePin(PINB6,LOW);
			DIO_WritePin(PINB7,LOW);

			if(Ext_Int_2_Flag==1)
			{
				State = STOP ;
				Ext_Int_2_Flag=0;
				Timer_0_Flag = 0 ;
				break ;
			}
			if(Timer_0_Flag >= ONE_SECOND)
			{
				Timer_0_Flag = 0 ;
				State = STOP ;
			}
			break;
			
			case STOP :
			DIO_WritePin(PINB5,LOW); /*Stop State*/
			DIO_WritePin(PINB6,LOW);
			DIO_WritePin(PINB7,HIGH);
			
			if(Ext_Int_2_Flag==1)
			{
				State = STOP ;
				Ext_Int_2_Flag=0;
				Timer_0_Flag = 0 ;
				break ;
			}
			if(Timer_0_Flag >= ONE_SECOND)
			{
				Timer_0_Flag = 0 ;
				State = GET_READY ;
			}
			break;
			
			case GET_READY :
			DIO_WritePin(PINB5,LOW); 
			DIO_WritePin(PINB6,HIGH);
			DIO_WritePin(PINB7,LOW);
			if(Ext_Int_2_Flag==1)
			{
				State = STOP ;
				Ext_Int_2_Flag=0;
				Timer_0_Flag = 0 ;
				break ;
			}
			if(Timer_0_Flag >= ONE_SECOND)
			{
				Timer_0_Flag = 0 ;
				State = GO ;
			}
			break;
			default :
				State = GO ;
				break;
		}
	}
}

