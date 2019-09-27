/*
 * pwm.c
 *
 *  Created on: Aug 27, 2019
 *      Author: hesha
 */

#include"pwm.h"



void PWM_init(void)
{
	PWM_TCNT2 = 0;

	DIO_SetPinDirection(DIO_PIN31,OUTPUT);

	PWM_TCCR2 = (1<<PWM_WGM20) | (1<<PWM_WGM21) | (1<<PWM_COM21) | (1<<PWM_CS21);

}

void PWM_duty(uint8 duty)
{
	PWM_OCR2=duty*255/100;
}
