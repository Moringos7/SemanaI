#include <NewPing.h>

#define PING_PIN  0  // Arduino pin tied to both trigger and echo pins on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

//NewPing sonar(PING_PIN, PING_PIN, MAX_DISTANCE); // NewPing setup of pin and maximum distance.
int distancia = 0;

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
   Serial.println("Hola");
   distancia = sonar.ping_cm();
   Serial.println(distancia);
   delay(500);
}
