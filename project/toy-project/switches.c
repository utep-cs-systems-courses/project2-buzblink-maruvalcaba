#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char switch_state_down, switch_state_changed, blink_count, blink_count2, seconds; /* effectively boolean */
int master, x;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  // P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  master = 0;
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  if((p2val & SW1) == 0){
    seconds = 0;
    blink_count = 0;
    blink_count2 = 0;
    x = 500;
    master = 1;
  }
  else if((p2val & SW2) == 0){
    master = 2;
    seconds = 0;
    blink_count = 0;
    blink_count2 = 0;
    x = 500;
  }
  else{
    master = 0;
    seconds = 0;
    blink_count = 0;
    blink_count2 = 0;
    x = 500;
  }
  switch_state_changed = 1;
}
