
#include "micro_config.h"
#define M2_READY 0x10


int main(void)
{

	uint8 key;
	UART_init();
    while(1)
    {
		key = KeyPad_getPressedKey(); //get the pressed key
		UART_sendByte(key); //send the pressed key to the second MC using uart
		_delay_ms(500);
    }
}
