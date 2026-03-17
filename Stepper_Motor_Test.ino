// Define stepper motor connections and steps per revolution:
#include <SPI.h>
#include <AccelStepper.h>
const int redButton = 2;
const int yellowButton = 3;
const int dirPin = 4;
const int stepPin = 5;
const int stepsPerRevolution = 200;

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(redButton,INPUT_PULLUP);
  pinMode(yellowButton,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // Set the spinning direction clockwise:
  

  // Spin the stepper motor 1 revolution slowly:
  
    if(digitalRead(redButton)==LOW){
      digitalWrite(dirPin, HIGH);
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
    }else if(digitalRead(yellowButton)==LOW){
      digitalWrite(dirPin, LOW);
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
    }
  
}



