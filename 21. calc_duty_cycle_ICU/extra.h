///*
// * extra.h
// *
// *  Created on: Mar 14, 2022
// *      Author: Ezz Eldeen
// */
//
//#ifndef EXTRA_H_
//#define EXTRA_H_
//#include "MemMap32.h"
//#define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2
//
///* External INT0 Interrupt Service Routine */
//ISR(INT0_vect)
//{
//	PORTC = PORTC ^ (1<<0); //toggle led state
//}
//
///* External INT0 enable and configuration function */
//void INT0_Init(void)
//{
//	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
//	DDRD  &= (~(1<<2));               // Configure INT0/PD2 as input pin
//	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
//	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
//	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
//}
///*
//ISR(TIMER0_COMP_vect)
//{
//	g_tick++;
//	if(g_tick == NUMBER_OF_OVERFLOWS_PER_HALF_SECOND)
//	{
//		PORTC = PORTC ^ (1<<0); //toggle led every 0.5 second
//		g_tick = 0; //clear the tick counter again to count a new 0.5 second
//	}
//}
//*/
//void timer0_init_normal_mode(void)
//{
//	TCNT0 = 0; //timer initial value
//	TIMSK |= (1<<TOIE0); //enable overflow interrupt
//
//	/* Configure the timer control register
//	 * 1. Non PWM mode FOC0=1
//	 * 2. Normal Mode WGM01=0 & WGM00=0
//	 * 3. Normal Mode COM00=0 & COM01=0
//	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
//	 */
//	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
//	TCCR0 &= ~(1<<CS01) ;
//	TCCR0 &= ~(1<<WGM00) ;
//	TCCR0 &= ~(1<<COM00) ;
//	TCCR0 &= ~(1<<COM01) ;
//	TCCR0 &= ~(1<<WGM01) ;
//	SREG  |= (1<<7); //enable global interrupts in MC by setting the I-Bit.
//
//}/*
//ISR(TIMER0_COMP_vect)
//{
//	g_tick++;
//	if(g_tick == NUMBER_OF_OVERFLOWS_PER_HALF_SECOND)
//	{
//		PORTC = PORTC ^ (1<<0); //toggle led every 0.5 second
//		g_tick = 0; //clear the tick counter again to count a new 0.5 second
//	}
//}
//*/
//void timer0_init_CTC_mode(unsigned char tick)
//{
//	TCNT0 = 0; //timer initial value
//	OCR0  = tick; //compare value
//	TIMSK |= (1<<OCIE0); //enable compare interrupt
//	/* Configure timer0 control register
//	 * 1. Non PWM mode FOC0=1
//	 * 2. CTC Mode WGM01=1 & WGM00=0
//	 * 3. No need for OC0 so COM00=0 & COM01=0
//	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
//	 */
//	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS02) | (1<<CS00);
//}
//
////	function to enable Watchdog timer.
//void WDT_ON(void)
//{
//	// Watchdog timer enables with timeout period 2.1 second.
//	WDTCR = (1<<WDE)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0);
//}
//
//// 	function to disable Watchdog timer.
//void WDT_OFF(void)
//{
//	// set the WDTOE & WDE bits in the same operation
//	WDTCR = (1<<WDTOE)|(1<<WDE);
//	//wait 4 cycles before clear the WDE bit
//	_delay_us(4);
//	WDTCR = 0x00;
//}
//
///*******************************************************************************
// *                                 Key Pad                                     *
// *******************************************************************************/
//#include "keypad.h"
//int main(void)
//{
//	uint8 key;
//	DDRC  |= 0x0F; /* 7-segment pins as output pins */
//	PORTC &= 0xF0; /* 7-segment displays Zero at the beginning */
//    while(1)
//    {
//        key = KeyPad_getPressedKey(); /* get the pressed button from keypad */
//	    if((key >= 0) && (key <= 9))
//		{
//			 PORTC = key;
//		}
//    }
//}
//
//
//#endif /* EXTRA_H_ */











// ICU

//void APP_edgeProcessing(void)
//{
//	g_edgeCount++;
//	if(g_edgeCount == 1)
//	{
//		/*
//		 * Clear the timer counter register to start measurements from the
//		 * first detected rising edge
//		 */
//		Icu_clearTimerValue();
//		/* Detect falling edge */
//		Icu_setEdgeDetectionType(FALLING);
//	}
//	else if(g_edgeCount == 2)
//	{
//		/* Store the High time value */
//		g_timeHigh = Icu_getInputCaptureValue();
//		/* Detect rising edge */
//		Icu_setEdgeDetectionType(RISING);
//	}
//	else if(g_edgeCount == 3)
//	{
//		/* Store the Period time value */
//		g_timePeriod = Icu_getInputCaptureValue();
//		/* Detect falling edge */
//		Icu_setEdgeDetectionType(FALLING);
//	}
//	else if(g_edgeCount == 4)
//	{
//		/* Store the Period time value + High time value */
//		g_timePeriodPlusHigh = Icu_getInputCaptureValue();
//		/* Clear the timer counter register to start measurements again */
//		Icu_clearTimerValue();
//		/* Detect rising edge */
//		Icu_setEdgeDetectionType(RISING);
//	}
//}
//
//int main(void)
//{
//	uint32 dutyCycle = 0;
//
//		/* Create configuration structure for ICU driver */
//		Icu_ConfigType Icu_Config = {F_CPU_CLOCK,RISING};
//
//		/* Enable Global Interrupt I-Bit */
//		SREG |= (1<<7);
//
//		/* Set the Call back function pointer in the ICU driver */
//		Icu_setCallBack(APP_edgeProcessing);
//
//		/* Initialize both the LCD and ICU driver */
//		LCD_init();
//		Icu_init(&Icu_Config);
//
//		while(1)
//		{
//			if(g_edgeCount == 4)
//			{
//				Icu_DeInit(); /* Disable ICU Driver */
//				g_edgeCount = 0;
//				LCD_displayString("Duty = ");
//				/* calculate the dutyCycle */
//				dutyCycle = ((float)(g_timePeriodPlusHigh-g_timePeriod) / (g_timePeriodPlusHigh - g_timeHigh)) * 100;
//				/* display the dutyCycle on LCD screen */
//				LCD_intgerToString(dutyCycle);
//				LCD_displayCharacter('%');
//			}
//		}
//}
