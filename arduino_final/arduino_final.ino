#include <dht.h>
dht DHT;
String voice;
 const int relay1=5;
 const int relay2=6;
 const int relay3=7; 
 int sensor1;
  int sensor2;
  int a;
    int sensor3;
    int sensor4;
    int sensor5;
    int sensor6;
    int sensor7;
    int sensor8;
    int sensor9;
#define DHT11_PIN 2


int airquality = 0;

const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;

int soundsensor=3;
int led=13;

const int trigPin = 9;
const int echoPin = 10;
const int trigPin1 = 11 ;
const int echoPin1=  12;
long duration;
int distance;
void allon(){
     digitalWrite(relay1,HIGH);
     digitalWrite(relay2,HIGH);
     digitalWrite(relay3,HIGH);
     }
void alloff(){
     digitalWrite(relay1, LOW);
     digitalWrite(relay2, LOW);
     digitalWrite(relay3, LOW);
    }

void setup()
{
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);

  pinMode(soundsensor,INPUT);pinMode(led,OUTPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);// Sets the echoPin as an Input
  pinMode(trigPin1, OUTPUT);
  pinMode (echoPin1, INPUT);
  alloff();
}

void loop()
{ while (Serial.available()){  
  delay(10); 
  char c = Serial.read(); 
  if (c == '#') {break;} 
  voice += c; 
  } 
  if (voice.length() > 0) {
    Serial.println(voice);
  if(voice.equals("all on")) {allon();}  
  else if(voice.equals("all of")){alloff();} 
  else if(voice.equals("watering system on")) {digitalWrite(relay1, HIGH);}
  else if(voice.equals("lights on")) {digitalWrite(relay2, HIGH);}
  else if(voice.equals("dehumidifier on")) {digitalWrite(relay3, HIGH);}
  else if(voice.equals("watering system of")) {digitalWrite(relay1, LOW);}
  else if(voice.equals("lights off")) {digitalWrite(relay2, LOW);delay(1000);}
  else if(voice.equals("dehumidifier of")) {digitalWrite(relay3, LOW);}
 
voice="";}
{{ digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration = pulseIn(echoPin1, HIGH);

  

  sensor9= duration*0.034/2;

   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  sensor8= duration*0.034/2;



 sensor7 = digitalRead (soundsensor);


  sensor6= analogRead(A1);



sensor5 = analogRead(A0);


sensor4=analogRead(A2);
sensor3= analogRead(A4);


sensor3 = analogRead(A4);


sensor1=DHT.temperature;
sensor2=DHT.humidity;
   

}}
  {{{Serial.print("WEATHER REPORT:\n\n");
  //Temperature
  int chk=DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  //if(DHT.humidity>25)
  //{digitalWrite(relay2,HIGH);}
  //delay(2000);
  

  //Air quality
  
  Serial.print("Air Quality = ");
  Serial.print(sensor3);
  Serial.print("*PPM");
  Serial.println();

  //light sensor
  
  Serial.print("Light=");
  Serial.print(sensor4);
  if(a<300)
  {digitalWrite(relay3,HIGH);}
  Serial.print("\n");
  

  //Rain sensor
 
  int range = map(sensor5, sensorMin, sensorMax, 0, 3);
  switch (range) {
 case 0:    
    Serial.println("Flood");
    break;
 case 1: 
    Serial.println("Rain Warning");
    break;
 case 2:  
    Serial.println("Not Raining");
    break;
  }
  

  //Soil moisture
  
  Serial.print("Soil moisture : ");
  if(sensor6<1000)
  {digitalWrite(relay1,HIGH);}
  Serial.println(sensor6);
    

  //Sound
  
  if (sensor7 == 1)
  {
    digitalWrite(led,HIGH);
    Serial.println("SOUND: HIGH");
  }
  else
  {
    digitalWrite(led,LOW);
    Serial.println("Sound: low");
  }


  //Storage
 

  Serial.print("Water level: ");
  Serial.println(15-sensor8);
  if ((15-sensor8)<=2)
    Serial.print("WATER LEVEL LOW!!!!\n");

 

  Serial.print("Fertilizer level: ");
  Serial.println(15-sensor9);
  if ((15-sensor9)<=2)
    Serial.print("FERTILIZER LEVEL LOW!!!!\n");

  Serial.println("\n\n");

  Serial.print("DISASTER MANAGEMENT STATISTICS:\n\n");

  a=analogRead(A3);
  if(a>160)
  {
   Serial.println("Vibration detected");
  }
  
  
  Serial.print("Air Quality = ");
  Serial.print(sensor1);
  Serial.print("*PPM\n\n");
  Serial.println();}}}
  /*{{{{Serial.print("sonDFR,");
  Serial.print(sensor2);
  Serial.print(";sonEB,");
  Serial.print(sensor3);
  Serial.print(";tempTMP,");
  Serial.print(sensor4);
  Serial.print(";lumin,");
  Serial.print(sensor5);
  Serial.print(";tempDHT,");
  Serial.print(sensor6);
  Serial.print(";humidDHT,"); 
  Serial.print(sensor7);
  Serial.print(";airQUAL,");
  Serial.println(sensor8);}}}}*/

  delay(2000);

  
}
