void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int j=0;j<360;j++){
  Serial.println(sin(j*(PI/180)));
  Serial.println("0");
}

}
