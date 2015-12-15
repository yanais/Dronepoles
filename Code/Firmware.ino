// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     3  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define LedRed		9	
#define LedGreen	6	
#define LedBlue		5	

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

bool isStop = true;
int uS = 0;
int successCounter = 0;
bool goodMessage = false;
bool tooHighMessage = false;
bool tooLowMessage = false;
void setup() {
	//Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
	pinMode(LedRed,OUTPUT);
	pinMode(LedGreen,OUTPUT);
	pinMode(LedBlue,OUTPUT);
	setRGBLed(1,1,0);
	delay(500);
}

void loop() {
	                     
	uS = 0;
	for(int i=0;i<10;i++)
	{
		uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
		delay(5);
	}
	uS = (int)(uS/10);
	//Serial.println(uS);
	if(uS > 50 && uS < 400)
	{
		setRGBLed(1,0,1);
		delay(1000);
	}
	else	
		setRGBLed(0,1,1);
	
	delay(10);
}

void setRGBLed(int R, int G, int B)
{
	digitalWrite(LedRed,R ); //BLUE
	digitalWrite(LedGreen,G); //GREEN
	digitalWrite(LedBlue, B); //RED
}
