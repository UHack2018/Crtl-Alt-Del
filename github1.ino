#include <dht.h>
 int sensor1;
  int sensor2;
  int sensor3;
  int sensor4;
  int sensor5;
  int sensor6;
  #define DHR11_PIN 2;
  int airquality = 0;
 const int sensormin=0;
 const int sensormax=1024;
 const int trigpin=9;
 const int echopin=10;
 const int trigpin1=11;
 const int echopin1=12;
 long duration;
 int distance;
void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(trigpin1,OUTPUT);
  pinMode(echopin1,INPUT);

}

void loop() {
sensor1=analogRead(A0);
sensor2=analogRead(A1);
sensor3=analogRead(A2);
sensor4=analogRead(A3);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration=pulseIn(echopin,HIGH);
sensor5=duration*0.034/2;
digitalWrite(trigpin1,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1,LOW);
duration=pulseIn(echopin1,HIGH);
sensor6=duration*0.034/2;
Serial.println(sensor1);
Serial.println(sensor2);
Serial.println(sensor3);
Serial.println(sensor4);
Serial.println(sensor5);
Serial.println(sensor6);
}
