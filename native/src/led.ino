#include "inc/include.h"

void ledBlink(int pin, int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(pin, LED_ON);
    delay(125);
    digitalWrite(pin, LED_OFF);
    delay(125);
  }
}

void ledOff() {
  digitalWrite(PIN_LED_GREEN, LED_OFF);
  digitalWrite(PIN_LED_RED, LED_OFF);
  digitalWrite(PIN_LED_BLUE, LED_OFF);
}

void ledOn(int pin) {
  ledOff();
  digitalWrite(pin, LED_ON);
}
