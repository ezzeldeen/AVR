
#ifndef macros_H_
#define macros_H_

#define SET_BIT(REG, BIT_NUM) (REG |= (1<<BIT_NUM)) // set bit in reg.
#define CLEAR_BIT(REG, BIT_NUM) (REG &= (~(1<<BIT_NUM))) // clear bit in reg.
#define TOGGLE_BIT(REG, BIT_NUM) (REG ^= (1<<BIT_NUM)) // toggle bit in reg.
#define ROR(REG, BIT_NUM) (REG = (REG >> BIT_NUM) | (REG << (8 - BIT_NUM))) // rotate bits right in reg.
#define ROL(REG, BIT_NUM) (REG = (REG << BIT_NUM) | (REG >> (8 - BIT_NUM))) // rotate bits left in reg.
#define BIT_IS_SET(REG, BIT_NUM) (REG & (1<<BIT_NUM)) // check if bit is set
#define BIT_IS_CLEAR(REG, BIT_NUM) (!(REG & (1<<BIT_NUM))) // check if bit is clear
#define READ_BIT(REG, BIT_NUM) ((REG & (1<<BIT_NUM)) >>BIT_NUM)

/*
#define REG_MCU *(volatile unsigned int *) (MCU_BASE + 0x1c)
// #define UART0 *((volatile unsigned int * const ) ((unsigned int *) 0x11f1000))  // const pointer to volatile reg = address
// #define REG *((volatile unsigned int *) 0x11f1000) , *((volatile unsigned int * )(0x11f1000)) = 0xfff1

   printf("File :%s\n", __FILE__ );	// This contains the current filename as a string literal.
   printf("Date :%s\n", __DATE__ );	// The current date as a character literal in "MMM DD YYYY" format.
   printf("Time :%s\n", __TIME__ );	// The current time as a character literal in "HH:MM:SS" format.
   printf("Line :%d\n", __LINE__ );	// This contains the current line number as a decimal constant.
   printf("ANSI :%d\n", __STDC__ );	// Defined as 1 when the compiler complies with the ANSI standard.
#define  message_for(a, b)   printf(#a " and " #b ": We love you!\n")
   message_for(Carole, Debra); // Carole and Debra: We love you!
*/

/* Define Generic PORTn, DDn, and PINn values. */
#define PIND0   0
#define PIND1   1
#define PIND2   2
#define PIND3   3
#define PIND4   4
#define PIND5   5
#define PIND6   6
#define PIND7   7

#define DDD0    0
#define DDD1    1
#define DDD2    2
#define DDD3    3
#define DDD4    4
#define DDD5    5
#define DDD6    6
#define DDD7    7

#define PD0     0
#define PD1     1
#define PD2     2
#define PD3     3
#define PD4     4
#define PD5     5
#define PD6     6
#define PD7     7

#define PINC0   0
#define PINC1   1
#define PINC2   2
#define PINC3   3
#define PINC4   4
#define PINC5   5
#define PINC6   6
#define PINC7   7

#define DDC0    0
#define DDC1    1
#define DDC2    2
#define DDC3    3
#define DDC4    4
#define DDC5    5
#define DDC6    6
#define DDC7    7

#define PC0     0
#define PC1     1
#define PC2     2
#define PC3     3
#define PC4     4
#define PC5     5
#define PC6     6
#define PC7     7

#define PINB0   0
#define PINB1   1
#define PINB2   2
#define PINB3   3
#define PINB4   4
#define PINB5   5
#define PINB6   6
#define PINB7   7

#define DDB0    0
#define DDB1    1
#define DDB2    2
#define DDB3    3
#define DDB4    4
#define DDB5    5
#define DDB6    6
#define DDB7    7

#define PB0     0
#define PB1     1
#define PB2     2
#define PB3     3
#define PB4     4
#define PB5     5
#define PB6     6
#define PB7     7

#define PINA0   0
#define PINA1   1
#define PINA2   2
#define PINA3   3
#define PINA4   4
#define PINA5   5
#define PINA6   6
#define PINA7   7

#define DDA0    0
#define DDA1    1
#define DDA2    2
#define DDA3    3
#define DDA4    4
#define DDA5    5
#define DDA6    6
#define DDA7    7

#define PA0     0
#define PA1     1
#define PA2     2
#define PA3     3
#define PA4     4
#define PA5     5
#define PA6     6
#define PA7     7

/* Port Data Register (generic) */
#define    PORT7        7
#define    PORT6        6
#define    PORT5        5
#define    PORT4        4
#define    PORT3        3
#define    PORT2        2
#define    PORT1        1
#define    PORT0        0

/* Port Data Direction Register (generic) */
#define    DD7          7
#define    DD6          6
#define    DD5          5
#define    DD4          4
#define    DD3          3
#define    DD2          2
#define    DD1          1
#define    DD0          0

/* Port Input Pins (generic) */
#define    PIN7         7
#define    PIN6         6
#define    PIN5         5
#define    PIN4         4
#define    PIN3         3
#define    PIN2         2
#define    PIN1         1
#define    PIN0         0

/* Define PORTxn an Pxn values for all possible port pins if not defined already by io.h. */

/* PORT A */

