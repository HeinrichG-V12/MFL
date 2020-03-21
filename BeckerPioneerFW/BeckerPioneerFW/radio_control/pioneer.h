/*
 * pioneer.h
 *
 * Created: 21.03.2020 10:22:28
 *  Author: Heinrich
 */



#ifndef PIONEER_H_
#define PIONEER_H_

#include <avr/io.h>
#include <stdint.h>
#include "../mcp42xxx/mcp42xxx.h"

void p_source(void);
void p_mute(void);
void p_next(void);
void p_back(void);
void p_increase(void);
void p_decrease(void);
void p_list(void);
void p_select(void);
void p_mode(void);



#endif /* PIONEER_H_ */