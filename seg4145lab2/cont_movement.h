#ifndef CONT_MOVEMENT_H
#define CONT_MOVEMENT_H
/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 *   (8135145) Jessica Zhan
 * Course Info: 
 *   SEG 4145
 *   Common Utility
 *7
 * cont_movement
 *   This module acts as a controller for the movement of the robot.
 *
 * Date: 
 *   15 January 2019
 *****************************************************************************/
#include "intr_lcd_display.h"
#include "intr_motor.h"
#include "intr_wheel_sensor.h"

#define DISTANCE_BETWEEN_WHEELS   20.0 // The distance, in cm, between the wheels on the robot
// #define ADJUSTMENT_PERIOD        200.0 // Amount of time between adjustments in ms

// Footprints
void contMovementSetup();
void turnLeft(float rotations);
void turnRight(float rotations);
void moveForward(float distance);
void moveBackward(float distance);
void runUntil(int totalTicks);
void readSensor(float inReading, float* inOutOldReading, int* inOutTicks, bool* inOutHigh);
void stopMovement();

/******************************************************************************
* contMovementSetup
*   Prepares the movement controller to be used.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void contMovementSetup() {
  intrLcdDisplaySetup();
  intrMotorSetup();
  intrWheelSensorSetup();
}

/******************************************************************************
* turnLeft
*   Turns the robot CCW a certain number of rotations.
*   
* Parameters:
*   float rotations - Then number of rotations
*
* Returns:
*   void
*****************************************************************************/
void turnLeft(float rotations) {
  displayCenteredMessage("Turning", "Left");
  leftForward();
  rightBackward();
  runUntil((rotations * (DISTANCE_BETWEEN_WHEELS * PI / 2.0) / (WHEEL_DIAMETER * PI)) * TICKS_PER_ROTATION);
  stopBoth();
}

/******************************************************************************
* turnRight
*   Turns the robot CW a certain number of rotations.
*   
* Parameters:
*   float rotations - Then number of rotations
*
* Returns:
*   void
*****************************************************************************/
void turnRight(float rotations) {
  displayCenteredMessage("Turning", "Right");
  leftBackward();
  rightForward();
  runUntil((rotations * (DISTANCE_BETWEEN_WHEELS * PI / 2.0) / (WHEEL_DIAMETER * PI)) * TICKS_PER_ROTATION);
  stopBoth();
}

/******************************************************************************
* moveForwardTime
*   Move the robot forward for a given distance.
*   
* Parameters:
*   float distance - The distance of the movement in cm
*
* Returns:
*   void
*****************************************************************************/
void moveForward(float distance) {
  displayCenteredMessage("Moving", "Forward");
  leftForward();
  rightForward();
  runUntil(distance / (WHEEL_DIAMETER * PI) * TICKS_PER_ROTATION);
  stopBoth();
}

/******************************************************************************
* moveBackward
*   Move the robot backward for a given disatance.
*   
* Parameters:
*   float distance - The distance of the movement in cm
*
* Returns:
*   void
*****************************************************************************/
void moveBackward(float distance) {
  displayCenteredMessage("Moving", "Backward");
  leftBackward();
  rightBackward();
  runUntil(distance / (WHEEL_DIAMETER * PI) * TICKS_PER_ROTATION);
  stopBoth();
}

/******************************************************************************
* moveBackward
*   Move the robot backward for a given disatance.
*   
* Parameters:
*   int totalTicks - The total number of sensor transitions before each 
*   wheel should stop. 
*
* Returns:
*   void
*****************************************************************************/
void runUntil(int totalTicks) {
  int leftTicks = 0;
  int rightTicks = 0;  
  float leftSen = readLeftSensor();
  float rightSen = readRightSensor();
  bool leftHigh = false;
  bool rightHigh = false;
  while(leftTicks < totalTicks && rightTicks < totalTicks) {
    readSensor(readLeftSensor(), &leftSen, &leftTicks, &leftHigh);
    readSensor(readRightSensor(), &rightSen, &rightTicks, &rightHigh);
  }
  if(leftTicks < rightTicks) {
    stopRight();
    while(leftTicks < rightTicks) {
      readSensor(readLeftSensor(), &leftSen, &leftTicks, &leftHigh);
    }
  }
  if(rightTicks < leftTicks) {
    stopLeft();
    displayCenteredMessage("Loop", "Right");
    while(rightTicks < leftTicks){
      readSensor(readRightSensor(), &rightSen, &rightTicks, &rightHigh);
    }
  }
}

/******************************************************************************
* moveBackward
*   Takes the sensor reading, and sents the sensor states.
*   
* Parameters:
*   float inReading - The sentor value
*   float* inOutOldReading - the last reading
*   float* inOutTicks - the number of transitions to date
*   bool* inOutHigh - whether the delta between the last two readins was positive
*
* Returns:
*   void
*****************************************************************************/
void readSensor(float inReading, float* inOutOldReading, int* inOutTicks, bool* inOutHigh) {    
    if(inReading > *inOutOldReading && !*inOutHigh) {
      *inOutTicks = *inOutTicks + 1;
    }
    *inOutHigh = inReading > *inOutOldReading;
    *inOutOldReading = inReading;
}

/******************************************************************************
* stopMovment
*   Stops the robot.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void stopMovement() {
  displayCenteredMessage("Stopped", "");
  stopBoth();
}

#endif
