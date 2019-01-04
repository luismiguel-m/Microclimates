void sendDataToNetwork()
{
  getData();
  RF24NetworkHeader header(master00);     // (Address where the data is going)
  network.write(header, &station, sizeof(station)); // Send the data
  delay(200);
}
