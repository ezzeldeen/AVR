/*
 *
 * Control motor with adjustable wave form to change speed
 * Ezz
 *
 */

#include "MemMap32.h"
#include <util/delay.h>
#define F_CPU 8000000UL
volatile unsigned char duty=128;


void PWM_Timer0_Init(unsigned char set_duty_cycle)
{
	TCNT0 = 0; //timer initial value
	OCR0  = set_duty_cycle; //compare value
	DDRB  = DDRB | (1<<3); //set OC0 as output pin --> pin where the PWM signal is
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
void (*ptr_func) (unsigned char) = PWM_Timer0_Init;

ISR(INT0_vect)
{
	duty += 64;
	ptr_func(duty);
}

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
	PWM_Timer0_Init(128); //generate duty cycle 50% to get half motor speed

		DDRA = DDRA & (~(1<<0)); // configure pin 0 of PORTA as input pin
		DDRA = DDRA & (~(1<<1)); // configure pin 1 of PORTA as input pin
		DDRA = DDRA & (~(1<<2)); // configure pin 2 of PORTA as input pin
		DDRC = DDRC | (1<<0);    // configure pin 3 of PORTC as output pin
		DDRC = DDRC | (1<<1);    // configure pin 4 of PORTC as output pin

		//Motor is stop at the beginning
		PORTC &= ~((1<<0) | (1<<1));

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


