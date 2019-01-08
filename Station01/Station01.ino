//        == Node 01 (Child of Master node 00) ==

#include <SPI.h>
#include <RF24Network.h>
#include <RF24.h>
#include <DHT.h>

//===== === =====//

RF24 radio(9, 10);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 01;   // Address of our node in Octal format ( 04,031, etc)
const uint16_t master00 = 00;    // Address of the other node in Octal format

typedef struct {
  float temp, hA, hS;
  int ID = (int) this_node;
}
st;
st station;

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define sensorHs A0

//===== === =====//

void setup() {
  SPI.begin();

  radio.begin();
  network.begin(78, this_node);  //(channel, node address)
  radio.setPALevel(RF24_PA_MAX);

  dht.begin();
}



void loop() {
  network.update();
  sendDataToNetwork();
}
