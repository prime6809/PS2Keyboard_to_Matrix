/* 
	mt8816.c
	
	Driver for handling the MT8816 crosspoint switch.
	
	2011-04-27, Seperated from generic matrix code.
*/

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "mt8816.h"
#include "status.h"
#include "matrix_kbd.h"
#include "scancode.h"

#define	MT_KEY_DOWN	0x80

// Reset the MT8816
static void mt_reset(void)
{
	// Reset the MT8816, this clears all keypresses.
	MTAssertReset();			
	_delay_ms(1);
	MTClearReset();
	MTClearStrobe();
}


// MT_init, initialise MT8816 and keyboard variables.
void mt_init(void)
{
	// Initialise output ports connected to MT8816
	MT_KEYS_DDR |= 0xFF;
	MT_CTRL_DDR	|= ((1<<MT_RESET) | (1<<MT_STROBE));
	mt_reset();
	logv0("MT8816 driver initialised\n");
}

/* 
	Latch keypress out to MT8816.
	
	KeyCode should be formatted as follows :-
	b7		= Don't care, masked out.
	b6..b4	= Row Data fed to AY2..0
	b3..b0	= Col data fed to AX3..0
*/	

void mt_output_key(uint8_t	KeyCode,
				   uint8_t	State)
{
	switch (KeyCode)
	{
		case 0xFF :
			break;
		
		default :
			// combine code and up/down state
			if (State==KEY_DOWN)
				KeyCode|=MT_KEY_DOWN;
			else
				KeyCode&=~MT_KEY_DOWN;
			
			// output matrix code, and assert strobe to MT8816
			MT_KEYS_PORT=KeyCode;
			MTAssertStrobe();
    
			// Wait a while for it to settle, then clear strobe
			_delay_us(10);
			MTClearStrobe();
			break;
	}
}
