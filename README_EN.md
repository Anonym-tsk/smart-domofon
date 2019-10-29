# Smart intercom based on ESP8266
**English** | [Русский](https://github.com/Anonym-tsk/smart-domofon/blob/master/README.md)

This device can send "door open" command to intercom main unit after receiving of incoming call. It only works with coordinate line intercoms. Tested with Cyfral russian intercom.

---

Enjoy my work? [Help me out](http://yasobe.ru/na/esphome) for a couple of :beers: or a :coffee:!

[![coffee](https://www.buymeacoffee.com/assets/img/custom_images/black_img.png)](http://yasobe.ru/na/esphome)

---

### This is old deprecated version. Please use new [ESPHome version](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/README_EN.md)

## Parts used
* NodeMCU v3 x 1
* Double relay module x1 (or two single relay modules)
* LED x3 (or one RGB LED)
* Button x2
* Optocoupler x1
* Some resistors

Instead of NodeMCU, you can buy almost any ESP with enough count of GPIO (for example, Wemos D1 Mini). Button and LED are optional.

## Example Parts
1. [Оптопара PC817B](https://roboshop.spb.ru/PC817B)
2. [Реле электромеханическое 2-канальное](https://roboshop.spb.ru/SRD-05VDC-SL-C-2-channel-rele)
3. [NodeMCU V3](https://roboshop.spb.ru/NodeMCU-v3-dev-board)
4. [RGB светодиод на плате](https://roboshop.spb.ru/RGB-led-module)
5. [Кнопка тактовая 6х6х13мм KFC-A06-13H](https://roboshop.spb.ru/KFC-A06-13H)
6. [Провода "мама-мама" 10см, 20 шт.](https://roboshop.spb.ru/female-to-female-line)
7. [Провода "папа-мама" 10см, 20 шт.](https://roboshop.spb.ru/male-to-female-line)
8. [Резисторы](https://roboshop.spb.ru/600-resist-set)
9. [microUSB кабель](https://roboshop.spb.ru/BS-410)

## Scheme
![Scheme](https://raw.githubusercontent.com/Anonym-tsk/smart-domofon/master/scheme.jpeg)
*Thanks to Oleg Yu*

## Configuration and build
1. Fill in WiFi and MQTT credentials in [software.h](https://github.com/Anonym-tsk/smart-domofon/blob/master/src/config/software.h)
2. Fill in `upload_port` in [platformio.ini](https://github.com/Anonym-tsk/smart-domofon/blob/master/platformio.ini)
3. Use [PlatformIO](https://platformio.org/platformio-ide) to build and upload firmware

## Status MQTT messages (domofon/status)
* 'R' - ready; sent after successfull boot-up or after receiving of 'P' message
* 'L' - last will message; send when device goes offline

## Incoming MQTT messages (domofon/in)
* 'O' - door open command
* 'N' - call reject command (door will not open)
* 'P' - ping command (answers with 'R')

## Outgoing MQTT messages (domofon/out)
* 'C' - call; sent after detecting of incoming intercom call
* 'H' - hangup; sent after detected incoming call finished
* 'B' - button; sent when "door open" has been performed by green hw button press
* 'J' - reJected; sent when incoming call has been rejected by red hw button press
* 'S' - success; sent in response to 'O' or 'N' command
* 'F' - fail; sent in response to 'O' or 'N' command (this means that 'O' or 'N' command has been received but no incoming call detected)

## Home Assistant integration
![Home Assistant](https://raw.githubusercontent.com/Anonym-tsk/smart-domofon/master/homeassistant/ha.png)

[Full configuration with sensor, switches and automations](https://github.com/Anonym-tsk/smart-domofon/blob/master/homeassistant/domofon.yaml)

Put this file into `/config/packages/domofon.yaml` and correct notification service in automations.
