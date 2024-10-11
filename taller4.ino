#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

float voltaje,voltaje1;
float voltaje2;

void setup(){

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("       EPN     ");
  lcd.setCursor(0, 1);
  lcd.print("Voltaje: ");
  
  
}

void loop(){ 
  
    voltaje1 = analogRead(A0);
    voltaje2 =(voltaje1*5)/1023;
    voltaje = map(voltaje1, 0, 1023, 0, 255);

    analogWrite(13, voltaje);

    lcd.setCursor(9, 1);
    lcd.print(voltaje2);
    
    
}
  
