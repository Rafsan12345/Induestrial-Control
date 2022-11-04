/*
USE >> Arduino UNO
##Input Pin
PIN 2 >> Data recive pin fron ir sensor
##Output Pin
PIN 8 >> Connect Load 1 
PIN 9 >> Connect Load 2
PIN 10 >> Connect Load 3
##Ir Remote Selection >> Please see in remote Pic from Induestrial Control folder 
power Button >> All on /All off   
Button 1 >> Load1 on/off
Button 2 >> Load2 on/off
Button 3 >> Load3 on/off
*/







#include <IRremote.h>
#include<EEPROM.h>
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
  byte value1 = HIGH ;
  byte value2 = HIGH ;
  byte value3 = HIGH ;

int state1=0;
int state2=0;
int state3=0;
int state4=0;

int led1=8;
int led2=9;
int led3=10;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led1,OUTPUT); // in1
  pinMode(led2,OUTPUT); // in2
  pinMode(led3,OUTPUT); // in3
  
}

void loop() {

    if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);    
    irrecv.resume(); // Receive the next value
  
   //1  
    if(results.value == 0x38863BE0)
    {
     digitalWrite(led1,state1);
     EEPROM.write('L1',state1);
     state1 = !state1; 
    }


// 2
    
    else if(results.value == 0x38863BD0)
    {
     digitalWrite(led2,state2);
     EEPROM.write('L2',state2);
     state2 = !state2; 
    }


    // 3
   else if(results.value == 0x38863BF0)
    {
     digitalWrite(led3,state3);
     EEPROM.write('L3',state3);
     state3 = !state3; 
     
    }


///  power on off    
 else if (results.value == 0x38863BD2)
    {
      
     
     digitalWrite(8,state4);
     EEPROM.write('L1',state4);
     digitalWrite(9,state4);
     EEPROM.write('L2',state4);
     digitalWrite(10,state4);
     EEPROM.write('L3',state4);
     state4 = !state4;  
     
    }


    
    }

else
 {

   value1 = EEPROM.read('L1');
   value2 = EEPROM.read('L2');
   value3 = EEPROM.read('L3');
  digitalWrite(led1, value1); 
  digitalWrite(led2, value2); 
  digitalWrite(led3, value3); 
  
  
 }

 

    
    
    


}
