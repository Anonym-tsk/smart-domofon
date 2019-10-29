# Умный домофон на ESP8266 (версия на [ESPHome](https://esphome.io/))
[English](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/README_EN.md) | **Русский**

---

Нравится проект? [Поддержи автора](http://yasobe.ru/na/esphome)! Купи ему немного :beers: или :coffee:!

[![coffee](https://www.buymeacoffee.com/assets/img/custom_images/black_img.png)](http://yasobe.ru/na/esphome)

---

[Схема и компоненты](https://github.com/Anonym-tsk/smart-domofon/blob/master/README.md)

## Кнопка и индикация
* Красный светодиод мигает
    * Входящий вызов
* Синий светодиод мигает
    * Подключение к WiFi или Home Assistant
* Зеленый светодиод мигает
    * Одиночными - режим "открыть дверь один раз"
    * Двойными - режим "открывать дверь всегда"
* Одиночное нажатие кнопки
    * Нет входящего вызова - включит режим автоматического открытия (открыть один раз по первому нажатию, постоянное открыти по второму)
    * Входящий звонок - откроет дверь
* Долгое нажатие кнопки
    * Нет входящего вызова - выключит режим автоматического открытия
    * Входящий звонок - отклонит вызов

## Конфигурация и прошивка
1. Заполните настройки WiFi в файле [domofon.yaml](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/domofon.yaml#L18)
2. Используйте [ESPHome](https://esphome.io) для компиляции и загрузки прошивки

## Уведомления в Telegram через Home Assistant

Положите [этот файл](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/homeassistant/domofon.yaml) в `/config/packages/domofon.yaml` и исправьте используемые сервисы в автоматизации.
