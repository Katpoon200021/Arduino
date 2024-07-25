#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// Pin definitions for tilt sensor
const int TILT_SENSOR_PIN = 4;

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
  softwareSerial.begin(9600); // Start communication with DFPlayer Mini

  if (player.begin(softwareSerial)) {
    Serial.println("OK");
    // Set volume to maximum (0 to 30).
    player.volume(8);
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
}

void loop() {
  // Read the state of the tilt sensor
  int tiltState = digitalRead(TILT_SENSOR_PIN);
  Serial.println(tiltState);

  // Check if the tilt sensor is HIGH (tilted)
  if (tiltState == HIGH) {
    // If the song is not playing, start playing
    if (!isSongPlaying) {
      // Play all songs in the folder with index 1
      player.playFolder(1, 1); // Assuming folder 1 and song 1
      isSongPlaying = true;
    } else {
      // Check if the song has finished playing
      if (player.available()) {
        uint8_t type = player.readType();
        if (type == DFPlayerPlayFinished) {
          // Restart the song if it has finished playing
          player.playFolder(1, 1); // Assuming folder 1 and song 1
        }
      }
    }
  } else {
    // If the song is playing and the tilt sensor is LOW, stop playing immediately
    if (isSongPlaying) {
      player.stop();
      isSongPlaying = false;
    }
  }
}