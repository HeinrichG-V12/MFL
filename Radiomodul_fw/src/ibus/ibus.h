/*
 * ibus.h
 *
 *  Created on: 30.10.2019
 *      Author: heinrich
 */

#ifndef IBUS_IBUS_H_
#define IBUS_IBUS_H_

#include <stdint.h>
#include <LPC13xx.h>
#include "../uart/uart.h"
#include <stdlib.h>

#define RX_BUFFER_SIZE	5
#define TX_BUFFER_SIZE	5

typedef struct {
	uint8_t src;
	uint8_t len;
	uint8_t dst;
	uint8_t func;
	uint8_t *data;
	uint8_t crc;
} ibus_msg;

void update_crc (ibus_msg *msg);

void send_message( ibus_msg *msg );

void test( void );

#endif /* IBUS_IBUS_H_ */
