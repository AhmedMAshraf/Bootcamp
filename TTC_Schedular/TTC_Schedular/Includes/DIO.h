/*
 * DIO.h
 *
 * Created: 2/13/2019 2:44:22 PM
 *  Author: AVE-LAP-062
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "MemmoryMappedRegister.h"
#include "BitwiseOperations.h"
#include "DataTypes.h"



void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);

#define MSK0(pin) (pin&0x01)
#define MSK1(pin) ((pin&0x02)>>1)
#define MSK2(pin) ((pin&0x04)>>2)
#define MSK3(pin) ((pin&0x08)>>3)
#define MSK4(pin) ((pin&0x10)>>4)
#define MSK5(pin) ((pin&0x20)>>5)
#define MSK6(pin) ((pin&0x40)>>6)
#define MSK7(pin) ((pin&0x80)>>7)

#endif /* DIO_H_ */