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

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_LIMIT_VAL 190 // Reduce power consumption.
  // Orients Kyria LEDs to a circle around both halves:
  #define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13}
  // Orients Kyria LEDs for a left half-right half columnar progression:
  //#define RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,10,12,13,11,14,16,17,15,18,19}
#endif

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
