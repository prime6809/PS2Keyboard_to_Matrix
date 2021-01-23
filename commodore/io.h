/*
	io.h	: IO routines for the Commodore 64 / VIC-20 / C16 / Plus 4

	2009-07-16, P.Harvey-Smith.
*/

#ifndef _IO_H_
#define _IO_H_

#include "globalio.h"

#define	ISTED_BIT		0
#define ISTED_MASK		(1<<ISTED_BIT)

#define IsTED			(DIPIsSet(ISTED_MASK))

void InitIO(void);
void ResetMachine(void);
void TestLEDS(void);
void MainLoopPoll(void);
#endif