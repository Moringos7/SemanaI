#include <LiquidCrystal_I2C.h>


//Se crea el objeto LCD direccion en la direccion de memoria y en columas y filas
LiquidCrystal_I2C lcd(0x3F, 20,4);

void setup() {
  Serial.begin(9600);
  //Inicializar el lcd
  lcd.begin();

  //Encender la luz de fondo
  lcd.backlight();

  //Limpiar la pantalla
  lcd.clear();

  lcd.home();
  lcd.setCursor(2,2);
  lcd.print("Hola Mundo");
}

void loop() {
  // put your main code here, to run repeatedly:

}
