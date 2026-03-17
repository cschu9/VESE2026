#include <SPI.h>
#include <AccelStepper.h>

const int RED_BUTTON = 2; //downshift button
const int YELLOW_BUTTON = 3; //upshift button
volatile int YELLOW_STATE = LOW;

void setup() {
  pinMode(RED_BUTTON,INPUT_PULLUP);
  pinMode(YELLOW_BUTTON,INPUT_PULLUP);
  Serial.begin(9600);
}
 
void loop() {
  if(digitalRead(RED_BUTTON)==LOW){
    Serial.println("RED ON!");
  } 
  if(digitalRead(YELLOW_BUTTON)==LOW){
    Serial.println("YELLOW ON!");
  }
}




