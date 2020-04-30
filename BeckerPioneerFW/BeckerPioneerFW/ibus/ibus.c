/*
 * ibus.c
 *
 * Created: 03.01.2020 16:22:59
 *  Author: Heinrich
 */ 

#include "ibus.h"

enum {
	standby
	, standby_after_overflow
	, waitingForLen
	, rxActive
} eIrqStatus;

uint8_t irqStatus = standby;

void ibus_init (void)
{
	uart0_init();
	sen_sta_init();
	init_buffer();
	irqStatus = standby;
	timer0_init();
}

void sen_sta_init (void)
{
	// pe2 ist sen/sta pin des e910.15 und ist ein Eingang
	DDRE &= ~(1 << DDE2);
	// pull up ist aktiv
	PORTE |= (1 << PE2);
}

void send_ibus_message (uint8_t *data)
{
	uint8_t crc = 0, len = 0, t = 0;
	len = data[1];

	while (t < IBUS_PRIO1_DELAY)
	{
		if( PINE & (1<<PINE2) ) {	// sen/sta ist auf high, also wird gerade gesendet, ich muss die Klappe halten
			timer0_reset();
		}
		
		t = timer0_getValue();
	}
	
	uart0_tx();
		
	for (int i = 0; i <= len; i++)
	{
		crc ^= data[i];
		uart0_sendChar(data[i]);
	}
	uart0_sendChar(crc);
		
	uart0_rtx();		
}

ISR(USART0_RX_vect)
{
	uint8_t byte, timer_value;
	static uint8_t rx_position, len;
		
	byte = UDR0;
	timer_value = timer0_getValue();
	
	if (timer_value > IBUS_PRIO1_DELAY)
	{
		// neue Botschaft fängt an
		rx_buffer_write_entry(0, byte);
		irqStatus = waitingForLen;
	}
	else 
	{
		switch (irqStatus)
		{
			case waitingForLen:
				if (byte < MESSAGE_LENGHT)
				{
					len = byte;
					rx_buffer_write_entry(1, byte);
					rx_position = 2;
					irqStatus = rxActive;
				}
				else
				{
					irqStatus = standby_after_overflow;
				}
			break;
			
			case rxActive:
				if (rx_position < len + 2)
				{
					rx_buffer_write_entry(rx_position, byte);
				}
				
				rx_position++;
				
				if (rx_position == len + 2) 
				{
					rx_buffer_insertEntry();
					irqStatus = standby;
				}
			break;
		}
	}
	timer0_reset();
}