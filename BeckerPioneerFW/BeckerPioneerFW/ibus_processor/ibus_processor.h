/*
 * ibus_processor.h
 *
 * Created: 05.04.2020 16:09:27
 *  Author: Heinrich
 */ 


#ifndef IBUS_PROCESSOR_H_
#define IBUS_PROCESSOR_H_

// ibus message format
#define IBUS_SRC			0
#define IBUS_LENGTH			1
#define	IBUS_DST			2
#define	IBUS_FUNC			3
#define	IBUS_DATA			4

// IBUS_DEVICE IBUS_SRC (byte0) oder IBUS_DST (byte2):
#define	MFL					0x50
#define	RAD					0x68
#define	TEL					0xC8
#define LKM					0xD0
#define RLS					0xE8
#define GLO					0xBF

// IBUS_FUNC (byte3):
#define VOLUME				0x32
#define LIGHTSENSOR			0x59
#define	ARROWS				0x3B
#define	RT					0x01
#define	MIC					0x3B
#define BRIGHTNESS			0x5C

// IBUS_DATA (byte 4 and more)
#define	VOL_INC				0x11
#define	VOL_DEC				0x01
#define MIC_PRESS			0x80
#define	MIC_RELEASE			0xA0
#define MIC_LONG_PRESS		0x90

#include <stdint.h>
#include "../ibus/ibus.h"
#include "../ibus/buffer.h"


#endif /* IBUS_PROCESSOR_H_ */