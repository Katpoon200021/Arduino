//Project 1 - Drawing shapes
#include <Servo.h> //declare to insert Servo.h library
Servo myservo; //create servo object to control servo 1
Servo myservo2; //create servo object to control servo 2
int pos = 0; //variable pos to store position of servo

float d,h,l,phi;
float theta1,theta2;
int i,j;

// digital pin 12 has a pushbutton attached to it
int pushButton1 = 12;
// digital pin 11 has a pushbutton attached to it
int pushButton2 = 11;
// digital pin 10 has a pushbutton attached to it
int pushButton3 = 10;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  myservo2.attach(8);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT);
  pinMode(pushButton3, INPUT);
}

void go(float x, float y) {
  l = 8; //length of link, l= 8cm
  d = sqrt((x*x)+(y*y)); //distace between origin left and (x,y) point
  phi = atan2(y,x)*180/3.14; // phi, angle between d and x axis  
  h = sqrt((l*l)-((d/2)*(d/2))); //height of the triangle
  theta1 = atan2(h,(d/2))*180/3.14; // phi 1, angle between d and axis
  theta2 = (90 - theta1)*2; // angle between l and l
  theta1+=phi;
  
  if ((theta1>0 && theta2>0) && (theta1<180 && theta2<180)){
    myservo2.writeMicroseconds((int)((theta1/180)*1500+700));
    myservo.writeMicroseconds((int)((theta2/180)*1500+700));
  }
}

void square(){
  myservo2.write(45);
  for(i = 90; i < 120; i += 1) {
    myservo.write(i);  
    delay(70);
  }

  myservo.write(120);
  for(j = 45; j >= 15; j -= 1) {
    myservo2.write(j);
    if (i <= 145) {
      i += 0.95;
      myservo.write(i);
    }
    delay(70);
  }

  for(i < 120; i >= 90; i -= 1) {
    myservo.write(i);
    delay(70);
  }

  for(j = 15; j <= 45; j += 1) {
    myservo2.write(j);
    delay(70);
  }
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
    
    square();
    delay(20);
  } 
  else if (buttonState2 == HIGH) {
    Serial.println(" Pushbutton 2 is pressed, value is : ");
    Serial.println(buttonState2);

    // wave
    for(j = 10; j < 70; j += 1) { 
      //servo turns from 0 to 180 in steps of 1 degree
      myservo2.write(j); //tell servo to go to position in variable 'pos'
      for(i = 90; i <= 110; i += 1) {
        myservo.write(i);
        delay(7);
      }
      for(i = 110; i >= 90; i -= 1) {
        myservo.write(i);
        delay(7);
      }
      delay(150); //wts 15ms for the servo to reach the position
    }

    for(pos = 70; pos >= 10; pos-=1) { 
      // servo turns from 180 to 0 in steps of 1 degree
      myservo2.write(pos); //tell servo to go to position in variable 'pos'
      delay(8); //waits 15ms for the servo to reach the position
    }
  }
  else if (buttonState3 == HIGH) {
    Serial.println(" Pushbutton 3 is pressed, value is : ");
    Serial.println(buttonState3);

    // heart -> shoe/slipper
    for(j = 10; j < 60; j += 1) { 
      //servo turns from 0 to 180 in steps of 1 degree
      myservo2.write(j); //tell servo to go to position in variable 'pos'
      delay(40); //wts 15ms for the servo to reach the position
    }

    for(i = 90; i <= 130; i += 1) {
      myservo.write(i);
      delay(70);
    }

    for(j = 60; j >= 35; j -= 1) {
      myservo2.write(j);
      delay(70);
    }

    for(i = 130; i <= 150; i += 1) {
      myservo.write(i);
      delay(70);
    }

    for(j = 35; j >= 0; j -= 1) {
      myservo2.write(j);
      delay(70);
    }

    for(i = 150; i >= 90; i -= 1) {
      myservo.write(i);
      delay(70);
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
  delay(1000);
}
