/*
 * Debouncing.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-062
 */

#ifndef DEBOUNCING_H_
#define DEBOUNCING_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

extern uint32_t Debounce_Flag ;

extern void Debounce_Task (void);

#endif /* DEBOUNCING_H_ */
