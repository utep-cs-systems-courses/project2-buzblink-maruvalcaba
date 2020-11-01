## Description
This program utilizes the 4 buttons on the green board, SW1 - SW4, to switch
between different states of the toy. Pressing the different buttons will have
a different toy function be enabled.

## How to use

(1) To compile the program, use the command 'make' to compile all the
necessary files. Then, use the command 'make load' and this should load it
onto the MSP430.

(2) When the device is powered on and loaded, it will be in an idle state with
both leds active on the board, no sound.

(3) If you press the different switches they will have different
outcomes.

- Pressing SW1 will do a siren with leds depending on the movement of
the frequency.

- Pressing SW2 will do a funky ambulance sound with alternating
leds.

- Pressing SW3 will do a dimming sequence with sound that follows it.

- Pressing SW4 will set the toy back to the idle mode.









