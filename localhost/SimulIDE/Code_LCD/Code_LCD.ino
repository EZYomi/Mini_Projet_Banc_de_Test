/*
 CIEL 2 - Mini-Project - Banc de Test I2C
 FAIT PAR GAINCHE VALENTIN
*/

#include <LiquidCrystal.h>

// Initialisation de l'écran LCD (rs, en, d4, d5, d6, d7)
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buttonPin = 6;
int buttonState = 0;        
int lastButtonState = LOW;  
int testIndex = 0;          // Numéro du test en cours 

void setup() {
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT);
  
  // Accueil
  lcd.setCursor(0, 0);
  lcd.print("Banc de Test");
  lcd.setCursor(0, 1);
  lcd.print("Appuyez pour test");
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Détection d'un appui (passage de LOW à HIGH)
  if (buttonState == HIGH && lastButtonState == LOW) {
    testIndex++; // On passe au test suivant à chaque appui
    
    // Si on dépasse le nombre de tests, on boucle (revient au début ou réinitialise)
    if (testIndex > 4) {
      testIndex = 1; // Revient au premier test
    }

    // Effacement de l'écran et affichage du test correspondant
    lcd.clear();
    lcd.setCursor(0, 0);
    
    switch (testIndex) {
      case 1:
        lcd.print("Test 1: LCD OK");
        lcd.setCursor(0, 1);
        lcd.print("Affichage OK");
        lcd.noBlink();
        break;
        
      case 2:
        lcd.print("Test 2: Off");
        lcd.setCursor(0, 1);
        //lcd.;
        delay(5000);
        break;
        
      case 3:
        lcd.print("Test 3: Pleins");
        lcd.setCursor(0, 1);
        //lcd.;
        delay(10000);
        break;
        
      case 4:
        lcd.print("Test 4: Blink");
        lcd.setCursor(0, 1);
        lcd.blink();
        break;
    }
    
    delay(3000); // Anti-rebond
  }

  lastButtonState = buttonState; // Sauvegarde l'état du bouton
}
