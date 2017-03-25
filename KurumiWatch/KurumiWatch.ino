#include <Arduino.h>
#include <RTC.h>
#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// setting for SSD1306
SSD1306AsciiWire oled;
#define I2C_ADDRESS 0x3C

// settings for I/O pins
#define BUZZER_PIN      10          // pin for buzzer
#define KEY_PIN_PREV    2           // pin for previous button
#define KEY_PIN_SELECT  3           // pin for select button
#define KEY_PIN_NEXT    4           // pin for next button
#define BATTERY_CHECK   A0          // pin for battery voltage

// settings for buzzer
const uint8_t buzzer_volumes[4] = { 0, 1, 5, 15 };  // 4 steps volume (0=silence)
int buzzer_volume = 0;                              // initial volume index

// settings for animation
#define ANIMATION_STEP 1      // animation smoothness (1=smooth, 10=no animation)
#define ANIMATION_MAXSTEP 4   // animation max step

// variables for animation
boolean animation_required = true;
uint8_t animation_progress = 0;    // animation progress (0=start, 10=end)

// settings for display
const int display_contrasts[4] = { 0, 50, 128, 255 };  // 4 steps contrast
int display_contrast = 0;
boolean display_flip = false;

// settings for power saving
const unsigned long DELAY_SLEEPS[4] = {0, 5000, 10000, 30000};  // sleep (millisec, 0=always on)
int delay_sleep = 2;
unsigned long int tick_counter = 0;

// variables for watch
RTC_TIMETYPE datetime = {15, 12, 31, 2, 23, 59, 30};

// mode
#define MODE_TIME 0        // Watch
//#define MODE_MENU 1        // Menu
//#define MODE_SETTINGS 2    // Settings
//#define MODE_SETTIME 3     // Date&Time
//#define MODE_SETSOUND 4    // Sound
//#define MODE_STOPWATCH 5   // Stopwatch
//#define MODE_SETDISPLAY 6  // Display
//#define MODE_GAME 7        // Game
uint8_t mode_current = MODE_TIME;
uint8_t mode_prev = MODE_TIME;



void sleep() {
  oled.ssd1306WriteCmd(0x0ae); // display off
  setPowerManagementMode(PM_STOP_MODE);
  delay(0xffffffff); // into stop mode
}

void resume() {
  setPowerManagementMode(PM_NORMAL_MODE);
  tick_counter = 0;

  digitalWrite(24, LOW);
  while(digitalRead(2) == LOW);
  digitalWrite(24, HIGH);
}

void tick_handler(unsigned long u32ms)
{
  tick_counter++;
}



//------------------------------------------------------------------------------
void setup() {
  pinMode(24, OUTPUT); //blue led
  digitalWrite(24, HIGH);
  
  // RTC initialize
  rtc_init();
  SUBCUD.subcud = 0xB8;  // http://japan.renesasrulz.com/gr_user_forum_japanese/f/gr-kurumi/631/gr-kurumi-rtc
  rtc_set_time(&datetime); // RTCに初期値をセットしてRTCをスタート
  
  Wire.begin();     
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setContrast(255);
  oled.clear();

  // setup for the power management
  pinMode(KEY_PIN_PREV, INPUT_PULLUP);
  pinMode(KEY_PIN_SELECT, INPUT_PULLUP);
  pinMode(KEY_PIN_NEXT, INPUT_PULLUP);
  attachInterrupt(0, resume, FALLING);
  attachIntervalTimerHandler(tick_handler);

  sleep();
}

void loop() {
  oled.ssd1306WriteCmd(0x0af); // display on
  drawWatch();
  
  if (delay_sleep > 0 & tick_counter > DELAY_SLEEPS[delay_sleep]) {
    sleep();
  }
  
  delay(100);
}
