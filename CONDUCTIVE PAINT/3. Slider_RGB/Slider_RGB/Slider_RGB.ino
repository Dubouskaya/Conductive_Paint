//VARIABLES
// the lowest and highest readings you get from light sensor:
const int sensorMin = 0;   // sensor minimum, discovered through experiment
const int sensorMax = 1023;  // sensor maximum, discovered through experiment
const int sensorPin = A0;

const int ledR = 9;
const int ledG = 10;
const int ledB = 11;

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

  // map the sensor range to a range of 8 options:
  int range = map(sensorReading, sensorMax, sensorMin, 1, 6);
  // do something different depending on the range value
  analogWrite(ledR, 0);
  analogWrite(ledG, 0);
  analogWrite(ledB, 0);
  switch (range) {
    case 1:
      analogWrite(ledR, 255);
      break;
    case 2:
      analogWrite(ledR, 255/2);
      analogWrite(ledG, 255/2);
      break;
    case 3:
      analogWrite(ledG, 255);
      break;
    case 4:
      analogWrite(ledG, 255/2);
      analogWrite(ledB, 255/2);
      break;
    case 5:
      analogWrite(ledB, 255);
      break;
    case 6:
      analogWrite(ledR, 255/2);
      analogWrite(ledB, 255/2);
      break;
  }
    
  delay(1);
}
