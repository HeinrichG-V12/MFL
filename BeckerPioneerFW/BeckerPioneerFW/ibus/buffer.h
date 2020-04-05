/*
 * buffer.h
 *
 * Created: 03.04.2020 16:11:17
 *  Author: Heinrich
 */ 


#ifndef BUFFER_H_
#define BUFFER_H_

#include <stdint.h>
#include <stddef.h>

#define MESSAGE_LENGHT	36
#define RX_MESSAGE_COUNT 10

void init_buffer (void);
void rx_buffer_write_entry (uint8_t pos, uint8_t data);
void rx_buffer_insertEntry (void);
uint8_t* rx_buffer_get_entry (void);
void rx_buffer_remove_entry (void);

#endif /* BUFFER_H_ */