/*
 * uart.c
 *
 * Created: 21.03.2020 10:22:28
 *  Author: Heinrich
 */


#include "uart.h"
#include "../radio_control/global_types.h"

#define UBRR0_REG	103	// 9600 @ 16mhz
#define UBRR1_REG	103	// 9600 @ 16mhz

void uart0_init(void)
{
	uint8_t dummy = 0;
	UBRR0 = UBRR0_REG;
	UCSR0B = (1 << RXEN0)|(1 << TXEN0)|(1 << RXCIE0);	// receiver and transceiver enabled, rx interrupt enabled
	UCSR0C = (1 << UPM01)|(1 << UCSZ01)|(1 << UCSZ00);	// 8e1
	
	dummy = UDR0;
}

void uart0_sendChar(uint8_t data)
{
	while (!( UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

void uart0_tx (void)
{
	UCSR0B = (1 << TXEN0);
}

void uart0_rtx (void)
{
	UCSR0B = (1 << RXEN0)|(1 << TXEN0)|(1 << RXCIE0);
}

void uart1_init(void)
{
	uint8_t dummy = 0;
	UBRR1 = UBRR0_REG;
	UCSR1B = (1 << TXEN0);	// receiver and transceiver enabled
	UCSR1C = (1 << UCSZ11)|(1 << UCSZ10);	// 8n1
	dummy = UDR0;	
}

void uart1_sendChar(uint8_t data)
{
	while (!( UCSR1A & (1<<UDRE1)));
	UDR1 = data;
}

void uart1_sendCommand (uint8_t *data)
{
	int i = 0;
	
	while(data[i] != CR)
	{
		uart1_sendChar(data[i]);
		i++;
	}
}