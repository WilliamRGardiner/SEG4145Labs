#ifndef PROC_OBSTACLE_AVOIDANCE_H
#define PROC_OBSTACLE_AVOIDANCE_H

#include "intr_motor.h"
#include "cont_movement.h"
#include "intr_temperature.h"
#include "cont_messages.h"

#define TILE        1500 // The time to travel 1 tile.
#define QUATER_TURN    0.25

void procObstacleAvoidanceSetup();
void moveForwardUntilObstacle();
void displayTemperature(float temperature);

bool PROC_OBSTACLE_AVOIDANCE_SETUP = false;

void procObstacleAvoidanceSetup() {
  if(!PROC_OBSTACLE_AVOIDANCE_SETUP) {
    intrMotorSetup();
    contMovementSetup();
    intrTemperatureSetup();
    contMessagesSetup();
    PROC_OBSTACLE_AVOIDANCE_SETUP = true;
  }
}

void obstacleAvoidanceProcedure() {
  stopBoth();
  displayTemperature(readTemp());
  delay(5000);
 
  attachLeftMotorServo();
  attachRightMotorServo();
  moveBackward(TILE);
  
  attachLeftMotorServo();
  attachRightMotorServo();
  turnRight(QUATER_TURN);
  
  attachLeftMotorServo();
  attachRightMotorServo();
  moveForward(TILE*2);
  
  attachLeftMotorServo();
  attachRightMotorServo();
  turnLeft(QUATER_TURN);
  
}

void displayTemperature(float temperature) {
  char buff[10];
  dtostrf(temperature, 4, 2, buff);
  displayMessage("Temperature", buff, 5);
}

#endif
