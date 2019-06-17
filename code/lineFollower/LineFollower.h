#ifndef LINEFOLLOWER_H
#define LINEFOLLOWER_H

#include "Arduino.h"

const int blackValue = 0; //Specific analog or digital value of the sensor at which the sensor reads black.
const int whiteValue = 1;

class LineFollower
{
  private:
    //MOTOR variables' pins
    int rightMotor1 , rightMotor2; // Right Motor pins
    int leftMotor1 , leftMotor2; // Left Motor pins    

    //variable to store sensors' pins numbers
    int s1Pin,s2Pin,s3Pin,s4Pin,s5Pin; 

    //MOTOR DRIVER enable pins
    int enable1, enable2;


  public:
    LineFollower(int , int , int , int , int , int ,
                 int , int , int , int , int );

    void goForward( int);
    void stopCar();
    void goBackward(int);
    void turnCar(int , int); // 1.speed of left motor, 2.speed of right motor
    void testSensors(int  , byte );//Test code for one sensor or 5 sensors.

    
};

#endif // LINEFOLLOWER_H
