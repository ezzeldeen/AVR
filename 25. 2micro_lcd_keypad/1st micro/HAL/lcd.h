
#ifndef LCD_H_
#define LCD_H_

#include "MemMap32.h"
#include "std_types.h"
#include "macros.h"
#include "micro_config.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define DATA_BITS_MODE 8

/* Use higher 4 bits in the data port */
#if (DATA_BITS_MODE == 4)
// #define UPPER_PORT_PINS
#endif

/* LCD HW Pins */
#define RS PD4
#define RW PD5
#define EN PD6
#define LCD_CTRL_PORT PORTD
#define LCD_CTRL_PORT_DIR DDRD

#define LCD_DATA_PORT PORTC
#define LCD_DATA_PORT_DIR DDRC

/* LCD Commands */
#define CLEAR_COMMAND								(0x01)
#define FOUR_BITS_DATA_MODE 						(0x02)
#define TWO_LINE_LCD_Eight_BIT_MODE   				(0x38)
#define CURSOR_OFF   								(0x0C)
#define CURSOR_ON   								(0x0E)
#define SET_CURSOR_LOCATION							(0x80) // first location row 1
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_ENTRY_MODE								(0x06)

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void LCD_init();
void LCD_sendCommand(unsigned char command);
void LCD_displayCharacter(unsigned char character);
void LCD_displayString(char* string);
void LCD_check_lcd_isbusy(void);
void LCD_lcd_kick(void);
void LCD_clearScreen(void);
void LCD_goToRowColumn(unsigned char row, unsigned char col);
void LCD_display_number (int num);
void LCD_display_real_number (double num);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_intgerToString(int data);
#endif /* LCD_H_ */

/*
int main(void)
{
	LCD_init(); // initialize LCD
	LCD_displayStringRowColumn(0,2,"My LCD Driver");
	LCD_displayStringRowColumn(1,3,"Embedded WS");
	_delay_ms(4000); // wait four seconds

	LCD_clearScreen(); // clear the LCD display
	LCD_displayString("Interf. Course");
    LCD_displayStringRowColumn(1,5,"Group ");
    LCD_intgerToString(32);

    while(1)
    {
		// Note: we write the code before while(1) because we want to execute it only once
    }
}
*/
