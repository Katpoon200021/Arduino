int ledPin = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 3 quick blinks to represent “S” again
  for(int x=0;x<3;x++){
    // configure LED on
    digitalWrite(ledPin,HIGH);
    // delay 150 milliseconds
    delay(150);
    // configure LED off
    digitalWrite(ledPin,LOW);
    // delay 100 milliseconds
    delay(100);
  }
  // 100 milliseconds delay between each letter
  delay(100);

  //3 quick blinks to represent “O”
  for(int x=0;x<3;x++){
    // configure LED on
    digitalWrite(ledPin,HIGH);
    // delay 400 milliseconds
    delay(400);
    // configure LED off
    digitalWrite(ledPin,LOW);
    // delay 100 milliseconds
    delay(100);
  }
  // 100 milliseconds delay between each letter
  delay(100);

  for(int x=0;x<3;x++){
    // configure LED on
    digitalWrite(ledPin,HIGH);
    // delay 150 milliseconds
    delay(150);
    // configure LED off
    digitalWrite(ledPin,LOW);
    // delay 100 milliseconds
    delay(100);
  }
  // wait 5 seconds to repeat the next S.O.S signal
  delay(5000);
}
