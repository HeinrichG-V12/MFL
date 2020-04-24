/*
 * ibus.h
 *
 * Created: 03.01.2020 16:22:12
 *  Author: Heinrich
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
#include "../uart/uart.h"
#include "../timer/timer.h"
#include "buffer.h"

#ifndef IBUS_H_
#define IBUS_H_

// ibus prio delay
#define IBUS_PRIO1_DELAY	29

void ibus_init (void);
void sen_sta_init (void);
bool is_free_to_send (void);
void send_ibus_message (uint8_t *data);

#endif /* IBUS_H_ */