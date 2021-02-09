# Smart intercom based on ESP8266 ([ESPHome](https://esphome.io/) version)
**English** | [Русский](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/README.md)

---

Enjoy my work? [Help me out](http://yasobe.ru/na/esphome) for a couple of :beers: or a :coffee:!

[![coffee](https://www.buymeacoffee.com/assets/img/custom_images/black_img.png)](http://yasobe.ru/na/esphome)

---

[Scheme and parts](https://github.com/Anonym-tsk/smart-domofon/blob/master/native/README_EN.md#example-parts)

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
