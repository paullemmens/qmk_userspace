# Settings to save space via https://docs.qmk.fm/#/squeezing_avr.
LTO_ENABLE = yes
#
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
#
OS_DETECTION_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
# https://discord.com/channels/440868230475677696/473506116718952450/838845851962703893
SWAP_HANDS_ENABLE = no

ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = no
RGB_MATRIX_ENABLE = yes
RGBLIGHT_ENABLE = no
#
LEADER_ENABLE = no        # Enable the Leader Key feature
TAP_DANCE_ENABLE = no
UNICODE_ENABLE = no
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes
VELOCIKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
WPM_ENABLE = yes

# This adds module functionality to your keyboard (files found in users/halcyon_modules)
USER_NAME := halcyon_modules

# Include shared code
VPATH += $(QMK_USERSPACE)/users/paullemmens
SRC += paullemmens.c
SRC += persistent.c
