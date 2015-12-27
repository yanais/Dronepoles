#ifndef HCSR04_H
#define HCSR04_H

#include "Arduino.h"
#include "avr/io.h"
#include "Pins.h"

#define MAX_EHCO_DOWN 500			// Time out for waiting EHCO raise up in uS
#define MAX_EHCO_UP 30000			// Time out for waiting EHCO fall down in uS
#define TIME_OUT -1					// Time out error

#define INCH_ROUNDTRIP_TIME 148		//The time(in uS) take the sound to move 2 inches
#define CM_ROUNDTRIP_TIME 58		//The time(in uS) take the sound to move 2 centimetres


class HCSR04
{
	public:
		static HCSR04* getInstance();
		int read();
		int readInches();
		int readCentimeters();
	protected: //protected insure just one instance will create
		HCSR04();
	private:
		static HCSR04* instance;

    //register from pins:
    uint8_t triggerBitMask;
    uint8_t echoBitMask;
    volatile uint8_t *triggerOutputRegister;
    volatile uint8_t *echoInputRegister;
};


#endif //HCSR04_H
