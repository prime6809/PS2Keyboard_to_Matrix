/*
	IO	: IO routines for the TRS80.

	2020-12-28, P.Harvey-Smith.
*/

#ifndef _IO_H_
#define _IO_H_

#include "globalio.h"

#define	ISSWAP_BIT		0
#define ISSWAP_MASK		(1<<ISSWAP_BIT)

#define IsSWAP			(DIPIsSet(ISSWAP_MASK))

void InitIO(void);
void ResetMachine(void);
void MainLoopPoll(void);
#endif