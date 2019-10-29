# Умный домофон на ESP8266
[English](https://github.com/Anonym-tsk/smart-domofon/blob/master/README_EN.md) | **Русский**

Устройство умеет открывать домофон при входящем вызове. Работает только с координатными домофонами. Проверено с домофонами Visit, Cyfral, Metakom, Altis.

---

Нравится проект? [Поддержи автора](http://yasobe.ru/na/esphome)! Купи ему немного :beers: или :coffee:!

[![coffee](https://www.buymeacoffee.com/assets/img/custom_images/black_img.png)](http://yasobe.ru/na/esphome)

---

### Эта версия прошивки больше не поддерживается. Пожалуйста, используйте [новую прошивку на базе ESPHome](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/README.md).

## Используемые компоненты
* NodeMCU v3 x 1
* Двойной релейный модуль x1
* RGB светодиод x1
* Тактовая кнопка x1
* Оптрон x1
* Несколько резисторов

Вместо NodeMCU можно всять почти любую ESP с достаточным количеством GPIO (например, Wemos D1 Mini). Кнопка и светодиод не обязательны.

## Пример компонентов
1. [Оптопара PC817B](https://roboshop.spb.ru/PC817B)
2. [Реле электромеханическое 2-канальное](https://roboshop.spb.ru/SRD-05VDC-SL-C-2-channel-rele)
3. [NodeMCU V3](https://roboshop.spb.ru/NodeMCU-v3-dev-board)
4. [RGB светодиод на плате](https://roboshop.spb.ru/RGB-led-module)
5. [Кнопка тактовая 6х6х13мм](https://roboshop.spb.ru/KFC-A06-13H)
6. [Провода "мама-мама" 10см](https://roboshop.spb.ru/female-to-female-line)
7. [Провода "папа-мама" 10см](https://roboshop.spb.ru/male-to-female-line)
8. [Резисторы](https://roboshop.spb.ru/600-resist-set)
9. [microUSB кабель](https://roboshop.spb.ru/BS-410)

## Схема
![Scheme](https://raw.githubusercontent.com/Anonym-tsk/smart-domofon/master/scheme.jpeg)

*За схему спасибо Oleg Yu*

## Конфигурация и прошивка
1. Заполните настройки WiFi и MQTT в файле [software.h](https://github.com/Anonym-tsk/smart-domofon/blob/master/src/config/software.h)
2. Укажите `upload_port` в файле [platformio.ini](https://github.com/Anonym-tsk/smart-domofon/blob/master/platformio.ini)
3. Используйте [PlatformIO](https://platformio.org/platformio-ide) для компиляции и загрузки прошивки

## MQTT сообщения статуса (domofon/status)
* 'R' - ready; отправляется после успешной загрузки или в ответ на сообщение 'P'
* 'L' - last will message; отправляется когда устройство отключается от сети

## Входящие MQTT команды (domofon/in)
* 'O' - открыть дверь
* 'N' - отклонить вызов (дверь не откроется)
* 'P' - ping (ответом будет статус 'R')

## Информационные MQTT сообщения (domofon/out)
* 'C' - call; отправляется при входящем вызове
* 'H' - hangup; отправляется когда входящий вызов завершается
* 'B' - button; отправляется при открытии двери аппаратной кнопкой
* 'J' - reJected; отправляется когда вызов отклоняется аппаратной кнопкой
* 'S' - success; отправляется в ответ на команды 'O' и 'N'
* 'F' - fail; отправляется в ответ на команды 'O' и 'N' (означает, что команда была получена, но в данный момент не было входящего звонка)

## Интеграция с Home Assistant
![Home Assistant](https://raw.githubusercontent.com/Anonym-tsk/smart-domofon/master/homeassistant/ha.png)

[Конфигурация для Home Assistant с автоматизацией, сенсором и переключателями](https://github.com/Anonym-tsk/smart-domofon/blob/master/homeassistant/domofon.yaml)

Положите этот файл в `/config/packages/domofon.yaml` и исправьте используемые сервисы в автоматизации.
