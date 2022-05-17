
#include "MemMap32.h"
#include "micro_config.h"
#include <util/delay.h>

int main(void)
{
	uint16 res_value;
	LCD_INIT(); /* initialize LCD driver */
	ADC_init(); /* initialize ADC driver */
	LCD_clearScreen(); /* clear LCD at the beginning */
	/* display this string "ADC Value = " only once at LCD */
	LCD_displayString("ADC Value = ");
    while(1)
    {
    	LCD_clearScreen(); /* clear LCD at the beginning */
    	LCD_displayString("ADC Value = ");

		LCD_goToRowColumn(1,10); /* display the number every time at this position */
		res_value = ADC_readChannel(0); /* read channel zero where the potentiometer is connect */
		LCD_intgerToString(res_value); /* display the ADC value on LCD screen */
		_delay_ms(500);
    }
}
