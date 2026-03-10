#include <SPI.h>
#include <AccelStepper.h>



const int RED_BUTTON = 2; //downshift button
const int YELLOW_BUTTON = 3; //upshift button
const int CS_PIN = 10;
const int potPin = A0;

int previousState;
int rpm = 800;
unsigned int previousTimeDiff = 1000;
const int detectionState = LOW; //CHNAGE TO HIGH ONCE PULL DOWN RESISTOR WORKS YAY
const int readsPerRotation = 3; //Number of magnets on drive shaft/motor (Divide by this number to get RPM)
const int hallEffectPin = 2; //Hall effect sensor INPUT
unsigned long lastRevolutionTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(YELLOW_BUTTON, INPUT);
  pinMode(RED_BUTTON, INPUT);
  pinMode(hallEffectPin, INPUT);
  lastRevolutionTime = millis();
  previousState = HIGH;

  SPI.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int currentState = digitalRead(hallEffectPin);

  byte Analog_To_Digital = 2 * analogRead(potPin);

  //setDigiPot(Analog_To_Digital);

  int num = 500;
  setDigiPot(num);

  Serial.println(num);





  if(digitalRead(RED_BUTTON) == HIGH)
  {
    //Serial.println("Red");
  }

  else if(digitalRead(YELLOW_BUTTON) == HIGH)
  {
    Serial.println("YELLOW");
  }
delay(1000);
  
}

int setDigiPot(byte value) {
  Serial.print("Potentiometer set to: ");
  Serial.println(value);

  digitalWrite(CS_PIN, LOW); //selects device
  SPI.transfer(0x00); //clears previous position
 
  SPI.transfer(value);
  digitalWrite(CS_PIN, HIGH); //deselects device
 
  //Serial.print("Potentiometer set to: ");
  //Serial.println(value);
}

int getDSRPM(bool isTriggered){
  int rpm;
  int timeDiff;

  if(isTriggered)
  {
    timeDiff = millis() - lastRevolutionTime;
    lastRevolutionTime=millis();
    previousTimeDiff = timeDiff;
    rpm = ((1000/(double)timeDiff) * 60) / readsPerRotation;
    Serial.println(rpm);
    return rpm;
  }
  else
  {
    rpm = ((1000/(double)(previousTimeDiff + (millis() - lastRevolutionTime))) * 60) / readsPerRotation;
    Serial.println(rpm);
  }
}

