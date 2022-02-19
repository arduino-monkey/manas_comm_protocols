#include <SPI.h>

void setup() {
  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop() {
  int sensorValue = analogRead(A0);

  digitalWrite(SS, LOW);
  SPI.transfer(map(sensorValue, 0, 1023, 0, 255));
  digitalWrite(SS, HIGH);

  delay(10);
}
