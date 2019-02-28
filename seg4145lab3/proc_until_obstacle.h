#ifndef PROC_UNTIL_OBSTACLE_H
#define PROC_UNTIL_OBSTACLE_H

#include "intr_motor.h"
#include "intr_proximity_sensor.h"


void setupProcUntilObst();
void moveForwardUntilObstacle();

bool PROC_UNTIL_OBSTACLE_SETUP = false;

void procUntilObstacleSetup() {
  if(!PROC_UNTIL_OBSTACLE_SETUP) {
    intrMotorSetup();
    intrProximitySensorSetup();
    PROC_UNTIL_OBSTACLE_SETUP = true;
  }
}

void moveForwardUntilObstacle(float minDist) {
  attachLeftMotorServo();
  attachRightMotorServo();
  displayCenteredMessage("Moving", "Forward");
  leftForward();
  rightForward();
  while(getDistanceToObstacle() > minDist) {
    delay(50);
  }
  stopBoth();
}

#endif
