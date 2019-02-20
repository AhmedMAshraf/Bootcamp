/*
 * LCD.c
 *
 * Created: 2/19/2019 11:13:32 AM
 *  Author: AVE-LAP-062
 */ 
#include "../Includes/timer.h"
#include "../Includes/LCD.h"


void LCD_init(void)
{
	timer_delay(DELAY_10_MS);
	/* Set LCD Pins to output */
	DIO_SetPinDirection(RS_Pin,HIGH);
	DIO_SetPinDirection(RW_Pin,HIGH);
	DIO_SetPinDirection(EN_Pin,HIGH);
	DIO_SetPinDirection(LCD_D4,HIGH);
	DIO_SetPinDirection(LCD_D5,HIGH);
	DIO_SetPinDirection(LCD_D6,HIGH);
	DIO_SetPinDirection(LCD_D7,HIGH);
	
	/* Set LCD 4-bit */
	LCD_sendCommand(0x33);
	LCD_sendCommand(0x32);
	LCD_sendCommand(LCD_CMD_4B_MODE);
	/* Clear Screen */
	LCD_sendCommand(LCD_CMD_CLR);
	/*Display On cursor blinking*/
	LCD_sendCommand(LCD_CMD_DISPLAY_ON);
	/* Force cursor begin at 1st line */
	LCD_sendCommand(LCD_CMD_CURSOR_1ST_LINE);
	/* Auto Increment Cursor */
	LCD_sendCommand(0x06);
	/*Cursor off */
	LCD_sendCommand(LCD_CMD_OFF_CURSOR);
}

void LCD_sendCommand(uint8 command)
{
	timer_delay(DELAY_10_MS);
	DIO_WritePin(RS_Pin,LOW);
	DIO_WritePin(RW_Pin,LOW);
	DIO_WritePin(EN_Pin,HIGH);
	
	#if LCD_MODE == FOUR_BIT_MODE
		/* First four bits */
		
		/* Write Data pins */
		DIO_WritePin(LCD_D4,MSK4(command));
		DIO_WritePin(LCD_D5,MSK5(command));
		DIO_WritePin(LCD_D6,MSK6(command));
		DIO_WritePin(LCD_D7,MSK7(command));
		timer_delay(DELAY_10_MS);
		/* Latch LCD_EN=0 */
		DIO_WritePin(RS_Pin,LOW);
		DIO_WritePin(RW_Pin,LOW);
		DIO_WritePin(EN_Pin,LOW);
		timer_delay(DELAY_10_MS);
		/* Reset LCD_EN */
		DIO_WritePin(EN_Pin,HIGH);
		timer_delay(DELAY_10_MS);
		
		/* Last four bits */
		command = (command << 4) & 0xf0 ;
		/* Write Data pins */
		DIO_WritePin(LCD_D4,MSK4(command));
		DIO_WritePin(LCD_D5,MSK5(command));
		DIO_WritePin(LCD_D6,MSK6(command));
		DIO_WritePin(LCD_D7,MSK7(command));
		timer_delay(DELAY_10_MS);
		/* Latch LCD_EN=0 */
		DIO_WritePin(RS_Pin,LOW);
		DIO_WritePin(RW_Pin,LOW);
		DIO_WritePin(EN_Pin,LOW);
		timer_delay(DELAY_10_MS);
		/* Reset LCD_EN */
		DIO_WritePin(EN_Pin,HIGH);
		timer_delay(DELAY_10_MS);
	#endif
	#if LCD_MODE == EIGHT_BIT_MODE
		LCD_DATA |= command&0xf0;
		timer_delay(DELAY_10_MS);
		DIO_WritePin(RS_Pin,LOW);
		DIO_WritePin(RW_Pin,LOW);
		DIO_WritePin(EN_Pin,HIGH);
		timer_delay(DELAY_10_MS);
		DIO_WritePin(EN_Pin,LOW);
		timer_delay(DELAY_10_MS);
	#endif	
		
}

void LCD_displayChar(uint8 character)
{
	timer_delay(DELAY_10_MS);
	DIO_WritePin(RS_Pin,HIGH);
	DIO_WritePin(RW_Pin,LOW);
	DIO_WritePin(EN_Pin,HIGH);
	
	/* Write Data pins */
	DIO_WritePin(LCD_D4,MSK4(character));
	DIO_WritePin(LCD_D5,MSK5(character));
	DIO_WritePin(LCD_D6,MSK6(character));
	DIO_WritePin(LCD_D7,MSK7(character));
	timer_delay(DELAY_10_MS);
	/* Latch LCD_EN=0 */
	DIO_WritePin(EN_Pin,LOW);
	timer_delay(DELAY_10_MS);
	/* Reset LCD_EN */
	DIO_WritePin(EN_Pin,HIGH);
	timer_delay(DELAY_10_MS);
	
	/* Last four bits */
	character = (character << 4) & 0xf0 ;
	/* Write Data pins */
	DIO_WritePin(LCD_D4,MSK4(character));
	DIO_WritePin(LCD_D5,MSK5(character));
	DIO_WritePin(LCD_D6,MSK6(character));
	DIO_WritePin(LCD_D7,MSK7(character));
	timer_delay(DELAY_10_MS);
	/* Latch LCD_EN=0 */
	DIO_WritePin(EN_Pin,LOW);
	timer_delay(DELAY_10_MS);
	/* Reset LCD_EN */
	DIO_WritePin(EN_Pin,HIGH);
	timer_delay(DELAY_10_MS);
}

void LCD_displayString(uint8 *str)
{
	int n=0;
	while(str[n])
	{
		LCD_displayChar(str[n]);
		n++;
		if (n==LCD_COLS)
		{
			LCD_sendCommand(LCD_CMD_INC_CURSOR);
		}
	}
}

void LCD_gotoRowColumn(uint8 row , uint8 col)
{
	
	
	col--;
	if (row==1)
	{
		LCD_sendCommand(0x80+col);
	}
	if (row==2)
	{
		LCD_sendCommand(0xC0+col);
	}

	
}

void LCD_sendString_RowCol(uint8 *str , uint8 row , uint8 col)
{
	LCD_gotoRowColumn(row,col);
	timer_delay(DELAY_10_MS);
	LCD_displayString(str);
}

void LCD_clear(void)
{
	LCD_sendCommand(LCD_CMD_CLR);
	LCD_sendCommand (LCD_CMD_CURSOR_1ST_LINE);
}

void LCD_Custom_Char (uint8 loc, uint8 *msg)
{
	uint8 i;
	if(loc<8)
	{
		LCD_sendCommand (0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		LCD_displayChar(msg[i]);
	}
}