#ifndef SENSOR_H
#define SENSOR_H

#include "Arduino.h"

class Sensor
{
public:
	Sensor(int trigPin, int echoPin, int groundPin, int vccPin);
	Sensor();
	long getDistance();
	
private:
	int trigPin;
	int echoPin;
	int	groundPin;
	int vccPin;
	long inches;
	long centimeters;
	
	long microsecondsToInches(long microseconds);
	long microsecondsToCentimeters(long microseconds);
};

#endif