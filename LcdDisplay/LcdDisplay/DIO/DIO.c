/*
 * DIO.c
 *
 * Created: 2/13/2019 2:44:34 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/DIO.h"

/* DIO_WritePin */
/* Parameters : uint8 , uint8 */
/* I/p : PinNum , PinValue */
/* O/p : nothing */
/* Return : void */
/* Function that write to DIO pin */
void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	if(PinValue == 1)
	{
		if(PinNum >= 0 && PinNum<=7)
		{
			Set_Bit(PORTA,PinNum);
		}
		else if(PinNum > 7 && PinNum <= 15)
		{
			Set_Bit(PORTB,(PinNum-8));
		}
		else if(PinNum > 15 && PinNum <= 23 )
		{
			Set_Bit(PORTC,(PinNum-16));
		}
		else if(PinNum > 23 && PinNum<= 31)
		{
			Set_Bit(PORTD,(PinNum-24));
		}
		else;
	}
	else if(PinValue == 0)
	{
		if(PinNum >= 0 && PinNum<=7)
		{
			Clear_Bit(PORTA,PinNum);
		}
		else if(PinNum > 7 && PinNum <= 15)
		{
			Clear_Bit(PORTB,(PinNum-8));
		}
		else if(PinNum > 15 && PinNum <= 23 )
		{
			Clear_Bit(PORTC,(PinNum-16));
		}
		else if(PinNum > 23 && PinNum<= 31)
		{
			Clear_Bit(PORTD,(PinNum-24));
		}
		else;
	}
	else;
}

/* DIO_ReadPin */
/* Parameters : uint8  */
/* I/p : PinNum */
/* O/p : Value of pin */
/* Return : unint8 */
/* Function that read value of DIO pin */
uint8 DIO_ReadPin(uint8 PinNum)
{
	uint8 Pin =0;
	if(PinNum >= 0 && PinNum<=7)
	{
		Pin = Get_Bit(PINA,PinNum);
	}
	else if(PinNum > 7 && PinNum <= 15)
	{
		Pin = Get_Bit(PINB,(PinNum-8));
	}
	else if(PinNum > 15 && PinNum <= 23 )
	{
		Pin = Get_Bit(PINC,(PinNum-16));
	}
	else if(PinNum > 23 && PinNum<= 31)
	{
		Pin = Get_Bit(PIND,(PinNum-24));
	}
	else;
	return Pin ;
}
/* DIO_SetPinDirection */
/* Parameters : uint8 , uint8 */
/* I/p : PinNum , PinDirection */
/* O/p : nothing */
/* Return : void */
/* Function that Sets direction of DIO pin */
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	if(PinDirection == 1)
	{
		if(PinNum >= 0 && PinNum<=7)
		{
			Set_Bit(DDRA,PinNum);
		}
		else if(PinNum > 7 && PinNum <= 15)
		{
			Set_Bit(DDRB,(PinNum-8));
		}
		else if(PinNum > 15 && PinNum <= 23 )
		{
			Set_Bit(DDRC,(PinNum-16));
		}
		else if(PinNum > 23 && PinNum<= 31)
		{
			Set_Bit(DDRD,(PinNum-24));
		}
		else;
	}
	else if(PinDirection == 0)
	{
		if(PinNum >= 0 && PinNum<=7)
		{
			Clear_Bit(DDRA,PinNum);
		}
		else if(PinNum > 7 && PinNum <= 15)
		{
			Clear_Bit(DDRB,(PinNum-8));
		}
		else if(PinNum > 15 && PinNum <= 23 )
		{
			Clear_Bit(DDRC,(PinNum-16));
		}
		else if(PinNum > 23 && PinNum<= 31)
		{
			Clear_Bit(DDRD,(PinNum-24));
		}
		else;
	}
	else;
}