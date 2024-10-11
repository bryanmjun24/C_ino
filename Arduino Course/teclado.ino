#include <Keypad.h>

const byte filas = 4; 
const byte columnas = 3; 

char teclado[filas][columnas] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte filaPin[filas] = {3, 2, 1, 0}; 
byte colPin[columnas] = {7, 6, 5}; 


Keypad teclas = Keypad( makeKeymap(teclado), filaPin, colPin, filas, columnas); 

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char tecla = teclas.getKey();
  
  if (tecla){
    Serial.println(tecla);
  }
}
