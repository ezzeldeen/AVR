/*
 *
 * Toggle LED every half second with timer0 normal mode
 * Ezz
 *
 */

#include "MemMap32.h"
//#include <util/delay.h>

#define F_CPU 1000000UL
#define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2
unsigned char g_tick = 0;

ISR(TIMER0_OVF_vect)
{
	g_tick++;
	if(g_tick == NUMBER_OF_OVERFLOWS_PER_HALF_SECOND)
	{
		PORTC ^= (1<<0); //toggle led every 0.5 second
		g_tick = 0; //clear the tick counter again to count a new 0.5 second
	}
}

void timer0_init_normal_mode(void)
{
	TCNT0 = 0; //timer initial value
	TIMSK |= (1<<TOIE0); //enable overflow interrupt

	/* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
	TCCR0 &= ~(1<<CS01) ;
	TCCR0 &= ~(1<<WGM00) ;
	TCCR0 &= ~(1<<COM00) ;
	TCCR0 &= ~(1<<COM01) ;
	TCCR0 &= ~(1<<WGM01) ;
	SREG  |= (1<<7); //enable global interrupts in MC by setting the I-Bit.

}



int main()
{

	DDRC  |= (1<<0); //configure the led pin to be output pin.
	PORTC &= ~(1<<0); //LED is off at the beginning(Positive Logic).
	timer0_init_normal_mode(); //start the timer.
	while (1)
	{

	}
}


