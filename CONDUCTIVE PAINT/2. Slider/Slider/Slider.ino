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
