//unsigned long
 float st =0;

void setup()
{
  Serial.begin(9600);

  pinMode(7, INPUT);
  pinMode(8, INPUT);
}

void loop()
{

 int  f = digitalRead(7);
 //unsigned long 
 int f1 = digitalRead(8);
if (f == HIGH){
   st = millis();
}
else if (f1 == HIGH && st>0){
  float st1 = millis();
  float ff = (st1 - st)/1000;
  ff = (180*ff)/0.01;
  ff = ff *(3.1415926535897932384626433832795/180);
  ff = cos(ff);
  ff = abs(ff);


  
  Serial.println(ff,3);
  delay(10);
  st =0;
  st1 =0;
}



 
 //


}
