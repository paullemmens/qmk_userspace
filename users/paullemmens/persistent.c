#include "persistent.h"
#include "os_detection.h"

user_config_t user_config;

void keyboard_post_init_user(void) {
  // Call the keymap level matrix init.

  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;

  os_variant_t os_type = detected_host_os();
  if (os_type) {
    switch(os_type) {
      case OS_MACOS:
      case OS_IOS:
        user_config.macos_enabled = true; // We want this enabled by default
        break;
      default:
        user_config.macos_enabled = false;
        break;
    }
  }

  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now
}
