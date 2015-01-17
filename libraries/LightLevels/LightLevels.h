#ifndef LIGHTLEVELS_H
#define LIGHTLEVELS_H

#include "Arduino.h"
#include "Led.h"

class LightLevels
{
	public:
		LightLevels(double maxDistance, double minDistance);
		void setLed(Led *led, long distance);
		void setLedFrac(Led *led, long distance);
	
	private:
		static const int lengthDiv = 2;
		static const int length = 255 / lengthDiv;
		double delta;
		int lightLevels[length];
		double distances[length];
};

#endif