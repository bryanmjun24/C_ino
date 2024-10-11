
#define Pecho 6
#define Ptrig 7
long duracion, distancia, auxi;   
int analogPin = 3;
int lvlmax=14;
int aux2;//variable para cambiar la relacion proporcional de la cosa
void setup() {                
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  pinMode(analogPin, OUTPUT);            // Define el pin 13 como salida
  }
  
void loop() {
  
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros

  
  if (distancia >= 50 || distancia <= 0){  // si la distancia es mayor a 500cm o menor a 0cm 
   // Serial.println("---");                  // no mide nada
   
    Serial.println(distancia);
  }
  else {
    Serial.print(distancia);           // envia el valor de la distancia por el puerto serial
    Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
    digitalWrite(13, 0);               // en bajo el pin 13
    auxi=map(distancia,1,lvlmax,0,255);
    aux2=255-auxi;
    if (aux2<1){
    aux2=0;
    }
    
    analogWrite(analogPin, aux2);
    Serial.println(aux2);
    
  }
  
   
  delay(400);                                // espera 400ms para que se logre ver la distancia en la consola
}
