//Definición de variables
float data_1;
float data_2;
float data_3;
void setup() {
  // Inicializa la comunicación serial
  Serial.begin(115200);
}

// Lazo principal
void loop() {
if (Serial.available()>0){
  data_1 = Serial.parseFloat();
  data_2 = Serial.parseFloat();
  data_3 = Serial.parseFloat();
  Serial.print(data_1);
  Serial.print(',');
  Serial.print(data_2);
  Serial.print(',');
  Serial.println(data_3); // solo el ultimo va con println
}
}
