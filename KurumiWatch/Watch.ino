const char *DayShortStr[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
const char *MonthShortStr[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

void drawWatch() {
  rtc_get_time(&datetime); // RTCレジスタ内容をmyRTCに読み出す

  // draw date strings
  String s = DayShortStr[datetime.weekday];
  s += " ";
  if (datetime.day<10) {
    s += "0";
  }
  s += datetime.day;
  s += " ";
  s += MonthShortStr[datetime.mon - 1];
  s += " ";
  s += (datetime.year+2000);

  oled.set2X();
  oled.setFont(TomThumbs3x6);
  oled.setCursor(0, 0);
  oled.print(s);
  
  char buffer[10];
  sprintf(buffer, "%02d:%02d", datetime.hour, datetime.min);
  oled.setFont(lcdnums12x16);
  oled.setCursor(0, 2);
  oled.print(buffer);

  oled.set1X();
  oled.setCursor(0, 7);
  oled.setFont(TomThumbs3x6);
  oled.print("Watch "); 
  oled.print(getTemperature(TEMP_MODE_CELSIUS)); 
  oled.print("°C"); 
}

