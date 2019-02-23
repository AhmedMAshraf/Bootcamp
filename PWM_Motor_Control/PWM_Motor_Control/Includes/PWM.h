/*
 * PWM.h
 *
 * Created: 2/21/2019 11:54:21 AM
 *  Author: AVE-LAP-062
 */ 


#ifndef PWM_H_
#define PWM_H_


#define F_CPU 16000000UL

#include "MemmoryMappedRegister.h"
#include "DIO.h"

#define DELAY_10_MS 1
#define DELAY_1_SEC 500
#define ONE_SECOND 1000
#define OCR0_VALUE 124
#define ZERO 0

#define TIMER1_MAX 1024

#define MOTOR1_DIR  FORWARD
#define MOTOR2_DIR  FORWARD

#define FORWARD 4
#define BACKWARD 5
#define STOP 6
#define MOTOR2 PIND5
#define MOTOR1 PIND4
#define MOTOR1_DIR1_PIN PIND2
#define MOTOR1_DIR2_PIN PIND3
#define MOTOR2_DIR1_PIN PIND6
#define MOTOR2_DIR2_PIN PIND7



#define DUTY0 0
#define DUTY10 10
#define DUTY20 20
#define DUTY30 30
#define DUTY40 40
#define DUTY50 50
#define DUTY60 60
#define DUTY70 70
#define DUTY80 80
#define DUTY90 90
#define DUTY100 100


void Timer1_PWM_Init(void);
void Timer1_PWM_Change_Duty(uint8 duty);

//void timer_delay(uint32 n);


#endif /* PWM_H_ */