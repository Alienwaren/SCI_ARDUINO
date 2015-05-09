#include <Firmata.h>
void digitalWriteFirmata(byte pin, int value)
{ 
  digitalWrite(pin, value);
}
void setPinMode(byte pin, int value)
{
  pinMode(pin, value);
}
void setup()
{
  Firmata.setFirmwareVersion(0,1);
  Firmata.attach(DIGITAL_MESSAGE, digitalWriteFirmata);
  Firmata.attach(SET_PIN_MODE, setPinMode);
  Firmata.begin();

}
void loop() 
{
  while(Firmata.available())
  {
    Firmata.processInput();
  }
  Firmata.sendDigital(12, digitalRead(12));
}

