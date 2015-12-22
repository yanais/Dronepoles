#include "RGBLed.h"
#include "Pins.h"
#include "arduino.h"

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
