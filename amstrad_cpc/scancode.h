/*
 Scancode table for the Amstrad CPC-6128 keyboard interface. 

 Adapted from PCScanCodeTo Commodore, J.Branton, 2024-06-12.
 
 The target computer keyboard data is then output to a Zarlink MT8816 8x16 
 crosspoint switch.


    C0      C1       C2      C3      C4      C5      C6      C7     
R0                                                           DEL
R1  1!      2"       ESC     Q       TAB     A       CAPS    Z
R2  4$	    3#	     E	     W	     S	     D	     C	     X
R3  6&	    5%	     R	     T	     G	     F	     B       V
R4  8(	    7'	     U	     Y	     H	     J	     N       SPACE
R5  0_	    9)	     O	     I	     L	     K	     M	     ,<
R6  ^£	    -=	     @|	     P	     ;+      :*	     /?	     .>
R7  CLR	    [{       RETURN  ]}	     F4      SHIFT   \`	     CTRL
R8  CURLEFT COPY     F7      F8      F5      F1      F2      F0
R9  CURUP   CURRIGHT CURDOWN F9      F6      F3      ENTER   FDot

Fot the following key definition constants, the high nibble and 0x70 represent the 
COLUMN of the pressed key, and the low nibble represents the ROW. Bit 7 is ignored, 
as this is used by the matrix handling code to flag a key pressed or released.
*/

#ifndef __SCANCODES__
#define __SCANCODES__

#include <inttypes.h>
#include <avr/pgmspace.h> 
#include "ps2scancode.h"
#include "matrix_kbd.h"

#define CPC_KEY_1            0x01
#define CPC_KEY_4	     0x02
#define CPC_KEY_6	     0x03
#define CPC_KEY_8	     0x04
#define CPC_KEY_0	     0x05
#define CPC_KEY_UPPOUND	     0x06
#define CPC_KEY_CLR	     0x07
#define CPC_KEY_LEFT	     0x08
#define CPC_KEY_UP	     0x09

#define CPC_KEY_2	     0x11
#define CPC_KEY_3	     0x12
#define CPC_KEY_5	     0x13
#define CPC_KEY_7	     0x14
#define CPC_KEY_9	     0x15
#define CPC_KEY_MINUS	     0x16
#define CPC_KEY_LSQBRACK     0x17
#define CPC_KEY_COPY	     0x18
#define CPC_KEY_RIGHT	     0x19

#define CPC_KEY_ESC          0x21
#define CPC_KEY_E	     0x22
#define CPC_KEY_R	     0x23
#define CPC_KEY_U	     0x24
#define CPC_KEY_O	     0x25
#define CPC_KEY_AT	     0x26
#define CPC_KEY_ENTER	     0x27
#define CPC_KEY_F7	     0x28
#define CPC_KEY_DOWN	     0x29

#define CPC_KEY_Q	     0x31
#define CPC_KEY_W	     0x32
#define CPC_KEY_T	     0x33
#define CPC_KEY_Y	     0x34
#define CPC_KEY_I	     0x35
#define CPC_KEY_P	     0x36
#define CPC_KEY_RSQBRACK     0x37
#define CPC_KEY_F8	     0x38
#define CPC_KEY_F9	     0x39

#define CPC_KEY_TAB	     0x41
#define CPC_KEY_S	     0x42
#define CPC_KEY_G	     0x43
#define CPC_KEY_H	     0x44
#define CPC_KEY_L	     0x45
#define CPC_KEY_SEMICOLON    0x46
#define CPC_KEY_F4	     0x47
#define CPC_KEY_F5	     0x48
#define CPC_KEY_F6	     0x49

#define CPC_KEY_A	     0x51
#define CPC_KEY_D	     0x52
#define CPC_KEY_F	     0x53
#define CPC_KEY_J	     0x54
#define CPC_KEY_K	     0x55
#define CPC_KEY_COLON	     0x56
#define CPC_KEY_SHIFT	     0x57
#define CPC_KEY_F1	     0x58
#define CPC_KEY_F3	     0x59

#define CPC_KEY_CAPS	     0x61
#define CPC_KEY_C	     0x62
#define CPC_KEY_B	     0x63
#define CPC_KEY_N	     0x64
#define CPC_KEY_M	     0x65
#define CPC_KEY_SLASH	     0x66
#define CPC_KEY_BSLASH	     0x67
#define CPC_KEY_F2	     0x68
#define CPC_KEY_ENTERKP	     0x69

#define CPC_KEY_DEL          0x70
#define CPC_KEY_Z	     0x71
#define CPC_KEY_X	     0x72
#define CPC_KEY_V	     0x73
#define CPC_KEY_SPACE	     0x74
#define CPC_KEY_COMMA	     0x75
#define CPC_KEY_POINT	     0x76
#define CPC_KEY_CTRL	     0x77
#define CPC_KEY_F0	     0x78
#define CPC_KEY_FDOT	     0x79

#define RESET_KEY	0xFF

void ScancodeInit(matrix_t *ToInit);
#endif
