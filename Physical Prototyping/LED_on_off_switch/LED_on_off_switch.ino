// Lights the LED light
// const int ledPin = 7; // Define the pin connected to the LED

// void setup() {
//   pinMode(ledPin, OUTPUT); // Set the LED pin as an output
// }

// void loop() {
//   digitalWrite(ledPin, HIGH); // Turn on the LED
//   delay(1000); // Wait for 1 second
// }

const int switchPin1 = 7; // Define the pin connected to one row of switch pins
const int switchPin2 = 6; // Define the pin connected to the other row of switch pins
const int ledPin = 5;     // Define the pin connected to the LED

void setup() {
  pinMode(switchPin1, INPUT_PULLUP); // Set the switch pin 1 as an input with pull-up resistor
  pinMode(switchPin2, INPUT_PULLUP); // Set the switch pin 2 as an input with pull-up resistor
  pinMode(ledPin, OUTPUT);           // Set the LED pin as an output
}

void loop() {
  // Read the state of the switch pins
  int switchState1 = digitalRead(switchPin1);
  int switchState2 = digitalRead(switchPin2);
  
  // Check if the switch is turned on (active LOW)
  if (switchState1 == LOW || switchState2 == LOW) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
  }
}

