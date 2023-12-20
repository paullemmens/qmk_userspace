#include "persistent.h"

void keyboard_post_init_user(void) {
  // Call the keymap level matrix init.

  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.macos_enabled = false; // We want this disabled by default
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now
}
