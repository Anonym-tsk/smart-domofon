#include "inc/include.h"

void wifiDisconnect() {
  WiFi.disconnect();
  ledOff();
}

void wifiConnect() {
  DEBUG_F("[WIFI] (Re)connecting to \"%s\"\n", WIFI_SSID);

  WiFi.mode(WIFI_STA);
  WiFi.hostname(HOST_NAME);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  for (int i = 0; WiFi.status() != WL_CONNECTED; i++) {
    // Если не получилось за 5 попыток - перезагружаемся
    if (i >= 5) {
      ESP.restart();
      return;
    }

    // Ждем 2 секунды
    DEBUG_F(".");
    ledBlink(PIN_LED_BLUE, 8);
  }

  DEBUG_LN("\n[WIFI] Done");
  DEBUG_F("[WIFI] IP address: %s\n", WiFi.localIP().toString().c_str());
}

void wifiReconnect() {
  wifiDisconnect();
  wifiConnect();
}

void wifiSetup() {
  wifiConnect();
}

void wifiLoop() {
  if (WiFi.status() != WL_CONNECTED) {
    wifiReconnect();
  }
}
