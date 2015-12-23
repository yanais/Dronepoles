
#include "HCSR04.h"
#include "Pins.h"
#include "arduino.h"

HCSR04* HCSR04::instance = 0;

HCSR04* HCSR04::getInstance()
{
	if(instance == 0)
		instance = new HCSR04;
	return instance;
}
HCSR04::HCSR04(int max_cm_distance)
{
	/*_triggerBit 	= digitalPinToBitMask(HCSR04_TRIGGER_PIN); // Get the port register bitmask for the trigger pin.
	_echoBit 		= digitalPinToBitMask(HCSR04_ECHO_PIN);       // Get the port register bitmask for the echo pin.

	_triggerOutput 	= portOutputRegister(digitalPinToPort(HCSR04_TRIGGER_PIN)); // Get the output port register for the trigger pin.
	_echoInput 		= portInputRegister(digitalPinToPort(HCSR04_ECHO_PIN));         // Get the input port register for the echo pin.

	_triggerMode 	= (uint8_t *) portModeRegister(digitalPinToPort(HCSR04_TRIGGER_PIN)); // Get the port mode register for the trigger pin.
*/
	_maxEchoTime 	= min(max_cm_distance, MAX_SENSOR_DISTANCE) * US_ROUNDTRIP_CM + (US_ROUNDTRIP_CM / 2); // Calculate the maximum distance in uS.
  
  pinMode(HCSR04_TRIGGER_PIN,OUTPUT);
  pinMode(HCSR04_ECHO_PIN,INPUT);
}



unsigned int HCSR04::read() 
{

	if (!trigger()) 
  {  
		return NO_ECHO; 
  }
	while (digitalRead(HCSR04_ECHO_PIN))
	{
		if (micros() > _max_time) 
      return NO_ECHO;       
	  
	}
	return (micros() - (_max_time - _maxEchoTime) - 5); 
}

unsigned int HCSR04::readInch() 
{
	unsigned int echoTime = HCSR04::read();          
	return HCSR04Convert(echoTime, US_ROUNDTRIP_IN);
}

unsigned int HCSR04::readCentimeter() 
{
	unsigned int echoTime = HCSR04::read();         
	return HCSR04Convert(echoTime, US_ROUNDTRIP_CM);
}


boolean HCSR04::trigger() 
{   
	digitalWrite(HCSR04_TRIGGER_PIN,LOW);
	delayMicroseconds(4);            
	digitalWrite(HCSR04_TRIGGER_PIN,HIGH);
	delayMicroseconds(10);           
	digitalWrite(HCSR04_TRIGGER_PIN,LOW);

	_max_time =  micros() + MAX_SENSOR_DELAY;                  
	while (digitalRead(HCSR04_ECHO_PIN) && micros() <= _max_time); 
	while (!digitalRead(HCSR04_ECHO_PIN))
	{	
		if (micros() > _max_time) 
			return false;                
	}
	
	_max_time = micros() + _maxEchoTime; 
	return true;                         
}


