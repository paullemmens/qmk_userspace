// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "paullemmens.h"
#include "persistent.h"

#ifdef VELOCIKEY_ENABLE
#include "rgblight.h"
#endif

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#endif


// There is an extra row added for the Halcyon modules. Currently only the Encoder module is
// supported but we reserve 5 keys per half for future expansion. Your personal keymap will also
// need to be updated to include this row, and the `LAYOUT` macro will need to be updated to
// `LAYOUT_split_3x6_5_hlc` in order to compile.

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT_split_3x6_5_hlc(__VA_ARGS__)

// Watch out: line continuation all over, so kyria_base is defined as LAYOUT_wrapper!
// Re-pass though to allow templates to be used.
#define LAYOUT_kyria_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
      KC_TAB,  K01, K02, K03,     K04,     K05,                                                 K06,     K07,     K08,     K09, K0A, KC_BSPC, \
      KC_ESC,  K11, K12, K13,     K14,     K15,                                                 K16,     K17,     K18,     K19, K1A, KC_QUOT, \
      KC_LSFT, K21, K22, K23,     K24,     K25,     CL_QWER,  _______,       DEL_RAI,  BS_LALT, K26,     K27,     K28,     K29, K2A, KC_RSFT, \
                         KC_LGUI, KC_LOPT, SPC_LWR, KC_LCMD,  TO(_RAISE),    KC_RCMD,  ENT_RSF, KC_SPC,  KC_ROPT, KC_APP, \
      KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,                                                               KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO \
    )

#define LAYOUT_kyria_base_wrapper(...)       LAYOUT_kyria_base(__VA_ARGS__)

// clang-format off
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
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,                                                               KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO 
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
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,                                                               KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO 
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
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,                                                               KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO 

    ),

/*
 * Raise Layer: numbers, arrows, and some symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      | = +  |  [   |  ]   |      |                              |      |  7   |  8   |  9   | - _  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | ' "  | \ |  |  (   |  )   |  `   |                              |      |  4   |  5   |  6   |  +   |   *    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |  {   |  }   |  ~   |      |      |  |      |      |      |  1   |  2   |  3   |  :   |   :    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | TO(0)|      |      |      |  |      |      |  0   |  .   |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT_wrapper(
      _______, _________________RAISE_L1__________________,                                     _________________RAISE_R1__________________, _______,
      _______, _________________RAISE_L2__________________,                                     _________________RAISE_R2__________________, KC_PAST,
      _______, _________________RAISE_L3__________________, _______, _______, _______, _______, _________________RAISE_R3__________________, KC_COLN,
                                 _______, TO(0),   _______, _______, TO(0),   _______, _______, KC_0,    KC_PDOT, _______,
      KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,                                                               KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO 

    ),

    // FIXME: fix memory for the macos setting.
/*
 * Adjust Layer: Symbols, volume, locks, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   VLK  | BrDn | BrUp |      |      |      |                              |      |  &   |  *   |  (   |  _   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  CAPSW | SAI  | HUI  | VAI  | SPDU | EFFU |                              |      |  $   |  %   |  ^   | ' "  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | RMTOG  | SAD  | HUD  | VAD  | SPDD | EFFD |      |      |  |      |      |      |  !   |  @   |  #   |  :   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute |      |      | NumLk|Scrllk|  |Insert| OSX  |QWERTY|COLEMA|      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#ifdef RGB_MATRIX_ENABLE
    [_ADJUST] = LAYOUT_wrapper(
      VK_TOGG, _________________ADJUST_L1_________________,                                     _________________ADJUST_R1_________________, _______,
      CW_TOGG, _________________ADJUST_L2_________________,                                     _________________ADJUST_R2_________________, _______,
      RM_TOGG, _________________ADJUST_L3_________________, _______, _______, _______, _______, _________________ADJUST_R3_________________, _______,
                                 KC_MUTE, _______, _______, KC_NUM,  KC_SCRL, KC_INS,  MACOS_L, DEFAU_L, COLEMAK, _______,
      KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,                                                               KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO 
    )
#endif // RGB_MATRIX_ENABLE
#ifdef RGBLIGHT_ENABLE
    [_ADJUST] = LAYOUT_wrapper(
      VK_TOGG, _________________ADJUST_L1_________________,                                     _________________ADJUST_R1_________________, _______,
      CW_TOGG, _________________ADJUST_L2_________________,                                     _________________ADJUST_R2_________________, _______,
      UG_TOGG, _________________ADJUST_L3_________________, _______, _______, _______, _______, _________________ADJUST_R3_________________, _______,
                                 KC_MUTE, _______, _______, KC_NUM,  KC_SCRL, KC_INS,  MACOS_L, DEFAU_L, COLEMAK, _______,
      KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,                                                               KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO 
    )
#endif // RGBLIGHT_ENABLE

// /*
//  * Halcyon Layer template
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
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * |      |      |       |      |      |                                              |      |      |       |      |      |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_split_3x6_5_hlc(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//
//       _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
//     ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [1] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [2] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [3] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [4] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [5] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [6] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
};
#endif

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
