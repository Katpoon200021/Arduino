const int analogInPin = A0; //analog input pint that the potentiometer is attached to
const int analogOutPin = 9; //analog output pin that the LED is attached to

int sensorValue = 0; //value read from pot
int outputValue = 0; //value output to PWM (analog out)

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //initializes the serial communication to 9600 bps
}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue = analogRead(analogInPin); //read the analog in value
outputValue = map(sensorValue, 0, 1023, 0, 255); //map it to the range of the analog out
analogWrite(analogOutPin, outputValue); //change the analog out value to the LED

//print the results to the Serial Monitor
Serial.print("sensor = ");
Serial.print(sensorValue);
Serial.print("\t output = ");
Serial.println(outputValue);

delay(2); //wait 2 milliseconds before the next loop for the analog to digital
}
