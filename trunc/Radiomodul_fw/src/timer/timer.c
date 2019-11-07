/*
 * timer.c
 *
 *  Created on: 07.11.2019
 *      Author: heinrich
 */


#include "timer.h"

void ibusTimer_init( void ) {
	// 0,01ms = 3599

	LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 7);	// enable timer0 ct16
	LPC_TMR16B0->CTCR = 0x0;
	LPC_TMR16B0->PR = 3599;
	LPC_TMR16B0->TCR |= (1 << 1);			// reset timer
	LPC_TMR16B0->TCR |= (1 << 0);			// start timer
}

uint32_t ibusTimer_getValue( void ) {
	return LPC_TMR16B0->TC;
}

uint32_t ibusTimer_getValueReset( void ) {
	uint32_t value = ibusTimer_getValue();
	LPC_TMR16B0->TCR |= (1 << 1);			// reset timer

	return value;
}
