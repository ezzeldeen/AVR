
#include "lcd.h"

void LCD_clearScreen()
{
	LCD_sendCommand(CLEAR_COMMAND); //clear display
}

void LCD_lcd_kick()
{
	LCD_CTRL_PORT |= (1 << EN);
	_delay_ms(50);
	LCD_CTRL_PORT &= ~(1 << EN);
}

void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* 10 for decimal */
   LCD_displayString(buff);
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_goToRowColumn(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

void LCD_goToRowColumn(unsigned char row, unsigned char col)
{
	if (row == 1)
	{
		if (col < 16 && col >= 0)
		{
			LCD_sendCommand(SET_CURSOR_LOCATION+col);
		}
	}
	if (row == 2)
	{
		if (col < 16 && col >= 0)
		{
			LCD_sendCommand(LCD_BEGIN_AT_SECOND_ROW+col);
		}
	}
}

void LCD_INIT()
{
	LCD_DATA_PORT_DIR = 0xFF;  /* Configure the data port as output port */
	LCD_CTRL_PORT_DIR |= (1<<EN | 1<<RS | 1<<RW); /* Configure the control pins(E,RS,RW) as output pins */

	#ifdef EIGHT_BIT_MODE
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
	#endif

	#ifdef FOUR_BIT_MODE
		//LCD_sendCommand(0x02);		/* send for 4 bit initialization of LCD  */
		//LCD_sendCommand(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
		//LCD_sendCommand(0x0c);              /* Display on cursor off*/
		//LCD_sendCommand(0x06);              /* Increment cursor (shift cursor to right)*/
		//LCD_sendCommand(0x01);
	LCD_sendCommand(0x02);
	LCD_sendCommand(LCD_FUNCTION_4BIT_2LINES);
	#endif

	LCD_sendCommand(CURSOR_OFF); /* cursor off */
	LCD_sendCommand(CLEAR_COMMAND); /* clear LCD at the beginning */
}

void LCD_check_lcd_isbusy()
{
	LCD_DATA_PORT_DIR &= ~(0xFF<<DATA_shift);
	LCD_CTRL_PORT |= (1 << RW);
	LCD_CTRL_PORT &= ~(1 << RS);
	LCD_lcd_kick();
	LCD_DATA_PORT_DIR |= (0xFF<<DATA_shift);
	LCD_CTRL_PORT &= ~(1 << RW);
}

void LCD_sendCommand(unsigned char command)
{
	#ifdef EIGHT_BIT_MODE
		//LCD_check_lcd_isbusy();
		//LCD_DATA_PORT = command;
		//LCD_CTRL_PORT &= ~((1 << RS) | (1<<RW));
		//_delay_ms(1);
		//LCD_lcd_kick();
		CLEAR_BIT(LCD_CTRL_PORT,RS); /* Instruction Mode RS=0 */
		CLEAR_BIT(LCD_CTRL_PORT,RW); /* write data to LCD so RW=0 */
		_delay_ms(1); /* delay for processing Tas = 50ns */
		SET_BIT(LCD_CTRL_PORT,EN); /* Enable LCD E=1 */
		_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
		LCD_DATA_PORT = command; /* out the required command to the data bus D0 --> D7 */
		_delay_ms(1); /* delay for processing Tdsw = 100ns */
		CLEAR_BIT(LCD_CTRL_PORT,EN); /* disable LCD E=0 */
		_delay_ms(1); /* delay for processing Th = 13ns */
	#endif
	#ifdef FOUR_BIT_MODE
		LCD_check_lcd_isbusy();
		LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
		LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
		LCD_lcd_kick ();
		LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
		LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
		LCD_lcd_kick();
	#endif
}

void LCD_displayCharacter(unsigned char character)
{
	#ifdef EIGHT_BIT_MODE
		//LCD_check_lcd_isbusy();
		//LCD_DATA_PORT = character; /* out the required data char to the data bus D0 --> D7 */
		//LCD_CTRL_PORT &= ~(1 << RW);
		//LCD_CTRL_PORT |= (1 << RS);
		//_delay_ms(1);
		//LCD_lcd_kick();
		SET_BIT(LCD_CTRL_PORT,RS); /* Data Mode RS=1 */
		CLEAR_BIT(LCD_CTRL_PORT,RW); /* write data to LCD so RW=0 */
		_delay_ms(1); /* delay for processing Tas = 50ns */
		SET_BIT(LCD_CTRL_PORT,EN); /* Enable LCD E=1 */
		_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
		LCD_DATA_PORT = character; /* out the required data char to the data bus D0 --> D7 */
		_delay_ms(1); /* delay for processing Tdsw = 100ns */
		CLEAR_BIT(LCD_CTRL_PORT,EN); /* disable LCD E=0 */
		_delay_ms(1); /* delay for processing Th = 13ns */
	#endif

	#ifdef FOUR_BIT_MODE
		//LCD_check_lcd_isbusy();
		LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
		LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
		LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
		LCD_lcd_kick();
		LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
		LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
		LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
		LCD_lcd_kick ();
	#endif
}

void LCD_displayString(char* string)
{
	unsigned int count = 0;
	while (*string > 0)
	{
		count++;
		LCD_displayCharacter(*string++);
		if (count == 16)
		{
			LCD_goToRowColumn(2,0);
		}
		else if (count == 32)
		{
			LCD_clearScreen();
			LCD_goToRowColumn(1,0);
			count = 0;
		}
	}
}

void LCD_display_number (int num)
{
	char str[7];
	sprintf(str,"%d",num);
	LCD_displayString(str);
}

void LCD_display_real_number (double num)
{
	char str[16];
	char *tmpSign = (num <0)? "-" : "";
	float tmpVal = (num <0)? -num : num;
	int tmpInt1 = tmpVal;
	float tmpFrac = tmpVal - tmpInt1;
	int tmpInt2 = tmpFrac * 10000;
	sprintf(str, "%s%d.%04d", tmpSign, tmpInt1, tmpInt2);
	LCD_displayString(str);
}
