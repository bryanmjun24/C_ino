int a;
int c=1;
int ante=1;

void setup() {
  pinMode(2,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  a=digitalRead(2);
  if(a==LOW&&ante==HIGH)
  {
    Serial.println(c);
    c++;
    delay(200);
    }
ante=a;
}
