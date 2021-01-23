/*
	io.c	: IO routines for the Acorn BBC A/B/B+.

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

void InitIO(void)
{
}

void ResetMachine(void)
{
	ResetTargetMachine();
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
		default:
			break;
	}
	
	return handled;
}  