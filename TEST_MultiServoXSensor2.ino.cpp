#include<Servo.h>

//sensor 1
int trig1=8;
int echo1=9;
int dt1=10;

//sensor 2
int trig2=10;
int echo2=11;
int dt2=10;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

//int distance,duration;
void setup() {
  // put your setup code here, to run once:
 pinMode(13, OUTPUT);
//motor 1
pinMode(trig1,OUTPUT);
pinMode(echo1,INPUT);
Serial.begin(9600);
servo1.attach(13);

//motor 2
pinMode(trig2,OUTPUT);
pinMode(echo2,INPUT);
Serial.begin(9600);
servo2.attach(12);
}

void loop() {

// sensor1
if (calc_dis1()<10)
{
  digitalWrite(13, HIGH); 
  for (int i=0;i<=540;i++)
  {
    servo1.write(i);
    delay(1);
  }
  delay(100);
  for (int i=540;i>=0;i--)
  {
    servo1.write(i);
    delay(1);
  }
  delay(100);
}

// sensor2
if (calc_dis2()<10)
{
  digitalWrite(13, LOW); 
  for (int j=0;j<=540;j++)
  {
    servo2.write(j);
    delay(1);
  }
  delay(100);
  for (int j=540;j>=0;j--)
  {
    servo2.write(j);
    delay(1);
  }
  delay(100);
}
}

//This code is written to calculate the DISTANCE using ULTRASONIC SENSOR

// sensor1
int calc_dis1()
{
  int duration1,distance1;
  digitalWrite(trig1,HIGH);
  delay(dt1);
  digitalWrite(trig1,LOW);
  duration1=pulseIn(echo1,HIGH);
  distance1 = (duration1/2) / 29.1;
  return distance1;
}

// sensor2
int calc_dis2()
{
  int duration2,distance2;
  digitalWrite(trig2,HIGH);
  delay(dt2);
  digitalWrite(trig2,LOW);
  duration2=pulseIn(echo2,HIGH);
  distance2 = (duration2/2) / 29.1;
  return distance2;
}