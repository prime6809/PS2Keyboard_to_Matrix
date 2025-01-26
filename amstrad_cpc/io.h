/*
	io.h	: IO routines for the Amstrad CPC-6128

	2024-06-13, J.Branton.
*/

#ifndef _IO_H_
#define _IO_H_

#include "globalio.h"

void InitIO(void);
void ResetMachine(void);
void MainLoopPoll(void);
#endif
