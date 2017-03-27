const char *DayShortStr[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
const char *MonthShortStr[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void drawWatch(unsigned char key) {
  if (key == KEY_SELECT) {
    mode_current = MODE_MENU;
    return;
  }
  
  rtc_get_time(&datetime);

  // draw date strings
  oled.setFont(BM_tube9x8);
  oled.set1X();
  oled.setCursor(0, 0);
  oled.print(DayShortStr[datetime.weekday]);
  oled.setCursor(33, 0);
  if (datetime.day<10) {
    oled.print("0");
  }
  oled.print(datetime.day);
  oled.setCursor(56, 0);
  oled.print(MonthShortStr[datetime.mon - 1]);
  oled.setCursor(89, 0);
  oled.print((datetime.year+2000));
 
  // draw time strings
  oled.setCursor(2, 3);
  oled.set2X();
  if (datetime.hour<10) {
    oled.print("0");
  }
  oled.print(datetime.hour);
  oled.print(':');
  if (datetime.min<10) {
    oled.print("0");
  }
  oled.print(datetime.min);

  oled.set1X();
  oled.setCursor(107, 4);
  if (datetime.second<10) {
    oled.print('0');
  }
  oled.print(datetime.second);
  
  oled.set1X();
  oled.setCursor(0, 7);
  oled.setFont(BM_tube9x8);
//  oled.print("Watch "); 
  oled.print(getTemperature(TEMP_MODE_CELSIUS)); 
  oled.print("°C"); 
}

