#ifndef TYPES_H_
#define TYPES_H_

#define LED_ON    HIGH
#define LED_OFF   LOW
#define RELAY_ON  LOW
#define RELAY_OFF HIGH

typedef enum {
  IDLE,
  CALL
} EState;

typedef enum {
  NO_ACTION,
  OPEN,
  OPEN_BY_BUTTON,
  REJECT,
  REJECT_BY_BUTTON
} EAction;

#endif // TYPES_H_
