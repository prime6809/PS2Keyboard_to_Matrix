/*
 Scancode table for the Commodore 64 and VIC-20 keyboard interface. 

 Adapted from PCScanCodeTo Dragon, P.Harvey-Smith, 2008-12-06.
 
 The target computer keyboard data is then output to a Zarlink MT8816 8x16 
 crosspoint switch.

The Commodore 64 and VIC-20 have the same keyboard matrix (the C16 may also
be so similar this can be used for it too).

The only oddity about the Commodore keyboards is that the Shift lock key is
a pysical toggle key, so we need to emulate this.

    C0      C1      C2      C3      C4      C5      C6      C7     

R0  DEL		Return	CRSRLR	F7/F8	F1/F2	F3/F4	F5/F6	CRSRUD
R1  3		W		A		4		Z		S		E		LSHIFT
R2  5		R		D		6		C		F		T		X
R3  7		Y		G		8		B		H		U		V
R4  9		I		J		0		M		K		O		N
R5  +		P		L		-		.		:		@		,
R6  £		*		;		HOME	RSHIFT	=		Up		/
R7  1		Left	CTRL	2		Space	Comm	Q		RSTOP

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

#define C64VIC_KEY_DEL			0x00
#define C64VIC_KEY_ENTER		0x01
#define C64VIC_KEY_CRSRLR		0x02
#define C64VIC_KEY_F7			0x03
#define C64VIC_KEY_F1			0x04
#define C64VIC_KEY_F3			0x05
#define C64VIC_KEY_F5			0x06
#define C64VIC_KEY_CRSRUD		0x07

#define C64VIC_KEY_3			0x10
#define C64VIC_KEY_W			0x11
#define C64VIC_KEY_A			0x12
#define C64VIC_KEY_4			0x13
#define C64VIC_KEY_Z			0x14
#define C64VIC_KEY_S			0x15
#define C64VIC_KEY_E			0x16
#define C64VIC_KEY_LSHIFT		0x17

#define C64VIC_KEY_5			0x20
#define C64VIC_KEY_R			0x21
#define C64VIC_KEY_D			0x22
#define C64VIC_KEY_6			0x23
#define C64VIC_KEY_C			0x24
#define C64VIC_KEY_F			0x25
#define C64VIC_KEY_T			0x26
#define C64VIC_KEY_X			0x27

#define C64VIC_KEY_7			0x30
#define C64VIC_KEY_Y			0x31
#define C64VIC_KEY_G			0x32
#define C64VIC_KEY_8			0x33
#define C64VIC_KEY_B			0x34
#define C64VIC_KEY_H			0x35
#define C64VIC_KEY_U			0x36
#define C64VIC_KEY_V			0x37

#define C64VIC_KEY_9			0x40
#define C64VIC_KEY_I			0x41
#define C64VIC_KEY_J			0x42
#define C64VIC_KEY_0			0x43
#define C64VIC_KEY_M			0x44
#define C64VIC_KEY_K			0x45
#define C64VIC_KEY_O			0x46
#define C64VIC_KEY_N			0x47

#define C64VIC_KEY_PLUS			0x50
#define C64VIC_KEY_P			0x51
#define C64VIC_KEY_L			0x52
#define C64VIC_KEY_MINUS		0x53
#define C64VIC_KEY_POINT		0x54
#define C64VIC_KEY_COLON		0x55
#define C64VIC_KEY_AT			0x56
#define C64VIC_KEY_COMMA		0x57

#define C64VIC_KEY_POUND		0x60
#define C64VIC_KEY_STAR			0x61
#define C64VIC_KEY_SEMI			0x62
#define C64VIC_KEY_HOME			0x63
#define C64VIC_KEY_RSHIFT		0x64
#define C64VIC_KEY_EQUAL		0x65
#define C64VIC_KEY_UP			0x66
#define C64VIC_KEY_SLASH		0x67

#define C64VIC_KEY_1			0x70
#define C64VIC_KEY_LEFT			0x71
#define C64VIC_KEY_CTRL			0x72
#define C64VIC_KEY_2			0x73
#define C64VIC_KEY_SPACE		0x74
#define C64VIC_KEY_CDORE		0x75
#define C64VIC_KEY_Q			0x76
#define C64VIC_KEY_RUNSTP		0x77

//#define SHIFT_KEY	C64VIC_KEY_LSHIFT
#define RESET_KEY	0xFF

/* 

The Commodore 16 and Plus 4 (and presumabley 116) have the same keyboard matrix.
This is almost the same as the VIC-20/C64 matrix.

The only oddity about the Commodore keyboards is that the Shift lock key is
a pysical toggle key, so we need to emulate this.

    C0      C1      C2      C3      C4      C5      C6      C7     

R0  DEL		Return	£		Help	F1/F4	F2/F5	F3/F6	@
R1  3		W		A		4		Z		S		E		SHIFT
R2  5		R		D		6		C		F		T		X
R3  7		Y		G		8		B		H		U		V
R4  9		I		J		0		M		K		O		N
R5  Down	P		L		Up		.		:		-		,
R6  Left	*		;		Right	ESC		=		+		/
R7  1		CLRHOME	CTRL	2		Space	Comm	Q		RSTOP
*/

