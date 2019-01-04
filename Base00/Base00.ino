//          == Base/ Master Node 00==

#include <SPI.h>
#include<Wire.h>
#include <RF24Network.h>
#include <RF24.h>
#include <LiquidCrystal_I2C.h>

//===== === =====//

RF24 radio(9, 10);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
RF24NetworkHeader header;        // Header RF24Network
const uint16_t this_node = 00;   // Address of this node in Octal format ( 04,031, etc)
const uint16_t node01 = 01;      // Address of the other node in Octal format
const uint16_t node02 = 02;
uint16_t station = node01;       // Current station from which information is being received


LiquidCrystal_I2C lcd(0x27, 16, 2);
byte C[8] = { B00100, B01010, B00100, B00000, B00000, B00000, B00000, B00000 };


typedef struct {
  float temp, hA, hS;
  int ID;
}
st;
st incomingData;


const int timeThreshold = 150;
const int buttonPin = 2;
long long timeCounter = 0;


bool flag = false;

//===== === =====//

void setup() {
  SPI.begin();
  radio.begin();
  network.begin(78, this_node);  //(channel, node address)
  radio.setPALevel(RF24_PA_MAX);

  startLCD();

  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), changeStation, FALLING);

  welcome();
}

void loop() {
  network.update();
  scanNetwork();
}
