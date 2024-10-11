int valor;
float voltaje;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
valor = analogRead(0);
voltaje=((float)valor*20.0)/1023.0;//debo poner un .0 para que se haga flotante

Serial.println(voltaje);// LA ULITMA ES LN

}
