#ifndef PROC_WIFI_COMMANDS_H
#define PROC_WIFI_COMMANDS_H



void setupProcWifiCommands();
void readCommands();

bool PROC_WIFI_COMMANDS_SETUP = false;

void procWifiCommandsSetup() {
  if(!PROC_WIFI_COMMANDS_SETUP) {
     intrMotorSetup();
     contMovementSetup();
     intrTemperatureSetup();
     contMessagesSetup();
     intrProximitySensorSetup();

    PROC_WIFI_COMMANDS_SETUP = true;
  }
}

void readCommands() {
  // if there are incoming bytes available from the peer device, read them and print them:
  bool receivedCommand = false;
  
  while (client.available()) {
    int in;
    char array[25];
  
    int index = 0;
      while(!receivedCommand){
        
        while ((in = client.read()) == -1){}
        
        Serial.println((char)in);
    
        if((char)in == '\n'){
          array[index] = (char)in; 
          receivedCommand=true;
          break;
        }
        else{
          array[index] = (char)in;  
        }
    
        index++;
     } 


  if(receivedCommand){
    Serial.println("Received Command");
    String one = ""; //First part of a command
    String two = ""; //Second part of a command
    String three = ""; //Thir part of a command
    
    int index2 = 0;
    while(array[index2] != ':'){
      one+= array[index2]; 
      index2++; 
    }
  
    Serial.println("one:" + one);
    index2++;
    
    while(array[index2] != ',' && array[index2] != '.'){
      two+= array[index2];
      index2++;
    }
  
    Serial.println("two:" + two);
  
    if(one == "move"){
          index2++;
          while(array[index2] != '.'){
            three+= array[index2];
            index2++;
          }
          Serial.println("three:" + three);
  
          if(two == "forward"){
            Serial.println("Command: Move the robot forward");
            attachLeftMotorServo();
            attachRightMotorServo();
            moveForward(three.toFloat()*50);
            receivedCommand=false;
  
          }
          else if(two = "backward"){
            Serial.println("Command: Move the robot backward");
            attachLeftMotorServo();
            attachRightMotorServo();
            moveBackward(three.toFloat()*50);
            receivedCommand=false;
  
          }
    }
    else if(one == "rotate"){
        index2++;
        while(array[index2] != '.'){
          three+= array[index2];
          index2++;
        }
      
        if(two == "cw"){
          Serial.println("Command: Rotate the robot clockwise");
          attachLeftMotorServo();
          attachRightMotorServo();
          turnRight(three.toFloat()/360);
          receivedCommand=false;
  
        }
        else if(two == "ccw"){
          Serial.println("Command: Rotate the robot counter clockwise");
          attachLeftMotorServo();
          attachRightMotorServo();
          turnLeft(three.toFloat()/360);
          receivedCommand=false;
  
        }
    }
    else if(one == "read"){
        if(two == "temperature"){
          Serial.println("Command: Read temperature values");
          displayTemperature(readTemp());
          client.println(readTemp()); //Your own message
          receivedCommand=false;
  
        }
        else if(two == "distance"){
          Serial.println("Command: Read the distance to the nearest object");
          displayDistance(getDistanceToObstacle());
          receivedCommand=false;
  
        }
    }
    else if(one == "quit"){
        Serial.println("Command Quit");
        stopMovement();
        receivedCommand=false;
  
    }
    else{
        Serial.print("Invalid Operation");
        receivedCommand=false;
  
    }
  
  }
   delay(1);
  } 
}

#endif
