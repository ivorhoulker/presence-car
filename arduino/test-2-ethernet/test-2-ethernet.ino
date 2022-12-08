/*
 * Pico board manager download: https://github.com/earlephilhower/arduino-pico
 * OSCBundle library: https://github.com/CNMAT/OSC/releases - version 1.3.5 is used.
 */


#include "config.h"
#include <Wire.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>

#include <OSCBundle.h>

/*PICO SPI PIN:
  MOSI  <---> GP19
  MISO  <---> GP16
  SCK <---> GP18
  CS  <---> GP17
*/

EthernetUDP Udp;

//the Arduino's IP
IPAddress ip(192, 168, 8, 101);

//iPhone's IP for Ethernet connection (set manually via settings)
IPAddress outIp(192, 168, 8, 100);

//port number to listen on:
const unsigned int inPort = 10101;

//the port that react native is listening on:
const unsigned int outPort = 20000;


bool isSetupDone = false;
void setup() {
  Serial.begin(115200);
  delay(5000);
  ethernetSetup();
}

void setup1() {
  Serial.begin(115200);
  delay(8000);
  isSetupDone = true;
}

void loop() {
  if (isSetupDone) {
    ethernetLoop();
    serialLoop();
  }
}
