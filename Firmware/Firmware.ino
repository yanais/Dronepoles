#include "HCSR04.h"
#include "RGBLed.h"

HCSR04 ultrasonic;
RGBLed led;

void setup() 
{
	
}

void loop() 
{	    
	int sample;
	sample = ultrasonic.read(); 
	if(sample > 200)
		led.setRGB(255,0,0);
	else if(sample > 100)
		led.setRGB(0,255,0);
	else
		led.setRGB(0,0,255);
		
	delay(100);
}


