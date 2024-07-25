#include <Servo.h>
#include "pitches.h"
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int grabButtonPin = 9;
const int rightButtonPin = 7;
const int leftButtonPin = 6;

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

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Welcome to the");
  lcd.setCursor(0, 1);
  lcd.print("Claw Machine!");

  delay(3000);
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
    while (millis() - startTime < 5000) {
      if ((millis() - startTime) % 1000 < 500) {
        lcd.clear();
      } else {
        lcd.setCursor(4, 0);
        lcd.print("Grabbing");
      }
    }
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Grabbed");
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
      timerRunning = false;
    }
  }

  delay(400);
}
