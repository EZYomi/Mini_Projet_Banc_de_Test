/*
 CIEL 2 - Mini-Project - Banc de Test I2C
 FAIT PAR GAINCHE VALENTIN
 LE 16/09/2026
*/

#include <LiquidCrystal.h>

// Initialisation de l'écran LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buttonPin = 6;    
const int outputPin = d6;

bool systemRunning = false;      // État du programme (marche/arrêt)
int lastButtonState = LOW;       // Mémorise l'état précédent du bouton

void setup() {
  lcd.begin(16, 2);
  lcd.print("Ecran en marche");

  pinMode(buttonPin, INPUT);
  pinMode(outputPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    systemRunning = !systemRunning; // Inverse l'état (true devient false, et vice-versa)
    delay(50); // Petit délai anti-rebond pour éviter les faux contacts
  }
  lastButtonState = buttonState;

  // Actions selon l'état du système
  if (systemRunning) {
    digitalWrite(outputPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Actif: ");
    lcd.print(millis() / 1000);
    lcd.print("s   "); // Espaces pour effacer les anciens caractères
  } else {
    digitalWrite(outputPin, LOW);
    lcd.setCursor(0, 0);
    lcd.print("TEST REUSSIE");
  }
}
