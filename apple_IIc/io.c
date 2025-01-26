/*
  io.c	: IO routines for the Apple IIc

  2024-10-20, J.Branton.
*/

#include <avr/interrupt.h>
#include <inttypes.h>
#include <util/delay.h>
#include "globalio.h"
#include "io.h"
#include "status.h"
#include "matrix_kbd.h"
#include "scancode.h"
#include "ps2kbd.h"

extern matrix_t MainMatrix;

static uint8_t	CntrlState;
static uint8_t	CapsLockState;

void InitIO(void)
{
  JSDDR |= (SHIFT_PIN | CNTRL_PIN | OAPPLE_PIN | CAPPLE_PIN | CAPSLOCK_PIN);
  ShiftOff();
  CntrlOff();
  OAppleOff();
  CAppleOff();
  CapsLockOn();
}

void ResetMachine(void)
{
  if (CntrlState)
    {
      ResetTargetMachine();
    }
}

void CntrlOn(void)
{
  (JSPORT &= (~CNTRL_PIN));
  CntrlState = 1;
}

void CntrlOff(void)
{
  (JSPORT |= CNTRL_PIN);
  CntrlState = 0;
}

void CapsLockOn(void)
{
  (JSPORT &= (~CAPSLOCK_PIN));
  CapsLockState = 1;
  PS2SetLED(PS2_LED_CAPS);
}

void CapsLockOff(void)
{
  (JSPORT |= CAPSLOCK_PIN);
  CapsLockState = 0;
  PS2ClearLED(PS2_LED_CAPS);
}

uint8_t TargetKeyCallback(uint8_t PrefixCode, uint8_t KeyCode, uint8_t State)
{
  uint8_t handled = true;

  logv0("TargetKeyCallback Prefix:%2.2X Scan:%2.2X State:%d\n", PrefixCode, KeyCode, State);

  if (PrefixCode == SCAN_CODE_NO_PREFIX) 
    {
      switch (KeyCode)
        {
        case SCAN_CODE_LSHIFT:
        case SCAN_CODE_RSHIFT:
          (State == KEY_DOWN) ? ShiftOn() : ShiftOff();
          break;
        case SCAN_CODE_LCTRL:
          (State == KEY_DOWN) ? CntrlOn() : CntrlOff();
          break;
        case SCAN_CODE_CAPSLOCK:
          if (State == KEY_DOWN)
            {
              CapsLockState ? CapsLockOff() : CapsLockOn();
            }
          break;
        case SCAN_CODE_LALT:
          (State == KEY_DOWN) ? OAppleOn() : OAppleOff();
          break;
        default:
          handled = false;
          break;
        }
    }
  else if (PrefixCode == SCAN_CODE_ESCAPE)
    {
      switch (KeyCode)
        {
        case SCAN_CODE_RCTRL:
          (State == KEY_DOWN) ? CntrlOn() : CntrlOff();
          break;
        case SCAN_CODE_RALT:
          (State == KEY_DOWN) ? CAppleOn() : CAppleOff();
          break;
        default:
          handled = false;
          break;
        }
    }
  else
    {
      handled = false;
    }
	
  return handled;
}  

// Called from main loop.
void MainLoopPoll(void)
{	
}
