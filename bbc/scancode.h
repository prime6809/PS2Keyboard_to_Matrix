/*
 Scancode table for the  Acorn BBC A/B/B+ keyboard interface. 

 Adapted from PCScanCodeTo Dragon, P.Harvey-Smith, 2008-12-06.
 
 The target computer keyboard data is then output to a Zarlink MT8816 8x16 
 crosspoint switch.

BBC A/B/B+

D0..D7 connected to 74LS251 are rows
C0..C9 connected to 74LS45/74LS145 are cols
S1..S7 Startup option dip switches

    C0      C1      C2      C3      C4      C5      C6      C7      C8      C9      
D0  SHIFT   CTRL    S8      S7      S6      S5      S4      S3      S2      S1
D1  Q       3#      4$      5%      f4      8(      f7      -=      ^~      Left
D2  f0      W       E       T       7'      I       9)      0       _£      Down
D3  1!      2"      D       R       6&      U       O       P       [{      Up
D4  CAPS    A       X       F       Y       J       K       @       :*      ret 
D5  SHIFTLK S       C       G       H       N       L       ;+      ]}      del  
D6  TAB     Z       sp      V       B       M       ,<      .>      /?      copy    
D7  ESC     f1      f2      f3      f5      f6      f8      f9      |       Right   

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

#define BBC_KEY_ESC			0x00
#define BBC_KEY_TAB			0x10
#define BBC_KEY_SHIFTLK		0x20
#define BBC_KEY_CAPS		0x30
#define BBC_KEY_1			0x40
#define BBC_KEY_F0			0x50
#define BBC_KEY_Q			0x60
#define BBC_KEY_SHIFT		0x7F

#define BBC_KEY_F1			0x01
#define BBC_KEY_Z			0x11
#define BBC_KEY_S			0x21
#define BBC_KEY_A			0x31
#define BBC_KEY_2			0x41
#define BBC_KEY_W			0x51
#define BBC_KEY_3			0x61
#define BBC_KEY_CTRL		0x7E

#define BBC_KEY_F2			0x02
#define BBC_KEY_SPACE		0x12
#define BBC_KEY_C			0x22
#define BBC_KEY_X			0x32		
#define BBC_KEY_D			0x42
#define BBC_KEY_E			0x52
#define BBC_KEY_4			0X62

#define BBC_KEY_F3			0x03
#define BBC_KEY_V			0x13
#define BBC_KEY_G			0x23
#define BBC_KEY_F			0x33
#define BBC_KEY_R			0x43
#define BBC_KEY_T			0x53
#define BBC_KEY_5			0x63

#define BBC_KEY_F5			0x04
#define BBC_KEY_B			0x14
#define BBC_KEY_H			0x24
#define BBC_KEY_Y			0x34
#define BBC_KEY_6			0x44
#define BBC_KEY_7			0x54
#define BBC_KEY_F4			0x64

#define BBC_KEY_F6			0x05
#define BBC_KEY_M			0x15
#define BBC_KEY_N			0x25
#define BBC_KEY_J			0x35
#define BBC_KEY_U			0x45
#define BBC_KEY_I			0x55
#define BBC_KEY_8			0x65

#define BBC_KEY_F8			0x06
#define BBC_KEY_COMMA		0x16
#define BBC_KEY_L			0x26
#define BBC_KEY_K			0x36
#define BBC_KEY_O			0x46
#define BBC_KEY_9			0x56
#define BBC_KEY_F7			0x66

#define BBC_KEY_F9			0x07
#define BBC_KEY_PERIOD		0x17
#define BBC_KEY_SEMI		0x27
#define BBC_KEY_AT			0x37
#define BBC_KEY_P			0x47
#define BBC_KEY_0			0x57
#define BBC_KEY_MINUS		0x67

#define BBC_KEY_PIPE		0x08
#define BBC_KEY_SLASH		0x18
#define BBC_KEY_RIGHTSB		0x28
#define BBC_KEY_COLON		0x38
#define BBC_KEY_LEFTSB		0x48
#define BBC_KEY_UNDER		0x58
#define BBC_KEY_CLARET		0x68

#define BBC_KEY_RIGHT		0X09
#define BBC_KEY_COPY		0X19
#define BBC_KEY_DEL			0X29
#define BBC_KEY_ENTER		0X39
#define BBC_KEY_UP			0X49
#define BBC_KEY_DOWN		0X59
#define BBC_KEY_LEFT		0X69

#define BBC_KEY_BREAK		0xFF

#define SHIFT_KEY	BBC_KEY_SHIFT
#define RESET_KEY	BBC_KEY_BREAK

void ScancodeInit(matrix_t *ToInit);
#endif