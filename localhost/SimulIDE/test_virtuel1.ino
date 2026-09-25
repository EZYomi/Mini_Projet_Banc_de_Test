/*
 CIEL 2 - Mini-Project - Banc de Test I2C
 FAIT PAR GAINCHE VALENTIN
 LE 16/09/2026
*/

#include <LiquidCrystal.h>

// Initialisation de l'écran LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buttonPin = 6;    // Premier bouton (marche/arrêt global)
int buttonState = 0;


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Test Ecran");
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  lcd.setCursor(0, 1);
  lcd.print("Reussi");
  if (buttonState == HIGH) {
    // Reset le tout et lancer le test:
    ;
  }
}