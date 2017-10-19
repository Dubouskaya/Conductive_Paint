//VARIABLES
// the lowest and highest readings you get from light sensor:

#include "pitches.h"

const int sensorMinB = 0;   // sensor minimum, discovered through experiment
const int sensorMaxB = 1023;  // sensor maximum, discovered through experiment
const int sensorPinB = A3;

const int speakerPin = 3;

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the sensor:
  int sensorReadingB = analogRead(sensorPinB);
  Serial.print("Sensor: ");
  Serial.print(sensorReadingB); 

// map the sensor range to a range of 8 options:
  int range = map(sensorReadingB, sensorMinB, sensorMaxB, 1, 7);
  Serial.print(";  range: ");
  Serial.println(range);
  // do something different depending on the range value
  switch (range) {
    case -1:
      //tone(pin, frequency (hertz), duration(ms))
      tone(speakerPin, NOTE_C4, 100);
      break;
    case 0:
      tone(speakerPin, NOTE_C4, 100);
      break;
    case 1:
      tone(speakerPin, NOTE_C4, 100);
      break;
    case 2:
      tone(speakerPin, NOTE_D4, 100);
      break;
    case 3:
      tone(speakerPin, NOTE_E4, 100);
      break;
    case 4:
      tone(speakerPin, NOTE_F4, 100);
      break;
    case 5:
      tone(speakerPin, NOTE_G4, 100);
      break;
    case 6:
      tone(speakerPin, NOTE_A4, 100);
      break;
    case 7:
      tone(speakerPin, NOTE_B4, 100);
      break;
    case 8:
      tone(speakerPin, NOTE_B4, 100);
      break;
    case 9:
      tone(speakerPin, NOTE_B4, 100);
      break;
    default: 
      noTone(speakerPin);
      break;
    
  }
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


