/* PS/2 keyboard routines by Jurre Hanema, version 1.0
 * ps2kbd.c
 *
 * Released under "THE BEER-WARE LICENSE" (Revision 42):
 * <kipmans@gmail.com> wrote this file. As long as you retain this notice you can 
 * do whatever you want with this stuff. If we meet some day, and you think this 
 * stuff is worth it, you can buy me a beer in return.
 */

/*
    Modified March-October 2009, P.Harvey-Smith to more suit the needs of the 
    Atom/BBC/Electron keyboard interfaces.

	2010-07-03, P.Harvey-Smith.
	Changed keyboard queue handling to use a propper ring buffer rather than a stack!
	
	2010-07-04, P.Harvey-Smith.
	Changed nested if statements to be a switch as I think this makes the code clearer
	if a little more verbose !
	Receive code now checks parity bit and only queues scancode if parity is valid.
	
	2011-04-27, Changed all externally callable routines to have the prefix
	ps2_kbd_

*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "ps2kbd.h"
#include "status.h"

#define LOGIC_XOR(a, b)	(((a) && !(b)) || ((b) && !(a)))

volatile uint8_t	kbd_bit_n = 1;
volatile uint8_t	kbd_n_bits = 0;
volatile uint8_t	kbd_buffer = 0;
volatile uint8_t	kbd_queue[KBD_BUFSIZE + 1];
volatile uint8_t	kbd_queue_idx = 0;
volatile uint8_t	kbd_parity;

volatile uint8_t	kbd_queue_insert = 0;
volatile uint8_t	kbd_queue_remove = 0;
volatile uint16_t	kbd_status = 0;

#define KQueueHasSpace()	(((kbd_queue_insert % KBD_BUFSIZE)+1) != (kbd_queue_remove % KBD_BUFSIZE))
#define KQueueEmpty()		((kbd_queue_insert % KBD_BUFSIZE) == (kbd_queue_remove % KBD_BUFSIZE))

// Begin actual implementation

void ps2_kbd_init()
{
	kbd_queue[KBD_BUFSIZE] = 0;
	kbd_queue_insert = 0;
	kbd_queue_remove = 0;
	kbd_status = 0;
	kbd_parity = 0;
	
	// Set interrupts
	
	KBD_SET_INT();
	KBD_EN_INT();
	
	// Enable pullup on clock
	
	KBD_CLOCK_PORT |= KBD_CLOCK_MASK;

//	sei();
}


uint8_t ps2_kbd_queue_scancode(volatile uint8_t p)
{
	//log0("PS/2:%02X\n",p);
	
	if(KQueueHasSpace())
	{
		kbd_queue[kbd_queue_insert++] = p;
		kbd_queue_insert %= KBD_BUFSIZE;
	} else
		return 0;

	return 1;
}


uint8_t ps2_kbd_get_scancode(void)
{
	uint8_t		result;

	if(!KQueueEmpty())
	{
		cli();
		result=kbd_queue[kbd_queue_remove++]; 
		kbd_queue_remove %= KBD_BUFSIZE;
		sei();
		
		return result;
	} else
		return 0;
}


void ps2_kbd_send(uint8_t data)
{
	//log0("kbd_send(%2X), kbd_status=%4X, kbd_bit_n=%d\n",data,kbd_status,kbd_bit_n);
	
	// This behaviour isn't the most desirable, but it's the easiest and proved to be reliable.
	while(kbd_status & (KBD_SEND | KBD_RECEIVE)) 
	//	_delay_ms(5);
		asm("nop");	
	
	// Initiate request-to-send, the actual sending of the data
	// is handled in the ISR.
	
	//log0("kbd_send(%2X)\n",data);
	KBD_CLOCK_PORT &= ~(1<<KBD_CLOCK_BIT);
	KBD_CLOCK_DDR  |= (1<<KBD_CLOCK_BIT);
	_delay_us(120);
	
	kbd_bit_n = 1;
	kbd_status |= KBD_SEND;
	kbd_n_bits = 0;
	kbd_buffer = data;

	KBD_DATA_DDR   |= (1<<KBD_DATA_BIT);
	KBD_CLOCK_DDR  &= ~(1<<KBD_CLOCK_BIT);
	KBD_CLOCK_PORT |= (1<<KBD_CLOCK_BIT);
}

void ps2_kbd_set_leds(uint8_t	kbleds)
{
	// Send the command to set the LEDS to the keyboard
	ps2_kbd_send(KBD_CMD_SET_LEDS);
	ps2_kbd_send(kbleds);
}

void ps2_kbd_update_leds(void)
{
	uint8_t	val = 0;

	if(kbd_status & KBD_CAPS) val |= 0x04;
	if(kbd_status & KBD_NUMLOCK) val |= 0x02;
	if(kbd_status & KBD_SCROLL) val |= 0x01;
	
	ps2_kbd_send(0xed);
	ps2_kbd_send(val);
}


unsigned char kbd_do_lookup(const unsigned char *lut, uint8_t sc)
{
	uint8_t	i;
	
	for(i = 0; pgm_read_byte(&lut[i]); i += 2)
		if(sc == pgm_read_byte(&lut[i]))
			return pgm_read_byte(&lut[i + 1]);
	return 0;
}

uint16_t ps2_kbd_get_status()
{
	return kbd_status;
}


ISR(PS2_KBD_INT)
{
	uint8_t	bit_in;
	
	if(kbd_status & KBD_SEND)
	{
		// Send data
		switch (kbd_bit_n)
		{
			case 9 :					// Parity bit
				if(kbd_n_bits & 0x01)
					KBD_DATA_DDR |= KBD_DATA_MASK;
				else
					KBD_DATA_DDR &= ~KBD_DATA_MASK;
			
				break;
				
			case 10 :					// Stop bit
				KBD_DATA_DDR &= ~KBD_DATA_MASK;
				break;
				
			case 11 : 					// ACK bit, set by device
				kbd_buffer = 0;
				kbd_bit_n = 0;
				kbd_status &= ~KBD_SEND;
				break;
			
			default : 
				if(kbd_buffer & (1 << (kbd_bit_n - 1)))
				{
					KBD_DATA_DDR &= ~KBD_DATA_MASK;
					kbd_n_bits++;
				} 
				else
					KBD_DATA_DDR |= KBD_DATA_MASK;
		}
	} 
	else
	{
		// Receive data
		
		//if(kbd_bit_n == 1)
		//	kbd_status |= KBD_RECEIVE;

		bit_in=(KBD_DATA_PIN & KBD_DATA_MASK) ? 0x01 : 0x00;
		
		switch (kbd_bit_n)
		{
			case 1 :						// ignore start bit
				//kbd_status |= KBD_RECEIVE;
				break;
					
			case 10 :						// parity bit
				kbd_parity=bit_in;
				break;
				
			//case 11 : 						// stop bit
			//	break;
				
			case 11 :
				kbd_n_bits&=0x01;
				
				// Only queue code if parity is valid.
				if (((kbd_parity==1) && (kbd_n_bits==0)) ||
				    ((kbd_parity==0) && (kbd_n_bits==1)))
					ps2_kbd_queue_scancode(kbd_buffer);

				//log0("scan=%2X, parity=%d, kbd_n_bits=%d\n",kbd_buffer,kbd_parity,kbd_n_bits); 
	
				kbd_buffer = 0;
				kbd_bit_n = 0;
				kbd_parity = 0;
				kbd_n_bits = 0;
				//kbd_status &= ~KBD_RECEIVE;
				break;
				
			default :						// data bits
				if(bit_in)
				{
					kbd_buffer |= (1 << (kbd_bit_n - 2));
					kbd_n_bits++;
				}	
		}
		
	}
	
	kbd_bit_n++;
	
//	KBD_SET_INT();
}
