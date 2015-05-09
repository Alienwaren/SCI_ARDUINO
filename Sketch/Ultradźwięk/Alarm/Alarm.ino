#include "dzwieki.h"
int buzzer = 5;
int echo = 9;
int trigger = 8;
int delayValue = 10000;
int maxValue = 200;
void setup() {
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(buzzer, OUTPUT);
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
  tone(buzzer, distance * 100, 500);
  Serial.println(distance);
  delay(100);
}


