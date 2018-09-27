#include "inc/include.h"

void DEBUG_LN(const char *text) {
  Serial.println(text);
  webSocket().printfAll("%s\n", text);
}

template<typename... Args>
void DEBUG_F(const char *format, Args... args) {
  Serial.printf(format, args...);
  webSocket().printfAll(format, args...);
}
