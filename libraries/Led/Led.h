#ifndef LED_H
#define LED_H

#include "Arduino.h"

class Led
{
	public:
		Led(int pin);
		Led();
		void on();
		void off();
		void setValue(int value);
		bool getStatus();
		int getPin();
		double getFraction();
		void setFraction(double newFraction);
		void setValueFrac(int value);
	
	private:
		int pin;
		bool status;
		double fraction;
};

#endif