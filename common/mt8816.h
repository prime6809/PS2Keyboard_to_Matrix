/* 
	mt8816.h
	
	Definitions for handling the MT8816 crosspoint switch.
	
	2009-07-23, P.Harvey-Smith.
*/

/*
 Port to output row,col and open close data on, the AX0..4 inputs of the
 MT8816 should be connected to bits 0..3, AY0..2 to bits 4..6, and DATA
 to bit 7.
*/

#define MT_KEYS_PORT	PORTA	
#define MT_KEYS_DDR		DDRA	// should all be set as outputs

#define MT_CTRL_PORT	PORTD	// Control lines for MT8816 connected to this port
#define MT_CTRL_PIN		PIND
#define MT_CTRL_DDR		DDRD
#define MT_RESET		6		// bit0 = MT8816 RESET, active high !
#define MT_STROBE		7		// bit1 = MT8816 STROBE, active high.	

#define MT_KEY_DOWN     0x80    // Key down bit

#define MTAssertStrobe()	{ MT_CTRL_PORT |= (1<<MT_STROBE); };
#define MTClearStrobe()		{ MT_CTRL_PORT &= ~(1<<MT_STROBE); };

#define MTAssertReset()		{ MT_CTRL_PORT |= (1<<MT_RESET); };
#define MTClearReset()		{ MT_CTRL_PORT &= ~(1<<MT_RESET); };

// MT_init, initialise MT8816 and keyboard variables.
void mt_init(void);

// Output a keycode to the crosspoint
void mt_output_key(uint8_t	KeyCode,
				   uint8_t	State); 
