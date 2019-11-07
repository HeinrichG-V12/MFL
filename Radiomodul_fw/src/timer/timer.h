/*
 * timer.h
 *
 *  Created on: 07.11.2019
 *      Author: heinrich
 */

#ifndef TIMER_TIMER_H_
#define TIMER_TIMER_H_

#include <LPC13xx.h>
#include <stdint.h>

void ibusTimer_init( void );
uint32_t ibusTimer_getValue( void );
uint32_t ibusTimer_getValueReset( void );

#endif /* TIMER_TIMER_H_ */
