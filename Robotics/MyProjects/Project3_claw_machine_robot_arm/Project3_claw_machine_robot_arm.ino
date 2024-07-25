// Project 3 - Claw Machine Robot Arm
#include <Servo.h> //declare to insert Servo.h library
Servo baseservo; // servo for the base of the claw machine
Servo myservo2; // servo that is attached to the base
Servo myservo3; // servo that is placed in the middle 
Servo myservo4; // servo holding the claw
Servo clawservo; // servo for the claw of the claw machine

int pos = 0; // variable pos to store position of servo

void setup() {
  // put your setup code here, to run once:
  baseservo.attach(1);
  myservo2.attach(2);
  myservo3.attach(3);
  myservo4.attach(4);
  clawservo.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Base Servo
  // Moves the base servo 0 - 180 and 180 - 0
  // for(pos = 0; pos <= 180; pos += 1){ 
  //   //servo turns from 0 to 180 in steps of 1 degree
  //   baseservo.write(pos); //tell servo to go to position in variable 'pos'
  //   delay(30); //wts 15ms for the servo to reach the position
  // }

  // for(pos = 180; pos >= 0; pos -= 1) { 
  //   // servo turns from 180 to 0 in steps of 1 degree
  //   baseservo.write(pos); //tell servo to go to position in variable 'pos'
  //   delay(30); //waits 15ms for the servo to reach the position
  // }

  // makes the second servo point straight ahead
  // baseservo.write(0);
  // delay(2000);
  // // makes the second servo point straight sideways
  // baseservo.write(180);
  // delay(2000);

  // Second servo motor
  // makes the third servo point straight up
  // myservo2.write(0);
  // delay(5000);
  // // is as far as the third servo can go down
  // myservo2.write(50);
  // delay(5000);

  // myservo2.write(40);

  // Third servo motor
  // myservo3.write(0);
  // delay(2000);
  // myservo3.write(40);
  // delay(2000);

  // myservo3.write(30);

  // Fourth servo motor
  // myservo4.write(0);
  // delay(1000);
  // myservo4.write(75);
  // delay(1000);

  // Claw servo motor
  // clawservo.write(0);
  // delay(1000);
  // clawservo.write(75);
  // delay(1000);

  // baseservo.write(20);
  // delay(200);
  // myservo2.write(0);
  // delay(200);
  // myservo3.write(50);
  // delay(200);
  // myservo4.write(20);
  // delay(200);
  // clawservo.write(0);
  // delay(200);

  // Where claw machine goes to drop the candy
  baseservo.write(115);
  delay(200);
  myservo2.write(40);
  delay(200);
  myservo3.write(60);
  delay(200);
  myservo4.write(10);
  delay(200);
}
