// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "plattfot.h"

enum layers {
    _BASE,
    _L_SYMFU,
    _R_SYMFU,
    _NAV,
    _R_SHORT,
};

int plt_left_symfunc_index(void) {return _L_SYMFU;}

#define TO_BASE TO(_BASE)

#define L_SYMFU OSL(_L_SYMFU)
#define R_SYMFU OSL(_R_SYMFU)

#define R_SHORT OSL(_R_SHORT)
#define OSL_NAV OSL(_NAV)

#define EU_TDOT RSA(KC_SLSH)
#define EU_CDOT RALT(KC_EQUAL)
#define EU_DEG  RALT(KC_SCLN)

#define CTL_PUP RCTL(KC_PGUP)
#define CTL_PDN RCTL(KC_PGDN)

enum combo_events {
  C_ESC,
  C_CAPS, // caps word

  C_CLEAR, // clear state
  C_LSHIFT,
  C_LCTRL,
  C_LALTL,
  C_LGUI,

  C_TAB,
  C_LNAV, // to navigation
  C_RALTL,
  C_MPLY,

  C_RSHORT,
  C_RSHIFT,
  C_RCTRL,
  C_LALTR,
  C_RGUI,

  C_BSPC,
  C_RNAV, // to navigation
  C_RALTR,
  C_F20, // mic mute

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

const uint16_t PROGMEM tab_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM raltl_combo[] = {KC_S, KC_C, COMBO_END};
const uint16_t PROGMEM mply_combo[] = {KC_R, KC_X, COMBO_END};

const uint16_t PROGMEM rshort_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM rshift_combo[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM rctrl_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM laltr_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM rgui_combo[] = {KC_SCLN, KC_O, COMBO_END};

const uint16_t PROGMEM bspc_combo[] = {KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM raltr_combo[] = {KC_E, KC_COMM, COMBO_END};
const uint16_t PROGMEM micmute_combo[] = {KC_I, KC_DOT, COMBO_END};

combo_t key_combos[] = {
 [C_ESC] = COMBO_ACTION(esc_combo),
 [C_CAPS] = COMBO_ACTION(caps_combo),

 [C_CLEAR] = COMBO_ACTION(clear_combo),
 [C_LSHIFT] = COMBO_ACTION(lshift_combo),
 [C_LCTRL] = COMBO_ACTION(lctrl_combo),
 [C_LALTL] = COMBO_ACTION(laltl_combo),
 [C_LGUI] = COMBO_ACTION(lgui_combo),

 [C_TAB] = COMBO(tab_combo, KC_TAB),
 [C_RALTL] = COMBO_ACTION(raltl_combo),
 [C_MPLY] = COMBO(mply_combo, KC_MPLY),

 [C_RSHORT] = COMBO(rshort_combo, OSL(_R_SHORT)),
 [C_RSHIFT] = COMBO_ACTION(rshift_combo),
 [C_RCTRL] = COMBO_ACTION(rctrl_combo),
 [C_LALTR] = COMBO_ACTION(laltr_combo),
 [C_RGUI] = COMBO_ACTION(rgui_combo),

 [C_BSPC] = COMBO_ACTION(bspc_combo),
 [C_RALTR] = COMBO_ACTION(raltr_combo),
 [C_F20] = COMBO(micmute_combo, KC_F20),
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
   _______,  KC_F9,   KC_F8,   KC_F7,   KC_F12,             KC_LBRC, KC_RBRC, KC_GRV,  KC_DLR,  EU_TDOT,
   KC_F10,   KC_F3,   KC_F2,   KC_F1,   KC_F11,             KC_LCBR, KC_RCBR, KC_QUOT, KC_COLN, KC_CIRC,
   _______,  KC_F6,   KC_F5,   KC_F4,   CLO_TAP,            KC_LT,   KC_GT,   KC_DQUO, KC_TILDE,KC_QUES,
                                     TO_BASE, _______, _______, OSL_NAV

 ),

 /*
  * Right symbol and number Layer
  */
 [_R_SYMFU] = LAYOUT(
   EU_DEG,  KC_AT,   KC_ASTR, KC_HASH, KC_PERC,             _______, KC_7,    KC_8,   KC_9,   _______,
   KC_PIPE, KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN,             _______, KC_1,    KC_2,   KC_3,   KC_0,
   KC_EXLM, KC_BSLS, KC_PLUS, KC_EQUAL,KC_AMPR,             CLO_TAP, KC_4,    KC_5,   KC_6,   _______,
                                    OSL_NAV, _______, _______, TO_BASE
  ),

 /*
  * Nav layer
  */
 [_NAV] = LAYOUT(
   _______, _______, KC_RGHT, KC_UP,   KC_LEFT,             _______, _______, _______, _______, _______,
   _______, KC_LEFT, KC_RGHT, KC_DOWN, _______,             _______, KC_DOWN, KC_HOME, KC_END,  _______,
   _______, _______, CTL_PUP, CTL_PDN, _______,             _______, _______, KC_PGUP, KC_PGDN, _______,
                                    TO_BASE, _______, _______, TO_BASE
 ),

 [_R_SHORT] = LAYOUT(
    _______, _______, KC_MPRV, KC_MNXT, _______,             _______, G(KC_7), G(KC_8), G(KC_9), _______,
    _______, _______, KC_VOLD, KC_VOLU, _______,             _______, G(KC_1), G(KC_2), G(KC_3), G(KC_0),
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
    case C_CLEAR:
        if (pressed) {
            clear_oneshot_mods();
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
    case C_BSPC:
    {
        const uint8_t key = get_highest_layer(layer_state) == plt_left_symfunc_index()?
            KC_DEL:
            KC_BSPC;
        if (pressed) {
            register_code(key);
        } else {
            unregister_code(key);
            clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        }
        break;
    }
    }
}
