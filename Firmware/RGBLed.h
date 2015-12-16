#ifndef RGBLED_H
#define RGBLED_H

class RGBLed
{
	public:
		RGBLed();
		void setRGB(int R, int G, int B);             
		void turnOff();  
};
#endif //__RGBLED_H