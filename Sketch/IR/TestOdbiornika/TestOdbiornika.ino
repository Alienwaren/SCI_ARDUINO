/*
  SKETCH DO ODBIERANIA DANYCH Z ODBIORNIKA IR. 
*/
#include <IRremote.h>

int RECV_PIN = 11; //pin do którego jest przyłączony sensor

IRrecv irrecv(RECV_PIN); //obiekt do obsługi odbiornika IR

decode_results results; //nasze wartosci

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // uruchamiamy sensor
}

void loop() {
  if (irrecv.decode(&results)) { //dekodujemy
    Serial.println(results.value, HEX); //i wyświetlamy
    irrecv.resume(); // Oczywiście że chcemy kolejne wartości (:
  }
  delay(100);
}
