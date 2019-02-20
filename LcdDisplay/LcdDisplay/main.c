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
#define SCREEN_SCORE 6
#define SCREEN_SMILE 7
#define SCREEN_SAD 8

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
		
	uint8 Custom1[]={0,0,1,2,4,8,16,16};
	uint8 Custom2[]={0,31,0,0,27,0,0,0};
	uint8 Custom3[]={0,0,16,8,4,2,1,1};
	uint8 Custom4[]={16,16,8,4,2,1,0,0};
	uint8 Custom5[]={0,14,17,17,0,0,31,0};
	uint8 Custom6[]={1,1,2,4,8,16,0,0};
	uint8 Custom7[]={0,17,17,14,0,0,31,0};
	uint8 ScreenState = 0 , Prev_Screen=1 , Score = 0 ;
	
	
	
	/* Init Push  buttons Ports to input */
	DIO_SetPinDirection(PUSHBTN0 , LOW);
	DIO_SetPinDirection(PUSHBTN1 , LOW);
	
	timer_init();
	LCD_init();
	LCD_clear();

	LCD_Custom_Char(0,Custom1);
	LCD_Custom_Char(1,Custom2);
	LCD_Custom_Char(2,Custom3);
	LCD_Custom_Char(3,Custom4);
	LCD_Custom_Char(4,Custom5);
	LCD_Custom_Char(5,Custom6);
	LCD_Custom_Char(6,Custom7);
		
    while (1) 
    {
		switch (ScreenState)
		{
			case SCREEN0 :
				LCD_clear();
				LCD_gotoRowColumn(1,5);
				LCD_displayString(msg0);
				timer_delay(300);
				LCD_clear();
				LCD_gotoRowColumn(1,4);
				LCD_displayString(msg01);
				timer_delay(300);
				LCD_clear();
				LCD_gotoRowColumn(1,3);
				LCD_displayString(msg02);
				timer_delay(300);
				LCD_clear();
				LCD_gotoRowColumn(1,2);
				LCD_displayString(msg03);
				timer_delay(DELAY_1_SEC);
				ScreenState = SCREEN1 ;
				break;
			case SCREEN1 :
				Prev_Screen = SCREEN1 ;
				LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_displayString(Ques1);
				LCD_gotoRowColumn(2,1);
				LCD_displayString(Ans1);
				while(!DIO_ReadPin(PUSHBTN0) && !DIO_ReadPin(PUSHBTN1));
				
				if(DIO_ReadPin(PUSHBTN0))
				{
					ScreenState = SCREEN_SAD;
	
				}

				if(DIO_ReadPin(PUSHBTN1))
				{
					ScreenState = SCREEN_SMILE;
					Score++;
				}
			
				break;
				
			case SCREEN2 :
				Prev_Screen = SCREEN2 ;
				LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_displayString(Ques2);
				LCD_gotoRowColumn(2,1);
				LCD_displayString(Ans1);
				while(!DIO_ReadPin(PUSHBTN0) && !DIO_ReadPin(PUSHBTN1));
				
				if(DIO_ReadPin(PUSHBTN0))
				{
					ScreenState = SCREEN_SAD;
				}
				
				if(DIO_ReadPin(PUSHBTN1))
				{
					ScreenState = SCREEN_SMILE;
					Score ++ ;
				}
				
				break;
			case SCREEN3 :
				Prev_Screen = SCREEN3 ;
				LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_displayString(Ques3);
				LCD_gotoRowColumn(2,1);
				LCD_displayString(Ans1);
				while(!DIO_ReadPin(PUSHBTN0) && !DIO_ReadPin(PUSHBTN1));
				
				if(DIO_ReadPin(PUSHBTN0))
				{
					ScreenState = SCREEN_SMILE;
					Score++;
				}
				
				if(DIO_ReadPin(PUSHBTN1))
				{
					ScreenState = SCREEN_SAD;
				}
				
				break;
			case SCREEN4 :
				Prev_Screen = SCREEN4 ;
				//LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_displayString(Ques4);
				LCD_gotoRowColumn(2,1);
				LCD_displayString(Ans1);
				while(!DIO_ReadPin(PUSHBTN0) && !DIO_ReadPin(PUSHBTN1));
			
				if(DIO_ReadPin(PUSHBTN0))
				{
					ScreenState = SCREEN_SAD;
				}
				
				if(DIO_ReadPin(PUSHBTN1))
				{
					ScreenState = SCREEN_SMILE;
					Score ++;
				}
				
				break;
			case SCREEN5 :
				Prev_Screen = SCREEN5 ;
				//LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_displayString(Ques5);
				LCD_gotoRowColumn(2,1);
				LCD_displayString(Ans1);
				while(!DIO_ReadPin(PUSHBTN0) && !DIO_ReadPin(PUSHBTN1));
			
				if(DIO_ReadPin(PUSHBTN0))
				{
					ScreenState = SCREEN_SMILE;
					Score++;
				}
				
				if(DIO_ReadPin(PUSHBTN1))
				{
					ScreenState = SCREEN_SAD;
				}
				
				break;
			case SCREEN_SMILE :
				LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_sendCommand(0x87);
				LCD_displayChar(0);
				LCD_displayChar(1);
				LCD_displayChar(2);
				LCD_sendCommand(0xc7);
				timer_delay(2);
				LCD_displayChar(3);
				LCD_displayChar(6);
				LCD_displayChar(5);
				timer_delay(2000);
				LCD_clear();
				
				ScreenState = ++Prev_Screen;
				break;
			case SCREEN_SAD :
				LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_sendCommand(0x87);
				LCD_displayChar(0);
				LCD_displayChar(1);
				LCD_displayChar(2);
				LCD_sendCommand(0xc7);
				timer_delay(2);
				LCD_displayChar(3);
				LCD_displayChar(4);
				LCD_displayChar(5);
				timer_delay(2000);
				LCD_clear();
	
				ScreenState = ++Prev_Screen;
				break;
			case SCREEN_SCORE :
				//LCD_clear();
				LCD_gotoRowColumn(1,1);
				LCD_displayString("Your Score: ");
				LCD_displayChar(Score+48);
				LCD_gotoRowColumn(2,1);
				LCD_displayString("Again ?");
				while(!DIO_ReadPin(PUSHBTN0) && !DIO_ReadPin(PUSHBTN1));
				
				if(DIO_ReadPin(PUSHBTN0))
				{
					ScreenState = SCREEN0;
					Score++;
				}
				
				if(DIO_ReadPin(PUSHBTN1))
				{
					ScreenState = SCREEN_SCORE;
				}
				break;
		}		
    }
}

