#include "LineFollower.h"


LineFollower lineFollower(5, 6, 10, 11, A0, A1, A2, A3, A4);//M1.1 , M1.2 , M2.1 , M2.2 , S1, S2, S3, S4, S5 

void setup() {
  

}

void loop() {

// Edit this line. 1st argument: number of sensors 1 or 5. 2nd argument: 'D' for Digital , 'A' for Analog 
lineFollower.testSensors(1 , 'D'); 
  
}
