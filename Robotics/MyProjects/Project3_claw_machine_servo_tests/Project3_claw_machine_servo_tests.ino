// Project 3 - Claw Machine Tests / Practices
#include <Servo.h> //declare to insert Servo.h library
Servo myservo1; // the 180 servo motor
Servo myservo2; // the 2nd 180 servo motor
Servo myservo3; // the 360 servo motor

void setup() {
  // put your setup code here, to run once:
  // Servo
  myservo1.attach(1); // attach the 180 servo to digital pin 1
  myservo2.attach(2); // attach the 2nd 180 servo to digital pin 2
  myservo3.attach(3); // attach the 360 servo to digital pin 3
}

void loop() {
  // put your main code here, to run repeatedly:
  // Getting the claw to open and close
  // myservo1.write(90);
  // delay(1000);
  // myservo1.write(135);
  // delay(1000);

  // Define the parameters for the circular motion
  // int centerX = 90;    // Center position of the servo
  // int radius = 50;     // Radius of the circular motion
  // int speed = 5;       // Speed of the motion (smaller values mean faster motion)
  
  // // Move the servo in a circular motion
  // for (int angle = 0; angle < 360; angle++) {
  //   int x = centerX + radius * cos(angle * 3.14159 / 180);  // Calculate x position
  //   int y = centerX + radius * sin(angle * 3.14159 / 180);  // Calculate y position
    
  //   // Move the servo to the calculated position
  //   myservo2.write(x);
    
  //   // Delay to control the speed of the motion
  //   delay(speed);
  // }

  // Testing the 360 servo motor
  // Rotate the servo to its maximum position (360 degrees)
  myservo3.write(0); // Rotate to position 0 (full anticlockwise)
  delay(1000); // Wait for 1 second

  // Rotate the servo to its minimum position (360 degrees)
  myservo3.write(180); // Rotate to position 180 (full clockwise)
  delay(1000); // Wait for 1 second
}
