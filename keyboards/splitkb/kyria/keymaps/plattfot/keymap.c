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

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here
    // New keys
    CLO_TAP,  // Close the next key press
};

// Close tap feature based on a post from drashna
// https://www.reddit.com/r/olkb/comments/citkbx/double_key_press_modifier_qmkwould_work_like/ev9cue8/
// Will insert the closing equivalent key and move the cursor inside.
// For example clo_tap and then ( will result in (|), where | is the
// cursor. For " it will be "|" as the close equivalent key is the
// same key.
enum close_tap_modes {
  CLO_DISABLED = 0b000,
  CLO_PRESSED  = 0b001, // Close tap key is pressed
  CLO_ACTIVE   = 0b010, // Close tap next keypress
  CLO_USED     = 0b100, // Turn off when close tap key is released
};

#define CLO_RELEASE(flag) flag & ~CLO_PRESSED

static enum close_tap_modes close_tap_it = CLO_DISABLED;

enum layers {
    _BASE,
    _L_SYMFU,
    _R_SYMFU,
    _L_SHORT,
    _R_SHORT,
    _ADJUST,
    _NAV,
};

enum combo_events {
  C_OE, // ö
  C_AE, // ä
  C_AO, // å
  C_ESC, // escape
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM oe_combo[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM ae_combo[] = {KC_A, KC_DOT, COMBO_END};
const uint16_t PROGMEM ao_combo[] = {KC_W, KC_DOT, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_SPACE, KC_ENT, COMBO_END};

combo_t key_combos[] = {
 [C_OE] = COMBO_ACTION(oe_combo),
 [C_AE] = COMBO_ACTION(ae_combo),
 [C_AO] = COMBO_ACTION(ao_combo),
 [C_ESC] = COMBO_ACTION(esc_combo),
};


#define TO_BASE TO(_BASE)
#define MO_ADJT MO(_ADJUST)
#define L_SHORT OSL(_L_SHORT)
#define L_SYMFU OSL(_L_SYMFU)
#define R_SYMFU OSL(_R_SYMFU)
#define R_SHORT OSL(_R_SHORT)
#define TGL_NAV TG(_NAV)
#define EU_TDOT RSA(KC_SLSH)
#define EU_CDOT RALT(KC_EQUAL)
#define EU_DEG  RALT(KC_SCLN)

#define OS_LSFT OSM(KC_LSFT)
#define OS_LCTL OSM(KC_LCTL)
#define OS_LALT OSM(KC_LALT)
#define OS_LGUI OSM(KC_LGUI)

#define OS_RSFT OSM(KC_RSFT)
#define OS_RCTL OSM(KC_RCTL)
#define OS_RALT OSM(KC_RALT)
#define OS_RGUI OSM(KC_RGUI)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Default
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Del   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   ;  | BSpace |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |      |LSYMFU|  |RSYMFU|      |   K  |   H  |   ,  |   .  |   /  | RShift |
 * `----------------------+------+------+------| Space|------|  |------| Enter|------+------+------+----------------------'
 *                        | MPlay|      | LGUI |      | LCtrl|  | RCtrl|      | RGUI |      | Tgl  |
 *                        |      |      |      |      |      |  |      |      |      |      | Nav  |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
      KC_DEL,  KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
      KC_TAB,  KC_A,   KC_R,   KC_S,   KC_T,   KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,    XXXXXXX,  L_SYMFU, R_SYMFU, XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_MPLY,XXXXXXX,KC_LGUI, KC_SPACE, KC_LCTL, KC_RCTL,  KC_ENT, KC_RGUI, XXXXXXX, TGL_NAV
    ),

/*
 * Left symbol and function Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |                              |   ^  |  &   |  *   |  ~   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F11 | RAlt | LAlt | LCtrl|CLOTAP|                              |   =  |  {   |  }   |  [   |  ]   |   `    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  |ADJUST|      |   …  |  "   |  <   |  >   |  ?   |        |
 * `----------------------+------+------+------|LSHORT|------|  |------|      |------+------+------+----------------------'
 *                        |      |      |      | Cuts |      |  |      |      |      |      | Mute |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_L_SYMFU] = LAYOUT(
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE,_______, _______,
      _______, KC_F11,  KC_RALT, KC_LALT, KC_LCTL, CLO_TAP,                                     KC_EQUAL,KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_GRV,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, _______, MO_ADJT, XXXXXXX, EU_TDOT, KC_DQUO, KC_LT,   KC_GT,   KC_QUES, _______,
                                 _______, _______, _______, L_SHORT, _______, _______, _______, _______, _______, KC_MUTE

    ),


/*
 * Right symbol and function Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                              |  6   |  7   |  8   |  9   | 0    |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  |   |  _   |  \   |  -   |  +   |                              |CLOTAP| RCtrl| LAlt | RAlt | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  °   |  :   |  (   |  )   |  ×   |      |ADJUST|  |      |      |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * `----------------------+------+------+------|      |------|  |------|RSHORT|------+------+------+----------------------'
 *                        | Mic  |      |      |      |      |  |      | Cuts |      |      |      |
 *                        | Mute |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_R_SYMFU] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, KC_PIPE, KC_UNDS, KC_BSLS, KC_MINS, KC_PLUS,                                     CLO_TAP, KC_RCTL, KC_LALT, KC_RALT, KC_F12,  _______,
      _______, EU_DEG,  KC_COLN, KC_LPRN, KC_RPRN, EU_CDOT, XXXXXXX, MO_ADJT, _______, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
                                 KC_F20,  _______, _______, _______, _______, _______, R_SHORT, _______, _______, _______
    ),

