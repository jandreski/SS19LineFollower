
#include "LineFollower.h"


int blackValue=1; //Specific analog or digital value of the sensor at which the sensor reads black.
LineFollower lineFollower(5, 6, 10, 11, A0, A1, A2, A3, A4);//M1.1 , M1.2 , M2.1 , M2.2 , S1, S2, S3, S4, S5 

void setup() {
  

}

void loop() {

  // get all sensors' readings.
  lineFollower.activateSensors();

  //Move forward at the beginning of the line. Do we add if 3 reads black condition?
  lineFollower.goForward(255);//go forward with full speed

  //Stop the car if all sensors read black(The end of the line)
  if (lineFollower.valueOfSensor(1) == blackValue && lineFollower.valueOfSensor(2) == blackValue
      && lineFollower.valueOfSensor(3) == blackValue && lineFollower.valueOfSensor(4) == blackValue
      && lineFollower.valueOfSensor(5) == blackValue) {
    lineFollower.stopCar();
  }

  // detect a Right angle on the Right of the car.
  if (lineFollower.valueOfSensor(1) == blackValue && lineFollower.valueOfSensor(2) == blackValue
      && lineFollower.valueOfSensor(3) == blackValue) {
    lineFollower.rightRA(175);//Turn right with 175 speed
  }

  // detect a Right angle on the Left of the car.
  if (lineFollower.valueOfSensor(5) == blackValue && lineFollower.valueOfSensor(4) == blackValue
      && lineFollower.valueOfSensor(3) == blackValue) {
    lineFollower.leftRA(175);//Turn left with 175 speed
  }

  // Behaviour during curvature to the right. sensor 4 or 5 reads black.
  if (lineFollower.valueOfSensor(3) != blackValue  && (lineFollower.valueOfSensor(4) == blackValue
      || lineFollower.valueOfSensor(5) == blackValue) ) {
    for (int c = 0; lineFollower.valueOfSensor(3) != blackValue; c++) {
      lineFollower.turnRight(175);//Turn right with 175 speed
    }
  }

  // Behaviour during curvature to the left. sensor 1 or 2 reads black.
  if (lineFollower.valueOfSensor(3) != blackValue  && (lineFollower.valueOfSensor(1) == blackValue
      || lineFollower.valueOfSensor(2) == blackValue) ) {
    for (int c = 0; lineFollower.valueOfSensor(3) != blackValue; c++) {
      lineFollower.turnLeft(175);//Turn left with 175 speed
    }
  }



}
