/*
 * spi.h
 *
 * Created: 27.01.2020 11:34:46
 *  Author: Heinrich
 */ 

#include <avr/io.h>
#include <stdint.h>
#include "../core/core.h"

#ifndef SPI_H_
#define SPI_H_

#define SELECT_CS()		(PORTB |= (1 << DD_CS))
#define DESELECT_CS()	(PORTB &= ~(1 << DD_CS))

void spi_init(void);
void spi_write (uint8_t data);

#endif /* SPI_H_ */