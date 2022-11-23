#define BUTTON_PIN 4
float  cc =0;
void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
  unsigned long duration = pulseIn(BUTTON_PIN, LOW);
  cc = (duration*2)*0.000001;
  Serial.println(1/cc);
}
