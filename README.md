# Smart intercom with MQTT based on NodeMCUv3

This device can send "door open" command to intercom main unit after receiving of incoming call. It only works with coordinate line intercoms. Tested with Cyfral russian intercom.

Thanks to [Metori](https://github.com/Metori) for [original progect](https://github.com/Metori/mqtt_domofon)

## Parts used:
* NodeMCU v3 x 1
* Double relay module x1 (or two single relay modules)
* LED x3 (or one RGB LED)
* Button x2
* Optocoupler x1
* Some resistors

## Status MQTT messages (domofon/status):
* 'R' - ready; sent after successfull boot-up or after receiving of 'P' message
* 'L' - last will message; send when device goes offline

## Incoming MQTT messages (domofon/in):
* 'O' - door open command
* 'N' - call reject command (door will not open)
* 'P' - ping command (answers with 'R')

## Outgoing MQTT messages (domofon/out):
* 'C' - call; sent after detecting of incoming intercom call
* 'H' - hangup; sent after detected incoming call finished
* 'B' - button; sent when "door open" has been performed by green hw button press
* 'J' - reJected; sent when incoming call has been rejected by red hw button press
* 'S' - success; sent in response to 'O' or 'N' command
* 'F' - fail; sent in response to 'O' or 'N' command (this means that 'O' or 'N' command has been received but no incoming call detected)

## Home Assistant configuration
```
binary_sensor:
  - platform: mqtt
    name: "Domofon"
    state_topic: "domofon/out"
    availability_topic: "domofon/status"
    payload_on: "C"
    payload_off: "H"
    payload_available: "R"
    payload_not_available: "L"
    device_class: lock
```
