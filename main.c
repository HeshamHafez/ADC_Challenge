/*
 * main.c
 *
 *  Created on: Sep 26, 2019
 *      Author: hesha
 */

#include "ADC.h"
#include "lcd.h"
#include <util/delay.h>

volatile uint32 temp = 0;

void INT0_Init(void);

ISR(INT0_vect)
{
	temp = ADC_ReadChannel(); /* read channel zero where the potentiometer is connect */
	temp = (temp*150*5)/(1023*1.5); /* calculate the temp from the ADC value*/
}
int main(void)
{

	LCD_init(); /* initialize LCD driver */
	ADC_Init(); /* initialize ADC driver */
	LCD_displayString("Temp = ");
	LCD_goToRowColumn(0,10);
	/* display character 'C' on the screen "Temp =   C" */
	LCD_displayCharacter('C');
	SET_BIT(SREG,I);
	INT0_Init();
	ADC_StartConversion();
	while(1)
	{
		LCD_goToRowColumn(0,7); /* display the number every time at this position */
		LCD_intgerToString(temp); /* display the temp on LCD screen */
	}
}

void INT0_Init(void)
{
	SET_BIT(GICR,INT0);
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	DIO_SetPinDirection(DIO_PIN26,0);
}
