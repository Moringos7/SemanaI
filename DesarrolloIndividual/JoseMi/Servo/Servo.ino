#include <Servo.h>

Servo servoM;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoM.attach(1);

}

void loop() {
  servoM.write(0);
  Serial.println("0");
  delay(500);
  servoM.write(180);
  Serial.println("180");
  delay(500);
}
