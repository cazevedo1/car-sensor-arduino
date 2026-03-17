#include <Ultrasonic.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int ledRed = 13;
int ledYel = 12;
int ledGre = 11;
int buzzer = 8;

LiquidCrystal_I2C lcd(0x27, 16, 2);
HC_SR04 distancia(7, 6);

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledYel, OUTPUT);
  pinMode(ledGre, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  Serial.begin(9600);
}

void loop() {
  noTone(buzzer);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYel, LOW);
  digitalWrite(ledGre, LOW);
  
  if(distancia.distance() > 30) {
   lcd.print("      ");
   lcd.print(distancia.distance());
   lcd.print(" cm");
   lcd.setCursor(3, 1);
   lcd.print("         ");
   delay(500);
   lcd.clear();
  } else if(distancia.distance() > 20 & distancia.distance() <= 30) {
    lcd.print("      ");
    lcd.print(distancia.distance());
    lcd.print(" cm");
    printGreen();
    delay(500);
    lcd.clear();
  } else if(distancia.distance() > 10 & distancia.distance() <= 20) {
    lcd.print("      ");
    lcd.print(distancia.distance());
    lcd.print(" cm");
    printYellow();
    delay(500);
    lcd.clear();
  } else if(distancia.distance() <= 10) {
    lcd.print("      ");
    lcd.print(distancia.distance());
    lcd.print(" cm");
    printRed();
    delay(500);
    lcd.clear();
  } 
  
  Serial.println(distancia.distance());
}

void printGreen() {
  digitalWrite(ledGre, HIGH);
  lcd.setCursor(3, 1);
  lcd.print(" Cuidado! ");
}

void printYellow() {
  digitalWrite(ledYel, HIGH);
  lcd.setCursor(3, 1);
  lcd.print("Bem Perto!");
  tone(buzzer, 350);
}

void printRed() {
  digitalWrite(ledRed, HIGH);
  lcd.setCursor(3, 1);
  lcd.print("VAI BATER!");
  tone(buzzer, 200);
}
