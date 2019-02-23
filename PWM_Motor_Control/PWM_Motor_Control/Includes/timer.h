/*
 * timer.h
 *
 * Created: 2/13/2019 4:56:30 PM
 *  Author: AVE-LAP-062
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#define F_CPU 16000000UL

#include "MemmoryMappedRegister.h"
#include "DIO.h"

void timer_init();

void timer_delay(uint32 n);


#endif /* TIMER_H_ */