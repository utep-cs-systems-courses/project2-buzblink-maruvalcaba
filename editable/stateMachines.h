#ifndef stateMachine_included
#define stateMachine_included

extern int master;

extern int x;

void state_advance();

void go_up();

void go_down();

void both_on();

void buzzer_advance(int sb);
#endif // included
