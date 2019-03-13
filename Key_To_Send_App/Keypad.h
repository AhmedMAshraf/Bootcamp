/*
 * Keypad.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-062
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#define KEYPADROW1PORT GPIO_PORTB_BASE
#define KEYPADROW2PORT GPIO_PORTB_BASE
#define KEYPADROW3PORT GPIO_PORTB_BASE
#define KEYPADROW1PIN GPIO_PIN_2
#define KEYPADROW2PIN GPIO_PIN_3
#define KEYPADROW3PIN GPIO_PIN_6

#define KEYPADCOL1PORT GPIO_PORTD_BASE
#define KEYPADCOL2PORT GPIO_PORTD_BASE
#define KEYPADCOL3PORT GPIO_PORTA_BASE
#define KEYPADCOL1PIN GPIO_PIN_7
#define KEYPADCOL2PIN GPIO_PIN_6
#define KEYPADCOL3PIN GPIO_PIN_5

#define HIGH 1
#define LOW 0
void Keypad_Init(void);
extern uint8_t Keypad_GetPressedKey(void);



#endif /* KEYPAD_H_ */
