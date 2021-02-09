#ifndef MQTT_H_
#define MQTT_H_

// High level protocol messages
#define MSG_STATUS_READY            "R" // ready; sent after successfull boot-up or after receiving of 'P' message
#define MSG_STATUS_LAST_WILL        "L" // last will message; send when device goes offline

#define MSG_OUT_CALL                "C" // call; sent after detecting of incoming intercom call
#define MSG_OUT_HANGUP              "H" // hangup; sent after detected incoming call finished
#define MSG_OUT_OPENED_BY_BUTTON    "B" // button; sent when "door open" has been performed by green hw button press
#define MSG_OUT_REJECTED_BY_BUTTON  "J" // reJected; sent when incoming call has been rejected by red hw button press
#define MSG_OUT_SUCCESS             "S" // success; sent in response to 'O' or 'N' command
#define MSG_OUT_FAIL                "F" // fail; sent in response to 'O' or 'N' command (this means that 'O' or 'N' command has been received but no incoming call detected)

#define MSG_IN_OPEN                 'O' // door open command
#define MSG_IN_REJECT               'N' // call reject command (door will not open)
#define MSG_IN_PING                 'P' // ping command (answers with 'R')

#endif // MQTT_H_
