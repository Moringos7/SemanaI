
int ledPin = 12;
int botonPin = 10;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(botonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if(digitalRead(botonPin) == 0){
    Serial.println("Boton 1 == 1");
      digitalWrite(ledPin, HIGH);
  }else{
    Serial.println("Boton 1 == 0");
    digitalWrite(ledPin, LOW);
  }
  
}
