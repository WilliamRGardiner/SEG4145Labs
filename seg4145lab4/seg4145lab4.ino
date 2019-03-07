/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 *   (8135145) Jessica Zhan
 * Course Info: 
 *   SEG 4145
 *   Lab 3
 *
 * seg4145lab3
 *   The main file for Lab 3. Contains the setup and the loop.
 *
 * Date: 
 *    February 11 2019
 *****************************************************************************/
#include <string.h>
#include <unistd.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <Wirefree.h>
#include <WifiClient.h>

#include "proc_startup_message.h"
#include "proc_until_obstacle.h"
#include "proc_obstacle_avoidance.h"
#include "intr_temperature.h"
#include "cont_movement.h"


// Global Variables
SoftwareSerial LCD = SoftwareSerial(0, LCD_PIN); // The LCD display.
Servo sensorServo;

WIFI_PROFILE wireless_prof = {
 /* SSID */ "stingray",
 /* WPA/WPA2 passphrase */ "12345678",
 /* Robot IP address */ "192.168.1.110",
 /* subnet mask */ "255.255.255.0",
 /* Gateway IP */ "192.168.1.1", };
 
String remote_server = "192.168.1.145"; // peer device IP address.

String remote_port = "9876"; // arbitrary 

//Creates a client that can connect to a specified internet IP address and port number
WifiClient client(remote_server, remote_port, PROTO_UDP);

/******************************************************************************
* setup
*   Performs the required setup before the loop is called.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void setup() { //stingray



 Serial.begin(9600);

  intrMotorSetup();
  contMovementSetup();
  intrTemperatureSetup();
  contMessagesSetup();

 
  // Startup Messge
  procStartupMessageSetup();
  displayStartupMessage();
  
  sensorServo.attach(7);
  sensorServo.write(70);
  delay(1000);
  sensorServo.detach();

  Serial.println("Starting Wifi...");
  // connect to AP
  Wireless.begin(&wireless_prof);
  Serial.println("Wifi Connected");
  
 //Serial.println("client.connect() = "+ client.connect());

  // if you get a connection, report back via serial. client.connect() connect to the IP address and port specified earlier. It returns true if the connection succeeds, false if not.
  if (client.connect()) {
    Serial.println("connected"); // prints to serial monitor. Check the Serial Monitor Section at the end of  this manual.
    // Send message over UDP socket to peer device
    client.println("Robot10"); //Your own message
  }
  else {
    // if connection setup failed:
    Serial.println("failed");
  } 

}

/******************************************************************************
* loop
*   Runs the lab excercise.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void loop() {
// if there are incoming bytes available from the peer device, read them and print them:
  bool receivedCommand = false;
 while (client.available()) {
  int in;
  char array[25];
  
 

  int index = 0;
  while ((in = client.read()) == -1){
    Serial.println((char)in);
    
    if((char)in == '.'){
      receivedCommand=true;
      break;
    }
    else{
    array[index] = (char)in;  
    }
    
    index++;
  }  

  
if(receivedCommand){
  String one = "";
  String two = "";
  String three = "";
  
  int index2 = 0;
  while(array[index2] != ":"){
    one+= array[index2];
    index2++;
  }
  
  while(array[index2] != ":" ||array[index2] != "."){
    two+= array[index2];
    index2++;
  }

  if(one == "move"){
        while(array[index2] != "."){
          three+= array[index2];
          index2++;
        }
        
        if(two == "forward"){
          Serial.print("Move the robot forward");
          attachLeftMotorServo();
          attachRightMotorServo();
          moveForward(three.toFloat());
        }
        else if(two = "backward"){
          Serial.print("Move the robot backward");
          attachLeftMotorServo();
          attachRightMotorServo();
          moveBackward(three.toFloat());
        }
  }
  else if(one == "rotate"){
      while(array[index2] != "."){
        three+= array[index2];
        index2++;
      }
    
      if(two == "cw"){
        Serial.print("Rotate the robot clockwise");
        attachLeftMotorServo();
        attachRightMotorServo();
        turnRight(three.toFloat());
      }
      else if(two == "ccw"){
        Serial.print("Rotate the robot counter clockwise");
        attachLeftMotorServo();
        attachRightMotorServo();
        turnLeft(three.toFloat());
      }
  }
  else if(one == "read"){
      if(two == "temperature"){
        Serial.print("6 - Read temperature values");
        displayTemperature(readTemp());
      }
      else if(two == "distance"){
        Serial.print("Read the distance to the nearest object");
      }
  }
  else if(one == "quit"){
      Serial.print("Quit");
      stopMovement();
  }
  else{
      Serial.print("Invalid Operation");
  }

}
 delay(1);
}
}
