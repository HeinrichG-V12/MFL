/*
 * radio_controller.h
 *
 * Created: 05.04.2020 15:27:55
 *  Author: Heinrich
 */ 


#ifndef RADIO_CONTROLLER_H_
#define RADIO_CONTROLLER_H_

#include "pioneer.h"
#include "../timer/timer.h"
#include <stdbool.h>

void controller_init (void);
void controller_volume_increase (void);
void controller_volume_decrease (void);
void controller_next (void);
void controller_back (void);
void controller_set_search (bool state);
void controller_exec_search_up (void);
void controller_exec_search_down (void);
void controller_set_micro (bool state);
void controller_exec_micro (void);
void controller_rt (void);

#endif /* RADIO_CONTROLLER_H_ */