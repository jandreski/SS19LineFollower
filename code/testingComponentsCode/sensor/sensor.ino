//actual sensors
int sensor1 = 1;
int sensor2 = 2;
int sensor3 = 3;
int sensor4 = 4;
int sensor5 = 5;

//readout variables 
int s1;
int s2;
int s3;
int s4;
int s5;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);
  pinMode(sensor5,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  s1 = digitalRead(sensor1);
  s2 = digitalRead(sensor2);
  s3 = digitalRead(sensor3);
  s4 = digitalRead(sensor4);
  s5 = digitalRead(sensor5);

  Serial.print(s1);
  Serial.print(" ");
  Serial.print(s2);
  Serial.print(" ");
  Serial.print(s3);
  Serial.print(" ");
  Serial.print(s4);
  Serial.print(" ");
  Serial.print(s5);
  Serial.println();
}
