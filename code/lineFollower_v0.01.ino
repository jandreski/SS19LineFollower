

//////////Right motor Pins definition
int motor1a = 5; // set it HIGH to go forward
int motor1b = 6; // set it HIGH to go backward

//////////left motor Pins definition
int motor2a = 10; // set it HIGH to go forward
int motor2b = 11; // set it HIGH to go backward

int sensor1;
int sensor2;
int sensor3;
int sensor4;
int sensor5;

void setup() {
  pinMode(motor1a , OUTPUT); //set the motor pin as output
  pinMode(motor1b , OUTPUT); //set the motor pin as output
  pinMode(motor2a , OUTPUT); //set the motor pin as output
  pinMode(motor2b , OUTPUT); //set the motor pin as output

}

void loop() {
  sensorReadings();// get all sensors' readings. is it continous?

  if(sensor3==1){ //change later
    goForward();
  }
  
  if(sensor1==1 && sensor2==1 && sensor3==1){
  rightAngle();  
  }

  if(sensor5==1 && sensor4==1 && sensor3==1){
  leftAngle();  
  }

  
  for(int c=0; c=!-1; c++){  
  
  
  
  }


}


void sensorReadings(){
  sensor1=analogRead(A0);
  sensor2=analogRead(A1);
  sensor3=analogRead(A2);
  sensor4=analogRead(A3);
  sensor5=analogRead(A4);
}

void goForward(){
  digitalWrite(motor1a , HIGH); // run the right motor in a direction
  digitalWrite(motor1b , LOW);
  digitalWrite(motor2a , HIGH); // run the Left motor in the same direction as right
  digitalWrite(motor2b , LOW);  
}

void rightAngle(){
   do {    
    goRightRA();
  }
  while(sensor1!=1 && sensor2!=1 && sensor3==1);
}

void leftAngle(){
   do {    
    goleftRA();
  }
  while(sensor5!=1 && sensor4!=1 && sensor3==1);
}


void goRightRA(){ // to turn right slowly momentarly
  digitalWrite(motor1a , LOW); 
  digitalWrite(motor1b , LOW);
  analogWrite(motor2a , 175); // run the Left motor in the same direction as right
  digitalWrite(motor2b , LOW);  
}

void goleftRA(){ // to turn left slowly momentarly
  analogWrite(motor1a , 175); // run the left motor in a direction 
  digitalWrite(motor1b , LOW);  
  analogWrite(motor2a , LOW); 
  digitalWrite(motor2b , LOW);   
}
