/*
USE >> Arduino UNO
##Input Pin
PIN 8 >>From Generator Side Input DC 5V with pull down resistor
PIN 7 >>From National Supply Side Input DC 5V with pull down resistor
##Output Pin
PIN 6 >>Generator ON/OFF Action PIN
PIN 5 >>National power Supply ON/OFF Action PIN
*/







int L1 = 6;// Relay  IN1  // Generator ON/OFF Action PIN
int L2 = 5; // Relay  IN2 // National power Supply ON/OFF Action PIN



void setup() {
  pinMode(8, INPUT); // Generator >>>>>>Input DC 5V with pull down resistor
  pinMode(7, INPUT); // National Grid Supply >>>>>> Input DC 5V with pull down resistor
  pinMode(L1, OUTPUT); // Generator ON/OFF Action PIN
  pinMode(L2, OUTPUT); // National power Supply ON/OFF Action PIN
  digitalWrite(L1, 1);
  digitalWrite(L2, 1);
}

void loop() {

  int Line1 = digitalRead(8);
  int Line2 = digitalRead(7);



  if (Line1 == LOW && Line2 == LOW )
  {
    delay(5000);
    digitalWrite(L1, 0);
    digitalWrite(L2, 1);
  }


  else if (Line1 == LOW && Line2 == HIGH )
  {

    delay(5000);
    digitalWrite(L1, 1);
    digitalWrite(L2, 0);
  }

  else if (Line1 == HIGH && Line2 == LOW )
  {
    delay(5000);
    digitalWrite(L1, 0);
    digitalWrite(L2, 1);
  }


  else if (Line1 == HIGH && Line2 == HIGH )
  {
    delay(5000);
    digitalWrite(L1, 1);
    digitalWrite(L2, 0);
  }

 else
 {
    digitalWrite(L1, 1);
    digitalWrite(L2, 1);
 }




}
