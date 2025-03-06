#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int scl = A5, sda = A4;
const int trig = 2, echo = A0, gas = A1;

LiquidCrystal_I2C lcd(0x27, scl, sda);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(20, 4);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(gas, INPUT);
}

void cls()
{
  for(long long i = 0; i < 4; i++)
  {
    for(long long j = 0; j < 20; j++)
    {
      lcd.setCursor(j, i);
      lcd.print(" ");
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  cls();
  digitalWrite(trig, LOW);
  digitalWrite(trig, HIGH);
  digitalWrite(trig, LOW);
  float x = pulseIn(echo, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Ultrasonic Sensor:");
  lcd.setCursor(0, 1);
  lcd.print(x);
  lcd.setCursor(0, 2);
  lcd.print("Gas Sensor:");
  x = analogRead(gas);
  lcd.print(x);
  delay(1000);
}
