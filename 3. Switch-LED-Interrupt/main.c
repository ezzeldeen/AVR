/*
 *
 * control LED with external interrupt
 * Ezz
 *
 */
#include "MemMap32.h"
#include <util/delay.h>
#define F_CPU 8000000UL



/* External INT0 Interrupt Service Routine */
ISR(INT0_vect)
{
	PORTC = PORTC ^ (1<<0); //toggle led state
}

/* External INT0 enable and configuration function */
void INT0_Init(void)
{
	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<2));               // Configure INT0/PD2 as input pin
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}



int main()
{


	INT0_Init();              // Enable external INT0

	DDRC  = DDRC | (1<<0);  // Configure pin0 in PORTC as output pin
	PORTC = PORTC | (1<<0); // Initialization Led is off at the beginning(Negative Logic)

	while (1)
	{

	}
	return 0;
}


