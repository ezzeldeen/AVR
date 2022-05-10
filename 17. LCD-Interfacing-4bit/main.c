
#include "MemMap32.h"
#include "micro_config.h"
#include <util/delay.h>

int main(void)
{
	LCD_INIT(); /* initialize LCD */
	LCD_displayStringRowColumn(1,3,"EZZ Eldeen!");
	LCD_displayStringRowColumn(2,3,"Embedded WS");
	_delay_ms(4000); /* wait four seconds */

	LCD_clearScreen(); /* clear the LCD display */
	while(1)
	{

	}
}

