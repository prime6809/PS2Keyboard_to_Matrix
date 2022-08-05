/* 
	matrix_kbd.h
	
	Definitions for handling a matrix keyboard output. 
		
	2009-07-23, P.Harvey-Smith.
    
    2010-05-03, Fixed so that CTRL-BREAK now works.
	
	2011-04-27, Seperated driver for MT8816 into seperate driver file.
				Changed from using a table containing all the possible scancodes
				both used and unused to a table that only contains used scancodes.
				
	2021-01-15, Modified the way that callbacks (to the machine driver) are done, so
				they are done *BEFORE* any table processing. The callback returns
				a flag to say if it has processed the key or not. 
				
	2021-01-18, Modified LookupKeys, so that we can use several blocks of modifier
				keys within the shift table this way if we wanted to say have a PS/2
				code encode to the matrix's shift-key but another to ctrl-key we can 
				do it. This is accieved by having an entry in the shift key table 
				that consists of the scancode and prefix code being set to 
				SCAN_CODE_NEWSHIFT, and the matrix code bing the matrix code of the
				new modifier key. All subsiquent entries will then use this code.
				This can of course be applied multiple times for different modifiers.
				Each scan of the table resets to the shift field of Matrix->matrix_shift
				
	2021-01-24, Added code to dump the PS2->Matrix table as an array on screen. This
			    is usefull for spotting matrix positions that have no PS/2 key encoding 
				to them.
*/

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <string.h>
#include "matrix_kbd.h"
#include "ps2kbd.h"
#include "scancode.h"
#include "status.h"
#include "globalio.h"
#include "io.h"

static uint8_t	LastScanCode;
static uint8_t	PrefixCode;

static uint8_t  CodeCount;

static matrix_t		*Matrix = NULL;	

void check_matrix(void);

// initialise the matrix routines 
void matrix_init(matrix_t *InitMatrix)
{
	logv0("Keyboard matrix init\n");

	LastScanCode=0x00;
	PrefixCode=SCAN_CODE_NO_PREFIX;

	Matrix=InitMatrix;

    // Init Scancode buffer variables
    CodeCount=0;
	
	// If DIP4 is set then display matrix.
	if (DIPIsSet(DIPS4)) 
		check_matrix();
}

static uint8_t LookupKeys(uint8_t	Scancode,
					      uint8_t 	IsShift)
{
	uint16_t	Offset 	= 0;
	uint8_t		*Table;
	uint8_t		Prefix;
	uint8_t		Code;	
	uint8_t		MatrixCode;	
	uint8_t		Handled	= 0;
	uint8_t		ShiftKey = Matrix->matrix_shift;	// Default matrix shift key.
	
	// Select which table to use
	if(IsShift)
		Table=Matrix->ScancodeShiftTable;
	else
		Table=Matrix->ScancodeTable;
	
	// Point at initial values
	Prefix 		= pgm_read_byte(&Table[Offset++]);
	Code		= pgm_read_byte(&Table[Offset++]);
	MatrixCode	= pgm_read_byte(&Table[Offset++]);
	
	logv0("LookupKeys(%02X,%d), Table=%05X\n",Scancode,IsShift,Table);
	
	// Scan through shift code table
	while((Prefix!=SCAN_CODE_TERMINATE) && (!Handled))
	{
		//logv0("o=%d, p=%02X, c=%02X, z=%02X\n",Offset,Prefix,Code,ZXCode);
		// If we are in the shift lookup table, and we see the code for a new shift key
		// then set it. 
		if((SCAN_CODE_NEWSHIFT == Prefix) && (SCAN_CODE_NEWSHIFT == Code) && IsShift)
		{
			ShiftKey = MatrixCode;
		}
		

		// if code found, output it.
		// If IsShift is true press ShiftKey then key
		// on release release key then ShiftKey
		if((PrefixCode==Prefix) && (Scancode==Code))
		{
			logv0("MatrixCode=%02X\n",MatrixCode);

			if(LastScanCode!=SCAN_CODE_RELEASE)
			{
				if(MatrixCode!=RESET_KEY)
				{
					if(IsShift)
						Matrix->output(ShiftKey,KEY_DOWN);

					Matrix->output(MatrixCode,KEY_DOWN);
				}
				
				Handled++;
			}
			else
			{
				if(MatrixCode!=Matrix->matrix_reset)
				{
					Matrix->output(MatrixCode,KEY_UP);
					if(IsShift)
						Matrix->output(ShiftKey,KEY_UP);
				}
				else
					ResetMachine();
					
				Handled++;
			}
			Prefix=SCAN_CODE_TERMINATE;
		}
		else
		{
			Prefix 		= pgm_read_byte(&Table[Offset++]);
			Code		= pgm_read_byte(&Table[Offset++]);
			MatrixCode	= pgm_read_byte(&Table[Offset++]);
		}
	}
	
	return Handled;
}

