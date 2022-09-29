#include <Servo.h>

const int light = 6;
int DistanceValue = 0;
int LDRValue = 0;
double temp;
int tempin = A1;
#define fan 5

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_4;
Servo servo_9;

void setup()
{
  
  // Giving Fan Current â€¦.Making Fan Pin 9 For Output
  pinMode (fan,OUTPUT);
  pinMode(light, OUTPUT);
  pinMode(A0, INPUT);
  servo_4.attach(4, 500, 2500);
  servo_9.attach(9, 500, 2500);
}

void loop()
{
  temp = 0;
  temp =analogRead(tempin);
  temp = (double)temp/1024;
  temp = temp * 5;
  temp = temp - 0.5;
  temp = temp * 100;   //Convert Temperature
  if (temp <20) {
    analogWrite(fan,0);   //Fan Off
  }
  else if (temp<=20) {
    analogWrite(fan, 51);   //Fan Speed 20%
  }
  else if (temp<=25) {
    analogWrite( fan,102);   //Fan Speed 40%
  }
  else if (temp<=30) {
    analogWrite (fan,153);   //Fan Speed 60%
  }
  else if (temp<=49) {
    analogWrite(fan,200);   //Fan Speed 80%
  }
  else if (temp>=50) {
    analogWrite(fan,255);   //Fan Speed 100%
  }
  
  DistanceValue = 0.01723 * readUltrasonicDistance(11, 11);
  LDRValue = analogRead(A0);
  if (LDRValue >= 550) {
    servo_4.write(90);
    analogWrite(light,0);
  } 
  else {
    servo_4.write(0);
    analogWrite(light,255);
  }
  if (DistanceValue <= 300) {
    servo_9.write(90);
    delay(100); // Delay a little bit to improve simulation performance
    
  } 
  else {
    servo_9.write(0);
    delay(100); // Delay a little bit to improve simulation performance
    
  } 
}
