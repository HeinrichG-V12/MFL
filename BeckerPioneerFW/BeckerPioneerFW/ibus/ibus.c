/*
 * ibus.c
 *
 * Created: 03.01.2020 16:22:59
 *  Author: Heinrich
 */ 

#include "ibus.h"

enum {
	standby
	, waitingForLen
	, rxActive	
} eIrqStatus;

uint8_t irqStatus = standby;

void ibus_init (void)
{
	init_buffer();
	irqStatus = standby;
	timer0_init();
}

void send_ibus_message (uint8_t *data)
{
	uint8_t crc = 0;
	uart0_tx();
	for (int i = 0; i <= data[1] -1; i++) {
		crc ^= data[i];
		uart0_sendChar(data[i]);
	}
	uart0_sendChar(crc);
	uart0_rtx();
}

ISR(USART0_RX_vect)
{
	uint8_t byte, timer_value;
	static uint8_t rx_position, msg_length;
	
	byte = UDR0;
	timer_value = timer0_getValue();
	
	if (timer_value > IBUS_PRIO1_DELAY)
	{
		// start of new ibus message
		rx_buffer_write_entry(0, byte);
		irqStatus = waitingForLen;
	}
	else
	{
		switch(irqStatus)
		{
			case waitingForLen:
			// second byte of the ibus message
			rx_buffer_write_entry(1, byte);
			irqStatus = rxActive;
			rx_position = 1;
			msg_length = byte;
			break;
			
			case rxActive:
			rx_position++;
			rx_buffer_write_entry(rx_position, byte);
			
			if (msg_length == rx_position-2)
			{
				rx_buffer_insertEntry();
				irqStatus = standby;
			}
			
			break;
		}
	}
	timer0_reset();
}