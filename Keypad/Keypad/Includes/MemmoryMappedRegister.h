/*
 * MemmoryMappedRegister.h
 *
 * Created: 2/13/2019 2:37:00 PM
 *  Author: AVE-LAP-062
 */ 


#ifndef MEMMORYMAPPEDREGISTER_H_
#define MEMMORYMAPPEDREGISTER_H_
#include "../Includes/DataTypes.h"

#define PORTA (*(volatile uint8 *)0x3B)
#define PORTB (*(volatile uint8 *)0x38)
#define PORTC (*(volatile uint8 *)0x35)
#define PORTD (*(volatile uint8 *)0x32)

#define PINA (*(volatile uint8 *)0x39)
#define PINB (*(volatile uint8 *)0x36)
#define PINC (*(volatile uint8 *)0x33)
#define PIND (*(volatile uint8 *)0x30)

#define DDRA (*(volatile uint8 *)0x3A)
#define DDRB (*(volatile uint8 *)0x37)
#define DDRC (*(volatile uint8 *)0x34)
#define DDRD (*(volatile uint8 *)0x31)

#define OCR0 (*(volatile uint8 *)0x5c)
#define TIMSK (*(volatile uint8 *)0x59)
#define TIFR (*(volatile uint8 *)0x58)
#define TCCR0 (*(volatile uint8 *)0x53)
#define TCNT0 (*(volatile uint8 *)0x52)









#endif /* MEMMORYMAPPEDREGISTER_H_ */