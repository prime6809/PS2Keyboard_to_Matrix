/*
 Scancode table for the Dragon 32/64/Alpha and Tandy CoCo 1/2/3 keyboard interface. 

 The Dragon/CoCo keyboard data is then output to a Zarlink MT8816 8x16 
 crosspoint switch.

 The output of the crosspoint switch is connected to the matrix 
 inputs of the target computer. 
 
 As the Dragon/CoCo's matrix is 8x8, we use 8 of the rows and all 8 columns.
 
 The CoCo keyboard is laid out as follows :-

Column		0		1		2 		3		4		5		6		7
Row 0		@		A		B		C		D		E		F		G
Row 1		H		I		J		K		L		M		N		O
Row 2		P		Q		R		S		T		U		V		W
Row 3		X		Y		Z		Up		Down	Left	Right	Space
Row 4		0		1		2		3		4		5		6		7
Row 5		8		9		:		;		,		-		.		/
Row 6		Enter	Clear	Break	ALT**	CTRL**	F1**	F2**	Shift

Keys marked ** on CoCo 3 only.

 The Dragon keyboard is laid out as follows :-

Column		0		1		2 		3		4		5		6		7
Row 0		0		1		2		3		4		5		6		7
Row 1		8		9		:		;		,		-		.		/
Row 2		@		A		B		C		D		E		F		G
Row 3		H		I		J		K		L		M		N		O
Row 4		P		Q		R		S		T		U		V		W
Row 5		X		Y		Z		Up		Down	Left	Right	Space
Row 6		Enter	Clear	Break	ALT**	CTRL**	F1**	F2**	Shift

Fot the following key definition constants, the high nibble and 0x70 represent the 
ROW of the pressed key, and the low nibble represents the COLUMN. Bit 7 is ignored, 
as this is used by the matrix handling code to flag a key pressed or released.
*/

#ifndef __SCANCODES__
#define __SCANCODES__

#include <inttypes.h>
#include <avr/pgmspace.h> 
#include "ps2scancode.h"
#include "matrix_kbd.h"

#define COCO_KEY_AT			0x00
#define COCO_KEY_A			0x01
#define COCO_KEY_B			0x02
#define COCO_KEY_C			0x03
#define COCO_KEY_D			0x04
#define COCO_KEY_E			0x05
#define COCO_KEY_F			0x06
#define COCO_KEY_G			0x07

#define COCO_KEY_H			0x10
#define COCO_KEY_I			0x11
#define COCO_KEY_J			0x12
#define COCO_KEY_K			0x13
#define COCO_KEY_L			0x14
#define COCO_KEY_M			0x15
#define COCO_KEY_N			0x16
#define COCO_KEY_O			0x17

#define COCO_KEY_P			0x20
#define COCO_KEY_Q			0x21
#define COCO_KEY_R			0x22
#define COCO_KEY_S			0x23
#define COCO_KEY_T			0x24
#define COCO_KEY_U			0x25
#define COCO_KEY_V			0x26
#define COCO_KEY_W			0x27

#define COCO_KEY_X			0x30
#define COCO_KEY_Y			0x31
#define COCO_KEY_Z			0x32
#define COCO_KEY_UP			0x33
#define COCO_KEY_DOWN		0x34
#define COCO_KEY_LEFT		0x35
#define COCO_KEY_RIGHT		0x36
#define COCO_KEY_SPACE		0x37

#define COCO_KEY_0			0x40
#define COCO_KEY_1			0x41
#define COCO_KEY_2			0x42
#define COCO_KEY_3			0x43
#define COCO_KEY_4			0x44
#define COCO_KEY_5			0x45
#define COCO_KEY_6			0x46
#define COCO_KEY_7			0x47

#define COCO_KEY_8			0x50
#define COCO_KEY_9			0x51
#define COCO_KEY_COLON		0x52
#define COCO_KEY_SEMI		0x53
#define COCO_KEY_COMMA		0x54
#define COCO_KEY_EQUAL		0x55
#define COCO_KEY_POINT		0x56
#define COCO_KEY_SLASH		0x57

#define COCO_KEY_ENTER		0x60
#define COCO_KEY_CLEAR		0x61
#define COCO_KEY_BREAK		0x62
#define COCO_KEY_ALT		0x63
#define COCO_KEY_CTRL		0x64
#define COCO_KEY_F1			0x65
#define COCO_KEY_F2			0x66
#define COCO_KEY_SHIFT		0x67

#define RESET_KEY			0xff
#define COCO_KEY_CAPS		COCO_KEY_0

#define DRAGON_KEY_0		0x00
#define DRAGON_KEY_1		0x01
#define DRAGON_KEY_2		0x02
#define DRAGON_KEY_3		0x03
#define DRAGON_KEY_4		0x04
#define DRAGON_KEY_5		0x05
#define DRAGON_KEY_6		0x06
#define DRAGON_KEY_7		0x07

#define DRAGON_KEY_8		0x10
#define DRAGON_KEY_9		0x11
#define DRAGON_KEY_COLON	0x12
#define DRAGON_KEY_SEMI		0x13
#define DRAGON_KEY_COMMA	0x14
#define DRAGON_KEY_EQUAL	0x15
#define DRAGON_KEY_POINT	0x16
#define DRAGON_KEY_SLASH	0x17

#define DRAGON_KEY_AT		0x20
#define DRAGON_KEY_A		0x21
#define DRAGON_KEY_B		0x22
#define DRAGON_KEY_C		0x23
#define DRAGON_KEY_D		0x24
#define DRAGON_KEY_E		0x25
#define DRAGON_KEY_F		0x26
#define DRAGON_KEY_G		0x27

#define DRAGON_KEY_H		0x30
#define DRAGON_KEY_I		0x31
#define DRAGON_KEY_J		0x32
#define DRAGON_KEY_K		0x33
#define DRAGON_KEY_L		0x34
#define DRAGON_KEY_M		0x35
#define DRAGON_KEY_N		0x36
#define DRAGON_KEY_O		0x37

#define DRAGON_KEY_P		0x40
#define DRAGON_KEY_Q		0x41
#define DRAGON_KEY_R		0x42
#define DRAGON_KEY_S		0x43
#define DRAGON_KEY_T		0x44
#define DRAGON_KEY_U		0x45
#define DRAGON_KEY_V		0x46
#define DRAGON_KEY_W		0x47

#define DRAGON_KEY_X		0x50
#define DRAGON_KEY_Y		0x51
#define DRAGON_KEY_Z		0x52
#define DRAGON_KEY_UP		0x53
#define DRAGON_KEY_DOWN		0x54
#define DRAGON_KEY_LEFT		0x55
#define DRAGON_KEY_RIGHT	0x56
#define DRAGON_KEY_SPACE	0x57

#define DRAGON_KEY_ENTER	0x60
#define DRAGON_KEY_CLEAR	0x61
#define DRAGON_KEY_BREAK	0x62
#define DRAGON_KEY_ALT		0x63
#define DRAGON_KEY_CTRL		0x64
#define DRAGON_KEY_F1		0x65
#define DRAGON_KEY_F2		0x66
#define DRAGON_KEY_SHIFT	0x67

#define DRAGON_KEY_CAPS		DRAGON_KEY_0

void ScancodeInit(matrix_t *ToInit);
#endif