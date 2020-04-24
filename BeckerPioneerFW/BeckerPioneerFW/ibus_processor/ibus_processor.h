/*
 * ibus_processor.h
 *
 * Created: 05.04.2020 16:09:27
 *  Author: Heinrich
 */ 


#ifndef IBUS_PROCESSOR_H_
#define IBUS_PROCESSOR_H_

// ibus message format
#define IBUS_SRC					0
#define IBUS_LENGTH					1
#define	IBUS_DST					2
#define	IBUS_FUNC					3
#define	IBUS_DATA					4

// IBUS_DEVICE IBUS_SRC (byte0) oder IBUS_DST (byte2):
#define	DEV_MFL						0x50
#define	DEV_RAD						0x68
#define	DEV_TEL						0xC8
#define DEV_LKM						0xD0
#define DEV_RLS						0xE8
#define DEV_GLO						0xBF
#define DEV_LOC						0xFF

// IBUS_FUNC (byte3):
#define DEVICE_STATUS_REQ			0x01
#define WHEEL_VOLUME				0x32
#define LIGHT_SENSOR				0x59
#define	ARROWS						0x3B
#define	RT							0x01
#define	MIC							0x3B
#define BRIGHTNESS					0x5C
#define LIGHT_DIMMER_STATUS			0x5D

// IBUS_DATA (byte 4 and more)
#define	VOL_INC						0x11
#define	VOL_DEC						0x01
#define MIC_PRESS					0x80
#define	MIC_RELEASE					0xA0
#define MIC_LONG_PRESS				0x90

#include <stdint.h>
#include "../ibus/ibus.h"
#include "../ibus/buffer.h"

void set_brightness (void);
void device_status_ready_after_reset (uint8_t source);
void ibus_processor (uint8_t *msg);

#endif /* IBUS_PROCESSOR_H_ */
