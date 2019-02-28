/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 *   (8135145) Jessica Zhan
 * Course Info: 
 *   SEG 4145
 *   Lab 2
 *
 * proc_follow_path
 *   This module defines a procedure for following preprogrammed paths.
 *
 * Date: 
 *   15 January 2019
 *****************************************************************************/
#ifndef PROC_FOLLOW_PATH_H
#define PROC_FOLLOW_PATH_H
#include "cont_movement.h"
#include "intr_lcd_display.h"

#define PATH_MESSAGE_DISPLAY_TIME 5000   // The time that the robot takes to display messages
#define TILE                        30.5 // The width of a tile in cm

/******************************************************************************
* ENUM - ActionDirection
*   Represents the action taken durning an instruction.
*****************************************************************************/
typedef enum {FORWARD, BACKWARD, LEFT, RIGHT, WAIT, END} ActionDirection;

/******************************************************************************
* STRUCT - PathInstruction
*   Collects and action and a scale of that action into one type.
*****************************************************************************/
typedef struct {
  ActionDirection action;
  float scale; 
} PathInstruction;

void procFollowPathSetup();
void runPath(bool returnToStart);
int runPathForward(PathInstruction path[]);
void runPathReverse(PathInstruction path[], int indexOfLastInstruction);
void executeInstruction(PathInstruction instruction);
PathInstruction getReverseInstruction(PathInstruction instruction);

// The path in Lab 2
PathInstruction PATH[] = {
  {FORWARD, 2 * TILE}, {RIGHT, 1.0/4}, 
  {FORWARD, 2 * TILE}, {RIGHT, 1.0/4}, 
  {FORWARD, 3 * TILE}, {RIGHT, 1.0/4}, 
  {FORWARD, 3 * TILE}, {RIGHT, 1.0/4},
  {FORWARD, 2 * TILE}, {LEFT, 1.0/8},
  {FORWARD, 1 * sqrt(2) * TILE}, {LEFT, 3.0/8},
  {FORWARD, 4 * TILE}, {LEFT, 1.0/4},
  {FORWARD, 2 * TILE}, {LEFT, 1.0/4},
  {FORWARD, 2 * TILE}, {END}};

/******************************************************************************
* procFollowPathSetup
*   Sets up the follow path precedure.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void procFollowPathSetup() {
  contMovementSetup();
  intrLcdDisplaySetup();
}

/******************************************************************************
* runPath1
*   Runs path 1 described in the lab manual for Lab 1.
*   
* Parameters:
*   bool returnToStart - If True, the robot will execute the path backwards 
*                        after its forward pass.
*
* Returns:
*   void
*****************************************************************************/
void runPath(bool returnToStart) {
  displayCenteredMessage("Running", "Path");
  delay(5000);
  int index = runPathForward(PATH);
  if(returnToStart) {
    displayCenteredMessage("Reversing", "Path");
    delay(5000);
    runPathReverse(PATH, index);
  }
}

/******************************************************************************
* runPath
*   Runs given path.
*   
* Parameters:
*  PathInstruction path[] - An array of path instructions to follow
*
* Returns:
*   int - The index of the last instruction
*****************************************************************************/
int runPathForward(PathInstruction path[]) {
  int index = 0;
  while(true) {
    PathInstruction instruction = path[index];
    if(instruction.action == END) {
      return index;
    }
    executeInstruction(instruction);
    index = index + 1;
  }
}

/******************************************************************************
* runPathReverse
*   Runs given path in reverse.
*   
* Parameters:
*  PathInstruction path[]     - An array of path instructions to follow
*  int indexOfLastInstruction - The index of the last path instruction
*
* Returns:
*   void
*****************************************************************************/
void runPathReverse(PathInstruction path[], int indexOfLastInstruction) {
  int index = indexOfLastInstruction - 1;
  for(int index = indexOfLastInstruction - 1; index >= 0; index--) {
    PathInstruction instruction = path[index];
    executeInstruction(getReverseInstruction(instruction));
  }
}

/******************************************************************************
* executeInstruction
*   Executes a single path instruction.
*   
* Parameters:
*  PathInstruction instruction - The instruction to execute
*  
* Returns:
*   void
*****************************************************************************/
void executeInstruction(PathInstruction instruction) {
  switch(instruction.action) {
    case FORWARD:
      moveForward(instruction.scale);
      break;
    case BACKWARD:
      moveBackward(instruction.scale);
      break;
    case LEFT:
      turnLeft(instruction.scale);
      break;
    case RIGHT:
      turnRight(instruction.scale);
      break;
    case WAIT:
      stopMovement();
      delay(instruction.scale);
      break;
    case END:
      stopMovement();
      break;
    default:
      stopMovement();
      displayCenteredMessage("Error", "Bad Path");
      delay(120000);
      break;
  }
}

/******************************************************************************
* getReverseInstruction
*   Returns the reverse of an instruction.
*   
* Parameters:
*  PathInstruction instruction - The instruction to reverse
*  
* Returns:
*   PathInstruction - The reversed instruction
*****************************************************************************/
PathInstruction getReverseInstruction(PathInstruction instruction) {
  switch(instruction.action) {
    case FORWARD:
      return {BACKWARD, instruction.scale};
    case BACKWARD:
      return {FORWARD, instruction.scale};
    case LEFT:
      return {RIGHT, instruction.scale};
    case RIGHT:
      return {LEFT, instruction.scale};
    default:
      return instruction;
  }
}
#endif
