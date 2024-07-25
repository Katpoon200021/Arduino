// Project - Music Player Continuous Looping
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFRobotDFPlayerMini player;

// Variable to track whether the song is playing or not
bool isSongPlaying = false;

void setup() {
  // Init USB serial port for debugging
  Serial.begin(9600); // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);// Start communication with DFPlayer Mini

  if (player.begin(softwareSerial)) {
    Serial.println("OK");
    // Set volume to maximum (0 to 30).
    player.volume(10);
    // Play the first MP3 file on the SD card
    player.play(001);
    // Set the variable to true since the song is playing
    isSongPlaying = true;
  }
  else {
    Serial.println("Connecting to DFPlayer Mini failed!"); 
  } 
}

void loop() { 
  // Play the first MP3 file on the SD card
  //player.play(001);

  // Delay for 50 seconds before playing again
  //delay(50000);

  if (!isSongPlaying) {
    // If not, play the song again
    player.play(001);
    // Set the variable to true since the song is playing
    isSongPlaying = true;
  } else {
    // Check if the song has finished playing
    if (player.available()) {
      // Get the current message type
      uint8_t type = player.readType();
      // Check if the message type is "Play Finished"
      if (type == DFPlayerPlayFinished) {
        // If the song has finished playing, set the variable to false
        isSongPlaying = false;
      }
    }
  }
}