#include QMK_KEYBOARD_H
#include "paullemmens.h"

#ifdef VELOCIKEY_ENABLE
#include "velocikey.h"
#endif

// Tap dance stuff
#ifdef TAP_DANCE_ENABLE
enum {
    TD_5_6,
    TD_6_7,
    TD_PERC_CIRC,
    TD_AMPR_CIRC
};

qmk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_5_6] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_6),
    [TD_6_7] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_7),
    [TD_PERC_CIRC] = ACTION_TAP_DANCE_DOUBLE(KC_PERC, KC_CIRC),
    [TD_AMPR_CIRC] = ACTION_TAP_DANCE_DOUBLE(KC_AMPR, KC_CIRC)
};
#endif

// These shortcuts are Redox specific to make keymap more readable.
#define RAISE_L MO(_RAISE)
#define T_RAI_L TT(_RAISE)
#define KC_RALB LT(_RAISE, KC_LBRC)
#define KC_RARB LT(_RAISE, KC_RBRC)

#define KC_ADJ6 LT(_ADJUST, KC_6)
#define KC_ADSL LT(_ADJUST, KC_BSLS)

/*
 * The `LAYOUT_redox_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes.
 *
 * I copied this code from @drashna's "example" code in the qmk repository.
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)

/* Watch out: line continuation all over, so redox_base is defined as
   LAYOUT_wrapper! */
