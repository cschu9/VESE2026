const int readsPerRotation = 2; //Number of magnets on drive shaft/motor (Divide by this number to get RPM)
const int hallEffectPin = 2; //Hall effect sensor INPUT
volatile int rpm = 5;
volatile unsigned int previousTimeDiff = 10;
volatile unsigned long lastRevolutionTime;


void setup() {
  //AttachInterupt Test
  pinMode(hallEffectPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(hallEffectPin), getDSRPM, FALLING);
  lastRevolutionTime = millis();
  Serial.begin(9600);
}

void loop() {
  Serial.println(rpm);
}

void getDSRPM(){
  int timeDiff;
  timeDiff = millis() - lastRevolutionTime;
  lastRevolutionTime=millis();
  previousTimeDiff = timeDiff;
  rpm = ((1000/(double)timeDiff) * 60) / readsPerRotation;

}