/*
 * Left short cuts
 *
 */
    [_L_SHORT] = LAYOUT(
      _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5),                                     _______, _______, _______, _______, _______, _______,
      _______, _______, KC_RALT, KC_LALT, KC_LCTL, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, XXXXXXX, _______, TO_BASE, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Right short cuts
 */
    [_R_SHORT] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_LALT, KC_RCTL, KC_RALT, _______, _______,
      _______, _______, _______, _______, _______, _______, XXXXXXX, TO_BASE, _______, XXXXXXX, _______, _______, _______, _______, _______, _______,
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
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------|      |------|  |------|      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, KC_CAPS, KC_INS,  _______, _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______,
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
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
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
    if (record->event.pressed) {
        switch (keycode) {
            case CLO_TAP:
                close_tap_it = close_tap_it & CLO_ACTIVE?
                    CLO_USED:
                    CLO_ACTIVE|CLO_PRESSED;
                return false;
            case KC_LEAD:
                close_tap_it = CLO_DISABLED;
                return true;
        }
    } else if (close_tap_it & CLO_ACTIVE &&
               keycode != CLO_TAP &&
               keycode != OSL(_R_SHORT) &&
               keycode != OSL(_R_SYMFU) &&
               keycode != OSL(_L_SYMFU) &&
               keycode != OSL(_L_SHORT)) {

        close_tap_it = close_tap_it & CLO_PRESSED?
            close_tap_it | CLO_USED:
            CLO_DISABLED;
        switch(keycode)
        {
        case KC_LPRN:
          tap_code16(KC_RPRN);
          tap_code16(KC_LEFT);
          break;
        case KC_RPRN:
          tap_code16(KC_LEFT);
          tap_code16(KC_LPRN);
          break;
        case KC_LCBR:
          tap_code16(KC_RCBR);
          tap_code16(KC_LEFT);
          break;
        case KC_RCBR:
          tap_code16(KC_LEFT);
          tap_code16(KC_LCBR);
          break;
        case KC_LBRC:
          tap_code16(KC_RBRC);
          tap_code16(KC_LEFT);
          break;
        case KC_RBRC:
          tap_code16(KC_LEFT);
          tap_code16(KC_LBRC);
          break;
        case KC_LT:
          tap_code16(KC_GT);
          tap_code16(KC_LEFT);
          break;
        case KC_GT:
          tap_code16(KC_LEFT);
          tap_code16(KC_LT);
          break;
        default:
          tap_code16(keycode);
          tap_code16(KC_LEFT);
          break;
        }
    } else {
        switch (keycode) {
            case CLO_TAP:
                close_tap_it = close_tap_it & CLO_USED?
                    CLO_DISABLED:
                    CLO_RELEASE(close_tap_it);
        }
    }

    return true;
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
            oled_write_P(PSTR("<-sym|fun->\n"), false);
            break;
        case _L_SYMFU:
            oled_write_P(PSTR("<-fun|sym->\n"), false);
            break;
        case _L_SHORT:
            oled_write_P(PSTR("<-shortcuts\n"), false);
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
    } else if (close_tap_it) {
        oled_write_P(PSTR("Close  "), false);
    } else {
        oled_write_P(PSTR("       "), false);
    }

    if (led_state.caps_lock) {
        oled_write_P(PSTR("CAPLCK "), false);
    } else if (close_tap_it) {
        oled_write_P(PSTR("Tap    "), false);
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
            case _L_SHORT:
                // Scroll up and down through the containers
                if (clockwise) {
                    tap_code16(G(KC_P));
                } else {
                    tap_code16(G(KC_N));
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

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case C_OE:
      if (pressed) {
        tap_code16(RALT(KC_O));
      }
      break;
    case C_AE:
      if (pressed) {
        tap_code16(RALT(KC_A));
      }
      break;
    case C_AO:
      if (pressed) {
        tap_code16(RALT(KC_W));
      }
      break;
    case C_ESC:
      if (pressed) {
        tap_code16(KC_ESC);
      }
      break;
  }
}
