#include "LineFollower.h"
#include "Arduino.h"

// constructor....
LineFollower::LineFollower(int _enable1, int _enable2, int _leftMotor1, int _leftMotor2, int _rightMotor1, int _rightMotor2, 
                           int _sensor1, int _sensor2, int _sensor3, int _sensor4, int _sensor5)
{
  // store the motor pins arguments inside the variables
  rightMotor1 = _rightMotor1;
  rightMotor2 = _rightMotor2;
  leftMotor1 = _leftMotor1;
  leftMotor2 = _leftMotor2;

  // store the motor pins arguments inside the variables
  s1Pin=_sensor1;
  s2Pin=_sensor2;
  s3Pin=_sensor3;
  s4Pin=_sensor4;
  s5Pin=_sensor5;

  // set/initialise Motor pins as OUTPUT
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);

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
  digitalWrite(enable1, HIGH);
  digitalWrite(enable2, HIGH);

}


void LineFollower::goForward(int leftMotorSpeed , int rightMotorSpeed) {

  analogWrite(leftMotor1 , leftMotorSpeed); // run the Left motor in forward direction
  digitalWrite(leftMotor2 , LOW);
  analogWrite(rightMotor1 , rightMotorSpeed); // run the right motor in forward direction
  digitalWrite(rightMotor2 , LOW);
}


void LineFollower::stopCar() {

  digitalWrite(leftMotor1 , LOW);
  digitalWrite(leftMotor2 , LOW);
  digitalWrite(rightMotor1 , LOW);
  digitalWrite(rightMotor2 , LOW);
}



void LineFollower::turnCar(int leftMotorSpeed, int rightMotorSpeed) {

  analogWrite(leftMotor1 , leftMotorSpeed); // run the Left motor in forward direction
  digitalWrite(leftMotor2 , LOW);
  analogWrite(rightMotor1 , rightMotorSpeed); // run the right motor in forward direction
  digitalWrite(rightMotor2 , LOW);

}
