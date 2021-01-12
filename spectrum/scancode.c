/*
  PC Scan Code to ZX81 Column/Row translation table.

  Encoded as follows, 
  Each record consists of 3 bytes :-
 
  1) The prefix code, either SCAN_CODE_NO_PREFIX, or SCAN_CODE_ESCAPE
  2) The PC scan code to check for, from scancode.h
  3) The target machine key it represents, from constant table (scancode.h).

  This table should ONLY contain mappings for which there is a valid
  output key.

  Working out this table took far too long !!!!
*/

#include "scancode.h"
#include "io.h"
#include "status.h"

const uint8_t ScancodeTableZX8X[] PROGMEM = {
// Prefix code			Scancode				Keycode
SCAN_CODE_NO_PREFIX,	SCAN_CODE_A,			ZXSP_KEY_A,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_B,			ZXSP_KEY_B,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_C,			ZXSP_KEY_C,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_D,			ZXSP_KEY_D,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_E,			ZXSP_KEY_E,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F,			ZXSP_KEY_F,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_G,			ZXSP_KEY_G,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_H,			ZXSP_KEY_H,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_I,			ZXSP_KEY_I,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_J,			ZXSP_KEY_J,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_K,			ZXSP_KEY_K,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_L,			ZXSP_KEY_L,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_M,			ZXSP_KEY_M,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_N,			ZXSP_KEY_N,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_O,			ZXSP_KEY_O,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_P,			ZXSP_KEY_P,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Q,			ZXSP_KEY_Q,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_R,			ZXSP_KEY_R,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_S,			ZXSP_KEY_S,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_T,			ZXSP_KEY_T,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_U,			ZXSP_KEY_U,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_V,			ZXSP_KEY_V,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_W,			ZXSP_KEY_W,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_X,			ZXSP_KEY_X,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Y,			ZXSP_KEY_Y,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Z,			ZXSP_KEY_Z,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_0,			ZXSP_KEY_0,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_1,			ZXSP_KEY_1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_2,			ZXSP_KEY_2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_3,			ZXSP_KEY_3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_4,			ZXSP_KEY_4,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_5,			ZXSP_KEY_5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_6,			ZXSP_KEY_6,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_7,			ZXSP_KEY_7,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_8,			ZXSP_KEY_8,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_9,			ZXSP_KEY_9,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_ENTER,		ZXSP_KEY_ENTER,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SPACE,		ZXSP_KEY_SPACE,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LSHIFT,		ZXSP_KEY_CSHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_RSHIFT,		ZXSP_KEY_CSHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LCTRL,		ZXSP_KEY_SSHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_RCTRL,		ZXSP_KEY_SSHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_ESC,			ZXSP_KEY_SPACE,

SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE
};


/*
  The shift key table, this has the same format as the above standard 
  key table, however when one of these keys is pressed, the output shift 
  key will also be pressed before the key, and released after the key.
	
  This allows as single PC key to translate to a SHIFT-KEY combination 
  on the output matrix. 
  
  A similar method could be used for other modifier keys.
*/

const uint8_t ScancodeShiftTableZX8X[] PROGMEM = {
// Prefix code			Scancode				Keycode
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LCTRL,		ZXSP_KEY_ENTER,	// Shift-enter = function
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LALT,			ZXSP_KEY_9,		// Shift-9 = graphics mode
SCAN_CODE_NO_PREFIX,	SCAN_CODE_BACKSPACE,	ZXSP_KEY_0,		// shift-0 = delete

SCAN_CODE_ESCAPE,		SCAN_CODE_LARROW,		ZXSP_KEY_5,		// Curosrs, left,down,up,right
SCAN_CODE_ESCAPE,		SCAN_CODE_DARROW,		ZXSP_KEY_6,
SCAN_CODE_ESCAPE,		SCAN_CODE_UARROW,		ZXSP_KEY_7,
SCAN_CODE_ESCAPE,		SCAN_CODE_RARROW,		ZXSP_KEY_8,
SCAN_CODE_ESCAPE,		SCAN_CODE_RALT,			ZXSP_KEY_1,		// shift-1 = edit

SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE
};

void ScancodeInit(matrix_t *ToInit)
{
	log0("ScancodeInit()\n");
	ToInit->ScancodeTable=(ptable_t)&ScancodeTableZX8X;
	ToInit->ScancodeShiftTable=(ptable_t)&ScancodeShiftTableZX8X;
	ToInit->matrix_shift=ZXSP_KEY_CSHIFT;
	ToInit->matrix_reset=RESET_KEY;
}