/*
 * macros.h
 *
 *  Created on: Jan 9, 2022
 *      Author: Ezz Eldeen
 */

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





#endif /* macros_H_ */
