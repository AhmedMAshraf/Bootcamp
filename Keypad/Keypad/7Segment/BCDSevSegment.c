/*
 * BCDSevSegment.c
 *
 * Created: 2/18/2019 12:47:35 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/Keypad.h"
#include "../Includes/BCDSevSegment_cfg.h"
#include "../Includes/timer.h"

/* BCDSevegments_enable */
/* Parameters : void */
/* I/p : void */
/* O/p : nothing */
/* Return : void */
/* Function that initialize the 7-segment */
void BCDSevegments_enable(void)
{
	/* Set Direction of data lines of 7-seg o/p */
	DIO_SetPinDirection(SevSegmentData1,HIGH); 
	DIO_SetPinDirection(SevSegmentData2,HIGH); 
	DIO_SetPinDirection(SevSegmentData3,HIGH);
	DIO_SetPinDirection(SevSegmentData4,HIGH);
	
	/* Set Direction of EN Pins 7-seg o/p */
	DIO_SetPinDirection(SevSegmentEN1,HIGH);
	DIO_SetPinDirection(SevSegmentEN2,HIGH);
	DIO_SetPinDirection(SevSegmentEN3,HIGH);
	DIO_SetPinDirection(SevSegmentEN4,HIGH);
	
	DIO_WritePin(SevSegmentEN1,HIGH);
	DIO_WritePin(SevSegmentEN2,HIGH);
	DIO_WritePin(SevSegmentEN3,HIGH);
	DIO_WritePin(SevSegmentEN4,HIGH);
}

/* BCDSevegments_disable */
/* Parameters : void */
/* I/p : void */
/* O/p : nothing */
/* Return : void */
/* Function that disables the 7-segment */
void BCDSevegments_disable(void)
{
	DIO_WritePin(SevSegmentEN1,LOW);
	DIO_WritePin(SevSegmentEN2,LOW);
	DIO_WritePin(SevSegmentEN3,LOW);
	DIO_WritePin(SevSegmentEN4,LOW);
}

/* BCDSevegments_displayNo */
/* Parameters : void */
/* I/p : number to display */
/* O/p : nothing */
/* Return : void */
/* Function that takes up to a 4-digit number and displays it on 7-seg */
void BCDSevegments_displayNo(uint16 no)
{	uint8 c ;
	
	/* first check on number if its 1 digit */
	if(no >= 0 && no<=9)
	{
		DIO_WritePin(SevSegmentEN1,HIGH);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		DIO_WritePin(SevSegmentData1,Get_Bit(no,0)) ;
		DIO_WritePin(SevSegmentData2,Get_Bit(no,1)) ;
		DIO_WritePin(SevSegmentData3,Get_Bit(no,2)) ;
		DIO_WritePin(SevSegmentData4,Get_Bit(no,3)) ;
	}
	
	/* if number is 2 digit */
	else if(no >= 10 && no<=99)
	{
		c = no%10 ;
		DIO_WritePin(SevSegmentEN1,HIGH);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		DIO_WritePin(SevSegmentData1,Get_Bit(c,0)) ;
		DIO_WritePin(SevSegmentData2,Get_Bit(c,1)) ;
		DIO_WritePin(SevSegmentData3,Get_Bit(c,2)) ;
		DIO_WritePin(SevSegmentData4,Get_Bit(c,3)) ;
		timer_delay(DELAY_2_MS);
		no = no/10 ;
		DIO_WritePin(SevSegmentEN1,LOW);
		DIO_WritePin(SevSegmentEN2,HIGH);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		DIO_WritePin(SevSegmentData1,Get_Bit(no,0)) ;
		DIO_WritePin(SevSegmentData2,Get_Bit(no,1)) ;
		DIO_WritePin(SevSegmentData3,Get_Bit(no,2)) ;
		DIO_WritePin(SevSegmentData4,Get_Bit(no,3)) ;
		timer_delay(DELAY_2_MS);
	}
	
	/* if number is 3 digit */
	else if(no >= 100 && no<=999)
	{
		c = no%10 ;
		DIO_WritePin(SevSegmentEN1,HIGH);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		DIO_WritePin(SevSegmentData1,Get_Bit(c,0)) ;
		DIO_WritePin(SevSegmentData2,Get_Bit(c,1)) ;
		DIO_WritePin(SevSegmentData3,Get_Bit(c,2)) ;
		DIO_WritePin(SevSegmentData4,Get_Bit(c,3)) ;
		timer_delay(DELAY_2_MS);
		no = no/10 ;
		c = no%10 ;
		DIO_WritePin(SevSegmentEN1,HIGH);
		DIO_WritePin(SevSegmentEN2,HIGH);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		DIO_WritePin(SevSegmentData1,Get_Bit(c,0)) ;
		DIO_WritePin(SevSegmentData2,Get_Bit(c,1)) ;
		DIO_WritePin(SevSegmentData3,Get_Bit(c,2)) ;
		DIO_WritePin(SevSegmentData4,Get_Bit(c,3)) ;
		timer_delay(DELAY_2_MS);
		no = no/10 ;
		DIO_WritePin(SevSegmentEN1,LOW);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,HIGH);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		DIO_WritePin(SevSegmentData1,Get_Bit(no,0)) ;
		DIO_WritePin(SevSegmentData2,Get_Bit(no,1)) ;
		DIO_WritePin(SevSegmentData3,Get_Bit(no,2)) ;
		DIO_WritePin(SevSegmentData4,Get_Bit(no,3)) ;
		timer_delay(DELAY_2_MS);
	}
	
	/* if number is 4 digit */
	else
	{
		c = no%10 ;
		DIO_WritePin(SevSegmentEN1,HIGH);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		DIO_WritePin(SevSegmentData1,Get_Bit(c,0)) ;
		DIO_WritePin(SevSegmentData2,Get_Bit(c,1)) ;
		DIO_WritePin(SevSegmentData3,Get_Bit(c,2)) ;
		DIO_WritePin(SevSegmentData4,Get_Bit(c,3)) ;
		timer_delay(DELAY_2_MS);
		no = no/10 ;
		c = no%10 ;
		DIO_WritePin(SevSegmentEN1,LOW);
		DIO_WritePin(SevSegmentEN2,HIGH);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		DIO_WritePin(SevSegmentData1,Get_Bit(c,0)) ;
		DIO_WritePin(SevSegmentData2,Get_Bit(c,1)) ;
		DIO_WritePin(SevSegmentData3,Get_Bit(c,2)) ;
		DIO_WritePin(SevSegmentData4,Get_Bit(c,3)) ;
		timer_delay(DELAY_2_MS);
		no = no/10 ;
		c= no%10;
		DIO_WritePin(SevSegmentEN1,LOW);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,HIGH);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		DIO_WritePin(SevSegmentData1,Get_Bit(c,0)) ;
		DIO_WritePin(SevSegmentData2,Get_Bit(c,1)) ;
		DIO_WritePin(SevSegmentData3,Get_Bit(c,2)) ;
		DIO_WritePin(SevSegmentData4,Get_Bit(c,3)) ;
		timer_delay(DELAY_2_MS);
		no = no/10 ;
		c= no%10;
		DIO_WritePin(SevSegmentEN1,LOW);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,HIGH);
		
		DIO_WritePin(SevSegmentData1,Get_Bit(no,0)) ;
		DIO_WritePin(SevSegmentData2,Get_Bit(no,1)) ;
		DIO_WritePin(SevSegmentData3,Get_Bit(no,2)) ;
		DIO_WritePin(SevSegmentData4,Get_Bit(no,3)) ;
		timer_delay(DELAY_2_MS);
	}
}
