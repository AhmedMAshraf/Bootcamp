/*
 * Keypad.c
 *
 * Created: 2/18/2019 2:44:52 PM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/Keypad.h"

/* Keypad_init */
/* Parameters : void */
/* I/p : void */
/* O/p : nothing */
/* Return : void */
/* Function that initialize the Keypad */

void Keypad_init (void)
{
	/* Set Columns to O/P */
	DIO_SetPinDirection(KeypadCol1,HIGH);
	DIO_SetPinDirection(KeypadCol2,HIGH);
	DIO_SetPinDirection(KeypadCol3,HIGH);
	
	/* Set Rows To I/p */
	DIO_SetPinDirection(KeypadRow1,LOW);
	DIO_SetPinDirection(KeypadRow2,LOW);
	DIO_SetPinDirection(KeypadRow3,LOW);
	
	/* Enable internal Pull ups */
	DIO_WritePin(KeypadRow1,HIGH);
	DIO_WritePin(KeypadRow2,HIGH);
	DIO_WritePin(KeypadRow3,HIGH);
}

/* Keypad_getPressedKey */
/* Parameters : void */
/* I/p : void */
/* O/p : Key pressed by user on keypad */
/* Return : uint8 key */
/* Function that detect the key pressed by user on keypad */

uint8 Keypad_getPressedKey(void)
{
	uint8 key ;
	/* Set Column 1 */
	DIO_WritePin(KeypadCol1,LOW);
	DIO_WritePin(KeypadCol2,HIGH);
	DIO_WritePin(KeypadCol3,HIGH);
	if(!DIO_ReadPin(KeypadRow1))
		{
			key = 1 ;
			return key ;
		}
	else if(!DIO_ReadPin(KeypadRow2))
		{
			key = 4 ;
			return key ;
		}
	else if(!DIO_ReadPin(KeypadRow3))
		{
			key = 7 ;
			return key ;
		}
	else
		key = 0 ;
		
	/* Set Column 2 */
	DIO_WritePin(KeypadCol1,HIGH);
	DIO_WritePin(KeypadCol3,HIGH);
	DIO_WritePin(KeypadCol2,LOW);
	
	if(!DIO_ReadPin(KeypadRow1))
	{
		key = 2 ;
		return key ;
	}
	else if(!DIO_ReadPin(KeypadRow2))
	{
		key = 5 ;
		return key ;
	}
	else if(!DIO_ReadPin(KeypadRow3))
	{
		key = 8 ;
		return key ;
	}
	else
		key = 0 ;
	/* Set Column 3 */
	DIO_WritePin(KeypadCol1,HIGH);
	DIO_WritePin(KeypadCol2,HIGH);
	DIO_WritePin(KeypadCol3,LOW);
	
	if(!DIO_ReadPin(KeypadRow1))
	{
		key = 3 ;
		return key ;
	}
	else if(!DIO_ReadPin(KeypadRow2))
	{
		key = 6 ;
		return key ;
	}
	else if(!DIO_ReadPin(KeypadRow3))
	{
		key = 9 ;
		return key ;
	}
	else
	key = 0 ;
	
	return key ;
}