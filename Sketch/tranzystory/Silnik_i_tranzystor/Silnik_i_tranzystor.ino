int transistorPin = 4;
String message = "";
void setup() {
  // put your setup code here, to run once:
  pinMode(transistorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  message = getMessage();
  if(message.indexOf("on") >= 0)
   {
     digitalWrite(transistorPin, HIGH);
     Serial.println("on");
     message = "";
   }else if(message.indexOf("off") >= 0)
   {
      digitalWrite(transistorPin, LOW);
      Serial.println("off");
      message = "";
   }
   delay(1000);
}
String getMessage()
{
  String bufferMessage = "";
  while(Serial.available() > 0)
  {
    int byteRecv = Serial.read();
    bufferMessage += (char)byteRecv;
    if(byteRecv == '\n')
    {
      Serial.println(bufferMessage);
      return bufferMessage;
    }
  }
  return "noMessage";
}
