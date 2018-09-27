#include "inc/include.h"

// Код частично заимствован и переделан
// @see https://github.com/Metori/mqtt_domofon

void setup() {
  hardwareSetup();
  wifiSetup();
  otaSetup();
  mqttSetup();
  webServerSetup();
  domofonSetup();
}

void loop() {
  wifiLoop();
  otaLoop();
  mqttLoop();
  domofonLoop();
}
