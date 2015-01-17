#include "Led.h"
#include "Sensor.h"
#include "LightLevels.h"
#include "Prox.h"
#include "Cycle.h"
#include "Filter.h"

long maxDistance = 30, minDistance = 0, distance = 0;
const int ledLength = 5;
Led leds[ledLength] = {(3), (9), (10), (11), (6)};
// Sensor(trigPin, echoPin, groundPin, vccPin);
Sensor sensor(8, 4, 5, 2);
Prox prox(maxDistance);
LightLevels levels(maxDistance, minDistance);
Cycle cycles[ledLength] = {(&leds[0]), (&leds[1]), (&leds[2]), (&leds[3]), (&leds[4])};
boolean on = false, cycling = false, cycleMode = false, doubleSwipe = false, discoMode = false;
int loopCounter = 0;
Filter filter(1000);
unsigned long currentSwipeTime = 0, prevSwipeTime = 20000, prev2SwipeTime = 40000;

void setup() {
  Serial.begin(9600);
  Serial.println("Setup");
}

void loop() {
  distance = sensor.getDistance();
  
  if(loopCounter == 2) {                        // set cutoff for filter
    Serial.print("Distance: ");
    Serial.println(distance);
    filter.setDistanceCutoff(distance);
  } else {
    distance = filter.filterDistance(distance);
  }
  
  prox.sensor(distance);      // give prox sensor distance so proximity of objects can be determined
  
  loopCounter++;
  
  if(on && prox.isSwipe()) {    // turn off white leds if swipe and off
    on = false;
    cycling = false;
    stopCycles();
    turnOffLeds();
    cycleMode = false;
    discoMode = false;
  }else if(!on && prox.isSwipe()) {    // turn on all leds if on and swipe
    on = true;
    cycling = false;
    leds[0].on();
  } else if(!on && prox.isLightAdjust()) {    // start cycling if light adjust and off
    on = true;
    cycling = true;
    cycles[0].startCycle();
  } else if(on && prox.isLightAdjust() && !cycling) {    // adjust brightness if on and light adjust and not cycling lights
    setBrightnessFrac();
  }
  
  // test for 2 or 3 swipes close together to activate disco mode or cycle mode
  if(prox.isSwipe()) {
    Serial.println("Hand Swipe");
    currentSwipeTime = millis();
    if((currentSwipeTime - prevSwipeTime) < 500) {
      cycleMode = true;
      cycling = true;
      on = true;
      cycles[0].startCycle();
      discoMode = false;
      Serial.println("Cycle Mode Activated!");
    }
    if((currentSwipeTime - prev2SwipeTime) < 1000) {
      cycleMode = false;
      cycling = true;
      on = true;
      cycles[0].startCycle();
      discoMode = true;
      Serial.println("Disco Mode Activated!");
    }
    prev2SwipeTime = prevSwipeTime;
    prevSwipeTime = currentSwipeTime;
  }
  
  if(!prox.isObjectClose() && cycling && !cycleMode && !discoMode) {      // stop cycling if no object is detected
    cycling = false;
    stopCycles();
    Serial.println("Stopped cycling.");
  }  
  
  if(on && cycling && !discoMode) {            // if on and cycling leds
    for(int x = 1; x < ledLength; x++) {      // start next led cycle when current cycle reaches max value
      if(cycles[x-1].halfCycle()) {
        cycles[x].startCycle();
      }
    }
    
    if(cycles[ledLength-1].halfCycle() && !leds[ledLength - 1].getStatus()) {    // if end of cycle activate cycle mode
      cycleMode = true;
      Serial.println("Cycle Mode Activated!");
    }
  }
  
  if(cycleMode && cycles[ledLength-1].halfCycle()) {    // if cycleMode and last led is halfway, start cycle again
    cycling = true;
    cycles[0].startCycle();
  }
  
  if(discoMode && cycles[ledLength-1].quarterCycle()) {  // if discoMode and last led is quarter way through, start cycle again
    cycling = true;
    cycles[0].startCycle();
  }
  
  if(on && discoMode) {            // if on and cycling leds
    for(int x = 1; x < ledLength; x++) {      // start next led cycle when current cycle reaches quarter value
      if(cycles[x-1].quarterCycle()) {
        cycles[x].startCycle();
      }
    }
  }
  
  if (on) {        // if lights are on cycle leds
    cycleLeds();
  }
  delay(10);
  
}


void cycleLeds() {
  for(int x = 0; x < ledLength; x++) {
    cycles[x].cycleLed();
  }
}

void stopCycles() {
  for(int x = 0; x < ledLength; x++) {
    cycles[x].stopCycle();
  }
}

void setBrightness() {
  for(int x = 0; x < ledLength; x++) {
    if(leds[x].getStatus()) {
      levels.setLed(&leds[x], distance);
    }
  }
}

void setBrightnessFrac() {
  for(int x = 0; x < ledLength; x++) {
    if(leds[x].getStatus()) {
      levels.setLedFrac(&leds[x], distance);
    }
  }
}

void turnOffLeds() {
  for(int x = 0; x < ledLength; x++) {
    leds[x].off();
  }
}
