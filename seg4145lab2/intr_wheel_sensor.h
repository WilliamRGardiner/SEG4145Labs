#ifndef INTR_WHEEL_SENSOR_H
#define INTR_WHEEL_SENSOR_H
/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 *   (8135145) Jessica Zhan
 * Course Info: 
 *   SEG 4145
 *   Common Utility
 *
 * intr_wheel_sensor
 *   This module acts as a hardware interface for the left and right motor sensors. 
 *   They are treated as a single unit for simplicity.
 *
 * Date: 
 *   04 February 2019
 *****************************************************************************/
#define LEFT_WHEEL_SENSOR_PIN     48   // The pin for the left motor
#define RIGHT_WHEEL_SENSOR_PIN    49   // The pin for the right motor
#define SENSOR_PERIOD           2000.0 // Duration over which a tick reading is summed
#define SENSOR_THRESHOLD         315.0

// Signatures
void intrWheelSensorSetup();
float readLeftSensor();
float readRightSensor();

bool INTR_WHEEL_SENSOR_SETUP = false;
/******************************************************************************
* intrWheelSensorSetup
*   Prepares the sensors to be used.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void intrWheelSensorSetup() {
  if(!INTR_WHEEL_SENSOR_SETUP) {
    pinMode(LEFT_WHEEL_SENSOR_PIN, INPUT);
    pinMode(RIGHT_WHEEL_SENSOR_PIN, INPUT);
    INTR_WHEEL_SENSOR_SETUP = true;
  }
}

/******************************************************************************
* readLeftSensor
*   Reads the left wheel sensor.
*   
* Parameters:
*   None
*
* Returns:
*   the value returned by the left wheel sensor
*****************************************************************************/
float readLeftSensor() {
  return digitalRead(LEFT_WHEEL_SENSOR_PIN);
}

/******************************************************************************
* readRightSensor
*   Reads the right wheel sensor.
*   
* Parameters:
*   None
*
* Returns:
*   the value returned by the right wheel sensor
*****************************************************************************/
float readRightSensor() {
  return digitalRead(RIGHT_WHEEL_SENSOR_PIN);
}

#endif
