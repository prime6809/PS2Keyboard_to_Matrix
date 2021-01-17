/*
	io.c	: IO routines for the Commodore 64 / VIC-20 / C16 / Plus 4.

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

extern matrix_t MainMatrix;

static uint8_t	LockState;

void InitIO(void)
{
	// Make reset line an input
	RESET_DDR &= ~RESET_MASK;
	
	// Jumper to select if machine is TED based or VIC/VICII based.
	// set as input with pullup
	ISTED_DDR  &= ISTED_MASK;
	ISTED_PORT |= ISTED_MASK;
	
	// Clear capslock
	LockState=KEY_UP;
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
	uint8_t handled 	= false;
	uint8_t ShiftKey	= IsTED ? C16P4_KEY_SHIFT : C64VIC_KEY_LSHIFT;

	if (PrefixCode == SCAN_CODE_NO_PREFIX) 
	{
		if((KeyCode == SCAN_CODE_CAPSLOCK) && (State == KEY_DOWN))
		{	
			LockState = (LockState == KEY_DOWN) ? KEY_UP : KEY_DOWN;
			handled = true;
			
			MainMatrix.output(ShiftKey,LockState);
		}
		else if ((KeyCode == SCAN_CODE_LSHIFT) && LockState)
		{
			handled = true;
		}
	}
	
	return handled;
}  

// Called from main loop.
void MainLoopPoll(void)
{	
}
