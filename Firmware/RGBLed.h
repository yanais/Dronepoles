#ifndef RGBLED_H
#define RGBLED_H

#include "Pins.h"
#include "arduino.h"

class RGBLed
{
	public:
		static RGBLed* getInstance();
		void setRGB(int R, int G, int B);             
		void turnOff();  
	protected:
		RGBLed();
	private:
		static RGBLed* instance;
};
#endif //__RGBLED_H
