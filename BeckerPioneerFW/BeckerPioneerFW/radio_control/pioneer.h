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

#ifdef AD5293
#include "../ad5293/ad5293.h"
#endif // AD5293

#ifdef MCP42050
#include "../mcp42050/mcp42xxx.h"
#endif // MCP42050

// pioneer_2 = PB4

#define DDR_PIONEER_2			DDRB
#define DD_PIONEER_2			PB4

#define SELECT_PIONEER_2()		(PORTB |= (1 << DD_PIONEER_2))
#define DESELECT_PIONEER_2()	(PORTB &= ~(1 << DD_PIONEER_2))

void pioneer_init (void);
void pioneer_source (void);
void pioneer_mute (void);
void pioneer_list (void);
void pioneer_next (void);
void pioneer_next_long (void);
void pioneer_back (void);
void pioneer_back_long (void);
void pioneer_volume_increase (void);
void pioneer_volume_decrease (void);
void pioneer_select (void);
void pioneer_mode (void);
void pioneer_release(void);
void pioneer_send_release (void);

#endif /* PIONEER_H_ */