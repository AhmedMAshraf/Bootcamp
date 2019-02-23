/*
 * MemmoryMappedRegister.h
 *
 * Created: 2/13/2019 2:37:00 PM
 *  Author: AVE-LAP-062
 */ 


#ifndef MEMMORYMAPPEDREGISTER_H_
#define MEMMORYMAPPEDREGISTER_H_
#include "DataTypes.h"

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

#define OCR0   (*(volatile uint8 *)0x5c)
#define TIMSK  (*(volatile uint8 *)0x59)
#define TIFR   (*(volatile uint8 *)0x58)
#define TCCR0  (*(volatile uint8 *)0x53)
#define TCNT0  (*(volatile uint8 *)0x52)
#define TCCR1A (*(volatile uint8 *)0x4F)
#define TCCR1B (*(volatile uint8 *)0x4E)
#define TCNT1H (*(volatile uint8 *)0x4D)
#define TCNT1L (*(volatile uint8 *)0x4C)
#define OCR1AH (*(volatile uint8 *)0x4B)
#define OCR1AL (*(volatile uint8 *)0x4A)
#define OCR1BH (*(volatile uint8 *)0x49)
#define OCR1BL (*(volatile uint8 *)0x48)
#define ICR1H  (*(volatile uint8 *)0x47)
#define ICR1L  (*(volatile uint8 *)0x46)
#define WGM10 0
#define WGM11 1
#define WGM12 3
#define WGM13 4
#define COM1A0 6
#define COM1A1 7
#define COM1B0 4
#define COM1B1 5
#define CS10 0
#define CS11 1
#define CS12 2


#define SREG (*(volatile uint8 *)0x5f)
#define GICR (*(volatile uint8 *)0x5b)
#define MCUCSR (*(volatile uint8 *)0x54)

#define  OCIE0 1
#define  TOIE0 0
#define  GIE 7
#define  INT2 5
#define  ISC2 6

#define PINA0 0
#define PINA1 1
#define PINA2 2 
#define PINA3 3
#define PINA4 4
#define PINA5 5
#define PINA6 6
#define PINA7 7

#define PINB0 8
#define PINB1 9
#define PINB2 10
#define PINB3 11
#define PINB4 12
#define PINB5 13
#define PINB6 14
#define PINB7 15

#define PINC0 16
#define PINC1 17
#define PINC2 18
#define PINC3 19
#define PINC4 20
#define PINC5 21
#define PINC6 22
#define PINC7 23

#define PIND0 23
#define PIND1 25
#define PIND2 26
#define PIND3 27
#define PIND4 28
#define PIND5 29
#define PIND6 30
#define PIND7 31









#endif /* MEMMORYMAPPEDREGISTER_H_ */