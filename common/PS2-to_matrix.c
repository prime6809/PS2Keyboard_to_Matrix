/*
	PS2-to-matrix	: 
		Keyboard module for translatin a PS2 keyboard to a matrix suitable
		for many retro computers.

	2009-07-28, 2020-12-28, P.Harvey-Smith.
	
	Implements the following :
	
	1) PS/2 Keyboard interface, driving crosspoint switch connected to
	   target keyboard interface.
	
	2009-09-05 Added the ability to the keyboard module to hadle both the
	normal and escaped scancodes, this allows us to treat for example
	left and right ctrl differently and the numeric keypad keys differently
	from the ins block and seperate cursors.
	
	2009-09-06 Added the ability to reset the target from the keyboard by 
	pressing the break key, this is achieved by attaching PD3 of the AVR to
	the target reset line. Normally it is configured as an input and allowed 
	to float. When break is pressed the pin is re-configured as an output and
	sent low, and then after a delay sent high again.
	
	2011-05-25 Ported the new keyboard handling code, this fixes several long 
	standing hang bugs with the keyboard code, and should hopefully be much more 
	stable.
	
*/

#include <avr/interrupt.h>
#include <inttypes.h>
#include <util/delay.h>
#include "ps2kbd.h"
#include "ps2scancode.h"
#include "scancode.h"
#include "status.h"
#include "mt8816.h"
#include "matrix_kbd.h"
#include "target_defs.h"
#include "io.h"

#define LED_DELAY	150

void key_callback(uint8_t	scancode,
				  uint8_t	state);

matrix_t MainMatrix;

void init_vars(void)
{
	log0("init_vars()\n");

	// We do this here, in the future we could have multiple scancode tables
	// and switch them around as needed, if we had two machines with similar 
	// tables e.g. Dragon and CoCo.
	
	MainMatrix.output=&mt_output_key;
	MainMatrix.callback=&key_callback;
	MainMatrix.ScancodeTable=NULL;
	MainMatrix.ScancodeShiftTable=NULL;
}

// Toggle the PS/2 leds so that the user knows the system is ready.
void flag_init(void)
{
	uint8_t	leds = 0;
	
	ps2_kbd_set_leds(leds);	_delay_ms(LED_DELAY);
	leds|=KBD_LED_SCROLL;
	ps2_kbd_set_leds(leds);	_delay_ms(LED_DELAY);
	leds|=KBD_LED_CAPS;
	ps2_kbd_set_leds(leds);	_delay_ms(LED_DELAY);
	leds|=KBD_LED_NUMLOCK;
	ps2_kbd_set_leds(leds);	_delay_ms(LED_DELAY);

	leds&=~KBD_LED_SCROLL;
	ps2_kbd_set_leds(leds);	_delay_ms(LED_DELAY);
	leds&=~KBD_LED_CAPS;
	ps2_kbd_set_leds(leds);	_delay_ms(LED_DELAY);
	leds&=~KBD_LED_NUMLOCK;
	ps2_kbd_set_leds(leds);	_delay_ms(LED_DELAY);
}

void key_callback(uint8_t	scancode,
				  uint8_t	state)
{
	if(state==KEY_DOWN)
	{
		switch(scancode)
		{
			case SCAN_CODE_F10 :
				log0("\n");
				break;
		}
	}
}

int main(void)
{
	Serial_Init(115200,115200);
	log0(TARGET_NAME" PS/2 Keyboard interface V1.0\n");
	log0("2021-01-06 Ramoth Software.\n");
	
	init_vars();
	
	log0("PS/2 keyboard init\n");
	ps2_kbd_init();

	mt_init();
	ScancodeInit(&MainMatrix);
	
	matrix_init(&MainMatrix);
	
	log0("I/O Init\n");
	InitIO();
	
	log0("init done!\n");
	sei();

	flag_init();

	while(1)
	{
		matrix_check_output();
		MainLoopPoll();			// Poll the I/O driver for work.
	}
	
	return 0;
}