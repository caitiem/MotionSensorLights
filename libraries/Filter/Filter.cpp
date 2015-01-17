#include "Filter.h"

Filter::Filter(long distanceCutoff) {
	this->distanceCutoff = distanceCutoff;
	distance = 1000;
}

Filter::Filter() {
	distanceCutoff = 1000;
	distance = 1000;
}

long Filter::filterDistance(long newDistance) {
	if(newDistance <= distanceCutoff + distanceDev) {
		distance = newDistance;
	}
	return distance;
}

void Filter::setDistanceCutoff(long newCutoff) {
	distanceCutoff = newCutoff;
}