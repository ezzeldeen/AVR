
#ifndef UART_H_
#define UART_H_

#include "micro_config.h"
#define USART_BAUDRATE 9600

#define DefaultStop '\r'


void UART_init(void);	///////////////////
void UART_sendByte(unsigned char data );	///////////////////
unsigned char UART_recieveByte(void);	///////////////////
void UART_sendString (const uint8 *Str) ;	///////////////////
void UART_receiveString (uint8 *Str);/////////////////

void UART_SendNumberU32(unsigned int num);
unsigned int UART_ReceiveNumberU32(void);
void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);
void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);
char* UART_SendString_Asynch( void);
void UART_Send_NoBlock (unsigned char data );

#endif /* UART_H_ */
