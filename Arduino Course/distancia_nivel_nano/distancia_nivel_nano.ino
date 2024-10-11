#define Pecho 6
#define Ptrig 7
long duracion, distancia, d, m, b;   
int lvlmin=5, lvlmax=30, aux;

void setup() {
  // put your setup code here, to run once:
 Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  digitalWrite(Ptrig, LOW);
  pinMode(3, OUTPUT);            // Define el pin 13 como salida
  
}

void loop() {
 
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;     
  d=duracion/59;
  if (d>lvlmin&&d<lvlmax){
  aux=map (d,0,lvlmax,0,255);
   analogWrite(3,aux);
    
  }
  
   //Serial.print(distancia);           // envia el valor de la distancia por el puerto serial
   Serial.println(d); 
   //Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
   Serial.println(aux);
   //Serial.println(m);
   //Serial.println(b);

   

  delay(400); 

}
