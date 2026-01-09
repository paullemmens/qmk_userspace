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
#pragma once

#ifdef WPM_ENABLE
  /* #define BONGOCAT */
  #define BONGO2
  /* #define WPM_GRAPH */
  #define SPLIT_WPM_ENABLE
#endif

#ifdef OLED_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#if defined(RGBLIGHT_ENABLE) 
  #define RGBLIGHT_LIMIT_VAL 190 // Reduce power consumption.
  // Orients Kyria LEDs to a circle around both halves:
  #define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13}
  // Orients Kyria LEDs for a left half-right half columnar progression:
  //#define RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,10,12,13,11,14,16,17,15,18,19}
#endif //RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE
  #define RGB_MATRIX_DISABLE_SHARED_KEYCODES

  #define RGB_MATRIX_MODE_NAME_ENABLE // enables rgb_matrix_get_mode_name()

  //#define RGB_MATRIX_KEYRELEASES // reactive effects respond to keyreleases (instead of keypresses)
  #define RGB_MATRIX_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
  #define RGB_MATRIX_SLEEP // turn off effects when suspended
  #define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
  #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
  //#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
  #define RGB_MATRIX_DEFAULT_ON true // Sets the default enabled state, if none has been set
  #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINBOW_PINWHEELS // Sets the default mode, if none has been set
  #define RGB_MATRIX_DEFAULT_HUE 0 // Sets the default hue value, if none has been set
  #define RGB_MATRIX_DEFAULT_SAT 255 // Sets the default saturation value, if none has been set
  #define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
  #define RGB_MATRIX_DEFAULT_SPD 127 // Sets the default animation speed, if none has been set
  #define RGB_MATRIX_HUE_STEP 8 // The value by which to increment the hue per adjustment action
  #define RGB_MATRIX_SAT_STEP 16 // The value by which to increment the saturation per adjustment action
  #define RGB_MATRIX_VAL_STEP 16 // The value by which to increment the brightness per adjustment action
  #define RGB_MATRIX_SPD_STEP 16 // The value by which to increment the animation speed per adjustment action
  #define RGB_MATRIX_DEFAULT_FLAGS LED_FLAG_ALL // Sets the default LED flags, if none has been set
  #define RGB_TRIGGER_ON_KEYDOWN      // Triggers RGB keypress events on key down. This makes RGB control feel more responsive. This may cause RGB to not function properly on some boards
  //#define RGB_MATRIX_FLAG_STEPS { LED_FLAG_ALL, LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER, LED_FLAG_UNDERGLOW, LED_FLAG_NONE } // Sets the flags which can be cycled through.

  // List of animations that can run on the rgb matrix.
  #define ENABLE_RGB_MATRIX_ALPHAS_MODS
  /* #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN */
  #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_BREATHING
  /* #define ENABLE_RGB_MATRIX_BAND_SAT */
  /* #define ENABLE_RGB_MATRIX_BAND_VAL */
  /* #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT */
  /* #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL */
  /* #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT */
  /* #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL */
  /* #define ENABLE_RGB_MATRIX_CYCLE_ALL */
  #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  /* #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN */
  #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  /* #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN */
  /* #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL */
  /* #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL */
  /* #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL */
  /* #define ENABLE_RGB_MATRIX_DUAL_BEACON */
  #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
  #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  #define ENABLE_RGB_MATRIX_FLOWER_BLOOMING
  /* #define ENABLE_RGB_MATRIX_RAINDROPS */
  /* #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS */
  /* #define ENABLE_RGB_MATRIX_HUE_BREATHING */
  /* #define ENABLE_RGB_MATRIX_HUE_PENDULUM */
  /* #define ENABLE_RGB_MATRIX_HUE_WAVE */
  /* #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL */
  /* #define ENABLE_RGB_MATRIX_PIXEL_FLOW */
  /* #define ENABLE_RGB_MATRIX_PIXEL_RAIN */
  /* #define ENABLE_RGB_MATRIX_STARLIGHT */
  #define ENABLE_RGB_MATRIX_STARLIGHT_SMOOTH
  /* #define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE */
  /* #define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT */
  /* #define ENABLE_RGB_MATRIX_RIVERFLOW */
  /* #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE */
  /* #define ENABLE_RGB_MATRIX_SOLID_REACTIVE */
  /* #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE */
  /* #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE */
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
  /* #define ENABLE_RGB_MATRIX_SPLASH */
  /* #define ENABLE_RGB_MATRIX_MULTISPLASH */
  /* #define ENABLE_RGB_MATRIX_SOLID_SPLASH */
  /* #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH */
  #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#endif //RGB_MATRIX_ENABLE

// Encoder settings.
// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10

#if defined(KEYBOARD_splitkb_kyria_rev1)
  #define ENCODER_DIRECTION_FLIP
#endif
// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
#define ENCODER_RESOLUTION 2

// Ensure that we can double tap reset to go into bootloader mode.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 300U // Timeout window in ms in which the double tap can occur.
/* #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led by GPIO number which blinks when entering the bootloader */


// https://docs.splitkb.com/hc/en-us/articles/5799711553820-Power-LED
#define LED_CAPS_LOCK_PIN 24
#define LED_PIN_ON_STATE 0
