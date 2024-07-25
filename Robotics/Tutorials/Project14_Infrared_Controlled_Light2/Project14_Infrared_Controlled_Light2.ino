//project fourteen – infrared receiving tube
#include <IRremote.h>
int RECV_PIN = 11;
int ledPin = 10; // LED – digital 10
boolean ledState = LOW; // ledState to store the state of LED
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(ledPin,OUTPUT); // define LED as output signal
}

void loop() {
  // put your main code here, to run repeatedly:
  // test if receive decoding data and save it to variable results
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    // once receive code from power button, the state of LED is changed from HIGH
    // to LOW or from LOW to HIGH.
    if(results.value == 0xFD00FF){
      ledState = !ledState; //reverse
      digitalWrite(ledPin,ledState); //change the state of LED
    }
  
    irrecv.resume();
  }
}
