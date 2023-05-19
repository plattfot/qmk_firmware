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
    _R_SHORT,
};

#define TO_BASE TO(_BASE)

#define L_SYMFU OSL(_L_SYMFU)
#define R_SYMFU OSL(_R_SYMFU)

#define R_SHORT OSL(_R_SHORT)

#define EU_TDOT RSA(KC_SLSH)
#define EU_CDOT RALT(KC_EQUAL)
#define EU_DEG  RALT(KC_SCLN)

#define CTL_PUP RCTL(KC_PGUP)
#define CTL_PDN RCTL(KC_PGDN)

enum combo_events {
  C_ESC,
  C_CAPS, // caps word

  C_BASE, // to base
  C_LALTL,
  C_LCTRL,
  C_LGUI,
  C_LSHIFT,

  C_CPU, // Ctri + PgUp
  C_DEL,
  C_MPLY,
  C_RALTL,
  C_TAB,

  C_RSHORT,
  C_LALTR,
  C_RCTRL,
  C_RGUI,
  C_RSHIFT,

  C_CPD, // Ctri + PgDn
  C_ENT,
  C_F20, // mic mute
  C_RALTR,
  C_NAV, // to navigation

  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM esc_combo[] = {KC_SPACE, KC_BSPC, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_G, KC_M, COMBO_END};

const uint16_t PROGMEM base_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM laltl_combo[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM lctrl_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM lgui_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM lshift_combo[] = {KC_Q, KC_A, COMBO_END};

const uint16_t PROGMEM cpu_combo[] = {KC_G, KC_V, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM mply_combo[] = {KC_S, KC_C, COMBO_END};
const uint16_t PROGMEM raltl_combo[] = {KC_R, KC_X, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_A, KC_Z, COMBO_END};

const uint16_t PROGMEM rshort_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM laltr_combo[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM rctrl_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM rgui_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM rshift_combo[] = {KC_SCLN, KC_O, COMBO_END};

const uint16_t PROGMEM cpd_combo[] = {KC_M, KC_K, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM micmute_combo[] = {KC_E, KC_COMM, COMBO_END};
const uint16_t PROGMEM raltr_combo[] = {KC_I, KC_DOT, COMBO_END};
const uint16_t PROGMEM nav_combo[] = {KC_O, KC_SLSH, COMBO_END};

combo_t key_combos[] = {
 [C_ESC] = COMBO_ACTION(esc_combo),
 [C_CAPS] = COMBO_ACTION(caps_combo),

 [C_BASE] = COMBO_ACTION(base_combo),
 /* [C_LALTL] = COMBO(laltl_combo, OSM(MOD_LALT)), */
 /* [C_LCTRL] = COMBO(lctrl_combo, OSM(MOD_LCTL)), */
 /* [C_LGUI] = COMBO(lgui_combo, OSM(MOD_LGUI)), */
 /* [C_LSHIFT] = COMBO(lshift_combo, OSM(MOD_LSFT)), */
 [C_LALTL] = COMBO_ACTION(laltl_combo),
 [C_LCTRL] = COMBO_ACTION(lctrl_combo),
 [C_LGUI] = COMBO_ACTION(lgui_combo),
 [C_LSHIFT] = COMBO_ACTION(lshift_combo),


 [C_CPU] = COMBO(cpu_combo, LCTL(KC_PGUP)),
 [C_DEL] = COMBO(del_combo, KC_DEL),
 [C_MPLY] = COMBO(mply_combo, KC_MPLY),
 /* [C_RALTL] = COMBO(raltl_combo, OSM(MOD_RALT)), */
 [C_RALTL] = COMBO_ACTION(raltl_combo),
 [C_TAB] = COMBO(tab_combo, KC_TAB),

 [C_RSHORT] = COMBO(rshort_combo, OSL(_R_SHORT)),
 /* [C_LALTR] = COMBO(laltr_combo, OSM(MOD_LALT)), */
 /* [C_RCTRL] = COMBO(rctrl_combo, OSM(MOD_RCTL)), */
 /* [C_RGUI] = COMBO(rgui_combo, OSM(MOD_RGUI)), */
 /* [C_RSHIFT] = COMBO(rshift_combo, OSM(MOD_RSFT)), */
 [C_LALTR] = COMBO_ACTION(laltr_combo),
 [C_RCTRL] = COMBO_ACTION(rctrl_combo),
 [C_RGUI] = COMBO_ACTION(rgui_combo),
 [C_RSHIFT] = COMBO_ACTION(rshift_combo),

 [C_CPD] = COMBO(cpd_combo, RCTL(KC_PGDN)),
 [C_ENT] = COMBO(ent_combo, KC_ENT),
 [C_F20] = COMBO(micmute_combo, KC_F20),
 /* [C_RALTR] = COMBO(raltr_combo, OSM(MOD_RALT)), */
 [C_RALTR] = COMBO_ACTION(raltr_combo),
 [C_NAV] = COMBO(nav_combo, OSL(_NAV)),
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
  *                        | LSYM | SPC  | | BSPC | RSYM |
  *                        |      |      | |      |      |
  *                        `-------------' `-------------'
  */
 [_BASE] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   L_SYMFU, KC_SPC,  KC_BSPC, R_SYMFU
 ),
 /*
  * Left symbol and function Layer
  */
 [_L_SYMFU] = LAYOUT(
   KC_F12,  KC_F9,   KC_F8,   KC_F7,   KC_VOLU,             KC_LBRC, KC_RBRC, KC_GRV,  KC_DLR,  EU_TDOT,
   KC_F11,  KC_F3,   KC_F2,   KC_F1,   KC_VOLD,             KC_LCBR, KC_RCBR, KC_QUOT, KC_COLN, KC_CIRC,
   KC_F10,  KC_F6,   KC_F5,   KC_F4,   CLO_TAP,             KC_LT,   KC_GT,   KC_DQUO, KC_TILDE,KC_QUES,
                                     TO_BASE, _______, _______, TO_BASE

 ),

 /*
  * Right symbol and number Layer
  */
 [_R_SYMFU] = LAYOUT(
   EU_DEG,  KC_AT,   KC_ASTR, KC_HASH, KC_PERC,             KC_MPRV, KC_7,    KC_8,   KC_9,   _______,
   KC_PIPE, KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN,             KC_MNXT, KC_1,    KC_2,   KC_3,   KC_0,
   KC_EXLM, KC_BSLS, KC_PLUS, KC_EQUAL,KC_AMPR,             CLO_TAP, KC_4,    KC_5,   KC_6,   _______,
                                    TO_BASE, _______, _______, TO_BASE
  ),

 /*
  * Nav layer
  */
 [_NAV] = LAYOUT(
   _______, _______, KC_RGHT, KC_UP,   KC_LEFT,             _______, _______, _______, _______, _______,
   _______, KC_HOME, KC_PGUP, KC_END,  _______,             _______, KC_DOWN, _______, _______, _______,
   _______, _______, KC_PGDN, _______, _______,             _______, _______, _______, _______, _______,
                                    TO_BASE, _______, _______, TO_BASE
 ),

 [_R_SHORT] = LAYOUT(
    _______, _______, _______, _______, _______,             _______, G(KC_7), G(KC_8), G(KC_9), _______,
    _______, _______, _______, _______, _______,             _______, G(KC_1), G(KC_2), G(KC_3), G(KC_0),
    _______, _______, _______, _______, _______,             _______, G(KC_4), G(KC_5), G(KC_6), _______,
                                     _______, _______, _______, _______

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
    case C_LALTR:
    case C_LALTL:
        if (pressed) {
            register_code(KC_LALT);
            add_oneshot_mods(MOD_BIT(KC_LALT));
        } else {
            unregister_code(KC_LALT);
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
    case C_ESC:
        if (pressed) {
            tap_code16(KC_ESC);
            caps_word_set(false);
            cancel_close_tap();
        }
        break;
    case C_BASE:
        if (pressed) {
            layer_move(_BASE);
            caps_word_set(false);
            cancel_close_tap();
        }
        break;
    case C_CAPS:
        if (pressed) {
            caps_word_set(!caps_word_get());
        }
        break;
    }
}
