#include <SPI.h>

//spi lib doesnot support slave func natively

volatile byte data; //volatile used because var changed inside ISR

void setup() {
  pinMode(MISO, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  SPCR |= 1 << SPE; //enable spi
  SPCR |= 1 << SPIE; //If the SPI Interrupt Enable bit (SPIE) in 
                     //the SPCR Register is set, an interrupt is requested
}

void loop() {
  analogWrite(13, data);
  Serial.println(data);
}

ISR (SPI_STC_vect){
  //SPI_STC => spi transfer complete handler
  //interrupt occurs when spi data received
  
  data = SPDR; //get data from the SPDR register
}
