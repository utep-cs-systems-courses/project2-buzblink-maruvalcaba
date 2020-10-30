#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "stateMachines.h"

int master = 1;
int x = 500;

void red_off()
{
  red_on = 0;
  led_changed = 1;
  led_update();
}

void green_off()
{
  green_on = 0;
  led_changed = 1;
  led_update();
}

void both_on()
{
  red_on = 1;
  green_on = 1;
  led_changed = 1;
  led_update();
}

char red_on_all()		/* always toggle! */
{
  red_on = 1;
  led_changed = 1;
  led_update();
  return 1;			/* always changes an led */
}

char toggle_red()		/* always toggle! */
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
  return 1;			/* always changes an led */
}

char red_33()		/* always toggle! */
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
  return 1;			/* always changes an led */
}

char red_66()		/* always toggle! */
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
  return 1;			/* always changes an led */
}

char red_25()		/* always toggle! */
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
  return 1;			/* always changes an led */
}

char green_on_all()		/* always toggle! */
{
  green_on = 1;
  return 1;			/* always changes an led */
}

char toggle_green()		/* always toggle! */
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
  return 1;			/* always changes an led */
}

char green_33()		/* always toggle! */
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
  return 1;			/* always changes an led */
}

char green_66()		/* always toggle! */
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
  return 1;			/* always changes an led */
}

char green_25()		/* always toggle! */
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
  return 1;			/* always changes an led */
}
/*
char toggle_green()	 only toggle green if red is on!  
{
  char changed = 0;
  if(red_on){
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}
*/

void state_advance()		/* alternate between toggling red & green */
{
  switch(master){
  case 0:
    led_changed = red_on_all();
    green_on = 0; break;
  case 5:
    led_changed = green_on_all();
    red_on = 0; break;
  case 1:
    led_changed = red_66();
    green_on = 0; break;
  case 6:
    led_changed = green_66();
    red_on = 0; break;
  case 2:
    led_changed = toggle_red();
    green_on = 0; break;
  case 7:
    led_changed = toggle_green();
    red_on = 0; break;
  case 3:
    led_changed = red_33();
    green_on = 0; break;
  case 8:
    led_changed = green_33();
    red_on = 0; break;
  case 4:
    led_changed = red_25();
    green_on = 0; break;
  case 9:
    led_changed = green_25();
    red_on = 0; break;
  }
  led_update();
}

void go_up()
{
  static char sb = 0;
  sb = 0;
  led_changed = 1;
  green_on = 1;
  red_on = 0;
  led_update();
  buzzer_advance(sb);
}

void go_down()
{
  static char sb = 0;
  sb = 1;
  led_changed = 1;
  red_on = 1;
  green_on = 0;
  led_update();
  buzzer_advance(sb);
}

void buzzer_advance(int sb)		/* alternate between toggling red & green */
{
  switch(sb){
  case 0:
    x+=8;
    break;
  case 1:
    x-=16;
    break;
  }
}




