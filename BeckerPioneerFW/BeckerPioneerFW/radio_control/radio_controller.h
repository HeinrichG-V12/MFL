/*
 * radio_controller.h
 *
 * Created: 05.04.2020 15:27:55
 *  Author: Heinrich
 */ 


#ifndef RADIO_CONTROLLER_H_
#define RADIO_CONTROLLER_H_

#include "becker.h"
#include "pioneer.h"
#include "../timer/timer.h"

void controller_init (void);
void controller_increase (void);
void controller_decrease (void);
void controller_next (void);
void controller_back (void);



#endif /* RADIO_CONTROLLER_H_ */