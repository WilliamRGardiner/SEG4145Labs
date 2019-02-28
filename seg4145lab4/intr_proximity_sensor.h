#ifndef INTR_PROXIMITY_SENSOR
#define INTR_PROXIMITY_SENSOR

#include "intr_motor.h"

#define SONAR_SENSOR_PIN 22

void intrProximitySensorSetup();
float getDistanceToObstacle();

bool INTR_PROXIMITY_SENSOR_SETUP = false;

void intrProximitySensorSetup() {
  if(!INTR_PROXIMITY_SENSOR_SETUP) {
    INTR_PROXIMITY_SENSOR_SETUP = true;
  }
}

float getDistanceToObstacle() {
//  1. Set up the sonar sensor pin as an output pin.
    pinMode(SONAR_SENSOR_PIN, OUTPUT);
//  2. Write a low value to the pin for two microseconds.
    digitalWrite(SONAR_SENSOR_PIN, LOW);
    delayMicroseconds(2);
//  3. Write a high value to the pin for five microseconds.
    digitalWrite(SONAR_SENSOR_PIN, HIGH);
    delayMicroseconds(5);
//  4. Write a low value to the pin.
    digitalWrite(SONAR_SENSOR_PIN, LOW);
//  5. Set up the sonar sensor pin as an input pin.
    pinMode(SONAR_SENSOR_PIN, INPUT);
//  6. Read the duration of the pulse from the sonar sensor pin (in microseconds) using
//  command pulseIn(pin, HIGH).
    float duration = pulseIn(SONAR_SENSOR_PIN, HIGH);
//  7. Convert the pulse duration time to distance using the following equation:
//  Distance = time / (29 * 2)
//  where time is in microseconds and distance in centimeters. This equation is based
//  on the speed of sound which is 340 m/s. The pulse must travel to the object and
//  back so half the distance value is considered.
    float distance = duration / (29 * 2);
    return distance;
}

#endif
