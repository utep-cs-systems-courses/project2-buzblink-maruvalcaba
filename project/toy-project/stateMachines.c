#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

int master = 0;                 /* master state set automatically to 0 */
int substate = 0;               /* substate set automatically to 0 */
int x = 500;                    /* x set to 0 */

void red_off()                  /* red light off*/
{
  red_on = 0;
  led_changed = 1;
  led_update();
}

void green_off()                /* green light off */
{
  green_on = 0;
  led_changed = 1;
  led_update();
}

void both_on()                  /* both lights on */
{
  red_on = 1;
  green_on = 1;
  led_changed = 1;
  led_update();
}

char red_on_all()	        /* 100% brightness red */
{
  red_on = 1;
  led_changed = 1;
  led_update();
  return 1;			
}

char toggle_red()		/* 50% brightness red */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			
}

char red_33()		        /* 33% brightness red */
{
  static char state2 = 0;

  switch (state2) {
  case 0:
    red_on = 0;
    state2 = 1;
    break;
  case 1:
    red_on = 0;
    state2 = 2;
    break;
  case 2:
    red_on = 1;
    state2 = 0;
    break;
  }
  return 1;			
}

char red_66()		        /* 66% brightness red */
{
  static char state3 = 0;
  
  switch (state3) {
  case 0:
    red_on = 0;
    state3 = 1;
    break;
  case 1:
    red_on = 1;
    state3 = 2;
    break;
  case 2:
    red_on = 1;
    state3 = 0;
    break;
  }
  return 1;		       
}

char red_25()	                /* 25% brightness red */
{
  static char state4 = 0;
  
  switch (state4) {
  case 0:
    red_on = 0;
    state4 = 1;
    break;
  case 1:
    red_on = 0;
    state4 = 2;
    break;
  case 2:
    red_on = 0;
    state4 = 3;
    break;
  case 3:
    red_on = 1;
    state4 = 0;
  }
  return 1;			
}

char green_on_all()		/* 100% brightness green */
{
  green_on = 1;
  return 1;			
}

char toggle_green()		/* 50% brightness green */
{
  static char state5 = 0;
  
  switch (state5) {
  case 0:
    green_on = 0;
    state5 = 1;
    break;
  case 1:
    green_on = 1;
    state5 = 0;
    break;
  }
  return 1;		      
}

char green_33()		/* 33% brightness green */
{
  static char state6 = 0;
  
  switch (state6) {
  case 0:
    green_on = 0;
    state6 = 1;
    break;
  case 1:
    green_on = 0;
    state6 = 2;
    break;
  case 2:
    green_on = 1;
    state6 = 0;
    break;
  }
  return 1;			
}

char green_66()		/* 66% brightness green */
{
  static char state7 = 0;
  
  switch (state7) {
  case 0:
    green_on = 0;
    state7 = 1;
    break;
  case 1:
    green_on = 1;
    state7 = 2;
    break;
  case 2:
    green_on = 1;
    state7 = 0;
    break;
  }
  return 1;		      
}

char green_25()		/* 25% brightness green */
{
  static char state8 = 0;

  switch (state8) {
  case 0:
    green_on = 0;
    state8 = 1;
    break;
  case 1:
    green_on = 0;
    state8 = 2;
    break;
  case 2:
    green_on = 0;
    state8 = 3;
    break;
  case 3:
    green_on = 1;
    state8 = 0;
  }
  return 1;			  
}

void state_advance()   		   /* switch between different dimming modes */
{
  switch(substate){
  case 0:
    led_changed = red_on_all();    /* 100% brightness red */
    buzzer_set_period(2000000/x);       /* set buzzer */
    green_on = 0; break;
  case 5:
    led_changed = green_on_all();  /* 100% brightness green */
    buzzer_set_period(2000000/x);       /* set buzzer */
    red_on = 0; break;
  case 1:
    led_changed = red_66();        /* 66% brightness red */
    buzzer_set_period(2000000/x);       /* set buzzer */
    green_on = 0; break;
  case 6:
    led_changed = green_66();      /* 66% brightness green */
    buzzer_set_period(2000000/x);       /* set buzzer */
    red_on = 0; break;
  case 2:
    led_changed = toggle_red();    /* 50% brightness red */
    buzzer_set_period(2000000/x);       /* set buzzer */
    green_on = 0; break;
  case 7:
    led_changed = toggle_green();  /* 50% brightness green */
    buzzer_set_period(2000000/x);       /* set buzzer */
    red_on = 0; break;
  case 3:
    led_changed = red_33();        /* 33% brightness red */
    buzzer_set_period(2000000/x);       /* set buzzer */
    green_on = 0; break;
  case 8:
    led_changed = green_33();      /* 33% brightness green */
    buzzer_set_period(2000000/x);       /* set buzzer */
    red_on = 0; break;
  case 4:
    led_changed = red_25();        /* 25% brightness red */
    buzzer_set_period(2000000/x);       /* set buzzer */
    green_on = 0; break;
  case 9:
    led_changed = green_25();      /* 25% brightness green */
    buzzer_set_period(2000000/x);       /* set buzzer */
    red_on = 0; break;
  }
  led_update();
}

void go_up()                        /* function that moves the frequency up and enables a specific light */
{
  static char sb = 0;               /* indicates if we are moving up or down */
  sb = 0;
  led_changed = 1;
  green_on = 1;
  red_on = 0;
  led_update();
  buzzer_set_period(2000000/x);     /* set buzzer */
  buzzer_advance(sb);
}

void go_down()                      /* function that moves the frequency down and enables a specific light */
{
  static char sb = 0;               /* indicates if we are moving up or down */
  sb = 1;
  led_changed = 1;
  red_on = 1;
  green_on = 0;
  led_update();
  buzzer_set_period(2000000/x);     /* set buzzer */
  buzzer_advance(sb);
}

void buzzer_advance(int sb)	    /* advances the buzzer for a certain function */
{
  switch(sb){
  case 0:
    x+=8;                           /* increases the frequency by 8 */
    break;
  case 1:
    x-=16;                          /* decreases the frequecy by 16 */
    break;
  }
}

void ambulance_advance(int stateA)
{
  switch(stateA){
  case 0:
    buzzer_set_period(2000000/2500);  /* set buzzer */
      green_on_all();                   /* 2 lines set lights */
      red_off();
      break;
  case 1:
    buzzer_set_period(2000000/500);   /* set buzzer */
      red_on_all();                     /* set leds */
      green_off();
      break;
  }
}



