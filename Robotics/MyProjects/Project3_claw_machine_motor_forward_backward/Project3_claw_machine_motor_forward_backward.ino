// Define pins connected to the transistors controlling motor 1
const int motor1ForwardPin = 2;   // Connect to the transistor base for forward direction of motor 1
const int motor1BackwardPin = 3;  // Connect to the transistor base for backward direction of motor 1

// Define pins connected to the transistors controlling motor 2
const int motor2ForwardPin = 4;   // Connect to the transistor base for forward direction of motor 2
const int motor2BackwardPin = 5;  // Connect to the transistor base for backward direction of motor 2

void setup() {
  // Set motor control pins as outputs
  pinMode(motor1ForwardPin, OUTPUT);
  pinMode(motor1BackwardPin, OUTPUT);
  pinMode(motor2ForwardPin, OUTPUT);
  pinMode(motor2BackwardPin, OUTPUT);
}

void loop() {
  // Example: move both motors forward for 2 seconds
  moveMotorsForward();
  delay(2000);

  // Example: move both motors backward for 2 seconds
  moveMotorsBackward();
  delay(2000);
}

// Function to move both motors forward
void moveMotorsForward() {
  // Set motor 1 to move forward
  digitalWrite(motor1ForwardPin, HIGH);
  digitalWrite(motor1BackwardPin, LOW);

  // Set motor 2 to move forward
  digitalWrite(motor2ForwardPin, HIGH);
  digitalWrite(motor2BackwardPin, LOW);
}

// Function to move both motors backward
void moveMotorsBackward() {
  // Set motor 1 to move backward
  digitalWrite(motor1ForwardPin, LOW);
  digitalWrite(motor1BackwardPin, HIGH);

  // Set motor 2 to move backward
  digitalWrite(motor2ForwardPin, LOW);
  digitalWrite(motor2BackwardPin, HIGH);
}