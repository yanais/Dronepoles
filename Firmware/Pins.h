/*
PIN OUT header file

Produced automatically by Circuito Ltd

MicroController - Arduino pro micro 5V/16MHz
Peripherals:
	inputs:
		HC-SR04 Ultrasonic sensor
	outputs:
		RGB Led Common anode
*/

#ifndef PINS_H
#define PINS_H

/*HC-SR04*/
#define HCSR04_ECHO_PIN 	3
#define HCSR04_TRIGGER_PIN 	4

/*RGB led Common anode*/
#define RGBLED_RED_PIN 		5 
#define RGBLED_GREEN_PIN	6
#define RGBLED_BLUE_PIN		9

#endif //__PINS_H
