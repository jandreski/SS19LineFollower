#include "LineFollower.h"

char dirControl; // Variable to store a ch
LineFollower lineFollower(0 , 15, 6, 10, 11, A0, A1, A2, A3, A4);//M1.1 , M1.2 , M2.1 , M2.2 , S1, S2, S3, S4, S5 

void setup() {
  

}

void loop() {

  // read the user input from serial monitor and store it in "dirControl"
  dirControl=Serial.read();  

  // run a specific function based on the user input.
  switch(dirControl){
    case 'F' : lineFollower.goForward(255); break;
    case 'B' : lineFollower.goBackward(255); break;
    case 'S' : lineFollower.stopCar(); break;
    case 'R' : lineFollower.turnRight(255); break;
    case 'L' : lineFollower.turnLeft(255); break;
    default : break;    
  } 
  
}
