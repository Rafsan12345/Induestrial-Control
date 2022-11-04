
const int redPin = 8;
const int greenPin = 9;
const int bluePin = 10;
#include "DHT.h"

#define DHTPIN 2     
#define DHTTYPE DHT11   


DHT dht(DHTPIN, DHTTYPE);
int state1 = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;

void setup() {

  pinMode(redPin,   OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin,  OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, HIGH);
  //Serial.println(F("DHTxx test!"));

  dht.begin();

  
}

void loop() {

  if (Serial.available() > 0) {
      char comdata = char(Serial.read());
      
    if (comdata == 'R') {
      
      
      digitalWrite(redPin, state1);
      state1 = !state1;
    }
  


    
    else if (comdata == 'G' ) {
      
      digitalWrite(greenPin, state2);
      state2 = !state2;
    }
 
    
    
    else if (comdata == 'B') {
      
      digitalWrite(bluePin, state3);
      state3 = !state3;
    }
    
   
    else if (comdata == 'O') {
      
      digitalWrite(redPin, state4);
      digitalWrite(greenPin, state4);
      digitalWrite(bluePin, state4);
      state4 = !state4;
    }

//m 
else if (comdata == 'T') {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println(t);
  
  
}

else if (comdata == 'H') {
  
  float h = dht.readHumidity();
  
  Serial.println(h);
  
  
}











    
    
  }
}
