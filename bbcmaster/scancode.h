/*
 Scancode table for the  Acorn BBC Master / Master Compact keyboard interface. 

 PCScanCodeTo Acorn BBC Master/Master Compact keyboard emulation routines.

 Adapted from PCScanCodeTo Dragon, P.Harvey-Smith, 2008-12-06.
 
 The target computer keyboard data is then output to a Zarlink MT8816 8x16 
 crosspoint switch.

BBC Master
Basically the same as the A/B/B+ but with an extra 3 collumns to deal with the numeric keypad.

    C0      C1      C2      C3      C4      C5      C6      C7      C8      C9      C10     C11     C12

R0  ESC     f1      f2      f3      f5      f6      f8      f9      |       Right   4'      5'      2'
R1  TAB     Z       sp      V       B       M       ,<      .>      /?      copy    0'      1'      3'
R2  SHIFTLK S       C       G       H       N       L       ;+      ]}      del     #'      *'      ,'
R3  CAPS    A       X       F       Y       J       K       @       :*      ret     /'      del'    .'
R4  1!      2"      D       R       6&      U       O       P       [{      Up      +'      -'      ret'
R5  f0      W       E       T       7'      I       9)      0       _£      Down    8'      9'
R6  Q       3#      4$      5%      f4      8(      f7      -=      ^~      Left    6'      7'
R7  SHIFT   CTRL

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

#define BBCM_KEY_ESC		0x00
#define BBCM_KEY_TAB		0x10
#define BBCM_KEY_SHIFTLK	0x20
#define BBCM_KEY_CAPS		0x30
#define BBCM_KEY_1			0x40
#define BBCM_KEY_F0			0x50
#define BBCM_KEY_Q			0x60
#define BBCM_KEY_SHIFT		0x70

#define BBCM_KEY_F1			0x01
#define BBCM_KEY_Z			0x11
#define BBCM_KEY_S			0x21
#define BBCM_KEY_A			0x31
#define BBCM_KEY_2			0x41
#define BBCM_KEY_W			0x51
#define BBCM_KEY_3			0x61
#define BBCM_KEY_CTRL		0x71

#define BBCM_KEY_F2			0x02
#define BBCM_KEY_SPACE		0x12
#define BBCM_KEY_C			0x22
#define BBCM_KEY_X			0x32		
#define BBCM_KEY_D			0x42
#define BBCM_KEY_E			0x52
#define BBCM_KEY_4			0X62

#define BBCM_KEY_F3			0x03
#define BBCM_KEY_V			0x13
#define BBCM_KEY_G			0x23
#define BBCM_KEY_F			0x33
#define BBCM_KEY_R			0x43
#define BBCM_KEY_T			0x53
#define BBCM_KEY_5			0x63

#define BBCM_KEY_F5			0x04
#define BBCM_KEY_B			0x14
#define BBCM_KEY_H			0x24
#define BBCM_KEY_Y			0x34
#define BBCM_KEY_6			0x44
#define BBCM_KEY_7			0x54
#define BBCM_KEY_F4			0x64

#define BBCM_KEY_F6			0x05
#define BBCM_KEY_M			0x15
#define BBCM_KEY_N			0x25
#define BBCM_KEY_J			0x35
#define BBCM_KEY_U			0x45
#define BBCM_KEY_I			0x55
#define BBCM_KEY_8			0x65

#define BBCM_KEY_F8			0x06
#define BBCM_KEY_COMMA		0x16
#define BBCM_KEY_L			0x26
#define BBCM_KEY_K			0x36
#define BBCM_KEY_O			0x46
#define BBCM_KEY_9			0x56
#define BBCM_KEY_F7			0x66

#define BBCM_KEY_F9			0x07
#define BBCM_KEY_PERIOD		0x17
#define BBCM_KEY_SEMI		0x27
#define BBCM_KEY_AT			0x37
#define BBCM_KEY_P			0x47
#define BBCM_KEY_0			0x57
#define BBCM_KEY_MINUS		0x67

#define BBCM_KEY_PIPE		0x08
#define BBCM_KEY_SLASH		0x18
#define BBCM_KEY_RIGHTSB	0x28
#define BBCM_KEY_COLON		0x38
#define BBCM_KEY_LEFTSB		0x48
#define BBCM_KEY_UNDER		0x58
#define BBCM_KEY_CLARET		0x68

#define BBCM_KEY_RIGHT		0X09
#define BBCM_KEY_COPY		0X19
#define BBCM_KEY_DEL		0X29
#define BBCM_KEY_ENTER		0X39
#define BBCM_KEY_UP			0X49
#define BBCM_KEY_DOWN		0X59
#define BBCM_KEY_LEFT		0X69

#define BBCM_KEY_KP_4		0x0A
#define BBCM_KEY_KP_0		0x1A
#define BBCM_KEY_KP_HASH	0x2A
#define BBCM_KEY_KP_SLASH	0x3A
#define BBCM_KEY_KP_PLUS	0x4A
#define BBCM_KEY_KP_8		0x5A
#define BBCM_KEY_KP_6		0x6A

#define BBCM_KEY_KP_5		0x0B
#define BBCM_KEY_KP_1		0x1B
#define BBCM_KEY_KP_STAR	0x2B
#define BBCM_KEY_KP_DEL		0x3B
#define BBCM_KEY_KP_MINUS	0x4B
#define BBCM_KEY_KP_9		0x5B
#define BBCM_KEY_KP_7		0x6B

#define BBCM_KEY_KP_2		0x0C
#define BBCM_KEY_KP_3		0x1C
#define BBCM_KEY_KP_COMMA	0x2C
#define BBCM_KEY_KP_QUOTE	0x3C
#define BBCM_KEY_KP_ENTER	0x4C

#define BBCM_KEY_BREAK		0xFF

#define SHIFT_KEY	BBCM_KEY_SHIFT
#define RESET_KEY	BBCM_KEY_BREAK

void ScancodeInit(matrix_t *ToInit);
#endif