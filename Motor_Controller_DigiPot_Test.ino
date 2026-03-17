#include <SPI.h>
#include <AccelStepper.h>

const int RED_BUTTON = 2; //downshift button
const int YELLOW_BUTTON = 3; //upshift button
int throttlePin = A0;
const int CS_PIN = 10;
int val = 0;
 

void setup() {
  pinMode(RED_BUTTON,INPUT_PULLUP);
  pinMode(YELLOW_BUTTON,INPUT_PULLUP);
  Serial.begin(9600);
  SPI.begin();
  SPI.transfer(0x00);
}
 
void loop() {
  //Read physical potentiometer data
  val = analogRead(throttlePin);
  //Byte Conversion
  byte newVal = val/4;
  Serial.print("CONVERSION: ");
  Serial.println(newVal);
  //If button pressed, CUT POWER!! OR FULL THROTLWEEJEw

  int fullThrottle = digitalRead(YELLOW_BUTTON);
  int cutPower = digitalRead(RED_BUTTON);

  if(cutPower == LOW){
    setDigiPot(0);
  }else if(fullThrottle == LOW){
    setDigiPot(255);
  }else{
    setDigiPot(newVal);
  }
}



void setDigiPot(byte value) {
  digitalWrite(CS_PIN, LOW); //selects device
  SPI.transfer(0x00); //clears previous position
 
  SPI.transfer(value);
  digitalWrite(CS_PIN, HIGH); //deselects device
 
  //Serial.print("Potentiometer set to: ");
  Serial.println(value);
}

