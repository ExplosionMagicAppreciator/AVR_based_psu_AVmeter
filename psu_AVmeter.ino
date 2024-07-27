#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int voltageAnalogInput = A0;
int CurrentAnalogInput = A1; 
  
int currentADC = 0;
int gain = ;
int maximumCurrent = 5;
float minimumShuntVoltage = ;
float shuntVoltage = 0.0;
float voltage = 0.0;
float current = 0.0;
float power = 0.0;
float R1 = ;
float R2= ;
 
void setup(){
   pinMode(votageAnalogInput, INPUT);
   pinMode(currentAnalogInput, INPUT);
   lcd.init();
   }

float fmap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void loop() {
   currentADC = analogRead(currentAnalogInput);
   voltageADC = analogRead(voltageAnalogInput);
   ShuntVoltage = fabs(fmap(currentADC, 0.0, 1024.0, 0.00, 5.0)); 
   current = shuntVoltage * (maximumCurrent/(minimumShuntVoltage*gain));
   voltage = voltageADC * (5.0/1024)*((R1 + R2)/R2);
   power = voltage * current;
   
   lcd.setCursor(0,0); 
   lcd.print(voltage,3);
   lcd.print("V") 
   lcd.setCursor(7,0);
   lcd.print(current,3);      
   lcd.print("A"); 
   lcd.setCursor(0,1); 
   lcd.print(power,3);
   lcd.print("W")
   delay(500);   
}
