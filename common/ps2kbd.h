/* PS/2 keyboard routines by Jurre Hanema, version 1.0
 * ps2kbd.h
 *
 * Features yet to be implemented:
 *	- Support for PAUSE/BREAK and PRINT SCREEN/SYSRQ
 *
 * Released under "THE BEER-WARE LICENSE" (Revision 42):
 * <kipmans@gmail.com> wrote this file. As long as you retain this notice you can 
 * do whatever you want with this stuff. If we meet some day, and you think this 
 * stuff is worth it, you can buy me a beer in return.
 */
 
/* 
	2011-04-27, Changed all externally callable routines to have the prefix
		ps2_kbd_
*/

#ifndef PS2KBD_H
#define PS2KBD_H

#include <stdint.h>

/* Interrupt to be activated on negative edge of clock signal */
#define	PS2_KBD_INT		INT0_vect		

#define KBD_INT_MASK	((1<<ISC00) | (1<<ISC01))

#ifdef EICRA

/* Code to trigger the appropriate interrupt on the negative edge */
#define	KBD_SET_INT()	{ EICRA &= ~KBD_INT_MASK; EICRA |= (1<<ISC01); };

/* Code to enable the appropriate interrupt */
#define KBD_EN_INT()	{ EIMSK |= (1<<INT0); };	

#else

/* Code to trigger the appropriate interrupt on the negative edge */
#define	KBD_SET_INT()	{ MCUCR &= ~KBD_INT_MASK; MCUCR |= (1<<ISC01); };

/* Code to enable the appropriate interrupt */
#define KBD_EN_INT()	{ GICR |= (1<<INT0); };	

#endif


#define	KBD_DATA_PORT	PORTD
#define	KBD_DATA_DDR	DDRD
#define	KBD_DATA_PIN	PIND
#define	KBD_DATA_BIT	PD4
#define KBD_DATA_MASK	(1<<KBD_DATA_BIT)

#define	KBD_CLOCK_PORT	PORTD
#define	KBD_CLOCK_DDR	DDRD
#define	KBD_CLOCK_BIT	PD2
#define KBD_CLOCK_MASK	(1<<KBD_CLOCK_BIT)

// Buffer size needs to be big enough to hold several sets of scancodes.
#define	KBD_BUFSIZE	128

// Bits in keyboard status register


#define	KBD_SHIFT		0x0001		/* SHIFT is held down */
#define	KBD_CTRL		0x0002		/* CTRL is held down */
#define KBD_ALT			0x0004		/* ALT is held down */
#define	KBD_NUMLOCK		0x0008		/* NUM LOCK is activated */
#define	KBD_CAPS		0x0010		/* CAPS LOCK is activated */
#define	KBD_SCROLL		0x0020		/* SCROLL LOCK is activated */
#define	KBD_BAT_PASSED	0x0040		/* Keyboard passed its BAT test */

#define	KBD_SEND		0x0080		/* This and the next bits are for internal use */
#define	KBD_RECEIVE		0x0100
#define	KBD_EX			0x0200
#define	KBD_BREAK		0x0400
#define	KBD_LOCKED		0x0800

#define	PS2_LED_CAPS	0x04
#define PS2_LED_NUMLOCK	0x02
#define PS2_LED_SCROLL	0x01
#define PS2_LED_MASK	(PS2_LED_CAPS | PS2_LED_NUMLOCK | PS2_LED_SCROLL)

#define KBD_CMD_SET_LEDS	0xED

// "Public" function declarations

// Initialize keyboard routines: activate appropriate interrupts. This also executes a 
// sei() to enable them.
// NOTE: sei() disabled

void ps2_kbd_init(void);

// Returns the next character waiting in the buffer or 0 if there are no characters
// left.
unsigned char ps2_kbd_getchar(void);

// Returns the next scancode waiting in the buffer or 0 if there are no characters
// left.
uint8_t ps2_kbd_get_scancode(void);

// Sends data to the keyboard
// If another sending cycle is in progress this function waits (blocks) for 5 ms and then
// tries again.

void ps2_kbd_send(uint8_t data);

// Set the leds to specified pattern
void ps2_kbd_set_leds(uint8_t	kbleds);

// Returns the value of the keyboard status register. Can be used to check if SHIFT,
// CAPS LOCK or NUM LOCK is activated.

uint16_t ps2_kbd_get_status(void);

// Check to see if keyboard LEDS have changed since last poll if so, update them.
void ps2_poll_leds(void);

extern uint8_t	PS2_LEDS;

#define PS2SetLED(LED)				PS2_LEDS |= LED
#define PS2ClearLED(LED)			PS2_LEDS &= ~LED
#define PS2SetClearLED(STATE,LED)  do { if (STATE) PS2SetLED(LED); else PS2ClearLED(LED); } while (0)

#endif
