/*
 * pwm.h
 *
 *  Created on: Aug 27, 2019
 *      Author: hesha
 */

#ifndef PWM_H_
#define PWM_H_

#include"DIO.h"

#ifndef F_CPU
#define F_CPU 8000000UL //1MHz Clock frequency
#endif

#define PWM_TCCR2 (*(volatile uint8 * )0x0045) /*Timer/Counter Control Register – TCCR0*/
#define PWM_TCNT2 (*(volatile uint8 * )0x0044) /*Timer/Counter Register – TCNT0*/
#define PWM_OCR2  (*(volatile uint8 * )0x0043) /*Output Compare Register – OCR0*/
#define PWM_TIMSK (*(volatile uint8 * )0x0059) /*Timer/Counter Interrupt Mask Register – TIMSK*/
#define PWM_TIFR  (*(volatile uint8 * )0x0058) /*Timer/Counter Interrupt Flag Register – TIFR*/


/*Timer/Counter Control Register – TCCR0*/
#define PWM_CS20   0
#define PWM_CS21   1
#define PWM_CS22   2
#define PWM_WGM21  3
#define PWM_COM20  4
#define PWM_COM21  5
#define PWM_WGM20  6
#define PWM_FOC2   7

/*Timer/Counter Interrupt Mask Register – TIMSK*/
#define PWM_TOIE2  6
#define PWM_OCIE2  7

/*Timer/Counter Interrupt Flag Register – TIFR*/
#define PWM_TOV2   6
#define PWM_OCF2   7

#define PHASECORRECT_PWM 1
#define FAST_PWM 3

#define CLEAR_MODE 2
#define SET_MODE 3

void PWM_init(void);
void PWM_duty(uint8 duty);



#endif /* PWM_H_ */
