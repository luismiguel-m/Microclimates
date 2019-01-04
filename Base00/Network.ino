void scanNetwork()
{
  if ( network.available() ) {     // Is there any incoming data?
    getData();
  } else {
    errorToConnect();
  }
}


void getData()
{
  //===== Receiving =====//
  updateData();
  if (header.from_node == station) {    // If data comes from current Node selected
    printIncomingData();
  }
}


void updateData()
{
  network.update();
  network.read(header, &incomingData, sizeof(incomingData)); // Read the incoming data
}


void changeStation()
{
  if (millis() > timeCounter + timeThreshold)
  {
    if (station == node01) {
      station = node02;
    } else {
      station = node01;
    }
    timeCounter = millis();
    flag = true;
  }
}
