void getDataDTH11()
{
  // Leemos la temperatura en grados Celcius
  station.temp = (float) dht.readTemperature();
  // Leemos la humedad relativa
  station.hA = (float) dht.readHumidity();
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
