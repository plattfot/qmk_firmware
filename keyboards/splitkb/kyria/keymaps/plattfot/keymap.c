/* Copyright 2020-2023 Fredrik Salomonsson <plattfot@gmail.com>
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
int plt_left_symfunc_index(void) {return _L_SYMFU;}
int plt_shortcut_index(void) {return _R_SHORT;}

enum combo_events {
  C_ESC,
  C_CAPS, // caps word
  // Upper left hand
  C_CLEAR, // clear state
  C_LALTL,
  C_LCTRL,
  C_LSHIFT,
  C_LGUI,

  // Upper right hand
  C_RSHORT,
  C_LALTR,
  C_RCTRL,
  C_RSHIFT,
  C_RGUI,

  // Lower left hand
  C_LNAV, // to navigation
  C_RALTL,

  // Lower right hand
  C_RNAV, // to navigation
  C_RALTR,

  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM esc_combo[] = {KC_SPACE, KC_ENT, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_G, KC_M, COMBO_END};

const uint16_t PROGMEM clear_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM lshift_combo[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM lctrl_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM laltl_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM lgui_combo[] = {KC_Q, KC_A, COMBO_END};

const uint16_t PROGMEM rshort_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM rshift_combo[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM rctrl_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM laltr_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM rgui_combo[] = {KC_SCLN, KC_O, COMBO_END};

const uint16_t PROGMEM lnav_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM raltl_combo[] = {KC_S, KC_C, COMBO_END};

const uint16_t PROGMEM rnav_combo[] = {KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM raltr_combo[] = {KC_E, KC_COMM, COMBO_END};

combo_t key_combos[] = {
 [C_ESC] = COMBO_ACTION(esc_combo),
 [C_CAPS] = COMBO_ACTION(caps_combo),

 [C_CLEAR] = COMBO_ACTION(clear_combo),
 [C_LALTL] = COMBO_ACTION(laltl_combo),
 [C_LCTRL] = COMBO_ACTION(lctrl_combo),
 [C_LSHIFT] = COMBO_ACTION(lshift_combo),
 [C_LGUI] = COMBO_ACTION(lgui_combo),

 [C_RSHORT] = COMBO_ACTION(rshort_combo),
 [C_LALTR] = COMBO_ACTION(laltr_combo),
 [C_RCTRL] = COMBO_ACTION(rctrl_combo),
 [C_RSHIFT] = COMBO_ACTION(rshift_combo),
 [C_RGUI] = COMBO_ACTION(rgui_combo),

 [C_LNAV] = COMBO_ACTION(lnav_combo),
 [C_RALTL] = COMBO_ACTION(raltl_combo),

 [C_RNAV] = COMBO_ACTION(rnav_combo),
 [C_RALTR] = COMBO_ACTION(raltr_combo),
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Default
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   ;  |
 * |-LGui-+-LAlt-+-LCtl-+-LSft-+--Clr-|                              |-RSrt-+-LSft-+-RCtl-+-RAlt-+-RGui-|
 * |   A  |   R  |   S  |   T  |   G  Caps                        Word   M  |   N  |   E  |   I  |   O  |
 * |------+------+-AltGr+-Nav--+------+-------------.  ,-------------+------+-Nav--+-AltGr+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |      |      |  |      |      |   K  |   H  |   ,  |   .  |   /  |
 * `-------------+------+------+------| Space| Tab  |  | BS   | Enter|------+------+------+-------------'
 *               | MPlay|      | LSYMF|      |      |  |      |      | RSYMF|      | MMute|
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               `------+      +---------Esc--------'  `--------Esc---------+      +------'
 */
 [_BASE] = LAYOUT(
      XXXXXXX, KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, XXXXXXX,
      XXXXXXX, KC_A,   KC_R,   KC_S,   KC_T,   KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    XXXXXXX,
      XXXXXXX, KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                               KC_MPLY,XXXXXXX,L_SYMFU, KC_SPACE, KC_TAB,  KC_BSPC, KC_ENT, R_SYMFU, XXXXXXX, KC_F20
    ),

