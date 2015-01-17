#include "dzwieki.h"
int button = 5;
int buttonState = 0;
int note = NOTE_E2;
int speaker = 8;
//rezystor czerwony, czarny, zloty 
void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
   buttonState = digitalRead(button);
   Serial.println(buttonState);
   if(buttonState == true)
   {
     tone(8, note, 1000);
   }else
   {
     noTone(8);
   }
}
