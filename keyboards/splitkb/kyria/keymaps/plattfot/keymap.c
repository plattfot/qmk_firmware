/* Copyright 2020-2021 Fredrik Salomonsson <plattfot@gmail.com>
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
#include "version.h"
#include "plattfot.h"

enum custom_keycodes {
  PLACEHOLDER = CLOSE_TAP_SAFE_RANGE,  // can always be here
  // New keys
};

enum layers {
    _BASE,
    _L_SYMFU,
    _R_SYMFU,
    _R_SHORT,
    _ADJUST,
    _NAV,
};

#define TO_BASE TO(_BASE)

#define L_SYMFU OSL(_L_SYMFU)
#define R_SYMFU OSL(_R_SYMFU)
#define R_SHORT OSL(_R_SHORT)

#define OSL_ADJ OSL(_ADJUST)
#define TGL_NAV TG(_NAV)

int plt_base_index(void) {return _BASE;}
int plt_nav_index(void) {return _NAV;}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Default
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   ;  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  RAlt  |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |  RAlt  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |      |LSYMFU|  |RSYMFU|      |   K  |   H  |   ,  |   .  |   /  | RShift |
 * `----------------------+------+------+------| Space|------|  |------| Enter|------+------+------+----------------------'
 *                        | MPlay| LAlt | LGUI |      | LCtrl|  | RCtrl|      | RGUI | LAlt | Tgl  |
 *                        |      |      |      |      |      |  |      |      |      |      | Nav  |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
      XXXXXXX, KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, XXXXXXX,
      KC_RALT, KC_A,   KC_R,   KC_S,   KC_T,   KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_RALT,
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,    XXXXXXX,  L_SYMFU, R_SYMFU, XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_MPLY,KC_LALT,KC_LGUI, KC_SPACE, KC_LCTL, KC_RCTL,  KC_ENT, KC_RGUI, KC_LALT, TGL_NAV
    ),

/*
 * Left symbol and function Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F12 |  F9  |  F8  |  F7  |      |                              |   ^  |  &   |  *   |  ~   |  :   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F11 |  F3  |  F2  |  F1  |CLOTAP|                              |   =  |  {   |  }   |  [   |  ]   |   `    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F10 |  F6  |  F5  |  F4  | Tab  |      | BASE |  | BASE |      |   …  |  "   |  <   |  >   |  ?   |        |
 * `----------------------+------+------+------|ADJUST|------|  |------| BSpc |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_L_SYMFU] = LAYOUT(
      _______, KC_F12,  KC_F9,   KC_F8,   KC_F7,   _______,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE,KC_COLN, _______,
      _______, KC_F11,  KC_F3,   KC_F2,   KC_F1,   CLO_TAP,                                     KC_EQUAL,KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
      _______, KC_F10,  KC_F6,   KC_F5,   KC_F4,   KC_TAB,  XXXXXXX, TO_BASE, TO_BASE, XXXXXXX, EU_TDOT, KC_DQUO, KC_LT,   KC_GT,   KC_QUES, _______,
                                 _______, _______, _______, OSL_ADJ, _______, _______, KC_BSPC, _______, _______, _______

    ),

/*
 * Right symbol and number Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                              |      |  7   |  8   |  9   |  ,   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  |   |  _   |  \   |  -   |  +   |                              |CLOTAP|  1   |  2   |  3   |  0   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  °   |  (   |  )   |  '   |  `   |      | BASE |  | BASE |      | Tab  |  4   |  5   |  6   |  .   |        |
 * `----------------------+------+------+------| Del  |------|  |------|RSHORT|------+------+------+----------------------'
 *                        | Mic  |      |      |      |      |  |      | Cuts |      |      |      |
 *                        | Mute |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

    [_R_SYMFU] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                     _______, KC_7,    KC_8,   KC_9,   KC_COMM, _______,
      _______, KC_PIPE, KC_UNDS, KC_BSLS, KC_MINS, KC_PLUS,                                     CLO_TAP, KC_1,    KC_2,   KC_3,   KC_0,    _______,
      _______, EU_DEG,  KC_LPRN, KC_RPRN, KC_QUOT, KC_GRV,  XXXXXXX, TO_BASE, TO_BASE, XXXXXXX, KC_TAB,  KC_4,    KC_5,   KC_6,   KC_DOT,  _______,
                                 KC_F20,  _______, _______, KC_DEL,  _______, _______, R_SHORT, _______, _______, _______
    ),

/*
 * Right short cuts
 */
    [_R_SHORT] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, G(KC_7), G(KC_8), G(KC_9), _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, G(KC_1), G(KC_2), G(KC_3), G(KC_0), _______,
      _______, _______, _______, _______, _______, _______, XXXXXXX, TO_BASE, TO_BASE, XXXXXXX, _______, G(KC_4), G(KC_5), G(KC_6), _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

    ),

