#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  lcd.begin(16,2);
  lcd.print("Bienvenidos");
  delay(2000);
  lcd.clear();
  
  lcd.print("C=      F=");
  lcd.setCursor(0,1);
  lcd.print("K=      R=");
}
float centigrados(){
  int dato;
  float cent;
  dato=analogRead(A0);
  cent=(500.0*dato)/1023;
  return(cent);
}
float kelvin(float cent){
  float kel;
  kel=cent+273.15;
  return(kel);
}
float fahren(float cent){
  float far;
  far=cent*1.8+32;
  return(far);
}
float rankin(float cent){
  float ran;
  ran=(cent+273.15)*1.8;
  return(ran);
}

void loop() {
  float c=centigrados();
  float f=fahren(c);
  float k=kelvin(c);
  float r=rankin(c);
  
  lcd.setCursor(2,0);
  lcd.print(c);
  
  lcd.setCursor(10,0);
  lcd.print(f);
  
  lcd.setCursor(2,1);
  lcd.print(k);
  
  lcd.setCursor(10,1);
  lcd.print(r);
  
  delay(200);

}



































































