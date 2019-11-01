/*
 * adc.h
 *
 *  Created on: 29.04.2019
 *      Author: Heinrich
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

#define VREF       3.3 //Reference Voltage at VREFP pin, given VREFN = 0V(GND)
#define ADC_CLK_EN (1<<13) //Enable ADC clock
#define SEL_AD2    (1<<2) //Select Channel AD2
#define CLKDIV     15 // ADC clock-divider (ADC_CLOCK=PCLK/CLKDIV+1), yields 4.5Mhz ADC clock
#define ADC_PWRUP  (~(1<<4)) //setting it to 0 will power it up
#define START_CNV  (1<<24) //001 for starting the conversion immediately
#define ADC_DONE   (1U<<31) //define it as unsigned value or compiler will throw warning
#define ADCR_SETUP_SCM (CLKDIV<<8)

#define CLKS_10BIT	(0x0 << 17)
#define CLKS_9BIT	(0x1 << 17)
#define CLKS_8BIT	(0x2 << 17)
#define CLKS_7BIT	(0x3 << 17)
#define CLKS_6BIT	(0x4 << 17)
#define CLKS_5BIT	(0x5 << 17)
#define CLKS_4BIT	(0x6 << 17)
#define CLKS_3BIT	(0x7 << 17)

void adc_init(void);
int adc_getValue (void);

#endif /* ADC_H_ */
