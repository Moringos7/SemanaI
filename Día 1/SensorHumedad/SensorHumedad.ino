#include "DHT.h"
#define DHTTYPE DHT11
#define dht_dpin 15
DHT dht(dht_dpin, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
  Serial.println("HUMEDAD Y TEMPERATURA\n\n");
  delay(700);
}

void loop() {
  // put your main code here, to run repeatedly:
  float h= dht.readHumidity();
  float t= dht.readTemperature();
  Serial.print("Humedad = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("Temperatura = ");
  Serial.print(t);
  Serial.println("°C");
  delay(800);
}
