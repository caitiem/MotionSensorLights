#include "Prox.h"

Prox::Prox(double maxDistance) {
	this->maxDistance = maxDistance;
	closeObject = false;
	swipe = false;
	lightAdjust = false;
	
	for(int x = 0; x < proxLength; x++) {
		proxCount[x] = 0;
	}
}

void Prox::sensor(long distance) {
	
	for(int x = proxLength - 1; x > 0; x--) {
		proxCount[x] = proxCount[x-1];
	}
	
	swipe = false;
	lightAdjust = false;
	
	if (distance <= maxDistance + distanceDev) {
		proxCount[0]++;
	} else {
		proxCount[0] = 0;
	}
	
	if (proxCount[0] >= minProxCount) {
		closeObject = true;
	} else {
		closeObject = false;
	}
	
	if (proxCount[0] == 0 && proxCount[1] == 0 && proxCount[2] <= swipeCount && proxCount[2] >= minProxCount) {
		swipe = true;
	}
	if (proxCount[0] > swipeCount) {
		lightAdjust = true;
	}
}

bool Prox::isSwipe() {
	return swipe;
}

bool Prox::isLightAdjust() {
	return lightAdjust;
}

bool Prox::isObjectClose() {
	return closeObject;
}