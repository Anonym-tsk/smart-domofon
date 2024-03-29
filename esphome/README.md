# Умный домофон на ESP8266 (версия на [ESPHome](https://esphome.io/))
[English](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/README_EN.md) | **Русский**

---

Нравится проект? [Поддержи автора](https://yoomoney.ru/to/410019180291197)! Купи ему немного :beers: или :coffee:!

[![coffee](https://www.buymeacoffee.com/assets/img/custom_images/black_img.png)](https://yoomoney.ru/to/410019180291197)

---

[Схема и компоненты](https://github.com/Anonym-tsk/smart-domofon/blob/master/native/README.md#пример-компонентов)

[Чат в Telegram](https://t.me/esphome)

## Кнопка и индикация
* Красный светодиод мигает
    * Входящий вызов
* Красный светодиод горит
    * Включен режим "отклонять всегда"
* Синий светодиод мигает
    * Подключение к WiFi или Home Assistant
* Зеленый светодиод мигает
    * Включен режим "открыть дверь один раз"
* Зеленый светодиод горит
    * Включен режим "открывать дверь всегда"
* Одиночное нажатие кнопки
    * Нет входящего вызова - меняет режим автоматического открытия или отклонения (открыть один раз по первому нажатию, постоянное открытие по второму, отклонение по третьему)
    * Входящий звонок - откроет дверь
* Долгое нажатие кнопки
    * Нет входящего вызова - выключит режим автоматического открытия или отклонения
    * Входящий звонок - отклонит вызов

## Конфигурация и прошивка
1. Заполните настройки WiFi в файле [domofon.yaml](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/domofon.yaml#L20)
2. Используйте [ESPHome](https://esphome.io) для компиляции и загрузки прошивки

## Уведомления в Telegram через Home Assistant

Положите [этот файл](https://github.com/Anonym-tsk/smart-domofon/blob/master/esphome/homeassistant/domofon.yaml) в `/config/packages/domofon.yaml` и исправьте используемые сервисы в автоматизации.