/*
 * Left symbol and function Layer
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |      |  F9  |  F8  |  F7  | F12  |                              |   [  |  ]   |  `   |  $   |  …   |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |  F10 |  F3  |  F2  |  F1  | F11  |                              |   {  |  }   |  '   |  :   |  ^   |
 * |------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------|
 * |      |  F6  |  F5  |  F4  |CLOTAP|      |      |  |      |      |   <  |  >   |  "   |  ~   |  ?   |
 * `-------------+------+------+------|      |      |  |      |      |------+------+------+-------------'
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               `------+      +--------------------'  `--------------------+      +------'
 */
    [_L_SYMFU] = LAYOUT(
      XXXXXXX, _______, KC_F9,   KC_F8,   KC_F7,   KC_F12,                                      KC_LBRC, KC_RBRC, KC_GRV,  KC_DLR,  EU_TDOT, XXXXXXX,
      XXXXXXX, KC_F10,  KC_F3,   KC_F2,   KC_F1,   KC_F11,                                      KC_LCBR, KC_RCBR, KC_QUOT, KC_COLN, KC_CIRC, XXXXXXX,
      XXXXXXX, _______, KC_F6,   KC_F5,   KC_F4,   CLO_TAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_DQUO, KC_TILDE,KC_QUES, XXXXXXX,
                                 _______, XXXXXXX, _______, _______, _______, KC_DEL,  _______, _______, XXXXXXX, _______

    ),

/*
 * Right symbol and number Layer
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |  °   |  @   |  *   |  #   |  %   |                              |      |  7   |  8   |  9   |      |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |  |   |  _   |  -   |  (   |  )   |                              |      |  1   |  2   |  3   |  0   |
 * |------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------|
 * |  !   |  \   |  +   |  =   |  &   |      |      |  |      |      |CLOTAP|  4   |  5   |  6   |      |
 * `-------------+------+------+------|      |      |  |      |      |------+------+------+-------------'
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               `------+      +--------------------'  `--------------------+      +------'
 */

    [_R_SYMFU] = LAYOUT(
      XXXXXXX, EU_DEG,  KC_AT,   KC_ASTR, KC_HASH, KC_PERC,                                     _______, KC_7,    KC_8,   KC_9,   _______, XXXXXXX,
      XXXXXXX, KC_PIPE, KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN,                                     _______, KC_1,    KC_2,   KC_3,   KC_0,    XXXXXXX,
      XXXXXXX, KC_EXLM, KC_BSLS, KC_PLUS, KC_EQUAL,KC_AMPR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CLO_TAP, KC_4,    KC_5,   KC_6,   _______, XXXXXXX,
                                 _______, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, _______
    ),

/*
 * Right short cuts
 */
    [_R_SHORT] = LAYOUT(
      XXXXXXX, _______, _______, _______, G(KC_UP),_______,                                     _______, G(KC_7), G(KC_8), G(KC_9), _______, XXXXXXX,
      XXXXXXX, _______, _______, _______, A(C(KC_M)), _______,                                  _______, G(KC_1), G(KC_2), G(KC_3), G(KC_0), XXXXXXX,
      XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, G(KC_4), G(KC_5), G(KC_6), _______, XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______

    ),

/*
 * Navigation
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |      |      |   →  |   ↑  |   ←  |                              |      |      |      |      |      |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |      |      |      |      |      |                              |      |  ↓   |      |      |      |
 * |------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |
 * `-------------+------+------+------|      |      |  |      |      |------+------+------+-------------'
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               `------+      +--------------------'  `--------------------+      +------'
 */
    [_NAV] = LAYOUT(
      XXXXXXX, _______, _______, KC_RGHT, KC_UP,   KC_LEFT,                                     _______, _______, _______, _______, _______, XXXXXXX,
      XXXXXXX, _______, _______, _______, _______, _______,                                     _______, KC_DOWN, _______, _______, _______, XXXXXXX,
      XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX,
                                 _______, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, _______
    ),

