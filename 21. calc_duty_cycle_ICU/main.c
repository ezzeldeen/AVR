
#include "MemMap32.h"
#include "micro_config.h"
#include <util/delay.h>
#include <avr/interrupt.h>


uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;
uint16 g_timePeriod = 0;
uint16 g_timePeriodPlusHigh = 0;

void APP_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		Icu_clearTimerValue();
		/* Detect falling edge */
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeHigh = Icu_getInputCaptureValue();
		/* Detect rising edge */
		Icu_setEdgeDetectionType(RISING);
	}
	else if(g_edgeCount == 3)
	{
		/* Store the Period time value */
		g_timePeriod = Icu_getInputCaptureValue();
		/* Detect falling edge */
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 4)
	{
		/* Store the Period time value + High time value */
		g_timePeriodPlusHigh = Icu_getInputCaptureValue();
		/* Clear the timer counter register to start measurements again */
		Icu_clearTimerValue();
		/* Detect rising edge */
		Icu_setEdgeDetectionType(RISING);
	}
}

int main(void)
{
	uint32 dutyCycle = 0;
	uint32 period = 0;
	uint32 freq = 0;

	/* Create configuration structure for ICU driver */
	Icu_ConfigType Icu_Config = {F_CPU_CLOCK,RISING};

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* Set the Call back function pointer in the ICU driver */
	Icu_setCallBack(APP_edgeProcessing);

	/* Initialize both the LCD and ICU driver */
	LCD_init();
	Icu_init(&Icu_Config);

	while(1)
	{
		if(g_edgeCount == 4)
		{
			Icu_DeInit(); /* Disable ICU Driver */
			g_edgeCount = 0;
			LCD_displayString("Duty = ");
			/* calculate the dutyCycle */
			dutyCycle = ((float)(g_timePeriodPlusHigh-g_timePeriod) / (g_timePeriodPlusHigh - g_timeHigh)) * 100;
			/* display the dutyCycle on LCD screen */
			LCD_intgerToString(dutyCycle);
			LCD_displayCharacter('%');

			LCD_goToRowColumn(1,0);
			LCD_displayString("Period = ");
			period = ((g_timePeriodPlusHigh - g_timeHigh) / 1000);
			/* display the period on LCD screen */
			LCD_intgerToString(period);
			LCD_displayString(" MiliS");
			_delay_ms(1000);

			LCD_goToRowColumn(1,0);
			LCD_displayString("freq = ");
			/* calculate the freq */
			freq = 1000000 / (g_timePeriodPlusHigh - g_timeHigh);;
			/* display the freq on LCD screen */
			LCD_intgerToString(freq);
			LCD_displayString(" Hz   ");
		}
	}
}
