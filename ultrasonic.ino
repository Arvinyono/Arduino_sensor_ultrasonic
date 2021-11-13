/* 
   PRAKTEK MENGGUNAKAN ARDUINO DENGAN SENSOR ULTRASONIC
   DAN LCD 16 X 2
   Echo ke pin 13
   trig ke pin 12
   SDA ke pin A4
   SCL ke pin A5
*/

#include <UltraDistSensor.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

UltraDistSensor sensorku;
int hasil;

void setup() {
    lcd.init();                      // initialize the lcd 
    lcd.backlight();
    Serial.begin(9600);
    sensorku.attach(12,13);//Trigger pin , Echo pin
}

void loop() {
    hasil=sensorku.distanceInCm();
     lcd.setCursor(0,0);
     lcd.print("Pengukur jarak");
     lcd.setCursor(1,0);
     lcd.print("Dalam S. Cm: ");
     lcd.print(hasil);
     //lcd.print("Cm");

    delay(1000);
}