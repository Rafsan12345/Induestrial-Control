#include <LiquidCrystal_I2C.h>
#include "ACS712.h"
#include <IRremote.h>
#include<EEPROM.h>
ACS712 sensor(ACS712_05B, A0);
//ACS712_05B
//ACS712_20A for 20 Amp type
//ACS712_30A for 30 Amp type

float I = 0;
float cc = 0;
float data = 0;
int pp = 0;
int pin = 7;
int pin2 = 8;
int pin3 = 9;
int pin4 = 4;
int ccc = 0;
int bbb = 0;
int hh = 0;
int self = 0;
float picup_current = 0; // intial cosidering current for controlling
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x3F for a 16 chars and 2 line display
void setup() {
  digitalWrite(10, HIGH);
  lcd.init(); // lcd display initialize
  lcd.clear();// display clearing
  lcd.backlight();    // Make sure backlight is o
  pinMode(pin, INPUT); //  "
  pinMode(pin2, INPUT); // "
  pinMode(pin3, INPUT); // "
  pinMode(pin4, INPUT); // "
  pinMode(2, OUTPUT);// green indecator
  pinMode(3, OUTPUT); // blue indecator
  pinMode(6, OUTPUT); // red indecator
  pinMode(5, OUTPUT); // relay coil
  pinMode(10, OUTPUT); //rst
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  sensor.calibrate();
  Serial.begin(9600);
  delay(500);

}

void loop() {

  unsigned long sec = millis();
  sec = sec / 1000;
  int input = digitalRead(pin); //++
  int input2 = digitalRead(pin2); // --
  int input3 = digitalRead(pin3); // reset
  int input4 = digitalRead(pin4); // set
  I = sensor.getCurrentAC();
  //ignoring the value below 0.09
  if (I < 0.09) {
    I = 0;
  }
  lcd.setCursor(0, 1);
  lcd.print("Current >");
  lcd.print(I);
  lcd.print("A");
  //Serial.println(I);
  lcd.setCursor(0, 0);
  lcd.print("Pickup C>");
  lcd.print(cc);
  lcd.print("A");



  // "Increasing" section
  if (input == 1 && ccc == 0 )
  {
    cc = cc + 0.25;
    cc = cc;
    ccc = !ccc;

  }

  else if (input == 0 && ccc == 1 )
  {
    ccc = 0;
  }

  // "Decreasing" section
  else if (input2 == 1 && bbb == 0 && cc > 0)
  {
    cc = cc - 0.25;
    bbb = !bbb;
  }

  else if (input2 == 0 && bbb == 1 )
  {
    bbb = 0;
  }

  // "Reset" section

  else if (input3 == 1 &&  hh > 0)
  {


    digitalWrite(5, HIGH); // relay off
    digitalWrite(6, HIGH); // red led on
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    picup_current = cc;
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("<<RESET>>");
    lcd.setCursor(4, 1);
    lcd.print("<<RESET>>");
    delay(1000);
    digitalWrite(10, LOW);
    hh = 0;
    cc = 0;
  }

  // auto
  else if (I > picup_current && hh > 0)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Fault Detect");
    lcd.setCursor(0, 1);
    lcd.print("Wait 3 SEC");
    //Serial.print(I);
    delay(3000);
    check();

  }






















  // "SET" section

  else if (input4 == 1 && cc > 0 )
  {
    picup_current = cc;
    float fg = map(picup_current * 100, 0, 500, 0, 255);
    EEPROM.write('L1', fg);
    digitalWrite(5, LOW); // relay on
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(2, HIGH ); // green led  on
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("<<SET>>");
    lcd.setCursor(5, 1);
    lcd.print("<<SET>>");
    delay(1000);
    hh = 5;
  }

  // self Decission section
  else if ( sec >= 20 && sec <= 30 && hh == 0 && self == 0 )
  {
    data = EEPROM.read('L1');
    Serial.println(data);
    data = map(data, 0, 255, 0, 500);
    cc = data / 100;
    picup_current = cc + 0.20;
    digitalWrite(5, LOW); // relay on
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(2, HIGH ); // green led  on
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("<<SET>>");
    lcd.setCursor(5, 1);
    lcd.print("<<SET>>");
    delay(1000);
    self = 5;
    hh = 5;
  }







  else
  {

  }

}

void check()
{
I = sensor.getCurrentAC();
  if (I > picup_current)
  {
    //Serial.print("YES");
    digitalWrite(5, HIGH); // relay off
    digitalWrite(6, HIGH); // red led on
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    picup_current = cc;
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("<<RESET>>");
    lcd.setCursor(4, 1);
    lcd.print("<<RESET>>");
    delay(1000);
    digitalWrite(10, LOW);
    hh = 0;
    cc = 0;
  }

  else
  {
Serial.print("NO");
  }
}
