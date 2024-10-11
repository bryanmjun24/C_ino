#include <LiquidCrystal.h>
LiquidCrystal pant(12,11,5,4,3,2); //11 enable 12 rs

void setup() {
  pant.begin(16,2);//aki se pone el tamaño del lcd
  pant.print("Bienvenidos");
  delay(2000);
  pant.clear();//se borra lo escrito
  pant.print("C=      F=");
  pant.setCursor(0,1);
  pant.print("K=      R=");

}

void loop() {
  float c=centig();
  float f=faren(c);
  float k=kelvin(c);
  float r=rankin(c);
  pant.setCursor(2,0);
  pant.print(c);
  pant.setCursor(10,0);
  pant.print(f);
  pant.setCursor(2,1);
  pant.print(k);
  pant.setCursor(10,1);
  pant.print(r);
  delay(200);

}
float centig()
{
  int a;
  float cent;
  a=analogRead(A0);
  cent=(500*a/1023);
  return(cent);
  }
float kelvin(float cent)
  {
    float kel;
    kel=cent+273.15;
    return(kel);
    }
float faren(float cent)
   {
     float far;
     far=cent*1.8+32;
     return(far);
     }
float rankin(float cent)
    {
      float ran;
      ran=(cent+273.15)*1.8;
      return(ran);
      
      }
    
