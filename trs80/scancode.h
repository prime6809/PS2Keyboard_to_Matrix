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

// Keycodes where Pin 1 on interface connected to 1 on TRS80
// This needs pairs of connectors swapped in the cable as
// The TRS80 Model 3's keyboard connector has the odd numbered 
// pins on the right, even on the left!

#define TRS_KEY0_AT			0x00
#define TRS_KEY0_A			0x10
#define TRS_KEY0_B			0x20
#define TRS_KEY0_C			0x30
#define TRS_KEY0_D			0x40
#define TRS_KEY0_E			0x50
#define TRS_KEY0_F			0x60
#define TRS_KEY0_G			0x70

#define TRS_KEY0_H			0x01
#define TRS_KEY0_I			0x11
#define TRS_KEY0_J			0x21
#define TRS_KEY0_K			0x31
#define TRS_KEY0_L			0x41
#define TRS_KEY0_M			0x51
#define TRS_KEY0_N			0x61
#define TRS_KEY0_O			0x71

#define TRS_KEY0_P			0x02
#define TRS_KEY0_Q			0x12
#define TRS_KEY0_R			0x22
#define TRS_KEY0_S			0x32
#define TRS_KEY0_T			0x42
#define TRS_KEY0_U			0x52
#define TRS_KEY0_V			0x62
#define TRS_KEY0_W			0x72

#define TRS_KEY0_X			0x03
#define TRS_KEY0_Y			0x13
#define TRS_KEY0_Z			0x23
#define TRS_KEY0_33			0x33
#define TRS_KEY0_43			0x43
#define TRS_KEY0_53			0x53
#define TRS_KEY0_63			0x63
#define TRS_KEY0_73			0x73

#define TRS_KEY0_0			0x04
#define TRS_KEY0_1			0x14
#define TRS_KEY0_2			0x24
#define TRS_KEY0_3			0x34
#define TRS_KEY0_4			0x44
#define TRS_KEY0_5			0x54
#define TRS_KEY0_6			0x64
#define TRS_KEY0_7			0x74

#define TRS_KEY0_8			0x05
#define TRS_KEY0_9			0x15
#define TRS_KEY0_COLON		0x25
#define TRS_KEY0_SCOLON		0x35
#define TRS_KEY0_COMMA		0x45
#define TRS_KEY0_MINUS		0x55
#define TRS_KEY0_POINT		0x65
#define TRS_KEY0_SLASH		0x75

#define TRS_KEY0_ENTER		0x06
#define TRS_KEY0_CLEAR		0x16
#define TRS_KEY0_BREAK		0x26
#define TRS_KEY0_UP			0x36
#define TRS_KEY0_DOWN		0x46
#define TRS_KEY0_LEFT		0x56
#define TRS_KEY0_RIGHT		0x66
#define TRS_KEY0_SPACE		0x76

#define TRS_KEY0_LSHIFT		0x07
#define TRS_KEY0_RSHIFT		0x17
#define TRS_KEY0_CTRL		0x27
#define TRS_KEY0_CAPS		0x37
#define TRS_KEY0_F1			0x47
#define TRS_KEY0_F2			0x57
#define TRS_KEY0_F3			0x67
#define TRS_KEY0_77			0x77

#define TRS_KEY0_RESET		0xFF

// This is for a straight cable, which logically swapps the lines. 

#define TRS_KEY1_I			0x00
#define TRS_KEY1_H			0x10
#define TRS_KEY1_K			0x20
#define TRS_KEY1_J			0x30
#define TRS_KEY1_M			0x40
#define TRS_KEY1_L			0x50
#define TRS_KEY1_O			0x60
#define TRS_KEY1_N			0x70

#define TRS_KEY1_A			0x01
#define TRS_KEY1_AT			0x11
#define TRS_KEY1_C			0x21
#define TRS_KEY1_B			0x31
#define TRS_KEY1_E			0x41
#define TRS_KEY1_D			0x51
#define TRS_KEY1_G			0x61
#define TRS_KEY1_F			0x71

#define TRS_KEY1_Y			0x02
#define TRS_KEY1_X			0x12
#define TRS_KEY1_33			0x22
#define TRS_KEY1_Z			0x23
#define TRS_KEY1_53			0x24
#define TRS_KEY1_43			0x25
#define TRS_KEY1_73			0x26
#define TRS_KEY1_63			0x27

#define TRS_KEY1_Q			0x03
#define TRS_KEY1_P			0x13
#define TRS_KEY1_S			0x23
#define TRS_KEY1_R			0x33
#define TRS_KEY1_U			0x43
#define TRS_KEY1_T			0x53
#define TRS_KEY1_W			0x63
#define TRS_KEY1_V			0x73

#define TRS_KEY1_9			0x04
#define TRS_KEY1_8			0x14
#define TRS_KEY1_SCOLON		0x24
#define TRS_KEY1_COLON		0x34
#define TRS_KEY1_MINUS		0x44
#define TRS_KEY1_COMMA		0x54
#define TRS_KEY1_SLASH		0x64
#define TRS_KEY1_POINT		0x74

#define TRS_KEY1_1			0x05
#define TRS_KEY1_0			0x15
#define TRS_KEY1_3			0x25
#define TRS_KEY1_2			0x35
#define TRS_KEY1_5			0x45
#define TRS_KEY1_4			0x55
#define TRS_KEY1_7			0x65
#define TRS_KEY1_6			0x75

#define TRS_KEY1_RSHIFT		0x06
#define TRS_KEY1_LSHIFT		0x16
#define TRS_KEY1_CAPS		0x26
#define TRS_KEY1_CTRL		0x36
#define TRS_KEY1_F2			0x46
#define TRS_KEY1_F1			0x56
#define TRS_KEY1_77			0x66
#define TRS_KEY1_F3			0x76

#define TRS_KEY1_CLEAR		0x07
#define TRS_KEY1_ENTER		0x17
#define TRS_KEY1_UP			0x27
#define TRS_KEY1_BREAK		0x37
#define TRS_KEY1_LEFT		0x47
#define TRS_KEY1_DOWN		0x57
#define TRS_KEY1_SPACE		0x67
#define TRS_KEY1_RIGHT		0x77

#define TRS_KEY1_RESET		0xFF

#define SHIFT_KEY	TRS_KEY1_LSHIFT
#define RESET_KEY	TRS_KEY1_RESET

void ScancodeInit(matrix_t *ToInit);
#endif