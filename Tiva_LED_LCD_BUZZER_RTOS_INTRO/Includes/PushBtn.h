/*
 * PushBtn.h
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-062
 */

#ifndef INCLUDES_PUSHBTN_H_
#define INCLUDES_PUSHBTN_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#define PUSHBTN0PORT GPIO_PORTB_BASE
#define PUSHBTN0PIN GPIO_PIN_6

#define PUSHBTN1PORT GPIO_PORTD_BASE
#define PUSHBTN1PIN GPIO_PIN_2

void Btns_Init(void);
uint8_t Btn1_Read(void);


#endif /* INCLUDES_PUSHBTN_H_ */
