#include "HCSR04.h"
#include "RGBLed.h"

HCSR04 ultrasonic;
RGBLed led;

void setup() 
{
	Serial.begin(9600);
Serial.println("start2");
  
  
}

void loop() 
{	    
    Serial.println("st2");
	int sample;
	sample = ultrasonic.read(); 
        Serial.println(sample);
	if(sample > 200)
		led.setRGB(255,0,0);
	else if(sample > 100)
		led.setRGB(0,255,0);
	else
		led.setRGB(0,0,255);
		
	delay(200);
}