/*
 * Adjust Layer: RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      | Caps | Ins  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      | BASE |  | BASE |      |      |      |      |      |      |        |
 * `----------------------+------+------+------|      |------|  |------|      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, KC_CAPS, KC_INS,  _______, _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,XXXXXXX, TO_BASE, TO_BASE, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |   →  |   ↑  |   ←  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |  ↓   |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | BASE |  | BASE |      |      |      |      |      |      |        |
 * `----------------------+------+------+------|      |------|  |------|      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, KC_RGHT, KC_UP,   KC_LEFT,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_DOWN, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, XXXXXXX, TO_BASE, TO_BASE, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

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
//       _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};
// clang-format on

/* void keyboard_post_init_user(void) { */
/*   rgblight_setrgb(51, 135, 204); */
/* } */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }
    if (!process_close_tap(keycode, record)) { return false; }

    if (record->event.pressed) {
        switch (keycode) {
            case KC_LEAD:
              cancel_close_tap();
              return true;
        }
    }

    return true;
}

void matrix_scan_user(void) {
    caps_word_task();
}

//layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

// clang-format off
static void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

    oled_write_P(qmk_logo, false);
}
// clang-format on
static void render_static_info(void) {
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n"), false);
    oled_write_P(PSTR("Keymap: plattfot v2\n"), false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n"), false);
    oled_write_P(PSTR("v" QMK_VERSION "\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("base\n"), false);
            break;
        case _R_SYMFU:
            oled_write_P(PSTR("<-sym|num->\n"), false);
            break;
        case _L_SYMFU:
            oled_write_P(PSTR("<-fun|sym->\n"), false);
            break;
        case _R_SHORT:
            oled_write_P(PSTR("shortcuts->\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("adjust\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("navigation\n"), false);
            break;
        default:
            oled_write_P(PSTR("undefined\n"), false);
    }

    // Host Keyboard LED Status and Double tap
    led_t led_state = host_keyboard_led_state();
    if (led_state.num_lock) {
        oled_write_P(PSTR("NUMLCK "), false);
    } else if (is_close_tap_active()) {
        oled_write_P(PSTR("CLOTAP "), false);
    } else {
        oled_write_P(PSTR("       "), false);
    }

    if (led_state.caps_lock) {
        oled_write_P(PSTR("CAPLCK "), false);
    } else if (caps_word_get()) {
        oled_write_P(PSTR("CAPWRD "), false);
    } else {
        oled_write_P(PSTR("       "), false);
    }

    oled_write_P(led_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_static_info();
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _R_SYMFU:
                // Skip/Prev song
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                break;
            default:
                // Volume control
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                break;
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _L_SYMFU:
                // Scroll left and right through the containers
                if (clockwise) {
                    tap_code16(G(KC_F));
                } else {
                    tap_code16(G(KC_B));
                }
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                break;
            case _ADJUST:
                // Scroll up and down through the containers
                if (clockwise) {
                    tap_code16(G(KC_N));
                } else {
                    tap_code16(G(KC_P));
                }
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                break;
            default:
                // Scrolling
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                break;
        }
    }
    return false;
}
#endif
