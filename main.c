/*
 * main.c
 *
 *  Created on: Sep 26, 2019
 *      Author: hesha
 */

#include "ADC.h"
#include "lcd.h"
#include "pwm.h"

int main(void)
{
	uint32 temp = 0;
	LCD_init(); /* initialize LCD driver */
	ADC_Init(); /* initialize ADC driver */
	DIO_SetPinDirection(DIO_PIN8,OUTPUT);
	DIO_SetPinDirection(DIO_PIN9,OUTPUT);
	DIO_WritePin(DIO_PIN8,HIGH);
	DIO_WritePin(DIO_PIN9,LOW);
	PWM_init();
	LCD_displayString("Temp = ");
	LCD_goToRowColumn(0,10);
	/* display character 'C' on the screen "Temp =   C" */
	LCD_displayCharacter('C');
	SET_BIT(SREG,I);
	ADC_StartConversion();
	while(1)
	{
		LCD_goToRowColumn(0,7); /* display the number every time at this position */
		temp = ADC_ReadChannel(); /* read channel zero where the potentiometer is connect */
		temp = (temp*150*5)/(1023*1.5); /* calculate the temp from the ADC value*/
		LCD_intgerToString(temp); /* display the temp on LCD screen */
		if(temp <= 30)
		{
			PWM_duty(30);
		}
		else if(temp >= 30 && temp <= 100)
		{
			PWM_duty(temp);
		}
		else
		{
			/*Do nothing*/
		}
	}
}
