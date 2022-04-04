/*
 *
 * Enable watchDog to reset before executing the main to loop
 * Ezz
 *
 */

#include "MemMap32.h"
#include <util/delay.h>

#define F_CPU 8000000UL

//	function to enable Watchdog timer.
void WDT_ON(void)
{
	// Watchdog timer enables with timeout period 2.1 second.
	WDTCR = (1<<WDE)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0);
}

// 	function to disable Watchdog timer.
void WDT_OFF(void)
{
	// set the WDTOE & WDE bits in the same operation
	WDTCR = (1<<WDTOE)|(1<<WDE);
	//wait 4 cycles before clear the WDE bit
	_delay_us(4);
	WDTCR = 0x00;
}


int main()
{
	// Enable the Watchdog timer
		WDT_ON();

		// Configure PD6 as output pin
		DDRD |= (1<<6);

		// Toggle the led every reset
		PORTD |= (1<<6);
		_delay_ms(1000);
		PORTD &= ~(1<<6);

		// Wait until the system reset itself
	while (1)
	{

	}
}


