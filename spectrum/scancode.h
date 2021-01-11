/*
 Scancode table for the ZX Spectrum keyboard interface. 

 Adapted from PCScanCodeTo Dragon, P.Harvey-Smith, 2008-12-06.
 
 The ZX Spectrum keyboard data is then output to a Zarlink MT8816 8x16 
 crosspoint switch.

 The output of the crosspoint switch is connected to the matrix 
 inputs of the target computer. 
 
 As the ZX Spectrum's matrix is 5x8, we use 8 of the rows and all 8 columns.
 
 The ZX Spectrum's keyboard is laid out as follows, this is *ALMOST* identical to the 
 ZX80/81 :-

Column		0		1		2 		3		4		5		6		7
Row 0  		CShift	A		Q		1		0		P		Enter	Space
Row 1  		Z		S		W		2		9		O		L		SShift
Row 2  		X		D		E		3		8		I		K		M
Row 3  		C		F		R		4		7		U		J		N
Row 4  		V		G		T		5		6		Y		H		B

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

#define ZXSP_KEY_CSHIFT	0x00
#define ZXSP_KEY_Z		0x10
#define ZXSP_KEY_X		0x20
#define ZXSP_KEY_C		0x30
#define ZXSP_KEY_V		0x40

#define ZXSP_KEY_A		0x01
#define ZXSP_KEY_S		0x11
#define ZXSP_KEY_D		0x21
#define ZXSP_KEY_F		0x31
#define ZXSP_KEY_G		0x41

#define ZXSP_KEY_Q		0x02
#define ZXSP_KEY_W		0x12
#define ZXSP_KEY_E		0x22
#define ZXSP_KEY_R		0x32
#define ZXSP_KEY_T		0x42

#define ZXSP_KEY_1		0x03
#define ZXSP_KEY_2		0x13
#define ZXSP_KEY_3		0x23
#define ZXSP_KEY_4		0x33
#define ZXSP_KEY_5		0x43

#define ZXSP_KEY_0		0x04
#define ZXSP_KEY_9		0x14
#define ZXSP_KEY_8		0x24
#define ZXSP_KEY_7		0x34
#define ZXSP_KEY_6		0x44

#define ZXSP_KEY_P		0x05
#define ZXSP_KEY_O		0x15
#define ZXSP_KEY_I		0x25
#define ZXSP_KEY_U		0x35
#define ZXSP_KEY_Y		0x45

#define ZXSP_KEY_ENTER	0x06
#define ZXSP_KEY_L		0x16
#define ZXSP_KEY_K		0x26
#define ZXSP_KEY_J		0x36
#define ZXSP_KEY_H		0x46

#define ZXSP_KEY_SPACE	0x07
#define ZXSP_KEY_SSHIFT	0x17
#define ZXSP_KEY_M		0x27
#define ZXSP_KEY_N		0x37
#define ZXSP_KEY_B		0x47

#define RESET_KEY		0xff

void ScancodeInit(matrix_t *ToInit);
#endif