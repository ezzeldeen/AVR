/*
 *
 *
 * Ezz
 *
 */

#include "MemMap32.h"
#include <util/delay.h>

#define F_CPU 8000000UL



int main()
{
	/* configure pin PA0, PA1 and PA2 as input pins */
	DDRA &= ~(1<<0);
	DDRA &= ~(1<<1);
	DDRA &= ~(1<<2);

	/* configure pin PC0 and PC1 as output pins */
	DDRC |= (1<<0);
	DDRC |= (1<<1);

	/* Motor is stop at the beginning */
	PORTC &= ~(1<<0);
	PORTC &= ~(1<<1);

	// Wait until the system reset itself
	while (1)
	{
		/* check if the first switch is pressed (Rotate clock wise) */
		if(PINA & (1<<0))
		{
			PORTC &= (~(1<<0));
			PORTC |= (1<<1);
		}

		/* check if the second switch is pressed (Rotate anti-clock wise) */
		else if(PINA & (1<<1))
		{
			PORTC |= (1<<0);
			PORTC &= (~(1<<1));
		}

		/* check if the third switch is pressed (turn off the motor) */
		else if(PINA & (1<<2))
		{
			PORTC &= (~(1<<0));
			PORTC &= (~(1<<1));
		}
	}
}


