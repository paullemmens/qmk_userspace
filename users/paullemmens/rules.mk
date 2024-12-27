# Settings to save space via https://docs.qmk.fm/#/squeezing_avr.
LTO_ENABLE = yes
#
CONSOLE_ENABLE = no
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
LEADER_ENABLE = no        # Enable the Leader Key feature
TAP_DANCE_ENABLE = no
UNICODE_ENABLE = no
CAPS_WORD_ENABLE = yes

SRC += paullemmens.c
SRC += persistent.c
