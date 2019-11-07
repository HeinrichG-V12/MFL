/*
 * uart.c
 *
 *  Created on: 30.10.2019
 *      Author: heinrich
 */


#include "uart.h"
#include <stdint.h>
#include <LPC13xx.h>

void init_uart(void) {
	LPC_IOCON->PIO1_6 &= ~0x07;
	LPC_IOCON->PIO1_6 |= 0x1; 		//Select RXD for PIO1_6
	LPC_IOCON->PIO1_7 &= ~0x07;
	LPC_IOCON->PIO1_7 |= 0x1; 		//Select RXD for PIO2_7

	//UART CLOCK Enable Sequence Step 2 - Set Divider & Enable Clock
	LPC_SYSCON->UARTCLKDIV = 1; 	//Set Divider by 1, so UART_PCLK=CCLK
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<12);//Enable UART clock

	LPC_UART->LCR = (0x3 << 0)	// 8 bit, 1 stop bit
					| (1 << 3)	// parity enable
					| (1 << 4)	// even parity
					| DLAB_BIT ; //DLAB set to 1
	LPC_UART->DLL = DEF_DLL;
	LPC_UART->DLM = DEF_DLM;

	LPC_UART->FCR |= Ux_FIFO_EN | Rx_FIFO_RST | Tx_FIFO_RST;
	LPC_UART->FDR = (DEF_MULVAL<<4) | DEF_DIVADDVAL; /* MULVAL=15(bits - 7:4) , DIVADDVAL=2(bits - 3:0)  */
	LPC_UART->LCR &= ~(DLAB_BIT);

	NVIC_EnableIRQ(UART_IRQn);
}

void send_char (uint8_t data) {
	while(!(LPC_UART->LSR & THRE)); //wait until THR is empty
	//now we can write to Tx FIFO
	LPC_UART->THR = data;
}

void UART_IRQHandler() {

}
