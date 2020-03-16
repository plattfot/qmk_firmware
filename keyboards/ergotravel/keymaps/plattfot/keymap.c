﻿#include QMK_KEYBOARD_H
#include "version.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _SYMB 1 // Symbols
#define _GAME 2 // Experimental layer
#define _MDIA 3 // Media keys
#define _RAIS 4 // shift number keys


#define RSFT_1 RSFT(KC_1)
#define RSFT_2 RSFT(KC_2)
#define RSFT_3 RSFT(KC_3)
#define RSFT_4 RSFT(KC_4)
#define RSFT_5 RSFT(KC_5)
#define RSFT_6 RSFT(KC_6)
#define RSFT_7 RSFT(KC_7)
#define RSFT_8 RSFT(KC_8)
#define RSFT_9 RSFT(KC_9)
#define RSFT_0 RSFT(KC_0)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  EPRM,
  VRSN,
  RGB_SLD,
/* // Macros */
  M_LRBRC, // []
  M_LRCBR, // {}
  M_LRPRN, // ()
  M_LRABR, // <>
  M_DQOUT, // ""
};

// #define KC_ KC_TRNS
#define _______ KC_TRNS


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ESC,           KC_ENT,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    OSL(_GAME),       KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    OSL(_SYMB),       KC_INS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSL(_RAIS),
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, KC_LALT, KC_LGUI,          KC_LCTL, KC_SPC,           KC_BSPC, MO(_MDIA),        LALT(KC_RCTL),_______, _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_SYMB] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,          _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, KC_LPRN, KC_RPRN, KC_BSLS, KC_MINS, M_LRABR, _______,          _______, M_DQOUT, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, M_LRBRC, M_LRPRN, M_LRCBR, _______, _______,          KC_SLCK, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,          _______, _______,          _______, RALT_T(KC_DEL),   _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_GAME] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,           KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------
     _______, KC_LPRN, KC_RPRN, KC_BSLS, KC_MINS, M_LRABR, _______,          _______, M_DQOUT, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, M_LRBRC, M_LRPRN, M_LRCBR, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,          _______, _______,          _______, _______,          _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_MDIA] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     VRSN,    _______, _______, _______, _______, _______, _______,          _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_MPLY, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,          _______, _______,          _______, _______,          _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_RAIS] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     _______, RSFT_1,  RSFT_2,  RSFT_3,  RSFT_4,  RSFT_5,  _______,          _______, RSFT_6,  RSFT_7,  RSFT_8,  RSFT_9,  RSFT_0,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,          _______, KC_LALT,          KC_ENT,  _______,          _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),
};

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
    case M_LRPRN:
      SEND_STRING("()"SS_TAP(X_LEFT));
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    case M_LRCBR:
      SEND_STRING("{}"SS_TAP(X_LEFT));
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    case M_LRBRC:
      SEND_STRING("[]"SS_TAP(X_LEFT));
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    case M_LRABR:
      SEND_STRING("<>"SS_TAP(X_LEFT));
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    case M_DQOUT:
      SEND_STRING("\"\""SS_TAP(X_LEFT));
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    }
  }
  return true;
}
