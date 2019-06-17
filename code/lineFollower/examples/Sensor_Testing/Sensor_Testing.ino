#include "LineFollower.h"

//////// NOT WORKING RIGHT NOW ////////////


//pins order inside the class parameter: 
//enable1, enable2, leftMotor1, leftMotor2, rightMotor1, rightMotor2, S1, S2, S3, S4, S5
LineFollower lineFollower(0, 1, 5, 6, 10, 11, A0, A1, A2, A3, A4);


void setup() {

    Serial.begin(9600);
}

void loop() {

// Edit this line. 1st argument: number of sensors 1 or 5. 2nd argument: 'D' for Digital , 'A' for Analog 
lineFollower.testSensors(5 , 'D'); 
  
}
