float corriente = 0.0;
float R=100;
float gain=1;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
for(int i=1;i<=20;i++){
  corriente= (float) analogRead(0)*(5/1023.0)/R+corriente;
  delay(2);
}
Serial.print(corriente*1000/(gain*20),3); //3 es numero de decimales
Serial.println(" mA");
delay(30);
corriente=0;




}
