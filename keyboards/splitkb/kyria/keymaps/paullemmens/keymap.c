/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H
#include "paullemmens.h"

#include "persistent.h"

#ifdef WPM_ENABLE
    char wpm_str[10];

    #ifdef WPM_GRAPH
        uint16_t wpm_graph_timer = 0;
        #include "wpm_graph.h"
    #endif

    #ifdef BONGO2
        #include "bongo2.h"
    #endif
    #ifdef BONGOCAT
        #include "bongocat.h"
    #endif
#endif

#ifdef VELOCIKEY_ENABLE
#include "rgblight.h"
#endif

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#endif

// Tap dance stuff
#ifdef TAP_DANCE_ENABLE
enum {
    TD_5_6,
    TD_6_7,
    TD_PERC_CIRC,
    TD_AMPR_CIRC
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_5_6] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_6),
    [TD_6_7] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_7),
    [TD_PERC_CIRC] = ACTION_TAP_DANCE_DOUBLE(KC_PERC, KC_CIRC),
    [TD_AMPR_CIRC] = ACTION_TAP_DANCE_DOUBLE(KC_AMPR, KC_CIRC)
};
#endif

/*
 * The `LAYOUT_kyria_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes.
 *
 * I copied this code from @drashna's "example" code in the qmk repository.
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)

/* Watch out: line continuation all over, so kyria_base is defined as
   LAYOUT_wrapper! */
#define LAYOUT_kyria_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
      KC_TAB,  K01, K02, K03,     K04,     K05,                                                 K06,     K07,     K08,     K09, K0A, KC_BSPC, \
      KC_ESC,  K11, K12, K13,     K14,     K15,                                                 K16,     K17,     K18,     K19, K1A, KC_QUOT, \
      KC_LSFT, K21, K22, K23,     K24,     K25,     CL_QWER,  _______,       DEL_RAI,  BS_LALT, K26,     K27,     K28,     K29, K2A, KC_RSFT, \
                         KC_LGUI, KC_LOPT, SPC_LWR, KC_LCMD,  TO(_RAISE),    KC_RCMD,  ENT_RSF, KC_SPC,  KC_ROPT, KC_APP \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_kyria_base_wrapper(...)       LAYOUT_kyria_base(__VA_ARGS__)

/* Set up the actual keymaps using the user land configuration. */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Modded qwerty layer as base layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |  E   |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  BS    |
 * |        |      |      |      |adjust|      |                              |      |adjust|      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  ESC   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |        |      |      | LShft| raise|lower |                              | lower| raise|RShift|      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |  C   |   V  |   B  | Clean|      |  | Del  | LAlt |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * |        | LGui |      |      | LCmd | LCtrl|Qwerty|      |  | Raise| BS   | RCtrl| RCmd |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LGUI | LOpt | Space| LCmd | To   |  | RCmd | Enter| Space| ROpt | Menu |
 *                        |      |      | lower|      | Raise|  |      |RSHift|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MOD_QWERTY] = LAYOUT_kyria_base_wrapper(
        _____________MOD_QWERTY_L1_________________, _____________MOD_QWERTY_R1_________________,
        _____________MOD_QWERTY_L2_________________, _____________MOD_QWERTY_R2_________________,
        _____________MOD_QWERTY_L3_________________, _____________MOD_QWERTY_R3_________________
    ),
