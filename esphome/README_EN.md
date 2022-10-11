# Smart intercom based on ESP8266 ([ESPHome](https://esphome.io/) version)
**English** | [Русский](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/README.md)

---

Enjoy my work? [Help me out](https://yoomoney.ru/to/410019180291197) for a couple of :beers: or a :coffee:!

[![coffee](https://www.buymeacoffee.com/assets/img/custom_images/black_img.png)](https://yoomoney.ru/to/410019180291197)

---

[Scheme and parts](https://github.com/Anonym-tsk/smart-domofon/blob/master/native/README_EN.md#example-parts)

[Telegram chat](https://t.me/esphome)

## Button and LED
* Red LED blinks
    * Incoming call
* Red LED is on
    * "Reject calls" mode
* Blue LED blinks
    * Connecting to WiFi or Home Assistant
* Green LED blinks
    * "Automatically open once" mode
* Green LED is on
    * "Automatically open permanent" mode
* Short button click
    * No call - enables automatically open/reject door mode (once by first click, permanent by second click, reject by third click)
    * Incoming call - accept call and open door
* Long button click
    * No call - disables automatically open/reject door mode
    * Incoming call - reject call

## Configuration and build
1. Fill in WiFi credentials in [domofon.yaml](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/domofon.yaml#L20)
2. Use [ESPHome](https://esphome.io) to build and upload firmware

## Home Assistant Telegram notifications

Put [this file](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/homeassistant/domofon.yaml) into `/config/packages/domofon.yaml` and correct notification service in automations.
