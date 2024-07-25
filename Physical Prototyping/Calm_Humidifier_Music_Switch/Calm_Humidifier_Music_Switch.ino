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

// Switch pins
const int switchPin1 = 7; // Define the pin connected to one row of switch pins
const int switchPin2 = 6; // Define the pin connected to the other row of switch pins

void setup() {
  pinMode(switchPin1, INPUT_PULLUP); // Set the switch pin 1 as an input with pull-up resistor
  pinMode(switchPin2, INPUT_PULLUP); // Set the switch pin 2 as an input with pull-up resistor

  // Init serial ports
  Serial.begin(9600);
  softwareSerial.begin(9600);

  // Init music player
  if (player.begin(softwareSerial)) {
    Serial.println("Music player initialized");
    player.volume(22); // Set volume
  } else {
    Serial.println("Connecting to music player failed!");
  }
}

void loop() {
  // Read the state of the switch pins
  int switchState1 = digitalRead(switchPin1);
  int switchState2 = digitalRead(switchPin2);

  // Check if the switch is turned on (active LOW)
  if (switchState1 == LOW || switchState2 == LOW) {
    // If the song is not playing, start playing
    if (!isSongPlaying) {
      player.play(1); // Play the first MP3 file on the SD card
      isSongPlaying = true;
    }
  } else {
    // If the switch is turned off, stop playing and reset the song state
    if (isSongPlaying) {
      player.stop();
      isSongPlaying = false;
    }
  }

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
