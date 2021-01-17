/*
	AtomIO	: IO routines for the Acorn Atom.

	2009-07-16, P.Harvey-Smith.
*/

#include <avr/interrupt.h>
#include <inttypes.h>
#include <util/delay.h>
#include "io.h"
#include "status.h"
#include "matrix_kbd.h"
#include "scancode.h"

void InitIO(void)
{
	// Make Atom reset line an input
	RESET_DDR &= ~RESET_MASK;

	AtomConfigRept();
}

void ResetMachine(void)
{
	log0("ResetAtom()\n");
	// Make reset line an output, and take reset line low
	RESET_DDR	|= RESET_MASK;
	RESET_PORT	&= ~RESET_MASK;
	
	// Let it take effect
	_delay_ms(10);
	
	// make it an input again, and let line float
	RESET_DDR	&= ~RESET_MASK;
	RESET_PORT	&= ~RESET_MASK;
}

// Called from main loop.
void MainLoopPoll(void)
{	
}

uint8_t TargetKeyCallback(uint8_t	PrefixCode,
						  uint8_t	KeyCode,
					      uint8_t	State)
{
	uint8_t handled = false;
	
	switch (KeyCode)
	{
		case ATOM_KEY_REPT :
			if (State==KEY_DOWN)
				AtomAssertRept();
			else
				AtomClearRept();
			
				handled = true;
			break;
		default:
			break;
	}
	
	return handled;
}  