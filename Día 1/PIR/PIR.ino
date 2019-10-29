int led = 12;
int sensor = 13;


void setup() {
  pinMode(sensor, INPUT); //Declaración del sensor  como entrada
  pinMode(led, OUTPUT); //Declaración del Led como salida
  Serial.begin(9600);
}

void loop(){
  long state = digitalRead(sensor);
  delay(1000);
  if(state == HIGH){
    digitalWrite (led, HIGH);
    Serial.println("Movimiento detectado");
  }else{
    digitalWrite (led, LOW);
    Serial.println("Sin movimiento");
  }
}
