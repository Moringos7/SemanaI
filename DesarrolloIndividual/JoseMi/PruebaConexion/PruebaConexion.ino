#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "semanai-4ea99.firebaseio.com"
#define FIREBASE_AUTH "az4SQ6BPBqScFTFzeciectZz71Axmmc6XlDvEyHJ"
#define WIFI_SSID "Tec-IoT"
#define WIFI_PASSWORD "spotless.magnetic.bridge"

//#define WIFI_SSID "rover"
//#define WIFI_PASSWORD "12345678"

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wifi Conectado!");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
}

void loop() {
  Firebase.setInt("foco", 6);
  delay(500);
  Serial.println("Enviado");

}
