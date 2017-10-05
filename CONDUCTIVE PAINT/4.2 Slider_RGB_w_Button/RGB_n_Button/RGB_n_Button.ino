//LIBRARIES
#include <CapacitiveSensor.h>

//VARIABLES _ RGB
// the lowest and highest readings you get from light sensor:
const int sensorMinRGB = 405;   // sensor minimum, discovered through experiment
const int sensorMaxRGB = 430;  // sensor maximum, discovered through experiment
const int sensorPin = A0;
const int bufferValue = 200;

const int ledR = 9;
const int ledG = 10;
const int ledB = 11;

const int allStates = 256*2;
const int States6 = allStates/6; 

//VARIABLES _ BUTTON
CapacitiveSensor   cs_8_7 = CapacitiveSensor(8,7);        // 10M resistor between pins 8 & 7, pin 7 is sensor pin, add a wire and or foil if desired
int sensorValue = 0;
int buttonPressed = 400;

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication:
  Serial.begin(9600);

  cs_8_7.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
}


void loop() {


  long start = millis();
  long total1 =  cs_8_7.capacitiveSensor(30);
  sensorValue = total1;
  Serial.println(sensorValue);
  
  // put your main code here, to run repeatedly:
  // read the sensor:

  if(sensorValue >= buttonPressed){
        int sensorReading = analogRead(sensorPin);
      
        // map the sensor range to a range of 8 options:
        int colorState = map(sensorReading, sensorMinRGB, sensorMaxRGB, 0, allStates);
        //Serial.println(sensorReading);
        //reset colors
        analogWrite(ledR, 255);
        analogWrite(ledG, 255);
        analogWrite(ledB, 255);
        
        // do something different depending on the range value  
        if(colorState > 0-bufferValue && colorState <= 0){
          analogWrite(ledR, 0);
        }
        if(colorState > 0 && colorState <= allStates/2){ //255
          analogWrite(ledR, colorState);
          analogWrite(ledG, 255-colorState);
        }
        else if(colorState > allStates/2 && colorState <= allStates){//510
          analogWrite(ledG, colorState-255);
          analogWrite(ledB, 255-(colorState-255));
        }
      //  else if(colorState > 510 && colorState <= 765){//765 -> if allStates = 256*3; 
      //    analogWrite(ledB, colorState-510);
      //    analogWrite(ledR, 255-(colorState-510));
      //  }
        if(colorState > allStates && colorState <= allStates+bufferValue){
          analogWrite(ledB, 0);
        }
        else if(colorState > allStates+bufferValue || colorState <= 0-bufferValue){
          analogWrite(ledR, 0);
          analogWrite(ledG, 0);
          analogWrite(ledB, 0);
        }
        
  }
  
    
  delay(1);
}
