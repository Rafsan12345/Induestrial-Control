

// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
      

// variables:
int v = 0;
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value


void setup() {
  // turn on LED to signal the start of the calibration period:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

 digitalWrite(6,HIGH);
 digitalWrite(7,HIGH);
 digitalWrite(8,HIGH);
 digitalWrite(9,HIGH);

  
  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  // signal the end of the calibration period
  digitalWrite(13, LOW);
}

void loop() {
  int maxx = sensorMax;
  int mainn = sensorMin;
  sensorValue = analogRead(sensorPin);
  int i = map(sensorValue, sensorMin, sensorMax, 0, 1023);
  v = constrain(i, 0, 1023);
  
    if (v  > 100 && v < 250 ) 
{ 
  
digitalWrite(6,LOW);

}




else if ( i  > 1020 ) 
{ 

sensorMax = mainn;
sensorMin = maxx;

}

else if ( i == 0 ) 
{ 

sensorMax = maxx;
sensorMin = mainn;


}



else if ( v  > 270 && v < 410 ) 
{ 
digitalWrite(7,LOW);

}


else if ( v  > 430 && v < 570 ) 
{ 
digitalWrite(8,LOW);

}


else if ( v  > 590 && v < 730 ) 
{ 
digitalWrite(9,LOW);

}





else if ( v  > 800 && v < 950 ) 
{ 
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
}





else
{
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH); 
digitalWrite(9,HIGH);  
}










  
}
