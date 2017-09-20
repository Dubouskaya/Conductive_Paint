//VARIABLES
// the lowest and highest readings you get from light sensor:
const int sensorMin = 0;   // sensor minimum, discovered through experiment
const int sensorMax = 25;  // sensor maximum, discovered through experiment
const int sensorPin = A0;

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the sensor:
  int sensorReading = analogRead(sensorPin);
  Serial.print("Sensor: ");
  Serial.println(sensorReading); 
  
  delay(1);
}





//****************************************************************
//LIBRARY
  //#include "pitches.h"


//VARIABLE
  // const int speakerPin = 3;


//INSIDE THE LOOP
  /*
  // map the sensor range to a range of 8 options:
  int range = map(sensorReading, sensorMax, sensorMin, 0, 8);
  // do something different depending on the range value
  switch (range) {
    case 0:
      noTone(speakerPin);
      break;
    case 1:
      //tone(pin, frequency (hertz), duration(ms))
      tone(speakerPin, NOTE_C4, 10);
      break;
    case 2:
      tone(speakerPin, NOTE_D4, 10);
      break;
    case 3:
      tone(speakerPin, NOTE_E4, 10);
      break;
    case 4:
      tone(speakerPin, NOTE_F4, 10);
      break;
    case 5:
      tone(speakerPin, NOTE_G4, 10);
      break;
    case 6:
      tone(speakerPin, NOTE_A4, 10);
      break;
    case 7:
      tone(speakerPin, NOTE_B4, 10);
      break;
    case 8:
      tone(speakerPin, NOTE_C5, 10);
      break;
  }
  */


