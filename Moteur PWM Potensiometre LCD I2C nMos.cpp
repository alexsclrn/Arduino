// Les librairies
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Definition ecran LCD
LiquidCrystal_I2C lcd(0x20, 16, 2); // Addresse I2C, Lettre par ligne, nombre de lignes

// Definition broches
int brochePot = A0; 
int brocheMoteur = 9;
int valeurCAN = 0;
int valeurPWM = 0;
float tension = 0.0;
int pourcentage = 0;

// Setup
void setup() {
  Serial.begin(9600);
  pinMode(brocheMoteur, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("Systeme PWM OK");
  delay(1000);
  lcd.clear();
}

// Loop
void loop() {
  valeurCAN = analogRead(brochePot);
  valeurPWM = map(valeurCAN, 0, 1023, 0, 255);
  tension = valeurCAN * 5.0 / 1023.0; 
  pourcentage = map(valeurCAN, 0, 1023, 0, 100); 
  analogWrite(brocheMoteur, valeurPWM); 
  lcd.setCursor(0, 0); lcd.print("CAN: "); lcd.print(valeurCAN);
  lcd.setCursor(0, 1); lcd.print("Vitesse: "); lcd.print(pourcentage); lcd.print("%");
  delay(200);
}
