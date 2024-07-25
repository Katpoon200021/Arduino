// Define the pin connected to the transistor base
const int motorPin1 = 2;
const int motorPin2 = 3;

void setup() {
  // Set the first motor pin as an output
  pinMode(motorPin1, OUTPUT);

  // Set the second motor pin as an output
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  // Turn the first motor on for 10 seconds
  digitalWrite(motorPin1, HIGH);
    // Turn the second motor on for 10 seconds
  digitalWrite(motorPin2, HIGH);
  delay(10000);
  
  // Turn the first motor off for 2 seconds
  digitalWrite(motorPin1, LOW);
  // Turn the first motor off for 2 seconds
  digitalWrite(motorPin2, LOW);
  delay(2000);
}