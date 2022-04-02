/*
 *
 * Generate 500KHz WF using timer0 PWM mode 
 * Ezz
 *
 */

#include "MemMap32.h"
//#include <util/delay.h>

#define F_CPU 8000000UL

unsigned char g_tick = 0;

void Timer0_PWM_Init(unsigned char set_duty_cycle)
{
	TCNT0 = 0; //timer initial value
	OCR0  = set_duty_cycle; //compare value
	DDRB  = DDRB | (1<<3); //set OC0 as output pin --> pin where the PWM signal is

	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}


int main()
{
	Timer0_PWM_Init(128); //50% duty cycle

	while (1)
	{

	}
}