#define C16P4_KEY_DEL			0x00
#define C16P4_KEY_ENTER			0x01
#define C16P4_KEY_POUND			0x02
#define C16P4_KEY_HELP			0x03
#define C16P4_KEY_F1			0x04
#define C16P4_KEY_F2			0x05
#define C16P4_KEY_F3			0x06
#define C16P4_KEY_AT			0x07

#define C16P4_KEY_3				0x10
#define C16P4_KEY_W				0x11
#define C16P4_KEY_A				0x12
#define C16P4_KEY_4				0x13
#define C16P4_KEY_Z				0x14
#define C16P4_KEY_S				0x15
#define C16P4_KEY_E				0x16
#define C16P4_KEY_SHIFT			0x17

#define C16P4_KEY_5				0x20
#define C16P4_KEY_R				0x21
#define C16P4_KEY_D				0x22
#define C16P4_KEY_6				0x23
#define C16P4_KEY_C				0x24
#define C16P4_KEY_F				0x25
#define C16P4_KEY_T				0x26
#define C16P4_KEY_X				0x27

#define C16P4_KEY_7				0x30
#define C16P4_KEY_Y				0x31
#define C16P4_KEY_G				0x32
#define C16P4_KEY_8				0x33
#define C16P4_KEY_B				0x34
#define C16P4_KEY_H				0x35
#define C16P4_KEY_U				0x36
#define C16P4_KEY_V				0x37

#define C16P4_KEY_9				0x40
#define C16P4_KEY_I				0x41
#define C16P4_KEY_J				0x42
#define C16P4_KEY_0				0x43
#define C16P4_KEY_M				0x44
#define C16P4_KEY_K				0x45
#define C16P4_KEY_O				0x46
#define C16P4_KEY_N				0x47

#define C16P4_KEY_DOWN			0x50
#define C16P4_KEY_P				0x51
#define C16P4_KEY_L				0x52
#define C16P4_KEY_UP			0x53
#define C16P4_KEY_POINT			0x54
#define C16P4_KEY_COLON			0x55
#define C16P4_KEY_MINUS			0x56
#define C16P4_KEY_COMMA			0x57

#define C16P4_KEY_LEFT			0x60
#define C16P4_KEY_STAR			0x61
#define C16P4_KEY_SEMI			0x62
#define C16P4_KEY_RIGHT			0x63
#define C16P4_KEY_ESC			0x64
#define C16P4_KEY_EQUAL			0x65
#define C16P4_KEY_PLUS			0x66
#define C16P4_KEY_SLASH			0x67

#define C16P4_KEY_1				0x70
#define C16P4_KEY_CLRHOME		0x71
#define C16P4_KEY_CTRL			0x72
#define C16P4_KEY_2				0x73
#define C16P4_KEY_SPACE			0x74
#define C16P4_KEY_CDORE			0x75
#define C16P4_KEY_Q				0x76
#define C16P4_KEY_RUNSTP		0x77


void ScancodeInit(matrix_t *ToInit);
#endif