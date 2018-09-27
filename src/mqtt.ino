#include "inc/include.h"

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void mqttSendCommand(const char *msg) {
  mqttClient.publish(MQTT_TOPIC_OUT, msg, 1);
  DEBUG_F("[MQTT] Message sent: %s\n", msg);
}

void mqttSendStatus(const char *msg) {
  mqttClient.publish(MQTT_TOPIC_STATUS, msg, 1);
  DEBUG_F("[MQTT] Status sent: %s\n", msg);
}

void onMqttMsgReceived(char* topic, byte* payload, unsigned int len) {
  if (len != 1) {
    char* command = (char*)malloc(len + 2);
    memcpy(command, payload, len);
    command[len] = '\0';

    DEBUG_F("[MQTT] Message received [%u]: %s\n", len, command);
    return;
  }

  char cmd = (char)payload[0];
  DEBUG_F("[MQTT] Command received: %c\n", cmd);

  switch (cmd) {
    case MSG_IN_OPEN:
      action = OPEN;
      break;

    case MSG_IN_REJECT:
      action = REJECT;
      break;

    case MSG_IN_PING:
      mqttSendStatus(MSG_STATUS_READY);
      break;

    default:
      DEBUG_LN("[MQTT] Unknown command");
      break;
  }
}

void mqttConnect() {
  DEBUG_F("[MQTT] (Re)connecting to server on %s...\n", MQTT_SERVER_ADDR);

  for (int i = 0; !mqttClient.connected(); i++) {
    // Если не получилось за 5 попыток - перезагружаемся
    if (i >= 5) {
      ESP.restart();
      return;
    }

    if (!mqttClient.connect(MQTT_CLIENT_ID, MQTT_USER_NAME, MQTT_USER_PASSWORD, MQTT_TOPIC_STATUS, 0, 0, MSG_STATUS_LAST_WILL)) {
      // Ждем 2 секунды
      DEBUG_F(".");
      ledBlink(PIN_LED_GREEN, 8);
    }
  }

  DEBUG_LN("\n[MQTT] Done");
  mqttSendStatus(MSG_STATUS_READY);
  mqttClient.subscribe(MQTT_TOPIC_IN);

  setStateIdle();
  DEBUG_LN("[MQTT] Current state: IDLE");
}

void mqttStop() {
  mqttClient.disconnect();
  ledOff();
}

void mqttSetup() {
  mqttClient.setServer(MQTT_SERVER_ADDR, MQTT_SERVER_PORT);
  mqttClient.setCallback(onMqttMsgReceived);
  mqttConnect();
}

void mqttLoop() {
  if (!mqttClient.connected()) {
    mqttConnect();
  }
  mqttClient.loop();
}
