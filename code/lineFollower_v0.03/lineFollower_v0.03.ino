#include "lineFollower.h"
int minValue=1; //Specific analog or digital value of the sensor 


LineFollower lineFollower(5, 6, 10, 11, A0, A1, A2, A3, A4);

void setup() {
  

}

void loop() {

  // get all sensors' readings.
  lineFollower.activateSensors();

  //Move forward at the beginning of the line. Do we add if 3 reads black condition?
  lineFollower.goForward(255);//go forward with full speed

  //Stop the car if all sensors read black(The end of the line)
  if (lineFollower.valueOfSensor(1) == minValue && lineFollower.valueOfSensor(2) == minValue
      && lineFollower.valueOfSensor(3) == minValue && lineFollower.valueOfSensor(4) == minValue
      && lineFollower.valueOfSensor(5) == minValue) {
    lineFollower.stopCar();
  }

  // detect a Right angle on the Right of the car.
  if (lineFollower.valueOfSensor(1) == minValue && lineFollower.valueOfSensor(2) == minValue
      && lineFollower.valueOfSensor(3) == minValue) {
    lineFollower.rightRA(175);//Turn right with 175 speed
  }

  // detect a Right angle on the Left of the car.
  if (lineFollower.valueOfSensor(5) == minValue && lineFollower.valueOfSensor(4) == minValue
      && lineFollower.valueOfSensor(3) == minValue) {
    lineFollower.leftRA(175);//Turn left with 175 speed
  }

  // Behaviour during curvature to the right. sensor 4 or 5 reads black.
  if (lineFollower.valueOfSensor(3) != minValue  && (lineFollower.valueOfSensor(4) == minValue
      || lineFollower.valueOfSensor(5) == minValue) ) {
    for (int c = 0; lineFollower.valueOfSensor(3) != minValue; c++) {
      lineFollower.turnRight(175);//Turn right with 175 speed
    }
  }

  // Behaviour during curvature to the left. sensor 1 or 2 reads black.
  if (lineFollower.valueOfSensor(3) != minValue  && (lineFollower.valueOfSensor(1) == minValue
      || lineFollower.valueOfSensor(2) == minValue) ) {
    for (int c = 0; lineFollower.valueOfSensor(3) != minValue; c++) {
      lineFollower.turnLeft(175);//Turn left with 175 speed
    }
  }



}