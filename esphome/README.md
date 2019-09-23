# Smart intercom based on NodeMCUv3

[ESPHome](https://esphome.io/) version of Smart Intercom

[Scheme and parts](https://github.com/Anonym-tsk/smart-domofon/blob/master/README.md)

## Button and LED
* Red LED blinks
    * Incoming call
* Blue LED blinks
    * Connecting to WiFi or Home Assistant
* Green LED blinks
    * Single - "automatically open once" mode
    * Double - "automatically open permanent" mode
* Short button click
    * No call - enables automatically open door mode (once by first click and permanent by second click)
    * Incoming call - accept call and open door
* Long button click
    * No call - disables automatically open door mode
    * Incoming call - reject call

## Configuration and build
1. Fill in WiFi credentials in [domofon.yaml](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/domofon.yaml#L18)
2. Use [ESPHome](https://esphome.io) to build and upload firmware

## Home Assistant Telegram notifications

Put [this file](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/homeassistant/domofon.yaml) into `/config/packages/domofon.yaml` and correct notification service in automations.
