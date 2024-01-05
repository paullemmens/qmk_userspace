OLED_ENABLE = yes         # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
WPM_ENABLE = yes
VELOCIKEY_ENABLE = yes
KEY_LOCK_ENABLE = no
CAPS_WORD_ENABLE = yes

OS_DETECTION_ENABLE = yes
SPLIT_DETECTED_OS_ENABLE = yes

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = rp2040
