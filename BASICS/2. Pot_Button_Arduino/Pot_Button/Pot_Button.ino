//-----BUTTON-----
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  12;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


void setup() {
  Serial.begin(9600); // initialize serial communications at 9600 bps

  pinMode(ledPin, OUTPUT); // initialize the LED pin as an output
  pinMode(buttonPin, INPUT); // initialize the pushbutton pin as an input
}

void loop() {

  buttonState = digitalRead(buttonPin); // read the state of the pushbutton value

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH); // turn LED on
  } else {
    digitalWrite(ledPin, LOW); // turn LED off
  }
}



/*
//---------------------------------------------------------------------
//-----POTENTIOMETER-----

//VARIABLES
// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 13; // Analog output pin that the LED is attached to
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)


//INSIDE THE LOOP:
  //-----POTENTIOMETER-----
  sensorValue = analogRead(analogInPin); // read the analog in value
  outputValue = map(sensorValue, 0, 1023, 0, 255); // map it to the range of the analog out
  analogWrite(analogOutPin, outputValue); // change the analog out value

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);

/*

