//LIBRARIES
#include "pitches.h"
#include <CapacitiveSensor.h>

//VARIABLES for BUZZER
// the lowest and highest readings you get from light sensor:

const int sensorMinB = 40;   // CHANGE IT :sensor minimum, discovered through experiment
const int sensorMaxB = 580;  // CHANGE IT :sensor maximum, discovered through experiment
const int sensorPinB = A3; //A1

const int speakerPin = 3;

int speedVar = 100;

//VARIABLES for SENSOR
CapacitiveSensor   cs_6_5 = CapacitiveSensor(1,0);        // 10M resistor between pins 6 & 5, pin 5 is sensor pin, add a wire and or foil if desired
int sensorValue = 0;
int outputValue = 0;
int minCapSensor = 200;
int maxCapSensor = 1600;

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication:
  Serial.begin(9600);
  cs_6_5.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   
}

void loop() {
  
  long start = millis();
  long total1 =  cs_6_5.capacitiveSensor(30);
  sensorValue = total1;
  Serial.print("CAP SENSOR: ");
  Serial.print(sensorValue);
  outputValue = map(sensorValue, minCapSensor, maxCapSensor, 10, 2000);
  if(outputValue <=10){speedVar = 0;}
  else {speedVar = outputValue;}
  // put your main code here, to run repeatedly:
  // read the sensor:
  Serial.print(";  SPEED: ");
  Serial.print(speedVar);
  int sensorReadingB = analogRead(sensorPinB);
  Serial.print(";  SLIDER: ");
  Serial.print(sensorReadingB); 

// map the sensor range to a range of 8 options:
  int range = map(sensorReadingB, sensorMinB, sensorMaxB, 1, 7);
  Serial.print(";  NOTE: ");
  Serial.println(range);
  // do something different depending on the range value
  if(speedVar == 0){noTone(speakerPin);}
  else{
  switch (range) {
    case -1:
      //tone(pin, frequency (hertz), duration(ms))
      tone(speakerPin, NOTE_C4, speedVar);
      break;
    case 0:
      tone(speakerPin, NOTE_C4, speedVar);
      break;
    case 1:
      tone(speakerPin, NOTE_C4, speedVar);
      break;
    case 2:
      tone(speakerPin, NOTE_D4, speedVar);
      break;
    case 3:
      tone(speakerPin, NOTE_E4, speedVar);
      break;
    case 4:
      tone(speakerPin, NOTE_F4, speedVar);
      break;
    case 5:
      tone(speakerPin, NOTE_G4, speedVar);
      break;
    case 6:
      tone(speakerPin, NOTE_A4, speedVar);
      break;
    case 7:
      tone(speakerPin, NOTE_B4, speedVar);
      break;
    case 8:
      tone(speakerPin, NOTE_B4, speedVar);
      break;
    case 9:
      tone(speakerPin, NOTE_B4, speedVar);
      break;
    default: 
      noTone(speakerPin);
      break;
    
  }
  delay(speedVar+500);
  }
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


