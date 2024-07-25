//Project 1 - Drawing with push buttons
#include <Servo.h> //declare to insert Servo.h library
Servo myservo; //create servo object to control a servo
int pos = 0; //variable pos to store position of servo

// digital pin 12 has a pushbutton attached to it
int pushButton1 = 12;
// digital pin 11 has a pushbutton attached to it
int pushButton2 = 11;
// digital pin 10 has a pushbutton attached to it
int pushButton3 = 10;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9); //attach the servo to digital pin 9.

    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT);
  pinMode(pushButton3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input pin:
  int buttonState1 = digitalRead(pushButton1);
  int buttonState2 = digitalRead(pushButton2);
  int buttonState3 = digitalRead(pushButton3);

  // print out the state of the button:
  if (buttonState1 == HIGH) {
    Serial.println(" Pushbutton 1 is pressed, value is : ");
    Serial.println(buttonState1);
    // you will see servo sweeping back and forth from 0 - 180 degrees
    for(pos = 5; pos < 80; pos += 1){ 
      //servo turns from 0 to 180 in steps of 1 degree
      myservo.write(pos); //tell servo to go to position in variable 'pos'
      delay(10); //wts 15ms for the servo to reach the position
    }
    for(pos = 80; pos >= 0; pos -= 1){ 
      //servo turns from 0 to 180 in steps of 1 degree
      myservo.write(pos); //tell servo to go to position in variable 'pos'
      delay(10); //wts 15ms for the servo to reach the position
    }
  } 
  else if (buttonState2 == HIGH) {
    Serial.println(" Pushbutton 2 is pressed, value is : ");
    Serial.println(buttonState2);
    for(pos = 95; pos < 180; pos += 1) {
      myservo.write(pos);
      delay(10);
    }
    for(pos = 180; pos >= 95; pos -= 1) {
      myservo.write(pos);
      delay(10);
    }
  }
  else if (buttonState3 == HIGH) {
    Serial.println(" Pushbutton 3 is pressed, value is : ");
    Serial.println(buttonState3);
    for(pos = 65; pos <= 115; pos += 1) {
      myservo.write(pos);
      delay(10);
    }
    for (pos = 115; pos >= 65; pos -= 1) {
      myservo.write(pos);
      delay(10);
    }
  }
  else {
    Serial.println(" Pushbutton 1 is not pressed, value is : ");
    Serial.println(buttonState1);

    Serial.println(" Pushbutton 2 is not pressed, value is : ");
    Serial.println(buttonState2);

    Serial.println(" Pushbutton 3 is not pressed, value is : ");
    Serial.println(buttonState3);
  }
    delay(1000);  // delay in between reads for stability
}