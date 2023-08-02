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
  OS_LSFT,
  OS_RSFT
  // New keys
};

enum layers {
    _BASE,
    _L_SYMFU,
    _R_SYMFU,
    _R_SHORT,
    _NAV,
};

#define L_SYMFU OSL(_L_SYMFU)
#define R_SYMFU OSL(_R_SYMFU)
#define R_SHORT OSL(_R_SHORT)

#define OSL_NAV OSL(_NAV)

int plt_base_index(void) {return _BASE;}
int plt_nav_index(void) {return _NAV;}
int plt_shortcut_index(void) {return _R_SHORT;}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Default
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Nav   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   ;  |  Nav   |
 * |--------+-AltGr+-LGui-+-LCtl-+-LAlt-+--Clr-|                              |-RSrt-+-LAlt-+-RCtl-+-RGui-+-AltGr+--------|
 * |  Tab   |   A  |   R  |   S  |   T  |   G  Caps                        Word   M  |   N  |   E  |   I  |   O  |  BSpc  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |      | LAlt |  | LAlt |      |   K  |   H  |   ,  |   .  |   /  | RShift |
 * `----------------------+------+------+------| Space|------|  |------| Enter|------+------+------+----------------------'
 *                        | MPlay| LGui | LSYMF|      | LCtrl|  | RCtrl|      | RSYMF| RGui | MMute|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `-----------------------Esc--------'  `--------Esc-----------------------'
 */
 [_BASE] = LAYOUT(
      OSL_NAV, KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, OSL_NAV,
      KC_TAB,  KC_A,   KC_R,   KC_S,   KC_T,   KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_BSPC,
      OS_LSFT, KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,    XXXXXXX,  KC_LALT, KC_LALT, XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OS_RSFT,
                               KC_MPLY,KC_LGUI,L_SYMFU, KC_SPACE, KC_LCTL, KC_RCTL,  KC_ENT, R_SYMFU, KC_LGUI, KC_F20
    ),

/*
 * Left symbol and function Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |  F9  |  F8  |  F7  | F12  |                              |   [  |  ]   |  `   |  $   |  …   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F10 |  F3  |  F2  |  F1  | F11  |                              |   {  |  }   |  '   |  :   |  ^   |  Del   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |  F6  |  F5  |  F4  |CLOTAP|      |      |  |      |      |   <  |  >   |  "   |  ~   |  ?   |        |
 * `----------------------+------+------+------|      |------|  |------|      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_L_SYMFU] = LAYOUT(
      _______, _______, KC_F9,   KC_F8,   KC_F7,   KC_F12,                                      KC_LBRC, KC_RBRC, KC_GRV,  KC_DLR,  EU_TDOT, _______,
      _______, KC_F10,  KC_F3,   KC_F2,   KC_F1,   KC_F11,                                      KC_LCBR, KC_RCBR, KC_QUOT, KC_COLN, KC_CIRC, KC_DEL,
      _______, _______, KC_F6,   KC_F5,   KC_F4,   CLO_TAP, XXXXXXX, _______, _______, XXXXXXX, KC_LT,   KC_GT,   KC_DQUO, KC_TILDE,KC_QUES, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

    ),

/*
 * Right symbol and number Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  °   |  @   |  *   |  #   |  %   |                              |      |  7   |  8   |  9   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  |   |  _   |  -   |  (   |  )   |                              |      |  1   |  2   |  3   |  0   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  !   |  \   |  +   |  =   |  &   |      |      |  |      |      |CLOTAP|  4   |  5   |  6   |      |        |
 * `----------------------+------+------+------|      |------|  |------|      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

    [_R_SYMFU] = LAYOUT(
      _______, EU_DEG,  KC_AT,   KC_ASTR, KC_HASH, KC_PERC,                                     _______, KC_7,    KC_8,   KC_9,   _______, _______,
      _______, KC_PIPE, KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN,                                     _______, KC_1,    KC_2,   KC_3,   KC_0,    _______,
      _______, KC_EXLM, KC_BSLS, KC_PLUS, KC_EQUAL,KC_AMPR, XXXXXXX, _______, _______, XXXXXXX, CLO_TAP, KC_4,    KC_5,   KC_6,   _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Right short cuts
 */
    [_R_SHORT] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, G(KC_7), G(KC_8), G(KC_9), _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, G(KC_1), G(KC_2), G(KC_3), G(KC_0), _______,
      _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, G(KC_4), G(KC_5), G(KC_6), _______, _______,
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
      _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______,
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
    // Workaround for OSM(MOD_LSFT) not working correctly
    switch (keycode)
    {
    case OS_LSFT:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            add_oneshot_mods(MOD_BIT(KC_LSFT));
        } else {
            unregister_code(KC_LSFT);
        }
        return false;
    case OS_RSFT:
        if (record->event.pressed) {
            register_code(KC_RSFT);
            add_oneshot_mods(MOD_BIT(KC_RSFT));
        } else {
            unregister_code(KC_RSFT);
        }
        return false;
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
    oled_write_P(PSTR("Keymap: plattfot v3\n"), false);
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
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                break;
            default:
                // Scrolling
                if (clockwise) {
                    tap_code16(C(KC_PGDN));
                } else {
                    tap_code16(C(KC_PGUP));
                }
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                break;
        }
    }
    return false;
}
#endif
