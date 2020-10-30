#ifndef led_included
#define  led_included

#include <msp430.h>

#define LED_RED BIT6               // P1.0
#define LED_GREEN BIT0             // P1.6
#define LEDS (BIT0 | BIT6)

extern unsigned char red_on, green_on;
extern unsigned char led_changed;

void led_init();		/* initialize LEDs */
void led_update();		/* update leds */
char red_on_all();

char toggle_red();

char red_33();

char red_66();

char red_25();

char green_on_all();

char toggle_green();

char green_33();

char green_66();

char green_25();

// these are boolean flags
extern unsigned char leds_changed, green_led_state, red_led_state;

#endif
