/*
	IO	: IO routines for the Dragon 32/64/Alpha and Tandy CoCo 1/2/3.

	2020-12-28, P.Harvey-Smith.
*/

#ifndef _IO_H_
#define _IO_H_

#include "globalio.h"

#define	DORC_BIT		0
#define DORC_MASK		(1<<DORC_BIT)

#define IsDragon		(DIPIsSet(DORC_MASK))

void InitIO(void);
void ResetMachine(void);
void MainLoopPoll(void);
#endif