
/*
  USE >> Arduino UNO
  ##Input Pin(Connect push button with pull down resistor)
  PIN 7 >> Increasing ++
  PIN 8 >> Decreasing --
  PIN 9 >> RESET
  PIN 4 >> SET
  
*/

int pp, cc = 0;
int pin = 7;
int pin2 = 8;
int pin3 = 9;
int pin4 = 4;
int ccc = 0;
int bbb = 0;

void setup() {
  pinMode(pin, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);

  Serial.begin(9600);

}

void loop() {

  int input = digitalRead(pin);
  int input2 = digitalRead(pin2);
  int input3 = digitalRead(pin3);
  int input4 = digitalRead(pin4);
  Serial.println(cc);
  //Increasing
  if (input == 1 && ccc == 0)
  {

    cc++;

    ccc = !ccc;
  }

  else if (input == 0 && ccc == 1 )
  {
    ccc = 0;
  }

  //Decreasing
  else if (input2 == 1 && bbb == 0 )
  {
    cc--;

    bbb = !bbb;
  }

  else if (input2 == 0 && bbb == 1 )
  {
    bbb = 0;
  }

  //Reset

  else if (input3 == 1 )
  {
    Serial.print("RESET");
    pp = 0 ;
    cc  = 0 ;
    ccc  = 0 ;
    bbb = 0 ;
  }

  // SET

  else if (input4 == 1 )
  {
    //Statement
    Serial.print("SET");
  }



  else
  {

  }
}
