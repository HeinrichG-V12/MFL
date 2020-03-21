/*
 * uart.h
 *
 * Created: 03.01.2020 16:12:11
 *  Author: Heinrich
 */ 

#include <avr/io.h>
#include <stdint.h>

#ifndef UART_H_
#define UART_H_

void uart0_init(void);
void uart0_sendChar(uint8_t data);
void uart0_tx(void);
void uart0_rtx(void);

void uart1_init(void);
void uart1_sendChar(uint8_t data);
void uart1_sendCommand(uint8_t *data);

#endif /* UART_H_ */