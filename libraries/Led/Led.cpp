#include "Led.h"

Led::Led(int pin) {
	this->pin = pin;
	status = false;
	pinMode (pin,OUTPUT);
	fraction = 1.0;
}

Led::Led() {}

void Led::on() {
	analogWrite(pin, 255);
	status = true;
	fraction = 1.0;
}

void Led::off() {
	analogWrite(pin, 0);
	status = false;
	fraction = 1.0;
}

void Led::setValue(int value) {
	analogWrite(pin, value);
	if(value > 0) {
		status = true;
	} else {
		status = false;
	}
}

void Led::setValueFrac(int value) {
	analogWrite(pin, value * fraction);
	if(value > 0) {
		status = true;
	} else {
		status = false;
	}
	
	/*Serial.print("Value = ");
	Serial.println(value);
	Serial.print("Fraction = ");
	Serial.println(fraction);
	Serial.print("Mult = ");
	Serial.println(value * fraction);*/
}

bool Led::getStatus() {
	return status;
}

int Led::getPin() {
	return pin;
}

double Led::getFraction() {
	return fraction;
}

void Led::setFraction(double newFraction) {
	fraction = newFraction;
}