// /*
//  * Layer template
//  *
//  * ,----------------------------------.                              ,----------------------------------.
//  * |      |      |      |      |      |                              |      |      |      |      |      |
//  * |------+------+------+------+------|                              |------+------+------+------+------|
//  * |      |      |      |      |      |                              |      |      |      |      |      |
//  * |------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |
//  * `-------------+------+------+------+      |      |  |      |      |------+------+------+-------------'
//  *               |      |      |      |      |      |  |      |      |      |      |      |
//  *               |      |      |      |      |      |  |      |      |      |      |      |
//  *               `------+      +--------------------'  `--------------------+      +------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       XXXXXXX, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, XXXXXXX,
//       XXXXXXX, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, XXXXXXX,
//       XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX,
//                                  _______, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, _______
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

__attribute__((weak)) void process_combo_event(uint16_t combo_index, bool pressed)
{
    switch(combo_index) {
    case C_LNAV:
    case C_RNAV:
        if (pressed) {
            set_oneshot_layer(plt_nav_index(), ONESHOT_START);
        } else {
            clear_oneshot_layer_state(ONESHOT_PRESSED);
        }
        break;
    case C_LSHIFT:
        if (pressed) {
            register_code(KC_LSFT);
            add_oneshot_mods(MOD_BIT(KC_LSFT));
        } else {
            unregister_code(KC_LSFT);
        }
        break;
    case C_RSHIFT:
        if (pressed) {
            register_code(KC_RSFT);
            add_oneshot_mods(MOD_BIT(KC_RSFT));
        } else {
            unregister_code(KC_RSFT);
        }
        break;
    case C_LCTRL:
        if (pressed) {
            register_code(KC_LCTL);
            add_oneshot_mods(MOD_BIT(KC_LCTL));
        } else {
            unregister_code(KC_LCTL);
        }
        break;
    case C_RCTRL:
        if (pressed) {
            register_code(KC_RCTL);
            add_oneshot_mods(MOD_BIT(KC_RCTL));
        } else {
            unregister_code(KC_RCTL);
        }
        break;
    case C_RALTR:
    case C_RALTL:
        if (pressed) {
            register_code(KC_RALT);
            add_oneshot_mods(MOD_BIT(KC_RALT));
        } else {
            unregister_code(KC_RALT);
        }
        break;
    case C_LALTR:
    case C_LALTL:
        if (pressed) {
            register_code(KC_LALT);
            add_oneshot_mods(MOD_BIT(KC_LALT));
        } else {
            unregister_code(KC_LALT);
        }
        break;
    case C_LGUI:
        if (pressed) {
            register_code(KC_LGUI);
            add_oneshot_mods(MOD_BIT(KC_LGUI));
        } else {
            unregister_code(KC_LGUI);
        }
        break;
    case C_RGUI:
        if (pressed) {
            register_code(KC_RGUI);
            add_oneshot_mods(MOD_BIT(KC_RGUI));
        } else {
            unregister_code(KC_RGUI);
        }
        break;
    case C_RSHORT:
        if (pressed) {
            set_oneshot_layer(plt_shortcut_index(), ONESHOT_START);
        } else {
            clear_oneshot_layer_state(ONESHOT_PRESSED);
        }
        break;
    case C_ESC:
        if (pressed) {
            tap_code16(KC_ESC);
            caps_word_off();
            cancel_close_tap();
        }
        break;
    case C_CLEAR:
        if (pressed) {
            clear_oneshot_mods();
            layer_move(plt_base_index());
            caps_word_off();
            cancel_close_tap();
        }
        break;
    case C_CAPS:
        if (pressed) {
            caps_word_toggle();
        }
        break;
    }
}
