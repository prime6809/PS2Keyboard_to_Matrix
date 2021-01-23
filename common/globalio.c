/*
	globalio.h	: Global I/O definitions. dip switthches / joystick etc.
	
	2021-01-23, P.Harvey-Smith.
*/

#include <inttypes.h>
#include "globalio.h"
#include "status.h"

void GlobalIOInit(void)
{
	log0("GlobalIOInit()\n");
	
	// Init DIPs/Jumpers, inputs with pullups
	DIPDDR 	&= ~DIPMASK;
	DIPPORT |= DIPMASK;
	
	// Init Joystick, inputs with pullups
	JSDDR	&= ~JSINMASK;
	JSPORT	|= JSINMASK;
	
	// Init AUX with just inputs no pullups.
	JSDDR	&= ~AUXMASK;
	
	// Init JS prog LED, and turn it off
	JSDDR	|= JSPROGLED;
	JSLEDOff();
	
	// Init target machine reset, input with pullup
	ClearTargetReset();
}
