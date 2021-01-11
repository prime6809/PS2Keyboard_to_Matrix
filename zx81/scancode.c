/*
  PC Scan Code to ZX80/ZX81 Column/Row translation table.

  Encoded as follows, 
  Each record consists of 3 bytes :-
 
  1) The prefix code, either SCAN_CODE_NO_PREFIX, or SCAN_CODE_ESCAPE
  2) The PC scan code to check for, from scancode.h
  3) The target machine key it represents, from constant table (scancode.h>.

  This table should ONLY contain mappings for which there is a valid
  output key.

  Working out this table took far too long !!!!
*/

#include "scancode.h"
#include "io.h"
#include "status.h"

const uint8_t ScancodeTableZX8X[] PROGMEM = {
// Prefix code			Scancode				Keycode
SCAN_CODE_NO_PREFIX,	SCAN_CODE_A,			ZX8X_KEY_A,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_B,			ZX8X_KEY_B,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_C,			ZX8X_KEY_C,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_D,			ZX8X_KEY_D,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_E,			ZX8X_KEY_E,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F,			ZX8X_KEY_F,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_G,			ZX8X_KEY_G,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_H,			ZX8X_KEY_H,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_I,			ZX8X_KEY_I,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_J,			ZX8X_KEY_J,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_K,			ZX8X_KEY_K,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_L,			ZX8X_KEY_L,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_M,			ZX8X_KEY_M,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_N,			ZX8X_KEY_N,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_O,			ZX8X_KEY_O,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_P,			ZX8X_KEY_P,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Q,			ZX8X_KEY_Q,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_R,			ZX8X_KEY_R,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_S,			ZX8X_KEY_S,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_T,			ZX8X_KEY_T,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_U,			ZX8X_KEY_U,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_V,			ZX8X_KEY_V,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_W,			ZX8X_KEY_W,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_X,			ZX8X_KEY_X,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Y,			ZX8X_KEY_Y,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Z,			ZX8X_KEY_Z,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_0,			ZX8X_KEY_0,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_1,			ZX8X_KEY_1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_2,			ZX8X_KEY_2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_3,			ZX8X_KEY_3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_4,			ZX8X_KEY_4,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_5,			ZX8X_KEY_5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_6,			ZX8X_KEY_6,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_7,			ZX8X_KEY_7,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_8,			ZX8X_KEY_8,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_9,			ZX8X_KEY_9,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_ENTER,		ZX8X_KEY_ENTER,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SPACE,		ZX8X_KEY_SPACE,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_POINT,		ZX8X_KEY_POINT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LSHIFT,		ZX8X_KEY_SHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_RSHIFT,		ZX8X_KEY_SHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_ESC,			ZX8X_KEY_SPACE,

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
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LCTRL,		ZX8X_KEY_ENTER,	// Shift-enter = function
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LALT,			ZX8X_KEY_9,		// Shift-9 = graphics mode
SCAN_CODE_NO_PREFIX,	SCAN_CODE_BACKSPACE,	ZX8X_KEY_0,		// shift-0 = delete

SCAN_CODE_ESCAPE,		SCAN_CODE_LARROW,		ZX8X_KEY_5,		// Curosrs, left,down,up,right
SCAN_CODE_ESCAPE,		SCAN_CODE_DARROW,		ZX8X_KEY_6,
SCAN_CODE_ESCAPE,		SCAN_CODE_UARROW,		ZX8X_KEY_7,
SCAN_CODE_ESCAPE,		SCAN_CODE_RARROW,		ZX8X_KEY_8,
SCAN_CODE_ESCAPE,		SCAN_CODE_RALT,			ZX8X_KEY_1,		// shift-1 = edit
SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE
};

void ScancodeInit(matrix_t *ToInit)
{
	log0("ScancodeInit()\n");
	ToInit->ScancodeTable=(ptable_t)&ScancodeTableZX8X;
	ToInit->ScancodeShiftTable=(ptable_t)&ScancodeShiftTableZX8X;
	ToInit->matrix_shift=ZX8X_KEY_SHIFT;
	ToInit->matrix_reset=RESET_KEY;
}