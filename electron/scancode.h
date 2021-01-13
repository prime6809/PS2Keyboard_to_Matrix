/*
 Scancode table for the  Acorn Electron keyboard interface. 

 PCScanCodeTo Acorn BBC Master/Master Compact keyboard emulation routines.

 Adapted from PCScanCodeTo Dragon, P.Harvey-Smith, 2008-12-06.
 
 The target computer keyboard data is then output to a Zarlink MT8816 8x16 
 crosspoint switch.
Electron 

A0..A13 connected to address bus through Diodes
D0..D3 connected to the ULA (and pulled up).
Does this work in the same way as the ZX80/81/Spectrum keyboards ? Yes!

    A0      A1      A2      A3      A4      A5      A6      A7      A8      A9      A10     A11     A12     A13     
D0  Left |\ Right^~ -=      0@      9)      8(      7'      6&      5%      4$      3#      2"      1!      ESCAPE
D1  Copy [] Down _} Up £{   P       O       I       U       Y       T       R       E       W       Q       CAPS FN
D2          Return  :*      ;+      L       K       J       H       G       F       D       S       A       CTRL   
D3  Space   Delete          /?      .>      ,<      M       N       B       V       C       X       Z       sHIFT

For the following key definition constants, the high nibble and 0x70 represent the 
ROW of the pressed key, and the low nibble represents the COLUMN. Bit 7 is ignored, 
as this is used by the matrix handling code to flag a key pressed or released.
*/

#ifndef __SCANCODES__
#define __SCANCODES__

#include <inttypes.h>
#include <avr/pgmspace.h> 
#include "ps2scancode.h"
#include "matrix_kbd.h"

#define ELK_KEY_PIPE		0x00
#define ELK_KEY_COPY		0x10
#define ELK_KEY_R2C0		0x20
#define ELK_KEY_SPACE		0x30

#define ELK_KEY_CLARET		0x01
#define ELK_KEY_UNDER		0x11
#define ELK_KEY_ENTER		0x21
#define ELK_KEY_DEL			0x31

#define ELK_KEY_MINUS		0x02
#define ELK_KEY_POUND		0x12
#define ELK_KEY_COLON		0x22
#define ELK_KEY_R3C2		0x32

#define ELK_KEY_0			0x03
#define ELK_KEY_P			0x13
#define ELK_KEY_SEMI		0x23
#define ELK_KEY_SLASH		0x33

#define ELK_KEY_9			0x04
#define ELK_KEY_O			0x14
#define ELK_KEY_L			0x24
#define ELK_KEY_PERIOD		0x34

#define ELK_KEY_8			0x05
#define ELK_KEY_I			0x15
#define ELK_KEY_K			0x25
#define ELK_KEY_COMMA		0x35	

#define ELK_KEY_7			0x06
#define ELK_KEY_U			0x16
#define ELK_KEY_J			0x26
#define ELK_KEY_M			0x36

#define ELK_KEY_6			0x07
#define ELK_KEY_Y			0x17
#define ELK_KEY_H			0x27
#define ELK_KEY_N			0x37

#define ELK_KEY_5			0x08
#define ELK_KEY_T			0x18
#define ELK_KEY_G			0x28
#define ELK_KEY_B			0x38

#define ELK_KEY_4			0x09
#define ELK_KEY_R			0x19
#define ELK_KEY_F			0x29
#define ELK_KEY_V			0x39

#define ELK_KEY_3			0x0A
#define ELK_KEY_E			0x1A
#define ELK_KEY_D			0x2A
#define ELK_KEY_C			0x3A

#define ELK_KEY_2			0x0B
#define ELK_KEY_W			0x1B
#define ELK_KEY_S			0x2B
#define ELK_KEY_X			0x3B

#define ELK_KEY_1			0x0C
#define ELK_KEY_Q			0x1C
#define ELK_KEY_A			0x2C
#define ELK_KEY_Z			0x3C

#define ELK_KEY_ESC			0x0D
#define ELK_KEY_FUNC		0x1D
#define ELK_KEY_CTRL		0x2D
#define ELK_KEY_SHIFT		0x3D

#define ELK_KEY_BREAK		0xFF

// Aliases for convenience
#define	ELK_KEY_UP			ELK_KEY_POUND
#define ELK_KEY_DOWN		ELK_KEY_UNDER
#define ELK_KEY_RIGHT		ELK_KEY_PIPE
#define ELK_KEY_LEFT		ELK_KEY_CLARET


#define SHIFT_KEY	ELK_KEY_SHIFT
#define RESET_KEY	ELK_KEY_BREAK

void ScancodeInit(matrix_t *ToInit);
#endif