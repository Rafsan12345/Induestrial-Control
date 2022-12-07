#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
int ldrPin = A0;
float ldrStatus = 0;

void setup()
{
  lcd.init();
  lcd.clear();
  lcd.backlight();      // Make sure backlight is on
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL, Time, Started Time, Date, temp,Lux");
  Serial.println("LUX Meter");



  dht.begin();
  pinMode(ldrPin, INPUT);
}

void loop()
{
  lcd.clear();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float r2 = 220;
  float ldrStatus = analogRead(ldrPin);
  float v2 = (ldrStatus / 204.6);
  float v1 = (5 - v2);
  float r1 = (v1 * 220) / (5 - v1);
  int lux =  (500 / (r1 / 1000));

  Serial.print("DATA, TIME, TIMER, DATE,");
  Serial.print(t);
  Serial.print(" ,");
  Serial.print(lux);
  Serial.println(" ,");
  
  //delay(1000);



  //Serial.println(ldrStatus);
  lcd.setCursor(1, 0);  //Set cursor to character 2 on line 0
  lcd.print(t);
  lcd.print('C');

  lcd.setCursor(8, 0);  //Set cursor to character 2 on line 0
  lcd.print(h);
  lcd.print('%');
  lcd.setCursor(1, 1);  //Set cursor to character 2 on line 0
  lcd.print("LUX>> ");
  lcd.print(lux);

  delay(500);

}