/*
	Check the scancode queue, and if codes are available interpret them, possibly
	outputting keys to the matrix driver.
*/

void matrix_check_output(void)
{
	uint8_t	Scancode;
	uint8_t	KeyValid = false;
	uint8_t	IsShift;
	
	if(Matrix==NULL)
	{
		logv0("ERROR, no matrix driver initialised, please initialise first with matrix_init()\n");
		return;
	}
	else
	{
		if((Matrix->output==NULL) || (Matrix->ScancodeTable==NULL) || (Matrix->ScancodeShiftTable==NULL))
		{
			logv0("ERROR, matrix structure not correctly initialized!\n");
			logv0("Matrix->output=%d, Matrix->ScancodeTable=%d, Matrix->ScancodeShiftTable=%d",
			     Matrix->output, Matrix->ScancodeTable, Matrix->ScancodeShiftTable);
				 
			return;
		}
	}
		
	// Check for a waiting scancode
	Scancode=ps2_kbd_get_scancode();
	
	// If it's a valid scancode process it
	if(Scancode!=0)
	{
        //logv0("%2X ",Scancode);
		//if(Scancode!=LastScanCode)
        //    logv0("Last:%2.2X Scan:%2.2X Prefix:%2.2X Count=%d\n",LastScanCode,Scancode,PrefixCode,CodeCount);
	
		if (CodeCount>0)
		{
        	CodeCount--;
			if(CodeCount==0)
			{
				if(PrefixCode==SCAN_CODE_BESCAPE)
				{
					ResetMachine();
				}
				LastScanCode=0;
				PrefixCode=0;
			}
		}
		else
		{
			switch (Scancode)
			{
                // Check for various escape scancodes and set prefix as needed
				case SCAN_CODE_ESCAPE :
					PrefixCode=SCAN_CODE_ESCAPE;
					break;
			
				// Break key ignore scan codes
				case SCAN_CODE_BESCAPE :
					PrefixCode=SCAN_CODE_BESCAPE;
					CodeCount=BREAK_SEQUENCE_LEN-1;
					break;
								
				case SCAN_CODE_F12 :
					if(LastScanCode!=SCAN_CODE_RELEASE)
						ResetMachine();	// Atomulator compatibility.
					break;
				
				case SCAN_CODE_F11 :
					asm("jmp 0x0000");	// Soft Reset AVR
					break;
				
				default: 
					if(Scancode<=MAX_SCANCODE)
					{
						// 2021-01-15, do callback processing first, then callback can 
						// override table.
						if(Matrix->callback!=NULL)
						{
							if(LastScanCode!=SCAN_CODE_RELEASE)
								KeyValid=Matrix->callback(PrefixCode,Scancode,KEY_DOWN);
							else
								KeyValid=Matrix->callback(PrefixCode,Scancode,KEY_UP);
						}

						if(!KeyValid)
						{
							// Lookup normal unshifted keys
							IsShift=0;
							KeyValid=LookupKeys(Scancode,IsShift);
						
							// If key was not found then try the shifted table
							if (!KeyValid)
							{
								IsShift=1;
								KeyValid=LookupKeys(Scancode,IsShift);
							}
						}	
							
						PrefixCode=SCAN_CODE_NO_PREFIX;
					}
					break;
			}
			// Update last scancode
			LastScanCode=Scancode;
		}
	}
}	

