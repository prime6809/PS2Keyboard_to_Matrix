/* 
	matrix_kbd.h
	
	Definitions for handling a matrix keyboard output. 
	
	2009-04-27, P.Harvey-Smith.
*/

#ifndef __MATRIX_KBD__
#define __MATRIX_KBD__

#define	KEY_DOWN	1
#define KEY_UP		0

// Type to hold the pointer to the callback routine to output keys to the 
// keyboard matrix, this takes, two paramters
// the first is the code to output, and can be any value, the second will
// be a 1 for a keypress and a 0 for a key release.
//
typedef void (*output_key_t)(uint8_t,uint8_t);

// Callback to machine driver, parameters are :
// Prefix code, scancode, press or release.
typedef uint8_t (*output_key_callback_t)(uint8_t,uint8_t,uint8_t);

typedef uint8_t		*ptable_t;

typedef struct  
{
	output_key_t			output;					// Output a key routine
	output_key_callback_t	callback;				// Callback routine, may be null if not needed
	ptable_t				ScancodeTable;			// Scancode -> matrix table for unshifted keys
	ptable_t				ScancodeShiftTable;		// Scancode -> matrix table for shifted key
	uint8_t					matrix_shift;			// Matrix key to use as shift
	uint8_t					matrix_reset;			// Matrix code to trigger reset, usually 0xff
} matrix_t;

// initialise the matrix routines and set the output callback
void matrix_init(matrix_t *InitMatrix); 

// Check for an available scancode and output it.
void matrix_check_output(void);

// Each target should have a function called TargetKeyCallback,
// it should return true if the key was handled, false if it was not.
uint8_t TargetKeyCallback(uint8_t	PrefixCode,
						  uint8_t	KeyCode,
					      uint8_t	State);
						  
// For extracting row and column from table entries
#define MAX_ROW		0x07
#define MAX_COL		0x0F
#define ROW_MASK	0x70
#define COL_MASK	0x0F

#define ROW_SHIFT	4

#define GetRow(RC)	((RC & ROW_MASK) >> ROW_SHIFT)
#define GetCol(RC)	(RC & COL_MASK)
 
#endif