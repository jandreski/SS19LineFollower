
#include "LineFollower.h"


LineFollower lineFollower(0, 1, 5, 6, 10, 11, A0, A1, A2, A3, A4);//en1 , en2, M1.1 , M1.2 , M2.1 , M2.2 , S1, S2, S3, S4, S5

void setup() {


}

void loop() {

  // get all sensors' readings.

  lineFollower.goForward(200);
  lineFollower.storeSensorValues();
  lineFollower.determineDirection();
  

  /*
  lineFollower.storeSensorValues();



 lineFollower.goForward(255);

 if (lineFollower.valueOfSensor(1) == whiteValue && lineFollower.valueOfSensor(2) == whiteValue
      && lineFollower.valueOfSensor(3) == whiteValue && lineFollower.valueOfSensor(4) == whiteValue
      && lineFollower.valueOfSensor(5) == whiteValue) {
    lineFollower.stopCar();
    */
  }











  /*Move forward at the beginning of the line.
  //if (lineFollower.valueOfSensor(3) == blackValue){
    lineFollower.goBackward(100);//go forward with 100/255 speed
  //}


  //Stop the car if all sensors read black(The end of the line)
  if (lineFollower.valueOfSensor(1) == blackValue && lineFollower.valueOfSensor(2) == blackValue
      && lineFollower.valueOfSensor(3) == blackValue && lineFollower.valueOfSensor(4) == blackValue
      && lineFollower.valueOfSensor(5) == blackValue) {
    lineFollower.stopCar();
  }

  // detect a Right angle on the Right of the car.
  if (lineFollower.valueOfSensor(1) == blackValue && lineFollower.valueOfSensor(2) == blackValue
      && lineFollower.valueOfSensor(3) == blackValue) {
    lineFollower.rightRA(75);//Turn right with 75/255 speed
  }

  // detect a Right angle on the Left of the car.
  if (lineFollower.valueOfSensor(5) == blackValue && lineFollower.valueOfSensor(4) == blackValue
      && lineFollower.valueOfSensor(3) == blackValue) {
    lineFollower.leftRA(75);//Turn left with 75/255 speed
  }

  // Behaviour during curvature to the right. sensor 4 or 5 reads black.
  if (lineFollower.valueOfSensor(3) != blackValue  && (lineFollower.valueOfSensor(4) == blackValue
      || lineFollower.valueOfSensor(5) == blackValue) ) {
    for (int c = 0; lineFollower.valueOfSensor(3) != blackValue; c++) {
      lineFollower.turnRight(75);//Turn right with 75/255 speed
    }
  }

  // Behaviour during curvature to the left. sensor 1 or 2 reads black.
  if (lineFollower.valueOfSensor(3) != blackValue  && (lineFollower.valueOfSensor(1) == blackValue
      || lineFollower.valueOfSensor(2) == blackValue) ) {
    for (int c = 0; lineFollower.valueOfSensor(3) != blackValue; c++) {
      lineFollower.turnLeft(75);//Turn left with 75/255 speed
    }
  }

*/
