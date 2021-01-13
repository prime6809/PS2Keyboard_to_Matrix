/*
 Scancode table for the TRS80 keyboard interface. 

 Adapted from PCScanCodeTo Dragon, P.Harvey-Smith, 2008-12-06.
 Tested / updated keymap on a real TRS80 Model 4, Bas Gialopsos, 2021-01-12.
 
 The TRS80 keyboard data is then output to a Zarlink MT8816 8x16 
 crosspoint switch.

 The output of the crosspoint switch is connected to the matrix 
 inputs of the target computer. 
 
 As the TRS80's matrix is 8x8, we use 8 of the rows and all 8 columns.
 
 The TRS80 keyboard is laid out as follows :-

Column	0	1	2 	3	4	5		6		7
Row 0	@	H	P	X	0	8		Enter	Left shift
Row 1	A	I	Q	Y	1	9		Clear	Right shift
Row 2	B	J	R	Z	2	*		Break	CTRL
Row 3	C	K	S		3	+		Up		Caps
Row 4	D	L	T		4	<		Dn		F1
Row 5	E	M	U		5	=		Left	F2
Row 6	F	N	V		6	>		Right	F3	
Row 7	G	O	W		7	?		Space

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

#define TRS_KEY_AT			0x00
#define TRS_KEY_A			0x10
#define TRS_KEY_B			0x20
#define TRS_KEY_C			0x30
#define TRS_KEY_D			0x40
#define TRS_KEY_E			0x50
#define TRS_KEY_F			0x60
#define TRS_KEY_G			0x70

#define TRS_KEY_H			0x01
#define TRS_KEY_I			0x11
#define TRS_KEY_J			0x21
#define TRS_KEY_K			0x31
#define TRS_KEY_L			0x41
#define TRS_KEY_M			0x51
#define TRS_KEY_N			0x61
#define TRS_KEY_O			0x71

#define TRS_KEY_P			0x02
#define TRS_KEY_Q			0x12
#define TRS_KEY_R			0x22
#define TRS_KEY_S			0x32
#define TRS_KEY_T			0x42
#define TRS_KEY_U			0x52
#define TRS_KEY_V			0x62
#define TRS_KEY_W			0x72

#define TRS_KEY_X			0x03
#define TRS_KEY_Y			0x13
#define TRS_KEY_Z			0x23
#define TRS_KEY_33			0x33
#define TRS_KEY_43			0x43
#define TRS_KEY_53			0x53
#define TRS_KEY_63			0x63
#define TRS_KEY_73			0x73

#define TRS_KEY_0			0x04
#define TRS_KEY_1			0x14
#define TRS_KEY_2			0x24
#define TRS_KEY_3			0x34
#define TRS_KEY_4			0x44
#define TRS_KEY_5			0x54
#define TRS_KEY_6			0x64
#define TRS_KEY_7			0x74

#define TRS_KEY_8			0x05
#define TRS_KEY_9			0x15
#define TRS_KEY_COLON		0x25
#define TRS_KEY_SCOLON		0x35
#define TRS_KEY_COMMA		0x45
#define TRS_KEY_MINUS		0x55
#define TRS_KEY_POINT		0x65
#define TRS_KEY_SLASH		0x75

#define TRS_KEY_ENTER		0x06
#define TRS_KEY_CLEAR		0x16
#define TRS_KEY_BREAK		0x26
#define TRS_KEY_UP			0x36
#define TRS_KEY_DOWN		0x46
#define TRS_KEY_LEFT		0x56
#define TRS_KEY_RIGHT		0x66
#define TRS_KEY_SPACE		0x76

#define TRS_KEY_LSHIFT		0x07
#define TRS_KEY_RSHIFT		0x17
#define TRS_KEY_CTRL		0x27
#define TRS_KEY_CAPS		0x37
#define TRS_KEY_F1			0x47
#define TRS_KEY_F2			0x57
#define TRS_KEY_F3			0x67
#define TRS_KEY_77			0x77

#define SHIFT_KEY	TRS_KEY_LSHIFT
#define RESET_KEY	TRS_KEY_77

void ScancodeInit(matrix_t *ToInit);
#endif