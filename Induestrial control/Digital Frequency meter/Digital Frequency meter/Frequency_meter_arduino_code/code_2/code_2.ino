
#define ZVC 2
int x = 0;
unsigned long ct = 0;
unsigned long pt = 0;



void setup()
{
  Serial.begin(9600);

}

void loop()
{
  attachInterrupt(0, acon, FALLING);
  ct = millis();

  if (ct - pt > 1000)
  {
    Serial.println(x / 2);
    x = 0;
    pt = ct;
  }




}
void acon(){
  x++;
}
