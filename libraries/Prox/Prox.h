#ifndef PROX_H
#define PROX_H

#include "Arduino.h"

class Prox
{
	public:
		Prox(double maxDistance);
		void sensor(long distance);
		bool isSwipe();
		bool isLightAdjust();
		bool isObjectClose();
	
	private:
		static const int minProxCount = 3;
		static const int swipeCount = 15;
		static const int proxLength = 3;
		double maxDistance;
		bool closeObject;
		int proxCount[proxLength];
		bool swipe;
		bool lightAdjust;
		static const int distanceDev = 10;
};

#endif