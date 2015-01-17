#ifndef CYCLE_H
#define CYCLE_H

#include "Arduino.h"
#include "Led.h"

class Cycle
{
	public:
		Cycle(Led *led);
		void startCycle();
		void stopCycle();
		void cycleLed();
		bool halfCycle();
		bool quarterCycle();
	
	private:
		static const int ledMax = 255;
		bool cycle;
		Led *led;
		int ledValue;
		bool half;
		bool quarter;
};

#endif