int cursol = 0;
int prev_cursol = -1;

#define CENTER_X 54
#define MARGIN_X 54
#define ANIMATION_STEPS 9

#define MENU_COUNT 4
#define MENU_TITLE "Setup"
const char *MENU_SUB_TITLE[MENU_COUNT] = {"WATCH", "CONTRAST", "SOUND", "POWER SAVING"};

void drawMenu(unsigned char key) {
  // return if idle
  if (key == KEY_NONE && cursol == prev_cursol) return;
  
  // key handler
  if (key == KEY_SELECT) {
    if (cursol == 0) {
      // Time
      prev_cursol = -1;
      oled.clear();
      mode_current = MODE_TIME;
      return;
    } else if (cursol == 1) {
      // Contrast
      // TBD
    } else if (cursol == 2) {
      // Sound
      // TBD
    } else if (cursol == 3) {
      // Power Saving
      // TBD
    }
  }
  else if (key == KEY_NEXT) {
    cursol++;
    if (cursol == MENU_COUNT) cursol = 0;
  }
  else if (key == KEY_PREV) {
    if (cursol < 1) {
      cursol = MENU_COUNT - 1;
    } else {
      cursol--;
    }
  }
  
  // draw title and subtitle
  oled.setFont(BM_tube9x8);
  oled.set1X();
  oled.setCursor(0, 0);
  oled.print(MENU_TITLE);
  oled.clearToEOL();
  oled.setCursor(0, 7);
  oled.print(MENU_SUB_TITLE[cursol]);
  oled.clearToEOL();
  
  // draw contents
  oled.set2X();
  if (cursol != prev_cursol) {
    int dx = (cursol - prev_cursol) * MARGIN_X / ANIMATION_STEPS;
    int x = CENTER_X - MARGIN_X * prev_cursol;
    
    for (uint8_t i=0; i<ANIMATION_STEPS; i++) {
      x -= dx;
      drawMenuSub(x);
    }
    delay(200);
    prev_cursol = cursol;
  }
  else {
    drawMenuSub(CENTER_X - MARGIN_X * cursol);
  }

  oled.setCol(34);
  oled.print("(");
  
  oled.setCol(74);
  oled.print(")");
  
}

void drawMenuSub(int x) {
  oled.setCursor(0, 3);
  oled.clearToEOL();
  
  printWithCheckBoundry(x + MARGIN_X * 0, "{");
  printWithCheckBoundry(x + MARGIN_X * 1, "|");
  printWithCheckBoundry(x + MARGIN_X * 2, "}");
  printWithCheckBoundry(x + MARGIN_X * 3, "~");

}

void printWithCheckBoundry(int x, String str) {
  if (x>=0 && x < oled.displayWidth()) {
    oled.setCol(x);
    oled.print(str);
  }
}
