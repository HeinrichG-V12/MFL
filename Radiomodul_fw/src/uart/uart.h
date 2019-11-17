/*
 * uart.h
 *
 *  Created on: 30.10.2019
 *      Author: heinrich
 */

#ifndef UART_UART_H_
#define UART_UART_H_

#include <stdint.h>

// 9600 Baud @ 72Mhz UART_PLCK – Use: DLL=213, DLM=1, MULVAL=1, DIVADDVALL=0
// settings for iBus: 9600 8E1


#define IER_RBR		0x01
#define IER_THRE	0x02	//Transmit Holding Register Empty
#define IER_RLS		0x04
#define DEF_DLL			213
#define	DEF_DLM			1
#define DEF_MULVAL      1
#define DEF_DIVADDVAL   0
#define Ux_FIFO_EN  (1<<0)
#define Rx_FIFO_RST (1<<1)
#define Tx_FIFO_RST (1<<2)
#define DLAB_BIT    (1<<7)

void init_uart(void);
void UART_IRQHandler( void );
void send_char (uint8_t data);

#endif /* UART_UART_H_ */
