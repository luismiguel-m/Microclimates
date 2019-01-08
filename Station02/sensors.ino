void getDataDTH11()
{
  station.temp = dht.readTemperature();  // Read the temperature in degrees Celsius
  station.hA = dht.readHumidity();  // Read relative humidity
}


void getFloorHumidity()
{
  station.hS = map( analogRead( sensorHs ), 0, 1023, 100, 0);
}


void getData()
{
  getDataDTH11();
  getFloorHumidity();
}
