// Project 9– Light the lamp
int LED = 13; //define LED digital pin 13
int val = 0; //define the voltage value of photo diode in digital pin 0

void setup() {
  // put your setup code here, to run once:
  // you can shine a falshlight on the photodiode to alter
  // the light levels in the environment.
  // When it's dark, they should light up.
  // When it's bright, the LED should turn off.
  pinMode(LED,OUTPUT); // Configure LED as output mode
  Serial.begin(9600); //Configure baud rate 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(0); // Read voltage value ranging from 0 -1023
  Serial.println(val); // read voltage value from serial monitor
  if(val<1000){ // If lower than 1000, turn off LED
    digitalWrite(LED,LOW);
  } else{ // Otherwise turn on LED
      digitalWrite(LED,HIGH);
    }
    
  delay(1000); // delay for 10ms
}
