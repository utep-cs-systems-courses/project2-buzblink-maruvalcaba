#ifndef stateMachine_included
#define stateMachine_included

extern int master;

extern int x;

extern char blink_count2;

extern char seconds;

extern char blink_count;

void state_advance();

void go_up();

void go_down();

void red_off();

void green_off();

void both_on();

void buzzer_advance(int sb);
#endif // included
