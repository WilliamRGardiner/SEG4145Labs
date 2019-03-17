#ifndef INTR_MOTOR_H
#define INTR_MOTOR_H
/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 *   (8135145) Jessica Zhan
 * Course Info: 
 *   SEG 4145
 *   Common Utility
 *
 * intr_motor
 *   This module acts as a hardware interface for the left and right motor. 
 *   They are treated as a single unit for simplicity.
 *
 * Date: 
 *   04 February 2019
 *****************************************************************************/
#include "Arduino.h"
#include <Servo.h>

// Physical Properties
#define LEFT_MOTOR_PIN         45   // The pin for the left motor
#define RIGHT_MOTOR_PIN         8   // The pin for the right motor
#define MOTOR_LEFT_FORWARD    191.5 // Pulse width required to move the left wheel forward
#define MOTOR_LEFT_BACKWARD   100.0 // Pulse width required to move the left wheel backward
#define MOTOR_RIGHT_FORWARD    80.0 // Pulse width required to move the right wheel forward
#define MOTOR_RIGHT_BACKWARD  191.5 // Pulse width required to move the right wheel backward
#define MOTOR_ALL_STOP          0.0 // Pulse width required to stop a wheel

#define SERVO_MOTOR_LEFT_FORWARD    180 // Pulse width required to move the left wheel forward
#define SERVO_MOTOR_LEFT_BACKWARD   0 // Pulse width required to move the left wheel backward
#define SERVO_MOTOR_RIGHT_FORWARD   0 // Pulse width required to move the right wheel forward
#define SERVO_MOTOR_RIGHT_BACKWARD  180 // Pulse width required to move the right wheel backward

Servo leftMotor;
Servo rightMotor;

// Physical Properties
#define SPEED                4.00 // Speed of robot in rot/s (heavily estimated)
#define WHEEL_DIAMETER       5.5  // Diameter of wheels in cm
#define TICKS_PER_ROTATION  64.0  // Number of High readings for the sensor per rotation

// Signatures
void intrMotorSetup();
void attachLeftMotorServo();
void attachRightMotorServo();
void detachLeftMotorServo();
void detachRightMotorServo();
void leftForward();
void rightForward();
void leftBackward();
void rightBackward();
void stopLeft();
void stopRight();
void stopBoth();

bool INTR_MOTOR_SETUP = false;
/******************************************************************************
* intrMotorSetup
*   Prepares the motors to be used.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void intrMotorSetup(){
  if(!INTR_MOTOR_SETUP) {
    pinMode(LEFT_MOTOR_PIN, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN, OUTPUT);

    //attachLeftMotorServo();
    //attachRightMotorServo();
    
    INTR_MOTOR_SETUP = true;
  }
}

/******************************************************************************
* attachLeftMotorServo
*   attaches the left motor to a servo.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void attachLeftMotorServo() {
  leftMotor.attach(LEFT_MOTOR_PIN);
}

/******************************************************************************
* detachLeftMotorServo
*   detaches the left motor from servo.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void detachLeftMotorServo() {
  leftMotor.detach();
}

/******************************************************************************
* attachRightMotorServo
*   attaches the right motor to a servo.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void attachRightMotorServo() {
  rightMotor.attach(RIGHT_MOTOR_PIN);
}

/******************************************************************************
* detachRightMotorServo
*   detaches the right motor from servo.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void detachRightMotorServo() {
  rightMotor.detach();
}

/******************************************************************************
* forward
*   Moves the left motor forward.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void leftForward() {
  leftMotor.write(SERVO_MOTOR_LEFT_FORWARD);
  //analogWrite (LEFT_MOTOR_PIN, MOTOR_LEFT_FORWARD);
}

/******************************************************************************
* forward
*   Moves the right motor forward.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void rightForward() {
  rightMotor.write(SERVO_MOTOR_RIGHT_FORWARD);
  //analogWrite (RIGHT_MOTOR_PIN, MOTOR_RIGHT_FORWARD);
}

/******************************************************************************
* backward
*   Moves the left motor backward.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void leftBackward() {
  leftMotor.write(SERVO_MOTOR_LEFT_BACKWARD);
  //analogWrite (LEFT_MOTOR_PIN, MOTOR_LEFT_BACKWARD);
}

/******************************************************************************
* backward
*   Moves the right motor backward.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void rightBackward() {
  rightMotor.write(SERVO_MOTOR_RIGHT_BACKWARD);
  //analogWrite (RIGHT_MOTOR_PIN, MOTOR_RIGHT_BACKWARD);
}

/******************************************************************************
* stopMotors
*   Stops the left motor.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void stopLeft() {
 leftMotor.detach();
 // analogWrite (LEFT_MOTOR_PIN, MOTOR_ALL_STOP);
}

/******************************************************************************
* stopMotors
*   Stops the right motor.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void stopRight() {
   rightMotor.detach();
 // analogWrite (RIGHT_MOTOR_PIN, MOTOR_ALL_STOP);
}

/******************************************************************************
* stopMotors
*   Stops both motors.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void stopBoth() {
  stopLeft();
  stopRight();
}

#endif
