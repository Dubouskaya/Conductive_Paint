#include "pitches.h"
// the lowest and highest readings you get from light sensor:
// sensor minimum, discovered through experiment
const int sensorMin = 80;
// sensor maximum, discovered through experiment
const int sensorMax = 980;
// speaker pin
const int spkPin = 3;

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the sensor:
  int sensorReading = analogRead(A0);
  //Serial.print("Sensor: ");
  Serial.println(sensorReading);
  // map the sensor range to a range of 8 options:
  int range = map(sensorReading, sensorMax, sensorMin, 0, 8);

  // do something different depending on the range value
  switch (range) {
    case 0:
      noTone(spkPin);
      break;
    case 1:
      //tone(pin, frequency (hertz), duration(ms))
      tone(spkPin, NOTE_C4, 10);
      break;
    case 2:
      tone(spkPin, NOTE_D4, 10);
      break;
    case 3:
      tone(spkPin, NOTE_E4, 10);
      break;
    case 4:
      tone(spkPin, NOTE_F4, 10);
      break;
    case 5:
      tone(spkPin, NOTE_G4, 10);
      break;
    case 6:
      tone(spkPin, NOTE_A4, 10);
      break;
    case 7:
      tone(spkPin, NOTE_B4, 10);
      break;
    case 8:
      tone(spkPin, NOTE_C5, 10);
      break;
  }
  delay(1);
}
