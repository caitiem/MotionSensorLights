#ifndef MOTION_H
#define MOTION_H

#include "Arduino.h"
#include "Sensor.h"

class Motion
{
	public:
		Motion(Sensor);
		String getMotionType();
	
	private:
		Sensor sensor;
		int distances[15];
		int index;
		int low;
		int [] getLastTen();
};

#endif