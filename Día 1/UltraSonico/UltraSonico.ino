/*#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "semanai-4ea99.firebaseio.com"
#define FIREBASE_AUTH "az4SQ6BPBqScFTFzeciectZz71Axmmc6XlDvEyHJ"
#define WIFI_SSID "Tec-IoT"
#define WIFI_PASSWORD "spotless.magnetic.bridge"*/

int disparador = 2;
int entrada = 0;

void setup(){
  pinMode(disparador,OUTPUT);
  pinMode(entrada,INPUT);
  Serial.begin(9600);
  Serial.println("Hola");
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
