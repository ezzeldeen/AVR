/*
 *
 * Control the brightness of LED with timer0 FastPWM 
 * Ezz
 *
 */

#include "MemMap32.h"
//#include <util/delay.h>

#define F_CPU 8000000UL
#include <util/delay.h>

volatile unsigned char duty=128;

ISR(INT0_vect)
{
	duty += 20;
}


void Timer0_PWM_Init(unsigned char set_duty_cycle)
{
	TCNT0 = 0; //timer initial value
	OCR0  = set_duty_cycle; //compare value
	DDRB  = DDRB | (1<<3); //set OC0 as output pin --> pin where the PWM signal is
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
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



	while (1)
	{
		Timer0_PWM_Init(duty); //50% duty cycle
		_delay_ms(100);
		//duty+=50;
	}
}


