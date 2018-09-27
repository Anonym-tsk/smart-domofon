#include "inc/include.h"

void otaSetup() {
  ArduinoOTA.setHostname(HOST_NAME);
  ArduinoOTA.setPort(OTA_PORT);

  ArduinoOTA.setPassword(HOST_PASSWORD);

  ArduinoOTA.onStart([]() {
    DEBUG_LN("[OTA] Start update");
    webServerStop();
    mqttStop();
  });

  ArduinoOTA.onEnd([]() {
    DEBUG_LN("[OTA] End update");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    DEBUG_F("[OTA] Progress: %u%%\n", (progress / (total / 100)));
  });

  ArduinoOTA.onError([](ota_error_t error) {
    String type;
    switch (error) {
      //  "Ошибка при аутентификации"
      case OTA_AUTH_ERROR:
        type = "Auth Failed";
        break;
      //  "Ошибка при начале OTA-апдейта"
      case OTA_BEGIN_ERROR:
        type = "Begin Failed";
        break;
      //  "Ошибка при подключении"
      case OTA_CONNECT_ERROR:
        type = "Connect Failed";
        break;
      //  "Ошибка при получении данных"
      case OTA_RECEIVE_ERROR:
        type = "Receive Failed";
        break;
      //  "Ошибка при завершении OTA-апдейта"
      case OTA_END_ERROR:
        type = "End Failed";
        break;
      default:
        type = "Unknown";
    }

    DEBUG_F("[OTA] Error[%u]: %s\n", error, type.c_str());
  });

  ArduinoOTA.begin();
}

void otaLoop() {
  ArduinoOTA.handle();
}
