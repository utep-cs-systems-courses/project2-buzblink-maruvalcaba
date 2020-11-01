#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"

char blink_count;
char blink_count2;
char seconds;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  if(master == 0){                      /* if master state is 0 */
    if(blink_count == 0){
      buzzer_set_period(0);             /* no more buzzing */
      both_on();                        /* both lights on to indicate idle */
      blink_count = 1;                  /* this is so it will only have to update once */
    }
  }
  if(master == 1){                      /* if master state is 1, do siren */
    if(seconds != 2){                   /* if 2 seconds have not gone by yet */
      blink_count++;
      buzzer_set_period(2000000/x);     /* set buzzer */
      go_up();
      if(++blink_count2 == 250){        /* if a second has gone by */
	blink_count = 0;                /* reset everything and count a second */
	blink_count2 = 0;
	seconds+=1;
      }
    }
    else{
      blink_count++;
      buzzer_set_period(2000000/x);     /* set buzzer */
      go_down();
      if(++blink_count2 == 250){        /* if a second has gone by */
	blink_count = 0;                /* reset everything and set seconds to 0 */
	blink_count2 = 0;
	seconds = 0;
      }
    }
  }
  if(master == 2){                      /* if the master state is 2, do a weird ambulance */
    if(blink_count == 0){
      buzzer_set_period(2000000/2500);  /* set buzzer */
      green_on_all();                   /* 2 lines set lights */
      red_off();
    }
    if(++blink_count == 50){            /* if 1/5 of a second has gone by */
      buzzer_set_period(2000000/500);   /* set buzzer */
      red_on_all();                     /* set leds */
      green_off();
    }
    if(blink_count == 100){             /* if another 1/5 of a second has gone by */
      blink_count = 0;
    }
  }
  if(master == 3){                      /* if master state is 3, do dimming and sound */
    if(substate == 10){                 /* if substate is out of bounds, go to the beginning */
      x = 1500;
      substate = 0;
    }
    state_advance();                    /* advance the substate */
    buzzer_set_period(2000000/x);       /* set buzzer */
    if(++blink_count == 50){            /* if 1/5 of a second has gone by */
      substate++;
      x-=100;
      blink_count = 0;
    }
  }
}
