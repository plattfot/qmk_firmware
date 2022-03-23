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

#pragma once

#include QMK_KEYBOARD_H

// It will insert the closing equivalent key and move the cursor
// inside. For example CLO_TAP and then ( will result in (|), where |
// is the cursor. For " it will be "|" as the close equivalent key is
// the same key.
//
// Based on a post from drashna [0] about implementing a double tap.
// [0] https://www.reddit.com/r/olkb/comments/citkbx/comment/evajkwy
enum close_tap_keycodes {
    CLOSE_TAP_PLACEHOLDER = SAFE_RANGE,
    // New keys
    CLO_TAP,  // Close the next key press
    CLOSE_TAP_SAFE_RANGE,
};

#define CLOSE_TAP = CLO_TAP;

// Call this function from `process_record_user()` to implement Close tap.
bool process_close_tap(uint16_t keycode, keyrecord_t* record);

// Deactivate close tap
void cancel_close_tap(void);

// Returns whether close tap is currently active.
bool is_close_tap_active(void);

// Optional callback function to override the logic for close tap.
// Useful if you are using a keyboard that doesn't follow the standard
// US ANSI layout.
bool close_tap_press_user(uint16_t keycode);


