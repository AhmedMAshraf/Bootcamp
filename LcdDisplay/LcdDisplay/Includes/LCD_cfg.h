/*
 * LCD_cfg.h
 *
 * Created: 2/19/2019 11:13:04 AM
 *  Author: AVE-LAP-062
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "MemmoryMappedRegister.h"

#define LCD_MODE 4
#define FOUR_BIT_MODE 4
#define EIGHT_BIT_MODE 8

#define RS_Pin PINA1
#define EN_Pin PINA3
#define RW_Pin PINA2
#define LCD_D4 PINA4
#define LCD_D5 PINA5
#define LCD_D6 PINA6
#define LCD_D7 PINA7
#define LCD_DATA PORTA

#define LCD_CMD_CLR 0x01
#define LCD_CMD_DISPLAY_ON 0x0E
#define LCD_CMD_CURSOR_1ST_LINE 0x80
#define LCD_CMD_4B_MODE 0x28
#define LCD_CMD_CURSOR_2ND_LINE 0xC0
#define LCD_CMD_INC_CURSOR 0x14
#define LCD_CMD_OFF_CURSOR 0x0C


#define LCD_COLS 16
#define LCD_ROWS 2


#endif /* LCD_CFG_H_ */