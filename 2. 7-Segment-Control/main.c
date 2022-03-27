/*
 *
 * control 7 segment using push button
 * Ezz
 *
 */
#include "MemMap32.h"
#include <util/delay.h>
#define F_CPU 8000000UL

int main()
{
	unsigned char num = 0;
	DDRD  = DDRD & (~(1<<4)); // configure pin 4 in PORTD as input pin
	DDRC |= 0x0F; // configure first four pins of PORTC as output pins

	// initialize the 7-segment
	PORTC &= ~((1<<0) | (1<<1) | (1<<2) | (1<<3));

	while (1)
	{
		// check if the push button is pressed or not
		if( PIND & (1<<4) )
		{
			_delay_ms(30);
			//second check due to switch bouncing
			if( PIND & (1<<4) )
			{
				if((PORTC & 0x0F) == 9)
				{
					// if overflow occurs
					num = 0;
					PORTC = (PORTC & 0xF0) | (num & 0x0F);
				}
				else
				{
					// increment 7-segment every press
					num++;
					PORTC = (PORTC & 0xF0) | (num & 0x0F);
				}
			}
			while( PIND & (1<<4) ){} // wait until switch is released
		}
	}
	return 0;
}


