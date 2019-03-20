/*
 * UART.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-016
 */

#ifndef UART_H_
#define UART_H_


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/uart.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"

void UART0_init(void);
extern void UART0_Send(uint8_t data);
extern uint8_t UART0_Recv(void);

extern volatile uint8_t UART_Flag ;
extern volatile uint8_t DataToSend  ;

#endif /* UART_H_ */
