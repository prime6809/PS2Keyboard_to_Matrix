/*
	io.c	: IO routines for the Acorn Electron.

	2009-07-16, P.Harvey-Smith.
*/

#include <avr/interrupt.h>
#include <inttypes.h>
#include <util/delay.h>
#include "io.h"
#include "status.h"
#include "matrix_kbd.h"
#include "scancode.h"
#include "ps2kbd.h"

// Value of leds read by timer interrupt
volatile uint8_t	leds;

// Value of leds on last call to TestLEDS, used to detect changes
// and update LEDS on PS/2 keyboard.
volatile uint8_t	last_leds;

void InitIO(void)
{
	// Make reset line an input
	RESET_DDR &= ~RESET_MASK;
	
	// Make Caps LED and Shift lock LED lines inputs
	LED_DDR &= ~LED_MASK;

	// Invalidate last_leds, so first call to TestLEDS() will set them.
	last_leds = ~(LED_PIN & LED_MASK);
}

void ResetMachine(void)
{
	log0("ResetMachine()\n");
	// Make reset line an output, and take reset line low
	RESET_DDR	|= RESET_MASK;
	RESET_PORT	&= ~RESET_MASK;
	
	// Let it take effect
	_delay_ms(10);
	
	// make it an input again, and let line float
	RESET_DDR	&= ~RESET_MASK;
	RESET_PORT	&= ~RESET_MASK;
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
	uint8_t	kbleds	= KBD_LED_NUMLOCK | KBD_LED_CAPS;
	uint8_t	lleds;
	
	// Read LED output lines from Master
	leds=LED_PIN & LED_MASK;	
	
	// Only update if they have changed
	if(leds!=last_leds)
	{
		// Take a local copy of leds 
		lleds=leds;	
		
		// Tanslate Electron->PS/2, lines from Electron are active low
		if (lleds & CAPS_LED_MASK) kbleds &= ~KBD_LED_CAPS;
		
        // Send the command to set the LEDS to the keyboard
		ps2_kbd_set_leds(kbleds);

		log0("set leds to : %2X\n",kbleds);
	
        // Update last_leds so that we can detect changes
		last_leds=lleds;
	}
}
