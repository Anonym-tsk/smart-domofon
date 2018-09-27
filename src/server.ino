#include "inc/include.h"

AsyncWebServer _server(80);
AsyncWebSocket _ws("/ws");

AsyncWebSocket webSocket() {
    return _ws;
}

void _wsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len) {
  uint32_t id = client->id();

  switch (type) {
    case WS_EVT_CONNECT:
      DEBUG_F("[WS] Client connected - ID: %u\n", id);
      client->ping();
      break;

    case WS_EVT_DISCONNECT:
      DEBUG_F("[WS] Client disconnected - ID: %u\n", id);
      break;

    case WS_EVT_ERROR:
      DEBUG_F("[WS] Error - ID: %u, code: %u, error: %s\n", id, *((uint16_t*)arg), (char*)data);
      break;

    case WS_EVT_PONG:
      DEBUG_F("[WS] Pong - ID: %u\n", id);
      break;

    case WS_EVT_DATA:
      AwsFrameInfo * info = (AwsFrameInfo*)arg;
      if (info->final && info->index == 0 && info->len == len) {
        if (info->opcode == WS_TEXT) {
          DEBUG_F("[WS] Message received - ID: %u, message: %s\n", id, (char*)data);
        } else {
          DEBUG_F("[WS] Bynary messages not supported - ID: %u\n", id);
        }
      } else if (info->final && (info->index + len) == info->len) {
        DEBUG_F("[WS] Message too long - ID: %u\n", id);
      }
      break;
  }
}

void webServerStop() {
  DEBUG_LN("[WS] Server stopped");
  SPIFFS.end();
  _ws.enable(false);
  _ws.closeAll(1012);
}

void webServerSetup() {
  SPIFFS.begin();

  _server.rewrite("/", "/index.html");
  _server.onNotFound([](AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "404: Not Found");
  });
  _server.on("/restart", HTTP_POST, [](AsyncWebServerRequest *request) {
    request->send(200);
    DEBUG_LN("Restarting...");
    webServerStop();
    mqttStop();
    deferredRestart(200);
  });
  _server.serveStatic("/", SPIFFS, "/");
  _server.begin();

  _ws.onEvent(_wsEvent);
  _server.addHandler(&_ws);
}
