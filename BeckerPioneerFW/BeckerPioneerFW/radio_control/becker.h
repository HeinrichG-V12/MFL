/*
 * becker.h
 *
 * Created: 21.03.2020 10:22:28
 *  Author: Heinrich
 */



#ifndef BECKER_H_
#define BECKER_H_

#include "../uart/uart.h"

void becker_init(void);
void becker_next(void);
void becker_next_long(void);
void becker_back(void);
void becker_back_long(void);
void becker_volume_increase(void);
void becker_volume_decrease(void);
void becker_send_init(void);
void becker_send_release(void);

#endif /* BECKER_H_ */