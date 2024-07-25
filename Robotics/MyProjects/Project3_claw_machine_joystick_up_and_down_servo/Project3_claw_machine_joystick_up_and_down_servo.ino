#include <Servo.h>

Servo myServo; // Define the servo object

const int joystickPin = A0; // Analog pin for the joystick
const int minAngle = 55;     // Minimum angle for the servo
const int maxAngle = 175;   // Maximum angle for the servo

void setup() {
  myServo.attach(1); // Attach the servo to pin 9
}

void loop() {
  int joystickValue = analogRead(joystickPin); // Read the joystick value (0 - 1023)
  
  // Map the joystick value to the servo angle range
  int angle = map(joystickValue, 0, 1023, minAngle, maxAngle);
  
  // Control the servo with the mapped angle
  myServo.write(angle);
  
  delay(500); // Add a small delay for stability
}