/*
 * Clean (no home row modifiers or mod tap layer keys) qwerty
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |  E   |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |        |
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |  C   |   V  |   B  | Mod  |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? |        |
 * |        |      |      |      |      |      |Qwerty|      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT_wrapper(
      _______, _________________QWERTY_L1_________________,                                     _________________QWERTY_R1_________________, _______,
      _______, _________________QWERTY_L2_________________,                                     _________________QWERTY_R2_________________, _______,
      _______, _________________QWERTY_L3_________________, MODQWER, _______, _______, _______, _________________QWERTY_R3_________________, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Layer: Colemak Mod DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  Q   |  W   |  F   |  P   |  B   |                              |  J   |  L   |  U   |  Y   | ; :  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  A   |  R   |  S   |  T   |  G   |                              |  M   |  N   |  E   |  I   |  O   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  Z   |  X   |  C   |  D   |  V   |      |      |  |      |      |  K   |  H   |  ,   |  .   |  /   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK] = LAYOUT_wrapper(
      _______, ______________COLEMAK_MOD_DH_L1____________,                                     ______________COLEMAK_MOD_DH_R1____________, _______,
      _______, ______________COLEMAK_MOD_DH_L2____________,                                     ______________COLEMAK_MOD_DH_R2____________, _______,
      _______, ______________COLEMAK_MOD_DH_L3____________, DEFAU_L, _______, _______, _______, ______________COLEMAK_MOD_DH_R3____________, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Lower Layer: F-keys, Numpad
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                              |  F6  |  F7  |  F8  |  F9  | - _  |  = +   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F11 |  F12 |   é  |   ë  |   ô  |                              | Left | Down |  Up  | Right|  |   |  \ |   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F10 |  ò   |   ó  |   ö  |   €  |      |      |  |      |      | Home | PgDn | PgUp |  End |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT_wrapper(
      _______, _________________LOWER_L1__________________,                                     _________________LOWER_R1__________________, KC_EQL,
      _______, _________________LOWER_L2__________________,                                     _________________LOWER_R2__________________, KC_BSLS,
      _______, _________________LOWER_L3__________________, _______, _______, _______, _______, _________________LOWER_R3__________________, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Raise Layer: numbers, arrows, and some symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |  [   |  ]   |      |                              |      |  7   |  8   |  9   | - _  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |      |  4   |  5   |  6   |  +   |   *    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  {   |  }   |  ~   |      |      |  |      |      |      |  1   |  2   |  3   |      |   /    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | TO(0)|      |      |      |  |      |      |  0   |  .   |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT_wrapper(
      _______, _________________RAISE_L1__________________,                                     _________________RAISE_R1__________________, _______,
      _______, _________________RAISE_L2__________________,                                     _________________RAISE_R2__________________, KC_PAST,
      _______, _________________RAISE_L3__________________, _______, _______, _______, _______, _________________RAISE_R3__________________, KC_COLN,
                                 _______, TO(0),   _______, _______, TO(0),   _______, _______, KC_0,    KC_PDOT, _______
    ),
/*
 * Adjust Layer: Symbols, volume, locks, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   VLK  | BrDn | BrUp |      |      |      |                              |      |  &   |  *   |  (   |  _   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  CAPS  | SAI  | HUI  | VAI  | Eff+ | MOD  |                              |      |  $   |  %   |  ^   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  RTOG  |RGB SN| RGB K| RGB X| RGB G| RGB T| RGB P| RGB B|  | RGB R|RGB SW|      |  !   |  @   |  #   |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute |      |      | NumLk|Scrllk|  |Insert| OSX  |QWERTY|COLEMA|      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT_wrapper(
      VK_TOGG, _________________ADJUST_L1_________________,                                      _________________ADJUST_R1_________________, _______,
      CW_TOGG, _________________ADJUST_L2_________________,                                      _________________ADJUST_R2_________________, _______,
      UG_TOGG, _________________ADJUST_L3_________________, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, _________________ADJUST_R3_________________, _______,
                                 KC_MUTE, _______, _______, KC_NUM,  KC_SCRL, KC_INS,  MACOS_L,  DEFAU_L, COLEMAK, _______
    )
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();

    #if defined(KEYBOARD_splitkb_kyria_rev1)
        oled_write_P(PSTR("Kyria rev1.2"), false);
    #else
        oled_write_P(PSTR("Kyria rev2.1"), false);
    #endif

    if (user_config.macos_enabled) {
        oled_write_P(PSTR(" OSX"), false);
    }
    else {
        oled_write_P(PSTR("    "), false);
    }

    #ifdef VELOCIKEY_ENABLE
    if (velocikey_enabled()) {
        oled_write_P(PSTR(" VLK"), false);
    }
    #endif

    oled_write_P(PSTR("\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _MOD_QWERTY:
            oled_write_P(PSTR("Mod Qw\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("\n"), false);
    oled_write_P(led_state.num_lock                       ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock || is_caps_word_on() ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock                    ? PSTR("SCR ") : PSTR("    "), false);

    #ifdef WPM_ENABLE
        /* Use code sample from https://docs.qmk.fm/#/squeezing_avr to prevent loading stdlib.h */
        oled_write_P(PSTR("WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
    #endif
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        #ifdef WPM_GRAPH
            render_wpm_graph();
        #elif defined(BONGOCAT)
            render_anim();
        #elif defined(BONGO2)
            draw_bongo(false);
        #else
            render_kyria_logo();
        #endif
    }
    return false;
}
#endif // OLED_ENABLE

