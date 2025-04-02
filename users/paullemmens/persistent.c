#include "persistent.h"
#include "modules/getreuer/tap_flow/tap_flow.h"

void keyboard_post_init_user(void) {
  // Call the keymap level matrix init.

  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();

  // Only set tap flow term because the other config is used in code to branch
  // OS specific logic.
  g_tap_flow_term = user_config.tap_flow_term;
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.macos_enabled = true; // We want this disabled by default
  user_config.tap_flow_term = TAP_FLOW_TERM;

  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now
}
