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
	SPCR |= (1 << SPE)|(1 << MSTR)|(1 << SPR0);
}

void spi_write (uint8_t data)
{
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
}