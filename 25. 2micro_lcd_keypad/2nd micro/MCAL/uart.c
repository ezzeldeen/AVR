
#include <uart.h>

#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 8UL))) - 1)
static unsigned char * TX_Str;
static unsigned char flag_send =1;

//////////////////////////////////////////////////
void UART_init(void)
{
	/* U2X = 1 for double transmission speed */
	UCSRA = (1<<U2X);
	//CLEAR_BIT(UCSRA, U2X); // normal mode

	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * RXEN  = 1 Transmitter Enable
	 * UCSZ2 = 0 For 8-bit data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/
	UCSRB = (1<<RXEN) | (1<<TXEN);

	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = 0 Asynchronous Operation
	 * UPM1:0  = 00 Disable parity bit
	 * USBS    = 0 One stop bit
	 * UCSZ1:0 = 11 For 8-bit data mode
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = BAUD_PRESCALE>>8;
	UBRRL = BAUD_PRESCALE;
}

//////////////////////////////////////////////////
void UART_sendByte(unsigned char data )
{
	/* UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte so wait until this flag is set to one */
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}
	/* Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now */
	UDR = data;
}

/////////////////////////////////////////////////
unsigned char UART_recieveByte(void)
{
	/* RXC flag is set when the UART receive data so wait until this
		 * flag is set to one */
	while(BIT_IS_CLEAR(UCSRA,RXC)){}
	/* Read the received data from the Rx buffer (UDR) and the RXC flag
		  will be cleared after read this data */
	return UDR ;
}

/////////////////////////////////////////////////
void UART_sendString (const uint8 *Str)
{
	uint8 i = 0;
		while(Str[i] != '\0')
		{
			UART_sendByte(Str[i]);
			i++;
		}
		UART_sendByte(DefaultStop) ;
}

/////////////////////////////////////////////////
void UART_receiveString (uint8 *Str)
{
	uint8 i = 0;
	Str[i] = UART_recieveByte();
	while(Str[i] != DefaultStop)
	{
		i++;
		Str[i] = UART_recieveByte();
	}
	Str[i] = '\0';
}



void UART_Send_NoBlock (unsigned char data )
{
	UDR = data ;
}

unsigned char UART_Receive_NoBlock(void)
{
	return UDR ;
}

void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB, RXCIE);
}

void UART_RX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB, RXCIE);
}

void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB, TXCIE);
}

void UART_TX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB, TXCIE);
}
void UART_SendNumberU32(unsigned int num)
{

	// UART_Send(num);
	// UART_Send(num>>8);
	// UART_Send(num>>16);
	// UART_Send(num>>24);

	unsigned char  *ptr = (unsigned char  *) &num;
	UART_sendByte(ptr[0]);
	UART_sendByte(ptr[1]);
	UART_sendByte(ptr[2]);
	UART_sendByte(ptr[3]);

}

unsigned int UART_ReceiveNumberU32(void)
{

	//u8 b1= UART_Receive();
	//u8 b2= UART_Receive();
	//u8 b3= UART_Receive();
	//u8 b4= UART_Receive();

	//u32 num1=0;
	// num = b1| (u32)b2<<8 | (u32)b3<<16 | (u32)b4<<24;

	unsigned int num;
	unsigned char *p = (unsigned char  *)&num;
	p[0] = UART_recieveByte();
	p[1] = UART_recieveByte();
	p[2] = UART_recieveByte();
	p[3] = UART_recieveByte();
	return num;
}

char* UART_Receive_Periodic_String (void)
{
	char* p_str ;

	if( READ_BIT(UCSRA,RXC) )
	{
		*p_str = UDR;
		return p_str ;

	}
	return 0;
}

char* UART_SendString_Asynch( void)
{
	char* p_str ;
	if(flag_send == 1)
	{
		UART_TX_InterruptEnable();
		UART_Send_NoBlock(p_str[0]);
		TX_Str = p_str;
		flag_send = 0;
	}
	return p_str ;

}
