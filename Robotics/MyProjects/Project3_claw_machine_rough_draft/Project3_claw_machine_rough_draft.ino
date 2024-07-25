#include <Servo.h>

Servo baseservo; // servo for the base of the claw machine
Servo myservo2; // servo that is attached to the base
Servo myservo3; // servo that is placed in the middle 
Servo myservo4; // servo holding the claw
Servo clawservo; // servo for the claw of the claw machine

#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int grabButtonPin = 9;
const int rightButtonPin = 7;
const int leftButtonPin = 6;
const int ledPin = 8; // LED pin

const int joystickPin = A1; // Analog pin for the joystick left and right
const int minAngle = 155;     // Minimum angle for the base servo
const int maxAngle = 0;   // Maximum angle for the base servo
int lastJoystickValue = 0; // Variable to store the last joystick value

const int joystickPin2 = A0; // Analog pin for the joystick up and down
const int minAngle2 = 0;     // Minimum angle for the shoulder servo
const int maxAngle2 = 100; // Maximum angle for the shoulder servo
int lastJoystickValue2 = 0; // Variable to store the last joystick value

const int minAngle3 = 0;  // Minimum angle for the middle servo
const int maxAngle3 = 90;  // Maximum angle for the middle servo

const int minAngle4 = 0;  // Minimum angle for the elbow servo
const int maxAngle4 = 90;  // Maximum angle for the elbow servo

int UD = 0;
int LR = 0;

int DWN = 13;
int UP = 12;
int LEFT = 11;
int RT = 10;

int IUP = A0;
int ILR = A1;
int MID = 10;
int LRMID = 0;
int UPMID = 0;

unsigned long timerStart = 0;
const unsigned long timerDuration = 30000; // 30 seconds

bool timerRunning = false;

unsigned long clawOpenTime = 0;
bool clawOpen = false;

