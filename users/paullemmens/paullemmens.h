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

#pragma once

#include "quantum.h"

// Personal key definitions:
// Very special combinations
#define SGUI_LWR    LM(_LOWER, MOD_LSFT|MOD_LGUI)
#define OSX_DSP     LM(_LOWER, MOD_LCTL|MOD_LALT|MOD_LGUI)
#define GUI_LWR     LM(_LOWER, MOD_LGUI)

// Following trick from https://discord.com/channels/440868230475677696/869812721552601088/1090742812670185605
// that refers to https://docs.qmk.fm/#/mod_tap?id=changing-hold-function.
#define E_UMLAU     LT(0, ALGR(KC_W))
#define EURO        LT(0, ALGR(KC_5))
#define _ACUTE_     LT(0, ALGR(KC_QUOTE))
#define _GRAVE_     LT(0, ALGR(KC_GRAVE))
#define _UMLAU_     LT(0, ALGR(S(KC_QUOTE)))
#define _CIRCFL     LT(0, ALGR(KC_CIRC))
// Home row mods
#define LGUI__Z     LGUI_T(KC_Z)
#define V_LCTRL     LCTL_T(KC_V)
#define B_LCTRL     LCTL_T(KC_B)
#define V__LCMD     LCMD_T(KC_V)
#define N_RCTRL     RCTL_T(KC_N)
#define M_RCTRL     RCTL_T(KC_M)
#define M__RCMD     RCMD_T(KC_M)
#define D_LSHFT     LSFT_T(KC_D)
#define K_RSHFT     RSFT_T(KC_K)
#define BS_LALT     LALT_T(KC_BSPC)
#define ENT_RSF     RSFT_T(KC_ENT)
// Layer toggles
#define R_ADJST     LT(_ADJUST, KC_R)
#define F_RAISE     LT(_RAISE, KC_F)
#define SPC_LWR     LT(_LOWER, KC_SPC)

// FIXME: figure out smart way for adjusting to macos vs windows so I don't need the extra layer no more
/* #define OS_LCMD     KC_LCMD */
#define OS_LCMD     OSM(MOD_LGUI)

#define DEL_RAI     LT(_RAISE, KC_DEL)
#define ESC_RAI     LT(_RAISE, KC_ESC)
#define H_LOWER     LT(_LOWER, KC_H)
#define G_LOWER     LT(_LOWER, KC_G)
#define J_RAISE     LT(_RAISE, KC_J)
#define U_ADJST     LT(_ADJUST, KC_U)
#define DEFAU_L     DF(_MOD_QWERTY)
#define CL_QWER     DF(_QWERTY)
#define MODQWER     DF(_MOD_QWERTY)
#define COLEMAK     DF(_COLEMAK)

// https://precondition.github.io/home-row-mods#using-non-basic-keycodes-in-mod-taps
enum custom_keycodes {
    MT_OUMLA = SAFE_RANGE,
    MT_EACUT,
    MT_RCBR,
    MACOS_L
};
#define OU_LCTL LCTL_T(MT_OUMLA)
#define EA_LSFT LSFT_T(MT_EACUT)
#define RB_LCTL LCTL_T(MT_RCBR)

/* My layers are: */
enum userspace_layers {
    _MOD_QWERTY = 0,
    _QWERTY,
    _COLEMAK,

    _LOWER,
    _RAISE,
    _ADJUST
};

/* Blocks for each of the four major keyboard layouts Organized so we can
   quickly adapt and modify all of them at once, rather than for each keyboard,
   one at a time. And this allows for much cleaner blocks in the keymaps. For
   instance Tap/Hold for Control on all of the layouts NOTE: These are all the
   same length. If you do a search/replace then you need to add/remove
   underscores to keep the lengths consistent. */

// clang-format off
#define _________________QWERTY_L1_________________       _______, _______, _______, KC_R,    _______
#define _________________QWERTY_L2_________________       _______, _______, KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    _______, _______, KC_V,    KC_B

#define _________________QWERTY_R1_________________       _______, KC_U,    _______, _______, _______
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    _______, _______
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    _______, _______, _______

#define _____________MOD_QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    R_ADJST, KC_T
#define _____________MOD_QWERTY_L2_________________       KC_A,    KC_S,    D_LSHFT, F_RAISE, G_LOWER
#define _____________MOD_QWERTY_L3_________________       LGUI__Z, KC_X,    KC_C,    V__LCMD, B_LCTRL 

#define _____________MOD_QWERTY_R1_________________       KC_Y,    U_ADJST, KC_I,    KC_O,    KC_P
#define _____________MOD_QWERTY_R2_________________       H_LOWER, J_RAISE, K_RSHFT, KC_L,    KC_SCLN, KC_QUOT
#define _____________MOD_QWERTY_R3_________________       N_RCTRL, M__RCMD, KC_COMM, KC_DOT,  KC_SLSH

#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________LOWER_L1__________________       _________________FUNC_LEFT_________________
#define _________________LOWER_L2__________________       KC_F11,  KC_F12,  EA_LSFT, E_UMLAU, _CIRCFL
#define _________________LOWER_L3__________________       KC_F10,  _GRAVE_, _ACUTE_, OU_LCTL, EURO

#define _________________LOWER_R1__________________       _________________FUNC_RIGHT________________
#define _________________LOWER_R2__________________       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE
#define _________________LOWER_R3__________________       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______

#define _________________RAISE_L1__________________       _______, _______, KC_LBRC, KC_RBRC, _______
#define _________________RAISE_L2__________________       KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV
#define _________________RAISE_L3__________________       KC_PERC, KC_CIRC, KC_LCBR, RB_LCTL, KC_TILD

#define _________________RAISE_R1__________________       ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________       _______, KC_4,    KC_5,    KC_6,    KC_PPLS
#define _________________RAISE_R3__________________       _______, KC_1,    KC_2,    KC_3,    KC_PSLS

#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       _______, KC_7,    KC_8,    KC_9,    KC_MINS
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_MINS

#define ___________________BLANK___________________       _______, _______, _______, _______, _______

#define _________________ADJUST_L1_________________       KC_BRID,  KC_BRIU, _______, _______, _______
#define _________________ADJUST_L2_________________       UG_SATU,  UG_HUEU, UG_VALU, UG_SPDU, UG_NEXT
#define _________________ADJUST_L3_________________       RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T

#define _________________ADJUST_R1_________________       _______,  KC_AMPR, KC_ASTR, KC_LPRN, KC_UNDS
#define _________________ADJUST_R2_________________       _______,  KC_DLR,  KC_PERC, KC_CIRC, _______
#define _________________ADJUST_R3_________________       _______,  KC_EXLM, KC_AT,   KC_HASH, _______
