#ifndef INTR_MOTOR_V2_H
#define INTR_MOTOR_V2_H
/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 * Course Info: 
 *   SEG 4145
 *   Common Utility
 *
 * intr_motor
 *   This module acts as a hardware interface for the left and right motor. 
 *   They are treated as a single unit for simplicity.
 *
 * Date: 
 *   15 January 2019
 *****************************************************************************/
#include "Arduino.h"
#include "intr_lcd_display.h"
#include <PID_v1.h>

//// Physical Properties
//#define LEFT_MOTOR_PIN         45   // The pin for the left motor
//#define RIGHT_MOTOR_PIN         8   // The pin for the right motor
#define LEFT_SENSOR_PIN        48   // The pin of the left wheel sensor
#define RIGHT_SENSOR_PIN       49   // The pint of the right sensor
//#define MOTOR_LEFT_FORWARD    191.5 // Pulse width required to move the left wheel forward
//#define MOTOR_LEFT_BACKWARD    10.0 // Pulse width required to move the left wheel backward
//#define MOTOR_RIGHT_FORWARD    10.0 // Pulse width required to move the right wheel forward
//#define MOTOR_RIGHT_BACKWARD  191.5 // Pulse width required to move the right wheel backward
//#define MOTOR_ALL_STOP          0.0 // Pulse width required to stop a wheel
//
//// Observed Properties
//#define ROTATION_TIME_LEFT  3000.0  // Time in milliseconds for the robot to make a full rotation CCW
//#define ROTATION_TIME_RIGHT 2500.0  // Time in milliseconds for the robot to make a full rotation CW
//#define SPEED                 30.0  // Speed of robot in cm/s (heavily estimated)

// PID
double kp = 2, ki = 0.3, kd = 0.5;
double lIn, rIn, lOut, rOut, lSet, rSet;
PID lPID = PID(&lIn, &lOut, &lSet, kp, ki, kd, DIRECT);
PID rPID = PID(&rIn, &rOut, &rSet, kp, ki, kd, DIRECT);

/******************************************************************************
* motorSetup
*   Prepares the motors to be used.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void motorSetupV2(){
  pinMode(LEFT_MOTOR_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN, OUTPUT);
  pinMode(LEFT_SENSOR_PIN, INPUT);
  pinMode(RIGHT_SENSOR_PIN, INPUT);
  lPID.SetMode(AUTOMATIC);
  rPID.SetMode(AUTOMATIC);
}


/******************************************************************************
* forward
*   Moves the robot forward.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void forwardV2() {
  analogWrite (LEFT_MOTOR_PIN, MOTOR_LEFT_FORWARD);
  analogWrite (RIGHT_MOTOR_PIN, MOTOR_RIGHT_FORWARD);
  lSet = 315;
  rSet = 315;
  while(true) {
    lIn = analogRead(LEFT_SENSOR_PIN);
    rIn = analogRead(RIGHT_SENSOR_PIN);
    lPID.Compute();
    rPID.Compute();
    analogWrite(LEFT_MOTOR_PIN, lOut);
    analogWrite(RIGHT_MOTOR_PIN, rOut);

    LCD.write(COMMAND_MODE);
    LCD.write(cursorPosition(0, 0));
    LCD.print(lOut);
    delay(LCD_DELAY);
    
    LCD.write(COMMAND_MODE);
    LCD.write(cursorPosition(1, 0));
    LCD.print(rOut);
    delay(LCD_DELAY);
  }
}

/******************************************************************************
* backward
*   Moves the robot backward.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
//void backward() {
//  analogWrite (LEFT_MOTOR_PIN, MOTOR_LEFT_BACKWARD);
//  analogWrite (RIGHT_MOTOR_PIN, MOTOR_RIGHT_BACKWARD);
//}
//
///******************************************************************************
//* rotateLeft
//*   Rotates the robot left.
//*   
//* Parameters:
//*   None
//*
//* Returns:
//*   void
//*****************************************************************************/
//void rotateLeft() {
//  analogWrite (LEFT_MOTOR_PIN, MOTOR_LEFT_BACKWARD);
//  analogWrite (RIGHT_MOTOR_PIN, MOTOR_RIGHT_FORWARD);
//}
//
///******************************************************************************
//* rotateRight
//*   Rotates the robot right.
//*   
//* Parameters:
//*   None
//*
//* Returns:
//*   void
//*****************************************************************************/
//void rotateRight() {
//  analogWrite (LEFT_MOTOR_PIN, MOTOR_LEFT_FORWARD);
//  analogWrite (RIGHT_MOTOR_PIN, MOTOR_RIGHT_BACKWARD);
//}
//
///******************************************************************************
//* stopMotors
//*   Stops both motors.
//*   
//* Parameters:
//*   None
//*
//* Returns:
//*   void
//*****************************************************************************/
//void stopMotors() {
//  analogWrite (LEFT_MOTOR_PIN, MOTOR_ALL_STOP);
//  analogWrite (RIGHT_MOTOR_PIN, MOTOR_ALL_STOP);
//}
//
///******************************************************************************
//* getLeftRotationTime
//*   Calculates the time required to make a given number of rotations CCW.
//*   
//* Parameters:
//*   float rotations - The number of rotations
//*
//* Returns:
//*   The calculated time
//*****************************************************************************/
//float getLeftRotationTime(float rotations) {
//  return ROTATION_TIME_LEFT * rotations;
//}
//
///******************************************************************************
//* getRightRotationTime
//*   Calculates the time required to make a given number of rotations CW.
//*   
//* Parameters:
//*   float rotations - The number of rotations
//*
//* Returns:
//*   The calculated time
//*****************************************************************************/
//float getRightRotationTime(float rotations) {
//  return ROTATION_TIME_RIGHT * rotations;
//}
//
///******************************************************************************
//* getForwardTime
//*   Calculates the time required to move the robot forward a certain distance.
//*   This function is more of a plcae holder. It is not required for lab 1, but
//*   it is part of the interface that would be ideal for these motor.
//*   
//* Parameters:
//*   float distance - The distance in centimeteres
//*
//* Returns:
//*   The calculated time
//*****************************************************************************/
//float getForwardTime(float distance) {
//  return distance/SPEED;
//}
//
///******************************************************************************
//* getBackwardTime
//*   Calculates the time required to move the robot backward a certain distance.
//*   This function is more of a plcae holder. It is not required for lab 1, but
//*   it is part of the interface that would be ideal for these motor.
//*   
//* Parameters:
//*   float distance - The distance in centimeteres
//*
//* Returns:
//*   The calculated time
//*****************************************************************************/
//float getBackwardTime(float distance) {
//  return distance/SPEED;
//}
#endif
