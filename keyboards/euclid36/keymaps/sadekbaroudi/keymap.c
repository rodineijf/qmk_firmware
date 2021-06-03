/* Copyright 2021 Sadek Baroudi
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

#include "sadekbaroudi.h"

#include QMK_KEYBOARD_H

#ifndef UNICODE_ENABLE
#    define UC(x) KC_NO
#endif

#ifdef THUMBSTICK_ENABLE
#    include "thumbstick.h"
#endif

// Uncomment to set up WPM
//char wpm_as_str[8];

/*
 * The `LAYOUT_euclid36_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_euclid36_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
        K01,            K02,            K03,            K04,            K05,                K06,            K07,            LT(_WINNAV,K08),  K09,            K0A, \
        LCTL_T(K11),    LGUI_T(K12),    LALT_T(K13),    LSFT_T(K14),    K15,                K16,            RSFT_T(K17),    RALT_T(K18),      RGUI_T(K19),    RCTL_T(K1A), \
        LSFT_T(K21),    K22,            K23,            K24,            K25,                K26,            K27,            K28,              K29,            RSFT_T(K2A), \
                       KC_MUTE,  KC_DEL, LT(_NAVIGATION,KC_ENT), LT(_FUNCTION,KC_TAB),     LT(_FUNCTION,KC_BSPC), LT(_SYMBOLS,KC_SPACE), LT(_MOUSE,KC_QUOT),  LCTL(KC_BSPC) \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_euclid36_base_wrapper(...)       LAYOUT_euclid36_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_euclid36_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_COLEMAK] = LAYOUT_euclid36_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),

    [_WORKMAN] = LAYOUT_euclid36_base_wrapper(
        _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
        _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
        _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
    ),

    [_NAVIGATION] = LAYOUT_wrapper(
        ________________NAVIGATION_1_______________, _________________NUMPAD_1__________________,
        ________________NAVIGATION_2_______________, _________________NUMPAD_2__________________,
        ________________NAVIGATION_3_______________, _________________NUMPAD_3__________________,
                 _______,  _______, _______, KC_TAB, KC_BSPC, MO(_MEDIA), KC_DOT, _______
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
        ________________SYMBOLS_L1_________________, ________________SYMBOLS_R1_________________,
        ________________SYMBOLS_L2_________________, ________________SYMBOLS_R2_________________,
        ________________SYMBOLS_L3_________________, ________________SYMBOLS_R3_________________,
               _______, _______, MO(_MEDIA), KC_TAB, KC_BSPC, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ________________SHIFTNAV_1_________________, ________________FUNCTION_1_________________,
        ________________SHIFTNAV_2_________________, ________________FUNCTION_2_________________,
        ________________SHIFTNAV_3_________________, ________________FUNCTION_3_________________,
                 _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
        ___________________RGB_1___________________, _________________MACROS_1__________________,
        ___________________RGB_2___________________, _________________MACROS_2__________________,
        ___________________RGB_3___________________, _________________MACROS_3__________________,
                 _______, _______, _______, _______, _______, _______, _______, _______
    ),
    
    [_MOUSE] = LAYOUT_wrapper(
        __________________MOUSE_1__________________, ___________________BLANK___________________,
        __________________MOUSE_2__________________, ___________________BLANK___________________,
        __________________MOUSE_3__________________, ___________________BLANK___________________,
           _______, _______, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN3, KC_MS_BTN2, _______, _______
    ),

    [_WINNAV] = LAYOUT_wrapper(
        __________________WIN_NAV_1________________, ___________________BLANK___________________,
        __________________WIN_NAV_2________________, ___________________BLANK___________________,
        ___________________BLANK___________________, ___________________BLANK___________________,
                 _______, _______, _______, _______, _______, _______, _______, _______
    )

};


#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
      return OLED_ROTATION_180;
}  

// Commenting out logo as it takes up a lot of space :(
static void render_logo(void) {
    // euclid36_logo, 128x32px
    static const char PROGMEM euclid36_logo[] = {
    // // 'logo', 128x32px
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0x70, 0x70, 0x70, 0x70, 0x70, 0xe0, 0xe0, 0xc0, 0x00, 0x00, 
    // 0x00, 0x60, 0x70, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x20, 0x70, 0x70, 0xf0, 0xf0, 0xe0, 0x00, 0x00, 
    // 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0x70, 0x70, 0x70, 0x70, 0x70, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x60, 0x70, 0x70, 0x73, 0xf3, 0xf3, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0xc0, 0xc0, 0xe0, 0x70, 0x70, 0x70, 0x70, 0x73, 0xe3, 0xe3, 0xff, 0xff, 0x00, 0x00, 0x00, 
    // 0x00, 0x04, 0x0e, 0x07, 0x03, 0xc3, 0xc3, 0xc3, 0xe3, 0xf7, 0xff, 0x3e, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0xc0, 0xf0, 0xfc, 0xbe, 0xce, 0xc7, 0xc7, 0xc3, 0xc3, 0xc3, 0x83, 0x03, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x1f, 0x3f, 0x7f, 0x66, 0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 0x67, 0x77, 0x67, 0x00, 
    // 0x00, 0x00, 0x00, 0x3f, 0x7f, 0xf8, 0xe0, 0xe0, 0xe0, 0x60, 0x70, 0xff, 0xff, 0xff, 0x60, 0x00, 
    // 0x00, 0x00, 0x1f, 0x3f, 0x71, 0x60, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x71, 0x71, 0x30, 0x00, 
    // 0x00, 0x40, 0x60, 0xe0, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xe0, 0x60, 0x00, 0x00, 
    // 0x00, 0x60, 0xe0, 0xe0, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0x60, 0x40, 0x00, 0x00, 
    // 0x0f, 0x3f, 0x7f, 0x70, 0xe0, 0xe0, 0xe0, 0xe0, 0x60, 0x70, 0x7b, 0xff, 0xff, 0xe0, 0x60, 0x00, 
    // 0x00, 0x70, 0x70, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe1, 0x71, 0x7f, 0x3f, 0x1e, 0x00, 0x00, 0x00, 
    // 0x00, 0x03, 0x1f, 0x3f, 0x7f, 0xe1, 0xe1, 0xe0, 0xe0, 0xe1, 0x7f, 0x3f, 0x1e, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

    // 'logo-2, 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 
    0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xe0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
    0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 
    0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf0, 0x38, 
    0x38, 0x38, 0x38, 0xfc, 0xf8, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0xf0, 0xfc, 0xfc, 0xfc, 0xfc, 0x78, 
    0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0x78, 0x38, 
    0x78, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xe0, 0x80, 0x00, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 
    0x00, 0x03, 0xc3, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0x78, 0x78, 
    0x78, 0xf8, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3c, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x1f, 0x03, 
    0x07, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xe0, 0xfe, 0xff, 0xff, 0xff, 0x87, 0x03, 0x07, 0x7f, 
    0x7f, 0x7f, 0x7f, 0x7e, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xe6, 
    0xe6, 0xc7, 0xe7, 0xe7, 0xe3, 0xe3, 0xe1, 0xe0, 0x00, 0x00, 0x3f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3c, 
    0x38, 0x38, 0x38, 0x1c, 0x7f, 0xff, 0xff, 0xfc, 0x60, 0x00, 0x7f, 0xff, 0xff, 0xf3, 0xc0, 0xc0, 
    0xc0, 0xc0, 0xc3, 0xc3, 0xc3, 0xe3, 0xe1, 0x00, 0x00, 0x9f, 0xff, 0xff, 0xff, 0xfe, 0xc0, 0xc0, 
    0x80, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 
    0xf0, 0xf0, 0xf8, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xc0, 0xc6, 0x87, 0x8f, 
    0x8f, 0x8f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x1e, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x87, 0x86, 
    0x86, 0x86, 0xce, 0xfe, 0xfc, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 
    0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 
    0x00, 0x01, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
    0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
    0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(euclid36_logo, sizeof(euclid36_logo));
}

static void render_status(void) {
  oled_write_P(PSTR("euclid36\n"), false);
  // Uncomment to set up WPM
//  sprintf(wpm_as_str, "WPM %03d", get_current_wpm());
//  oled_write(wpm_as_str,false);
  led_t led_state = host_keyboard_led_state();
  oled_write_P(PSTR("Caps: "), false);
  oled_write_P(led_state.caps_lock ? PSTR("on ") : PSTR("off"), false);
  oled_write_P(PSTR("\n"),false);
  switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty "), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Colemak"), false);
            break;
        case _WORKMAN:
            oled_write_P(PSTR("Workman"), false);
            break;
        case _NAVIGATION:
            oled_write_P(PSTR("Nav    "), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Function"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media  "), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse  "), false);
            break;
        case _WINNAV:
            oled_write_P(PSTR("Win nav"), false);
            break;

        default:
            oled_write_P(PSTR("Unkn "), false);
            break;
    }
}

void oled_task_user(void) {
    // If you don't want to display the logo, switch
    if (false) {
        render_status();
    } else {
        render_logo();
    }
}

#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
      if(clockwise) {
        tap_code16(C(KC_LEFT));
      }
      else{
        tap_code16(C(KC_RGHT));
      }
    }
}
#endif