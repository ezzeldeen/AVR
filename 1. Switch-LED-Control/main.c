/*
 *
 * Switch LED control
 * Ezz
 *
 */
#include "MemMap32.h"
#define F_CPU 8000000UL

int main()
{
	// switch conntected to PIN3 PORTA
	DDRA &= ~(1<<3); // pin is input

	// LED conntected to PIN5 PORTC
	DDRC |= (1<<5); // pin is output
	PORTC &= ~(1<<5); // LED OFF

	while (1)
	{
		if (PINA & (1<<3)) // check if switch is pressed
		{
			PORTC |= (1<<5); // LED ON

		}
		else
		{
			PORTC &= ~(1<<5); // LED OFF

		}
	}

}


