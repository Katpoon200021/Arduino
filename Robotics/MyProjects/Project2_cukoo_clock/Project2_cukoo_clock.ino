//Project 2 - Cuckoo clock
#include <Servo.h> //declare to insert Servo.h library
#include <Wire.h>
#include "pitches.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16,2);

// Music / Song
#define BUZZER_PIN 12

int melody[] = {
  REST, NOTE_D4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_C5, 
  NOTE_A4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_F4, NOTE_GS4,
  NOTE_D4, 
  NOTE_D4,
  
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_F5, NOTE_E5,
  NOTE_DS5, NOTE_B4,
  NOTE_DS5, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_B4,
  NOTE_G4,
  NOTE_AS4,
   
  NOTE_D5, NOTE_AS4,
  NOTE_D5, NOTE_AS4,
  NOTE_DS5, NOTE_D5,
  NOTE_CS5, NOTE_A4,
  NOTE_AS4, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_D4,
  NOTE_D5, 
  REST, NOTE_AS4,  
  
  NOTE_D5, NOTE_AS4,
  NOTE_D5, NOTE_AS4,
  NOTE_F5, NOTE_E5,
  NOTE_DS5, NOTE_B4,
  NOTE_DS5, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_AS4,
  NOTE_G4
};

int durations[] = {
  2, 4,
  4, 8, 4,
  2, 4,
  2, 
  2,
  4, 8, 4,
  2, 4,
  1, 
  4,
  
  4, 8, 4,
  2, 4,
  2, 4,
  2, 4,
  4, 8, 4,
  2, 4,
  1,
  4,
   
  2, 4,
  2, 4,
  2, 4,
  2, 4,
  4, 8, 4,
  2, 4,
  1, 
  4, 4,  
  
  2, 4,
  2, 4,
  2, 4,
  2, 4,
  4, 8, 4,
  2, 4,
  1
};

// Time
int hrsT = 1;
int hrsU = 1;
int minutesT = 5;
int minutesU = 9;
int secsT = 5;
int secsU = 0;
int TIME = 11;
int specifiedDelay = 1000;

//create servo object to control a servo
Servo myservo; // servo motor for pushing and pulling
Servo myservo1; // servor motor for the left wing
Servo myservo2; // servor motor for the right wing

int pos = 0;

// Flag to indicate whether the servo movement is in progress
bool servoMoving = false;
// Flag to indicate whether the servo movement at 12 PM has been performed
bool servoMovementPerformed = false;
// Flag to indicate whether the sound has been played
bool soundPlayed = false;

// Variable to store the last time the servo was moved
unsigned long previousMillis = 0;
// Interval between servo movements (milliseconds)
const long interval = 1000;

void setup() {
  // put your setup code here, to run once:
  // LCD Display code:
  lcd.init(); // it is to initialize the LCD
  lcd.backlight(); // it will turn on the LCD backlight
  lcd.setCursor(0, 0);
  lcd.print("Bird");
  lcd.setCursor(0, 1);
  lcd.print("Alarm Clock");
  delay(2000);
  lcd.clear();

  // Servors' code:
  // attach the servo motor for pushing and pulling to digital pin 11
  myservo.attach(11);
  // attach the servo motor for right wing to digital pin 9
  myservo1.attach(9);
  // attach the servo motor for left wing to digital pin 8
  myservo2.attach(8);

  pinMode(BUZZER_PIN, OUTPUT);
}

void clock() {
  //Clock:
  lcd.setCursor(0, 0);
  lcd.print("Time-");
  lcd.print(hrsT);
  lcd.print(hrsU);
  lcd.print(":");
  lcd.print(minutesT);
  lcd.print(minutesU);
  // lcd.print(":");
  // lcd.print(secsT);
  // lcd.print(secsU);

  // Update time logic
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    secsU++;
    if (secsU == 10) {
      secsU = 0;
      secsT++;
      if (secsT == 6) {
        secsT = 0;
        minutesU++;
        if (minutesU == 10) {
          minutesU = 0;
          minutesT++;
          if (minutesT == 6) {
            minutesT = 0;
            hrsU++;
            TIME++;
            if (hrsU == 10) {
              hrsU = 0;
              hrsT++;
            }
          }
        }
      }
    }
  }

  // Time
  if (TIME < 12) {
    lcd.setCursor(14, 0);
    lcd.print("AM");
  }
  else {
    lcd.setCursor(14, 0);
    lcd.print("PM");
  }
  if (TIME == 13) {
    hrsU = 1;
    hrsT = 0;
  }
  if (TIME == 24) {
    lcd.setCursor(14, 0);
    lcd.print("AM");
  }
  if (TIME == 25) {
    hrsT = 0;
    hrsU = 1;
    TIME = 1;
  }
}

void moveServos() {
  // Move both servos
  for (int i = 0; i < 10; ++i) {
    myservo1.write(90);
    myservo2.write(90);
    delay(300); // Example delay for each movement
    myservo1.write(160);
    myservo2.write(20);
    delay(300); // Example delay for each movement
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // Check if the current time is within the specified range for servo movement
  // Servo movement at 12 pm
  if (hrsT == 1 && hrsU == 2 && secsT == 0 && secsU == 1 && !servoMovementPerformed) { // Check if the time is 12 PM
    if (!soundPlayed) { // Check if the sound has not been played yet
      int size = sizeof(durations) / sizeof(int);

      unsigned long startTime = millis(); // Get the start time

      for (int note = 0; note < size; note++) {
        // Calculate the note duration
        int duration = 1000 / durations[note];
        tone(BUZZER_PIN, melody[note], duration);

        // Calculate the pause between notes
        int pauseBetweenNotes = duration * 1.30;
        delay(pauseBetweenNotes);
      
        // Check if the elapsed time exceeds the desired duration
        if (millis() - startTime >= 15000) { // Stop after 15 seconds
          break;
        }
      }

      // Stop the tone playing
      noTone(BUZZER_PIN);

      // Set the flag to indicate that the sound has been played
      soundPlayed = true; 
    }
    for (pos = 90; pos < 145; pos += 1) {
      myservo.write(pos);
      delay(100);
    }
    if (!servoMoving) {
      // Start moving the servos
      servoMoving = true;
      moveServos();
      myservo1.write(90);
      myservo2.write(90);
    }
    for (pos = 145; pos >= 90; pos -= 1) {
      myservo.write(pos);
      delay(100);
    }
    // Set the flag to indicate that the servo movement has been performed
    servoMovementPerformed = true;
  }
  else {
    servoMoving = false;
  }

  clock();
}
