# Adjustments specific for the Redox.
OLED_DRIVER_ENABLE = no   # Enables the use of OLED displays
ENCODER_ENABLE = no       # Enables the use of one or more encoders
WPM_ENABLE = no
VELOCIKEY_ENABLE = no
KEY_LOCK_ENABLE = yes

RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
CAPS_WORD_ENABLE = yes

# Use Link Time Optimization to squeeze last bit of space because I cannot
# replace the Redox controller so need to minimize space as much as possible.
LTO_ENABLE = yes

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = caterina
