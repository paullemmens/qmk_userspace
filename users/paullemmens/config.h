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
#endif


/* Customize timing related settings to make home row mods work for me. */
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD_PER_KEY

/* #define TAPPING_FORCE_HOLD */
#define TAPPING_TOGGLE 2


// Personal configuration directives

// https://docs.splitkb.com/hc/en-us/articles/5799711553820-Power-LED
#if defined(KEYBOARD_splitkb_kyria_rev2)
  #define LED_CAPS_LOCK_PIN 24
  #define LED_PIN_ON_STATE 0
#endif
