# Умный домофон (версия на [ESPHome](https://esphome.io/) от [Ge1mer](https://github.com/Ge1mer))
[English](https://github.com/Anonym-tsk/smart-domofon/blob/master/ge1mer/README_EN.md) | **Русский**

---

Нравится проект? [Поддержи автора](http://yasobe.ru/na/esphome)! Купи ему немного :beers: или :coffee:!

[![coffee](https://www.buymeacoffee.com/assets/img/custom_images/black_img.png)](http://yasobe.ru/na/esphome)

---

[Схема и компоненты](https://easyeda.com/ilmir73/domofon)

[Чат в Telegram](https://t.me/domofon_esp)

![Board](https://raw.githubusercontent.com/Anonym-tsk/smart-domofon/master/ge1mer/board.jpeg)

## Возможности и режимы
* Режим автоматического открытия двери (одиночный и постоянный)
* Режим автоматического отклонения вызова
* Режим "без звука" постоянный или на один звонок
* Интеграция с [Home Assistant](https://www.home-assistant.io/)
* Уведомления и управление через Telegram
* Настройка яркости светодиода

## Кнопка и индикация
* Красный светодиод мигает
    * Входящий вызов
* Красный светодиод горит
    * Включен режим "отклонять всегда"
* Синий светодиод мигает
    * Подключение к WiFi или Home Assistant
* Голубой светодиод горит
    * Включен режим "без звука"
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
1. Заполните настройки WiFi в файле [domofon.yaml](https://github.com/Anonym-tsk/smart-domofon/blob/master/ge1mer/domofon.yaml#L21)
2. Используйте [ESPHome](https://esphome.io) для компиляции и загрузки прошивки

## Уведомления в Telegram через Home Assistant

Положите [этот файл](https://github.com/Anonym-tsk/smart-domofon/blob/master/ge1mer/homeassistant/domofon.yaml) в `/config/packages/domofon.yaml` и исправьте используемые сервисы в автоматизации.
