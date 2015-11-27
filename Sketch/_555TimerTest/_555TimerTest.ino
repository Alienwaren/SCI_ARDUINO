
int readPin = 2;
bool actualState = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  actualState = digitalRead(readPin);
  if(actualState)
  {
    Serial.println("Swiece sie!");
  }
}



