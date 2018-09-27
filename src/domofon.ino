#include "inc/include.h"

EState state = IDLE;
EAction action = NO_ACTION;

Bounce debouncerBtnGreen = Bounce();
Bounce debouncerBtnRed = Bounce();

unsigned long lastCallDetectedTime = 0;

void callAnswer() {
  DEBUG_LN("[HW] Call answer...");
  digitalWrite(PIN_RELAY_DOOR_OPEN, RELAY_OFF);
  digitalWrite(PIN_RELAY_ANSWER, RELAY_ON);
  DEBUG_LN("[HW] Done");
}

void callHangUp() {
  DEBUG_LN("[HW] Hang up...");
  digitalWrite(PIN_RELAY_ANSWER, RELAY_OFF);
  digitalWrite(PIN_RELAY_DOOR_OPEN, RELAY_OFF);
  DEBUG_LN("[HW] Done");
}

void doorOpen() {
  DEBUG_LN("[HW] Door open...");
  digitalWrite(PIN_RELAY_DOOR_OPEN, RELAY_ON);
  delay(RELAY_OPEN_ON_TIME);
  digitalWrite(PIN_RELAY_DOOR_OPEN, RELAY_OFF);
  DEBUG_LN("[HW] Done");
}

void answerAndOpen() {
  callAnswer();
  delay(RELAY_ANSWER_ON_TIME);
  doorOpen();
  callHangUp();
}

void answerAndReject() {
  callAnswer();
  delay(RELAY_ANSWER_ON_TIME);
  callHangUp();
}

void handleIdle(EState oldState) {
  if (oldState != IDLE) {
    mqttSendCommand(MSG_OUT_HANGUP);
    ledOff();
    DEBUG_LN("[HW] Current state: IDLE");
  }

  if (action != NO_ACTION) {
    mqttSendCommand(MSG_OUT_FAIL);
    action = NO_ACTION;
  }

  if (debouncerBtnGreen.fell()) {
    DEBUG_LN("[HW] Button click");
    ledBlink(PIN_LED_GREEN, 2);
  }
}

void handleCall(EState oldState) {
  if (oldState != CALL) {
    action = NO_ACTION;
    mqttSendCommand(MSG_OUT_CALL);
    ledOn(PIN_LED_RED);
    DEBUG_LN("[HW] Current state: CALL");
  }

  if (action == NO_ACTION) {
    if (debouncerBtnRed.fell()) {
      action = REJECT_BY_BUTTON;
    } else if (debouncerBtnGreen.fell()) {
      action = OPEN_BY_BUTTON;
    }
  }

  switch (action) {
    case OPEN_BY_BUTTON:
      answerAndOpen();
      mqttSendCommand(MSG_OUT_OPENED_BY_BUTTON);
      break;

    case REJECT_BY_BUTTON:
      answerAndReject();
      mqttSendCommand(MSG_OUT_REJECTED_BY_BUTTON);
      break;

    case OPEN:
      answerAndOpen();
      mqttSendCommand(MSG_OUT_SUCCESS);
      break;

    case REJECT:
      answerAndReject();
      mqttSendCommand(MSG_OUT_SUCCESS);
      break;

    default:
      break;
  }

  action = NO_ACTION;
}

void setStateIdle() {
  state = IDLE;
}

void setStateCall() {
  state = CALL;
}

void domofonSetup() {
  debouncerBtnGreen.attach(PIN_BUTTON_GREEN);
  debouncerBtnGreen.interval(25);
  debouncerBtnRed.attach(PIN_BUTTON_RED);
  debouncerBtnRed.interval(25);
}

void domofonLoop() {
  debouncerBtnGreen.update();
  debouncerBtnRed.update();

  EState oldState = state;

  if (digitalRead(PIN_CALL_DETECT) == LOW) {
    setStateCall();
    lastCallDetectedTime = millis();
  } else if (millis() - lastCallDetectedTime > CALL_HANGUP_DETECT_DELAY) {
    setStateIdle();
  }

  switch (state) {
    case IDLE:
      handleIdle(oldState);
      break;

    case CALL:
      handleCall(oldState);
      break;
  }
}
