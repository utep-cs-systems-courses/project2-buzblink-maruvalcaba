#include <msp430.h>
#include "switches.h"

/* Switch on P2 (SW1-4) */
void
__interrupt_vec(PORT2_VECTOR) Port_1(){
  if (P2IFG & SW1) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SW1;		      /* clear pending sw interrupts */
    switch_interrupt_handler();
  }
  if (P2IFG & SW2) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SW2;		      /* clear pending sw interrupts */
    switch_interrupt_handler();
  }
  if (P2IFG & SW3) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SW3;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	
  }
  if (P2IFG & SW4) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SW4;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	
  }
}

