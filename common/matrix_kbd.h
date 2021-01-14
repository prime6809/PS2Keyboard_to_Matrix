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

typedef uint8_t		*ptable_t;

typedef struct  
{
	output_key_t	output;					// Output a key routine
	output_key_t	callback;				// Callback routine, may be null if not needed
	ptable_t		ScancodeTable;			// Scancode -> matrix table for unshifted keys
	ptable_t		ScancodeShiftTable;		// Scancode -> matrix table for shifted key
	uint8_t			matrix_shift;			// Matrix key to use as shift
	uint8_t			matrix_reset;			// Matrix code to trigger rese, usually 0xff
} matrix_t;

// initialise the matrix routines and set the output callback
void matrix_init(matrix_t *InitMatrix); 

// Check for an available scancode and output it.
void matrix_check_output(void);

#endif