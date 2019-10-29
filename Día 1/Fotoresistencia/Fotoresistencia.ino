void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int luz=analogRead(A0);
  luz=map(luz,650,10,100,0);
  Serial.println(luz);
}
