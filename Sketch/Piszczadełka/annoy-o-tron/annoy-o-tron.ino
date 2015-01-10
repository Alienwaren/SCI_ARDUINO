int out = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(out, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    digitalWrite(out, HIGH);
    delay(16);
    digitalWrite(out, LOW);
    delay(16);
}

