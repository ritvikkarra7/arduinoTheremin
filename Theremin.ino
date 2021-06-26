#include <Volume.h>

int trig1 = 8; 
int echo1 = 7; 
int trig2 = 10; 
int echo2 = 11; 
int dt = 2; 
Volume vol; 



void setup() {

//  pinMode(buzzPin, OUTPUT); 
  pinMode(trig1, OUTPUT); 
  pinMode(trig2, OUTPUT); 
  pinMode(echo2, INPUT); 
  pinMode(echo1, INPUT); 
  Serial.begin(9600); 
  vol.begin(); //default pin = 5 

}

void loop() {
  // put your main code here, to run repeatedly:

  int pitchDist = getDistance(trig1, echo1, 500, 20); 
  int pitch = -393./480* (pitchDist - 1000) + 130; //in Hz
  int volDist = getDistance(trig2, echo2, 500, 20); 
  byte volume = 255./480 * (volDist - 20); 
  vol.tone(pitch, volume); 
//  Serial.println(pitchDist); 
  

}

float getDistance(int trig, int echo, int upper, int lower){
  //distance in mm from sensor, with upper and lower limit 

  digitalWrite(trig, LOW); 
  delayMicroseconds(dt); 
  digitalWrite(trig, HIGH); 
  delayMicroseconds(dt); 
  digitalWrite(trig, LOW); 

  int ping = pulseIn(echo, HIGH); 

  int dist = abs((347800 * ping * pow(10, -6))/2.);
  
  if(dist > upper)
    return upper; 
  else if(dist < lower)
    return lower; 
  else
    return dist; 
   
}
