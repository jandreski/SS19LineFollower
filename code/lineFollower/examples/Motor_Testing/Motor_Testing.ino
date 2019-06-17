#include "LineFollower.h"

char dirControl; // Variable to store a character

//pins order inside the class parameter: 
//enable1, enable2, leftMotor1, leftMotor2, rightMotor1, rightMotor2, S1, S2, S3, S4, S5
LineFollower lineFollower(0, 1, 5, 6, 10, 11, A0, A1, A2, A3, A4);

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
    case 'R' : lineFollower.turnCar(255,0); break;//Turn right
    case 'L' : lineFollower.turnCar(0,255); break;//Turn left
    default : break;    
  } 
  
}
