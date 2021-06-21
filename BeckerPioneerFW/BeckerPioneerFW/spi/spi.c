/*
 * spi.c
 *
 * Created: 27.01.2020 11:34:31
 *  Author: Heinrich
 */

#include "spi.h"

void spi_init(void)
{
	SELECT_CS();
	// spi master, 2 divider = 8MHz spi freq
	//SPCR |= (1 << SPE)|(1 << MSTR)|(1 << SPI2X);
	
	// spi master, 2 divider = 8MHz spi freq (mcp42xxx max 10mhz )
	SPCR |= (1 << SPE)|(1 << MSTR);
	SPSR |= (1 << SPI2X); // f_cpu / 2
}

void spi_write (uint8_t data)
{
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
}