/*
 * spi.c
 *
 * Created: 27.01.2020 11:34:31
 *  Author: Heinrich
 */

#include "spi.h"

void spi_init(void)
{
	DDR_SPI |= (1 << DD_MOSI)|(1 << DD_SCK)|(1 << DD_CS);
	SELECT_CS();
	// spi master, 2 divider = 8MHz spi freq
	//SPCR |= (1 << SPE)|(1 << MSTR)|(1 << SPI2X);
	
	// spi master, 4 divider = 4MHz spi freq
	SPCR |= (1 << SPE)|(1 << MSTR);
}

void spi_write (uint8_t data)
{
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
}