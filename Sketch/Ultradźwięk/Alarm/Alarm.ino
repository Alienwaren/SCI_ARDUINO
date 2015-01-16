int leds[] = {12,11}; //tablica z ledami - odwołujemy się za pomocą leds[numerIndeksu]
int echo = 9;
int trigger = 8;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 2; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(echo, INPUT);
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
  }else
  {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], LOW);
  }
  Serial.println(distance);
   
}
