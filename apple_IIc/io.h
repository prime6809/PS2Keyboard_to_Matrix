/*
	io.h	: IO routines for the Apple IIc

	2024-10-20, J.Branton.
*/

#ifndef _IO_H_
#define _IO_H_

#include "globalio.h"

#define SHIFT_PIN JSUP
#define CNTRL_PIN JSDOWN
#define OAPPLE_PIN JSLEFT
#define CAPPLE_PIN JSRIGHT
#define CAPSLOCK_PIN AUX1

// Note for the above pin assignments to work JTAG must be disabled on the AVR.
// For example
//   avrdude -c usbtiny -p m16 -U lfuse:w:0xfd:m -U hfuse:w:0xd9:m

#define ShiftOn()	(JSPORT &= (~SHIFT_PIN))
#define ShiftOff()	(JSPORT |= SHIFT_PIN)
#define OAppleOn()	(JSPORT |= OAPPLE_PIN)
#define OAppleOff()	(JSPORT &= (~OAPPLE_PIN))
#define CAppleOn()	(JSPORT |= CAPPLE_PIN)
#define CAppleOff()	(JSPORT &= (~CAPPLE_PIN))

void InitIO(void);
void ResetMachine(void);
void TestLEDS(void);
void MainLoopPoll(void);
void CntrlOn(void);
void CntrlOff(void);
void CapsLockOn(void);
void CapsLockOff(void);
#endif
