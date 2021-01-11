/*
	IO	: IO routines for the TRS80.

	2020-12-28, P.Harvey-Smith.
*/

#ifndef _IO_H_
#define _IO_H_

//
// Reset line for target machine.
//

#define RESET_PORT		PORTD
#define RESET_PIN		PIND
#define RESET_DDR		DDRD
#define RESET			3
#define RESET_MASK		(1<<RESET)

void InitIO(void);
void ResetMachine(void);
void MainLoopPoll(void);
#endif