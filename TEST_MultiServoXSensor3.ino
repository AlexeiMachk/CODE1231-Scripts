#include<Servo.h>

int pos = 0;
int pos1 = 0;
int pos2 = 0;

int dt=10;
int dt1=10;
int dt2=10;

Servo servo;
Servo servo1;
Servo servo2;

//int distance,duration;
void setup() {
  // put your setup code here, to run once:
pinMode(A1,OUTPUT);
pinMode(A0,INPUT);
Serial.begin(9600);
servo.attach(10);

pinMode(A3,OUTPUT);
pinMode(A2,INPUT);
Serial.begin(9600);
servo1.attach(8);

pinMode(A5,OUTPUT);
pinMode(A4,INPUT);
Serial.begin(9600);
servo2.attach(6);
}

void loop() {
  // put your main code here, to run repeatedly:


if (calc_dis()<5)
{
for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(6);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(6);                       // waits 15ms for the servo to reach the position
  }
}

if (calc_dis1()<5)
{
for (pos1 = 0; pos1 <= 180; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(6);                       // waits 15ms for the servo to reach the position
  }
  for (pos1 = 180; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    servo1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(6);                       // waits 15ms for the servo to reach the position
  }
}

if (calc_dis2()<5)
{
for (pos2 = 0; pos2 <= 180; pos2 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(6);                       // waits 15ms for the servo to reach the position
  }
  for (pos2 = 180; pos2 >= 0; pos2 -= 1) { // goes from 180 degrees to 0 degrees
    servo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(6);                       // waits 15ms for the servo to reach the position
  }
}
}

//This code is written to calculate the DISTANCE using ULTRASONIC SENSOR

int calc_dis()
{
  int duration,distance;
  digitalWrite(A1,HIGH);
  delay(dt);
  digitalWrite(A1,LOW);
  duration=pulseIn(A0,HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}


int calc_dis1()
{
  int duration1,distance1;
  digitalWrite(A3,HIGH);
  delay(dt1);
  digitalWrite(A3,LOW);
  duration1=pulseIn(A2,HIGH);
  distance1 = (duration1/2) / 29.1;
  return distance1;
}

int calc_dis2()
{
  int duration2,distance2;
  digitalWrite(A5,HIGH);
  delay(dt2);
  digitalWrite(A5,LOW);
  duration2=pulseIn(A4,HIGH);
  distance2 = (duration2/2) / 29.1;
  return distance2;
}