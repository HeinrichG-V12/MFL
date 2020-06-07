/*
 * spi.c
 *
 * Created: 27.01.2020 11:34:31
 *  Author: Heinrich
 */

#include "spi.h"

void spi_init(void)
{
	// spi master, 16 divider = 921,6kHz spi freq
	DDR_SPI |= (1 << DD_MOSI)|(1 << DD_SCK)|(1 << DD_CS);
	SELECT_CS();
	
	#ifdef AD5293
	SPCR |= (1 << SPE)|(1 << MSTR)|(0 << CPOL)|(1 << CPHA)|(1 << SPR0);	// SPI enable, Master mode, divider 16, cpol = 0, cpha = 1, msb first
	#endif // AD5293
	
	#ifdef MCP42050
	SPCR |= (1 << SPE)|(1 << MSTR)|(1 << SPR0);
	#endif // MCP42050
}

void spi_write (uint8_t data)
{
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
}

void spi_write16 (uint16_t data)
{
	SPDR = ((uint8_t) (data >> 8));
	while(!(SPSR & (1<<SPIF)));
	SPDR = ((uint8_t) (data));
	while(!(SPSR & (1<<SPIF)));
}