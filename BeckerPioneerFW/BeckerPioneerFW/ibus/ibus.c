/*
 * ibus.c
 *
 * Created: 03.01.2020 16:22:59
 *  Author: Heinrich
 */ 

#include "ibus.h"
#include "../uart/uart.h"

extern uint8_t adc_value;

void send_ibus (uint8_t *data)
{
	uint8_t crc = 0;
	uart0_tx();
	for (int i = 0; i <= data[IBUS_LENGTH] -1; i++) {
		crc ^= data[i];
		uart0_sendChar(data[i]);
	}
	uart0_sendChar(crc);
	uart0_rtx();
}

void set_brightness (void)
{
	uint8_t msg[6];
	msg[0] = LKM;
	msg[1] = 5;
	msg[2] = GLO;
	msg[3] = adc_value;
	msg[4] = 0x00;
	
	send_ibus(msg);
}