/*
 * ibus.c
 *
 *  Created on: 30.10.2019
 *      Author: heinrich
 */

#include "ibus.h"

void send_message( ibus_msg *msg ) {

	update_crc(msg);

	NVIC_DisableIRQ(UART_IRQn);
	send_char(msg->src);
	send_char(msg->len);
	send_char(msg->dst);
	for (int i = 0; i <= msg->len-2; i++) {
		send_char(msg->data[i]);
	}
	send_char(msg->crc);
	LPC_UART->FCR |= Rx_FIFO_RST | Tx_FIFO_RST;
	NVIC_EnableIRQ(UART_IRQn);
}

void test( void ) {
	ibus_msg msg;

	msg.src = 0xD0;
	msg.len = 5;
	msg.dst = 0xBF;
	msg.func = 0x5C;

	msg.data = (uint8_t*) calloc(2, sizeof(uint8_t));
	msg.data[0] = 0xEC;
	msg.data[1] = 0x00;
	update_crc (&msg);
}

void update_crc (ibus_msg *msg) {
	uint8_t crc = 0;
	crc ^= msg->src;
	crc ^= msg->len;
	crc ^= msg->dst;
	crc ^= msg->func;
	for (int i = 0; i <= msg->len - 2; i++) {
		crc ^= msg->data[i];
	}
	msg->crc = crc;
}


