/*
USE >> Arduino UNO
##Input Pin
PIN 2 >> Data recive pin from ir sensor
##Output Pin
PIN 8 >> Forward MC
PIN 9 >> Revedrse MC

##Ir Remote Selection >> Please see in remote Pic from Induestrial Control folder 
power Button >> Reverse/forward  
Menu Button >> Stop 
*/


#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
//power=on,menu=off

int state1=1;

int led1=8;
int led2=9;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);

  
}

void loop() {

    if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);    
    irrecv.resume(); // Receive the next value
  
    
    if(results.value == 0x38863BD2)
    {
     int state2 = !state1;
      
     digitalWrite(led1,state1);
     digitalWrite(led2,state2);
      state1 = !state1;
    }




 else if(results.value == 0x38863BDC)
    {
     digitalWrite(led1,HIGH);
     digitalWrite(led2,HIGH);
    }



}



 
    
    
  
  

}
