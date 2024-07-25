// Project - Music Player for 3 Songs
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

// Function to play all songs in a specific folder
void playAllSongsInFolder(uint8_t folder) {
  for (uint8_t i = 1; i <= 255; i++) { // Assuming a maximum of 255 songs in a folder
    player.playFolder(folder, i);
    delay(300000); // Adjust delay as needed between songs
  }
}

void setup() {
  // Init USB serial port for debugging
  Serial.begin(9600); // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);// Start communication with DFPlayer Mini

  if (player.begin(softwareSerial)) {
    Serial.println("OK");
    // Set volume to maximum (0 to 30).
    player.volume(8);
    // Play all songs in the folder with index 1 (change folder number as needed)
    playAllSongsInFolder(01);
    // Set the variable to true since the song is playing
    isSongPlaying = true;
  }
  else {
    Serial.println("Connecting to DFPlayer Mini failed!"); 
  } 
}

void loop() { 
  // Check if the song has finished playing
  if (isSongPlaying && player.available()) {
    // Get the current message type
    uint8_t type = player.readType();
    // Check if the message type is "Play Finished"
    if (type == DFPlayerPlayFinished) {
      // If the song has finished playing, set the variable to false
      isSongPlaying = false;
      // Play all songs in the folder again
      playAllSongsInFolder(01); // Change folder number as needed
      // Set the variable to true since the song is playing
      isSongPlaying = true;
    }
  }
}