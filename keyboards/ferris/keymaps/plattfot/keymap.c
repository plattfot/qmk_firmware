// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "plattfot.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layers {
    _BASE,
    _L_SYMFU,
    _R_SYMFU,
    _NAV,
};

#define TO_BASE TO(_BASE)

#define L_SYMFU OSL(_L_SYMFU)
#define R_SYMFU OSL(_R_SYMFU)
#define R_SHORT OSL(_R_SHORT)

/* #define OSL_ADJ OSL(_ADJUST) */
#define TGL_NAV TG(_NAV)

#define EU_TDOT RSA(KC_SLSH)
#define EU_CDOT RALT(KC_EQUAL)
#define EU_DEG  RALT(KC_SCLN)

enum combo_events {
  C_OE, // ö
  C_AE, // ä
  C_AO, // å
  C_EE, // é
  C_QUOTE, // '
  C_ESC, // escape
  C_BS, // backspace
  C_DEL, // backspace
  C_CTRL,
  C_ALT,
  C_ALTGR,
  C_GUI,
  C_SHIFT,
  C_TAB,
  C_NAV, // to navigation
  C_BASE, // to base
  C_CAPS, // caps word
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM oe_combo[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM ae_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM ao_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM ee_combo[] = {KC_G, KC_S, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_SPACE, KC_ENT, COMBO_END};

const uint16_t PROGMEM nav_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM alt_combo[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM ctrl_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM shift_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_A, COMBO_END};

const uint16_t PROGMEM base_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM bs_combo[] = {KC_N, KC_L, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM altgr_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM quote_combo[] = {KC_SCLN, KC_O, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_G, KC_M, COMBO_END};

combo_t key_combos[] = {
 [C_OE] = COMBO_ACTION(oe_combo),
 [C_AE] = COMBO_ACTION(ae_combo),
 [C_AO] = COMBO_ACTION(ao_combo),
 [C_EE] = COMBO_ACTION(ee_combo),
 [C_ESC] = COMBO_ACTION(esc_combo),

 [C_NAV] = COMBO_ACTION(nav_combo),
 [C_CTRL] = COMBO_ACTION(ctrl_combo),
 [C_ALT] = COMBO_ACTION(alt_combo),
 [C_GUI] = COMBO_ACTION(gui_combo),
 [C_TAB] = COMBO_ACTION(tab_combo),

 [C_BASE] = COMBO_ACTION(base_combo),
 [C_BS] = COMBO_ACTION(bs_combo),
 [C_DEL] = COMBO_ACTION(del_combo),
 [C_SHIFT] = COMBO_ACTION(shift_combo),
 [C_ALTGR] = COMBO_ACTION(altgr_combo),
 [C_QUOTE] = COMBO_ACTION(quote_combo),

 [C_CAPS] = COMBO_ACTION(caps_combo),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /*
  * Base Layer: Colemak DH
  *
  * ,----------------------------------.      ,----------------------------------.
  * |   Q  |   W  |   F  |   P  |   B  |      |   J  |   L  |   U  |   Y  |   ;  |
  * |------+------+------+------+------|      |------+------+------+------+------|
  * |   A  |   R  |   S  |   T  |   G  |      |   M  |   N  |   E  |   I  |   O  |
  * |------+------+------+------+------+      +------+------+------+------+------|
  * |   Z  |   X  |   C  |   D  |   V  |      |   K  |   H  |   ,  |   .  |   /  |
  * `------------------------------------. .--+------+------+--------------------'
  *                        | LSYM | SPC  | | Enter| RSYM |
  *                        |      |      | |      |      |
  *                        `-------------' `-------------'
  */
 [_BASE] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   L_SYMFU, KC_SPC,  KC_ENT, R_SYMFU
 ),
 /*
  * Left symbol and function Layer
  */
 [_L_SYMFU] = LAYOUT(
   KC_F12,  KC_F9,   KC_F8,   KC_F7,   _______,             KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE,KC_GRV,
   KC_F11,  KC_F3,   KC_F2,   KC_F1,   CLO_TAP,             KC_EQUAL,KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,
   KC_F10,  KC_F6,   KC_F5,   KC_F4,   _______,             EU_TDOT, KC_DQUO, KC_LT,   KC_GT,   KC_QUES,
                                     TO_BASE, _______, _______, TO_BASE

 ),

 /*
  * Right symbol and number Layer
  */
 [_R_SYMFU] = LAYOUT(
   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             _______, KC_7,    KC_8,   KC_9,   KC_COMM,
   KC_PIPE, KC_UNDS, KC_BSLS, KC_MINS, KC_PLUS,             CLO_TAP, KC_1,    KC_2,   KC_3,   KC_0,
   EU_DEG,  KC_COLN, KC_LPRN, KC_RPRN, EU_CDOT,             _______, KC_4,    KC_5,   KC_6,   KC_DOT,
                                    TO_BASE, _______, _______, TO_BASE
  ),

 /*
  * Adjustment layer
  */
 [_NAV] = LAYOUT(
   _______, _______, KC_RGHT, KC_UP,   KC_LEFT,             _______, _______, _______, _______, _______,
   _______, _______, _______, KC_PGUP, _______,             _______, KC_DOWN, _______, _______, _______,
   _______, _______, _______, KC_PGDN, _______,             _______, _______, RCTL(KC_PGUP),RCTL(KC_PGDN), _______,
                                    TO_BASE, _______, _______, TO_BASE
 ),
/*
 * Template Layer:
 *
 * ,----------------------------------.      ,----------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------|      |------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+      +------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * `------------------------------------. .--+------+------+--------------------'
 *                        |      |      | |      |      |
 *                        |      |      | |      |      |
 *                        `-------------' `-------------'
    _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______,
                                     _______, _______, _______, _______
*/
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }
    if (!process_close_tap(keycode, record)) { return false; }

    return true;
}

void matrix_scan_user(void) {
    caps_word_task();
}

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
  case C_EE:
    if (pressed) {
      tap_code16(RALT(KC_G));
    }
    break;
  case C_ESC:
    if (pressed) {
      tap_code16(KC_ESC);
      caps_word_set(false);
    }
    break;
  case C_NAV:
    if (pressed) {
      layer_move(_NAV);
    }
    break;
  case C_BASE:
    if (pressed) {
      layer_move(_BASE);
    }
    break;
  case C_CTRL:
    if (pressed) {
      add_oneshot_mods(MOD_BIT(KC_LCTL));
    }
    break;
  case C_ALT:
    if (pressed) {
      add_oneshot_mods(MOD_BIT(KC_LALT));
    }
    break;
  case C_GUI:
    if (pressed) {
      add_oneshot_mods(MOD_BIT(KC_LGUI));
    }
    break;
  case C_TAB:
    if (pressed) {
      tap_code16(KC_TAB);
    }
    break;
  case C_BS:
    if (pressed) {
      tap_code16(KC_BSPC);
    }
    break;
  case C_DEL:
    if (pressed) {
      tap_code16(KC_DEL);
    }
    break;
  case C_SHIFT:
    if (pressed) {
      add_oneshot_mods(MOD_BIT(KC_LSFT));
    }
    break;
  case C_ALTGR:
    if (pressed) {
      add_oneshot_mods(MOD_BIT(KC_RALT));
    }
    break;
  case C_QUOTE:
    if (pressed) {
      tap_code16(KC_QUOT);
    }
    break;
    case C_CAPS:
      if (pressed) {
        caps_word_set(!caps_word_get());
      }
      break;
  }
}
