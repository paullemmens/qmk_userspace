OLED_ENABLE = yes         # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
WPM_ENABLE = yes
VELOCIKEY_ENABLE = yes
KEY_LOCK_ENABLE = no
CAPS_WORD_ENABLE = yes

# https://docs.splitkb.com/product-guides/liatris/onboard-rgb
RGBLIGHT_ENABLE = yes
WS2812_DRIVER = vendor # Use the RP2040's PIO interface

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp

CONVERT_TO=liatris
