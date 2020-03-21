/*
 * spi.c
 *
 * Created: 27.01.2020 11:34:31
 *  Author: Heinrich
 */

#include "spi.h"

void spi_init(void)
{
	// spi master, 128 divider
	SPCR |= (1 << SPE)|(1 << MSTR)|(1 << SPR1)|(1 << SPR0);
	
}

void spi_write (uint8_t data)
{
	while(!(SPSR & (1<<SPIF)));
	SPDR=data;
}

uint8_t spi_write_read (uint8_t data)
{
	while(!(SPSR & (1<<SPIF)));
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}