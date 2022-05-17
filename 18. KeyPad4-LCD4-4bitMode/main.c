
#include "MemMap32.h"
#include "micro_config.h"
#include <util/delay.h>

int main(void)
{


	unsigned char key;
		LCD_INIT();
		LCD_displayStringRowColumn(0,0,"EZZ Eldeen!");
		LCD_displayStringRowColumn(1,0,"Keypad 4x4");
		//LCD_clearScreen(); /* clear the LCD display */

		LCD_displayStringRowColumn(2,0,"LCD");
		LCD_goToRowColumn(3,0);
	while(1)
	{
		/* if any switch pressed for more than 500 ms it counts more than one press */
				key = Keypad_getkey(); /* get the pressed key number */
				if((key <= 9) && (key >= 0))
				{
					LCD_intgerToString(key); /* display the pressed keypad switch */
				}
				else
				{
					LCD_displayCharacter(key); /* display the pressed keypad switch */
				}
				_delay_ms(500); /* Press time */
	}
}

