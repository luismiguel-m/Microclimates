void startLCD()
{
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.createChar (0,C);
}


void welcome()
{
  lcd.setCursor(0, 0);
  lcd.print("Iniciando");
  lcd.setCursor(0, 1);
  lcd.print("Sistema");
  delay(700);
  lcd.print(".");
  delay(900);
  lcd.print(".");
  delay(900);
  lcd.print(".");
  delay(900);
}


void printIncomingData()
{
  for (int c = 0; c <= 2; c ++) {
    if ( flag == true ) {
      flag = false;
      return;
    }
    updateData();
    printLCD();
    delay(1000);
  }
  

  if ( flag == true ) {
    flag = false;
    return;
  }


  for (int c = 0; c <= 5; c ++) {
    updateData();
    lcd.scrollDisplayLeft();
    delay(200);
  }

  delay(2000);
  
  for (int c = 0; c <= 5; c ++) {
    updateData();
    lcd.scrollDisplayRight();
    delay(200);
  }
}


void printLCD()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Estacion ");
  lcd.print(incomingData.ID);
  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print((int)incomingData.temp);
  lcd.write (byte (0));
  lcd.print("C");
  lcd.print(" HA:");
  lcd.print((int)incomingData.hA);
  lcd.print("%/T");
  lcd.print(" HS:");
  lcd.print((int)incomingData.hS);
  lcd.print("%");
}


void errorToConnect()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sin comunicacion");
  lcd.setCursor(0, 1);
  lcd.print("con estacion ");
  lcd.print( (int) station );
  delay(500);
}
