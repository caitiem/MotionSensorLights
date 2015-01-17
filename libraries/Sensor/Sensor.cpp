#include "Sensor.h"

Sensor::Sensor(int trigPin, int echoPin, int groundPin, int vccPin)
{
	this->trigPin = trigPin;
	this->echoPin = echoPin;
	this->groundPin = groundPin;
	this->vccPin = vccPin;
	
	pinMode (vccPin,OUTPUT);//attach pin 2 to vcc
	pinMode (groundPin,OUTPUT);//attach pin 5 to GND
}

Sensor::Sensor() {
}

long Sensor::microsecondsToInches(long microseconds)
{
	// According to Parallax's datasheet for the PING))), there are
	// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
	// second).  This gives the distance travelled by the ping, outbound
	// and return, so we divide by 2 to get the distance of the obstacle.
	// See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
	return microseconds / 74 / 2;
}

long Sensor::microsecondsToCentimeters(long microseconds)
{
	// The speed of sound is 340 m/s or 29 microseconds per centimeter.
	// The ping travels out and back, so to find the distance of the
	// object we take half of the distance travelled.
	return microseconds / 29 / 2;
}

long Sensor::getDistance()
{
	digitalWrite(vccPin, HIGH);
	
	// The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
	// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
	pinMode(trigPin, OUTPUT);// attach pin 8 to Trig
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(5);
	digitalWrite(trigPin, LOW);
	
	// The same pin is used to read the signal from the PING))): a HIGH
	// pulse whose duration is the time (in microseconds) from the sending
	// of the ping to the reception of its echo off of an object.
	pinMode (echoPin, INPUT);//attach pin 4 to Echo
	long duration = pulseIn(echoPin, HIGH);
	
	inches = microsecondsToInches(duration);
	centimeters = microsecondsToCentimeters(duration);

	return centimeters;
}