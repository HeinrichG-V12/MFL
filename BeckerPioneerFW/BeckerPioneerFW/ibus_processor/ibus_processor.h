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
#define	WHEEL_SEARCH				0x3B
#define	WHEEL_RT					0x01
#define	WHEEL_MICRO					0x3B
#define BRIGHTNESS					0x5C
#define LIGHT_DIMMER_STATUS			0x5D

// IBUS_DATA (byte 4 and more)
#define	VOLUME_INC					0x11
#define	VOLUME_DEC					0x10

#define MICRO						0x80
#define MICRO_LONG					0x90
#define	MICRO_RELEASE				0xA0

#define SEARCH_UP					0x01
#define SEARCH_UP_LONG				0x11
#define SEARCH_UP_RELEASE			0x21

#define SEARCH_DOWN					0x08
#define SEARCH_DOWN_LONG			0x18
#define SEARCH_DOWN_RELEASE			0x28

#include <stdint.h>
#include "../ibus/ibus.h"
#include "../ibus/buffer.h"

void set_brightness (void);
void device_status_ready (uint8_t source);
void device_status_ready_after_reset (uint8_t source);
void ibus_processor (uint8_t *msg);

#endif /* IBUS_PROCESSOR_H_ */
