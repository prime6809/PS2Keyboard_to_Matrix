/*
	IO	: IO routines for the TRS80.

	2020-12-28, P.Harvey-Smith.
*/

#ifndef _IO_H_
#define _IO_H_

#include "globalio.h"

#define MODEL_MASK		DIPS0
#define SWAP_MASK		DIPS1

#define IsModel3		(DIPIsSet(MODEL_MASK))
#define IsSWAP			(DIPIsSet(ISSWAP_MASK))

void InitIO(void);
void ResetMachine(void);
void MainLoopPoll(void);
#endif