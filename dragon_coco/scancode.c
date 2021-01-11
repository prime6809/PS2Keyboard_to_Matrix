/*
  PC Scan Code to Dragon Column/Row translation table.

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

const uint8_t ScancodeTableCoCo[] PROGMEM = {
// Prefix code			Scancode				Keycode
SCAN_CODE_NO_PREFIX,	SCAN_CODE_A,			COCO_KEY_A,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_B,			COCO_KEY_B,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_C,			COCO_KEY_C,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_D,			COCO_KEY_D,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_E,			COCO_KEY_E,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F,			COCO_KEY_F,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_G,			COCO_KEY_G,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_H,			COCO_KEY_H,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_I,			COCO_KEY_I,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_J,			COCO_KEY_J,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_K,			COCO_KEY_K,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_L,			COCO_KEY_L,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_M,			COCO_KEY_M,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_N,			COCO_KEY_N,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_O,			COCO_KEY_O,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_P,			COCO_KEY_P,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Q,			COCO_KEY_Q,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_R,			COCO_KEY_R,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_S,			COCO_KEY_S,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_T,			COCO_KEY_T,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_U,			COCO_KEY_U,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_V,			COCO_KEY_V,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_W,			COCO_KEY_W,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_X,			COCO_KEY_X,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Y,			COCO_KEY_Y,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Z,			COCO_KEY_Z,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_0,			COCO_KEY_0,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_1,			COCO_KEY_1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_2,			COCO_KEY_2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_3,			COCO_KEY_3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_4,			COCO_KEY_4,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_5,			COCO_KEY_5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_6,			COCO_KEY_6,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_7,			COCO_KEY_7,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_8,			COCO_KEY_8,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_9,			COCO_KEY_9,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SPACE,		COCO_KEY_SPACE,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_POINT,		COCO_KEY_POINT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_COMMA,		COCO_KEY_COMMA,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SLASH,		COCO_KEY_SLASH,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SEMICOLON,	COCO_KEY_COLON,
//SCAN_CODE_NO_PREFIX,	SCAN_CODE_RBRACK,		COCO_KEY_RBRACK,
//SCAN_CODE_NO_PREFIX,	SCAN_CODE_LBRACK,		COCO_KEY_LBRACK,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_QUOTE,		COCO_KEY_AT,
//SCAN_CODE_NO_PREFIX,	SCAN_CODE_BSLASH,		COCO_KEY_BSLASH,
//SCAN_CODE_NO_PREFIX,	SCAN_CODE_MINUS,		COCO_KEY_MINUS,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_EQUAL,		COCO_KEY_COLON,
//SCAN_CODE_NO_PREFIX,	SCAN_CODE_TILDE,		COCO_KEY_CLARET,

//SCAN_CODE_NO_PREFIX,	SCAN_CODE_BACKSPACE,	COCO_KEY_DELETE,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_LSHIFT,		COCO_KEY_SHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LALT,			COCO_KEY_ALT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_RSHIFT,		COCO_KEY_SHIFT,
SCAN_CODE_ESCAPE,		SCAN_CODE_LGUI,			COCO_KEY_SHIFT,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_LCTRL,		COCO_KEY_CTRL,
SCAN_CODE_ESCAPE,		SCAN_CODE_RCTRL,		COCO_KEY_CTRL,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_ENTER,		COCO_KEY_ENTER,
SCAN_CODE_ESCAPE,		SCAN_CODE_KPENTER,		COCO_KEY_ENTER,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_ESC,			COCO_KEY_BREAK,
SCAN_CODE_ESCAPE,		SCAN_CODE_PAUSE,		COCO_KEY_BREAK,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_F1,			COCO_KEY_F1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F2,			COCO_KEY_F2,

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

const uint8_t ScancodeShiftTableCoCo[] PROGMEM = {
// Prefix code			Scancode				Keycode

SCAN_CODE_NO_PREFIX,	SCAN_CODE_CAPSLOCK,		COCO_KEY_CAPS,

SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE
};

const uint8_t ScancodeTableDragon[] PROGMEM = {
// Prefix code			Scancode				Keycode
SCAN_CODE_NO_PREFIX,	SCAN_CODE_A,			DRAGON_KEY_A,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_B,			DRAGON_KEY_B,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_C,			DRAGON_KEY_C,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_D,			DRAGON_KEY_D,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_E,			DRAGON_KEY_E,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F,			DRAGON_KEY_F,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_G,			DRAGON_KEY_G,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_H,			DRAGON_KEY_H,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_I,			DRAGON_KEY_I,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_J,			DRAGON_KEY_J,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_K,			DRAGON_KEY_K,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_L,			DRAGON_KEY_L,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_M,			DRAGON_KEY_M,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_N,			DRAGON_KEY_N,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_O,			DRAGON_KEY_O,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_P,			DRAGON_KEY_P,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Q,			DRAGON_KEY_Q,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_R,			DRAGON_KEY_R,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_S,			DRAGON_KEY_S,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_T,			DRAGON_KEY_T,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_U,			DRAGON_KEY_U,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_V,			DRAGON_KEY_V,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_W,			DRAGON_KEY_W,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_X,			DRAGON_KEY_X,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Y,			DRAGON_KEY_Y,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Z,			DRAGON_KEY_Z,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_0,			DRAGON_KEY_0,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_1,			DRAGON_KEY_1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_2,			DRAGON_KEY_2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_3,			DRAGON_KEY_3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_4,			DRAGON_KEY_4,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_5,			DRAGON_KEY_5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_6,			DRAGON_KEY_6,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_7,			DRAGON_KEY_7,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_8,			DRAGON_KEY_8,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_9,			DRAGON_KEY_9,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SPACE,		DRAGON_KEY_SPACE,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_POINT,		DRAGON_KEY_POINT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_COMMA,		DRAGON_KEY_COMMA,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SLASH,		DRAGON_KEY_SLASH,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SEMICOLON,	DRAGON_KEY_COLON,
//SCAN_CODE_NO_PREFIX,	SCAN_CODE_RBRACK,		DRAGON_KEY_RBRACK,
//SCAN_CODE_NO_PREFIX,	SCAN_CODE_LBRACK,		DRAGON_KEY_LBRACK,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_QUOTE,		DRAGON_KEY_AT,
//SCAN_CODE_NO_PREFIX,	SCAN_CODE_BSLASH,		DRAGON_KEY_BSLASH,
//SCAN_CODE_NO_PREFIX,	SCAN_CODE_MINUS,		DRAGON_KEY_MINUS,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_EQUAL,		DRAGON_KEY_COLON,
//SCAN_CODE_NO_PREFIX,	SCAN_CODE_TILDE,		DRAGON_KEY_CLARET,

//SCAN_CODE_NO_PREFIX,	SCAN_CODE_BACKSPACE,	DRAGON_KEY_DELETE,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_LSHIFT,		DRAGON_KEY_SHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LALT,			DRAGON_KEY_ALT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_RSHIFT,		DRAGON_KEY_SHIFT,
SCAN_CODE_ESCAPE,		SCAN_CODE_LGUI,			DRAGON_KEY_SHIFT,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_LCTRL,		DRAGON_KEY_CTRL,
SCAN_CODE_ESCAPE,		SCAN_CODE_RCTRL,		DRAGON_KEY_CTRL,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_ENTER,		DRAGON_KEY_ENTER,
SCAN_CODE_ESCAPE,		SCAN_CODE_KPENTER,		DRAGON_KEY_ENTER,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_ESC,			DRAGON_KEY_BREAK,
SCAN_CODE_ESCAPE,		SCAN_CODE_PAUSE,		DRAGON_KEY_BREAK,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_F1,			DRAGON_KEY_F1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F2,			DRAGON_KEY_F2,

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

const uint8_t ScancodeShiftTableDragon[] PROGMEM = {
// Prefix code			Scancode				Keycode

SCAN_CODE_NO_PREFIX,	SCAN_CODE_CAPSLOCK,		DRAGON_KEY_CAPS,

SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE
};


void ScancodeInit(matrix_t *ToInit)
{
	log0("ScancodeInit()\n");
	if(IsDragon)
	{
		ToInit->ScancodeTable=(ptable_t)&ScancodeTableDragon;
		ToInit->ScancodeShiftTable=(ptable_t)&ScancodeShiftTableDragon;
		ToInit->matrix_shift=DRAGON_KEY_SHIFT;
	}
	else
	{
		ToInit->ScancodeTable=(ptable_t)&ScancodeTableCoCo;
		ToInit->ScancodeShiftTable=(ptable_t)&ScancodeShiftTableCoCo;
		ToInit->matrix_shift=COCO_KEY_SHIFT;
	}	
	
	ToInit->matrix_reset=RESET_KEY;
}