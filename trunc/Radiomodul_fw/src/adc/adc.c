/*
 * adc.c
 *
 *  Created on: 29.04.2019
 *      Author: Heinrich
 */

#include "adc.h"
#include "LPC13xx.h"


void adc_init (void) {
	LPC_SYSCON->PDRUNCFG &= ADC_PWRUP; //Power-up ADC Block
	LPC_SYSCON->SYSAHBCLKCTRL |= ADC_CLK_EN; //Enable ADC clock
	LPC_ADC->CR = CLKS_8BIT | ADCR_SETUP_SCM | SEL_AD2; //Setup ADC Block

	/* Now select AD2 function and set ADMODE=0 for PIO1_1(P1.1) */
	LPC_IOCON->R_PIO1_1 = 0x2; //Use this for KEIL and LPCXpresso/MCUXpresso - check tutorial for more
}

int adc_getValue (void) {
	unsigned int result = 0;

	LPC_ADC->CR |= START_CNV; //Start new Conversion

	while((LPC_ADC->DR2 & ADC_DONE) == 0); //Wait until conversion is finished

	result = (LPC_ADC->DR2 >> 6) & 0x3FF; //10 bit Mask to extract result

	return result;
}
