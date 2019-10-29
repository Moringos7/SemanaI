#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "reto-2-semana-i.firebaseio.com"
#define FIREBASE_AUTH "jlxVNTxKAmwMtP1lcQMGzXnkjJuZtpohEcezGxvm"
#define WIFI_SSID "Tec-IoT"
#define WIFI_PASSWORD "spotless.magnetic.bridge"

int disparador = 2;
int entrada = 0;

void setup(){
  pinMode(disparador,OUTPUT);
  pinMode(entrada,INPUT);
  Serial.begin(9600);


  //Conectarse a internet y FireBase
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("");
  Serial.print("Wifi Connected");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
}

void loop(){
  long tiempo;
  float distancia;

  digitalWrite(disparador,HIGH);
  delayMicroseconds(10);
  digitalWrite(disparador,LOW);

  tiempo = (pulseIn(entrada,HIGH)/2);
  distancia = float(tiempo * 0.0343);
  Firebase.setFloat("Distancia",distancia);
  Serial.println(distancia);
  delay(300);
}