#ifdef ENCODER_ENABLE
// Use code from plattfot as example to make layer specifc encoder actions
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            // Move and move to windows in i3-wm or using Rectangle in macOS.
            case _RAISE:
                if (clockwise) {
                    if (user_config.macos_enabled) {
                        tap_code16(LCTL(LOPT(LCMD(KC_RIGHT))));
                    }
                    else {
                        tap_code16(LGUI(KC_RIGHT));
                    }
                } else {
                    if (user_config.macos_enabled) {
                        tap_code16(LCTL(LOPT(LCMD(KC_LEFT))));
                    }
                    else {
                        tap_code16(LGUI(KC_LEFT));
                    }
                }
                break;
            // Volume control on adjust
            case _ADJUST:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _LOWER:
                if (clockwise) {
                    tap_code16(RCMD(KC_TILD));
                } else {
                    tap_code16(RSFT(RCMD(KC_TILD)));
                }
                break;
            // Alt-tab code from https://docs.splitkb.com/hc/en-us/articles/360010513760-How-can-I-use-a-rotary-encoder-
            default:
                if (clockwise) {
                    if (!is_alt_tab_active) {
                        is_alt_tab_active = true;
                        if (user_config.macos_enabled) {
                            register_code(KC_LCMD);
                        }
                        else {
                            register_code(KC_LALT);
                        }
                    }
                    alt_tab_timer = timer_read();
                    tap_code16(KC_TAB);
                } else {
                    // TODO: a bit weird: first do clockwise turn so you can counter clockwise to another app, otherwise
                    // S-tab is sent in the current application. Is also convenient to some degree so ...
                    alt_tab_timer = timer_read();
                    tap_code16(S(KC_TAB));
                }
                break;
        }
    }
    else if (index == 1) { // Right-hand encoder
        switch (get_highest_layer(layer_state)) {
            case _LOWER:
                // Ctrl+left/right to move between words
                if (user_config.macos_enabled) {
                    if (clockwise) {
                        tap_code16(LOPT(KC_RIGHT));
                    } else {
                        tap_code16(LOPT(KC_LEFT));
                    }
                } else {
                    if (clockwise) {
                        tap_code16(C(KC_RIGHT));
                    } else {
                        tap_code16(C(KC_LEFT));
                    }
                }
                break;
            default:
                // Page up/Page down
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
        }
    }

    // Return true to also run the keyboard level code. In my case I think this
    // then runs the volume thing on macOS.
    return false;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 750) {
      if (user_config.macos_enabled) {
          unregister_code(KC_LCMD);
      }
      else {
          unregister_code(KC_LALT);
      }
      is_alt_tab_active = false;
    }
  }
}
#endif

void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
        // Set our LED pin as output
        setPinOutput(24);
        // Turn the LED off
        // (Due to technical reasons, high is off and low is on)
        writePinLow(24);
    } else {
        // Do something when Caps Word deactivates.
        setPinOutput(24);
        writePinHigh(24);
    }
}
