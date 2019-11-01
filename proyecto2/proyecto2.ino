#include <DHT.h>
#include <DHT_U.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Servo.h>
#define FIREBASE_HOST "semanai-4ea99.firebaseio.com"
#define FIREBASE_AUTH "az4SQ6BPBqScFTFzeciectZz71Axmmc6XlDvEyHJ"
//#define WIFI_SSID "rover"
//#define WIFI_PASSWORD "12345678"
#define WIFI_SSID "Tec-IoT"
#define WIFI_PASSWORD "spotless.magnetic.bridge"

int luz = A0;

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

//contServo
int cont = 0;

Servo servoM;
///////////////////////////////
bool abrir = true;
long timeS;
void setup() {
  pinMode(disparadorF,OUTPUT);
  pinMode(entradaF,INPUT);
  pinMode(disparadorA,OUTPUT);
  pinMode(entradaA,INPUT);
  pinMode(ventilador,OUTPUT);
  pinMode(foco,OUTPUT);
  digitalWrite(ventilador,HIGH);
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("");
  Serial.print("Wifi Connected");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  //Servo
  //Inicializar el lcd
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.home();
  //Inicializar el Humedad
  dht.begin(); 
  
}

void loop() {
  ///////Luz
  int lum=analogRead(luz);
  lum=map(lum,650,10,100,0);
  Firebase.setInt("Luz",lum);
  lcd.setCursor(1,3);
  if(lum <= 50){
    digitalWrite(foco,HIGH);
    lcd.print("LUZ ON ");
  }else{
    digitalWrite(foco,LOW);
    lcd.print("LUZ OFF");
  }
  delay(100);
  lcd.setCursor(0,0);
  lcd.print("FRENTE  TEMP  ATRAS");
  //////Frente
  long tiempoF;
  float distanciaF;
  digitalWrite(disparadorF,HIGH);
  delayMicroseconds(10);
  digitalWrite(disparadorF,LOW);
  tiempoF = (pulseIn(entradaF,HIGH)/2);
  distanciaF = float(tiempoF * 0.0343);
   lcd.setCursor(1,1);
  if(distanciaF <= 100){
    Firebase.setFloat("Frente",distanciaF);
    lcd.print(distanciaF);  
    lcd.print(" ");
  }else{
    Firebase.setFloat("Frente",0.0);
    lcd.print("--.--");
  }
  delay(100);
  ///////Atras
  lcd.setCursor(14,1);
  long tiempoA;
  float distanciaA;
  digitalWrite(disparadorA,HIGH);
  delayMicroseconds(10);
  digitalWrite(disparadorA,LOW);
  tiempoA = (pulseIn(entradaA,HIGH)/2);
  distanciaA = float(tiempoA * 0.0343);
  if(distanciaA <= 100){
    Firebase.setFloat("Atras",distanciaA);  
    lcd.print(distanciaA);
    lcd.print(" ");
  }else{
    Firebase.setFloat("Atras",0.0);
    lcd.print("--.--");
  }
  delay(100);
  ///////Temperatura
  //Se tomó el dato de Humedad debido a que la Temperatura
  //tarda mucho en cambiar
  lcd.setCursor(9,1);
  float humedad = dht.readHumidity(); 
  Firebase.setInt("Temperatura",(int)humedad);
  lcd.print((int)humedad);
  delay(100);
  //Obtener estado de carro
  int state = Firebase.getInt("Ventana");
  lcd.setCursor(11,3);
  lcd.print("AIRE ");
  if(state == 1){
    //Activar Servo
    if(abrir){
      timeS = millis() + 4000;
      abrir = false;
      servoM.attach(3);
      servoM.write(0);
    }
    if(timeS < millis()){
      servoM.detach();
    }
    digitalWrite(ventilador,HIGH);
    lcd.print("OFF");
  }else if(state == 0){
    //Activar Aire
    if(!abrir){
      timeS = millis() + 4000;
      abrir = true;
      servoM.attach(3);
      servoM.write(180);
    }
    if(timeS < millis()){
      servoM.detach();
    }
    digitalWrite(ventilador,LOW);
    lcd.print("ON ");
  }else{
    //Apagar Aire y Servo
    if(!abrir){
      timeS = millis() + 4000;
      abrir = true;
      servoM.attach(3);
      servoM.write(180);
    }
    if(timeS < millis()){
      servoM.detach();
    }
    digitalWrite(ventilador,HIGH);
    lcd.print("OFF");
  }
  delay(100);
}
