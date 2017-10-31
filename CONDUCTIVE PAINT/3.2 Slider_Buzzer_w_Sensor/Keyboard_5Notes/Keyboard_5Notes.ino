//LIBRARIES
#include "pitches.h"
#include <CapacitiveSensor.h>

//VARIABLES for BUZZER
const int speakerPin = 12;

//VARIABLES for SENSOR
CapacitiveSensor   cs_2_11 = CapacitiveSensor(11, 2);       // 10M resistor between pins 6 & 5, pin 5 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_3_10 = CapacitiveSensor(10, 3);       // 10M resistor between pins 6 & 5, pin 5 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_9 = CapacitiveSensor(9, 4);       // 10M resistor between pins 6 & 5, pin 5 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_5_8 = CapacitiveSensor(8, 5);       // 10M resistor between pins 6 & 5, pin 5 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_6_7 = CapacitiveSensor(7, 6);       // 10M resistor between pins 6 & 5, pin 5 is sensor pin, add a wire and or foil if desired


int sensorValueC = 0;
int sensorValueD = 0;
int sensorValueE = 0;
int sensorValueF = 0;
int sensorValueG = 0;


int minCapSensor = 200;
int maxCapSensor = 1600;


void setup() {
  // put your setup code here, to run once:
  // initialize serial communication:
  Serial.begin(9600);
  cs_2_11.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_3_10.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_4_9.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_5_8.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_6_7.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
}

void loop() {

  long start = millis();
  long totalC =  cs_2_11.capacitiveSensor(30);
  long totalD =  cs_3_10.capacitiveSensor(30);
  long totalE =  cs_4_9.capacitiveSensor(30);
  long totalF =  cs_5_8.capacitiveSensor(30);
  long totalG =  cs_6_7.capacitiveSensor(30);

  sensorValueC = totalC;
  sensorValueD = totalD;
  sensorValueE = totalE;
  sensorValueF = totalF;
  sensorValueG = totalG;


  //  Serial.print("CAP SENSOR: ");
  //  Serial.println(sensorValueC);

  if (sensorValueC <= maxCapSensor && sensorValueC >= minCapSensor) {
    tone(speakerPin, NOTE_C4, 200);
  }
  else if (sensorValueD <= maxCapSensor && sensorValueD >= minCapSensor) {
    tone(speakerPin, NOTE_D4, 200);
  }
  else if (sensorValueE <= maxCapSensor && sensorValueE >= minCapSensor) {
    tone(speakerPin, NOTE_E4, 200);
  }
  else if (sensorValueF <= maxCapSensor && sensorValueF >= minCapSensor) {
    tone(speakerPin, NOTE_F4, 200);
  }
  else if (sensorValueG <= maxCapSensor && sensorValueG >= minCapSensor) {
    tone(speakerPin, NOTE_G4, 200);
  }
  else {
    noTone(speakerPin);
  }

}

