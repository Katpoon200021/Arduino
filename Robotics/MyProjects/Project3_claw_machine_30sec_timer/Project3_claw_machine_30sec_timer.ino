#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Address 0x27, 16 columns, 2 rows

// Define variables for timer
unsigned long startTime;
const unsigned long timerDuration = 30000; // 30 seconds in milliseconds

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Print initial message
  lcd.setCursor(0, 0);
  lcd.print("Timer starting...");
}

void loop() {
  // Start the timer
  startTime = millis();

  // Clear the LCD
  lcd.clear();

  // Update LCD every 1 second until the timer is finished
  while (millis() - startTime < timerDuration) {
    // Calculate elapsed time
    unsigned long elapsedTime = millis() - startTime;
    
    // Calculate remaining time
    unsigned long remainingTime = timerDuration - elapsedTime;

    // Convert remaining time to seconds
    unsigned int seconds = remainingTime / 1000;

    // Update LCD with remaining time
    lcd.setCursor(0, 0);
    lcd.print("Time Remaining:");
    lcd.setCursor(0, 1);
    lcd.print(seconds);
    lcd.print(" seconds");

    // Wait for 1 second
    delay(1000);
  }

  // Timer finished, display completion message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Timer finished!");
  lcd.setCursor(0, 1);
  lcd.print("Restarting timer...");
}