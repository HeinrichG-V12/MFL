/*
 * ad5243.h
 *
 *  Created on: 02.11.2019
 *      Author: heinrich
 */

#ifndef AD5243_AD5243_H_
#define AD5243_AD5243_H_

#include <stdint.h>

#define AD5243_ADDR  0x2F

void write_value (uint8_t channel, uint8_t value);


#endif /* AD5243_AD5243_H_ */
