/* Copyright 2022 Fredrik Salomonsson <plattfot@posteo.net>
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
#include "close_tap.h"

enum close_tap_modes {
  CLOSE_TAP_DISABLED = 0b000,
  CLOSE_TAP_PRESSED  = 0b001, // Close tap key is pressed
  CLOSE_TAP_ACTIVE   = 0b010, // Close tap next keypress
  CLOSE_TAP_USED     = 0b100, // Turn off when close tap key is released
};

#define CLOSE_TAP_RELEASE(flag) flag & ~CLOSE_TAP_PRESSED

static enum close_tap_modes close_tap_state = CLOSE_TAP_DISABLED;

bool process_close_tap(uint16_t keycode, keyrecord_t* record)
{
  switch (keycode) {
    // Ignore MO, TO, TG, TT, and OSL layer switch keys.
  case QK_MOMENTARY ... QK_MOMENTARY_MAX:
  case QK_TO ... QK_TO_MAX:
  case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
  case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
  case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
    return true;
  }
  if (record->event.pressed) {
    if (keycode == CLO_TAP) {
      close_tap_state = close_tap_state & CLOSE_TAP_ACTIVE?
        CLOSE_TAP_USED:
        CLOSE_TAP_ACTIVE|CLOSE_TAP_PRESSED;
      return false;
    }
    else if (close_tap_state & CLOSE_TAP_ACTIVE) {
      close_tap_state = close_tap_state & CLOSE_TAP_PRESSED?
        close_tap_state | CLOSE_TAP_USED:
        CLOSE_TAP_DISABLED;
      tap_code16(keycode);
      return close_tap_press_user(keycode);
    }
  } else {
    if (keycode == CLO_TAP) {
      close_tap_state = close_tap_state & CLOSE_TAP_USED?
        CLOSE_TAP_DISABLED:
        CLOSE_TAP_RELEASE(close_tap_state);
      return false;
    }
  }
  return true;
}

void cancel_close_tap(void)
{
  close_tap_state = CLOSE_TAP_DISABLED;
}

bool is_close_tap_active(void)
{
  return close_tap_state & CLOSE_TAP_ACTIVE;
}

__attribute__((weak)) bool close_tap_press_user(uint16_t keycode)
{
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
  return false;
}
