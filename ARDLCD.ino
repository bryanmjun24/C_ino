#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup() 
  {
      lcd.begin(16, 2); // Hay que inicializar el LCD
      lcd.setCursor(0, 0); 
      lcd.print("HOLA DAVID LOPEZ");
      lcd.write(1); 
  }
void loop() 
 {
 }
