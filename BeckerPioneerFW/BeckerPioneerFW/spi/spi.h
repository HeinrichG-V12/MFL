/*
 * spi.h
 *
 * Created: 27.01.2020 11:34:46
 *  Author: Heinrich
 */ 

#include <avr/io.h>
#include <stdint.h>

#ifndef SPI_H_
#define SPI_H_

#define DDR_CS			DDRB
#define DD_CS			PB0
#define DDR_SPI			DDRB
#define DD_MOSI			PB2
#define DD_SCK			PB1

#define SELECT_CS()		(PORTB |= (1 << DD_CS))
#define DESELECT_CS()	(PORTB &= ~(1 << DD_CS))

void spi_init(void);
void spi_write (uint8_t data);

#endif /* SPI_H_ */