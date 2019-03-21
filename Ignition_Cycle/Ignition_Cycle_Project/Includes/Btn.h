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

#define PUSHBTN1PORT GPIO_PORTF_BASE
#define PUSHBTN1PIN GPIO_PIN_4

#define BTN1_ON 1
#define BTN1_OFF 0

extern void Btns_Init(void);
extern uint32_t Btn1_Read(void);
extern void Btn1_Task(void *pvParameters);

#define BTN1_FLAG   ( 1 << 1)

#endif /* INCLUDES_PUSHBTN_H_ */
