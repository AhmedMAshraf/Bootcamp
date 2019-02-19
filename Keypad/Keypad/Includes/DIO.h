/*
 * DIO.h
 *
 * Created: 2/13/2019 2:44:22 PM
 *  Author: AVE-LAP-062
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../Includes/MemmoryMappedRegister.h"
#include "../Includes/BitwiseOperations.h"
#include "../Includes/DataTypes.h"



void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);



#endif /* DIO_H_ */