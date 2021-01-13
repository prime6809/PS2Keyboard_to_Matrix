/*
	io.h	: IO routines for the Acorn Electron.

	2009-07-16, P.Harvey-Smith.
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

//
// Input lines for reading the keyboard leds from the computer.
//

#define LED_PORT		PORTC
#define LED_PIN			PINC
#define	LED_DDR			DDRC
#define SHIFT_LED		6
#define CAPS_LED		5
#define SHIFT_LED_MASK	(1<<SHIFT_LED)
#define CAPS_LED_MASK	(1<<CAPS_LED)
#define LED_MASK		(CAPS_LED_MASK)

void InitIO(void);
void ResetMachine(void);
void TestLEDS(void);
void MainLoopPoll(void);
#endif