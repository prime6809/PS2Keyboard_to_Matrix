/*
 Scancode table for the Apple IIc keyboard interface. 

 Adapted from PCScanCodeTo Commodore, J.Branton, 2024-10-19.
 
 The target computer keyboard data is then output to a Zarlink MT8816 8x16 
 crosspoint switch.


    C0      C1       C2      C3      C4      C5      C6      C7      C8      C9     
R0  ESC     1        2       3       4       5       6       7       8       9
R1  TAB     Q        W       E       R       Y       T       U       I       O
R2  A       D        S       H       F       G       J       K       ;       L
R3  Z       X        C       V       B       N       M       <       >       ?
R4                                                   \       +       0       -
R5                                                   ~       P       [       ]
R6                                                   Return  Up      Space   "
R7                                                   Delete  Down    Left    Right

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

#define AIIC_KEY_ESC         0x00
#define AIIC_KEY_1           0x01
#define AIIC_KEY_2	     0x02
#define AIIC_KEY_3	     0x03
#define AIIC_KEY_4	     0x04
#define AIIC_KEY_5	     0x05
#define AIIC_KEY_6	     0x06
#define AIIC_KEY_7	     0x07
#define AIIC_KEY_8	     0x08
#define AIIC_KEY_9	     0x09

#define AIIC_KEY_TAB	     0x10
#define AIIC_KEY_Q	     0x11
#define AIIC_KEY_W	     0x12
#define AIIC_KEY_E	     0x13
#define AIIC_KEY_R	     0x14
#define AIIC_KEY_Y	     0x15
#define AIIC_KEY_T	     0x16
#define AIIC_KEY_U	     0x17
#define AIIC_KEY_I	     0x18
#define AIIC_KEY_O	     0x19

#define AIIC_KEY_A	     0x20
#define AIIC_KEY_D	     0x21
#define AIIC_KEY_S	     0x22
#define AIIC_KEY_H	     0x23
#define AIIC_KEY_F	     0x24
#define AIIC_KEY_G	     0x25
#define AIIC_KEY_J	     0x26
#define AIIC_KEY_K	     0x27
#define AIIC_KEY_SEMICOLON   0x28
#define AIIC_KEY_L	     0x29

#define AIIC_KEY_Z	     0x30
#define AIIC_KEY_X	     0x31
#define AIIC_KEY_C	     0x32
#define AIIC_KEY_V	     0x33
#define AIIC_KEY_B	     0x34
#define AIIC_KEY_N	     0x35
#define AIIC_KEY_M	     0x36
#define AIIC_KEY_LT	     0x37
#define AIIC_KEY_GT	     0x38
#define AIIC_KEY_QUESTION    0x39

#define AIIC_KEY_TILDE       0x46
#define AIIC_KEY_EQUAL	     0x47
#define AIIC_KEY_0	     0x48
#define AIIC_KEY_MINUS	     0x49

#define AIIC_KEY_BSLASH	     0x56
#define AIIC_KEY_P	     0x57
#define AIIC_KEY_LSQBRACK    0x58
#define AIIC_KEY_RSQBRACK    0x59

#define AIIC_KEY_ENTER	     0x66
#define AIIC_KEY_UP	     0x67
#define AIIC_KEY_SPACE	     0x68
#define AIIC_KEY_DQUOTE	     0x69

#define AIIC_KEY_DEL         0x76
#define AIIC_KEY_DOWN	     0x77
#define AIIC_KEY_LEFT	     0x78
#define AIIC_KEY_RIGHT	     0x79

#define AIIC_KEY_SHIFT       0x80
#define AIIC_KEY_CTRL	     0x90
#define AIIC_KEY_OAPPLE	     0x88
#define AIIC_KEY_CAPPLE	     0x89

#define RESET_KEY	0xFF

void ScancodeInit(matrix_t *ToInit);
#endif
