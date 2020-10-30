#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"

char blink_count;
char blink_count2;
char seconds;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  if(master == 0){
    buzzer_set_period(0);
    both_on();
  }
  if(master == 1){
    if(seconds != 2){
      blink_count++;
      buzzer_set_period(2000000/x);
      go_up();
      if(++blink_count2 == 250){
	blink_count = 0;
	blink_count2 = 0;
	seconds+=1;
      }
    }
    else{
      blink_count++;
      buzzer_set_period(2000000/x);
      go_down();
      if(++blink_count2 == 250){
	blink_count = 0;
	blink_count2 = 0;
	seconds = 0;
      }
    }
  }
  if(master == 2){
    if(blink_count == 0){
      buzzer_set_period(2000000/2500);
      green_on_all();
      red_off();
    }
    if(++blink_count == 50){
      buzzer_set_period(2000000/500);
      red_on_all();
      green_off();
    }
    if(blink_count == 100){
      blink_count = 0;
    }
  }
}