void setup() {
  baseservo.attach(1);
  myservo2.attach(2);
  myservo3.attach(3);
  myservo4.attach(4);
  clawservo.attach(5);

  pinMode(ledPin, OUTPUT); // Set LED pin as output

  lcd.init();
  lcd.backlight();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("left -> start");
  lcd.setCursor(0, 1);
  lcd.print("right -> stop");

  pinMode(rightButtonPin, INPUT_PULLUP);
  pinMode(leftButtonPin, INPUT_PULLUP);
  pinMode(grabButtonPin, INPUT_PULLUP);

  pinMode(DWN, OUTPUT);
  pinMode(UP, OUTPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(RT, OUTPUT);
  digitalWrite(DWN, HIGH);
  digitalWrite(UP, HIGH);
  digitalWrite(LEFT, HIGH);
  digitalWrite(RT, HIGH);

  LRMID = analogRead(ILR);
  UPMID = analogRead(IUP);
}

void loop() {
  int rightButtonState = digitalRead(rightButtonPin);
  int leftButtonState = digitalRead(leftButtonPin);
  int grabButtonState = digitalRead(grabButtonPin);

  if (rightButtonState == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Stopping the");
    lcd.setCursor(0, 1);
    lcd.print("claw machine!");
    delay(2000);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Thank you");
    lcd.setCursor(3, 1);
    lcd.print("and Goodbye");
    delay(3000);
  }

  if (leftButtonState == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Starting the");
    lcd.setCursor(0, 1);
    lcd.print("claw machine!");
    delay(2000);

    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("30 sec timer");
    lcd.setCursor(4, 1);
    lcd.print("Good Luck");
    delay(3000);

    if (!timerRunning) {
      timerStart = millis();
      timerRunning = true;
    } else {
      timerStart = millis(); // Reset timer
    }
  }

  if (grabButtonState == LOW) {
    unsigned long startTime = millis();
    unsigned long elapsedTime = 0;
    elapsedTime = millis() - startTime;
    while (millis() - startTime < 5000) {
      if (!clawOpen && millis() - clawOpenTime >= 5000) {
        clawservo.write(75); // Open the claw
        clawOpenTime = millis(); // Record the time when the claw is opened
        clawOpen = true;
      }
      if ((millis() - startTime) % 1000 < 500) {
        lcd.clear();
      } else {
        lcd.setCursor(4, 0);
        lcd.print("Grabbing");
      }
    }
    clawservo.write(0); // Close the claw
    clawOpenTime = millis(); // Record the time when the claw is closed
    clawOpen = false; // Reset the flag
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Grabbed");
    delay(1000);
    
    // Check if the claw has been closed for 10 seconds
    unsigned long clawClosedTime = millis();
    while (millis() - clawClosedTime < 10000) {
      // Wait for 10 seconds
        lcd.setCursor(4, 0);
        lcd.print("Opening");
        elapsedTime = millis() - clawClosedTime;
        lcd.setCursor(0, 1);
        lcd.print("Time left: ");
        lcd.print((10000 - elapsedTime) / 1000);
        lcd.print(" sec");
    }

    // Reopen the claw
    clawservo.write(75); // Open the claw
    clawOpenTime = millis(); // Record the time when the claw is opened
    clawOpen = true;
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Opened");
    delay(1000);
  }

  UD = analogRead(IUP);
  LR = analogRead(ILR);

  if (UD < UPMID - MID) {
    digitalWrite(DWN, HIGH);
  } else {
    digitalWrite(DWN, LOW);
  }

  if (UD > UPMID + MID) {
    digitalWrite(UP, HIGH);
  } else {
    digitalWrite(UP, LOW);
  }

  if (LR < LRMID - MID) {
    digitalWrite(LEFT, HIGH);
  } else {
    digitalWrite(LEFT, LOW);
  }

  if (LR > LRMID + MID) {
    digitalWrite(RT, HIGH);
  } else {
    digitalWrite(RT, LOW);
  }

  if (timerRunning) {
    unsigned long elapsedTime = millis() - timerStart;
    unsigned long remainingTime = max(0, timerDuration - elapsedTime);
    unsigned int seconds = remainingTime / 1000;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Time left: ");
    lcd.setCursor(0, 1);
    lcd.print(seconds);
    lcd.print(" seconds");
    if (elapsedTime >= timerDuration) {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Timer done!");
      delay(1000);
      timerRunning = false;
      
      unsigned long startTime = millis();
      while (millis() - startTime < 5000) {
        if (!clawOpen && millis() - clawOpenTime >= 5000) {
          clawservo.write(75); // Open the claw
          clawOpenTime = millis(); // Record the time when the claw is opened
          clawOpen = true;
        }
        if ((millis() - startTime) % 1000 < 500) {
          lcd.clear();
        } else {
          lcd.setCursor(4, 0);
          lcd.print("Grabbing");
        }
      }
      clawservo.write(0); // Close the claw
      clawOpenTime = millis(); // Record the time when the claw is closed
      clawOpen = false; // Reset the flag
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("Grabbed");
      delay(1000);
    
      // Check if the claw has been closed for 10 seconds
      unsigned long clawClosedTime = millis();
      while (millis() - clawClosedTime < 10000) {
      // Wait for 10 seconds
        lcd.setCursor(4, 0);
        lcd.print("Opening");
        elapsedTime = millis() - clawClosedTime;
        lcd.setCursor(0, 1);
        lcd.print("Time left: ");
        lcd.print((10000 - elapsedTime) / 1000);
        lcd.print(" sec");
      }
      // Reopen the claw
      clawservo.write(75); // Open the claw
      clawOpenTime = millis(); // Record the time when the claw is opened
      clawOpen = true;
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("Opened");
      delay(1000);
    }
  }
  
  // Joystick control for the servo
  int joystickValue = analogRead(joystickPin); // Read the joystick value (0 - 1023)
  // Map the joystick value to the base servo angle range
  int angle = map(joystickValue, 0, 1023, minAngle, maxAngle);

  int joystickValue2 = analogRead(joystickPin2); // Read the joystick value
  // Map the joystick value to the shoulder servo angle range
  int angle2 = map(joystickValue2, 0, 1023, minAngle2, maxAngle2);
  int angle3 = map(joystickValue2, 0, 1023, minAngle3, maxAngle3);
  int angle4 = map(joystickValue2, 0, 1023, minAngle4, maxAngle4);

  // Check if the current joystick value is different from the last one
  if (joystickValue != lastJoystickValue) {
    // Control the servo with the mapped angle
    baseservo.write(angle);
    
    // Update the last joystick value
    lastJoystickValue = joystickValue;
  }

  // Check if the current joystick value is different form the last one
  if (joystickValue2 != lastJoystickValue2) {
    // Control the servo with the mapped angle
    myservo4.write(angle2);
    myservo3.write(angle3);
    myservo2.write(angle4);

    // Update the last joystick value
    lastJoystickValue2 = joystickValue2;
  }
  
  // Control the LED based on the joystick input only when the joystick is moved
  if (joystickValue != lastJoystickValue || joystickValue2 != lastJoystickValue2) {
    int ledBrightness = map(joystickValue, 0, 1023, 0, 255);
    analogWrite(ledPin, ledBrightness);
  } else {
    analogWrite(ledPin, 0); // Turn off LED if the joystick is not moved
  }

  delay(400);
}