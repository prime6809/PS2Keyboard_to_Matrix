/*
	globalio.h	: Global I/O definitions. dip switthches / joystick etc.
	
	2021-01-23, P.Harvey-Smith.
*/

#ifndef __GLOBALIO__
#define __GLOBALIO__

#include <util/delay.h>

// Jumpers / DIP switches.
#define DIPPORT		PORTB
#define DIPDDR		DDRB
#define DIPPIN		PINB

// Bits 0..4 used
#define DIPMASK		0x1F

// Note DIPs are pulled upm so we invert them so that a 1
// represents a closed jumper
#define ReadDIP()	(~DIPPIN & DIPMASK)

// Masks for testing DIPs
#define DIPS0		0x01
#define DIPS1		0x02
#define DIPS2		0x04
#define DIPS3		0x08
#define DIPS4		0x10

// Check for a dip being set 
#define DIPIsSet(SW)	((ReadDIP() & SW) == SW)

// Joystick and spare lines
#define JSPORT		PORTC
#define JSDDR		DDRC
#define JSPIN		PINC

// Joystick masks
#define JSUP		0x01
#define JSDOWN		0x02
#define JSLEFT		0x04
#define JSRIGHT		0x08
#define JSFIRE		0x10
#define AUX0		0x20
#define AUX1		0x40
#define JSPROGLED	0x80

#define JSINMASK	(JSUP | JSDOWN | JSLEFT | JSRIGHT | JSFIRE)
#define AUXMASK		(AUX0 | AUX1)
#define JSOUTMASK	JSPROGLED

// Note JS/AUX are pulled up so we invert them so that a 1
// represents a closed jumper
#define ReadJS()	(~JSPIN & JSINMASK)
#define ReadAUX()	(JSPIN & AUXMASK)

#define JSLEDOn()	(JSPORT &= JSPROGLED)
#define JSLEDOff()	(JSPORT |= JSPROGLED)

// Reset line for target machine.

#define RESET_PORT		PORTD
#define RESET_PIN		PIND
#define RESET_DDR		DDRD
#define RESET			3
#define RESET_MASK		(1<<RESET)

// Make reset line an output, and take reset line low
#define AssertTargetReset()	do { RESET_DDR |= RESET_MASK; RESET_PORT &= ~RESET_MASK; } while (0)

// make it an input again, and let line float
#define ClearTargetReset()	do { RESET_DDR &= ~RESET_MASK; RESET_PORT |= RESET_MASK; } while (0)

// reset the target
#define ResetTargetMachine()	do { AssertTargetReset(); _delay_ms(50); ClearTargetReset(); } while (0)

// initialize global IO.
void GlobalIOInit(void);

#endif

	