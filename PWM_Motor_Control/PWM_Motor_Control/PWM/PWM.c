/*
 * PWM.c
 *
 * Created: 2/21/2019 11:54:06 AM
 *  Author: AVE-LAP-062
 */ 

#include "../Includes/PWM.h"

/* timer_init */
/* Parameters : N/A */
/* I/p : N/A */
/* O/p : N/A */
/* Return : void */
/* Function that initalize timer one to pwm operation */

void Timer1_PWM_Init(void)
{
	/* Initialize OC1A / OC1B pins as output */
	DIO_SetPinDirection(MOTOR2,HIGH);
	DIO_SetPinDirection(MOTOR1,HIGH);
	DIO_SetPinDirection(MOTOR1_DIR1_PIN,HIGH);
	DIO_SetPinDirection(MOTOR1_DIR2_PIN,HIGH);
	DIO_SetPinDirection(MOTOR2_DIR1_PIN,HIGH);
	DIO_SetPinDirection(MOTOR2_DIR2_PIN,HIGH);
	
	/* Check Direction MACRO */
	#if (MOTOR1_DIR == FORWARD)
	DIO_WritePin(MOTOR1_DIR1_PIN,HIGH); //Motor1 dirA
	DIO_WritePin(MOTOR1_DIR2_PIN,LOW); //Motor1 dirB
	#elif (MOTOR1_DIR == BACKWARD)
	DIO_WritePin(MOTOR1_DIR1_PIN,LOW); //Motor1 dirA
	DIO_WritePin(MOTOR1_DIR2_PIN,HIGH); //Motor1 dirB
	#elif (MOTOR1_DIR == STOP)
	DIO_WritePin(MOTOR1_DIR1_PIN,LOW); //Motor1 dirA
	DIO_WritePin(MOTOR1_DIR2_PIN,LOW); //Motor1 dirB
	#endif
	#if (MOTOR2_DIR == FORWARD)
	DIO_WritePin(MOTOR2_DIR1_PIN,HIGH); //Motor1 dirA
	DIO_WritePin(MOTOR2_DIR2_PIN,LOW); //Motor1 dirB
	#elif (MOTOR2_DIR == BACKWARD)
	DIO_WritePin(MOTOR2_DIR1_PIN,LOW); //Motor1 dirA
	DIO_WritePin(MOTOR2_DIR2_PIN,HIGH); //Motor1 dirB
	#elif (MOTOR2_DIR == STOP)
	DIO_WritePin(MOTOR2_DIR1_PIN,LOW); //Motor1 dirA
	DIO_WritePin(MOTOR2_DIR2_PIN,LOW); //Motor1 dirB
	#endif
	
	/* Clear TCNT1 */
	TCNT1H = ZERO ;
	TCNT1L = ZERO ;
	
	/* Configure timer1 to operate on Fast-Pwm 10-bit Mode */
	Set_Bit(TCCR1A,WGM10);
	Set_Bit(TCCR1A,WGM11);
	Set_Bit(TCCR1B,WGM12);
	Clear_Bit(TCCR1B,WGM13);
	
	/* Non-Inverted Mode */
	Clear_Bit(TCCR1A,COM1A0);
	Clear_Bit(TCCR1A,COM1B0);
	Set_Bit(TCCR1A,COM1A1);
	Set_Bit(TCCR1A,COM1B1);
	
	/* Set Prescaler 64*/
	Set_Bit(TCCR1B,CS10);
	Set_Bit(TCCR1B,CS11);
	Clear_Bit(TCCR1B,CS12);
}

/* Timer1_PWM_Change_Duty */
/* Parameters : duty cycle */
/* I/p : N/A */
/* O/p : N/A */
/* Return : void */
/* Function that change timer duty cycle */
void Timer1_PWM_Change_Duty(uint8 duty)
{
	uint16 value = duty*TIMER1_MAX/100 ;
	OCR1AH = value >> 8 ;
	OCR1AL = value ;
	OCR1BH = value >> 8 ;
	OCR1BL = value ;
	
}