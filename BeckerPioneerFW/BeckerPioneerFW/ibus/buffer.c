/*
 * buffer.c
 *
 * Created: 03.04.2020 16:11:04
 *  Author: Heinrich
 */ 

#include "buffer.h"

uint8_t rx_buffer[RX_MESSAGE_COUNT][MESSAGE_LENGHT];
uint8_t rx_producer_ptr, rx_consumer_ptr;

void init_buffer (void)
{
	rx_producer_ptr = 0;
	rx_consumer_ptr = 0;
}

void rx_buffer_write_entry (uint8_t pos, uint8_t data)
{
	rx_buffer[rx_producer_ptr][pos] = data;
}

void rx_buffer_insertEntry (void)
{
	rx_producer_ptr++;
	
	if (rx_producer_ptr == RX_MESSAGE_COUNT)
	{
		rx_producer_ptr = 0;
	}
}

uint8_t* rx_buffer_get_entry (void)
{
	if(rx_producer_ptr == rx_consumer_ptr)
	return NULL;
	else
	return rx_buffer[rx_consumer_ptr];
}

uint8_t rx_buffer_get_depth (void)
{
	return (rx_producer_ptr - rx_consumer_ptr);
}

void rx_buffer_remove_entry (void)
{
	rx_consumer_ptr++;
	
	if (rx_consumer_ptr == RX_MESSAGE_COUNT)
	{
		rx_consumer_ptr = 0;
	}
}