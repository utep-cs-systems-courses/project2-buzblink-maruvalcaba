#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char blink_count2 = 0;
  static char seconds = 0;
  if(master == 0){
    buzzer_set_period(0);
    both_on();
    seconds = 0;
    blink_count = 0;
    blink_count2 = 0;
    x = 500;
  }
  if(master == 1){
    if(seconds != 2){
      if(++blink_count%25 == 0){
	go_up();
	buzzer_set_period(2000000/x);
      }
      if(++blink_count2 == 250){
	blink_count = 0;
	blink_count2 = 0;
	seconds+=1;
      }
    }
    else{
      if (++blink_count%25 == 0){
	go_down();
	buzzer_set_period(2000000/x);
      }
      if(++blink_count2 == 250){
	blink_count = 0;
	blink_count2 = 0;
	seconds = 0;
      }
    }
  }
}
