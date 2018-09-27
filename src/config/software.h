#ifndef SW_H_
#define SW_H_

// Software configuration
#define HOST_NAME                 "domofon"
#define HOST_PASSWORD             "domofon"
#define OTA_PORT                  8266
#define WIFI_SSID                 ""
#define WIFI_PASSWORD             ""

#define MQTT_SERVER_ADDR          ""
#define MQTT_SERVER_PORT          1883
#define MQTT_USER_NAME            ""
#define MQTT_USER_PASSWORD        ""
#define MQTT_CLIENT_ID            "domofon"
#define MQTT_TOPIC_IN             "domofon/in"
#define MQTT_TOPIC_OUT            "domofon/out"
#define MQTT_TOPIC_STATUS         "domofon/status"

#define CALL_HANGUP_DETECT_DELAY  3000
#define RELAY_ANSWER_ON_TIME      1500
#define RELAY_OPEN_ON_TIME        600

#endif // SW_H_
