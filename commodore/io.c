/*
	io.c	: IO routines for the Commodore 64 / VIC-20 / C16 / Plus 4.

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

extern matrix_t MainMatrix;

static uint8_t	LockState;

void InitIO(void)
{
	// Clear capslock
	LockState=KEY_UP;
}

void ResetMachine(void)
{
	ResetTargetMachine();
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
