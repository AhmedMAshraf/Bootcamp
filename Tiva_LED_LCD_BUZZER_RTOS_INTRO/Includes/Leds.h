/*
 * Leds.h
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-062
 */

#ifndef INCLUDES_LEDS_H_
#define INCLUDES_LEDS_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#define LED1PORT GPIO_PORTF_BASE
#define LED2PORT GPIO_PORTF_BASE
#define LED3PORT GPIO_PORTF_BASE

#define LED1PIN GPIO_PIN_1
#define LED2PIN GPIO_PIN_2
#define LED3PIN GPIO_PIN_3

void Leds_Init(void);
void Led1_Blink(void);
void Led2_Blink(void);
void Led3_Blink(void);

#define LED1_HIGH GPIO_PIN_1
#define LED2_HIGH GPIO_PIN_2
#define LED3_HIGH GPIO_PIN_3
#define LED1_LOW 0
#define LED2_LOW 0
#define LED3_LOW 0

#endif /* INCLUDES_LEDS_H_ */
