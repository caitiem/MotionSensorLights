#include "Motion.h"

Motion::Motion(Sensor sensor) {
	this->sensor = sensor;
	index = 0;
	low = 0;
}

String Motion::getMotionType() {
	distances[index] = sensor.getDistance();
	String type = "none";
	
	if (index < 15) {
		index++;
	}
	else {
		index = 0;
	}
	
	return type;
}