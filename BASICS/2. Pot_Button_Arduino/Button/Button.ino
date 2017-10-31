//-----BUTTON-----
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  // initialize the LED pin as an output
  pinMode(buttonPin, INPUT_PULLUP); // initialize the pushbutton pin as an input
}

void loop() {
  buttonState = digitalRead(buttonPin); // read the state of the pushbutton value
  Serial.println(buttonState);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:
  if (buttonState == LOW) {     //pressed
    digitalWrite(ledPin, HIGH); // turn LED on
  } else {
    digitalWrite(ledPin, LOW); // turn LED off
  }
}
