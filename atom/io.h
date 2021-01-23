/*
	AtomIO	: IO routines for the Acorn Atom.

	2009-07-16, P.Harvey-Smith.
*/

#ifndef _IO_H_
#define _IO_H_

#define ReptPIN			PIND		// Rept line attached to this port
#define ReptPORT		PORTD
#define ReptDDR			DDRD
#define ReptBIT			5			// Rept attached to this bit
#define ReptMask		(1 << ReptBIT)

#define AtomConfigRept()	do { ReptDDR |= ReptMask; } while (0)
#define AtomAssertRept()	do { ReptPORT &= ~ReptMask; } while (0)
#define AtomClearRept()		do { ReptPORT |= ReptMask; } while (0)

void InitIO(void);
void ResetMachine(void);
void MainLoopPoll(void);
#endif