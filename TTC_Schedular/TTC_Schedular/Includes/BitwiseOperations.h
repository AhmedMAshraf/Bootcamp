/*
 * DIO.h
 *
 * Created: 2/13/2019 11:37:35 AM
 *  Author: AVE-LAP-062
 */ 


#ifndef BitwiseOperations_H_
#define BitwiseOperations_H_

#define HIGH 1
#define LOW 0

#define Set_Bit(Register,Bit)    (Register |= (1<<Bit))
#define Clear_Bit(Register,Bit)  (Register &= ~(1<<Bit))
#define Get_Bit(Register,Bit)	 ((Register & (1<<Bit))>>Bit)
#define Toggle_Bit(Register,Bit) (Register ^= (1<<Bit))


#endif /* BitwiseOperations_H_ */