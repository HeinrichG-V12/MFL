/*
 * becker.h
 *
 * Created: 21.03.2020 10:22:28
 *  Author: Heinrich
 */



#ifndef BECKER_H_
#define BECKER_H_

#include "../mcp42xxx/mcp42xxx.h"
#include "../uart/uart.h"

void b_init(void);
void b_next(void);
void b_next_long(void);
void b_back(void);
void b_back_long(void);
void b_increase(void);
void b_decrease(void);

#endif /* BECKER_H_ */