/*
 * timer.h
 *
 * Created: 2/13/2019 4:56:30 PM
 *  Author: AVE-LAP-062
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#define F_CPU 8000000UL

#include "MemmoryMappedRegister.h"
#include "DIO.h"

#define DELAY_10_MS 1
#define DELAY_1_SEC 500
#define ONE_SECOND 1000
#define OCR0_VALUE 124
#define ZERO 0
void timer_init();

void timer_delay(uint32 n);


#endif /* TIMER_H_ */