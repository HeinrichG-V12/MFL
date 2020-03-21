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

void spi_init(void);
void spi_write (uint8_t data);
uint8_t spi_write_read (uint8_t data);

#endif /* SPI_H_ */