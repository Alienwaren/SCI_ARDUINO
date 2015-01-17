#include "dzwieki.h"
int leds[] = {12,11}; //tablica z ledami - odwołujemy się za pomocą leds[numerIndeksu]
int echo = 5 ;
int trigger = 4 ;
int buzzer = 2 ;

int melody[] = {
  NOTE_E4, NOTE_B4,NOTE_B4, NOTE_E5, NOTE_B2,0, NOTE_B3, NOTE_C3 ,NOTE_CS2 , NOTE_AS1 , NOTE_AS2 , NOTE_GS4 , NOTE_B4 , NOTE_FS5 , NOTE_E6 , NOTE_DS7 , NOTE_E4, NOTE_B4,NOTE_B4, NOTE_E5, NOTE_B2,0, NOTE_B3, NOTE_C3 ,NOTE_CS2 , NOTE_AS1 , NOTE_AS2 , NOTE_GS4 , NOTE_B4 , NOTE_FS5 , NOTE_E6 , NOTE_DS7};

  
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 2; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigger, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  int distance = 0;
  int duration = 0;
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration / 58;
  if(distance < 30)
  {
    digitalWrite(leds[0], LOW);
    digitalWrite(leds[1], HIGH);
    //tone(buzzer,melody[distance],1000);
    tone(buzzer,distance*250,1000);
  }else
  {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], LOW);
   noTone(buzzer);
  }
  Serial.println(distance);
}


