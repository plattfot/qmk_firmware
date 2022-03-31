/* Copyright 2015-2021 Jack Humbert
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
#include "plattfot.h"

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

#define TGL_NAV TG(_NAV)

int plt_base_index(void) {return _BASE;}
int plt_nav_index(void) {return _NAV;}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base: Colemak DH
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |      |      |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |      |      |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |      |      |   K  |   H  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | LSYM |  Spc |      |      | Enter| RSYM |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   BL_TOGG, BL_STEP, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,   _______, _______, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   _______, _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_VOLD, KC_MPLY, KC_VOLU, L_SYMFU, KC_SPC, _______, _______, KC_ENT,  R_SYMFU, KC_PGDN, TGL_NAV, KC_PGUP
),

 /*
  * Left symbol and function Layer
  */
[_L_SYMFU] = LAYOUT_planck_grid(
   KC_F12,  KC_F9,   KC_F8,   KC_F7,  _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE,KC_GRV,
   KC_F11,  KC_F3,   KC_F2,   KC_F1,  CLO_TAP, _______, _______, KC_EQUAL,KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,
   KC_F10,  KC_F6,   KC_F5,   KC_F4,  _______, _______, _______, EU_TDOT, KC_DQUO, KC_LT,   KC_GT,   KC_QUES,
   KC_MPRV, KC_F20, KC_MNXT, TO_BASE, _______, _______, _______, _______, TO_BASE, G(KC_B), _______, G(KC_F)
),

 /*
  * Right symbol and number Layer
  */
 [_R_SYMFU] = LAYOUT_planck_grid(
   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_COMM,
   KC_PIPE, KC_UNDS, KC_BSLS, KC_MINS, KC_PLUS, _______, _______, CLO_TAP, KC_1,    KC_2,    KC_3,    KC_0,
   EU_DEG,  KC_COLN, KC_LPRN, KC_RPRN, EU_CDOT, _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_DOT,
   _______, _______, _______, TO_BASE, _______, _______, _______, _______, TO_BASE, _______, _______, _______
  ),

 [_NAV] = LAYOUT_planck_grid(
   _______, _______, KC_RGHT, KC_UP,   KC_LEFT, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, KC_DOWN, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, TO_BASE, _______, _______, _______, _______, TO_BASE, RCTL(KC_PGUP), _______, RCTL(KC_PGDN)
 ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }
    if (!process_close_tap(keycode, record)) { return false; }

    return true;
}

void matrix_scan_user(void) {
    caps_word_task();
}
