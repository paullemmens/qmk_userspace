#ifndef PERSISTENT_H_
#define PERSISTENT_H_

#include QMK_KEYBOARD_H

typedef union {
  uint32_t raw;
  struct {
    bool     macos_enabled :1;
  };
} user_config_t;

user_config_t user_config;

#endif // PERSISTENT_H_
