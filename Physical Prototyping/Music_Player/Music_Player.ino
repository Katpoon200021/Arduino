#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX... D5 goes to 3rd pin down, 
// D6 goes to 2nd pin down from top


void sendCmd(int cmd, int lb, int hb, bool reply = false) { 
  // standard format for module command stream
  uint8_t buf[] = {0x7E, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEF};
  int16_t chksum = 0;
  int idx = 3; // position of first command byte

  buf[idx++] = (uint8_t)cmd; // inject command byte in buffer
  if (reply) buf[idx++] = 0x01;
  else buf[idx++] = 0x00;// set if reply is needed/wanted
  if (hb >= 0) // if there is a high byte data field
  buf[idx++] = (uint8_t)hb; // add it to the buffer
  if (lb >= 0) // if there is a low byte data field
  buf[idx++] = (uint8_t)lb; // add it to the buffer
  buf[2] = idx - 1; // inject command length into buffer
  buf[idx++] = 0xEF; // place end-of-command byte

  mySerial.write(buf, idx); // send the command to module
  // for (int i = 0; i < idx; i++) // send command as hex string to MCU
  // Serial.printf("%02X ", buf[i]);
  // Serial.println();
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //for console debugging
  delay(2000); //Allow Serial to start up

  Serial.println("starting ");
  mySerial.begin(9600); //communicate with DF Player
  delay(3000); //Allow SoftwareSerial to start up

  Serial.println("Stop anything playing"); //in case anything is already playing on reset
  sendCmd(0x0E, 0, 0, false);
  delay(200); //give a delay for the DF Player to execute the command

  Serial.println("Now volume ");
  sendCmd(2, 2, 0, false); //command code can be in decimal too.

  Serial.println("Starting Player");
  sendCmd(0x01, 0, 0, false); // Send a "next track" command that turns play mode on
  delay(1000);
  Serial.println("_____________________________________");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println("play track 3 ");
  // sendCmd(0x0F, 3, 1, false); //play track 003 in folder 01
  // delay(8000);
  // sendCmd(0x0E, 0, 0, false); //send stop command
  // delay(200);
  // Serial.println(" ");

  // Serial.println("play track 5 ");
  // sendCmd(0x0F, 5, 1, false); //play track 005 in folder 01
  // delay(8000);
  // sendCmd(0x0E, 0, 0, false); //send stop command
  // delay(200);
  // Serial.println(" ");

  Serial.println("play track 1 ");
  sendCmd(0x0F, 1, 1, false); //play track 001 in folder 01
  delay(80000);

  sendCmd(0x0E, 0, 0, false); //send stop command
  delay(200);
  Serial.println(" ");

  //Serial.println("play track 2 ");
  //sendCmd(0x0F, 2, 1, false); //play track 001 in folder 01
  //delay(80000);
  // sendCmd(0x0E, 0, 0, false); //send stop command
  // delay(200);
  // Serial.println(" ");

  // Serial.println("play track 2 ");
  // sendCmd(0x0F, 2, 1, false); //play track 001 in folder 01
  // delay(8000);
  // sendCmd(0x0E, 0, 0, false); //send stop command
  // delay(200);
  // Serial.println(" ");

  // Serial.println("play track 6 ");
  // sendCmd(0x0F, 6, 1, false); //play track 006 in folder 01
  // delay(8000);
  // sendCmd(0x0E, 0, 0, false); //send stop command
  // delay(200);
  // Serial.println(" ");
}
