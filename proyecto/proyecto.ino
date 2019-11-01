#include <DHT.h>
#include <DHT_U.h>

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Servo.h>
#define FIREBASE_HOST "semanai-4ea99.firebaseio.com"
#define FIREBASE_AUTH "az4SQ6BPBqScFTFzeciectZz71Axmmc6XlDvEyHJ"
#define WIFI_SSID "Tec-IoT"
#define WIFI_PASSWORD "spotless.magnetic.bridge"

/////Puertos


//sonarFrente
int disparadorF = 2; 
int entradaF = 0;

//sonarAtras
int disparadorA = 12;
int entradaA = 14;

//Temperatura
#define DHTTYPE DHT11
#define dht_dpin 13
DHT dht(dht_dpin, DHTTYPE);

//Led
int foco = 16;

//Ventilador
int ventilador = 15;

//Libreria de LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 20,4);

//Servo

Servo servoM;
///////////////////////////////

void setup() {
  Serial.begin(9600);
  
  //Ultrasonico Declaracion
  pinMode(disparadorF,OUTPUT);
  pinMode(entradaF,INPUT);
  pinMode(disparadorA,OUTPUT);
  pinMode(entradaA,INPUT);
 
  /*WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("");
  Serial.print("Wifi Connected");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
*/
  //Servo
  servoM.attach(1);
  //Inicializar el lcd
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.home();
  //lcd.print("Sistema La Nave");
  //Inicializar el Humedad
  dht.begin(); 
}

void loop() {
  delay(500);
  Serial.println("Hola");
   /*Firebase.setInt("Luz",50);
   delay(1000);
    Firebase.setInt("Luz",100);
    delay(1000);*/
}
