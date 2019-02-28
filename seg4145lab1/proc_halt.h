/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 * Course Info: 
 *   SEG 4145
 *   Lab 1
 *
 * proc_halt
 *   This module defines a procedure for halting the execution of the loop
 *   function: make it wait forever.
 *
 * Date: 
 *   15 January 2019
 *****************************************************************************/
/******************************************************************************
* loop
*   Forces the robot to wait for the rest of its life, or until we shut it off, 
*   whichever comes first.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void halt(){
  while(true){
    delay(10000);
  }
}
