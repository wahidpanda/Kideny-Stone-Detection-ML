#include <MQ2.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <SoftwareSerial.h>
int lpg, co, smoke;
int sensorValue;
int buzzer = 8;
int smokeA0 = A0;
// Your threshold value
int sensorThres = 100;
const int flamePin = 11;
int Flame = HIGH;

void setup(){
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  //lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smoke & Fire");
  lcd.setCursor(0, 1);
  lcd.print("Detection");
  delay(2000);

int buzzer = 10;
}
void loop() {
  int analogSensor = analogRead(smokeA0);
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
    
    tone(buzzer, 1000, 2000);
  }
  else 
  {
   
    noTone(buzzer);
  }

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  lcd.print("Smoke Level:");
  lcd.print(analogSensor-50);
  // Checks if it has reached the threshold value
  if (analogSensor-50 > sensorThres)
  {
    lcd.setCursor(0, 1);
    lcd.print("Alert!!!");
    lcd.setCursor(0, 1);
    lcd.print("Call Fire Serv.");
    tone(buzzer, 1000, 2000);
  }
  else
  {
  

    lcd.setCursor(0, 1);
    lcd.print(".....Normal.....");
    noTone(buzzer);
  }
  delay(500);
  lcd.clear();
}
