#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal pant(12,11,5,4,3,2);//rs enable y los datos
const byte fil=4;
const byte col=3;
char teclado [fil][col]={
  {'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}
  };
  byte filaPin[fil]={13,10,9,8};//donde esta conectada la fila uno 2 3 y 4
  byte colPin[col]={7,6,1};// donde esta conectada la columan 1 2 3 
  Keypad tecl=Keypad(makeKeymap(teclado),filaPin,colPin,fil,col);//nota las mayusculas de Key
  int a=0;
  int b=0;
void setup() {
  pant.begin(16,2);
  pant.print("Hola Bryan");
  delay(2000);
  pant.clear();
}

void loop() {
  char letra= tecl.getKey();
  if(letra)
  {
    if(letra=='#')
    {
      pant.clear();
    a=0;
    b=0;
  }
  else {
    pant.print(letra);
    a++;
    }
    if (a==16)
    {
      pant.setCursor(0,1);
      b++;
      a=0;
      }
      if(b==2)
      {
        pant.clear();
        b=0;
        }
    }

}
