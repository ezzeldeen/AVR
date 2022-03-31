/*
 *
 * Generate three wave forms 10, 5, 2.5 KHz with timer0 CTC mode with 50% duty cycle
 * Ezz
 *
 */

#include "MemMap32.h"
//#include <util/delay.h>

#define F_CPU 8000000UL

unsigned char g_tick = 0;

ISR(TIMER0_COMP_vect)
{
	g_tick++;

	PORTC ^= (1<<0); /* Toggle Pin0 to generate a 10Khz Clock */

	if(g_tick == 2)
	{
		PORTC ^= (1<<1); /* Toggle Pin1 to generate a 5Khz Clock */
	}
	else if(g_tick == 4)
	{
		PORTC ^= (1<<1); /* Toggle Pin1 to generate a 5Khz Clock */
		PORTC ^= (1<<2); /* Toggle Pin2 to generate a 2.5Khz Clock */
		g_tick = 0;
	}
}

void Timer0_CTC_Square_Wave_Init()
{
	TCNT0 = 0; //timer initial value
	OCR0  = 100; //compare value
	TIMSK |= (1<<OCIE0); //enable compare interrupt
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS01);
}


int main()
{
	DDRC |= 0x07; /* Configure PC0, PC1 and PC2 as output pins */
	PORTC &= 0xF8; /* Clear PC0, PC1 and PC2 pins */
	SREG |= (1<<7); /* enable global interrupts in MC */
	Timer0_CTC_Square_Wave_Init();

	while (1)
	{

	}
}


