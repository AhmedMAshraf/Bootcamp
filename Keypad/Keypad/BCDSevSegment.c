/*
 * BCDSevSegment.c
 *
 * Created: 2/18/2019 12:47:35 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/"
#include "BCDSevSegment_cfg.h"
#include "timer.h"

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

void BCDSevegments_disable(void)
{
	DIO_WritePin(SevSegmentEN1,LOW);
	DIO_WritePin(SevSegmentEN2,LOW);
	DIO_WritePin(SevSegmentEN3,LOW);
	DIO_WritePin(SevSegmentEN4,LOW);
}

void BCDSevegments_displayNo(uint16 no)
{	uint8 c ;
	if(no >= 0 && no<=9)
	{
		DIO_WritePin(SevSegmentEN1,HIGH);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		SevSegmentPORT &=~(0x0f) ;
		SevSegmentPORT |= no;
	}
	else if(no >= 10 && no<=99)
	{
		c = no%10 ;
		DIO_WritePin(SevSegmentEN1,HIGH);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		SevSegmentPORT &=~(0x0f) ;
		SevSegmentPORT |= c;
		timer_delay(2);
		no = no/10 ;
		DIO_WritePin(SevSegmentEN1,LOW);
		DIO_WritePin(SevSegmentEN2,HIGH);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		SevSegmentPORT &=~(0x0f) ;
		SevSegmentPORT |= no;
		timer_delay(2);
	}
	else if(no >= 100 && no<=999)
	{
		c = no%10 ;
		DIO_WritePin(SevSegmentEN1,HIGH);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		SevSegmentPORT &=~(0x0f) ;
		SevSegmentPORT |= c;
		timer_delay(2);
		no = no/10 ;
		c = no%10 ;
		DIO_WritePin(SevSegmentEN1,HIGH);
		DIO_WritePin(SevSegmentEN2,HIGH);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		SevSegmentPORT &=~(0x0f) ;
		SevSegmentPORT |= c;
		timer_delay(2);
		no = no/10 ;
		DIO_WritePin(SevSegmentEN1,LOW);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,HIGH);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		SevSegmentPORT &=~(0x0f) ;
		SevSegmentPORT |= no;
		timer_delay(2);
	}
	else
	{
		c = no%10 ;
		DIO_WritePin(SevSegmentEN1,HIGH);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		SevSegmentPORT &=~(0x0f) ;
		SevSegmentPORT |= c;
		timer_delay(2);
		no = no/10 ;
		c = no%10 ;
		DIO_WritePin(SevSegmentEN1,LOW);
		DIO_WritePin(SevSegmentEN2,HIGH);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		SevSegmentPORT &=~(0x0f) ;
		SevSegmentPORT |= c;
		timer_delay(2);
		no = no/10 ;
		c= no%10;
		DIO_WritePin(SevSegmentEN1,LOW);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,HIGH);
		DIO_WritePin(SevSegmentEN4,LOW);
		
		SevSegmentPORT &=~(0x0f) ;
		SevSegmentPORT |= c;
		timer_delay(2);
		no = no/10 ;
		c= no%10;
		DIO_WritePin(SevSegmentEN1,LOW);
		DIO_WritePin(SevSegmentEN2,LOW);
		DIO_WritePin(SevSegmentEN3,LOW);
		DIO_WritePin(SevSegmentEN4,HIGH);
		
		SevSegmentPORT &=~(0x0f) ;
		SevSegmentPORT |= no;
		timer_delay(2);
	}
}
