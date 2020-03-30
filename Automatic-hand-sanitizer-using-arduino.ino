/*
This Link will help you to check the circuit 
https://www.tinkercad.com/things/cCgtnMuSaqu-automatic-hand-sanitizer/editel?sharecode=U42NB5_TraOGJ74hmhFynrH-yzAvZ6CC11uy0tvZhNo=
Triger pin = 4
Echo pin =5
Servo = 6
Led Light = 7
VCC = +5V
GND = -Ve
*/

#include <Servo.h>
Servo myservo;  
//int pos = 0;  
const int trigPin = 4; //Tri pin of ultrasonic  Sensor
const int echoPin = 5; //Echo pin of ultrasonic  Sensor
int servo = 6;         //Servo motor pin
const int led = 7;     //Led Light Pin
int mindis = 20;       //Time delay

long duration;
float distance;

void setup() 
{
  myservo.attach(servo);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(led, OUTPUT);
  myservo.write(0);
}

void loop() 
{
  //Serial.begin(9600);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034*(duration/2);
  //Serial.println(distance);
  if (distance < mindis)
  {
    digitalWrite(led,HIGH);
    myservo.write(160);
    delay(1000);
  }
  else 
  {
    digitalWrite(led,LOW);
      myservo.write(0);
  }
  delay(300);
}
