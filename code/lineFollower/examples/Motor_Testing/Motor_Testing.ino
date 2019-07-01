#include "LineFollower.h"

char dirControl; // Variable to store a character

//pins order inside the class parameter: 
//enable1, enable2, leftMotor1, leftMotor2, rightMotor1, rightMotor2, S1, S2, S3, S4, S5
LineFollower lineFollower(10, 11, 8, 9, 12, 13, A10, A11, A12, A13, A14);

void setup() {
  
Serial.begin(9600);
}

void loop() {

  // read the user input from serial monitor and store it in "dirControl"
  dirControl=Serial.read();  

  // run a specific function based on the user input.
  switch(dirControl){
    case 'F' : lineFollower.goForward(255,255); break;
    
    case 'S' : lineFollower.stopCar(); break;
    case 'R' : lineFollower.turnCar(255,0); break;//Turn right
    case 'L' : lineFollower.turnCar(0,255); break;//Turn left
    default : break;    
  } 
  
}
