/* Used for global configuration options used for all keyboards. */
#pragma once

/* Space optimizations from https://docs.qmk.fm/#/squeezing_avr */
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
/* #define NO_ACTION_ONESHOT */
#define LAYER_STATE_8BIT


/* Shared settings for keyboards */
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_SLEEP
  #define RGBLIGHT_SPLIT
  #define RGBLIGHT_EFFECT_STATIC_LIGHT
  #define RGBLIGHT_EFFECT_ALTERNATING
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_KNIGHT
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_EFFECT_TWINKLE
#endif


/* Customize timing related settings to make home row mods work for me. */
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD_PER_KEY
/* I so rarely want this, that it is not worthwhile enabling and defaulting to false. */
/* #define HOLD_ON_OTHER_KEY_PRESS */

/* #define TAPPING_FORCE_HOLD */
#define TAPPING_TOGGLE 2


// Personal configuration directives

// Tap both shifts to activate caps word; in case of mod-tap press and hold
// until tapping term.
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000  // 3 seconds.
