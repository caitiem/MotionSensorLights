#include "Cycle.h"

Cycle::Cycle(Led *led) {
	this->led = led;
	cycle = false;
	ledValue = 0;
	half = false;
	quarter = false;
}

void Cycle::startCycle() {
	cycle = true;
}

void Cycle::stopCycle() {
	(*led).setFraction((double)ledValue / (double)ledMax);
	cycle = false;
	ledValue = 0;
	half = false;
	quarter = false;
}

void Cycle::cycleLed() {
	if (!cycle) {
		return;
	}
	if (ledValue < 0) {
		ledValue = 0;
		cycle = false;
		half = false;
		quarter = false;
	}
	
	(*led).setValue(ledValue);
	if(ledValue >= ledMax / 2) {
		quarter = true;
	}
	if(ledValue >= ledMax) {
		half = true;
	}
	if(!half) {
		ledValue += 3;
		if(ledValue > ledMax) {
			ledValue = ledMax;
		}
	} else {
		ledValue -= 3;
	}
}

bool Cycle::halfCycle() {
	return half;
}

bool Cycle::quarterCycle() {
	return quarter;
}