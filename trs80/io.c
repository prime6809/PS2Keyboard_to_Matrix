/*
	IO	: IO routines for the TRS80.

	2020-12-28, P.Harvey-Smith.
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
	logv0("Resetting.....\n");
	ResetTargetMachine();
	logv0("Done\n");	
}

// Called from main loop.
void MainLoopPoll(void)
{	
}

uint8_t TargetKeyCallback(uint8_t	PrefixCode,
						  uint8_t	KeyCode,
					      uint8_t	State)
{
	return false;
}