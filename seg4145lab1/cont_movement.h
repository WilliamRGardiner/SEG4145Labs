#ifndef CONT_MOVEMENT_H
#define CONT_MOVEMENT_H
/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 * Course Info: 
 *   SEG 4145
 *   Common Utility
 *
 * cont_movement
 *   This module acts as acontroller for the movement of the robot.
 *
 * Date: 
 *   15 January 2019
 *****************************************************************************/
#include "intr_lcd_display.h"
#include "intr_motor.h"

// Footprints
void turnLeft(float rotations);
void turnRight(float rotations);
void moveForwardTime(float duration);
void moveBackwardTime(float duration);
void stopMovement();
 
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
  rotateLeft();
  delay(getLeftRotationTime(rotations));
  stopMovement();
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
  rotateRight();
  delay(getRightRotationTime(rotations));
  stopMovement();
}

/******************************************************************************
* moveForwardTime
*   Move the robot forward for a given duration.
*   
* Parameters:
*   float duration - The duration of the movement in milliseconds
*
* Returns:
*   void
*****************************************************************************/
void moveForwardTime(float duration) {
  displayCenteredMessage("Moving", "Forward");
  forward();
  delay(duration);
  stopMovement();
}

/******************************************************************************
* moveBackwardTime
*   Move the robot backward for a given duration.
*   
* Parameters:
*   float duration - The duration of the movement in milliseconds
*
* Returns:
*   void
*****************************************************************************/
void moveBackwardTime(float duration) {
  displayCenteredMessage("Moving", "Backward");
  backward();
  delay(duration);
  stopMovement();
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
  stopMotors();
}

#endif
