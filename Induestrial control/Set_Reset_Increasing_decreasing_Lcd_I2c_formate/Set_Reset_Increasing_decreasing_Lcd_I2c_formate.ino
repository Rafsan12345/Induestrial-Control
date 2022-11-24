#include <LiquidCrystal_I2C.h>
float cc = 0;
int pp =  0;
int pin = 7;  // ++
int pin2 = 8; // --
int pin3 = 9; // set
int pin4 = 4; // reset
int ccc = 0;
int bbb = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {


  int input = digitalRead(pin); //++
  int input2 = digitalRead(pin2); // --
  int input3 = digitalRead(pin3); // reset
  int input4 = digitalRead(pin4); // set
  lcd.setCursor(0, 1);
  lcd.print("ABCD");
  Serial.println("I");




  // "Increasing"
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

  // "Decreasing"
  else if (input2 == 1 && bbb == 0 && cc > 0)
  {
    cc = cc - 0.25;
    bbb = !bbb;
  }

  else if (input2 == 0 && bbb == 1 )
  {
    bbb = 0;
  }

  // "Reset"

  else if (input3 == 1 )
  {
    pp = 0 ;
    cc  = 0 ;
    ccc  = 0 ;
    bbb = 0 ;

    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("<<RESET>>");
    lcd.setCursor(4, 1);
    lcd.print("<<RESET>>");
    delay(1000);
  }

  // "SET"

  else if (input4 == 1 && cc > 0 )
  {

    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("<<SET>>");
    lcd.setCursor(5, 1);
    lcd.print("<<SET>>");
    delay(1000);
  }

  else
  {

  }

}