// Display a representation of the matrix codes that are present in the
// scancode to matrix tables. This can be used to spot gaps in the matrix
// where no PS/2 code encodes to that matrix position.

#define TITLE_LEN	128

void check_matrix(void)
{
	uint16_t	Check[MAX_ROW+1];
	uint8_t		Codes[16][8];
	uint8_t		SHCodes[16][8];
	char		Title[TITLE_LEN];
	int8_t		Row;
	int8_t		Col;
	uint16_t	Offset 	= 0;
	uint8_t		*Table;
	uint8_t		Prefix;
	uint8_t		Code;	
	uint8_t		MatrixCode;	
	uint8_t		Pass;
	uint8_t		OutCh;

	// Clear array to hold matrix code presence flags
	memset(Check,0x00,sizeof(Check));
	memset(Codes,0x00,sizeof(Codes));
	memset(SHCodes,0x00,sizeof(SHCodes));
	

	// Make a pass over both the ScanCode table and the ShiftScan code table
	for(Pass=0 ; Pass < 1; Pass++)
	{
		// Select table.
		if (0 == Pass)
			Table  = Matrix->ScancodeTable;
		else
			Table  = Matrix->ScancodeShiftTable;
		
		// Start at the beginning :)
		Offset = 0;
		Prefix = 0;
		
		// Check each ScanCodeTable entry's matrix code, and set the bit in the check
		// array corresponding to the matrix code
		while(Prefix!=SCAN_CODE_TERMINATE) 
		{
			Prefix 		= pgm_read_byte(&Table[Offset++]);
			Code		= pgm_read_byte(&Table[Offset++]);
			MatrixCode	= pgm_read_byte(&Table[Offset++]);
	
			if(Prefix!=SCAN_CODE_TERMINATE)
				Check[GetRow(MatrixCode)] |= (1 << GetCol(MatrixCode));
				
			if(0 == Pass)
				Codes[GetCol(MatrixCode)][GetRow(MatrixCode)]=Code;
			else
				SHCodes[GetCol(MatrixCode)][GetRow(MatrixCode)]=Code;	
		}
	}

	// Display column titles
	snprintf(Title,TITLE_LEN,"ColNo    ");

	for(Col = MAX_COL; Col>-1; Col--)
		snprintf(Title,TITLE_LEN,"%s %02X",Title,Col);
	
	logv0("%s\n",Title);
	
	// Extract each bit from the chek array and display it.
	for(Row = 0; Row < MAX_ROW; Row++)
	{
		logv0("Row[%d]: ",Row);
		for(Col = MAX_COL; Col>-1; Col--)
		{
			OutCh=(Check[Row] & (1<<Col)) ? '1' : '0';
			logv0("  %c",OutCh);
		}
		logv0("\n");
	}
	
	// Display scancodes of unshifted table.
	logv0("\nUnshifted table\n\n%s\n",Title);
	for(Row = 0; Row < MAX_ROW; Row++)
	{
		logv0("Row[%d]:  ",Row);
		for(Col = MAX_COL; Col>-1; Col--)
		{
			logv0(" %02X",Codes[Col][Row]);
		}
		logv0("\n");
	}
	
	// Display scancodes of unshifted table.
	logv0("\nShifted table\n\n%s\n",Title);
	for(Row = 0; Row < MAX_ROW; Row++)
	{
		logv0("Row[%d]:  ",Row);
		for(Col = MAX_COL; Col>-1; Col--)
		{
			logv0(" %02X",SHCodes[Col][Row]);
		}
		logv0("\n");
	}
}