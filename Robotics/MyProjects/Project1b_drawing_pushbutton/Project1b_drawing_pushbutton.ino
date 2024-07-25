//Project 1 - Drawing with push button
#include <Servo.h> //declare to insert Servo.h library
Servo myservo; //create servo object to control a servo
int pos = 0; //variable pos to store position of servo

// digital pin 12 has a pushbutton attached to it
int pushButton = 12;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9); //attach the servo to digital pin 9.

    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input pin:
  int buttonState = digitalRead(pushButton);

  // print out the state of the button:
  if (buttonState == HIGH) {
    Serial.println(" Pushbutton is pressed, value is : ");
    Serial.println(buttonState);
    // you will see servo sweeping back and forth from 0 - 180 degrees
    for(pos = 5; pos < 170; pos += 1){ 
      //servo turns from 0 to 180 in steps of 1 degree
      myservo.write(pos); //tell servo to go to position in variable 'pos'
      delay(10); //wts 15ms for the servo to reach the position
    }

    for(pos = 170; pos>=5; pos-=1) { 
      // servo turns from 180 to 0 in steps of 1 degree
      myservo.write(pos); //tell servo to go to position in variable 'pos'
      delay(10); //waits 15ms for the servo to reach the position
    }

    for(pos = 5; pos < 90; pos += 1){ 
      //servo turns from 0 to 180 in steps of 1 degree
      myservo.write(pos); //tell servo to go to position in variable 'pos'
      delay(10); //wts 15ms for the servo to reach the position
    }
  } else {
    Serial.println(" Pushbutton is not pressed, value is : ");
    Serial.println(buttonState);
  }
    delay(1000);  // delay in between reads for stability
}