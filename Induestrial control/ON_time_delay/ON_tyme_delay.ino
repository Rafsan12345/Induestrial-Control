/*
  USE >> Arduino UNO
  ##Input Pin (Connect with pull down resistor)
  PIN 7 >> ++
  PIN 8 >> --
  PIN 9 >> SET
  PIN 4 >> RESET
  ##Output Pin
  PIN 5 >> Load
  ##Operation
  <<on time delay>>
*/
int pp, cc = 0;
int pin = 7;
int pin2 = 8;
int pin3 = 9;
int pin4 = 4;
int output = 5;
int ccc = 0;
int bbb = 0;

void setup() {
  pinMode(pin, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(output, OUTPUT);
  Serial.begin(9600);
  digitalWrite(5, LOW);
}

void loop() {

  int input = digitalRead(pin); // ++++
  int input2 = digitalRead(pin2); //----
  int input3 = digitalRead(pin3); // set
  int input4 = digitalRead(pin4); // reset
  Serial.println(cc);
  int v = cc;
  if (input == 1 && ccc == 0)
  {

    cc++;

    ccc = !ccc;
  }

  else if (input == 0 && ccc == 1 )
  {
    ccc = 0;
  }

  //  dec
  else if (input2 == 1 && bbb == 0 )
  {
    cc--;

    bbb = !bbb;
  }

  else if (input2 == 0 && bbb == 1 )
  {
    bbb = 0;
  }

  // dec

  // reset
  else if ( input4 == 1)
  {
    cc = 0;
    digitalWrite(5, LOW);

  }
  // set
  else if (input3 == 1 && cc > 0)
  {

    digitalWrite(5, LOW);
    delay(v * 1000);
    digitalWrite(5, HIGH);



  }


  else
  {

  }
}
