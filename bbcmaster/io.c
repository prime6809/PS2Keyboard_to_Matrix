/*
	io.c	: IO routines for the Acorn BBC Master/Master compact.

	2009-07-16, P.Harvey-Smith.
*/

#include <avr/interrupt.h>
#include <inttypes.h>
#include <util/delay.h>
#include "globalio.h"
#include "io.h"
#include "status.h"
#include "matrix_kbd.h"
#include "scancode.h"
#include "ps2kbd.h"

// Value of leds on last call to TestLEDS, used to detect changes
// and update LEDS on PS/2 keyboard.
uint8_t	last_leds = 0;

void InitIO(void)
{
	// Set numlock led to indicate power on.
	PS2SetLED(PS2_LED_NUMLOCK);
}

void ResetMachine(void)
{
	ResetTargetMachine();
}

uint8_t TargetKeyCallback(uint8_t	PrefixCode,
						  uint8_t	KeyCode,
					      uint8_t	State)
{
	uint8_t handled = false;
	
	switch (KeyCode)
	{
		default:
			break;
	}
	
	return handled;
}  

// Called from main loop.
void MainLoopPoll(void)
{	
	TestLEDS();
}

//
// Test Capslock / Shiftlock LEDS and set PS/2 leds to match
//
// The mappings of the BBC to PS/2 LEDS are as follows :
//
// BBC          PS/2
// Power        Scroll lock
// Caps lock    Caps lock
// Shift lock   Num lock
//

void TestLEDS(void)
{
	uint8_t	leds;

	// Read LED output lines from Master
	leds=ReadAUX();	
	
	// Only update if they have changed
	if(leds!=last_leds)
	{
		// Tanslate BBC->PS/2, lines from BBC are active low
		PS2SetClearLED((~leds & SHIFT_LED_MASK),PS2_LED_SCROLL);
		PS2SetClearLED((~leds & CAPS_LED_MASK),PS2_LED_CAPS);
		
        // Update last_leds so that we can detect changes
		last_leds=leds;
	}
}
