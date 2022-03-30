/*
 *
 * Generate square wave with timer0 compare mode 2KHz, 50% Duty cycle
 * Ezz
 *
 */

#include "MemMap32.h"
//#include <util/delay.h>

#define F_CPU 1000000UL


void Timer0_CTC_Square_Wave_Init()
{
	TCNT0 = 0; //timer initial value
	OCR0  = 250; //compare value
	DDRB = DDRB | (1<<3); // OC0 Pin as output pin
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<COM00) | (1<<CS00);
}


int main()
{
	Timer0_CTC_Square_Wave_Init();
	while (1)
	{

	}
}


