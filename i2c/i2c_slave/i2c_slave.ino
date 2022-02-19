#include <Wire.h>

unsigned long int x = 0;

void setup() {
  Wire.begin(8);
  Wire.onRequest(sendFunc);
  Wire.onReceive(getFunc);
  Serial.begin(9600);
}

void loop() {
  Serial.print(x);
  Serial.print(" ");
  delay(100);
}

void sendFunc(){
  Wire.write("hello from slave");
  x++;
}

void getFunc(){
  while (Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
}