#if defined(PA0) && !defined(PORTA0)
#  define PORTA0 PA0
#elif defined(PORTA0) && !defined(PA0)
#  define PA0 PORTA0
#endif
#if defined(PA1) && !defined(PORTA1)
#  define PORTA1 PA1
#elif defined(PORTA1) && !defined(PA1)
#  define PA1 PORTA1
#endif
#if defined(PA2) && !defined(PORTA2)
#  define PORTA2 PA2
#elif defined(PORTA2) && !defined(PA2)
#  define PA2 PORTA2
#endif
#if defined(PA3) && !defined(PORTA3)
#  define PORTA3 PA3
#elif defined(PORTA3) && !defined(PA3)
#  define PA3 PORTA3
#endif
#if defined(PA4) && !defined(PORTA4)
#  define PORTA4 PA4
#elif defined(PORTA4) && !defined(PA4)
#  define PA4 PORTA4
#endif
#if defined(PA5) && !defined(PORTA5)
#  define PORTA5 PA5
#elif defined(PORTA5) && !defined(PA5)
#  define PA5 PORTA5
#endif
#if defined(PA6) && !defined(PORTA6)
#  define PORTA6 PA6
#elif defined(PORTA6) && !defined(PA6)
#  define PA6 PORTA6
#endif
#if defined(PA7) && !defined(PORTA7)
#  define PORTA7 PA7
#elif defined(PORTA7) && !defined(PA7)
#  define PA7 PORTA7
#endif

/* PORT B */

#if defined(PB0) && !defined(PORTB0)
#  define PORTB0 PB0
#elif defined(PORTB0) && !defined(PB0)
#  define PB0 PORTB0
#endif
#if defined(PB1) && !defined(PORTB1)
#  define PORTB1 PB1
#elif defined(PORTB1) && !defined(PB1)
#  define PB1 PORTB1
#endif
#if defined(PB2) && !defined(PORTB2)
#  define PORTB2 PB2
#elif defined(PORTB2) && !defined(PB2)
#  define PB2 PORTB2
#endif
#if defined(PB3) && !defined(PORTB3)
#  define PORTB3 PB3
#elif defined(PORTB3) && !defined(PB3)
#  define PB3 PORTB3
#endif
#if defined(PB4) && !defined(PORTB4)
#  define PORTB4 PB4
#elif defined(PORTB4) && !defined(PB4)
#  define PB4 PORTB4
#endif
#if defined(PB5) && !defined(PORTB5)
#  define PORTB5 PB5
#elif defined(PORTB5) && !defined(PB5)
#  define PB5 PORTB5
#endif
#if defined(PB6) && !defined(PORTB6)
#  define PORTB6 PB6
#elif defined(PORTB6) && !defined(PB6)
#  define PB6 PORTB6
#endif
#if defined(PB7) && !defined(PORTB7)
#  define PORTB7 PB7
#elif defined(PORTB7) && !defined(PB7)
#  define PB7 PORTB7
#endif

/* PORT C */

#if defined(PC0) && !defined(PORTC0)
#  define PORTC0 PC0
#elif defined(PORTC0) && !defined(PC0)
#  define PC0 PORTC0
#endif
#if defined(PC1) && !defined(PORTC1)
#  define PORTC1 PC1
#elif defined(PORTC1) && !defined(PC1)
#  define PC1 PORTC1
#endif
#if defined(PC2) && !defined(PORTC2)
#  define PORTC2 PC2
#elif defined(PORTC2) && !defined(PC2)
#  define PC2 PORTC2
#endif
#if defined(PC3) && !defined(PORTC3)
#  define PORTC3 PC3
#elif defined(PORTC3) && !defined(PC3)
#  define PC3 PORTC3
#endif
#if defined(PC4) && !defined(PORTC4)
#  define PORTC4 PC4
#elif defined(PORTC4) && !defined(PC4)
#  define PC4 PORTC4
#endif
#if defined(PC5) && !defined(PORTC5)
#  define PORTC5 PC5
#elif defined(PORTC5) && !defined(PC5)
#  define PC5 PORTC5
#endif
#if defined(PC6) && !defined(PORTC6)
#  define PORTC6 PC6
#elif defined(PORTC6) && !defined(PC6)
#  define PC6 PORTC6
#endif
#if defined(PC7) && !defined(PORTC7)
#  define PORTC7 PC7
#elif defined(PORTC7) && !defined(PC7)
#  define PC7 PORTC7
#endif

/* PORT D */

#if defined(PD0) && !defined(PORTD0)
#  define PORTD0 PD0
#elif defined(PORTD0) && !defined(PD0)
#  define PD0 PORTD0
#endif
#if defined(PD1) && !defined(PORTD1)
#  define PORTD1 PD1
#elif defined(PORTD1) && !defined(PD1)
#  define PD1 PORTD1
#endif
#if defined(PD2) && !defined(PORTD2)
#  define PORTD2 PD2
#elif defined(PORTD2) && !defined(PD2)
#  define PD2 PORTD2
#endif
#if defined(PD3) && !defined(PORTD3)
#  define PORTD3 PD3
#elif defined(PORTD3) && !defined(PD3)
#  define PD3 PORTD3
#endif
#if defined(PD4) && !defined(PORTD4)
#  define PORTD4 PD4
#elif defined(PORTD4) && !defined(PD4)
#  define PD4 PORTD4
#endif
#if defined(PD5) && !defined(PORTD5)
#  define PORTD5 PD5
#elif defined(PORTD5) && !defined(PD5)
#  define PD5 PORTD5
#endif
#if defined(PD6) && !defined(PORTD6)
#  define PORTD6 PD6
#elif defined(PORTD6) && !defined(PD6)
#  define PD6 PORTD6
#endif
#if defined(PD7) && !defined(PORTD7)
#  define PORTD7 PD7
#elif defined(PORTD7) && !defined(PD7)
#  define PD7 PORTD7
#endif




#endif /* macros_H_ */
