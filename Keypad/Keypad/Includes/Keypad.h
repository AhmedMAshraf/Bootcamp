/*
 * Keypad.h
 *
 * Created: 2/18/2019 2:45:03 PM
 *  Author: AVE-LAP-062
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../Includes/DIO.h"
#include "../Includes/Keypad_cfg.h"

void Keypad_init (void);
uint8 Keypad_getPressedKey(void);


#endif /* KEYPAD_H_ */