#include <Filters.h> //Easy library to do the calculations
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

float testFrequency = 50;  // test signal frequency (Hz)

int Sensor = 0; //Sensor analog input, here it's A0
int relay = 9;  //Define output pin for relay

float intercept = 0.7; // To be adjusted based on calibration testing
float slope = 0.04; // To be adjusted based on calibration testing
float current_Volts; // Voltage

unsigned long printPeriod = 1000; //Refresh rate
unsigned long previousMillis = 0;


void setup() 
{
  lcd.init();
  lcd.backlight();
  pinMode(relay, OUTPUT);
  lcd.print("Voltage:");
  delay(1000);

}

void loop() 
{
  RunningStatistics inputStats;                // Easy life lines, actual calculation of the RMS requires a load of coding

  while ( true ) 
  {
    Sensor = analogRead(A0);  // Read the analog in value:
    inputStats.input(Sensor);  // Log to stats function

    if ((unsigned long)(millis() - previousMillis) >= printPeriod) 
    {
      previousMillis = millis();   // Update time every second

      current_Volts = intercept + slope * inputStats.sigma(); // Calibartions for offset and amplitude
      current_Volts = current_Volts * (40.3231);             // Further calibrations for the amplitude

      lcd.setCursor(9, 0);
      lcd.print(current_Volts);
      
      lcd.print("V");
    }
    // Case 1 Under Voltage
    if ( (current_Volts > 0)  &&  (current_Volts < 150) )
  {
    lcd.setCursor(0, 1);
    lcd.print("Under Voltage");
    digitalWrite(relay, LOW);
  }
  // Case 2 Normal Rated Voltage
  if ( (current_Volts >= 150)  &&  (current_Volts <= 260) )
  {
    lcd.setCursor(0, 1);
    lcd.print("Normal Voltage");
    digitalWrite(relay, HIGH);
  }
  // Case 3 Over Voltage
  if ( current_Volts > 260 )
  {
    lcd.setCursor(0, 1);
    lcd.print("Over Voltage");
    digitalWrite(relay, LOW);
  }
  }
}
