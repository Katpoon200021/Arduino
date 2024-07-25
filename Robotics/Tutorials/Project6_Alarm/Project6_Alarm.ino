// Project 6 Alarm
float sinVal;
int toneVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // you can hear alarm of high and low pitches
  for(int x=0; x<180; x++){
  //convert angle of sinusoidal to radian measure
  sinVal = (sin(x*(3.1412/180)));
  //generate sound of different frequencies by sinusoidal value
  toneVal = 2000+(int(sinVal*1000));
  //Set a frequency for Pin-out 8
  tone(8, toneVal);
  delay(2);
  }
}
