

int sensor1Pin = A10;
int sensor2Pin = A11;
int sensor3Pin = A12;
int sensor4Pin = A13;
int sensor5Pin = A14;



void setup() {

  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(sensor3Pin, INPUT);
  pinMode(sensor4Pin, INPUT);
  pinMode(sensor5Pin, INPUT);

  Serial.begin(9600);
  

}

void loop() {

  
  Serial.print( digitalRead(sensor1Pin) );
  Serial.print("  ");
  Serial.print( digitalRead(sensor2Pin) );
  Serial.print("  ");
  Serial.print( digitalRead(sensor3Pin) );
  Serial.print("  ");
  Serial.print( digitalRead(sensor4Pin) );
  Serial.print("  ");
  Serial.println( digitalRead(sensor5Pin) );

    
}
