/*
  PC Scan Code to Amstrad CPC-6128 Column/Row translation table.
   
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
#include "globalio.h"
#include "io.h"
#include "status.h"

const uint8_t ScancodeTableCPC[] PROGMEM = {
// Prefix code			Scancode				Keycode
SCAN_CODE_NO_PREFIX,	SCAN_CODE_A,			CPC_KEY_A,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_B,			CPC_KEY_B,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_C,			CPC_KEY_C,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_D,			CPC_KEY_D,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_E,			CPC_KEY_E,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F,			CPC_KEY_F,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_G,			CPC_KEY_G,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_H,			CPC_KEY_H,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_I,			CPC_KEY_I,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_J,			CPC_KEY_J,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_K,			CPC_KEY_K,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_L,			CPC_KEY_L,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_M,			CPC_KEY_M,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_N,			CPC_KEY_N,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_O,			CPC_KEY_O,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_P,			CPC_KEY_P,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Q,			CPC_KEY_Q,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_R,			CPC_KEY_R,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_S,			CPC_KEY_S,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_T,			CPC_KEY_T,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_U,			CPC_KEY_U,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_V,			CPC_KEY_V,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_W,			CPC_KEY_W,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_X,			CPC_KEY_X,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Y,			CPC_KEY_Y,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Z,			CPC_KEY_Z,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_0,			CPC_KEY_0,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_1,			CPC_KEY_1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_2,			CPC_KEY_2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_3,			CPC_KEY_3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_4,			CPC_KEY_4,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_5,			CPC_KEY_5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_6,			CPC_KEY_6,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_7,			CPC_KEY_7,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_8,			CPC_KEY_8,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_9,			CPC_KEY_9,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_ENTER,		CPC_KEY_ENTER,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SPACE,		CPC_KEY_SPACE,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LSHIFT,		CPC_KEY_SHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_RSHIFT,		CPC_KEY_SHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LCTRL,		CPC_KEY_CTRL,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP0,			CPC_KEY_F0,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP1,			CPC_KEY_F1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP2,			CPC_KEY_F2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP3,			CPC_KEY_F3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP4,			CPC_KEY_F4,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP5,			CPC_KEY_F5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP6,			CPC_KEY_F6,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP7,			CPC_KEY_F7,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP8,			CPC_KEY_F8,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KP9,			CPC_KEY_F9,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_KPPOINT,		CPC_KEY_FDOT,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_ESC,	                CPC_KEY_ESC,
SCAN_CODE_ESCAPE,	SCAN_CODE_LARROW,		CPC_KEY_LEFT,
SCAN_CODE_ESCAPE,	SCAN_CODE_RARROW,		CPC_KEY_RIGHT,
SCAN_CODE_ESCAPE,	SCAN_CODE_UARROW,		CPC_KEY_UP,
SCAN_CODE_ESCAPE,	SCAN_CODE_DARROW,		CPC_KEY_DOWN,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_BACKSPACE,	        CPC_KEY_DEL,


SCAN_CODE_NO_PREFIX,	SCAN_CODE_COMMA,		CPC_KEY_COMMA,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LSQBRACK,		CPC_KEY_AT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_RSQBRACK,		CPC_KEY_LSQBRACK,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_TILDE,		CPC_KEY_UPPOUND,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SEMICOLON,	        CPC_KEY_COLON,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_QUOTE,	        CPC_KEY_SEMICOLON,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_BSLASH,	        CPC_KEY_RSQBRACK,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_MINUS,		CPC_KEY_MINUS,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_EQUAL,		CPC_KEY_CLR,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_UK102_BS,		CPC_KEY_BSLASH,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_POINT,		CPC_KEY_POINT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SLASH,		CPC_KEY_SLASH,
SCAN_CODE_ESCAPE,	SCAN_CODE_LGUI,		        CPC_KEY_COPY,

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

const uint8_t ScancodeShiftTableCPC[] PROGMEM = {
// Prefix code			Scancode				Keycode

SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE
};




void ScancodeInit(matrix_t *ToInit)
{
  logv0("Amstrad CPC-6128 machine driver selected\n");
  ToInit->ScancodeTable=(uint8_t *)ScancodeTableCPC;
  ToInit->ScancodeShiftTable=(uint8_t *)ScancodeShiftTableCPC;
  ToInit->matrix_shift=CPC_KEY_SHIFT;
  
  ToInit->callback=&TargetKeyCallback;
  ToInit->matrix_reset=RESET_KEY;
}