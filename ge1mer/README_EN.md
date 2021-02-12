# Smart intercom based ([ESPHome](https://esphome.io/) version by [Ge1mer](https://github.com/Ge1mer))
**English** | [Русский](https://github.com/Anonym-tsk/smart-domofon/blob/master/ge1mer/README.md)

---

Enjoy my work? [Help me out](http://yasobe.ru/na/esphome) for a couple of :beers: or a :coffee:!

[![coffee](https://www.buymeacoffee.com/assets/img/custom_images/black_img.png)](http://yasobe.ru/na/esphome)

---

[Scheme and parts](https://easyeda.com/ilmir73/domofon)

[Telegram chat](https://t.me/domofon_esp)

![Board](https://raw.githubusercontent.com/Anonym-tsk/smart-domofon/master/ge1mer/board.jpeg)

![Connection](https://raw.githubusercontent.com/Anonym-tsk/smart-domofon/master/ge1mer/connection.jpeg)

## Features and modes
* Automatic door opening mode (one call or permanent)
* Automatic call rejection mode
* Silent mode (one call or permanent)
* [Home Assistant](https://www.home-assistant.io/) integration
* Notifications and controls via Telegram
* Adjust LED brightness
* OTA updates

## Button and LED
* Red LED blinks
    * Incoming call
* Red LED is on
    * "Reject calls" mode
* Blue LED blinks
    * Connecting to WiFi or Home Assistant
* Blue LED is on
    * Silent mode
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
1. Fill in WiFi credentials in [domofon.yaml](https://github.com/Anonym-tsk/smart-domofon/blob/master/ge1mer/domofon.yaml#L21)
2. Use [ESPHome](https://esphome.io) to build and upload firmware

## Home Assistant Telegram notifications

Put [this file](https://github.com/Anonym-tsk/smart-domofon/blob/master/ge1mer/homeassistant/domofon.yaml) into `/config/packages/domofon.yaml` and correct notification service in automations.