#define LAYOUT_redox_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A \
  ) \
  LAYOUT_wrapper( \
      KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,  KC_5,                                             KC_6, KC_7, KC_8,    KC_9,   KC_0,     KC_BSPC, \
      KC_TAB,   K01,     K02,     K03,     K04,   K05,  KC_ADJ6,                           KC_ADSL, K06,  K07,  K08,     K09,    K0A,      KC_BSPC, \
      KC_ESC,   K11,     K12,     K13,     K14,   K15,  KC_RALB,                           KC_RARB, K16,  K17,  K18,     K19,    K1A,      KC_QUOT, \
      KC_LSFT,  K21,     K22,     K23,     K24,   K25,  T_RAI_L,  SGUI_LWR,      DEL_RAI,  BS_LALT, K26,  K27,  K28,     K29,    K2A,      KC_RSFT, \
      KC_LCTL,  RAISE_L, KC_LGUI, KC_LOPT,   SPC_LWR,   KC_LCMD,  OSX_DSP,       KC_RCMD,  ENT_RSF,   KC_SPC,   KC_ROPT, KC_APP, KC_RCTL,  RAISE_L \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_redox_base_wrapper(...)       LAYOUT_redox_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MOD_QWERTY] = LAYOUT_redox_base_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  // KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,R_ADJST ,KC_T    ,KC_ADJ6 ,                          KC_ADSL ,KC_Y    ,U_ADJST ,KC_I    ,KC_O    ,KC_P    ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // KC_ESC  ,KC_A    ,KC_S    ,D_LSHFT ,F_RAISE ,KC_G    ,KC_RALB ,                          KC_RARB ,H_LOWER ,J_RAISE ,K_RSHFT ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // KC_LSFT ,LGUI__Z ,KC_X    ,KC_C    ,V_LCTRL ,B_LCTRL ,T_RAI_L ,SGUI_LWR,        DEL_RAI ,BS_LALT ,KC_N    ,M_RCTRL ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
  // KC_LCTRL,RAISE_L ,KC_LGUI ,KC_LOPT ,     SPC_LWR ,    KC_LCMD, OSX_DSP ,        KC_RCMD, ENT_RSF ,    KC_SPC  ,     KC_ROPT ,KC_APP  ,KC_RCTRL,RAISE_L
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        _____________MOD_QWERTY_L1_________________, _____________MOD_QWERTY_R1_________________,
        _____________MOD_QWERTY_L2_________________, _____________MOD_QWERTY_R2_________________,
        _____________MOD_QWERTY_L3_________________, _____________MOD_QWERTY_R3_________________
  ),

  //[_MACOS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //   _______ ,_______ ,_______ ,_______ ,V__LCMD ,B_LCTRL ,_______ ,OSX_DSP ,        _______ ,_______ ,N_RCTRL ,M__RCMD ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
  //   _______ ,_______ ,_______ ,KC_LOPT ,     _______ ,    KC_LCMD ,_______ ,        KC_RCMD ,_______ ,    _______ ,     KC_ROPT ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  //),

  [_LOWER] = LAYOUT_wrapper(
     _______ ,_________________LOWER_L1__________________ ,                                            _________________LOWER_R1__________________ ,_______ ,
     _______ ,_________________LOWER_L1__________________ ,_______ ,                          _______ ,_________________LOWER_R1__________________ ,KC_EQL  ,
     _______ ,_________________LOWER_L2__________________ ,_______ ,                          _______ ,_________________LOWER_R2__________________ ,KC_BSLS ,
     _______ ,_________________LOWER_L3__________________ ,_______ ,_______ ,        _______ ,_______ ,_________________LOWER_R3__________________ ,_______ ,
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  ),

  [_RAISE] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  // _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // _______ ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,_______ ,                          _______ ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_MINS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // _______ ,KC_HASH ,KC_DLR  ,KC_LPRN ,KC_RPRN ,KC_GRV  ,_______ ,                          _______ ,KC_LBRC ,KC_4    ,KC_5    ,KC_6    ,KC_PPLS ,KC_PAST ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // _______ ,KC_PERC ,KC_CIRC ,KC_LCBR ,RB_LCTL ,KC_TILD ,KC_LBRC ,KC_RBRC ,        _______ ,_______ ,KC_RBRC ,KC_1    ,KC_2    ,KC_3    ,_______ ,KC_PSLS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
  // _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_0    ,     KC_PDOT ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     _______ ,_________________RAISE_L1__________________ ,                                            _________________RAISE_R1__________________ ,_______ ,
     _______ ,_________________RAISE_L1__________________ ,_______ ,                          _______ ,_________________RAISE_R1__________________ ,_______ ,
     _______ ,_________________RAISE_L2__________________ ,_______ ,                          _______ ,_________________RAISE_R2__________________ ,KC_PAST ,
     _______ ,_________________RAISE_L3__________________ ,KC_LBRC ,KC_RBRC ,        _______ ,_______ ,_________________RAISE_R3__________________ ,KC_PSLS ,
     _______ ,_______ ,_______ ,_______ ,     TO(0) ,      _______ ,TO(0)   ,        _______ ,_______ ,    KC_0    ,     KC_PDOT ,_______ ,_______ ,_______
  ),

  [_ADJUST] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  // _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // VK_TOGG ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,_______ ,                          _______ ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_UNDS ,KC_UNDS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // CW_TOGG ,RGB_SAI ,RGB_HUI ,RGB_VAI ,RGB_SPI ,RGB_MOD ,_______ ,                          _______ ,KC_BRID ,KC_BRIU ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // RGB_TOG ,_______ ,_______ ,_______ ,_______ ,_______ ,RGB_M_P ,RGB_M_B ,        RGB_M_R ,RGB_M_SW,RGB_M_SN,RGB_M_K ,RGB_M_X ,RGB_M_G ,RGB_M_T ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
  // KC_MUTE ,_______ ,_______ ,_______ ,     _______ ,    KC_NLCK ,KC_SCRL ,        KC_INS  ,MACOS_L ,    DEFAU_L ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     _______ ,_________________FUNC_LEFT_________________ ,                                            _________________FUNC_RIGHT________________ ,_______ ,
     VK_TOGG ,_________________ADJUST_L1_________________ ,_______ ,                          _______ ,_________________ADJUST_R1_________________ ,KC_UNDS ,
     CW_TOGG ,_________________ADJUST_L2_________________ ,_______ ,                          _______ ,_________________ADJUST_R2_________________ ,_______ ,
     RGB_TOG ,_________________ADJUST_L3_________________ ,RGB_M_P ,RGB_M_B ,        RGB_M_R ,RGB_M_SW,_________________ADJUST_R3_________________ ,_______ ,
     KC_MUTE ,_______ ,_______ ,KC_MUTE ,     _______ ,    KC_NUM  ,KC_SCRL ,        KC_INS  ,MACOS_L ,    DEFAU_L ,     _______ ,_______ ,_______ ,_______
  )
};
