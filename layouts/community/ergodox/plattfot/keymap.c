#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum layers {
    _DEFAULT,
    _LOWER,
    _RAISE,
    _NAV,
    _ADJUST,
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

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  CLO_TAP,  // Close the next key press
};

#define MO_ADJT MO(_ADJUST)
#define L_RAISE OSL(_RAISE)
#define L_LOWER OSL(_LOWER)
#define L_NAV   MO(_NAV)
#define EU_TDOT RSA(KC_SLSH)
#define EU_CDOT RALT(KC_EQUAL)
#define EU_DEG  RALT(KC_SCLN)

// Fillers to make layering more clear
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Default
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |  DEL   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   Q  |   W  |   E  |   R  |   T  | CLO  |           | CLO  |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|  TAP |           |  TAP |------+------+------+------+------+--------|
 * |  TAB   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| Lead |           |  BS  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
 *   |VolDn |VolUp | Play | LGUI | LCTL |                                       |  NAV | RAlt | SCLK | PgDn | PgUp |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Raise|      |       |      |  Lower |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space| LALT |------|       |------|  Ctrl  | Entr |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_DEFAULT] = LAYOUT_ergodox(
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    CLO_TAP,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_LEAD,
        KC_VOLD,KC_VOLU,KC_MPLY,KC_LGUI, KC_LCTL,
                                                    L_RAISE, _______,
                                                             _______,
                                            KC_SPC, KC_LALT, _______,
        // right hand
        _______,   KC_6,   KC_7,      KC_8,    KC_9,    KC_0,    KC_DEL,
        CLO_TAP,  KC_Y,   KC_U,      KC_I,    KC_O,    KC_P,    _______,
                  KC_H,   KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_BSPC,  KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          L_NAV,     KC_RALT, KC_SLCK, KC_PGDN, KC_PGUP,
        _______,  L_LOWER,
        _______,
        _______,  KC_RCTRL, KC_ENT
    ),
