//traffic light code

int GreenLED = 10;
int YellowLED = 11; 
int RedLED = 12; 

void setup() {
  // put your setup code here, to run once:
  pinMode(GreenLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);

  digitalWrite(GreenLED, LOW);
  digitalWrite(YellowLED, LOW);
  digitalWrite(RedLED, LOW);

  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  //Yield Mode

  digitalWrite(GreenLED, LOW);
  digitalWrite(YellowLED, HIGH);
  digitalWrite(RedLED, LOW);

  Serial.println(" Light Mode : Yield ");
  delay(1000);

  //Go Mode

  digitalWrite(GreenLED, HIGH);
  digitalWrite(YellowLED, LOW);
  digitalWrite(RedLED, LOW);

  Serial.println(" Light Mode : Go ");
  delay(1000);

  //Stop Mode

  digitalWrite(GreenLED, LOW);
  digitalWrite(YellowLED, LOW);
  digitalWrite(RedLED, HIGH);

  Serial.println(" Light Mode : Stop ");
  delay(1000);
}

