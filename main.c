/*
 * main.c
 *
 *  Created on: Sep 26, 2019
 *      Author: hesha
 */

#include "ADC.h"
#include "lcd.h"
#include <util/delay.h>
int main(void)
{
	uint16 res_value;
	LCD_init(); /* initialize LCD driver */
	ADC_Init(); /* initialize ADC driver */
	LCD_clearScreen(); /* clear LCD at the beginning */
	/* display this string "ADC Value = " only once at LCD */
	LCD_displayString("ADC Value = ");
	ADC_SelectChannel(ADC0);
	SET_BIT(SREG,I);
	ADC_StartConversion();
    while(1)
    {
		LCD_goToRowColumn(0,12); /* display the number every time at this position */
		res_value = ADC_ReadChannel(); /* read channel zero where the potentiometer is connect */
		LCD_intgerToString(res_value); /* display the ADC value on LCD screen */
    }
}