/*
 * Lower Layer: Left symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  !   |  @   |  #   |  $   |  %   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  |   |  _   |  \   |  -   |  +   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  °   |  :   |  (   |  )   |  ×   |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |ADJUST|      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LOWER] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
       _______, KC_PIPE, KC_UNDS, KC_BSLS, KC_MINS, KC_PLUS,
       _______, EU_DEG,  KC_COLN, KC_LPRN, KC_RPRN, EU_CDOT, _______,
       KC_MPRV, KC_MNXT, _______, _______, _______,
                                                    MO_ADJT, _______,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
       _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/*
 * Raise Layer: Right symbols + state
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  ^   |  &   |  *   |  ~   |  ?   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  =   |  {   |  }   |  [   |  ]   |   `    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  …   |  "   |  <   |  >   |  /   |  CAPS  |
 * `--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
 *   |      |      | Mute |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |ADJUST|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAISE] = LAYOUT_ergodox(
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, KC_MUTE, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE,KC_QUES, _______,
                KC_EQUAL,KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_GRV,
       _______, EU_TDOT, KC_DQUO, KC_LT,   KC_GT,   _______, KC_CAPS,
                         _______, _______, KC_INS,  _______, _______,
       _______, MO_ADJT,
       _______,
       _______, _______, _______
),

/*
 * Navigation Layer: Number keys, navigation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  1   |  2   |  3   |  4   |  5   |      |           |      |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      | Left |  Up  | Down | Right|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Game layout
[_NAV] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_1, 	KC_2,    KC_3,    KC_4,    KC_5,     _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
       // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
                _______, KC_LEFT, KC_UP, KC_DOWN,   KC_RGHT, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/*
 * Adjust Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Version|      |      |      |      |      | EPRM |           | EPRM |      |      |      |      |      | Version|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | BL+  | BL-  | BL / |      |      |           |      |      | BL / | BL - | BL + |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_ADJUST] = LAYOUT_ergodox(
       VRSN,    _______, _______, _______, _______, _______, EPRM,
       _______, _______, BL_INC,  BL_DEC,  BL_TOGG, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       EPRM,    _______, _______, _______, _______, _______, VRSN,
       _______, _______, BL_TOGG, BL_DEC,  BL_INC,  _______, _______,
                _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),


};

/* const uint16_t PROGMEM fn_actions[] = { */
/*     [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols) */
/* }; */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      // dynamically generate these.
    case EPRM:
      eeconfig_init();
      break;
    case VRSN:
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    case RGB_SLD:
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(1);
#endif
      return false;
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
             keycode != OSL(_RAISE) &&
             keycode != OSL(_LOWER) &&
             keycode != MO(_NAV)) {

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

/* // Runs just one time when the keyboard initializes. */
/* void matrix_init_user(void) { */

/* }; */
LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
#ifdef KEYBOARD_ergodox_ez
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
#endif
    LEADER_DICTIONARY() {
      leading = false;
      leader_end();
      // Sway navigation
      SEQ_ONE_KEY(KC_1) {  // Jump to workspace 1
        SEND_STRING(SS_LGUI("1"));
      }
      SEQ_ONE_KEY(KC_2) {  // Jump to workspace 2
        SEND_STRING(SS_LGUI("2"));
      }
      SEQ_ONE_KEY(KC_3) {  // Jump to workspace 3
        SEND_STRING(SS_LGUI("3"));
      }
      SEQ_ONE_KEY(KC_4) {  // Jump to workspace 4
        SEND_STRING(SS_LGUI("4"));
      }
      SEQ_ONE_KEY(KC_5) {  // Jump to workspace 5
        SEND_STRING(SS_LGUI("5"));
      }

      SEQ_ONE_KEY(KC_6) {  // Jump to workspace 6
        SEND_STRING(SS_LGUI("6"));
      }
      SEQ_ONE_KEY(KC_7) {  // Jump to workspace 7
        SEND_STRING(SS_LGUI("7"));
      }
      SEQ_ONE_KEY(KC_8) {  // Jump to workspace 8
        SEND_STRING(SS_LGUI("8"));
      }
      SEQ_ONE_KEY(KC_9) {  // Jump to workspace 9
        SEND_STRING(SS_LGUI("9"));
      }
      SEQ_ONE_KEY(KC_0) {  // Jump to workspace 0
        SEND_STRING(SS_LGUI("0"));
      }
      SEQ_ONE_KEY(KC_G) {  // View scratch pad
        SEND_STRING(SS_LGUI("-"));
      }

      // Sway move window
      SEQ_TWO_KEYS(KC_M, KC_1) {  // Move to workspace 1
        SEND_STRING(SS_LSFT(SS_LGUI("1")));
      }
      SEQ_TWO_KEYS(KC_M, KC_2) {  // Move to workspace 2
        SEND_STRING(SS_LSFT(SS_LGUI("2")));
      }
      SEQ_TWO_KEYS(KC_M, KC_3) {  // Move to workspace 3
        SEND_STRING(SS_LSFT(SS_LGUI("3")));
      }
      SEQ_TWO_KEYS(KC_M, KC_4) {  // Move to workspace 4
        SEND_STRING(SS_LSFT(SS_LGUI("4")));
      }
      SEQ_TWO_KEYS(KC_M, KC_5) {  // Move to workspace 5
        SEND_STRING(SS_LSFT(SS_LGUI("5")));
      }

      SEQ_TWO_KEYS(KC_M, KC_6) {  // Move to workspace 6
        SEND_STRING(SS_LSFT(SS_LGUI("6")));
      }
      SEQ_TWO_KEYS(KC_M, KC_7) {  // Move to workspace 7
        SEND_STRING(SS_LSFT(SS_LGUI("7")));
      }
      SEQ_TWO_KEYS(KC_M, KC_8) {  // Move to workspace 8
        SEND_STRING(SS_LSFT(SS_LGUI("8")));
      }
      SEQ_TWO_KEYS(KC_M, KC_9) {  // Move to workspace 9
        SEND_STRING(SS_LSFT(SS_LGUI("9")));
      }
      SEQ_TWO_KEYS(KC_M, KC_0) {  // Move to workspace 0
        SEND_STRING(SS_LSFT(SS_LGUI("0")));
      }
      SEQ_TWO_KEYS(KC_M, KC_G) {  // Move to scratch pad
        SEND_STRING(SS_LSFT(SS_LGUI("-")));
      }
    }
};

