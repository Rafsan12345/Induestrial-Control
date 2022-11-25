void setup() {
 pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(A5, INPUT); 
}

void loop() {

 int f = analogRead(A5);
 f = map(f,0,1023,10,500);
  f = constrain(f,10,500);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  delay(f);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  delay(f);
  

}
