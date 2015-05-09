///TODO: add display
#include <dht.h>
int sensorPin = 5;
int ledPins[] = {13,12,11};
dht DHT;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 3; ++i)
  {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(115200);
}

void loop() {
  
  int statusDHT = DHT.read11(sensorPin);
  if(statusDHT == DHTLIB_OK)
  {
    float humidity = DHT.humidity;
    float temperature = DHT.temperature;
    Serial.println(temperature);
    if(temperature <= 20)
    {
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], LOW);
    }else if(temperature >= 20 && temperature <= 25)
    {
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], HIGH);
    }else if (temperature >= 25 && temperature >= 30)
    {
      digitalWrite(ledPins[0], LOW);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH);
    }
  }
}
