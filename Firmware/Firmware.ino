#include "HCSR04.h"
#include "RGBLed.h"

//Modules pointers
HCSR04 *ultrasonic;
RGBLed *led;

void setup() 
{
	Serial.begin(9600);

	ultrasonic = HCSR04::getInstance();
	led = RGBLed::getInstance();
}

void loop() 
{	
	int sample;
	sample = ultrasonic->readCentimeters(); 
	Serial.println(sample);
	if(sample > 100)
		led->setRGB(255,0,0);
	else if(sample > 50)
		led->setRGB(0,255,0);
	else
		led->setRGB(0,0,255);
		
	delay(200);
}


