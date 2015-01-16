int speaker = 7;
int echo = 9;
int trigger = 8;
void setup() {
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(speaker, OUTPUT);
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
  int out = (distance * 255) / 190;
  analogWrite(7, out);
  Serial.println(distance);
  delay(100);  
}
