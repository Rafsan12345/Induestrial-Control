int f = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(4, INPUT);// Zero crossing
  pinMode(5,OUTPUT); // plus control
  pinMode(A5,INPUT); // pot input
}

void loop()
{
  int a  = analogRead(A5);
  a = map(a,0,1023,0,400);
  a = constrain(a,0,400); // 0-400 range 


  
  f = digitalRead(4);
  if (f == 1)
  {
    delay(a);
    digitalWrite(5,HIGH);
    delay(500-a);
    digitalWrite(5,LOW);
    
    
  }

  else
  {

  }

}
