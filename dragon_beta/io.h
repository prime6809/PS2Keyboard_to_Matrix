/*
	IO	: IO routines for the Dragon 32/64/Alpha and Tandy CoCo 1/2/3.

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

#define DORC_PORT		PORTB
#define DORC_PIN		PINB
#define DORC_DDR		DDRB
#define	DORC_BIT		0
#define DORC_MASK		(1<<DORC_BIT)

#define IsDragon		((DORC_PIN & DORC_MASK)!=DORC_MASK)

void InitIO(void);
void ResetMachine(void);
void MainLoopPoll(void);
#endif