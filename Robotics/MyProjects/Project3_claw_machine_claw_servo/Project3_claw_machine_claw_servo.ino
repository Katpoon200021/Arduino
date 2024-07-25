#include <Servo.h>

Servo baseservo; // servo for the base of the claw machine
Servo myservo2;  // servo that is attached to the base
Servo myservo3;  // servo that is placed in the middle
Servo myservo4;  // servo holding the claw
Servo clawservo; // servo for the claw of the claw machine

unsigned long clawOpenTime = 0;
bool clawOpen = false;

void setup() {
  baseservo.attach(1);
  myservo2.attach(2);
  myservo3.attach(3);
  myservo4.attach(4);
  clawservo.attach(5);
}

void loop() {
  if (!clawOpen && millis() - clawOpenTime >= 5000) {
    clawservo.write(75); // Open the claw
    clawOpenTime = millis(); // Record the time when the claw is opened
    clawOpen = true;
  }

  if (clawOpen && millis() - clawOpenTime >= 5000) {
    clawservo.write(0); // Close the claw
    clawOpenTime = millis(); // Record the time when the claw is closed
    clawOpen = false; // Reset the flag
  }
}
