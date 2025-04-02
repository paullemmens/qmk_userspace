#ifndef PERSISTENT_H_
#define PERSISTENT_H_

#include QMK_KEYBOARD_H

typedef union {
  uint32_t raw;
  struct {
    bool     macos_enabled :1;
    uint8_t  tap_flow_term : 8;
  };
} user_config_t;

user_config_t user_config;

#endif // PERSISTENT_H_
