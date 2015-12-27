#include "RGBLed.h"

/**************************************************************/
/* Singelton section - promise just one instance of this class*/
/**************************************************************/
RGBLed* RGBLed::instance = 0;
RGBLed* RGBLed::getInstance()
{
	if(instance == 0)
		instance = new RGBLed;
	return instance;
}

/*End singleton section*/

/***********************/
/*Class implemantation:*/
/***********************/

RGBLed::RGBLed()
{
    pinMode(RGBLED_RED_PIN, OUTPUT);
	pinMode(RGBLED_GREEN_PIN, OUTPUT);
	pinMode(RGBLED_BLUE_PIN, OUTPUT);
}
void RGBLed::setRGB(int R, int G, int B)
{
	analogWrite(RGBLED_RED_PIN,255-R);
	analogWrite(RGBLED_GREEN_PIN,255-G);
	analogWrite(RGBLED_BLUE_PIN,255-B);
}
void RGBLed::turnOff()
{
	digitalWrite(RGBLED_RED_PIN,0);
	digitalWrite(RGBLED_GREEN_PIN,0);
	digitalWrite(RGBLED_BLUE_PIN,0);
}
