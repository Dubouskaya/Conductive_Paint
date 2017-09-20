//VARIABLES
// the lowest and highest readings you get from light sensor:
const int sensorMin = 0;   // sensor minimum, discovered through experiment
const int sensorMax = 25;  // sensor maximum, discovered through experiment
const int sensorPin = A0;

int range = 0;
int allStates = 255*3;
float rangePerState = 0;

const int ledR = 9;
const int ledG = 10;
const int ledB = 11;

int colorValue = 0;

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication:
  Serial.begin(9600);

//  pinMode(ledR, OUTPUT); 
//  pinMode(ledG, OUTPUT); 
//  pinMode(ledB, OUTPUT); 

  range = (sensorMax-sensorMin)*100;
  rangePerState = range/allStates;
  Serial.println(rangePerState);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the sensor:
  int sensorReading = analogRead(sensorPin);
  //Serial.print("Sensor: ");
  //Serial.println(sensorReading);

//  R = 255 - valueR;
//  G = 255 - valueG;
//  B = 255 - valueB;


  analogWrite(ledR, 255);
  analogWrite(ledG, 0);
  analogWrite(ledB, 0);
    
  delay(1);
}
