/*
	IO	: IO routines for the ZX80/ZX81.

	2020-12-28, P.Harvey-Smith.
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
	// Make reset line an input
	RESET_DDR &= ~RESET_MASK;
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