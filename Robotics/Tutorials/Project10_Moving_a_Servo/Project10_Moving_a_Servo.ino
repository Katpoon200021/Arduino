//Project 10 Servo
#include <Servo.h> //declare to insert Servo.h library
Servo myservo; //create servo object to control a servo
int pos = 0; //variable pos to store position of servo

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9); //attach the servo to digital pin 9.
}

void loop() {
  // put your main code here, to run repeatedly:
  // you will see servo sweeping back and forth from 0 - 180 degrees
  for(pos = 5; pos < 170; pos += 1){ 
    //servo turns from 0 to 180 in steps of 1 degree
    myservo.write(pos); //tell servo to go to position in variable 'pos'
    delay(30); //wts 15ms for the servo to reach the position
  }

  for(pos = 170; pos>=5; pos-=1) { 
    // servo turns from 180 to 0 in steps of 1 degree
    myservo.write(pos); //tell servo to go to position in variable 'pos'
    delay(30); //waits 15ms for the servo to reach the position
  }
}
