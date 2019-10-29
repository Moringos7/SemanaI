#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "reto-2-semana-i.firebaseio.com"
#define FIREBASE_AUTH "jlxVNTxKAmwMtP1lcQMGzXnkjJuZtpohEcezGxvm"
#define WIFI_SSID "Tec-IoT"
#define WIFI_PASSWORD "spotless.magnetic.bridge"



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("");
  Serial.print("Wifi Connected");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.setInt("Foco",1);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int luz=analogRead(A0);
  luz=map(luz,650,10,100,0);
  Serial.println(luz);
}
