#include<Keypad.h>
const byte fil=4;
const byte col=3;
int nota    []={261,294,329,345,392,440,493,523};
char teclado[fil][col]={
  {'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}
  };
  byte filaPin[fil]={13,10,9,8};//donde esta conectada la fila uno 2 3 y 4
  byte colPin[col]={7,6,1};// donde esta conectada la columan 1 2 3 
  Keypad tecl=Keypad(makeKeymap(teclado),filaPin,colPin,fil,col);//nota las mayusculas de Key
 
void setup() {
  

}

void loop() {
  char tecla=tecl.getKey();
  if (tecla)
  {
    if(tecla=='1')
    {
      tone(3,nota[0],500);
      }
    if(tecla=='2')
    {
      tone(3,nota[1],500);
      }
    if(tecla=='3')
    {
      tone(3,nota[2],500);
      }
     if(tecla=='4')
    {
      tone(3,nota[3],500);
      }
     if(tecla=='5')
    {
      tone(3,nota[4],500);
      }
      if(tecla=='6')
    {
      tone(3,nota[5],500);
      }
      if(tecla=='7')
    {
      tone(3,nota[6],500);
      }
      if(tecla=='8')
    {
      tone(3,nota[7],500);
      }
      else
      {
        noTone(2);
        }
    }
}
