/*
 * timer.h
 *
 * Created: 03.01.2020 17:11:29
 *  Author: Heinrich
 */ 

#include <avr/io.h>
#include <stdint.h>

#ifndef TIMER_H_
#define TIMER_H_

void timer0_init(void);
uint8_t timer0_getValue(void);
void timer0_reset(void);

void timer_delay_ms (uint16_t delay);


#endif /* TIMER_H_ */