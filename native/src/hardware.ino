#include "inc/include.h"

Ticker _defer_restart;

void hardwareSetup() {
  pinMode(PIN_BUTTON_GREEN, INPUT_PULLUP);
  pinMode(PIN_BUTTON_RED, INPUT_PULLUP);
  pinMode(PIN_CALL_DETECT, INPUT_PULLUP);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);
  pinMode(PIN_RELAY_ANSWER, OUTPUT);
  pinMode(PIN_RELAY_DOOR_OPEN, OUTPUT);

  digitalWrite(PIN_LED_RED, LED_OFF);
  digitalWrite(PIN_LED_GREEN, LED_OFF);
  digitalWrite(PIN_LED_BLUE, LED_OFF);
  digitalWrite(PIN_RELAY_ANSWER, RELAY_OFF);
  digitalWrite(PIN_RELAY_DOOR_OPEN, RELAY_OFF);
}

void restart() {
  ESP.reset();
}

void deferredRestart(unsigned long delay) {
    _defer_restart.once_ms(delay, restart);
}
