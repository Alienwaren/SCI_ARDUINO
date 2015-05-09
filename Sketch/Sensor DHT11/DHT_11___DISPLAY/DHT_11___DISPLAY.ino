
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>
#define I2C_ADDR    0x27 // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7


LiquidCrystal_I2C	lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
dht dht11;
int dhtPin = 5;
void setup()
{
  lcd.begin (16,2); //  <<----- My LCD was 16x2

  
// Switch on the backlight
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home (); // go home
}

void loop()
{
  lcd.setCursor(0,0);
  int chk = dht11.read11(dhtPin);
  Serial.println(chk);
  if(chk == DHTLIB_OK)
  {
    lcd.print("Humidity: ");
    lcd.print(dht11.humidity);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Temp:");
    lcd.print(dht11.temperature);
    lcd.print("C");
  }
}
