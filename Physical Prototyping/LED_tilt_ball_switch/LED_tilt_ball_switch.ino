int ledPin = 12; //set the LED pin
int sensorPin = 4; //set the sensor pin
int sensorValue; //grabs the sensor value 
int lastTiltState = HIGH; // the previous reading from the tilt sensor

// the following variables are long because the time is measured in miliseconds and will quickly become a bigger number than can be stored in an int.

long lastDebounceTime = 0; // the last time the output pin was toggled
long debounceDelay = 50; // the debounce time; increase if the output flickers

void setup(){
pinMode(sensorPin, INPUT); //sets the sensor pin as input
digitalWrite(sensorPin, HIGH); //digitalWrite() sets the output to HIGH
pinMode(ledPin, OUTPUT); //sets the LED pin as output
Serial.begin(9600);
}

void loop(){
sensorValue = digitalRead(sensorPin); //sets sensor Value to read the sensor pin

// If the switch changed, due to noise or pressing:
if (sensorValue == lastTiltState) {
// reset the debouncing timer
lastDebounceTime = millis();
}
if ((millis() - lastDebounceTime) > debounceDelay) {
// whatever the reading is at, it's been there for longer
// than the debounce delay, so take it as the actual current state:
lastTiltState = sensorValue;
}
digitalWrite(ledPin, lastTiltState);

Serial.println(sensorValue);
delay(500);
}
