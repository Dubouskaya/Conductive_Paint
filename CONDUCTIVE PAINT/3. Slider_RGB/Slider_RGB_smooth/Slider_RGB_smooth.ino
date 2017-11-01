//VARIABLES
// the lowest and highest readings you get from light sensor:
const int sensorMin = 0;   // sensor minimum, discovered through experiment
const int sensorMax = 1023;  // sensor maximum, discovered through experiment
const int sensorPin = A0;
const int bufferValue = 200;

const int ledR = 9;
const int ledG = 10;
const int ledB = 11;

const int allStates = 255*2;
const int States6 = allStates/6; 

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  // read the sensor:
  int sensorReading = analogRead(sensorPin);

  // map the sensor range to a range of 8 options:
  int colorState = map(sensorReading, sensorMin, sensorMax, 0, allStates);
  Serial.println(colorState);

  //reset colors
  analogWrite(ledR, 0);
  analogWrite(ledG, 0);
  analogWrite(ledB, 0);
  
  // do something different depending on the range value  
  if(colorState > 0-bufferValue && colorState <= 0){
    analogWrite(ledR, 255);
  }
  if(colorState > 0 && colorState <= allStates/2){ //255
    analogWrite(ledR, 255-colorState);
    analogWrite(ledG, colorState);
  }
  else if(colorState > allStates/2 && colorState <= allStates){//510
    analogWrite(ledG, 255-(colorState-255));
    analogWrite(ledB, colorState-255);
  }
//  else if(colorState > 510 && colorState <= 765){//765 -> if allStates = 256*3; 
//    analogWrite(ledB, colorState-510);
//    analogWrite(ledR, 255-(colorState-510));
//  }
  if(colorState > allStates && colorState <= allStates+bufferValue){
    analogWrite(ledB, 255);
  }
  else if(colorState > allStates+bufferValue || colorState <= 0-bufferValue){
    analogWrite(ledR, 255);
    analogWrite(ledG, 255);
    analogWrite(ledB, 255);
  }
  
  
    
  delay(1);
}
