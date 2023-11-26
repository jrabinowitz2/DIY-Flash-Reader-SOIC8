#include <SPI.h>
#define RDID 0x90
#define CLOCKRATE 85000000

const int csPin = 10; 
const int mosiPin = 11; 
const int misoPin = 12; 
const int clkPin = 13;

byte transferAndWait (const byte what)
{
  byte a = SPI.transfer (what); 
  delayMicroseconds (20); 
  return a;
}

void setup(){
  Serial.begin(9600);
  Serial.println("Initializating...");
  SPI.begin();
  pinMode(csPin, OUTPUT);
  pinMode(mosiPin, OUTPUT);
  pinMode(misoPin, INPUT);
  pinMode(clkPin, OUTPUT);
  delay(100);
  
  Serial.println("Beginning SPI Transaction...");
  SPI.beginTransaction(SPISettings(CLOCKRATE, MSBFIRST, SPI_MODE0));
  byte a,b,c,d;
  
  //send data (output '9F')
  digitalWrite(csPin,LOW);
  Serial.println("Sending data...");
  
  a = transferAndWait(RDID);
  b = transferAndWait(0x00);
  c = transferAndWait(0x00);
  d = transferAndWait(0x00);
  
  digitalWrite(csPin,HIGH);
  SPI.endTransaction();
  SPI.end();
  
  Serial.println("Received Bytes:");
  //Serial.println(a, HEX);
  Serial.println(b, HEX);
  Serial.println(c, HEX);
  Serial.println(d, HEX);
}

void loop(){
}
