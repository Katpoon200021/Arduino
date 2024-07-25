//Project eleven controllable servo
#include <Servo.h> // insert the Servo.h library
Servo myservo; // create servo object to control servo
int potpin = 0; // connect potentiometer to digital pin0
int val; // variable value to read value from analog pin

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9); //Attach the servo on pin 9 to the servo object.
}

void loop() {
  // put your main code here, to run repeatedly:
  // you can see the servo turn account to the position of the
  // potentiometer
  val = analogRead(potpin); //reads the value of the potentiommeter
                            // (value between 0 and 1023)
  val = map(val, 0, 1023, 5, 170); // scale it to use it with the servo (value
                                   //between 0 and 180)
  myservo.write(val); // sets the servo position according to the
                      // scaled value
  delay(15);
}
