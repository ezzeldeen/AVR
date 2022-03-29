/*
 *
 * Toggle LED every half second with timer0 Compare mode
 * Ezz
 *
 */

#include "MemMap32.h"
//#include <util/delay.h>

#define F_CPU 1000000UL
#define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2
unsigned char g_tick = 0;

ISR(TIMER0_COMP_vect)
{
	g_tick++;
	if(g_tick == NUMBER_OF_OVERFLOWS_PER_HALF_SECOND)
	{
		PORTC = PORTC ^ (1<<0); //toggle led every 0.5 second
		g_tick = 0; //clear the tick counter again to count a new 0.5 second
	}
}

void timer0_init_CTC_mode(unsigned char tick)
{
	TCNT0 = 0; //timer initial value
	OCR0  = tick; //compare value
	TIMSK |= (1<<OCIE0); //enable compare interrupt

	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS02) | (1<<CS00);
}



int main()
{

	DDRC  |= (1<<0); //configure the led pin to be output pin.
	PORTC &= ~(1<<0); //LED is off at the beginning(Positive Logic).
	SREG  |= (1<<7); //enable global interrupts in MC by setting the I-Bit.
	timer0_init_CTC_mode(250); // start the timer.
	while (1)
	{

	}
}


