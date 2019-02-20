/*
 * LCD.h
 *
 * Created: 2/19/2019 11:12:51 AM
 *  Author: AVE-LAP-062
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "MemmoryMappedRegister.h"
#include "DIO.h"
#include "LCD_cfg.h"
#include "timer.h"

void LCD_init(void);
void LCD_sendCommand(uint8 command);
void LCD_displayChar(uint8 character);
void LCD_displayString(uint8 *str);
void LCD_gotoRowColumn(uint8 row , uint8 col);
void LCD_sendString_RowCol(uint8 *str , uint8 row , uint8 col);
void LCD_clear(void);
void LCD_Custom_Char (uint8 loc, uint8 *msg);

#endif /* LCD_H_ */