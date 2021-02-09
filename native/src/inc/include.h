#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include <FS.h>
#include <PubSubClient.h>
#include <Bounce2.h>
#include <ESPAsyncWebServer.h>
#include <Ticker.h>

#include "../config/hardware.h"
#include "../config/software.h"
#include "../config/mqtt.h"
#include "types.h"
