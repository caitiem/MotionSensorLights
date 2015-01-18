# MotionSensorLights
Arduino based motion sensor lights.


-How this project works:

	A hand swipe is used to turn the first LED on if the light is on and off if the light is on.
	
	After the first hand swipe, your hand can be used to dim the light by lowering your hand over the sensor or brighten the light by raising your hand over the sensor.
	
	If the light is off initially, you can place your hand over the sensor to cycle through the lights to get a different light or combo. Just remove your hand when you have the combo you want. Warning, if you get to the end of the cycle, cycle mode is activated.
	
	Cycle mode cycles through the lights with the next light starting when the previous light reaches full brightness. Disco mode cycles throught the lights with the next light starting when the previous light reaches half brightness.
	
	Two hand swipes close together activates cycle mode. Three hand swipes close together activates disco mode.
	
	


-This project requires an arduino.

-It is set up to use five LEDs with resistors.

-It also requires an ultrasonic sensor. (Model is HC-SR04)


-To hook up LEDS:

	Use a resistor and an LED for each pin.
	
	You can change the pin numbers in the code but not all the pins have PWM (Pulse Width Modulation).
	
	The pins used in the code are 3, 9, 10, 11, 6.
	
	Don't forget to ground your pins.


-To hook up the sensor (vcc, trig, echo, and gnd are labeled on sensor):

	Pin 8 should connect to the trig pin on the sensor.
	
	Pin 4 should connect to the echo pin on the sensor.
	
	Pin 5 should connect to the gnd pin on the sensor.
	
	Pin 2 should connect to the vcc pin on the sensor.
