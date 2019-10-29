#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "reto-2-semana-i.firebaseio.com"
#define FIREBASE_AUTH "jlxVNTxKAmwMtP1lcQMGzXnkjJuZtpohEcezGxvm"
#define WIFI_SSID "Tec-IoT"
#define WIFI_PASSWORD "spotless.magnetic.bridge"

int led = 12;
int sensor = 13;

void setup() {
  pinMode(sensor, INPUT); //Declaración del sensor  como entrada
  pinMode(led, OUTPUT); //Declaración del Led como salida
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
  long state = digitalRead(sensor);
  delay(1000);
  if(state == HIGH){
    digitalWrite (led, HIGH);
    Serial.println("Movimiento detectado");
    Firebase.setInt("Movimiento",1);
  }else{
    digitalWrite (led, LOW);
    Serial.println("Sin movimiento");
    Firebase.setInt("Movimiento",0);
  }
}
