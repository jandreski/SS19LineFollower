#include "LineFollower.h"
#include "Arduino.h"
//#include <iostream>

using namespace std;


// constructor....
LineFollower::LineFollower(int _enable1, int _enable2, int _motor1a, int _motor1b, int _motor2a, int _motor2b,
                           int _sensor1, int _sensor2, int _sensor3, int _sensor4, int _sensor5){
  // store the motor pins arguments inside the variables
  motor1a = _motor1a;
  motor1b = _motor1b;
  motor2a = _motor2a;
  motor2b = _motor2b;

  // set/initialise Motor pins as OUTPUT
  pinMode(motor1a, OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);

  // set/initialise Sensor pins as INPUT
  pinMode(_sensor1, INPUT);
  pinMode(_sensor2, INPUT);
  pinMode(_sensor3, INPUT);
  pinMode(_sensor4, INPUT);
  pinMode(_sensor5, INPUT);

  //Enable Motor driver channels
  enable1 = _enable1; // store the enable pins arguments inside the variables
  enable2 = _enable2; // store the enable pins arguments inside the variables
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  digitalWrite(enable1, HIGH); // activates motor driver
  digitalWrite(enable2, HIGH); // activates motor driver


  // to visualise sensor data from computer's monitor
  Serial.begin(9600);

  //logFile.open("log.txt");
  //logFile << "Log file:\n";
}

