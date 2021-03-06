/*
  PC Scan Code to Acorn BBC A/B/B+ Column/Row translation table.
  
  Note the BBC A/B/B+ will need extra hardware beyond the matrix output,
  this is to replicate the circuit surrounding the matrix on a real BBC
  keyboard.
  
  Encoded as follows, 
  Each record consists of 3 bytes :-
 
  1) The prefix code, either SCAN_CODE_NO_PREFIX, or SCAN_CODE_ESCAPE
  2) The PC scan code to check for, from scancode.h
  3) The target key it represents, from constant table above.

  This table should ONLY contain mappings for which there is a valid
  output key.

  Working out this table took far too long !!!!
*/

#include "scancode.h"

const uint8_t ScancodeTableBBC[] PROGMEM = {
// Prefix code			Scancode				Keycode
SCAN_CODE_NO_PREFIX,	SCAN_CODE_A,			BBC_KEY_A,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_B,			BBC_KEY_B,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_C,			BBC_KEY_C,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_D,			BBC_KEY_D,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_E,			BBC_KEY_E,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F,			BBC_KEY_F,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_G,			BBC_KEY_G,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_H,			BBC_KEY_H,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_I,			BBC_KEY_I,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_J,			BBC_KEY_J,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_K,			BBC_KEY_K,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_L,			BBC_KEY_L,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_M,			BBC_KEY_M,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_N,			BBC_KEY_N,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_O,			BBC_KEY_O,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_P,			BBC_KEY_P,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Q,			BBC_KEY_Q,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_R,			BBC_KEY_R,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_S,			BBC_KEY_S,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_T,			BBC_KEY_T,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_U,			BBC_KEY_U,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_V,			BBC_KEY_V,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_W,			BBC_KEY_W,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_X,			BBC_KEY_X,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Y,			BBC_KEY_Y,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Z,			BBC_KEY_Z,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_0,			BBC_KEY_0,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_1,			BBC_KEY_1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_2,			BBC_KEY_2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_3,			BBC_KEY_3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_4,			BBC_KEY_4,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_5,			BBC_KEY_5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_6,			BBC_KEY_6,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_7,			BBC_KEY_7,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_8,			BBC_KEY_8,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_9,			BBC_KEY_9,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_ENTER,		BBC_KEY_ENTER,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SPACE,		BBC_KEY_SPACE,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LSHIFT,		BBC_KEY_SHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_RSHIFT,		BBC_KEY_SHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LCTRL,		BBC_KEY_CTRL,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_F1,			BBC_KEY_F0,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F1,			BBC_KEY_F1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F2,			BBC_KEY_F2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F3,			BBC_KEY_F3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F4,			BBC_KEY_F4,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F5,			BBC_KEY_F5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F6,			BBC_KEY_F6,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F7,			BBC_KEY_F7,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F8,			BBC_KEY_F8,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F9,			BBC_KEY_F9,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_TAB,			BBC_KEY_TAB,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_TILDE,		BBC_KEY_AT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LALT,			BBC_KEY_SHIFTLK,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_ESC,			BBC_KEY_ESC,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_COMMA,		BBC_KEY_COMMA,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_POINT,		BBC_KEY_PERIOD,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SLASH,		BBC_KEY_SLASH,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SEMICOLON,	BBC_KEY_SEMI,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_MINUS,		BBC_KEY_MINUS,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_QUOTE,		BBC_KEY_COLON,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LSQBRACK,		BBC_KEY_LEFTSB,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_RSQBRACK,		BBC_KEY_RIGHTSB,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_EQUAL,		BBC_KEY_CLARET,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_CAPSLOCK,		BBC_KEY_CAPS,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_BSLASH,		BBC_KEY_UNDER,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_UK102_BS,		BBC_KEY_PIPE,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_BACKSPACE,	BBC_KEY_DEL,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_ESC,			BBC_KEY_ESC,

SCAN_CODE_ESCAPE,		SCAN_CODE_RALT,			BBC_KEY_COPY,
SCAN_CODE_ESCAPE,		SCAN_CODE_RCTRL,		BBC_KEY_CTRL,
SCAN_CODE_ESCAPE,		SCAN_CODE_END,			BBC_KEY_COPY,
SCAN_CODE_ESCAPE,		SCAN_CODE_LARROW,		BBC_KEY_LEFT,
SCAN_CODE_ESCAPE,		SCAN_CODE_RARROW,		BBC_KEY_RIGHT,
SCAN_CODE_ESCAPE,		SCAN_CODE_UARROW,		BBC_KEY_UP,
SCAN_CODE_ESCAPE,		SCAN_CODE_DARROW,		BBC_KEY_DOWN,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP0,			BBC_KEY_0,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP1,			BBC_KEY_1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP2,			BBC_KEY_2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP3,			BBC_KEY_3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP4,			BBC_KEY_4,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP5,			BBC_KEY_5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP6,			BBC_KEY_6,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP7,			BBC_KEY_7,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP8,			BBC_KEY_8,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP9,			BBC_KEY_9,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_NUMLOCK,		BBC_KEY_COMMA,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KPPLUS,		BBC_KEY_COLON,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KPMINUS,		BBC_KEY_MINUS,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KPSTAR,		BBC_KEY_COLON,

SCAN_CODE_ESCAPE,		SCAN_CODE_KPSLASH,		BBC_KEY_SLASH,
SCAN_CODE_ESCAPE,		SCAN_CODE_KPENTER,		BBC_KEY_ENTER,
//SCAN_CODE_ESCAPE,		SCAN_CODE_INSERT,		BBC_KEY_HASH,
SCAN_CODE_ESCAPE,		SCAN_CODE_DELETE,		BBC_KEY_DEL,

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

const uint8_t ScancodeShiftTableBBC[] PROGMEM = {
// Prefix code			Scancode				Keycode

SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE
};

void ScancodeInit(matrix_t *ToInit)
{
	ToInit->ScancodeTable=(uint8_t *)ScancodeTableBBC;
	ToInit->ScancodeShiftTable=(uint8_t *)ScancodeShiftTableBBC;
	ToInit->matrix_shift=BBC_KEY_SHIFT;
	ToInit->matrix_reset=RESET_KEY;
}
