# Settings to save space via https://docs.qmk.fm/#/squeezing_avr.
LTO_ENABLE = yes
#
CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
#
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
# https://discord.com/channels/440868230475677696/473506116718952450/838845851962703893
SWAP_HANDS_ENABLE = no
#
# TODO: may bug things on the display.
AVR_USE_MINIMAL_PRINTF = yes

# Stuff shared over keyboards
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
LEADER_ENABLE = no        # Enable the Leader Key feature
TAP_DANCE_ENABLE = no
UNICODE_ENABLE = no

SRC += paullemmens.c
SRC += oneshot.c
SRC += persistent.c
