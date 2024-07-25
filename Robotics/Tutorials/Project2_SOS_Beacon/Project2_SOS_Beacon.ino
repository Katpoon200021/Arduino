int ledPin = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 3 quick blinks to represent “S”
  digitalWrite(ledPin,HIGH);
  delay(150);
  digitalWrite(ledPin,LOW);
  delay(100);
  digitalWrite(ledPin,HIGH);
  delay(150);
  digitalWrite(ledPin,LOW);
  delay(100);
  digitalWrite(ledPin,HIGH);
  delay(150);
  digitalWrite(ledPin,LOW);
  delay(100);
  delay(100); 
  //100 milliseconds as a break of each letter

  //3 quick blinks to represent “0”
  digitalWrite(ledPin,HIGH);
  delay(400);
  digitalWrite(ledPin,LOW);
  delay(100);
  digitalWrite(ledPin,HIGH);
  delay(400);
  digitalWrite(ledPin,LOW);
  delay(100);
  digitalWrite(ledPin,HIGH);
  delay(400);
  digitalWrite(ledPin,LOW);
  delay(100);
  delay(100);
  // 100 milliseconds delay between each letter

  //3 quick blinks to represent “S” again
  digitalWrite(ledPin,HIGH);
  delay(150);
  digitalWrite(ledPin,LOW);
  delay(100);
  digitalWrite(ledPin,HIGH);
  delay(150);
  digitalWrite(ledPin,LOW);
  delay(100);
  digitalWrite(ledPin,HIGH);
  delay(150);
  digitalWrite(ledPin,LOW);
  delay(100);
  
  delay(5000); 
  // wait 5 seconds to repeat the next S.O.S signal
}
