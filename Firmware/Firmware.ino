#include "HCSR04.h"
#include "RGBLed.h"

HCSR04 *ultrasonic;
RGBLed *led;

void setup() 
{
	Serial.begin(9600);
	Serial.println("start2");
	ultrasonic = HCSR04::getInstance();
	led = RGBLed::getInstance();
	
	led->setRGB(255,0,0);
	delay(500);
	led->setRGB(0,255,0);
	delay(500);
	led->setRGB(0,0,255);
	delay(500);
}

void loop() 
{	
	int sample;
	sample = ultrasonic->read(); 
	Serial.println(sample);
	if(sample > 2000)
		led->setRGB(255,0,0);
	else if(sample > 1000)
		led->setRGB(0,255,0);
	else
		led->setRGB(0,0,255);
		
	delay(200);
}


