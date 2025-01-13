/* Copyright 2021 Paul Lemmens (paul.lemmens@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "paullemmens.h"
#include "persistent.h"

#ifdef CALLUM_ONESHOT
  #include "callum_oneshot.h"
#endif

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#if defined(TAPPING_TERM_PER_KEY)
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case K_RSHFT:
            return TAPPING_TERM + 75;
        case H_LOWER:
        case U_ADJST:
            return TAPPING_TERM - 25;
        case F_RAISE:
        case J_RAISE:
            return TAPPING_TERM - 50;
        case V__LCMD:
        case N_RCTRL:
        case M_RCTRL:
        case M__RCMD:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}
#endif

#if defined(PERMISSIVE_HOLD_PER_KEY)
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case U_ADJST:
        case R_ADJST:
        case F_RAISE:
        case J_RAISE:
            return true;
        default:
            return false;
    }
}
#endif

#if defined(HOLD_ON_OTHER_KEY_PRESS)
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        // Capture all mod-tap keycodes.
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            if (keycode == U_ADJST) {
                // Disable HOLD_ON_OTHER_KEY_PRESS for U_ADJST
                // aka enable IGNORE_MOD_TAP_INTERRUPT for U_ADJST.
                return false;
            } else if (keycode == R_ADJST) {
                return false;
            } else if (keycode == H_LOWER) {
                return false;
            } else {
                // Enable HOLD_ON_OTHER_KEY_PRESS for every other mod-tap keycode.
                return true;
            }
        default:
            return false;
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef CALLUM_ONESHOT
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS__ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS__CMD, keycode, record);
#endif

    switch (keycode) {
        case MACOS_L:  // This allows me to toggle macOS relevant adjusting of modifiers
            if (record->event.pressed) {
                user_config.macos_enabled ^= 1; // Toggles the status
                eeconfig_update_user(user_config.raw); // Writes the new status to EEPROM
            }
            break;
        case OU_LCTL:
            if (record->tap.count && record->event.pressed) {
                // send advanced keycode, etc.
                // the 16 bit version of the `tap_code` function is used here
                // because KC_HASH is a non-basic keycode.
                if (user_config.macos_enabled) {
                    tap_code16(ROPT(KC_U));
                    return false;
                } else {
                    tap_code16(ALGR(S(KC_QUOTE)));
                    return false;
                }
            }
            // do not continue with default tap action
            // if the MT was pressed or released, but not held
            break;
        case EA_LSFT:
            if (record->tap.count && record->event.pressed) {
                // send advanced keycode, etc.
                if (user_config.macos_enabled) {
                    tap_code16(ROPT(KC_E));
                    tap_code16(KC_E);
                    return false;
                } else {
                    // the 16 bit version of the `tap_code` function is used here
                    // because KC_HASH is a non-basic keycode.
                    tap_code16(ALGR(KC_E));
                    return false;
                }
            }
            break;
        case E_UMLAU:
            if (record->tap.count && record->event.pressed) {
                // send advanced keycode, etc.
                if (user_config.macos_enabled) {
                    tap_code16(ROPT(KC_U));
                    tap_code16(KC_E);
                    return false;
                } else {
                    // the 16 bit version of the `tap_code` function is used here
                    // because KC_HASH is a non-basic keycode.
                    tap_code16(ALGR(KC_E));
                    return false;
                }
            }
            break;
        case EURO:
            if (record->tap.count && record->event.pressed) {
                if (user_config.macos_enabled) {
                    /* SEND_STRING(SS_LEFT(SS_LOPT("2"))); */
                    tap_code16(ROPT(S(KC_2)));
                    return false;
                } else {
                    tap_code16(ALGR(KC_5));
                    return false;
                }
            }
            break;
        case _ACUTE_:
            if (record->tap.count && record->event.pressed) {
                if (user_config.macos_enabled) {
                    tap_code16(ROPT(KC_E));
                    return false;
                } else {
                    // the 16 bit version of the `tap_code` function is used here
                    // because KC_HASH is a non-basic keycode.
                    tap_code16(ALGR(KC_QUOTE));
                    return false;
                }
            }
            break;
        case _CIRCFL:
            if (record->tap.count && record->event.pressed) {
                // send advanced keycode, etc.
                if (user_config.macos_enabled) {
                    tap_code16(ROPT(KC_U));
                    tap_code16(KC_I);
                    return false;
                } else {
                    // the 16 bit version of the `tap_code` function is used here
                    // because KC_HASH is a non-basic keycode.
                    tap_code16(ALGR(KC_CIRC));
                    return false;
                }
            }
            break;
        case RB_LCTL:
            if (record->tap.count && record->event.pressed) {
                // send advanced keycode, etc.
                // the 16 bit version of the `tap_code` function is used here
                // because KC_HASH is a non-basic keycode.
                tap_code16(KC_RCBR);
                return false;
            }
            break;
        case KC_HOME:
            if (user_config.macos_enabled) {
                if (record->event.pressed) {
                    tap_code16(LCMD(KC_LEFT));
                }
                return false;
            }
            break;
        case KC_END:
            if (user_config.macos_enabled) {
                if (record->event.pressed) {
                    tap_code16(LCMD(KC_RIGHT));
                }
                return false;
            }
            break;
        default:
            return true;
    }

#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    return true;
};

// https://docs.splitkb.com/hc/en-us/articles/5799711553820-Power-LED
#if defined(KEYBOARD_splitkb_kyria_rev2) || defined(KEYBOARD_splitkb_kyria_rev1)
    void keyboard_pre_init_user(void) {
    // Set our LED pin as output
    gpio_set_pin_output(24);
    // Turn the LED off
    // (Due to technical reasons, high is off and low is on)
    gpio_write_pin_high(24);
    };
#endif
