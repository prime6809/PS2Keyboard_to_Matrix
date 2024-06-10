/*
	io.h	: IO routines for the Amstrad CPC-6128

	2024-06-13, J.Branton.
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
