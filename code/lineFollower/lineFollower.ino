
#include "LineFollower.h"

//pins order inside the class parameter:
//enable1, enable2, leftMotor1, leftMotor2, rightMotor1, rightMotor2, S1, S2, S3, S4, S5
LineFollower lineFollower(0, 1, 5, 6, 10, 11, A0, A1, A2, A3, A4);


// SENSOR variables to store Sensors' readings ordered from left to right
int sensor1 , sensor2 , sensor3 , sensor4 , sensor5 ;

void setup() {


}

void loop() {

  sensor1 = digitalRead(A0);
  sensor2 = digitalRead(A1);
  sensor3 = digitalRead(A2);
  sensor4 = digitalRead(A3);
  sensor5 = digitalRead(A4);

// Move forward in case the middle sensor only reads black.
  if (sensor1 == whiteValue && sensor2 == whiteValue && sensor3 == blackValue && sensor4 == whiteValue && sensor5 == whiteValue) {
    lineFollower.goForward(255);
  }
// Turn left if the car is drifted to the right
  else if ( ( sensor1 == whiteValue || sensor2 == whiteValue) && sensor3 == whiteValue 
         && ( sensor4 == blackValue || sensor5 == blackValue) ) {
    lineFollower.turnCar(0, 255);
  }

// Turn Right if the car is drifted to the left
  else if ( ( sensor1 == blackValue || sensor2 == blackValue) && sensor3 == whiteValue
         && ( sensor4 == whiteValue || sensor5 == whiteValue) ) {
    lineFollower.turnCar(255, 0);
  }
















  /*

    delay(2500);
    // get all sensors' readings.
    lineFollower.getSensorsData();

    // Move forward in case the middle sensor only reads black.
    if (lineFollower.valueOfSensor(3) == blackValue
        && lineFollower.valueOfSensor(1) == whiteValue && lineFollower.valueOfSensor(2) == whiteValue
        && lineFollower.valueOfSensor(4) == whiteValue && lineFollower.valueOfSensor(5) == whiteValue ) {

      lineFollower.goForward(150);
    }


    // Right Angle behaviour

    // right Angle to the left of the car
    else if (lineFollower.valueOfSensor(3) == blackValue
        && lineFollower.valueOfSensor(1) == blackValue && lineFollower.valueOfSensor(2) == blackValue) {



      for(int i=0; (lineFollower.valueOfSensor(3) == blackValue); i++){
        lineFollower.turnCar(0, 150); //Turn left
      }
    }

    // right Angle to the right of the car
    else if (lineFollower.valueOfSensor(3) == blackValue && lineFollower.valueOfSensor(4) == blackValue
        && lineFollower.valueOfSensor(5) == blackValue) {



       for(int i=0; (lineFollower.valueOfSensor(3) == blackValue); i++){
         lineFollower.turnCar(150, 0); //Turn right
      }
    }


    // Curve behaviour

    // Do this in case middle sensor doesn't read black anymore.
    else if (lineFollower.valueOfSensor(3) == whiteValue) {

    // in case any of the sensors on the left side of the car reads black >>> //Turn right
       if (lineFollower.valueOfSensor(1) == blackValue || lineFollower.valueOfSensor(2) == blackValue ) {
        lineFollower.turnCar(200, 100); //Turn right
      }

    // in case any of the sensors on the right side of the car reads black >>> //Turn left
      else if (lineFollower.valueOfSensor(4) == blackValue || lineFollower.valueOfSensor(5) == blackValue ) {
        lineFollower.turnCar(100, 200); //Turn left
      }
    }


    // End of the line
    else if (lineFollower.valueOfSensor(1) == whiteValue && lineFollower.valueOfSensor(2) == whiteValue
         && lineFollower.valueOfSensor(3) == whiteValue && lineFollower.valueOfSensor(4) == whiteValue
         && lineFollower.valueOfSensor(5) == whiteValue) {

      lineFollower.stopCar(); //Stop
    }

  */
}
