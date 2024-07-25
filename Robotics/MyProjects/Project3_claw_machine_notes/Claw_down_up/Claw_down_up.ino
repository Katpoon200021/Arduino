#include "pitches.h"
#define BUZZER_PIN 13

// Notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, REST, // Melody going down
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, REST, // Melody going down
  NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, REST,  // Melody going up
  NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, REST,  // Melody going up
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 
  4, 8, 8, 4,
  4, 8, 8, 4, 
  4, 8, 8, 4
};

void setup() {
  unsigned long startTime = millis(); // Record the start time
  unsigned long elapsedTime = 0; // Initialize the elapsed time
  
  while (elapsedTime < 10000) { // Play for 10 seconds
    // Iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 20; thisNote++) {
      // To calculate the note duration, take one second divided by the note type.
      // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(BUZZER_PIN, melody[thisNote], noteDuration);

      // To distinguish the notes, set a minimum time between them.
      // The note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // Stop the tone playing:
      noTone(BUZZER_PIN);

      // Update the elapsed time
      elapsedTime = millis() - startTime;
      
      // If the elapsed time exceeds 10 seconds, break out of the loop
      if (elapsedTime >= 10000) {
        break;
      }
    }
  }
}

void loop() {
  // The loop is empty as the melody is played in the setup function
}