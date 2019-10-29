#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "reto-2-semana-i.firebaseio.com"
#define FIREBASE_AUTH "jlxVNTxKAmwMtP1lcQMGzXnkjJuZtpohEcezGxvm"
#define WIFI_SSID "Tec-IoT"
#define WIFI_PASSWORD "spotless.magnetic.bridge"

int ledPin = 12;
int botonPin = 10;
void setup() {
  Serial.begin(9600);
  pinMode(botonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("");
  Serial.print("Wifi Connected");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  
}

void loop() {
  if(digitalRead(botonPin) == 0){
    Serial.println("Boton 1 == 1");
      digitalWrite(ledPin, HIGH);
      Firebase.setInt("Led",1);
  }else{
    Serial.println("Boton 1 == 0");
    digitalWrite(ledPin, LOW);
    Firebase.setInt("Led",0);
  }
  
}
