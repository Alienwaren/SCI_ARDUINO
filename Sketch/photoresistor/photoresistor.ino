int led = 11;
void setup()
{
  pinMode(led, OUTPUT);
  
}

void loop()
{
  double reading = analogRead(A0);
  Serial.println(reading);
  if(reading <= 700)
  {
    digitalWrite(led, HIGH);
  }else
  {
    digitalWrite(led, LOW);
  }
}