void LineFollower::determineDirection(){
  // put all the line following logic here

  if(valueOfSensor(4) == whiteValue && valueOfSensor(5) == whiteValue){
    //first half of the code (1,2,3)
    if(valueOfSensor(1) == blackValue && valueOfSensor(2) == whiteValue && valueOfSensor(3) == whiteValue){
      turnLeft(80,255);   // TEST VALUES!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    else if(valueOfSensor(1) == whiteValue && valueOfSensor(2) == blackValue && valueOfSensor(3) == whiteValue){
      turnLeft(80,200);   // TEST VALUES!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    else if(valueOfSensor(1) == whiteValue && valueOfSensor(2) == whiteValue && valueOfSensor(3) == blackValue){
      goForward(200);
    } 
    else if(valueOfSensor(1) == whiteValue && valueOfSensor(2) == whiteValue && valueOfSensor(3) == whiteValue){
      delay(2000);
      stopCar();
    }
    delay(100);
  }
  else if((valueOfSensor(1) == blackValue) && (valueOfSensor(2) == blackValue) && (valueOfSensor(2) == blackValue) && (valueOfSensor(4) == blackValue) && (valueOfSensor(5) == blackValue)){
    stopCar();
  }
  else {
    //second half of the code (3,4,5)
    //stopCar();
  }


  /*
  if (valueOfSensor(3) == blackValue){

    if(valueOfSensor(1) == whiteValue && valueOfSensor(2) == whiteValue
    && valueOfSensor(4) == whiteValue && valueOfSensor(5) == whiteValue){
      lineFollower.goForward(150);//go forward with 100/255 speed
    }
    else if(valueOfSensor(1) == whiteValue && valueOfSensor(2) == blackValue
    && valueOfSensor(4) == whiteValue && valueOfSensor(5) == whiteValue){

    }

  } else {

  }
  */

  /*
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
}

void LineFollower::goForward(int f) {
  //logFile << "Forward...\n";
  analogWrite(motor1a , f); // run the right motor in a direction
  digitalWrite(motor1b , LOW);
  analogWrite(motor2a , f); // run the Left motor in the same direction as the right one
  digitalWrite(motor2b , LOW);
}


void LineFollower::stopCar() {
  //logFile << "STOP...\n";
  digitalWrite(motor1a , LOW); // stop the right motor
  digitalWrite(motor1b , LOW);
  digitalWrite(motor2a , LOW); // stop the Left motor
  digitalWrite(motor2b , LOW);
}

void LineFollower::goBackward(int b) {
  //logFile << "Backwards...\n";
  digitalWrite(motor1a , LOW);
  analogWrite(motor1b , b); // run the right motor in opposite direction
  digitalWrite(motor2a , LOW);
  analogWrite(motor2b , b); // run the Left motor in the same direction as the right one
}

void LineFollower::turnRight(int r) {
  //logFile << "Soft Right...\n";
  digitalWrite(motor1a , LOW); // stop the right motor
  digitalWrite(motor1b , LOW);
  analogWrite(motor2a , r); // run the Left motor in forward direction
  digitalWrite(motor2b , LOW);
}

void LineFollower::turnLeft(int l,int r) {
  do {
    analogWrite(motor1a , r); // run the right motor in a direction
    digitalWrite(motor1b , LOW);
    analogWrite(motor2a , l); // run the left motor in a direction
    digitalWrite(motor2b , LOW);
  }
  while (sensor3 == whiteValue); // To be changed?!
}

void LineFollower::storeSensorValues() {
  sensor1 = digitalRead(A0);
  sensor2 = digitalRead(A1);
  sensor3 = digitalRead(A2);
  sensor4 = digitalRead(A3);
  sensor5 = digitalRead(A4);

}

int LineFollower::valueOfSensor(int a) { // a is the number of sensor whose value is required
  if (a == 1) {
    sensor1 = digitalRead(A0);
    return sensor1;
  }

  if (a == 2) {
    sensor2 = digitalRead(A1);
    return sensor2;
  }

  if (a == 3) {
    sensor3 = digitalRead(A2);
    return sensor3;
  }

  if (a == 4) {
    sensor4 = digitalRead(A3);
    return sensor4;
  }

  if (a == 5) {
    sensor5 = digitalRead(A4);
    return sensor5;
  }

}

// detect a Right angle on the right of the car.
void LineFollower::rightRA(int rra) {
  //logFile << "Turning 90 deg right...\n";
  do {
    digitalWrite(motor1a , LOW);
    digitalWrite(motor1b , LOW);
    analogWrite(motor2a , rra); // run the Left motor in the same direction as right
    digitalWrite(motor2b , LOW);
  }
  while (sensor1 != 1 && sensor2 != 1 && sensor3 == 1); // To be changed?!
}

// detect a Right angle on the Left of the car.
void LineFollower::leftRA(int lra) {
  //logFile << "Turning 90 deg left...\n";
  do {
    analogWrite(motor1a , lra); // run the left motor in a direction
    digitalWrite(motor1b , LOW);
    digitalWrite(motor2a , LOW);
    digitalWrite(motor2b , LOW);
  }
  while ((sensor5 != 1) && (sensor4 != 1) && (sensor3 == 1)); // To be changed?!
  //works in theory, might not work in practice, due to sensor lag {Jakov}
}


void LineFollower::testSensors(int numberOfSensors , char signalType)//Test code for one sensor or 5 sensors pass 'A' for analog , 'D' for digital
{
  if (numberOfSensors == 1 && signalType == 'A') { // test code for 1 analog sensor
    sensor1 = analogRead(A0);
    Serial.println(sensor1);
  }

  else if (numberOfSensors == 1 && signalType == 'D') { // test code for 1 digital sensor
    sensor1 = digitalRead(A0);
    Serial.println(sensor1);
  }

  else if (numberOfSensors == 5 && signalType == 'A') { // test code for 5 analog sensor
    sensor1 = analogRead(A0);
    sensor2 = analogRead(A1);
    sensor3 = analogRead(A2);
    sensor4 = analogRead(A3);
    sensor5 = analogRead(A4);
    Serial.print(sensor1);
    Serial.print(" ");
    Serial.print(sensor2);
    Serial.print(" ");
    Serial.print(sensor3);
    Serial.print(" ");
    Serial.print(sensor4);
    Serial.print(" ");
    Serial.println(sensor5);
  }

  else{ // test code for 5 digital sensor
    sensor1 = digitalRead(A0);
    sensor2 = digitalRead(A1);
    sensor3 = digitalRead(A2);
    sensor4 = digitalRead(A3);
    sensor5 = digitalRead(A4);
    Serial.print(sensor1);
    Serial.print(" ");
    Serial.print(sensor2);
    Serial.print(" ");
    Serial.print(sensor3);
    Serial.print(" ");
    Serial.print(sensor4);
    Serial.print(" ");
    Serial.println(sensor5);
  }


}
