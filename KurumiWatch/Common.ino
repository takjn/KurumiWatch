
unsigned char key_read(void) {
  if (digitalRead(KEY_SELECT_PIN) == 0) {
    digitalWrite(24, LOW);
    while (digitalRead(KEY_SELECT_PIN) == 0);
    digitalWrite(24, HIGH);
    tick_counter = 0;
    return KEY_SELECT;
  } else if (digitalRead(KEY_PREV_PIN) == 0) {
    while (digitalRead(KEY_PREV_PIN) == 0);
    tick_counter = 0;
    return KEY_PREV;
  } else if (digitalRead(KEY_NEXT_PIN) == 0) {
    while (digitalRead(KEY_NEXT_PIN) == 0);
    tick_counter = 0;
    return KEY_NEXT;
  }
  
  return KEY_NONE;
}

void beep(void) {
  if (buzzer_volume != 0) {
    tone(BUZZER_PIN, 1024, BUZZER_VOLUMES[buzzer_volume]);
  }
}

