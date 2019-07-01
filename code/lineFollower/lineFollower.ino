
#include "LineFollower.h"
#include "StarWars.h"


//pins order inside the class parameter:
//enable1, enable2, leftMotor1, leftMotor2, rightMotor1, rightMotor2, S1, S2, S3, S4, S5
StarWars starWars;
LineFollower lineFollower(10, 11, 8, 9, 12, 13, A10, A11, A12, A13, A14);



// SENSOR variables to store Sensors' readings ordered from left to right
int sensor1 , sensor2 , sensor3 , sensor4, sensor5  ;


int turnCondition = 0;


void updateSensors() {
  sensor1 = digitalRead(A10);
  sensor2 = digitalRead(A11);
  sensor3 = digitalRead(A12);
  sensor4 = digitalRead(A13);
  sensor5 = digitalRead(A13);

}



void setup() {


}



void loop() {

  buttonState = digitalRead(myButton);

  if (buttonState == HIGH) {
    updateSensors();

    // Move forward in case the middle sensor only reads black.
    if (sensor1 == whiteValue && sensor2 == whiteValue && sensor3 == blackValue && sensor4 == whiteValue && sensor5 == whiteValue ) {
      turnCondition = 0;
      lineFollower.goForward(200, 200);
    }
    // Turn Right
    else if ( ( sensor1 == whiteValue || sensor2 == whiteValue) && sensor3 == whiteValue
              && ( sensor4 == blackValue || sensor5 == blackValue) ) {
      turnCondition = 1;
      lineFollower.turnCar(200, 0);

    }

    // Turn Left
    else if ( ( sensor1 == blackValue || sensor2 == blackValue) && sensor3 == whiteValue
              && ( sensor4 == whiteValue || sensor5 == whiteValue) ) {
      turnCondition = 2;
      lineFollower.turnCar(0, 200);

    }

    /////////////////////////////////////////////
    // Stop car if all sensors read white or black
    else if ( (sensor1 == whiteValue && sensor2 == whiteValue && sensor3 == whiteValue && sensor4 == whiteValue && sensor5 == whiteValue ) ||
              (sensor1 == blackValue && sensor2 == blackValue && sensor3 == blackValue && sensor4 == blackValue && sensor5 == blackValue )   ) {


      for (int i = 0; i < 350; i++) {
        delay(1);
        updateSensors();
        if ( (sensor1 == blackValue  || sensor2 == blackValue  || sensor3 == blackValue  || sensor4 == blackValue || sensor5 == blackValue  ) ) {
          break;
        }
      }


      if ( (sensor1 == whiteValue && sensor2 == whiteValue && sensor3 == whiteValue && sensor4 == whiteValue && sensor5 == whiteValue ) ||
           (sensor1 == blackValue && sensor2 == blackValue && sensor3 == blackValue && sensor4 == blackValue && sensor5 == blackValue )   ) {
        if (turnCondition == 0) {
          lineFollower.stopCar();
          starWars.StarWarsTheme();
        }
        else {
          while (sensor3 == whiteValue) {
            updateSensors();
            delay(1);
            if (turnCondition == 1) {
              lineFollower.turnCar(200, 0);
            }
            else {
              lineFollower.turnCar(0, 200);
            }
          }
        }
      }


    }
    /////////////////////////////////////////////////////////////////

  }
  // else If button is not pressed, Everything is off
  else {
    lineFollower.stopCar();
  }


}
