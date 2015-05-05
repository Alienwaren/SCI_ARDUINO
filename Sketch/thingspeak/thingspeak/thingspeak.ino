#include <dht.h>
#include <ArduinoJson.h>
dht dht11;
int pin = 5;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  ///najpierw temperatura...
  int dataTemperature = readDataTemperature(pin);
  delay(1000); //poczekajmy az sensor się "przeładuje"
  ///potem wilgotność
  int dataHumidity = readDataHumidity(pin);
  delay(1000);
  generateAndPrintJson(dataTemperature, dataHumidity);
}
int readDataTemperature(int pinToBeRead) //odczyt danych z sensora
{
   // put your main code here, to run repeatedly:
  int status = dht11.read11(pinToBeRead);
  if(status == DHTLIB_OK)
  {
    ///wszystko ok jedziemy dalej...
    return dht11.temperature;
  }else
  {
  	///coś nie działa, próbujemy jeszcze raz
  	Serial.println("oops");
  	return readDataTemperature(pin);
  }
}
int readDataHumidity(int pinToBeRead) //odczyt danych z sensora
{
   // put your main code here, to run repeatedly:
  int status = dht11.read11(pinToBeRead);
  if(status == DHTLIB_OK)
  {
    ///wszystko ok jedziemy dalej...
    return dht11.humidity;
  }else
  {
  	///coś nie działa, próbujemy jeszcze raz
  	Serial.println("oops");
  	return readDataTemperature(pin);
  }
}
void generateAndPrintJson(int temperature, int humidity)
{
	StaticJsonBuffer<200> jsonBuffer;
	JsonObject& root = jsonBuffer.createObject();
	root["sensor"] = "DHT11";
	JsonArray& data = root.createNestedArray("data");
	data.add(temperature);
	data.add(humidity);
	root.prettyPrintTo(Serial);
}