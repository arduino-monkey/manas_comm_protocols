#include <Wire.h>

unsigned long int x = 0;
void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  //getting data from slave
  Serial.print(x);
  Serial.print(" ");
  
  Wire.requestFrom(8, 16);
  while (Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
  
  //sending data to slave
  Wire.beginTransmission(8);
  Wire.write("hello from master");
  x++;
  Wire.endTransmission();
  delay(500);
}
