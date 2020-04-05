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

void pioneer_init (void);
void pioneer_source (void);
void pioneer_mute (void);
void pioneer_next (void);
void pioneer_back (void);
void pioneer_increase (void);
void pioneer_decrease (void);
void pioneer_list (void);
void pioneer_select (void);
void pioneer_mode (void);
void pioneer_release (void);



#endif /* PIONEER_H_ */