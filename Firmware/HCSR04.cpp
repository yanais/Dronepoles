#include "HCSR04.h"

/**************************************************************/
/* Singelton section - promise just one instance of this class*/
/**************************************************************/
HCSR04* HCSR04::instance = 0;
HCSR04* HCSR04::getInstance()
{
	if(instance == 0)
		instance = new HCSR04;
	return instance;
}
/*End singleton section*/

/***********************/
/*Class implemantation:*/
/***********************/

HCSR04::HCSR04() //HCSR04 constractor function
{
	triggerBitMask 	= digitalPinToBitMask(HCSR04_TRIGGER_PIN); // Get the port register bitmask for the trigger pin.
	echoBitMask 		= digitalPinToBitMask(HCSR04_ECHO_PIN);       // Get the port register bitmask for the echo pin.

	triggerOutputRegister 	= portOutputRegister(digitalPinToPort(HCSR04_TRIGGER_PIN)); // Get the output port register for the trigger pin.
	echoInputRegister 		= portInputRegister(digitalPinToPort(HCSR04_ECHO_PIN));         // Get the input port register for the echo pin.

	pinMode(HCSR04_TRIGGER_PIN,OUTPUT);
	pinMode(HCSR04_ECHO_PIN,INPUT);
}

int HCSR04::read() 
{
	//Send 10uS high pulse to the trigger pin:
	*triggerOutputRegister |= triggerBitMask;	// Set trigger pin high
	delayMicroseconds(10);						// Wait 10uS
	*triggerOutputRegister &= ~triggerBitMask;	// Set trigger pin low.

	//Wait ehco pin to turn up:
	uint8_t timeOut =  micros() + MAX_EHCO_DOWN; // Set a timeout for waiting echo to raise
	while (!(*echoInputRegister & echoBitMask)) 
	{
		if (micros() > timeOut) 
			return TIME_OUT;
	}

	//Wait echo pin to turn down:
	timeOut = micros() + MAX_EHCO_UP; // Set a timeout for waiting echo to fall
	while (*echoInputRegister & echoBitMask)
	{
		if (micros() > timeOut) 
			return TIME_OUT;       	  
	}
	return micros() - (timeOut - MAX_EHCO_UP); 
}

int HCSR04::readInches() //Convert uS to inches
{
	unsigned int echoTime = HCSR04::read(); 
	return (echoTime == TIME_OUT) ? TIME_OUT : echoTime / INCH_ROUNDTRIP_TIME; 
}

int HCSR04::readCentimeters() //Convert uS to centimetres
{
	unsigned int echoTime = HCSR04::read();         
	return (echoTime == TIME_OUT) ? TIME_OUT : echoTime / CM_ROUNDTRIP_TIME;
}

/*End class implemantation*/




