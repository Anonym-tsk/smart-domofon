# Smart intercom with MQTT based on NodeMCUv3

[ESPHome](https://esphome.io/) version of Smart Intercom

[Scheme and parts](https://github.com/Anonym-tsk/smart-domofon/blob/master/README.md)

## Configuration and build
1. Fill in WiFi credentials in [domofon.yaml](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/domofon.yaml#L10)
2. Use [ESPHome](https://esphome.io) to build and upload firmware

## Home Assistant Telegram notifications

Put [this file](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/homeassistant/domofon.yaml) into `/config/packages/domofon.yaml` and correct notification service in automations.
