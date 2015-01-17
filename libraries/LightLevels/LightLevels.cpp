#include "LightLevels.h"

LightLevels::LightLevels(double maxDistance, double minDistance) {
	delta = (maxDistance - minDistance) / length;
	distances[0] = minDistance;
	lightLevels[0] = 1;
	  
	for(int x = 1; x < length; x++)
	{
		distances[x] = distances[x-1] + delta;
		lightLevels[x] = lightLevels[x-1] + lengthDiv;
	}
}

void LightLevels::setLed(Led *led, long distance) {
	int light = 255;
	
	for(int x = 0; x < length - 1; x++) {
		if(distance >= distances[x] && distance <= distances[x+1]) {
			light = lightLevels[x];
		}
	}
	
	(*led).setValue(light);
}

void LightLevels::setLedFrac(Led *led, long distance) {
	int light = 255;
	
	for(int x = 0; x < length - 1; x++) {
		if(distance >= distances[x] && distance <= distances[x+1]) {
			light = lightLevels[x];
		}
	}
	(*led).setValueFrac(light);
}