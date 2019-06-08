#ifndef LINEFOLLOWER_H
#define LINEFOLLOWER_H

#include "Arduino.h"
//#include <fstream>

//master control constants
//const double forwardConst = 10;
//const double softTurnConst = 10;
//const double hardTurnConst = 10;


class LineFollower
{
  private:
    //variables
    int motor1a , motor1b; // Motor 1 pins
    int motor2a , motor2b; // Motor 2 pins

    // Sensor pins
    int sensor1 , sensor2 , sensor3 , sensor4 , sensor5 ;
    // sensor1 = leftmost  , sensor5 = Rightmost

    //Pins of Motor driver channels
    int enable1,enable2;

    //log file
    //std::ofstream logFile;

  public:
    LineFollower(int _enable1, int _enable2, int _motor1a, int _motor1b, int _motor2a, int _motor2b,
                 int _sensor1, int _sensor2, int _sensor3, int _sensor4, int _sensor5);

    void goForward( int f);
    void stopCar();
    void goBackward(int b); // do we need it??????
    void turnRight(int r);
    void turnLeft(int l);
    void activateSensors();
    int valueOfSensor(int a); // get the value of specific sensor e.g. sensor4
    void rightRA(int rra); // detect a Right angle on the right of the car.
    void leftRA(int lra); // detect a Right angle on the left of the car.
    void testSensors(int numberOfSensors , char signalType);//Test code for one sensor or 5 sensors
};

#endif // LINEFOLLOWER_H
