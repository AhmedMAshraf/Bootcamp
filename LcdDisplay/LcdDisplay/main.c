/*
 * LcdDisplay.c
 *
 * Created: 2/19/2019 10:47:13 AM
 * Author : AVE-LAP-062
 */ 

#include "Includes/DIO.h"
#include "Includes/timer.h"
#include "Includes/LCD.h"

#define SCREEN0 0
#define SCREEN1 1
#define SCREEN2 2
#define SCREEN3 3
#define SCREEN4 4
#define SCREEN5 5
#define SCREEN_SMILE 6
#define SCREEN_SAD 7
#define SCREEN_SCORE 8
#define PUSHBTN0 20
#define PUSHBTN1 10





int main(void)
{
    /* Variables */
	uint8 msg0[]={"WELCOME"};
	uint8 msg01[]={"-WELCOME-"};
	uint8 msg02[]={"--WELCOME--"};
	uint8 msg03[]={"---WELCOME---"};
	uint8 Ques1[]={"Is Nile 6685 km?"};  //wrong 
	uint8 Ques2[]={"Hitler died 30-6"};  //wrong
	uint8 Ques3[]={"ManUtd est. 1878"};  //yes
	uint8 Ques4[]={"Cr7 35 years ?"};    //wrong
	uint8 Ques5[]={"BOSCH est. 1886"};   //Yes
	uint8 Ans1[]={">Yes         >NO"};
	uint8 CustomChar1[]={0,10,0,0,4,10,17,0};
	uint8 CustomChar2[]={0,0,155,32,238,142,224,0};
	uint8 ScreenState = 0 ;
	uint8 Btn1 = 0 , Btn0 = 0 , Btn1_Prev = 0 , Btn0_Prev  = 0 ;
	
	/* Init Push  buttons Ports to input */
	DIO_SetPinDirection(PUSHBTN0 , LOW);
	DIO_SetPinDirection(PUSHBTN1 , LOW);
	
	timer_init();
	LCD_init();
	LCD_clear();

	LCD_Custom_Char(0,CustomChar1);
	LCD_Custom_Char(1,CustomChar2);
	
	
	/*LCD_sendCommand(0x80);
	LCD_displayChar(0);
	LCD_gotoRowColumn(2,10);
	LCD_displayChar(1);*/
	
    while (1) 
    {
		switch (ScreenState)
		{
			case SCREEN0 :
				LCD_clear();
				LCD_gotoRowColumn(1,5);
				LCD_displayString(msg0);
				timer_delay(DELAY_1_SEC);
				LCD_clear();
				LCD_gotoRowColumn(1,4);
				LCD_displayString(msg01);
				timer_delay(DELAY_1_SEC);
				LCD_clear();
				LCD_gotoRowColumn(1,3);
				LCD_displayString(msg02);
				timer_delay(DELAY_1_SEC);
				LCD_clear();
				LCD_gotoRowColumn(1,2);
				LCD_displayString(msg03);
				timer_delay(DELAY_1_SEC);
				ScreenState = SCREEN1 ;
				break;
			case SCREEN1 :
				LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_displayString(Ques1);
				LCD_gotoRowColumn(2,1);
				LCD_displayString(Ans1);
				while(DIO_ReadPin(PUSHBTN0) || DIO_ReadPin(PUSHBTN1));
				Btn0 = DIO_ReadPin(PUSHBTN0);
				Btn1 = DIO_ReadPin(PUSHBTN1);
				//if()
				
			case SCREEN2 :
				LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_displayString(Ques2);
				LCD_gotoRowColumn(2,1);
				LCD_displayString(Ans1);
			case SCREEN3 :
				LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_displayString(Ques3);
				LCD_gotoRowColumn(2,1);
				LCD_displayString(Ans1);
			case SCREEN4 :
				LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_displayString(Ques4);
				LCD_gotoRowColumn(2,1);
				LCD_displayString(Ans1);
			case SCREEN5 :
				LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_displayString(Ques5);
				LCD_gotoRowColumn(2,1);
				LCD_displayString(Ans1);
			case SCREEN_SMILE :
			
			case SCREEN_SAD :
			
			case SCREEN_SCORE :
				break;
		}		
    }
}

