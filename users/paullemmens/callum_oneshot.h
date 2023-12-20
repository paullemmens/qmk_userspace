#ifndef CALLUM_ONESHOT_H_
#define CALLUM_ONESHOT_H_

#include "oneshot.h"

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case OS_LCMD:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case OS_LCMD:
        case KC_LSFT:
        case KC_RSFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS__ALT:
        case OS__CMD:
        case R_ADJST:
        case F_RAISE:
        case G_LOWER:
        case U_ADJST:
        case J_RAISE:
        case H_LOWER:
        case OSL(_ADJUST):
        case OSL(_RAISE):
        case OSL(_LOWER):
            return true;
        default:
            return false;
    }
}

#endif // CALLUM_ONESHOT_H_


#ifdef CALLUM_ONESHOT
oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
#endif
