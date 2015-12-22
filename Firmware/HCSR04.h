
#ifndef HCSR04_H
#define HCSR04_H

#include "Arduino.h"

#include "avr/io.h"

#define MAX_SENSOR_DISTANCE 500 // Maximum sensor distance can be as high as 500cm, no reason to wait for ping longer than sound takes to travel this distance and back.
#define US_ROUNDTRIP_IN 146     // Microseconds (uS) it takes sound to travel round-trip 1 inch (2 inches total), uses integer to save compiled code space.
#define US_ROUNDTRIP_CM 57      // Microseconds (uS) it takes sound to travel round-trip 1cm (2cm total), uses integer to save compiled code space.

// Probably shoudln't change these values unless you really know what you're doing.
#define NO_ECHO 0               // Value returned if there's no ping echo within the specified MAX_SENSOR_DISTANCE or max_cm_distance.
#define MAX_SENSOR_DELAY 18000  // Maximum uS it takes for sensor to start the ping (SRF06 is the highest measured, just under 18ms).
#define ECHO_TIMER_FREQ 24      // Frequency to check for a ping echo (every 24uS is about 0.4cm accuracy).
#define PING_MEDIAN_DELAY 29    // Millisecond delay between pings in the ping_median method.

// Conversion from uS to distance (round result to nearest cm or inch).
#define HCSR04Convert(echoTime, conversionFactor) (max((echoTime + conversionFactor / 2) / conversionFactor, (echoTime ? 1 : 0)))

class HCSR04
{
	public:
		HCSR04(int max_cm_distance = MAX_SENSOR_DISTANCE);
		unsigned int read();
		unsigned int readInch();
		unsigned int readCentimeter();

	private:
		boolean trigger();
		uint8_t _triggerBit;
		uint8_t _echoBit;
		volatile uint8_t *_triggerOutput;
		volatile uint8_t *_triggerMode;
		volatile uint8_t *_echoInput;
		unsigned int _maxEchoTime;
		unsigned long _max_time;
};


#endif //HCSR04_H
