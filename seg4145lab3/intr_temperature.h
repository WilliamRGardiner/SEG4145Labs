#ifndef INTR_TEMPERATURE_H
#define INTR_TEMPERATURE_H

#include <Wire.h>
#define TEMPSENSOR 0x68 //Address

int reg = 0x01; // This register value determines if the
 // ambient temperature will be read or one
 // of the other eight temperature values
 // Ambient temperature = 0x01
 // 8 arrays values = 0x02 to 0x09
 
void intrTemperatureSetup() {
 Wire.begin(); // Join I2C bus
}

float readTemp() {
  Wire.beginTransmission(TEMPSENSOR);
  Wire.write(reg); // Indicate temperature value to read
  Wire.endTransmission();
  Wire.requestFrom(TEMPSENSOR, 1); // Request data
  while(Wire.available() < 1); // Wait for data
  return (float) Wire.read(); // Temp. value
}

#endif
