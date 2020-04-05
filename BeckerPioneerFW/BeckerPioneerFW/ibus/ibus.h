/*
 * ibus.h
 *
 * Created: 03.01.2020 16:22:12
 *  Author: Heinrich
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "../uart/uart.h"
#include "../timer/timer.h"
#include "buffer.h"

#ifndef IBUS_H_
#define IBUS_H_

// ibus prio delay
#define IBUS_PRIO1_DELAY	29

void send_ibus_message (uint8_t *data);

#endif /* IBUS_H_ */