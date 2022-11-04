

/*
USE >> Arduino UNO
##Input Pin
PIN 2 >> Data recive pin from ir sensor
##Output Pin
PIN 8 >> Star MC
PIN 9 >> Delta MC
##Ir Remote Selection >> Please see in remote Pic from Induestrial Control folder 
power Button >> on  
Menu Button >> Stop

*/



#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

int state1=1;

int Relay1=8;
int Relay2=9;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(Relay1,OUTPUT);
  pinMode(Relay2,OUTPUT);
  digitalWrite(Relay1,state1);
  digitalWrite(Relay2,state1);
  
}

void loop() {

    if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);    
    irrecv.resume(); // Receive the next value
  
    
    if(results.value == 0x38863BD2)
  
    {
      
     digitalWrite(Relay1,LOW);
     digitalWrite(Relay2,HIGH);
     
     delay(5000);
     digitalWrite(Relay1,HIGH);
     digitalWrite(Relay2,LOW);
      
    }


 else if(results.value == 0x38863BDC )
    {
      digitalWrite(Relay1,HIGH);
      digitalWrite(Relay2,HIGH);
    }

    
  }   
  

}
