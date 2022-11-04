
/*
  USE >> Arduino UNO
  ##Input Pin
  PIN 2 >> Data recive pin fron ir sensor
  ##Output Pin
  PIN 10 >> Action pin
  ##Ir Remote Selection >> Please see in remote Pic from Induestrial Control folder
  power Button >> ON/OFF
 
*/



#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
int state1 = 0;

int Relay = 10;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);
}

void loop() {

  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value


    if (results.value == 0x38863BD2)
    {
      digitalWrite(Relay, state1);
      state1 = !state1;
    }





  }


}
