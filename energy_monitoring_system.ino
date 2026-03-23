#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int voltagePin = A0;
const int currentPin = A1;
const int buzzerPin = 8;

float maxPower = 100.0;  // Threshold

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  // Read voltage (simulated)
  int voltageValue = analogRead(voltagePin);
  float voltage = voltageValue * (5.0 / 1023.0) * 10; 

  // Read current (ACS712)
  int currentValue = analogRead(currentPin);
  float currentVoltage = currentValue * (5.0 / 1023.0);
  float current = (currentVoltage - 2.5) / 0.185;

  // Calculate power
  float power = voltage * current;

  // Display on LCD
  lcd.setCursor(0,0);
  lcd.print("V:");
  lcd.print(voltage);
  lcd.print(" I:");
  lcd.print(current);

  lcd.setCursor(0,1);
  lcd.print("P:");
  lcd.print(power);
  lcd.print(" W");

  // Alert
  if(power > maxPower){
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  delay(1000);
}
