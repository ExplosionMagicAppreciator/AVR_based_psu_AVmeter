#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int analogInput = A3; 
  
int ADC = 0;
float voltage = 0.0;
float current = 0.0;
float power = 0.0;
 
void setup(){
   pinMode(analogInput, INPUT);
   lcd.init();
   }

float fmap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void loop() {
   ADC = analogRead(analogInput);
   voltage = fabs(fmap(ADC, 0.0, 1024.0, 0.00, 20.0)); 
   current = voltage * (/);
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
