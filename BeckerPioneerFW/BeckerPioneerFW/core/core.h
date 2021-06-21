/*
 * core.h
 *
 * Created: 20.06.2021 20:08:32
 *  Author: Heinrich
 */ 

#include <avr/io.h>

#ifndef CORE_H_
#define CORE_H_

// digipot ports and pins
#define MCP_HW_INT			DDRB
#define MCP_HW_INT_PORT		PORTB
#define RING				PB4
#define MCP_SHDN			PB5
#define MCP_RST				PB6

// spi ports and pins
#define DDR_CS				DDRB
#define DDR_SPI				DDRB
#define DD_CS				PB0
#define DD_SCK				PB1
#define DD_MOSI				PB2

void ports_pins_init (void);



#endif /* CORE_H_ */