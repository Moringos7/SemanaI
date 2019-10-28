int disparador = 2;
int entrada = 0;

void setup(){
  pinMode(disparador,OUTPUT);
  pinMode(entrada,INPUT);
  Serial.begin(9600);
}

void loop(){
  long tiempo;
  float distancia;

  digitalWrite(disparador,HIGH);
  delayMicroseconds(10);
  digitalWrite(disparador,LOW);

  tiempo = (pulseIn(entrada,HIGH)/2);
  distancia = float(tiempo * 0.0343);

  Serial.println(distancia);
  delay(300);
}
