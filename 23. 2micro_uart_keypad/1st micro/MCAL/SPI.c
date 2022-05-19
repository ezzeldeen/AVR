
/*
#include <avr/io.h>
#include <util/delay.h>

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

void SPI_MasterInit(void)
{
	// Set MOSI, SCK and SS output, all others input //
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);
	// Set MISO input //
	DDRB &= ~(1<<MISO);
	// Enable SPI, Master, set clock rate fck/16 //
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

unsigned char SPI_MasterTransmit(unsigned char cData)
{
	// Start transmission //
	SPDR = cData;
	// Wait for transmission complete //
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

int main(void)
{
    // Replace with your application code //
	unsigned char ch = 0;
	DDRA = 0xFF;
	SPI_MasterInit();
	for (ch = 0; ch <= 255; ch++)
	{
		_delay_ms(1000);
		PORTA = SPI_MasterTransmit(ch);
	}
}
*/
// ==================== Slave ==================== //

/*
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

void SPI_SlaveInit(void)
{
	// Set MISO output //
	DDRB |= (1<<MISO);
	// Set MOSI, SCK and SS input//
	DDRB &= ~(1<<MOSI) & ~(1<<SCK) & ~(1<<SS);
	// Enable SPI, Slave, set clock rate fck/16 //
	SPCR = (1<<SPE);
}

unsigned char SPI_SlaveRecieve(unsigned char cData)
{
	// Start transmission //
	SPDR = cData;
	// Wait for transmission complete //
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

int main(void)
{
    // Replace with your application code //
	unsigned char ch = 255;
	DDRA = 0xFF;
	SPI_SlaveInit();
	for (ch = 255; ch >= 0; ch--)
	{
		PORTA = SPI_SlaveRecieve(ch);
	}
}
*/
// ==================== 7 Segment * 8 ==================== //

/*
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SS 4
#define MOSI 5
#define SCK 7


void SPI_MasterInit()
{
	// Set MOSI, SCK and SS output//
	DDRB |= (1 << MOSI) | (1 << SS) | (1 << SCK);

	// Enable SPI, Master, set clock rate fck/16 //
	SPCR |= (1 << MSTR) | (1 << SPE) | (1 << SPR0);
}

void execute(unsigned char cmd, unsigned char data)
{
	PORTB &= ~(1 << SS);
	SPDR = cmd;
	while (!(SPSR & (1 << SPIF)));
	SPDR = data;
	while (!(SPSR & (1 << SPIF)));
	PORTB |= (1 << SS);
}

int main(void)
{
    // Replace with your application code //
	unsigned char counter = 0;
	unsigned char index_display;
	SPI_MasterInit();
	execute(0x09, 0xFF);
	execute(0x0A, 0xFF);
	execute(0x0B, 0xF7);
	execute(0x0C, 0x01);
    while (1)
    {
		for (index_display = 1; index_display < 9; index_display++)
			execute(index_display, counter++);
		_delay_ms(1000);
    }
}

*/
// ==================== General ==================== //
/*
void SPI_Init (void)
{
#if (SPI_MODE == MASTER)
	SPCR |= (1 << MSTR);
	SPCR &= (~ (1 << CPOL)) ;

#elif (SPI_MODE == SLAVE)
	SPCR &= (~ (1 << MSTR)) ;
#endif
	SPCR |= (1 << SPE) ;	// Enable SPI peripheral
	// speed 2mhz freq -> SPR1 - SPR0 =0 -> SPCR (FCPU / 4 )

}

unsigned char SPI_SendReceive(unsigned char data)
{
	SPDR = data;
	while(!(( SPSR >> SPIF)&1));
	return SPDR;
}

*/













